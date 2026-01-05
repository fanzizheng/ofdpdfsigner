//
//  Created by zizheng fan on 2023/04/02.
//
#ifndef FZZFILEMAGIC_H
#define FZZFILEMAGIC_H

//#include "office/poifs/storage/HeaderBlockConstants.h"

class FZZFileMagic
{
public:
    typedef enum {
        UNKNOWN,
        /** OLE2 / BIFF8+ stream used for Office 97 and higher documents */
        OLE2,
        /** OOXML / ZIP stream - The first 4 bytes of an OOXML file, used in detection */
        OOXML,
        /** XML file - The first 5 bytes of a raw XML file, used in detection */
        XML,
        /** BIFF2 raw stream - for Excel 2 */
        BIFF2,
        /** BIFF3 raw stream - for Excel 3 */
        BIFF3,
        /** BIFF4 raw stream - for Excel 4 */
        BIFF4,
        /** Old MS Write raw stream */
        MSWRITE,
        /** RTF document */
        RTF,
        /** PDF document */
        PDF,
        /** Some different HTML documents */
        HTML,
        WORD2,
        /** JPEG image */
        JPEG,
        /** GIF image */
        GIF,
        /** PNG Image */
        PNG,
        /** TIFF Image */
        TIFF,
        /** WMF image with a placeable header */
        WMF,
        /** EMF image */
        EMF,
        /** BMP image */
        BMP
    } TYPE;
    
    FZZFileMagic();
    virtual ~FZZFileMagic();
public:
    
    static unsigned char HEAD_OLE2[];
    static unsigned char HEAD_OOXML[];
    static unsigned char HEAD_XML[];
    static unsigned char HEAD_BIFF2[];
    static unsigned char HEAD_BIFF3[];
    static unsigned char HEAD_BIFF4[];
    static unsigned char HEAD_BIFF4_1[];
    /** Old MS Write raw stream */
    static unsigned char HEAD_MSWRITE[];
    static unsigned char HEAD_MSWRITE_1[];
    /** RTF document */
    static unsigned char HEAD_RTF[];
    /** PDF document */
    static unsigned char HEAD_PDF[];
    /** Some different HTML documents */
    static unsigned char HEAD_HTML[];
    static unsigned char HEAD_HTML_1[];
    static unsigned char HEAD_HTML_2[];
    static unsigned char HEAD_HTML_3[];
    static unsigned char HEAD_HTML_4[];
    static unsigned char HEAD_HTML_5[];
    static unsigned char HEAD_HTML_6[];
    static unsigned char HEAD_HTML_7[];
    static unsigned char HEAD_HTML_8[];
    static unsigned char HEAD_HTML_9[];
    static unsigned char HEAD_HTML_10[];
    static unsigned char HEAD_WORD2[];
    /** JPEG image */
    static unsigned char HEAD_JPEG[];
    static unsigned char HEAD_JPEG_1[];
    static unsigned char HEAD_JPEG_2[];
    static unsigned char HEAD_JPEG_3[];
    /** GIF image */
    static unsigned char HEAD_GIF[];
    static unsigned char HEAD_GIF_1[];
    /** PNG Image */
    static unsigned char HEAD_PNG[];
    /** TIFF Image */
    static unsigned char HEAD_TIFF[];
    static unsigned char HEAD_TIFF_1[];
    /** WMF image with a placeable header */
    static unsigned char HEAD_WMF[];
    /** EMF image */
    static unsigned char HEAD_EMF[];
    /** BMP image */
    static unsigned char HEAD_BMP[];
    
    static int MAX_PATTERN_LENGTH;
    static FZZFileMagic::TYPE valueOf(FZZBytes & magic);
    static string getContentTypeFromFileExtension(string filename);
    static string getFileExtension(string filename);
    static string getContentTypeFromFileTYPE(FZZFileMagic::TYPE type);
    static string getFileExtensionFromFileTYPE(FZZFileMagic::TYPE type);
    
private:
    static bool findMagic(const unsigned char * const expected, const unsigned char * const actual,int count);
private:
    
};

#endif //FZZFILEMAGIC_H
