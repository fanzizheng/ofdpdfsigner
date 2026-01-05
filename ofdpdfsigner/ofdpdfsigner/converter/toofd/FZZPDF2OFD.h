//
//  Created by zizheng fan on 2024/08/05.
//
#ifndef FZZPDF2OFD_H
#define FZZPDF2OFD_H

#include "basic/FZZBytes.h"
#include "ofd/FZZOFD.h"

#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"


#include "pdfsign/FZZPDF.h"

class FZZGenFont;

class FZZPDF2OFD
{
public:
    FZZPDF2OFD(FZZPDF * pdf);
    ~FZZPDF2OFD();
public:
    //pdf 加密文档和 不加密无密码的文档 在签名时不用特殊处理，而有密码的文档要调用VerifyPassWord
    bool isNeedPassWord();
    bool VerifyPassWord(string pwd);
    int getPDFPageCount();
    //true : No seal， false : Show Stamp
    void SetNoStamp(bool isNoStamp) { m_isNoStamp = isNoStamp; }
    bool makePage(int pageIndex);
    FZZBytes generateOFD();
    
    void setGenFontFlag(bool data) {m_isGenFont = data;}
    void generateOFDFont();
    
    void test();
private:
    FZZPDF2OFD();
    FZZPDF2OFD(const FZZPDF2OFD& obj);
    
    void pdf_page_annots(fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie);
    void pdf_page_annots_with_usage_imp(fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie);
    void pdf_annot_with_usage(fz_context *ctx, pdf_document *doc, pdf_page *page, pdf_annot *annot, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie);
    
    void pdf_page_widgets(fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie);
    void pdf_page_widgets_with_usage_imp(fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie);
   
private:
    FZZPDF * m_PDF;
    fz_context * m_CTX;
    pdf_document* m_Doc;
    fz_stream * m_Stm;
    
    //Default Display Stamp
    bool m_isNoStamp;
    
    FZZOFD* m_OFDDoc;
    
    bool m_isGenFont;
    
    map<string,FZZGenFont*> m_genFont;
    map<string,FZZBytes*> m_PDFFontData;
    
    
    map<string,unordered_map<FzUnichar,FzGlyphID>> m_ucs_gid_map;
    string m_PassWord;
};

#endif //FZZPDF2OFD_H

