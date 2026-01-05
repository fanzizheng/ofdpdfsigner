//
//  Created by zizheng fan on 2021/11/25.
//
#include "basic/FZZConst.h"


#include "gmssl/base64.h"
#ifndef _MSC_VER 
#include <iconv.h>
#include <unistd.h>
#endif

#ifdef MEMTEST
std::map<string,int> FZZConst::g_classcount;
#endif
//PdfiumLibInit FZZConst::g_PdfiumLibInit;
//FontContainer FZZConst::g_FontContainer;


string FZZConst::g_CurrPath = "";
string FZZConst::g_TempPath = "";

FZZFontConfig FZZConst::g_FZFontConfig;
FZZSystemFontList FZZConst::g_FZSystemFontList;



const fz_matrix MUPDF_fz_identity = { 1, 0, 0, 1, 0, 0 };
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZConst*******************************************************/
//-----------------------------------------------------------------------------------------------------------------

void FZZConst::addClassCount(string classname)
{
#ifdef MEMTEST
    if ( FZZConst::g_classcount.count(classname) == 0 ) {
        //g_classcount.insert(map<string,int>::value_type(classname,1));
        FZZConst::g_classcount[classname] = 1;
    } else {
        FZZConst::g_classcount[classname] = FZZConst::g_classcount[classname] + 1;
    }
#endif
}
//-----------------------------------------------------------------------------------------------------------------
void FZZConst::delClassCount(string classname)
{
#ifdef MEMTEST
    if ( FZZConst::g_classcount.count(classname) == 0 ) {
        FZZConst::g_classcount[classname] = 0;
    } else {
        FZZConst::g_classcount[classname] = FZZConst::g_classcount[classname] - 1;
    }
#endif
}
//-----------------------------------------------------------------------------------------------------------------
void FZZConst::printClassCount()
{
#ifdef MEMTEST
    map<string, int>::iterator it;
    for (it = FZZConst::g_classcount.begin(); it != FZZConst::g_classcount.end(); ++it) {
        DLOG("class: %s count %d",it->first.c_str(),it->second);
    }
#endif
}
//-----------------------------------------------------------------------------------------------------------------
int FZZConst::getClassCount(string classname)
{
#ifdef MEMTEST
    return FZZConst::g_classcount[classname];
#else 
    return 0;
#endif
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::Base64Encode(const unsigned char * const data,size_t len)
{
    BASE64_CTX ctx;
    char * buf1 = new char[len*3];
    memset(buf1,0x00,len*3);
    unsigned char * p = (unsigned char *)buf1;
    int plen = 0;
    base64_encode_init(&ctx);
    base64_encode_update(&ctx, data, (int)len, p, &plen); p += plen;
    base64_encode_finish(&ctx, p, &plen); p += plen;
    plen = (int)(p - (unsigned char *)buf1);
    string ret = buf1;
    delete [] buf1;
    if ( ret[ret.length()-1] == 0x0A ) {
        ret = ret.substr(0,ret.length()-1);
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZConst::Base64_decode(const char * base64str,size_t base64strlen,FZZBytes & out)
{
    BASE64_CTX ctx;
    char * buf2 = new char[base64strlen];
    memset(buf2,0x00,base64strlen);
    char * p= buf2;
    int len = (int)base64strlen;
    base64_decode_init(&ctx);
    base64_decode_update(&ctx, (const unsigned char *)base64str, (int)base64strlen, (unsigned char *)p, &len); p += len;
    base64_decode_finish(&ctx, (unsigned char *)p, &len); p += len;
    len = (int)(p - buf2);
    
    out.setData((unsigned char *)buf2,len);
//    *datalen = len;
//    if ( data != NULL ) {
//        memcpy(data,buf2,len);
//    }
    delete [] buf2;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::HexEncode(const unsigned char * const data,size_t len)
{
    string ret = "";
    char buf[10] = {0};
    unsigned char *p = (unsigned char *)data;
    for (size_t i = 0; i < len; i++) {
        memset(buf,0x00,10);
        sprintf(buf,"%02x ",*p);
        p++;
        ret += buf;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::HexEncodeNoSpace(const unsigned char * const data,size_t len)
{
    string ret = "";
    char buf[10] = {0};
    unsigned char *p = (unsigned char *)data;
    for (size_t i = 0; i < len; i++) {
        memset(buf,0x00,10);
        sprintf(buf,"%02x",*p);
        p++;
        ret += buf;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZConst::copyfile(string srcfile,string destfile)
{
    fstream infd,outfd;
    infd.open(srcfile.c_str(),ios::binary|ios::in);
    if (!infd) {
        return false;
    }
    outfd.open(destfile.c_str(),ios::binary|ios::out);
    if ( !outfd ) {
        infd.close();
        return false;
    }
    char buf[1024] = {0};

    while(!infd.eof()) {
        infd.read(buf,1024);
        outfd.write(buf,infd.gcount());
    }
    infd.close();
    outfd.close();
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZConst::getFileSize(string srcfile)
{
    fstream infd;
    infd.open(srcfile.c_str(),ios::binary|ios::in);
    if (!infd) {
        return 0;
    }
    int len = 0;
    infd.seekg(0,infd.end);
    len = (int)infd.tellg();
    infd.close();
    return len;
}
//-----------------------------------------------------------------------------------------------------------------
//bool FZZConst::readfile(string srcfile,unsigned char * data,int len)
//{
//    fstream infd;
//    infd.open(srcfile.c_str(),ios::binary|ios::in);
//    if (!infd) {
//        return false;
//    }
//    char buf[10240] = {0};
//    int readlen = 0;
//    memset(data,0x00,len);
//    while(!infd.eof()) {
//        infd.read(buf,10240);
//        memcpy(data+readlen,buf,infd.gcount());
//        readlen+=infd.gcount();
//    }
//    infd.close();
//    return readlen < len ? true : false;
//}
//-----------------------------------------------------------------------------------------------------------------
bool FZZConst::readfile(string srcfile,FZZBytes& outData)
{
    ifstream file(srcfile.c_str(), ifstream::binary | ifstream::ate);
    if (!file.is_open()) {
        return false;
    }
  
    // 获取文件大小
    size_t maxsize = file.tellg();
    if (maxsize == -1) {
        return false;
    }
  
    // 重置文件指针到文件开头
    file.seekg(0, std::ios::beg);
    
    outData.setMaxLen(maxsize);
    
    if (!file.read((char *)outData.getData(), maxsize)) {
        return false;
    }
  
    // 关闭文件
    file.close();
    return outData.getLen() > 0 ? true : false;
    
}
//-----------------------------------------------------------------------------------------------------------------
//bool FZZConst::readfile(string srcfile,FZZBytes& outData)
//{
//
//    fstream infd;
//
//    infd.open(srcfile.c_str(),ios::binary|ios::in);
//
//    if (!infd) {
//
//        return false;
//    }
//
//    //char buf[MAXBUFLEN_READFILE] = {0};
//    char * buf = (char *)malloc(MAXBUFLEN_READFILE);
//    if ( buf == NULL ) {
//        return false;
//    }
//    int readlen = 0;
//
//    while(!infd.eof()) {
//        infd.read(buf,MAXBUFLEN_READFILE);
//
//        outData.addData((unsigned char *)buf, (int)infd.gcount());
//        readlen+=infd.gcount();
//    }
//    infd.close();
//    if ( buf != NULL ) {
//        free(buf);
//    }
//    return outData.getLen() > 0 ? true : false;
//}
//-----------------------------------------------------------------------------------------------------------------
bool FZZConst::writefile(string srcfile,const unsigned char * const data,size_t len)
{
    fstream outfd;
    outfd.open(srcfile.c_str(),ios::binary|ios::out);
    if ( !outfd ) {
        return false;
    }
    outfd.write((char *)data,len);
    outfd.close();
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZConst::deleteFile(string srcfile)
{
    return remove(srcfile.c_str()) == 0;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZConst::splitWord(const string & word, vector<string> & characters)
{
    size_t num = word.size();
    int i = 0;
    while(i < num)
    {
        int size;
        if(word[i] & 0x80)
        {
            if(word[i] & 0x20)
            {
                if(word[i] & 0x10)
                {
                    if(word[i] & 0x08)
                    {
                        if(word[i] & 0x04)
                        {
                                size = 6;
                        }else{
                            size = 5;
                        }
                    }else{
                        size = 4;
                    }
                }else{
                    size = 3;
                }
            }else{
                size = 2;
            }
        }else{
            size = 1;
        }
        string subWord;
        subWord = word.substr(i, size);
        characters.push_back(subWord);
        i += size;
    }
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::replace_all(string str,const string old_value,const string new_value)
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
string FZZConst::format_time_YYYY_MM_DD(time_t date)
{
    struct tm t;
#ifdef _MSC_VER
    localtime_s(&t, &date);
#else
    localtime_r(&date,&t);
#endif
    char buffer[20] = { 0 };
    //sprintf(buffer, "%d-%d-%d %d:%d:%d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
    sprintf(buffer, "%02d-%02d-%02d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
    return buffer;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::format_time_YYYY_MM_DD_hh_mm_ss(time_t date)
{
    struct tm t;
#ifdef _MSC_VER
    localtime_s(&t, &date);
#else
    localtime_r(&date, &t);
#endif
    char buffer[40] = { 0 };
    //sprintf(buffer, "%d-%d-%d %d:%d:%d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
    sprintf(buffer, "%02d-%02d-%02d %02d:%02d:%02d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
    
    return buffer;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::format_time_YYYY_MM_DD_T_hh_mm_ss_Z(time_t date)
{
    struct tm t;
#ifdef _MSC_VER
    localtime_s(&t, &date);
#else
    localtime_r(&date, &t);
#endif
    char buffer[40] = { 0 };
    //sprintf(buffer, "%d-%d-%d %d:%d:%d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
    sprintf(buffer, "%02d-%02d-%02dT%02d:%02d:%02dZ", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
    
    return buffer;
}
//-----------------------------------------------------------------------------------------------------------------
time_t FZZConst::StringToTime(string strdate)
{
    strdate = FZZConst::replace_all(strdate, "T", " ");
    strdate = FZZConst::replace_all(strdate, "Z", " ");
    struct tm t;
    
    size_t pos = strdate.find("-");
    if ( pos != string::npos ) {
        t.tm_year = atoi(strdate.substr(0,pos).c_str())-1900;
        strdate = strdate.substr(pos+1);
        pos = strdate.find("-");
        if ( pos != string::npos ) {
            t.tm_mon = atoi(strdate.substr(0,pos).c_str())-1;
            strdate = strdate.substr(pos+1);
            pos = strdate.find(" ");
            if ( pos != string::npos ) {
                t.tm_mday = atoi(strdate.substr(0,pos).c_str());
                strdate = strdate.substr(pos+1);
                pos = strdate.find(":");
                if ( pos != string::npos ) {
                    t.tm_hour = atoi(strdate.substr(0,pos).c_str());
                    strdate = strdate.substr(pos+1);
                    pos = strdate.find(":");
                    if ( pos != string::npos ) {
                        t.tm_min = atoi(strdate.substr(0,pos).c_str());
                        strdate = strdate.substr(pos+1);
                        pos = strdate.find(".");
                        if ( pos != string::npos ) {
                            t.tm_sec = atoi(strdate.substr(0,pos).c_str());
                            strdate = strdate.substr(pos+1);
                            if (strdate[strdate.length()-1] == ' ') {
                                strdate = strdate.substr(0,strdate.length()-1);
                            }
                            //t.tm_ = atoi(strdate.c_str());
                        } else {
                            if (strdate[strdate.length()-1] == ' ') {
                                strdate = strdate.substr(0,strdate.length()-1);
                            }
                            t.tm_sec = atoi(strdate.c_str());
                        }
                        
                    }
                }
            }
        }
    }
    
    time_t tdate = mktime(&t);
    return tdate;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::fmt(double d)
{
    char buffer[60] = {0};
    if ((d - (int)(d)) == 0) {
        sprintf(buffer, "%ld", (long)d);
    }
    else {
        sprintf(buffer, "%.4lf", d);
    }

    string ret = buffer;
    
    size_t indexOf = ret.find_last_of('.');
    if (indexOf != string::npos) {
        int len = (int)ret.length();
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
string FZZConst::fmt(int d)
{
//    char buffer[30] = {0};
//    sprintf(buffer, "%d", d);
//    string ret = buffer;
//    return ret;
    return std::to_string(d);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::fmt(size_t d)
{
//    char buffer[60] = {0};
//    sprintf(buffer, "%zu", d);
//    string ret = buffer;
//    return ret;
    
    return std::to_string(d);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::fmt(long d)
{
//    char buffer[60] = {0};
//    sprintf(buffer, "%ld", d);
//    string ret = buffer;
//    return ret;
    return std::to_string(d);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::fmt(long long d)
{
//    char buffer[120] = { 0 };
//    sprintf(buffer, "%lld", d);
//    string ret = buffer;
//    return ret;
    return std::to_string(d);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::Trim(string data)
{
    if ( data.empty() ) return "";
    data.erase(0,data.find_first_not_of(" "));
    data.erase(data.find_last_not_of(" ")+1);
    return data;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZConst::split(const char* src, const char* sep,std::vector<std::string> & rets)
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
    int nMinLenSrc = (int)strlen(src);
    int nMinLensep = (int)strlen(sep);
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

//-----------------------------------------------------------------------------------------------------------------
string FZZConst::createuuid()
{
    char uuid[37];
    string retuid  = random_uuid(uuid);
    retuid = FZZConst::replace_all(retuid, "-","");
    time_t now;
    time(&now);
    retuid = retuid + "-";
    retuid = retuid + FZZConst::fmt(now);
    return retuid;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZConst::code_convert(const char *from_charset,const char *to_charset,const char *inbuf, size_t inlen,char *outbuf, size_t outlen)
{
#ifndef _MSC_VER 
    iconv_t cd;

    const char **pin = &inbuf;

    char **pout = &outbuf;

    cd = iconv_open(to_charset,from_charset);

    if (cd==0) return -1;

    memset(outbuf,0,outlen);

    if (iconv(cd, (char **)pin, &inlen,pout, &outlen)==-1) {
        iconv_close(cd);
        return -1;
    }

    iconv_close(cd);
#endif
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
#ifdef _MSC_VER
wstring FZZConst::GB2312ToUTF16(string& source)
{
    wstring ret;
    size_t inlen = source.length();
    if (inlen > 0) {
        const char* inbuf = source.c_str();
        inlen = MultiByteToWideChar(CP_ACP, 0, inbuf, -1, NULL, 0);
        size_t outlen = inlen + 1;
        wchar_t* outbuf = new wchar_t[outlen];
        int wLen = MultiByteToWideChar(CP_ACP, 0, inbuf, -1, (wchar_t*)outbuf, outlen);
        ((wchar_t*)outbuf)[wLen] = 0x00;

        ret = outbuf;
        delete[] outbuf;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::UTF16ToGB2312(wstring& source)
{
    string ret;
    size_t inlen = source.length();
    if (inlen > 0) {
        const wchar_t* inbuf = source.c_str();
        size_t outlen = (inlen + 1)*2;
        char * outbuf = new char[outlen];
        int Len = WideCharToMultiByte(CP_ACP, 0, (wchar_t*)inbuf, inlen, outbuf, outlen, NULL, NULL);
        outbuf[Len] = 0x00;

        ret = outbuf;
        delete[] outbuf;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
wstring FZZConst::Utf8toUTF16(string& source)
{
    wstring ret;
    size_t inlen = source.length();
    if (inlen > 0) {
        const char* inbuf = source.c_str();
        size_t outlen = inlen + 1;
        wchar_t* outbuf = new wchar_t[outlen];
        int wLen = MultiByteToWideChar(CP_UTF8, 0, inbuf, inlen, (wchar_t*)outbuf, outlen);
        ((wchar_t*)outbuf)[wLen] = 0x00;

        ret = outbuf;
        delete[] outbuf;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::Utf16toUTF8(wstring& source)
{
    string ret;
    size_t inlen = source.length();
    if (inlen > 0) {
        const wchar_t* inbuf = source.c_str();
        
        inlen = WideCharToMultiByte(CP_UTF8, 0, (wchar_t*)inbuf, -1, NULL, 0, NULL, NULL);
        
        size_t outlen = (inlen + 1)*2;
        char * outbuf = new char[outlen];

        int Len = WideCharToMultiByte(CP_UTF8, 0, (wchar_t*)inbuf, -1, outbuf, outlen, NULL, NULL);
        outbuf[Len] = 0x00;
        ret = outbuf;
        delete[] outbuf;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::Utf8toGB2312(string& source)
{
    string ret;
    wstring wstr = Utf8toUTF16(source);
    ret = UTF16ToGB2312(wstr);
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::GB2312toUtf8(string& source)
{
    wstring wstr =  GB2312ToUTF16(source);
    string ret = Utf16toUTF8(wstr);
    return ret;
}
#endif
//-----------------------------------------------------------------------------------------------------------------
uint32_t FZZConst::Utf8ToUtf32LE(string& source)
{
    
#ifdef _MSC_VER
    const char* inbuf = source.c_str();
    size_t inlen = source.length();
    if (inlen == 0 ) {
        return 0;
    }
    size_t outlen = inlen + 1;
    wchar_t* outbuf = new wchar_t[outlen]; //wchar_t 2字节，UTF-32 4字节

    int wLen = MultiByteToWideChar(CP_ACP, 0, inbuf, inlen, (wchar_t*)outbuf, outlen);
    ((wchar_t*)outbuf)[wLen] = 0x00;

    uint32_t ret = 0;
    uint16_t* tempret = (uint16_t*)&ret;
    tempret[0] = outbuf[0];
    tempret[1] = 0;
    delete[] outbuf;
    return ret;
#else 
    
    const char * inbuf = source.c_str();
    size_t inlen = source.length();
    if (inlen <= 0 ) {
        return 0;
    }
    //size_t outlen = inlen+1;
    uint32_t outbuf[2] = {0};
    code_convert("UTF-8","UTF-32LE",inbuf,inlen+1,(char *)outbuf,sizeof(uint32_t)*2);
    uint32_t ret = outbuf[0];
    return ret;
#endif
     
    
//    uint32_t utf32 = 0;
//    int bytes_read = 0;
//    for (size_t i = 0; i < source.length(); ++i) {
//        if (bytes_read < 1) {
//            if ((source[i] & 0x80) == 0) {
//                // ASCII字符，无需转换
//                utf32 = source[i];
//            } else if ((source[i] & 0xE0) == 0xC0) {
//                // 2字节UTF-8字符
//                utf32 = (source[i] & 0x1F) << 6;
//                bytes_read = 1;
//            } else if ((source[i] & 0xF0) == 0xE0) {
//                // 3字节UTF-8字符
//                utf32 = (source[i] & 0x0F) << 12;
//                bytes_read = 2;
//            } else if ((source[i] & 0xF8) == 0xF0) {
//                // 4字节UTF-8字符
//                utf32 = (source[i] & 0x07) << 18;
//                bytes_read = 3;
//            } else {
//                // 非法的UTF-8编码
//                utf32 = static_cast<uint32_t>('?');
//                return utf32;
//            }
//        } else {
//            // 读取剩余的字节
//            utf32 += (source[i] & 0x3F) << (6 * --bytes_read);
//            if (bytes_read == 0) {
//                // 将UTF-32字符写入UTF-32字符串
//                return utf32;
//            }
//        }
//    }
//    return utf32;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::Utf32LEToUtf8(uint32_t data)
{
#ifdef _MSC_VER
    uint16_t* tempdata = (uint16_t*)&data;
    wchar_t inbuf[2] = { 0 };
    inbuf[0] = tempdata[0];
    size_t inlen = 1;

    size_t outlen = (inlen + 1) * 2 * 2;
    char* outbuf = new char[outlen];

    int Len = WideCharToMultiByte(CP_ACP, 0, (wchar_t*)inbuf, inlen, outbuf, outlen, NULL, NULL);
    outbuf[Len] = 0x00;
    string ret = outbuf;
    delete[] outbuf;
    return ret;
#else
    //const wchar_t * inbuf = source.c_str();
    size_t inlen = 16;
    char inbuf[16] = { 0 };
    uint32_t* tempp = (uint32_t*)inbuf;
    tempp[0] = data;
    
    size_t outlen = (1+1)*2*2;
    char* outbuf = new char[outlen];
    code_convert("UTF-32LE", "UTF-8",(char *)inbuf,inlen,outbuf,outlen);
    string ret = outbuf;
    delete [] outbuf;
    
    return ret;
#endif
}
//-----------------------------------------------------------------------------------------------------------------
//uint16_t FZZConst::Utf8ToUtf16LE(string& source)
//{
//    const char * inbuf = source.c_str();
//    size_t inlen = source.length();
//    if (inlen == 0 || inlen > 1) {
//        return 0;
//    }
//    size_t outlen = inlen+1;
//    uint16_t outbuf[2] = {0}; //wchar_t 2字节，UTF-32 4字节
//    code_convert("UTF-8","UTF-16LE",inbuf,inlen,(char *)outbuf, sizeof(uint16_t)*2);
//    uint16_t ret = outbuf[0];
// 
//    return ret;
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZConst::Utf16LEToUtf8(wstring& source)
//{
//    const wchar_t * inbuf = source.c_str();
//    size_t inlen = source.length();
//    if (inlen == 0 || inlen > 1) {
//        return 0;
//    }
//    size_t outlen = (inlen+1)*2;
//    char* outbuf = new char[outlen];
//    code_convert("UTF-16LE", "UTF-8",(char *)inbuf,inlen,outbuf,outlen);
//    string ret = outbuf;
//    delete [] outbuf;
//    
//    return ret;
//}
//-----------------------------------------------------------------------------------------------------------------
uint32_t FZZConst::BytesToUint32(const unsigned char * data, size_t datalen)
{
    uint32_t ret = 0;
    
    if ( datalen > 4 ) {
        return -9999;
    }
    
    const unsigned char * bytes = data;
    size_t templen = datalen;
    if ( templen == 4 ) {
        ret = (uint32_t)(((unsigned char)bytes[3] << 24) |
                         ((unsigned char)bytes[2] << 16) |
                         ((unsigned char)bytes[1] << 8) |
                         (unsigned char)bytes[0]);
    } else if (templen == 1 ) {
        ret = (uint32_t)((unsigned char)bytes[0]);
    } else if (templen == 2 ) {
        ret = (uint32_t)(((unsigned char)bytes[1] << 8) |
                         (unsigned char)bytes[0]);
    } else if (templen == 3 ) {
        ret = (uint32_t)(((unsigned char)bytes[2] << 16) |
                         ((unsigned char)bytes[1] << 8) |
                         (unsigned char)bytes[0]);
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
uint32_t FZZConst::BytesToUint32(const FZZBytes & data)
{
    return FZZConst::BytesToUint32(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZConst::Uint32ToBytes(uint32_t value)
{
    FZZBytes ret;
    
    int charlen = 0;
    
    unsigned char bytes[4] = {0,0,0,0};
    bytes[0] = 0xFF & value;
    unsigned int temp = 0xFF00 & value;
    bytes[1] = temp >> 8;
    temp = 0xFF0000 & value;
    bytes[2] = temp >> 16;
    temp = 0xFF000000 & value;
    bytes[3] = temp >> 24;
    
    if ( bytes[3] == 0 ) {
        charlen = 3;
        if ( bytes[2] == 0 ) {
            charlen = 2;
            if ( bytes[1] == 0 ) {
                charlen = 1;
            }
        }
    }
    
    ret.setData(bytes, charlen);
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZConst::setCurrPath(string path)
{
    g_CurrPath = path;
    FZZConst::g_FZSystemFontList.addDefaultFont();

}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::getCurrPath()
{
    if ( g_CurrPath.empty() ) {
#ifdef _MSC_VER
        char szPath[512] = {0};
        if (GetModuleFileNameA(NULL, szPath, 512))
        {
            string temppath = szPath;
            temppath = FZZConst::replace_all(temppath, "\\", "/");
            int pos = temppath.find_last_of("/");
            if (pos != string::npos) {
                g_CurrPath = temppath.substr(0, pos);
            }
            else {
                g_CurrPath = temppath;
            }
        }
#else
        char * tempchar = getcwd(NULL,0);
        if ( tempchar == NULL ) {
            DLOG("error : run path is NULL!");
        } else {
            g_CurrPath = tempchar;
            free(tempchar);
            tempchar = NULL;
        }
#endif
    }
    //DLOG("getCurrPath：%s",g_CurrPath.c_str());
    return g_CurrPath;
}
//-----------------------------------------------------------------------------------------------------------------
//aa
void FZZConst::setTempPath(string path)
{
    g_TempPath = path;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::getTempPath()
{
    if ( g_TempPath.empty() ) {
#ifdef _MSC_VER
        char szPath[512] = {0};
        if (GetTempPathA(512, szPath))
        {
            string temppath = szPath;
            temppath = FZZConst::replace_all(temppath, "\\", "/");
            int pos = temppath.find_last_of("/");
            if (pos != string::npos) {
                g_TempPath = temppath.substr(0, pos);
            }
            else {
                g_TempPath = temppath;
            }
        }
#elif __linux__
        //sudo mkdir /mnt/memdiv
        //sudo mount -t tmpfs -o size=4096m tmpfs /mnt/memdiv
        g_TempPath= "/mnt/memdiv";
#else
        char * tempchar = getcwd(NULL,0);
        if ( tempchar == NULL ) {
            DLOG("error : run path is NULL!");
        } else {
            g_TempPath = tempchar;
            free(tempchar);
            tempchar = NULL;
        }
#endif
    }
    DLOG("getCurrPath：%s",g_TempPath.c_str());
    return g_TempPath;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::getDefaultFontPath()
{
    string ret = FZZConst::getCurrPath();
#ifdef __APPLE__
    #ifdef OS_MAC_PC
        ret += "/Resources/OFDFonts/";
    #else
        ret += "/OFDFonts/";
    #endif
#else
    ret += "/OFDFonts/";
#endif
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZConst::getDefaultFontFileName()
{
    string ret = FZZConst::getCurrPath();

#ifdef __APPLE__
    #ifdef OS_MAC_PC
        ret += "/Resources/OFDFonts/simsun.ttf";
    #else
        ret += "/OFDFonts/simsun.ttf";
    #endif
#else
    ret += "/OFDFonts/simsun.ttf";
#endif
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
bool valueInRange(int value, int min, int max)
{ return (value >= min) && (value <= max); }

bool rectOverlap(fz_rect* A, fz_rect* B)
{
    bool xOverlap = valueInRange(A->x0, B->x0, B->x1) ||
                    valueInRange(B->x0, A->x0, A->x1);

    bool yOverlap = valueInRange(A->y0, B->y0, B->y1) ||
                    valueInRange(B->y0, A->y0, A->y1);

    return xOverlap && yOverlap;
}
//-----------------------------------------------------------------------------------------------------------------

//PageBlockType* FZZConst::getInstance_PageBlockType(const char * const type, XMLDocument* m_doc, XMLNode* node)
//{
//    PageBlockType* res = NULL;
//    if (strcmp(type, "ofd:Layer") == 0) {
//        res = new CT_Layer(m_doc, node,);
//
//    }
//    else if (strcmp(type, "ofd:PageBlock") == 0) {
//        res = new CT_PageBlock(m_doc, node);
//    }
//    return res;
//}
//-----------------------------------------------------------------------------------------------------------------
//FZZOFDObject* FZZConst::CopyPtr_OFDObject(FZZOFDObject* data)
//{
//
//    if (data == NULL) return NULL;
//    FZZOFDObject* tempptr = NULL;
//
//    if (dynamic_cast<Document*>(data) != NULL) {
//        tempptr = new Document(*((Document*)data));
//        return tempptr;
//    }
//
//    if (dynamic_cast<OFD*>(data) != NULL) {
//        tempptr = new OFD(*((OFD*)data));
//        return tempptr;
//    }
//
//    tempptr = new FZZOFDObject(*data);
//    return tempptr;
//}
//-----------------------------------------------------------------------------------------------------------------

