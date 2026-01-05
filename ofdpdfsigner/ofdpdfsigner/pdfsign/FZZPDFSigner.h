//
//  Created by zizheng fan on 2023/03/06.
//
#ifndef FZZPDFSIGNER_H
#define FZZPDFSIGNER_H

#include "basic/FZZBytes.h"
#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"
#include "gm/crypto/FZZKey.h"
#include "gm/crypto/FZZCert.h"
#include "pdfsign/FZZPDF.h"


//fz_install_load_system_font_funcs

#define PDF_SIGNATURE_APPEARANCE_DATA ( \
    PDF_SIGNATURE_SHOW_LABELS | \
    PDF_SIGNATURE_SHOW_DN | \
    PDF_SIGNATURE_SHOW_DATE | \
    PDF_SIGNATURE_SHOW_TEXT_NAME  )

#define PDF_SIGNATURE_APPEARANCE_STAMP 0

#define PDF_MAX_STAMP_COUNT 6

//如果画文字 定义 PDF_STAMP_DRAWTEXT，注释掉PDF_STAMP_USE_CLIPS
//如果不画文字 注释掉 PDF_STAMP_DRAWTEXT，定义PDF_STAMP_USE_CLIPS
//#define PDF_STAMP_DRAWTEXT
#define PDF_STAMP_USE_CLIPS

#define PDF_STAMP_ALPHA 0.86

struct pdfStampimage_device
{
    fz_device super;
    //vector<FZZBytes *> stampImageList;
    FZZBytes * stampImage;
};

fz_device * new_pdfStampImage_device(fz_context *ctx);

class FZZPDFSigner
{
public:
    typedef enum {
        TYPE_Left,
        TYPE_Right,
        TYPE_Top,
        TYPE_Bottom
    } TYPE;
    
    
public:
    FZZPDFSigner(FZZPDF * pdf);
	~FZZPDFSigner();
	
public:
    int pageSize();
    //pdf 加密文档和 不加密无密码的文档 在签名时不用特殊处理，而有密码的文档要调用VerifyPassWord
    bool isNeedPassWord();
    bool VerifyPassWord(string pwd);
    void getSignatureInfos();
    //现在的实现方式是删除签名，但签名区域还在，用新的空图替换原来的图.所以删除签名后文档变大。
    //还有个办法是，重写生成pdf文件，生成时不带签名，但这可能导致字体的不准确。
    int Clear_Signs();
    int Verify(CallBack_Verify verifyFunc,const void * callBack_Param);
    int Verify(string sid,CallBack_Verify verifyFunc,const void * callBack_Param,string & signerdn,string & signtime);
    //pageIndex : 0 begin
    int SignData(int pageIndex,float x,float y,float stampWidth,float stampHeight,bool isCallBack,FZZCert *x509,FZZKey *prikey,CallBack_Sign signFunc, const void * cbParam);
    
    int SignStamp(int pageIndex,FZZBytes &stampimage,double alpha,float x,float y,float stampWidth,float stampHeight,bool isCallBack,FZZCert *x509,FZZKey *prikey,CallBack_Sign signFunc, const void * cbParam);
    
    int SignRidingStamp(FZZPDFSigner::TYPE type,FZZBytes &stampimage,double alpha,float stampWidth,float stampHeight,bool isCallBack,FZZCert *x509,FZZKey *prikey,CallBack_Sign signFunc, const void * cbParam);
    
    //TYPE_Right TYPE_Bottom
    int SignCuttingRidingStamp(FZZPDFSigner::TYPE type,FZZBytes &stampimage,double alpha,float stampWidth,float stampHeight,bool isCallBack,FZZCert *x509,FZZKey *prikey,CallBack_Sign signFunc, const void * cbParam);
    
    FZZBytes generatePDF();
    
    //FZZBytes not free
    void getSignInfos(vector<string> & pageIndexs,vector<string> & sids,vector<FZZBytes *> & stampimages);
    
    
    void getPageWidthHeight(int pageIndex,/*out*/double &pageWidth,/*out*/double &pageHeight);
    
    static void getStampImage(fz_context *ctx, pdf_document *doc, pdf_obj *field,FZZBytes & stampImage);
    
protected:
    void ClearAlpha(const FZZBytes & imageData,FZZBytes & outData);
private:
    typedef enum {
        TYPE_List,
        TYPE_Clear,
        TYPE_Verify
    } COMMAND_TYPE;
    
    FZZPDFSigner();
private:
    int process_acro_form(CallBack_Verify verifyFunc,const void * callBack_Param,const string &sid,string & signerdn,string & signtime);
    int process_field_hierarchy(fz_context *ctx, pdf_document *doc, pdf_obj *field,CallBack_Verify verifyFunc,const void * callBack_Param,const string &sid,bool & outIsContinue,string & signerdn,string & signtime);
    int process_field(fz_context *ctx, pdf_document *doc, pdf_obj *field,CallBack_Verify verifyFunc,const void * callBack_Param,string & signerdn,string & signtime);
    int verify_signature(fz_context *ctx, pdf_document *doc, pdf_obj *signature,CallBack_Verify verifyFunc,const void * callBack_Param,string & signerdn,string & signtime);
    int clear_signature(fz_context *ctx, pdf_document *doc, pdf_obj *signature);
    void list_signature(fz_context *ctx, pdf_document *doc, pdf_obj *signature);
    
    
    
    static fz_font * PDFSigner_load_system_font(fz_context *ctx, const char *name, int bold, int italic, int needs_exact_metrics);
    static fz_font * PDFSigner_load_system_cjk_font(fz_context *ctx, const char *name, int ordering, int serif);
    static fz_font * PDFSigner_load_system_fallback_font(fz_context *ctx, int script, int language, int serif, int bold, int italic);
    
    static void drawStampOverText(fz_context *ctx,fz_page *page,fz_device *dev,fz_rect rect,fz_image *showgraphic);
    
    static void drawStampOverText_End(fz_context *ctx,fz_page *page,fz_device *dev,fz_rect rect,fz_image *showgraphic);
    
    void getSignInfos(int pageindex);
    
    void pdf_page_annots(int pageIndex,fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie);
    void pdf_page_annots_with_usage_imp(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie);
    void pdf_page_widgets(int pageIndex,fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie);
    void pdf_page_widgets_with_usage_imp(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie);
    void pdf_annot_with_usage(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, pdf_annot *annot, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie);
    
    void fillPath(fz_device *dev,fz_text *text,fz_matrix ctm,fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params);
    
    void ClearSignature(fz_context *ctx, pdf_annot *widget);
    fz_display_list *
    SignatureAppearanceUnsigned(fz_context *ctx, fz_rect rect, fz_text_language lang);
private:
  
    fz_context * m_CTX;
    pdf_document* m_Doc;
    fz_stream * m_Stm;
    FZZPDF * m_PDF;
    string m_PassWord;
    int m_CurrAddStampCount;
    COMMAND_TYPE m_CommandType;
    
    
    vector<string> m_SignInfo_PageIndexs;
    vector<string> m_SignInfo_Sids;
    vector<FZZBytes *> m_SignInfo_StampImages;
    
};

#endif //FZZPDFSIGNER_H


