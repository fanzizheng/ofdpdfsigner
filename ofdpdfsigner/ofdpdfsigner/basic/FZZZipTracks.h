//
//  Created by zizheng fan on 2021/11/26.
//
#ifndef FZZZIPTRACKS_H
#define FZZZIPTRACKS_H




class FZZOFDFilesContainer;
class FZZZipTracks
{

public:
    FZZZipTracks();
    ~FZZZipTracks();
public:
    
#ifdef MINIZIPNG
    bool CreateZip_mem();
    FZZBytes CloseZip_mem();
#else
    unsigned long getZipFileMaxSize(unsigned long sourcelen);
    bool CreateZip_mem(unsigned char* zipdata, unsigned long zipdatalen);
    unsigned long CloseZip_mem();
#endif
    bool CreateZip(const char * const zipfilename);
    void CloseZip();
    void AddFileToZip(const char* fileNameInZip, const unsigned char* srcdata, unsigned long srcdatalen);
    
    bool UnZip(string retuid,const char * const filename,FZZOFDFilesContainer* ofdFilesContainer);
    bool UnZip(string retuid,const unsigned char* const zipdata, unsigned long zipdatalen,FZZOFDFilesContainer* ofdFilesContainer);
private:
    
private:
    zipFile m_newZipFile;
    zlib_filefunc_def m_ffunc;
};

#endif //FZZZIPTRACKS_H
