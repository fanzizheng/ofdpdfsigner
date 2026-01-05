//
//  Created by zizheng fan on 2023/03/09.
//
#ifndef FZZPDFCREATOR_H
#define FZZPDFCREATOR_H

#include "basic/FZZBytes.h"
#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"
#include "gm/crypto/FZZKey.h"
#include "gm/crypto/FZZCert.h"

#include "pdfsign/FZZPDF.h"

class FZZPDFCreator
{
public:
    FZZPDFCreator(FZZPDF * pdf);
	~FZZPDFCreator();
	
public:
    int pageSize();
    /*
     是否需要密码打开pdf文档
      (return) true 需要密码；false 不需要密码
     */
    bool isNeedPassWord();
    /*
     打开pdf文档，验证密码
     (in param) pwd: 密码
      (return) true 验证通过；false 验证失败
     */
    bool VerifyPassWord(string pwd);
    /*
      将一个PDF 复制 成另一个 PDF
      (in param) isEncrypt: 复制的PDF 是否加密
      (in param) passWord: 复制的PDF 设置密码
      (out param) outData: 复制的PDF数据
      (return) 0 成功
     */
    int CopyPDF(bool isEncrypt,string passWord,FZZBytes & outData);
protected:
    
private:
    FZZPDFCreator();
private:
    void OpenPDF(const unsigned char * const PDFData,size_t PDFDatalen);
private:
    FZZPDF * m_PDF;
    fz_context * m_CTX;
    pdf_document* m_Doc;
    fz_stream * m_Stm;
    
    
    
};


#endif //FZZPDFCREATOR_H


