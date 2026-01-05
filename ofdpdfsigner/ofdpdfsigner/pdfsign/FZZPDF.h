//
//  Created by zizheng fan on 2024/04/19.
//
#ifndef FZZPDF_H
#define FZZPDF_H

#include "basic/FZZBytes.h"
#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"


class FZZPDF
{
public:
    FZZPDF();
	~FZZPDF();
	
public:
    bool OpenPDF(const string pdfFileName);
    bool OpenPDF(const FZZBytes & pdfData);
    bool OpenPDF(const unsigned char * const PDFData,size_t PDFDatalen);
    
//    void clear();
    
//    int pageSize();
    FZZBytes * getSourceData() { return &m_sourcePdfData; }
//    fz_context * getCTX() { return m_CTX; }
//    pdf_document* getDocument() { return m_Doc; }
//    fz_stream * getStream() { return m_Stm; }
    
    void setPassWord(string pw) { m_PassWord = pw; }
    string getPassword() { return m_PassWord; }
private:
    //FZZPDFSigner 不能正确执行，因此删除
//    fz_context * m_CTX;
//    pdf_document* m_Doc;
//    fz_stream * m_Stm;
    FZZBytes m_sourcePdfData;
    string m_PassWord;
};

#endif //FZZPDF_H


