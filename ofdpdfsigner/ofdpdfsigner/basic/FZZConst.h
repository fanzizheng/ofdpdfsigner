//
//  Created by zizheng fan on 2021/11/25.
//
#ifndef FZZCONST_H
#define FZZCONST_H

#ifdef _MSC_VER
#include "pch.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <type_traits>
#include <mutex>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include "basic/tinyxml2.h"

using namespace tinyxml2;
using namespace std;

#include "basic/uuid.h"

#include <zlib.h>
#include "zip.h"
#ifndef MINIZIPNG
#include "ioapi_mem.h"
#endif
#include "unzip.h"

//There is no character mapping, so it is considered that the equal width ratio ASCII is 0.5 and the other 1 TOCLIENT cannot be used, or the problem of the skia memory management and the problem of the getpath() memory overwrite. TOCLIENT is only effective for fonts
//#define TOCLIENT
//Desktop Program Mode
#define CLIENTMODE

#define FONTCACHE

#define OLD_OFD


//#define OS_MAC_PC

typedef enum e_clear { none, CLEAR_left, CLEAR_right, both } Clear;
typedef enum e_AFloat {
    
    left,
    
    right,
     
    center
} AFloat;

typedef enum {
    
    Static,
    
    Relative,
     
    Absolute,
} Position;

typedef enum {
    
    SimSun,
    
    SimHei,
     
    MSYahei,
      
    KaiTi,
       
    FangSong,

        
    TimesNewRoman
} FontName;

typedef enum {
    Foreground = 5,
    Body = 3,
    Background = 1
} Type;

typedef enum {
    DO,
    PO,
    CLICK
} EventType;

typedef enum {
    XYZ,
    Fit,
    FitH,
    FitV,
    FitR
} DestType;

typedef enum {
    Play,
    Stop,
    Pause,
    Resume
} PlayType;

typedef enum {
    Normal,
    Column,
    Row,
    RowAndColumn
} ReflectMethod;

typedef enum {
    RelativeTo_Page,
    Object
} RelativeTo;

#include "basic/log.h"



//-------------------------------------------------------------------------------
#include "basic/FZZBytes.h"
#include "mupdf/fitz.h"


typedef int32_t FzUnichar;
typedef int32_t FzGlyphID;
#include "fzfont/FZZFontConfig.h"
#include "fzfont/FZZSystemFontList.h"





#include "basic/FZZZipTracks.h"
//#include "converter/utils/PdfiumLibInit.h"

#define nelen(x) (sizeof(x)/sizeof((x)[0]))

#define OFD_XMLHEADER "xml version=\"1.0\" encoding=\"UTF-8\""
#define OFD_NAMESPACE_URI "http://www.ofdspec.org/2016"
#define OFD_VERSION "1.2.3"
#define OFD_CREATOR "FZZ OFD"
#define OFD_COMPANY "FZZ"
#define WORD_COMPANY "FZZ WORD"

#define OFDFILENAME  "OFD.xml"
#define DOCCONTAINERPREFIX "Doc_"
#define DOCUMENTFILENAME "Document.xml"
#define PAGEPREFIX "Pages/Page_"
#define PAGECONTENTFILENAME "Content.xml"

#define MAXBUFLEN_READFILE 1048576
#define INCREMENT_BUFLEN_PNG 10240
//fzz add begin 2024.06.07
//sm2 p1 sign data len
#define MAXBUFLEN_SIGN 100
//fzz add end 2024.06.07

//#ifdef __APPLE__
//    #define SK_FONT_FILE_PREFIX "/Users/fzz/work/cpp/ofd/tmp/fonts/"
//    #define DEFAULTFONT "/Users/fzz/work/cpp/ofd/tmp/fonts/simsun.ttc"
//
//    #define PDFDEFAULTFONT_BLOD "/Users/fzz/work/cpp/ofd/tmp/pdffonts/simsun-blod.ttc"
//#elif __linux__
//    #define SK_FONT_FILE_PREFIX "/home/fzz/tools/OFDFonts"
//    #define DEFAULTFONT "/home/fzz/tools/OFDFonts/simsun.ttc"
//    #define PDFDEFAULTFONT_BLOD "/home/fzz/tools/PDFFonts/simsun-blod.ttc"
//#else
//    #define SK_FONT_FILE_PREFIX "C:/OFDFonts"
//    #define DEFAULTFONT "C:/OFDFonts/simsun.ttc"
//    #define PDFDEFAULTFONT_BLOD "C:/PDFFonts/simsun-blod.ttc"
//#endif

//#define MEMTEST

typedef struct S_OFD_COLOR {
    int r = 0;
    int g = 0;
    int b = 0;
} TOFDColor;

//seal callback func
typedef void (*CallBack_Sign)(const void * param,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
typedef void (*CallBack_getUserCert)(const void * param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
typedef void (*CallBack_getSealCert)(const void * param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
typedef bool (*CallBack_Verify)(const void * param,int algType,unsigned char * keyData,int keyDatalen,unsigned char * sourceData,int sourceDatalen,unsigned char * signData,int signDatalen);



typedef void (*CallBack_SystemFontFileNameFunc)(const void * param,const char* const fullFileName);

typedef void (*CallBack_EncryptSM4CBC)(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outEncData,/*out*/size_t * outEncDatalen);
typedef void (*CallBack_DecryptSM4CBC)(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * encData,int encDatalen,/*out*/unsigned char ** outDecData,/*out*/size_t * outDecDatalen);
typedef void (*CallBack_EncryptSM2)(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outEncData,/*out*/size_t * outEncDatalen);
typedef void (*CallBack_DecryptSM2)(const void * param,unsigned char * encData,int encDatalen,/*out*/unsigned char ** outDecData,/*out*/size_t * outDecDatalen);
typedef void (*CallBack_GenerateRandom)(const void * param,size_t len,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);

extern const fz_matrix MUPDF_fz_identity;

class FZZConst
{
public:
    static string Base64Encode(const unsigned char * const data,size_t len);
    static void Base64_decode(const char * base64str,size_t base64strlen,FZZBytes & out);
    static string HexEncode(const unsigned char * const data,size_t len);
    static string HexEncodeNoSpace(const unsigned char * const data,size_t len);
    static bool copyfile(string srcfile,string destfile);
    static int getFileSize(string srcfile);
    //static bool readfile(string srcfile,unsigned char * data,int len);
    static bool readfile(string srcfile,FZZBytes& outData);
    static bool writefile(string srcfile,const unsigned char * const data,size_t len);
    static bool deleteFile(string srcfile);
    //Split Chinese and English characters in a string
    static void splitWord(const string & word, vector<string> & characters);
    static string replace_all(string str,const string old_value,const string new_value);
    static string format_time_YYYY_MM_DD(time_t date);
    static string format_time_YYYY_MM_DD_hh_mm_ss(time_t date);
    static string format_time_YYYY_MM_DD_T_hh_mm_ss_Z(time_t date);
    static time_t StringToTime(string strdate);
    static string fmt(double d);
    static string fmt(int d);
    static string fmt(size_t d);
    static string fmt(long d);
    static string fmt(long long d);
    static string Trim(string data);
    static void split(const char* s, const char* delim,std::vector<std::string> & rets);
  
    //static FZZOFDObject* CopyPtr_OFDObject(FZZOFDObject*);
    //static PageBlockType* getInstance_PageBlockType(const char * const type, XMLDocument* m_doc, XMLNode* node);
    static string createuuid();
#ifdef _MSC_VER
    static wstring GB2312ToUTF16(string& source);
    static string UTF16ToGB2312(wstring& source);
    static wstring Utf8toUTF16(string& source);
    static string Utf16toUTF8(wstring& source);
    static string Utf8toGB2312(string& source);
    static string GB2312toUtf8(string& source);
#endif
    //One character. utf8 
    static uint32_t Utf8ToUtf32LE(string& source);
    //One character. utf8 
    static string Utf32LEToUtf8(uint32_t data);
    //One character
    //static uint16_t Utf8ToUtf16LE(string& source);
    //One character
    //static string Utf16LEToUtf8(wstring& source);
    static uint32_t BytesToUint32(const unsigned char * data, size_t datalen);
    static uint32_t BytesToUint32(const FZZBytes & data);
    static FZZBytes Uint32ToBytes(uint32_t value);
    static int code_convert(const char *from_charset,const char *to_charset,const char *inbuf, size_t inlen,char *outbuf, size_t outlen);
    static string getCurrPath();
    static void setCurrPath(string path);
    static string getDefaultFontPath();
    static string getDefaultFontFileName();
    static string getTempPath();
    static void setTempPath(string path);

    static void addClassCount(string classname);
    static void delClassCount(string classname);
    static void printClassCount();
    static int getClassCount(string classname);

    //static PdfiumLibInit g_PdfiumLibInit;

    static FZZFontConfig g_FZFontConfig;
    static FZZSystemFontList g_FZSystemFontList;

    //static FontContainer g_FontContainer;
    
private:
    
    static string g_CurrPath;
    static string g_TempPath;

#ifdef MEMTEST
    static std::map<string,int> g_classcount;
#endif
    
};

bool valueInRange(int value, int min, int max);
bool rectOverlap(fz_rect* A, fz_rect* B);

#endif //FZZCONST_H

