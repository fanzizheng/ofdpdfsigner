
#include "Util.h"
#include "rapidjson/document.h"
#include "basic/FZZBytes.h"
#include <QFile>

map<string,FILETEMPCACHE*> g_FilesContainer;
//-----------------------------------------------------------------------------------------------------------------
/***********************************************Until**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FILETEMPCACHE * newFileTempCache()
{
    FILETEMPCACHE * filetempchahe = (FILETEMPCACHE *)malloc(sizeof(FILETEMPCACHE));
    filetempchahe->filetype = 0;
    filetempchahe->filebase64 = new string("");
    filetempchahe->filedata = new FZZBytes();
    filetempchahe->pages = new vector<FZZBytes*>();
    return filetempchahe;
}
//-----------------------------------------------------------------------------------------------------------------
void DeleteFileTempCache(FILETEMPCACHE * filecache)
{
    if ( filecache == NULL ) return;
    if ( filecache->filebase64 != NULL ) {
        delete filecache->filebase64;
        filecache->filebase64 = NULL;
    }
    
    if ( filecache->filedata != NULL ) {
        delete filecache->filedata;
        filecache->filedata = NULL;
    }
    if ( filecache->pages != NULL ) {
        vector<FZZBytes*>::const_iterator it;
        for (it = filecache->pages->begin(); it != filecache->pages->end(); it++) {
            if (*it != NULL) {
                delete* it;
            }
        }
        filecache->pages->clear();
        delete filecache->pages;
        filecache->pages = NULL;
    }
    
    free(filecache);
}
//-----------------------------------------------------------------------------------------------------------------
void AddFiles_base64(string fileid,string filedata)
{
    FILETEMPCACHE * filetempcache = NULL;
    map<string,FILETEMPCACHE*>::const_iterator it = g_FilesContainer.find(fileid);
    if (it != g_FilesContainer.end()) {
        filetempcache = it->second;
        if ( filetempcache != NULL && filetempcache->filebase64 != NULL ) {
            *(filetempcache->filebase64) += filedata;
        }
    } else {
        filetempcache = newFileTempCache();
        if ( filetempcache != NULL && filetempcache->filebase64 != NULL ) {
            *(filetempcache->filebase64) = filedata;
            g_FilesContainer.insert(pair<string,FILETEMPCACHE*>(fileid,filetempcache));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
void clearFiles_base64(string fileid)
{
    FILETEMPCACHE * filetempcache = NULL;
    map<string,FILETEMPCACHE*>::const_iterator it = g_FilesContainer.find(fileid);
    if (it != g_FilesContainer.end()) {
        filetempcache = it->second;
        if ( filetempcache != NULL  ) {
            *(filetempcache->filebase64) = "";
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
string getFiles_base64(string fileid)
{
    string ret = "";
    FILETEMPCACHE * filetempcache = NULL;
    map<string,FILETEMPCACHE*>::const_iterator it = g_FilesContainer.find(fileid);
    if (it != g_FilesContainer.end()) {
        filetempcache = it->second;
        if ( filetempcache != NULL  ) {
            ret = *(filetempcache->filebase64);
        }
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void AddFiles(string fileid,FZZBytes* filedata,int filetype)
{
    RenovateFiles();
    if ( filedata == NULL ) return;
    
    FILETEMPCACHE * filetempcache = NULL;
    map<string,FILETEMPCACHE*>::const_iterator it = g_FilesContainer.find(fileid);
    if (it != g_FilesContainer.end()) {
        filetempcache = it->second;
        if ( filetempcache != NULL && filetempcache->filedata ) {
            filetempcache->filetype = filetype;
            filetempcache->filedata->setData(filedata->getData(),filedata->getLen());
        }
    } else {
        filetempcache = newFileTempCache();
        if ( filetempcache != NULL ) {
            filetempcache->filetype = filetype;
            filetempcache->filedata->setData(filedata->getData(),filedata->getLen());
            g_FilesContainer.insert(pair<string,FILETEMPCACHE*>(fileid,filetempcache));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
void AddFiles_Page(string fileid,FZZBytes* Page)
{
    if ( Page == NULL ) return;
    
    FILETEMPCACHE * filetempcache = NULL;
    map<string,FILETEMPCACHE*>::const_iterator it = g_FilesContainer.find(fileid);
    if (it != g_FilesContainer.end()) {
        filetempcache = it->second;
        if ( filetempcache != NULL && filetempcache->pages != NULL ) {
            FZZBytes * temp = new FZZBytes(Page->getData(),Page->getLen());
            filetempcache->pages->push_back(temp);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
int getFiles_PageCount(string fileid)
{
    FILETEMPCACHE * filetempcache = NULL;
    int temp = 0;
    map<string,FILETEMPCACHE*>::const_iterator it = g_FilesContainer.find(fileid);
    if (it != g_FilesContainer.end()) {
        filetempcache = it->second;
        if ( filetempcache != NULL && filetempcache->pages != NULL ) {
            temp = filetempcache->pages->size();
        }
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes * getFiles_Page(string fileid,int pageIndex)
{
    FILETEMPCACHE * filetempcache = NULL;
    FZZBytes * temp = NULL;
    map<string,FILETEMPCACHE*>::const_iterator it = g_FilesContainer.find(fileid);
    if (it != g_FilesContainer.end()) {
        filetempcache = it->second;
        if ( filetempcache != NULL && filetempcache->pages != NULL ) {
            
            if ( pageIndex+1 <= filetempcache->pages->size() ) {
                temp = (*(filetempcache->pages))[pageIndex];
            }
        }
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes * getFiles_FileData(string fileid)
{
    FILETEMPCACHE * filetempcache = NULL;
    FZZBytes * temp = NULL;
    map<string,FILETEMPCACHE*>::const_iterator it = g_FilesContainer.find(fileid);
    if (it != g_FilesContainer.end()) {
        filetempcache = it->second;
        if ( filetempcache != NULL && filetempcache->filedata != NULL ) {
            temp = filetempcache->filedata;
        }
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
int getFiles_FileType(string fileid)
{
    FILETEMPCACHE * filetempcache = NULL;
    int temp = 0;
    map<string,FILETEMPCACHE*>::const_iterator it = g_FilesContainer.find(fileid);
    if (it != g_FilesContainer.end()) {
        filetempcache = it->second;
        if ( filetempcache != NULL ) {
            temp = filetempcache->filetype;
        }
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
void DeleteFiles(string fileid)
{
    FILETEMPCACHE * filetempcache = NULL;
    map<string,FILETEMPCACHE*>::const_iterator it = g_FilesContainer.find(fileid);
    if (it != g_FilesContainer.end()) {
        filetempcache = it->second;
        if ( filetempcache != NULL  ) {
            DeleteFileTempCache(filetempcache);
        }
        g_FilesContainer.erase(it);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void RenovateFiles()
{
    FILETEMPCACHE * filetempcache = NULL;
    map<string,FILETEMPCACHE*>::const_iterator it;
    time_t now;
    time(&now);
    vector<string> keys;
    for (it = g_FilesContainer.begin(); it != g_FilesContainer.end(); it++) {
        string temptime = it->first;
        temptime = temptime.substr(temptime.find("-")+1);
        if ( now - atol(temptime.c_str()) >= DIFFTIME ) {
            if ( filetempcache != NULL  ) {
                DeleteFileTempCache(filetempcache);
            }
            keys.push_back(it->first);
            //
        }
    }
    string tempkey = "";
    vector<string>::const_iterator keyit;
    for (keyit = keys.begin(); keyit != keys.end(); keyit++) {
        tempkey = *keyit;
        it = g_FilesContainer.find(tempkey);
        if (it != g_FilesContainer.end()) {
            g_FilesContainer.erase(it);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
string genFileID()
{
    char uuid[37] = {0};
    time_t now;
    
    string fileID = random_uuid(uuid);
    fileID = replace_all(fileID, "-","");
    
    
    time(&now);
    fileID = fileID + "-";
    fileID = fileID + fmt(now);
    return fileID;
}
//-----------------------------------------------------------------------------------------------------------------
string getGetParam(const struct mg_http_message *hm)
{
    string ret = "";
    char * buffer = (char*)malloc(hm->query.len+1);
    if ( buffer == NULL ) {
        return ret;
    }
    memset(buffer,0x00,hm->query.len+1);
    memcpy(buffer,hm->query.ptr,hm->query.len);
    ret = buffer;
    free(buffer);
    if ( ret.find_first_of("callback") != string::npos ) {
        string tempkey = "{";
        int pos = ret.find_first_of(tempkey);
        if ( pos != string::npos ) {
            string temp = ret.substr(pos);
            pos = temp.find_first_of("}");
            if ( pos != string::npos ) {
                ret = temp.substr(0,pos+1);
            }
        }
    }
    
    ret = replace_all(ret,"%22","\"");
    //ret = replace_all(ret,"\\\\","\"");
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
string replace_all(string str,const string old_value,const string new_value)
{
    string::size_type pos = 0;
    while((pos = str.find(old_value,pos))!= string::npos)
    {
        str = str.replace(pos, old_value.length(),new_value);
        if (new_value.length() > 0 ){
            pos += new_value.length();
        }
    }
    return  str;
}
//-----------------------------------------------------------------------------------------------------------------
bool readfile(QString srcfile,FZZBytes& outData)
{
    QFile tempfile(srcfile);
    if ( !tempfile.open(QFile::ReadOnly) ) {

        return false;
    }
    QByteArray temdata = tempfile.readAll();

    outData.setData((const unsigned char *)temdata.data(),temdata.size());
    tempfile.close();
    return outData.getLen() > 0 ? true : false;
}
//-----------------------------------------------------------------------------------------------------------------
bool writefile(QString srcfile,const unsigned char * const data,int len)
{
    QFile file(srcfile);
    if(file.open(QIODevice::WriteOnly)) {
        QByteArray wirtedata;
        wirtedata.resize(len);
        memcpy(wirtedata.data(),data,len);
        file.write(wirtedata);
        file.close();
    }
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
char* random_uuid(char buf[37])
{

    const char* c = "89ab";

    char* p = buf;

    int n;

    for (n = 0; n < 16; ++n)

    {

        int b = rand() % 255;

        switch (n)

        {

        case 6:

            sprintf(p, "4%x", b % 15);

            break;

        case 8:

            sprintf(p, "%c%x", c[rand() % strlen(c)], b % 15);

            break;

        default:

            sprintf(p, "%02x", b);

            break;

        }



        p += 2;

        switch (n)

        {

        case 3:

        case 5:

        case 7:

        case 9:

            *p++ = '-';

            break;

        }

    }

    *p = 0;

    return buf;
}
//-----------------------------------------------------------------------------------------------------------------
string fmt(double d)
{
    char buffer[200] = {0};
    if ((d - (int)(d)) == 0) {
        sprintf(buffer, "%ld", (long)d);
    }
    else {
        sprintf(buffer, "%.4lf", d);
    }

    string ret = buffer;
    
    int indexOf = ret.find_last_of('.');
    if (indexOf != string::npos) {
        int len = ret.length();
        for (int i = len-1; i > indexOf; i-- ) {
            if ( buffer[i] == '0' ) {
                buffer[i] = 0x00;
            } else {
                break;
            }
        }
        ret = buffer;
    }
    
    if ( ret[ret.length()-1] == '.' ) {
        ret = ret.substr(0,ret.length()-1);
    }
    return ret;

}
//-----------------------------------------------------------------------------------------------------------------
string fmt(int d)
{
    char buffer[200] = {0};
    sprintf(buffer, "%d", d);
    string ret = buffer;
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
string fmt(long d)
{
    char buffer[200] = {0};
    sprintf(buffer, "%ld", d);
    string ret = buffer;
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
string fmt(long long d)
{
    char buffer[200] = { 0 };
    sprintf(buffer, "%lld", d);
    string ret = buffer;
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void split(const char* src, const char* sep,std::vector<std::string> & rets)
{

//    if (s && strlen(s))
//    {
//        int len = strlen(s);
//        char* src = new char[len + 1];
//        strcpy(src, s);
//        src[len] = '\0';
//        char* tokenptr = strtok(src, delim);
//        while (tokenptr != NULL)
//        {
//            std::string tk = tokenptr;
//            rets.emplace_back(tk);
//            tokenptr = strtok(NULL, delim);
//        }
//        delete[] src;
//    }
    
    if( (src == NULL) || (sep == NULL) )   {
        return ;
    }
    int nMinLenSrc = strlen(src);
    int nMinLensep = strlen(sep);
    char *pNew = new char[nMinLenSrc + 1];
    if ( pNew == NULL) return;
    
    memset(pNew, 0, nMinLenSrc + 1);
    memcpy(pNew, src, nMinLenSrc);
    char *p = (char *)sep;
    char *q = (char *)pNew;
    int i = 0;
    int j = 0;
    while(*p != 0 && i < nMinLensep)    {
            q = pNew;
            for(j = 0; j < nMinLenSrc; j++)        {
                       if(*q == *p)
                       *q = 0;
                       q++;
            }
            p++;
            i++;
    }
    q = pNew;
    i = 0;
    while(i < nMinLenSrc)    {
            if(*q != 0)        {
                std::string tk = q;
                rets.emplace_back(tk);
                    i += strlen(q);
                    q = pNew + i;
            } else {
                i++;
                q++;
            }
     }
     delete [] pNew;
         

}
//-----------------------------------------------------------------------------------------------------------------
string Base64Encode(const unsigned char * const data,int len)
{
    char * buf1 = new char[len*3];
    memset(buf1,0x00,len*3);
    char * p = buf1;
    int plen = 0;
    mg_base64_encode(data, len, p);
    string ret = buf1;
    delete [] buf1;
    if ( ret[ret.length()-1] == 0x0A ) {
        ret = ret.substr(0,ret.length()-1);
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void Base64_decode(const char * base64str,int base64strlen,FZZBytes & out)
{
    char * buf2 = new char[base64strlen];
    memset(buf2,0x00,base64strlen);
    char * p= buf2;
    int len = mg_base64_decode(base64str,base64strlen,p);
    
    out.setData((unsigned char *)buf2, len);
    delete[] buf2;
}
//-----------------------------------------------------------------------------------------------------------------
