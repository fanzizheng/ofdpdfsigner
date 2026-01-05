
//
//  Created by zizheng fan on 2023/03/08.
//
#ifndef FZZPKCS7_GM_H
#define FZZPKCS7_GM_H


#include "mupdf/pdf/document.h"
#include "mupdf/pdf/form.h"


#include "gm/crypto/FZZKey.h"
#include "gm/crypto/FZZCert.h"


typedef struct
{
    pdf_pkcs7_verifier base;
    int refs;
//    string cert_dn;
//    string c;
//    string cn;
//    string o;
//    string ou;
//    string email;
    char * cert_dn;
    char * c;
    char * cn;
    char * o;
    char * ou;
    char * email;
    time_t signtime;
    FZZBytes * imagedata;
    
    CallBack_Verify verifyFunc;
    const void * callback_param;
} GM_VERIFIER;


pdf_pkcs7_signer *pkcs7_gm_create_signer(fz_context *ctx, bool isCallBack,FZZCert *x509,FZZKey *prikey,
                                         CallBack_Sign singFunc,const void * callback_param,
                                         FZZBytes * imagedata);

pdf_pkcs7_verifier *pkcs7_gm_create_verifier(fz_context *ctx,CallBack_Verify verifyFunc,const void * callback_param);

//-----------------------------------------------------------------------------------------------------



fz_device * new_stamp_device(fz_context *ctx,fz_device *write_dev,fz_rect write_rect,bool isText,fz_image *showgraphic,fz_path *path);

#endif //FZZPKCS7_GM_H
