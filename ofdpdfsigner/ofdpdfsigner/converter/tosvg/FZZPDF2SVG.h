//
//  Created by zizheng fan on 2024/09/18.
//
#ifndef FZZPDF2SVG_H
#define FZZPDF2SVG_H

#include "basic/FZZBytes.h"

#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"
#include "mupdf/fitz/output-svg.h"



#include "pdfsign/FZZPDF.h"

class FZZPDF2SVG
{
public:
    FZZPDF2SVG(FZZPDF * pdf);
    ~FZZPDF2SVG();
public:
    //pdf 加密文档和 不加密无密码的文档 在签名时不用特殊处理，而有密码的文档要调用VerifyPassWord
    bool isNeedPassWord();
    bool VerifyPassWord(string pwd);
    int pageSize();
    //true : No seal， false : Show Stamp
    void SetNoStamp(bool isNoStamp) { m_isNoStamp = isNoStamp; }
    FZZBytes makePage(int pageIndex);
 
private:
    FZZPDF2SVG();
    FZZPDF2SVG(const FZZPDF2SVG& obj);
    
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
    string m_PassWord;

    
};

#endif //FZZPDF2SVG_H

