//
//  Created by zizheng fan on 2022/12/01.
//
#ifndef FZZPDFTOIMAGE_H
#define FZZPDFTOIMAGE_H

#include "basic/FZZBytes.h"
//#include "fpdfview.h"
//#include "fpdf_edit.h"

//class Timer {
// public:
//  using clock = std::chrono::system_clock;
//  Timer() { Start(); }
//  ~Timer() = default;
//  void Start() {
//    time_start_ = clock::now();
//  }
//  int64_t Elapsed(bool restart = true) {
//    using namespace std::chrono;  // NOLINT
//    auto d = duration_cast<milliseconds>(clock::now() - time_start_).count();
//    if (restart) Start();
//    return d;
//  }
// private:
//  clock::time_point time_start_;
//};

#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"

#include "pdfsign/FZZPDF.h"

struct pdftoimage_device
{
    fz_device super;
    //vector<FZZBytes *> stampImageList;
    FZZBytes * stampImage;
};

fz_device * new_pdftoimage_device(fz_context *ctx);

typedef void (*AttachmentFileFunc)(const char* const filename,
                                   const char * const time,
                                   const unsigned char* const filedata,
                                   int filedatalen);
typedef void (*AnnotsFunc)(int pagenum,
                 const char * const creator,
                 const char* const time,
                 const char* const type,
                           const char* const remark);
typedef void (*StampsFunc)(const char* const pagenum,
            const char * const time,
            const char * const sid,
            const unsigned char* imagedata,
                   int imagedatalen);

typedef void (*FindWordFunc)(int pageIndex,const char* const word,float x,float y,float w,float h);



class FZZPDFToImage
{
public:
    FZZPDFToImage(FZZPDF * pdf);
    ~FZZPDFToImage();
public:
    int pageSize();
    
    //pdf 加密文档和 不加密无密码的文档 在签名时不用特殊处理，而有密码的文档要调用VerifyPassWord
    bool isNeedPassWord();
    bool VerifyPassWord(string pwd);
    
    //pageIndex: 0 -- max pages;imageType : PNG,JPG
    
    
    FZZBytes makePage(int pageIndex,string imageType,float scaleValue);
    FZZBytes makePage(int pageIndex,string imageType);
    void getOtherInfo(int pageIndex,AttachmentFileFunc attachmentFileFunc,
                      AnnotsFunc annotsFunc,
                      StampsFunc stampsFunc);
    
    void findWord(int pageIndex,const char* const word,float *xs,float * ys,float *ws,float* hs,int* number,int max);
    
    void findWord(int pageIndex,const char* const word,FindWordFunc findWordFunc);
    
    
private:
    FZZPDFToImage();
    FZZPDFToImage(const FZZPDFToImage& obj);
private:
    void pdf_page_annots(int pageIndex,fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie,AttachmentFileFunc attachmentFileFunc,
                         AnnotsFunc annotsFunc,
                         StampsFunc stampsFunc);
    void pdf_page_annots_with_usage_imp(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie,AttachmentFileFunc attachmentFileFunc,
                                        AnnotsFunc annotsFunc,
                                        StampsFunc stampsFunc);
    void pdf_page_widgets(int pageIndex,fz_context *ctx, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie,AttachmentFileFunc attachmentFileFunc,
                          AnnotsFunc annotsFunc,
                          StampsFunc stampsFunc);
    void pdf_page_widgets_with_usage_imp(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie,AttachmentFileFunc attachmentFileFunc,
                                         AnnotsFunc annotsFunc,
                                         StampsFunc stampsFunc);
    void pdf_annot_with_usage(int pageIndex,fz_context *ctx, pdf_document *doc, pdf_page *page, pdf_annot *annot, fz_device *dev, fz_matrix ctm, const char *usage, fz_cookie *cookie,AttachmentFileFunc attachmentFileFunc,
                              AnnotsFunc annotsFunc,
                              StampsFunc stampsFunc);
private:
    FZZPDF * m_PDF;
    fz_context * m_CTX;
    pdf_document* m_Doc;
    fz_stream * m_Stm;
    string m_PassWord;
};

#endif //FZZPDFTOIMAGE_H

