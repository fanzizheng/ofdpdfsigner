//
//  Created by zizheng fan on 2023/04/02.
//
#include "basic/FZZConst.h"
#include "office/docx/FZZFileMagic.h"
#include "office/docx/FZZDocXConst.h"

unsigned char FZZFileMagic::HEAD_OLE2[] = {0xD0,0xCF,0x11,0xE0,0xA1,0xB1,0x1A,0xE1};
unsigned char FZZFileMagic::HEAD_OOXML[] = {0x50, 0x4b, 0x03, 0x04};
unsigned char FZZFileMagic::HEAD_XML[] = {0x3c, 0x3f, 0x78, 0x6d, 0x6c};
unsigned char FZZFileMagic::HEAD_BIFF2[] = {
        0x09, 0x00, // sid=0x0009
        0x04, 0x00, // size=0x0004
        0x00, 0x00, // unused
        '?', 0x00  // '?' = multiple values
};
unsigned char FZZFileMagic::HEAD_BIFF3[] = {
    0x09, 0x02, // sid=0x0209
    0x06, 0x00, // size=0x0006
    0x00, 0x00, // unused
    '?', 0x00  // '?' = multiple values
};
/** BIFF4 raw stream - for Excel 4 */
unsigned char FZZFileMagic::HEAD_BIFF4[] = {
    0x09, 0x04, // sid=0x0409
    0x06, 0x00, // size=0x0006
    0x00, 0x00, // unused
    '?', 0x00  // '? = multiple values
};
unsigned char FZZFileMagic::HEAD_BIFF4_1[] = {
    0x09, 0x04, // sid=0x0409
    0x06, 0x00, // size=0x0006
    0x00, 0x00, // unused
    0x00, 0x01
};
/** Old MS Write raw stream */
unsigned char FZZFileMagic::HEAD_MSWRITE[] = {0x31, 0xbe, 0x00, 0x00 };
unsigned char FZZFileMagic::HEAD_MSWRITE_1[] = {0x32, 0xbe, 0x00, 0x00 };
/** RTF document */
unsigned char FZZFileMagic::HEAD_RTF[] = {'{','\\','r','t','f'};
/** PDF document */
unsigned char FZZFileMagic::HEAD_PDF[] = { '%','P','D','F'};
/** Some different HTML documents */
unsigned char FZZFileMagic::HEAD_HTML[] = {'<','!','D','O','C','T','Y','P'};
unsigned char FZZFileMagic::HEAD_HTML_1[] = {'<','h','t','m','l'};
unsigned char FZZFileMagic::HEAD_HTML_2[] = {'\n','\r','<','h','t','m','l'};
unsigned char FZZFileMagic::HEAD_HTML_3[] = {'\r','\n','<','h','t','m','l'};
unsigned char FZZFileMagic::HEAD_HTML_4[] = {'\r','<','h','t','m','l'};
unsigned char FZZFileMagic::HEAD_HTML_5[] = {'\n','<','h','t','m','l'};
unsigned char FZZFileMagic::HEAD_HTML_6[] = {'<','H','T','M','L'};
unsigned char FZZFileMagic::HEAD_HTML_7[] = {'\r','\n','<','H','T','M','L'};
unsigned char FZZFileMagic::HEAD_HTML_8[] = {'\n','\r','<','H','T','M','L'};
unsigned char FZZFileMagic::HEAD_HTML_9[] = {'\r','<','H','T','M','L'};
unsigned char FZZFileMagic::HEAD_HTML_10[] = {'\n','<','H','T','M','L'};
unsigned char FZZFileMagic::HEAD_WORD2[] = {0xdb, 0xa5, 0x2d, 0x00};
/** JPEG image */
unsigned char FZZFileMagic::HEAD_JPEG[] = { 0xFF, 0xD8, 0xFF, 0xDB };
unsigned char FZZFileMagic::HEAD_JPEG_1[] = { 0xFF, 0xD8, 0xFF, 0xE0, '?', '?', 'J', 'F', 'I', 'F', 0x00, 0x01 };
unsigned char FZZFileMagic::HEAD_JPEG_2[] = { 0xFF, 0xD8, 0xFF, 0xEE };
unsigned char FZZFileMagic::HEAD_JPEG_3[] = { 0xFF, 0xD8, 0xFF, 0xE1, '?', '?', 'E', 'x', 'i', 'f', 0x00, 0x00 };
/** GIF image */
unsigned char FZZFileMagic::HEAD_GIF[] = {'G', 'I', 'F', '8', '7', 'a'};
unsigned char FZZFileMagic::HEAD_GIF_1[] = {'G', 'I', 'F', '8', '9', 'a'};
/** PNG Image */
unsigned char FZZFileMagic::HEAD_PNG[] = {0x89, 'P', 'N', 'G', 0x0D, 0x0A, 0x1A, 0x0A};
/** TIFF Image */
unsigned char FZZFileMagic::HEAD_TIFF[] = {'I', 'I', '*', 0x00};
unsigned char FZZFileMagic::HEAD_TIFF_1[] = {'M', 'M', 0x00, '*' };
/** WMF image with a placeable header */
unsigned char FZZFileMagic::HEAD_WMF[] = {0xD7, 0xCD, 0xC6, 0x9A};
/** EMF image */
unsigned char FZZFileMagic::HEAD_EMF[] = {0x01, 0x00, 0x00, 0x00,
    '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
    '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?',
    ' ', 'E', 'M', 'F'};
/** BMP image */
unsigned char FZZFileMagic::HEAD_BMP[] = {'B','M'};

int FZZFileMagic::MAX_PATTERN_LENGTH = 44;
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZFileMagic**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZFileMagic::FZZFileMagic()
{
    //DLOG("FZZFileMagic()");
    FZZConst::addClassCount("FZZFileMagic");
    
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
FZZFileMagic::~FZZFileMagic()
{
    //DLOG("~FZZFileMagic()");
    FZZConst::delClassCount("FZZFileMagic");
    
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZFileMagic::findMagic(const unsigned char * const expected, const unsigned char * const actual,int count)
{
    for ( int i = 0; i < count; i++ ) {
        if (actual[i] != expected[i] && expected[i] != '?') {
            return false;
        }
    }
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
FZZFileMagic::TYPE FZZFileMagic::valueOf(FZZBytes & magic)
{
    FZZFileMagic::TYPE retType = FZZFileMagic::TYPE::UNKNOWN;
    FZZBytes tempMagic;
    if ( magic.getLen() > MAX_PATTERN_LENGTH ) {
        tempMagic.setData(magic.getData(), MAX_PATTERN_LENGTH);
    } else {
        tempMagic.setData(magic.getData(), magic.getLen());
    }
    size_t tempMagicLen = tempMagic.getLen();
    unsigned char * tempMagicData = tempMagic.getData();
    
    if ( tempMagicLen >= sizeof(HEAD_OLE2) && findMagic(HEAD_OLE2, tempMagicData,sizeof(HEAD_OLE2)) ) {
        retType = FZZFileMagic::TYPE::OLE2;
    } else if ( tempMagicLen >= sizeof(HEAD_OOXML) && findMagic(HEAD_OOXML, tempMagicData,sizeof(HEAD_OOXML)) ) {
        retType = FZZFileMagic::TYPE::OOXML;
    } else if ( tempMagicLen >= sizeof(HEAD_XML) && findMagic(HEAD_XML, tempMagicData,sizeof(HEAD_XML)) ) {
        retType = FZZFileMagic::TYPE::XML;
    } else if ( tempMagicLen >= sizeof(HEAD_BIFF2) && findMagic(HEAD_BIFF2, tempMagicData,sizeof(HEAD_BIFF2)) ) {
        retType = FZZFileMagic::TYPE::BIFF2;
    } else if ( tempMagicLen >= sizeof(HEAD_BIFF3) && findMagic(HEAD_BIFF3, tempMagicData,sizeof(HEAD_BIFF3)) ) {
        retType = FZZFileMagic::TYPE::BIFF3;
    } else if ( tempMagicLen >= sizeof(HEAD_BIFF4) && findMagic(HEAD_BIFF4, tempMagicData,sizeof(HEAD_BIFF4)) ) {
        retType = FZZFileMagic::TYPE::BIFF4;
    } else if ( tempMagicLen >= sizeof(HEAD_BIFF4_1) && findMagic(HEAD_BIFF4_1, tempMagicData,sizeof(HEAD_BIFF4_1)) ) {
        retType = FZZFileMagic::TYPE::BIFF4;
    } else if ( tempMagicLen >= sizeof(HEAD_MSWRITE) && findMagic(HEAD_MSWRITE, tempMagicData,sizeof(HEAD_MSWRITE)) ) {
        retType = FZZFileMagic::TYPE::MSWRITE;
    } else if ( tempMagicLen >= sizeof(HEAD_MSWRITE_1) && findMagic(HEAD_MSWRITE_1, tempMagicData,sizeof(HEAD_MSWRITE_1)) ) {
        retType = FZZFileMagic::TYPE::MSWRITE;
    } else if ( tempMagicLen >= sizeof(HEAD_RTF) && findMagic(HEAD_RTF, tempMagicData,sizeof(HEAD_RTF)) ) {
        retType = FZZFileMagic::TYPE::RTF;
    } else if ( tempMagicLen >= sizeof(HEAD_PDF) && findMagic(HEAD_PDF, tempMagicData,sizeof(HEAD_PDF)) ) {
        retType = FZZFileMagic::TYPE::PDF;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML) && findMagic(HEAD_HTML, tempMagicData,sizeof(HEAD_HTML)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML_1) && findMagic(HEAD_HTML_1, tempMagicData,sizeof(HEAD_HTML_1)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML_2) && findMagic(HEAD_HTML_2, tempMagicData,sizeof(HEAD_HTML_2)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML_3) && findMagic(HEAD_HTML_3, tempMagicData,sizeof(HEAD_HTML_3)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML_4) && findMagic(HEAD_HTML_4, tempMagicData,sizeof(HEAD_HTML_4)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML_5) && findMagic(HEAD_HTML_5, tempMagicData,sizeof(HEAD_HTML_5)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML_6) && findMagic(HEAD_HTML_6, tempMagicData,sizeof(HEAD_HTML_6)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML_7) && findMagic(HEAD_HTML_7, tempMagicData,sizeof(HEAD_HTML_7)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML_8) && findMagic(HEAD_HTML_8, tempMagicData,sizeof(HEAD_HTML_8)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML_9) && findMagic(HEAD_HTML_9, tempMagicData,sizeof(HEAD_HTML_9)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_HTML_10) && findMagic(HEAD_HTML_10, tempMagicData,sizeof(HEAD_HTML_10)) ) {
        retType = FZZFileMagic::TYPE::HTML;
    } else if ( tempMagicLen >= sizeof(HEAD_WORD2) && findMagic(HEAD_WORD2, tempMagicData,sizeof(HEAD_WORD2)) ) {
        retType = FZZFileMagic::TYPE::WORD2;
    } else if ( tempMagicLen >= sizeof(HEAD_JPEG) && findMagic(HEAD_JPEG, tempMagicData,sizeof(HEAD_JPEG)) ) {
        retType = FZZFileMagic::TYPE::JPEG;
    } else if ( tempMagicLen >= sizeof(HEAD_JPEG_1) && findMagic(HEAD_JPEG_1, tempMagicData,sizeof(HEAD_JPEG_1)) ) {
        retType = FZZFileMagic::TYPE::JPEG;
    } else if ( tempMagicLen >= sizeof(HEAD_JPEG_2) && findMagic(HEAD_JPEG_2, tempMagicData,sizeof(HEAD_JPEG_2)) ) {
        retType = FZZFileMagic::TYPE::JPEG;
    } else if ( tempMagicLen >= sizeof(HEAD_JPEG_3) && findMagic(HEAD_JPEG_3, tempMagicData,sizeof(HEAD_JPEG_3)) ) {
        retType = FZZFileMagic::TYPE::JPEG;
    } else if ( tempMagicLen >= sizeof(HEAD_GIF) && findMagic(HEAD_GIF, tempMagicData,sizeof(HEAD_GIF)) ) {
        retType = FZZFileMagic::TYPE::GIF;
    } else if ( tempMagicLen >= sizeof(HEAD_GIF_1) && findMagic(HEAD_GIF_1, tempMagicData,sizeof(HEAD_GIF_1)) ) {
        retType = FZZFileMagic::TYPE::GIF;
    } else if ( tempMagicLen >= sizeof(HEAD_PNG) && findMagic(HEAD_PNG, tempMagicData,sizeof(HEAD_PNG)) ) {
        retType = FZZFileMagic::TYPE::PNG;
    } else if ( tempMagicLen >= sizeof(HEAD_TIFF) && findMagic(HEAD_TIFF, tempMagicData,sizeof(HEAD_TIFF)) ) {
        retType = FZZFileMagic::TYPE::TIFF;
    } else if ( tempMagicLen >= sizeof(HEAD_TIFF_1) && findMagic(HEAD_TIFF_1, tempMagicData,sizeof(HEAD_TIFF_1)) ) {
        retType = FZZFileMagic::TYPE::TIFF;
    } else if ( tempMagicLen >= sizeof(HEAD_WMF) && findMagic(HEAD_WMF, tempMagicData,sizeof(HEAD_WMF)) ) {
        retType = FZZFileMagic::TYPE::WMF;
    } else if ( tempMagicLen >= sizeof(HEAD_EMF) && findMagic(HEAD_EMF, tempMagicData,sizeof(HEAD_EMF)) ) {
        retType = FZZFileMagic::TYPE::EMF;
    } else if ( tempMagicLen >= sizeof(HEAD_BMP) && findMagic(HEAD_BMP, tempMagicData,sizeof(HEAD_BMP)) ) {
        retType = FZZFileMagic::TYPE::BMP;
    } else {
        retType = FZZFileMagic::TYPE::UNKNOWN;
    }
    
    return retType;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZFileMagic::getContentTypeFromFileExtension(string filename)
{
    size_t pos = filename.find_last_of(".");
    string format = "";
    if ( pos != string::npos ) {
        format = filename.substr(pos+1);
    }
    transform(format.begin(), format.end(), format.begin(), ::tolower);
    if ( format == CONTENTTYPES_EXTENSION_JPG_1 || format == CONTENTTYPES_EXTENSION_JPG_2 ) {
        return CONTENTTYPES_IMAGE_JPEG;
    } else if ( format == CONTENTTYPES_EXTENSION_GIF ) {
        return CONTENTTYPES_IMAGE_GIF;
    } else if ( format == CONTENTTYPES_EXTENSION_PICT ) {
        return CONTENTTYPES_IMAGE_PICT;
    } else if ( format == CONTENTTYPES_EXTENSION_PNG ) {
        return CONTENTTYPES_IMAGE_PNG;
    } else if ( format == CONTENTTYPES_EXTENSION_TIFF ) {
        return CONTENTTYPES_IMAGE_TIFF;
    } else if ( format == CONTENTTYPES_EXTENSION_XML ) {
        return CONTENTTYPES_XML;
    } else {
        return "";
    }
}
//-----------------------------------------------------------------------------------------------------------------
string FZZFileMagic::getFileExtension(string filename)
{
    size_t pos = filename.find_last_of(".");
    string format = "";
    if ( pos != string::npos ) {
        format = filename.substr(pos+1);
    }
    transform(format.begin(), format.end(), format.begin(), ::tolower);
    if ( format == CONTENTTYPES_EXTENSION_JPG_1 || format == CONTENTTYPES_EXTENSION_JPG_2 ) {
        return CONTENTTYPES_EXTENSION_JPG_1;
    } else if ( format == CONTENTTYPES_EXTENSION_GIF ) {
        return CONTENTTYPES_EXTENSION_GIF;
    } else if ( format == CONTENTTYPES_EXTENSION_PICT ) {
        return CONTENTTYPES_EXTENSION_PICT;
    } else if ( format == CONTENTTYPES_EXTENSION_PNG ) {
        return CONTENTTYPES_EXTENSION_PNG;
    } else if ( format == CONTENTTYPES_EXTENSION_TIFF ) {
        return CONTENTTYPES_EXTENSION_TIFF;
    } else if ( format == CONTENTTYPES_EXTENSION_XML ) {
        return CONTENTTYPES_EXTENSION_XML;
    } else {
        return "";
    }
}
//-----------------------------------------------------------------------------------------------------------------
string FZZFileMagic::getContentTypeFromFileTYPE(FZZFileMagic::TYPE type)
{
    if ( type == FZZFileMagic::TYPE::JPEG ) {
        return CONTENTTYPES_IMAGE_JPEG;
    } else if ( type == FZZFileMagic::TYPE::GIF ) {
        return CONTENTTYPES_IMAGE_GIF;
    //} else if ( format == CONTENTTYPES_EXTENSION_PICT ) {
    //    return CONTENTTYPES_IMAGE_PICT;
    } else if ( type == FZZFileMagic::TYPE::PNG ) {
        return CONTENTTYPES_IMAGE_PNG;
    } else if ( type == FZZFileMagic::TYPE::TIFF ) {
        return CONTENTTYPES_IMAGE_TIFF;
    } else if ( type == FZZFileMagic::TYPE::XML ) {
        return CONTENTTYPES_XML;
    } else {
        return "";
    }
}
//-----------------------------------------------------------------------------------------------------------------
string FZZFileMagic::getFileExtensionFromFileTYPE(FZZFileMagic::TYPE type)
{
    if ( type == FZZFileMagic::TYPE::JPEG ) {
        return CONTENTTYPES_EXTENSION_JPG_1;
    } else if ( type == FZZFileMagic::TYPE::GIF ) {
        return CONTENTTYPES_EXTENSION_GIF;
    //} else if ( type == FZZFileMagic::TYPE::PICT ) {
    //    return CONTENTTYPES_EXTENSION_PICT;
    } else if ( type == FZZFileMagic::TYPE::PNG ) {
        return CONTENTTYPES_EXTENSION_PNG;
    } else if ( type == FZZFileMagic::TYPE::TIFF ) {
        return CONTENTTYPES_EXTENSION_TIFF;
    } else if ( type == FZZFileMagic::TYPE::XML ) {
        return CONTENTTYPES_EXTENSION_XML;
    } else {
        return "";
    }
}
//-----------------------------------------------------------------------------------------------------------------
