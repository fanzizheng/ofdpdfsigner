//
//  Created by zizheng fan on 2021/11/26.
//
#include "basic/FZZConst.h"
#include "basic/FZZZipTracks.h"
#include "basic/FZZBytes.h"
#include "basic/FZZOFDFilesContainer.h"

#ifdef MINIZIPNG
#include "mz_strm_mem.h"
#endif

#define READ_SIZE 8192
#define MAX_FILENAME 512

//Defined in compiler _64_ or _32_ , 64 bit compiler and 32-bit compiler respectively
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZZipTracks****************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZZipTracks::FZZZipTracks() : m_newZipFile(NULL)
{
    //DLOG("FZZZipTracks()");
    FZZConst::addClassCount("FZZZipTracks");
}
//-----------------------------------------------------------------------------------------------------------------
FZZZipTracks::~FZZZipTracks()
{
    //DLOG("~FZZZipTracks()");
    FZZConst::delClassCount("FZZZipTracks");
    if (m_newZipFile != NULL) {
        zipClose(m_newZipFile, NULL);
        m_newZipFile = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
#ifdef MINIZIPNG
bool FZZZipTracks::CreateZip_mem()
{
    CloseZip();
    fill_memory_filefunc(&m_ffunc);
    m_newZipFile = zipOpen2("__notused__", APPEND_STATUS_CREATE, NULL, &m_ffunc);

    if (m_newZipFile == NULL)
    {
        return false;
    }

    return true;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZZipTracks::CloseZip_mem()
{
    FZZBytes ret;
    if (m_newZipFile != NULL) {
        zipClose_MZ(m_newZipFile, NULL);
        void* stream = zipGetStream_MZ(m_newZipFile);
        if (stream != NULL) {
            int32_t len = 0;
            mz_stream_mem_get_buffer_length(stream, &len);
            if (len > 0) {
                const void* buffer = NULL;
                mz_stream_mem_get_buffer(stream, &buffer);
                ret.setData((unsigned char*)buffer, len);
            }
        }

        zipClose(m_newZipFile, NULL);
        m_newZipFile = NULL;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
#else
//-----------------------------------------------------------------------------------------------------------------
unsigned long FZZZipTracks::getZipFileMaxSize(unsigned long sourcelen)
{
    return compressBound(sourcelen) + 100;
}

//-----------------------------------------------------------------------------------------------------------------
bool FZZZipTracks::CreateZip_mem(unsigned char *zipdata, unsigned long zipdatalen)
{
    CloseZip();
    char filename[100] = { 0 };
#ifdef _64_
    sprintf(filename, "%llx+%llx", zipdata, zipdatalen);
#else
    sprintf(filename, "%x+%x", zipdata, zipdatalen);
#endif
   
    //zlib_filefunc_def ffunc;
    fill_memory_filefunc(&m_ffunc);
    m_newZipFile = zipOpen2(filename, APPEND_STATUS_CREATE, NULL, &m_ffunc);
    if (m_newZipFile == NULL)
    {
        return false;
    }

    return true;
}
//-----------------------------------------------------------------------------------------------------------------
unsigned long FZZZipTracks::CloseZip_mem()
{
    if (m_newZipFile != NULL) {
        long len = getZipFileLengthAndClose(m_newZipFile,NULL);
        //zipClose(m_newZipFile, NULL);
        m_newZipFile = NULL;
        return len;
    } else {
        return 0;
    }
    //zip_bufferlen ,It is a global variable. There is a thread safety problem. We will consider how to solve it later.
    //return zip_bufferlen;
}
#endif
//-----------------------------------------------------------------------------------------------------------------
bool FZZZipTracks::CreateZip(const char * const zipfilename)
{
  
    CloseZip();
    m_newZipFile = zipOpen64(zipfilename, APPEND_STATUS_CREATE);
    if (m_newZipFile == NULL)
    {
        return false;
    }

    return true;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZZipTracks::CloseZip()
{
    if (m_newZipFile != NULL) {
        zipClose(m_newZipFile, NULL);
        m_newZipFile = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZZipTracks::AddFileToZip(const char* fileNameInZip, const unsigned char* srcdata, unsigned long srcdatalen)
{
    if (m_newZipFile == NULL || fileNameInZip == NULL ) {
        return;
    }
    
    //Initialize the file information written to zip
    zip_fileinfo zi;
    zi.tmz_date.tm_sec = zi.tmz_date.tm_min = zi.tmz_date.tm_hour =
        zi.tmz_date.tm_mday = zi.tmz_date.tm_mon = zi.tmz_date.tm_year = 0;
    zi.dosDate = 0;
    zi.internal_fa = 0;
    zi.external_fa = 0;

    //If srcFile is empty, add an empty directory
    char new_file_name[512] = { 0 };

    strcat(new_file_name, fileNameInZip);
    if (srcdata == NULL)
    {
        strcat(new_file_name, "/");
    }

    //Create a new file in the zip file
    zipOpenNewFileInZip(m_newZipFile, new_file_name, &zi, NULL, 0, NULL, 0, NULL, Z_DEFLATED, Z_DEFAULT_COMPRESSION);

    if (srcdata != NULL && srcdatalen > 0)
    {
        zipWriteInFileInZip(m_newZipFile, srcdata, (uint32_t)srcdatalen);
    }

   
    zipCloseFileInZip(m_newZipFile);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZZipTracks::UnZip(string retuid,const char * const filename,FZZOFDFilesContainer* ofdFilesContainer)
{
    bool retTF = false;
    if ( ofdFilesContainer == NULL || filename == NULL ) {
        return retTF;
    }
    
    unzFile zipfile = unzOpen(filename);
    if ( zipfile == NULL ) {
        return retTF;
    }
    
    unz_global_info global_info;
    if ( unzGetGlobalInfo( zipfile, &global_info ) != UNZ_OK )
    {
        unzClose( zipfile );
        return retTF;
    }
    
    unsigned char read_buffer[ READ_SIZE ];
    uint32_t i;
    for ( i = 0; i < global_info.number_entry; ++i )
    {
        // Get info about current file.
        unz_file_info file_info;
        char filename[ MAX_FILENAME ];
        if ( unzGetCurrentFileInfo(
            zipfile,
            &file_info,
            filename,
            MAX_FILENAME,
            NULL, 0, NULL, 0 ) != UNZ_OK )
        {
            unzClose( zipfile );
            return retTF;
        }

        // Check if this entry is a directory or file.
        const size_t filename_length = strlen( filename );
        if ( filename[ filename_length-1 ] == '/'  || filename[ filename_length-1 ] == '\\' )
        {
            // Entry is a directory, so create it.
            //printf( "dir:%s\n", filename );
            //mkdir( filename );
        }
        else
        {
            // Entry is a file, so extract it.
            //printf( "file:%s\n", filename );
            if ( unzOpenCurrentFile( zipfile ) != UNZ_OK )
            {
                unzClose( zipfile );
                
                return retTF;
            }

            // Open a file to write out the data.
            
            FZZBytes bytes;
            int datalen = UNZ_OK;
            do
            {
                datalen = unzReadCurrentFile( zipfile, read_buffer, READ_SIZE );
                if ( datalen < 0 )
                {
                   
                    unzCloseCurrentFile( zipfile );
                    unzClose( zipfile );
                    return retTF;
                }

                // Write data to file.
                if ( datalen > 0 )
                {
                    bytes.addData(read_buffer, datalen);
                    //VirtualContainer::m_OFDFilesContainer.
                    //fwrite( read_buffer, error, 1, out ); // You should check return of fwrite...
                }
            } while ( datalen > 0 );

            ofdFilesContainer->addFile(retuid, filename, bytes.getData(), bytes.getLen());
        }

        unzCloseCurrentFile( zipfile );

        // Go the the next entry listed in the zip file.
        if ( ( i+1 ) < global_info.number_entry )
        {
            if ( unzGoToNextFile( zipfile ) != UNZ_OK )
            {
                //printf( "cound not read next file\n" );
                retTF =true;
                unzClose( zipfile );
                return retTF;
            }
        }
    }

    unzClose( zipfile );
    retTF =true;
    return retTF;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZZipTracks::UnZip(string retuid,const unsigned char* const zipdata, unsigned long zipdatalen,FZZOFDFilesContainer* ofdFilesContainer)
{
    bool retTF = false;
    
    if ( ofdFilesContainer == NULL || zipdata == NULL || zipdatalen == 0 ) {
        return retTF;
    }

    zlib_filefunc_def ffunc;
    fill_memory_filefunc(&ffunc);
#ifdef MINIZIPNG
    
    unzFile zipfile = unzOpen2_my("__notused__", &ffunc, (void*)zipdata, (int)zipdatalen);
#else
    char filename[100] = { 0 };
#ifdef _64_
    sprintf(filename, "%llx+%llx", zipdata, zipdatalen);
#else
    sprintf(filename, "%x+%x", zipdata, zipdatalen);
#endif
   
    
    unzFile zipfile = unzOpen2(filename, &ffunc);
#endif
    if ( zipfile == NULL ) {
        return retTF;
    }
    unz_global_info global_info;
    if ( unzGetGlobalInfo( zipfile, &global_info ) != UNZ_OK )
    {
        unzClose( zipfile );
        return retTF;
    }
    
    unsigned char read_buffer[ READ_SIZE ];
    uint32_t i;
    for ( i = 0; i < global_info.number_entry; ++i )
    {
        // Get info about current file.
        unz_file_info file_info;
        char filename[ MAX_FILENAME ];
        if ( unzGetCurrentFileInfo(
            zipfile,
            &file_info,
            filename,
            MAX_FILENAME,
            NULL, 0, NULL, 0 ) != UNZ_OK )
        {
            unzClose( zipfile );
          
            return retTF;
        }

        // Check if this entry is a directory or file.
        const size_t filename_length = strlen( filename );
        if ( filename[ filename_length-1 ] == '/'  || filename[ filename_length-1 ] == '\\' )
        {
            // Entry is a directory, so create it.
            //printf( "dir:%s\n", filename );
            //mkdir( filename );
        }
        else
        {
            // Entry is a file, so extract it.
            //printf( "file:%s\n", filename );
            if ( unzOpenCurrentFile( zipfile ) != UNZ_OK )
            {
                unzClose( zipfile );
             
                return retTF;
            }

            // Open a file to write out the data.
            
            FZZBytes bytes;
            int datalen = UNZ_OK;
            do
            {
                datalen = unzReadCurrentFile( zipfile, read_buffer, READ_SIZE );
                if ( datalen < 0 )
                {
                   
                    unzCloseCurrentFile( zipfile );
                    unzClose( zipfile );
                    return retTF;
                }

                // Write data to file.
                if ( datalen > 0 )
                {
                    bytes.addData(read_buffer, datalen);
                    //VirtualContainer::m_OFDFilesContainer.
                    //fwrite( read_buffer, error, 1, out ); // You should check return of fwrite...
                }
            } while ( datalen > 0 );

            //When signing, it is compatible with "shu ke"
            //begin
            
            
            
            unsigned char * ptempData = bytes.getData();
            ptempData += bytes.getLen() -1;
            int ACount = 0;
            while( *ptempData == 0x0A || *ptempData == 0x0D ) {
                ACount++;
                ptempData -= 1;
            }

            if (  ACount > 0 ) {
                FZZBytes tempBytes;
                tempBytes.setMaxLen(bytes.getLen()+3);
                tempBytes.setData_NotMalloc(bytes.getData(), bytes.getLen());
                const char* found = strstr((char *)tempBytes.getData(), "<?xml");
                if ( found != NULL ) {
                    bytes.setLen(bytes.getLen()-ACount);
                }
            }
            //end
            ofdFilesContainer->addFile(retuid, filename, bytes.getData(), bytes.getLen());
        }

        unzCloseCurrentFile( zipfile );

        // Go the the next entry listed in the zip file.
        if ( ( i+1 ) < global_info.number_entry )
        {
            if ( unzGoToNextFile( zipfile ) != UNZ_OK )
            {
                //printf( "cound not read next file\n" );
                unzClose( zipfile );
                retTF = true;
                return retTF;
            }
        }
    }

    unzClose( zipfile );
    retTF = true;
    return retTF;
}
//-----------------------------------------------------------------------------------------------------------------
