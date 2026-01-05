//
//  Created by zizheng fan on 2024/04/19.
//
#include "basic/FZZConst.h"
#include "pdfsign/FZZPDF.h"
#include "mupdf/fitz/display-list.h"
#include "mupdf/fitz/device.h"
#include "mupdf/pdf/annot.h"
#include "mupdf/pdf/page.h"
#include "mupdf/pdf/object.h"



//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZPDF*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPDF::FZZPDF() : m_PassWord("")//: m_CTX(NULL),m_Doc(NULL),m_Stm(NULL)
{
    //DLOG("FZZPDF()");
    FZZConst::addClassCount("FZZPDF");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDF::~FZZPDF()
{
    //DLOG("~FZZPDF()");
    FZZConst::delClassCount("FZZPDF");
    
    //clear();
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZPDF::OpenPDF(const string pdfFileName)
{
//    FZZBytes data;
//    if (!FZZConst::readfile(pdfFileName,data) ) {
//        return false;
//    }
//    return OpenPDF(data.getData(),data.getLen());
    
    if (!FZZConst::readfile(pdfFileName,m_sourcePdfData) ) {
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZPDF::OpenPDF(const FZZBytes & pdfData)
{
    return OpenPDF(pdfData.getData(),pdfData.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZPDF::OpenPDF(const unsigned char * const PDFData,size_t PDFDatalen)
{
    //bool isTF = false;
    m_sourcePdfData.setData(PDFData,PDFDatalen);
    return true;
//    m_CTX = fz_new_context(NULL, NULL, FZ_STORE_DEFAULT);
//    if ( m_CTX == NULL ) return isTF;
//
//
//    fz_try(m_CTX)
//    {
//        fz_register_document_handlers(m_CTX);
//        fz_set_aa_level(m_CTX, 8);
//
//        m_Stm = fz_open_memory(m_CTX, PDFData, PDFDatalen);
//        if ( m_Stm == NULL ) return  isTF;
//        m_Doc = pdf_open_document_with_stream(m_CTX, m_Stm);
//        if ( m_Doc == NULL ) return  isTF;
//        isTF = true;
//    }
//    fz_always(m_CTX)
//    {
//
//    }
//    fz_catch(m_CTX)
//    {
//
//    }
//    return isTF;
    
}
//-----------------------------------------------------------------------------------------------------------------
//int FZZPDF::pageSize()
//{
//    int page_count = 0;
//    if ( m_Doc != NULL ) {
//        page_count = pdf_count_pages(m_CTX,m_Doc);
//    }
//    return page_count;
//}
////-----------------------------------------------------------------------------------------------------------------
//void FZZPDF::clear()
//{
//    if ( m_Doc != NULL ) {
//        pdf_drop_document(m_CTX,m_Doc);
//        m_Doc = NULL;
//    }
//
//    if ( m_Stm != NULL ) {
//        fz_drop_stream(m_CTX, m_Stm);
//        m_Stm = NULL;
//    }
//
//    if ( m_CTX != NULL ) {
//        fz_flush_warnings(m_CTX);
//        fz_drop_context(m_CTX);
//        m_CTX = NULL;
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
