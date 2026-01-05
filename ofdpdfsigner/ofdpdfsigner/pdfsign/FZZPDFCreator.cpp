//
//  Created by zizheng fan on 2023/03/09.
//

#include "basic/FZZConst.h"
#include "pdfsign/FZZPDFCreator.h"



//#include "pdfsign/FZZPkcs7_GM.h"

#include "mupdf/fitz/display-list.h"
#include "mupdf/fitz/device.h"
#include "mupdf/pdf/annot.h"
#include "mupdf/pdf/page.h"
#include "mupdf/pdf/object.h"

#include "basic/FZZString.h"


#include "fzfont/FZZFontCache.h"

#include "mupdf/pdf/clean.h"
#include "interface/FZZErrorCode.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZPDFCreator*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPDFCreator::FZZPDFCreator() : m_PDF(NULL),m_CTX(NULL),m_Doc(NULL),m_Stm(NULL)
{
    //DLOG("FZZPDFCreator()");
    FZZConst::addClassCount("FZZPDFCreator");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDFCreator::FZZPDFCreator(FZZPDF * pdf): FZZPDFCreator()
{
    m_PDF = pdf;
    if ( m_PDF == NULL ) {
        return;
    }
    
    FZZBytes * tempSrcData = m_PDF->getSourceData();
    if ( tempSrcData == NULL ) {
        return;
    }
    
    OpenPDF(tempSrcData->getData(),tempSrcData->getLen());
}
//-----------------------------------------------------------------------------------------------------------------
FZZPDFCreator::~FZZPDFCreator()
{
    //DLOG("~FZZPDFCreator()");
    FZZConst::delClassCount("FZZPDFCreator");
    
    if ( m_Stm != NULL ) {
        fz_drop_stream(m_CTX, m_Stm);
        m_Stm = NULL;
    }
    
    if ( m_Doc != NULL ) {
        pdf_drop_document(m_CTX,m_Doc);
        m_Doc = NULL;
    }
    
    if ( m_CTX != NULL ) {
        fz_flush_warnings(m_CTX);
        fz_drop_context(m_CTX);
        m_CTX = NULL;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPDFCreator::OpenPDF(const unsigned char * const PDFData,size_t PDFDatalen)
{
    m_CTX = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
    if ( m_CTX == NULL ) return;
    
    //-------fzz
    //Registration Document Control
   fz_try(m_CTX)
           fz_register_document_handlers(m_CTX);
   fz_catch(m_CTX)
   {
       DLOG("fz_register_document_handlers error: %s",fz_caught_message(m_CTX));
       fz_drop_context(m_CTX);
       m_CTX = NULL;
       return;
   }
    //-------fzz
    fz_set_aa_level(m_CTX, 8);
    
    m_Stm = fz_open_memory(m_CTX, PDFData, PDFDatalen);
    if ( m_Stm == NULL ) return;
    m_Doc = pdf_open_document_with_stream(m_CTX, m_Stm);
    
}
//-----------------------------------------------------------------------------------------------------------------
int FZZPDFCreator::pageSize()
{
    int page_count = 0;
    if ( m_Doc != NULL ) {
        page_count = pdf_count_pages(m_CTX,m_Doc);
    }
    return page_count;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZPDFCreator::isNeedPassWord()
{
    bool ret = false;
    if ( m_CTX == NULL && m_Doc == NULL ) {
        return ret;
    }
    if (pdf_needs_password(m_CTX, m_Doc)) {
        ret = true;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZPDFCreator::VerifyPassWord(string pwd)
{
    bool ret = false;
    
    
    if ( m_CTX == NULL && m_Doc == NULL ) {
        return ret;
    }
    
    if (pdf_needs_password(m_CTX, m_Doc)) {
        if (!pdf_authenticate_password(m_CTX, m_Doc, pwd.c_str())) {
            ret = false;
        } else {
            ret = true;
        }
    } else {
        ret = true;
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
//参考source/pdf/pdf-clean-file.c 中 pdf_clean_file 实现
int FZZPDFCreator::CopyPDF(bool isEncrypt,string passWord,FZZBytes & outData)
{
    int iRet = 0;
    int *pages = NULL;
    int cap, len, page;

    fz_var(pages);
    
    pdf_clean_options opts = { 0 };
    opts.write = pdf_default_write_options;
    opts.write.dont_regenerate_id = 1;
    opts.write.do_compress = 1;
    opts.write.do_compress_fonts = 1;
    opts.write.do_compress_images = 1;
    opts.write.do_compress_images = 1;
    opts.write.do_linear = 1;
    opts.write.do_clean = 1;
    if ( !passWord.empty() ) {
        opts.write.do_encrypt = PDF_ENCRYPT_AES_128;
        fz_strlcpy(opts.write.upwd_utf8, passWord.c_str(), nelen(opts.write.upwd_utf8));
        fz_strlcpy(opts.write.opwd_utf8, passWord.c_str(), nelen(opts.write.opwd_utf8));
    } else {
        if ( isEncrypt ) {
            opts.write.do_encrypt = PDF_ENCRYPT_AES_128;//PDF_ENCRYPT_RC4_40 PDF_ENCRYPT_RC4_128 PDF_ENCRYPT_AES_128 PDF_ENCRYPT_AES_256
        } else {
            opts.write.do_encrypt = PDF_ENCRYPT_NONE;
        }
    }
    
    fz_try(m_CTX)
    {
        len = cap = 0;
        
        int pagecount = pdf_count_pages(m_CTX, m_Doc);
        int argidx = 0;

        while (pagecount - argidx)
        {
            int spage, epage;
            string  pageIndex = FZZConst::fmt(argidx+1);
            const char *pagelist = pageIndex.c_str();

            while ((pagelist = fz_parse_page_range(m_CTX, pagelist, &spage, &epage, pagecount)))
            {
                if (len + (epage - spage + 1) >= cap)
                {
                    int n = cap ? cap * 2 : 8;
                    while (len + (epage - spage + 1) >= n)
                        n *= 2;
                    pages = fz_realloc_array(m_CTX, pages, n, int);
                    cap = n;
                }

                if (spage < epage)
                    for (page = spage; page <= epage; ++page)
                        pages[len++] = page - 1;
                else
                    for (page = spage; page >= epage; --page)
                        pages[len++] = page - 1;
            }

            argidx++;
        }

        pdf_rearrange_pages(m_CTX, m_Doc, len, pages);
        

        pdf_rewrite_images(m_CTX, m_Doc, &opts.image);

        if (opts.subset_fonts)
            pdf_subset_fonts(m_CTX, m_Doc, len, pages);

        string fileuuid = FZZConst::createuuid();
        string filename = FZZConst::getTempPath() + "/" + fileuuid + ".pdf";
        
        //pdf_save_document(m_CTX, m_Doc, filename.c_str(), &opts.write);
        
#ifdef _MSC_VER

        string utf8_filename = FZZConst::GB2312toUtf8(filename);
        pdf_save_document(m_CTX, m_Doc, utf8_filename.c_str(), &opts.write);
#else
        pdf_save_document(m_CTX, m_Doc, filename.c_str(), &opts.write);
#endif
        
        FZZConst::readfile(filename, outData);
        FZZConst::deleteFile(filename);
    }
    fz_always(m_CTX)
    {
        fz_free(m_CTX, pages);
        //pdf_drop_document(ctx, m_Doc);
    }
    fz_catch(m_CTX)
    {
        //fz_rethrow(ctx);
        return ERR_FAIL;
    }
    return iRet;
}
//-----------------------------------------------------------------------------------------------------------------





