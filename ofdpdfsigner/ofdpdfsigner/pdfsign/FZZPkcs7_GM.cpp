//
//  Created by zizheng fan on 2023/03/08.
//
#include "basic/FZZConst.h"
#include "mupdf/fitz.h"
#include "mupdf/pdf.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"

#include "pdfsign/FZZPkcs7_GM.h"
#include "font/FZZGenFont.h"

#include <limits.h>
#include <string.h>


#include "gm/crypto/FZZGMCrypto.h"
#include "gm/ses/data/FZZContentInfo.h"
#include "gm/ses/data/FZZSignerInfo.h"
#include "gm/ses/data/FZZAuthenticatedAttributes.h"



//-----------------------------------------------------------------------------------------------------------------


struct stamp_device
{
    fz_device super;
    fz_device *write_dev;
    fz_rect write_rect;
    map<string,FZZGenFont*> * genFontList;
    bool isGenFont;
    fz_path *path;
    fz_image *showgraphic;
    bool isGroup;
    float group_Alpha;
    bool isText;
};

typedef struct
{
    pdf_pkcs7_signer base;
    int refs;
    bool isSignCallBack;
    FZZCert *x509;
    FZZKey *pkey;
    CallBack_Sign singFunc;
    const void * callback_param;
    
//    string c;
//    string cn;
//    string o;
//    string ou;
//    string email;
    char * c;
    char * cn;
    char * o;
    char * ou;
    char * email;
    FZZBytes * imagedata;
} GM_SIGNER;
//-----------------------------------------------------------------------------------------------------------------
/************************private function*******************/
//-----------------------------------------------------------------------------------------------------------------
static  void read_best(fz_context *ctx, fz_stream *stm, size_t initial,FZZGMCrypto& crypto)
{
    size_t n;
    fz_try(ctx)
    {
        unsigned char* buffer = (unsigned char*)malloc(initial);
        if (buffer != NULL) {

        
            while (1)
            {
                n = fz_read(ctx, stm, buffer, initial);
                if (n == 0)
                    break;
                crypto.Digest_Update(buffer,n);
            }
            free(buffer);
        }
    }
    fz_catch(ctx)
    {

    }
}
//-----------------------------------------------------------------------------------------------------------------
static void drop_signer(fz_context *ctx, pdf_pkcs7_signer *signer)
{
    GM_SIGNER *osigner = (GM_SIGNER *)signer;
    if ( osigner == NULL ) {
        return;
    }
    if ( osigner->c != NULL ) {
        free(osigner->c);
        osigner->c = NULL;
    }
    
    if ( osigner->cn != NULL ) {
        free(osigner->cn);
        osigner->cn = NULL;
    }
    
    if ( osigner->o != NULL ) {
        free(osigner->o);
        osigner->o = NULL;
    }
    
    if ( osigner->ou != NULL ) {
        free(osigner->ou);
        osigner->ou = NULL;
    }

    if ( osigner->email != NULL ) {
        free(osigner->email);
        osigner->email = NULL;
    }
    
    if (fz_drop_imp(ctx, osigner, &osigner->refs))
    {
//        if ( osigner->x509 == NULL ) {
//            delete osigner->x509;
//        }
//        if ( osigner->pkey == NULL ) {
//            delete osigner->pkey;
//        }
        
        fz_free(ctx, osigner);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static pdf_pkcs7_signer *keep_signer(fz_context *ctx, pdf_pkcs7_signer *signer)
{
    GM_SIGNER *osigner = (GM_SIGNER *)signer;
    return (pdf_pkcs7_signer *)fz_keep_imp(ctx, osigner, &osigner->refs);
}
//-----------------------------------------------------------------------------------------------------------------
static pdf_pkcs7_distinguished_name *signer_distinguished_name(fz_context *ctx, pdf_pkcs7_signer *signer)
{
    GM_SIGNER *osigner = (GM_SIGNER *)signer;
    if ( osigner == NULL ) return NULL;
    pdf_pkcs7_distinguished_name *name = fz_malloc_struct(ctx, pdf_pkcs7_distinguished_name);
    fz_try(ctx)
    {
        size_t len = 0;
        if ( osigner->cn != NULL ) {
            size_t len = strlen(osigner->cn);
            name->cn = NULL;
            if ( len > 0 ) {
                name->cn = (char *)Memento_label(fz_malloc(ctx,len+1),"gm_pkcs7_distinguished_name_sign.cn");
                if ( name->cn != NULL ) {
                    memset(name->cn,0x00,len+1);
                    memcpy(name->cn,osigner->cn,len);
                }
            }
        }
        
        
//        name->cn = (char *)Memento_label(fz_malloc(ctx,osigner->cn.length()+1),"gm_pkcs7_distinguished_name_sign.cn");
//        memset(name->cn,0x00,osigner->cn.length()+1);
//        memcpy(name->cn,osigner->cn.c_str(),osigner->cn.length());
        if ( osigner->o != NULL ) {
            len = strlen(osigner->o);
            name->o = NULL;
            if ( len > 0 ) {
                name->o = (char *)Memento_label(fz_malloc(ctx,len+1),"gm_pkcs7_distinguished_name_sign.o");
                if ( name->o != NULL ) {
                    memset(name->o,0x00,len+1);
                    memcpy(name->o,osigner->o,len);
                }
            }
        }
        
//        name->o = (char *)Memento_label(fz_malloc(ctx,osigner->o.length()+1),"gm_pkcs7_distinguished_name_sign.o");
//        memset(name->o,0x00,osigner->o.length()+1);
//        memcpy(name->o,osigner->o.c_str(),osigner->o.length());
        if ( osigner->ou != NULL ) {
            len = strlen(osigner->ou);
            name->ou = NULL;
            if ( len > 0 ) {
                name->ou = (char *)Memento_label(fz_malloc(ctx,len+1),"gm_pkcs7_distinguished_name_sign.ou");
                if ( name->ou != NULL ) {
                    memset(name->ou,0x00,len+1);
                    memcpy(name->ou,osigner->ou,len);
                }
            }
        }
        
//        name->ou = (char *)Memento_label(fz_malloc(ctx,osigner->ou.length()+1),"gm_pkcs7_distinguished_name_sign.ou");
//        memset(name->ou,0x00,osigner->ou.length()+1);
//        memcpy(name->ou,osigner->ou.c_str(),osigner->ou.length());
        if ( osigner->email != NULL ) {
            len = strlen(osigner->email);
            name->email = NULL;
            if ( len > 0 ) {
                name->email = (char *)Memento_label(fz_malloc(ctx,len+1),"gm_pkcs7_distinguished_name_sign.email");
                if ( name->email != NULL ) {
                    memset(name->email,0x00,len+1);
                    memcpy(name->email,osigner->email,len);
                }
            }
        }
        
//        name->email = (char *)Memento_label(fz_malloc(ctx,osigner->email.length()+1),"gm_pkcs7_distinguished_name_sign.email");
//        memset(name->email,0x00,osigner->email.length()+1);
//        memcpy(name->email,osigner->email.c_str(),osigner->email.length());
        if ( osigner->c != NULL ) {
            len = strlen(osigner->c);
            name->c = NULL;
            if ( len > 0 ) {
                name->c = (char *)Memento_label(fz_malloc(ctx,len+1),"gm_pkcs7_distinguished_name_sign.c");
                if ( name->c != NULL ) {
                    memset(name->c,0x00,len+1);
                    memcpy(name->c,osigner->c,len);
                }
            }
        }
        
//        name->c = (char *)Memento_label(fz_malloc(ctx,osigner->c.length()+1),"gm_pkcs7_distinguished_name_sign.c");
//        memset(name->c,0x00,osigner->c.length()+1);
//        memcpy(name->c,osigner->c.c_str(),osigner->c.length());
    }
    fz_catch(ctx)
    {
        pdf_signature_drop_distinguished_name(ctx, name);
        //fz_rethrow(ctx);
    }

    return name;
}
//-----------------------------------------------------------------------------------------------------------------
//static int signer_create_digest(fz_context *ctx, pdf_pkcs7_signer *signer, unsigned char *sourcedata, size_t sourcedatalen, unsigned char *digest, size_t digest_len)
static int signer_create_digest(fz_context *ctx, pdf_pkcs7_signer *signer, fz_stream * in, unsigned char *digest, size_t digest_len)
{
    GM_SIGNER *osigner = (GM_SIGNER *)signer;
    if ( osigner == NULL )
    
    if ( osigner == NULL || osigner->x509 == NULL || osigner->pkey == NULL ) {
        return 0;
    }
    /*
    fz_buffer *buf;
    FZZBytes inData;
    if ( in != NULL ) {

        buf = fz_read_all(ctx, in, 0);
        if ( buf == NULL ) {
            return 0;
        }

        if ( buf->len <= 0 ) {
            fz_drop_buffer(ctx, buf);
            return 0;
        }

        inData.setData(buf->data, buf->len);
        fz_drop_buffer(ctx, buf);
    } else {
        inData.setData((unsigned char *)"aaa", 3);
    }
//    if ( sourcedata != NULL ) {
//        inData.setData(sourcedata, sourcedatalen);
//    } else {
//        inData.setData((unsigned char *)"aaa", 3);
//    }
    
    FZZGMCrypto gmCrypto;
    FZZBytes hashData;
    
    gmCrypto.Digest("SM3", inData, hashData);
    if ( hashData.getLen() < 8 ) {
        return 0;
    }
     */
    FZZGMCrypto gmCrypto;
    FZZBytes hashData;
    gmCrypto.Digest_Init("SM3");
    if ( in != NULL ) {
        
        read_best(ctx, in, 4096,gmCrypto);
        
    } else {
        gmCrypto.Digest_Update((unsigned char *)"aaa", 3);
    }
    gmCrypto.Digest_Finish(hashData);
    if ( hashData.getLen() < 8 ) {
        return 0;
    }
    
    
    
    FZZAuthenticatedAttributes authenticatedAttributes;
    authenticatedAttributes.setMessageDigest(hashData);
    FZZBytes plaintext = authenticatedAttributes.getPlainText();
    
    FZZBytes signdata;
    do {
        if ( osigner->isSignCallBack ) {
            if ( osigner->singFunc != NULL ) {
                //fzz edit begin 2026.06.07
//                signdata = osigner->singFunc(osigner->callback_param,plaintext);
//                if ( signdata.getLen() == 0 ) {
//                    break;
//                }
                size_t bufferLen = MAXBUFLEN_SIGN;
                unsigned char * buffer = (unsigned char *)malloc(bufferLen);
                if ( buffer == NULL ) {
                    break;
                }
                osigner->singFunc(osigner->callback_param,plaintext.getData(),(int)plaintext.getLen(),&buffer,&bufferLen);
                if (bufferLen <= 0) {
                    free(buffer);
                    buffer = NULL;
                    break;
                }
                signdata.setData(buffer, bufferLen);
                free(buffer);
                buffer = NULL;
                //fzz edit end 2026.06.07
            }
        } else {
            signdata = gmCrypto.sign(*(osigner->pkey), plaintext);
        }
    } while( signdata.getLen() != 72 );
    if ( signdata.getLen() <= 0 ) {
        return 0;
    }
    
    FZZContentInfo dataContent;
    uint32_t datacontentType_nodes[] = {1,2,156,10197,6,1,4,2,1};
    size_t datacontentType_nodes_count = 9;
    FZZBytes datacontentTypealg((unsigned char *)datacontentType_nodes,datacontentType_nodes_count*4);
    dataContent.setContentType(datacontentTypealg);
    //dataContent.setDataContent(hashData);
    
    
    FZZContentInfo contentInfo;
    uint32_t signcontentType_nodes[] = {1,2,156,10197,6,1,4,2,2};
    size_t signcontentType_nodes_count = 9;
    FZZBytes signcontentTypealg((unsigned char *)signcontentType_nodes,signcontentType_nodes_count*4);
    contentInfo.setContentType(signcontentTypealg);
    
    FZZSignedData signedData;
    
    uint32_t digestAlg_nodes[] = {1,2,156,10197,1,401};
    size_t digestAlg_nodes_count = 6;
    FZZBytes digestAlg((unsigned char *)digestAlg_nodes,digestAlg_nodes_count*4);
    signedData.addDigestAlg(digestAlg);
    signedData.setContentInfo(&dataContent);
    signedData.addCert(osigner->x509->getCertData());
    FZZSignerInfo signerinfo;
    signerinfo.setIssuer(osigner->x509->getIssuer());
    FZZBytes certsn = osigner->x509->getSerialNumberBytes();
    signerinfo.setSerialNumber(certsn);
    signerinfo.setDigestAlgorithm(digestAlg);
    signerinfo.setAuthenticatedAttributes(&authenticatedAttributes);
    FZZUnAuthenticatedAttributes unauthenticatedAttributes;
    if ( osigner->imagedata != NULL ) {
        unauthenticatedAttributes.setMessageDigest(*(osigner->imagedata));
        signerinfo.setUnAuthenticatedAttributes(&unauthenticatedAttributes);
    }
    
    uint32_t digestEncryptionAlg_nodes[] = {1,2,156,10197,1,301,1};
    size_t digestEncryptionAlg_count = 7;
    FZZBytes digestEncryptionAlg((unsigned char *)digestEncryptionAlg_nodes,digestEncryptionAlg_count*4);
    signerinfo.setDigestEncryptionAlgorithm(digestEncryptionAlg);
    signerinfo.setEncryptedDigest(signdata);
    signedData.addSignerInfo(&signerinfo);
    
    contentInfo.setContent(&signedData);
    
    FZZBytes esesigndata = contentInfo.Encode();
    if ( esesigndata.getLen() < 10 ) {
        return 0;
    }
    
    size_t ret= esesigndata.getLen();
    if ( digest != NULL ) {
        if (digest && esesigndata.getLen() > digest_len){
            return 0;
        }
        memcpy(digest, esesigndata.getData(), esesigndata.getLen());
        //test begin
        //FZZConst::writefile("/Users/fzz/work/cpp/ofd/tmp/signpdf/p7gm.dat",esesigndata.getData(),esesigndata.getLen());
        //test end
    }
    //if ( in != NULL ) {
   //     DLOG("signer_create_digest : %d",(int)ret);
    //}
    return (int)ret;
}
//-----------------------------------------------------------------------------------------------------------------
static size_t max_digest_size(fz_context *ctx, pdf_pkcs7_signer *signer)
{
    //return signer_create_digest(ctx, signer, NULL,0, NULL, 0);
    size_t ret = signer_create_digest(ctx, signer, NULL, NULL, 0);
    //DLOG("max_digest_size : %d",(int)ret);
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
static void drop_verifier(fz_context *ctx, pdf_pkcs7_verifier *verifier)
{
    GM_VERIFIER * gmVerify = (GM_VERIFIER *)verifier;
    if ( gmVerify == NULL ) return;
    
    if ( gmVerify->imagedata != NULL ) {
        delete gmVerify->imagedata;
        gmVerify->imagedata = NULL;
    }
    
    if ( gmVerify->cert_dn != NULL ) {
        free(gmVerify->cert_dn);
        gmVerify->cert_dn = NULL;
    }
    if ( gmVerify->c != NULL ) {
        free(gmVerify->c);
        gmVerify->c = NULL;
    }
    if ( gmVerify->cn != NULL ) {
        free(gmVerify->cn);
        gmVerify->cn = NULL;
    }
    if ( gmVerify->o != NULL ) {
        free(gmVerify->o);
        gmVerify->o = NULL;
    }
    if ( gmVerify->ou != NULL ) {
        free(gmVerify->ou);
        gmVerify->ou = NULL;
    }
    if ( gmVerify->email != NULL ) {
        free(gmVerify->email);
        gmVerify->email = NULL;
    }
    
    if (fz_drop_imp(ctx, gmVerify, &gmVerify->refs)) {
        fz_free(ctx, gmVerify);
    }
}
//-----------------------------------------------------------------------------------------------------------------
pdf_pkcs7_distinguished_name *get_signatory(fz_context *ctx, pdf_pkcs7_verifier *verifier, unsigned char *sig, size_t sig_len)
{
    pdf_pkcs7_distinguished_name *name = NULL;
    if ( verifier == NULL || sig == NULL || sig_len <= 0) {
        return name;
    }
    FZZContentInfo contentInfo(sig,sig_len);
    FZZSignedData* signedData = contentInfo.getContent();
    if ( signedData == NULL ) {
        return name;
    }

    GM_VERIFIER * gmverifier = (GM_VERIFIER *)verifier;
    vector<FZZSignerInfo*>* signerInfoList = signedData->getSignerInfos();
    vector<FZZSignerInfo *>::const_iterator SignerInfo_itr;
    for( SignerInfo_itr = signerInfoList->begin(); SignerInfo_itr != signerInfoList->end(); SignerInfo_itr++ ) {
        FZZSignerInfo* signerInfo = *SignerInfo_itr;
        if ( signerInfo == NULL ) {
            continue;
        }
        FZZUnAuthenticatedAttributes* unAuthenticatedAttributes = signerInfo->getUnAuthenticatedAttributes();
        if ( unAuthenticatedAttributes != NULL ) {
            FZZBytes * tempimagedata = unAuthenticatedAttributes->getMessageDigest();
            gmverifier->imagedata = new FZZBytes(*tempimagedata);
            
        }
        
        string subjectstr = signerInfo->getIssuer();
        
        vector<string> itmes;
        FZZConst::split(subjectstr.c_str(), ",", itmes);
        vector<string>::const_iterator itr;
        string tempstr = "";
        size_t pos = 0;
        string item_key;
        string item_value;
        for( itr = itmes.begin(); itr != itmes.end(); itr++ ) {
            tempstr = *itr;
            pos = tempstr.find("=");
            if (pos != string::npos) {
                item_key = tempstr.substr(0,pos);
                transform(item_key.begin(), item_key.end(), item_key.begin(), ::toupper);
                item_value = tempstr.substr(pos+1);
                if ( item_key == "C" ) {
                    if ( gmverifier->c != NULL ) {
                        free(gmverifier->c);
                    }
                    gmverifier->c = (char *)malloc(item_value.length()+2);
                    if ( gmverifier->c != NULL ) {
                        strcpy(gmverifier->c,item_value.c_str());
                    }
                    //signer->c = item_value;
                } else if ( item_key == "CN" ) {
                    //signer->cn = item_value;
                    if ( gmverifier->cn != NULL ) {
                        free(gmverifier->cn);
                    }
                    gmverifier->cn = (char *)malloc(item_value.length()+2);
                    if ( gmverifier->cn != NULL ) {
                        strcpy(gmverifier->cn,item_value.c_str());
                    }
                } else if ( item_key == "O" ) {
                    //signer->o = item_value;
                    if ( gmverifier->o != NULL ) {
                        free(gmverifier->o);
                    }
                    gmverifier->o = (char *)malloc(item_value.length()+2);
                    if ( gmverifier->o != NULL ) {
                        strcpy(gmverifier->o,item_value.c_str());
                    }
                } else if ( item_key == "OU" ) {
                    //signer->ou = item_value;
                    if ( gmverifier->ou != NULL ) {
                        free(gmverifier->ou);
                    }
                    gmverifier->ou = (char *)malloc(item_value.length()+2);
                    if ( gmverifier->ou != NULL ) {
                        strcpy(gmverifier->ou,item_value.c_str());
                    }
                } else if ( item_key == "E" || item_key == "EMAIL" ) {
                    //signer->email = item_value;
                    if ( gmverifier->email != NULL ) {
                        free(gmverifier->email);
                    }
                    gmverifier->email = (char *)malloc(item_value.length()+2);
                    if ( gmverifier->email != NULL ) {
                        strcpy(gmverifier->email,item_value.c_str());
                    }
                }
                
//                if ( item_key == "C" ) {
//                    gmverifier->c = item_value;
//                } else if ( item_key == "CN" ) {
//                    gmverifier->cn = item_value;
//                } else if ( item_key == "O" ) {
//                    gmverifier->o = item_value;
//                } else if ( item_key == "OU" ) {
//                    gmverifier->ou = item_value;
//                } else if ( item_key == "E" || item_key == "EMAIL" ) {
//                    gmverifier->email = item_value;
//                }
            }
        }
    }

    name = fz_malloc_struct(ctx, pdf_pkcs7_distinguished_name);
    fz_try(ctx)
    {
        size_t len = 0;
        if ( gmverifier->cn != NULL ) {
            len = strlen(gmverifier->cn);
            name->cn = NULL;
            if ( len > 0 ) {
                name->cn = (char *)Memento_label(fz_malloc(ctx,len+1),"gm_pkcs7_distinguished_name_verify.cn");
                if ( name->cn != NULL ) {
                    memset(name->cn,0x00,len+1);
                    memcpy(name->cn,gmverifier->cn,len);
                }
            }
        }
//        name->cn = (char *)Memento_label(fz_malloc(ctx,gmverifier->cn.length()+1),"gm_pkcs7_distinguished_name_verify.cn");
//        memset(name->cn,0x00,gmverifier->cn.length()+1);
//        memcpy(name->cn,gmverifier->cn.c_str(),gmverifier->cn.length());
        if ( gmverifier->o != NULL ) {
            len = strlen(gmverifier->o);
            name->o = NULL;
            if ( len > 0 ) {
                name->o = (char *)Memento_label(fz_malloc(ctx,len+1),"gm_pkcs7_distinguished_name_verify.o");
                if ( name->o != NULL ) {
                    memset(name->o,0x00,len+1);
                    memcpy(name->o,gmverifier->o,len);
                }
            }
        }
        
//        name->o = (char *)Memento_label(fz_malloc(ctx,gmverifier->o.length()+1),"gm_pkcs7_distinguished_name_verify.o");
//        memset(name->o,0x00,gmverifier->o.length()+1);
//        memcpy(name->o,gmverifier->o.c_str(),gmverifier->o.length());
        if ( gmverifier->ou != NULL ) {
            len = strlen(gmverifier->ou);
            name->ou = NULL;
            if ( len > 0 ) {
                name->ou = (char *)Memento_label(fz_malloc(ctx,len+1),"gm_pkcs7_distinguished_name_verify.ou");
                if ( name->ou != NULL ) {
                    memset(name->ou,0x00,len+1);
                    memcpy(name->ou,gmverifier->ou,len);
                }
            }
        }
        
//        name->ou = (char *)Memento_label(fz_malloc(ctx,gmverifier->ou.length()+1),"gm_pkcs7_distinguished_name_verify.ou");
//        memset(name->ou,0x00,gmverifier->ou.length()+1);
//        memcpy(name->ou,gmverifier->ou.c_str(),gmverifier->ou.length());
        if ( gmverifier->email != NULL ) {
            len = strlen(gmverifier->email);
            name->email = NULL;
            if ( len > 0 ) {
                name->email = (char *)Memento_label(fz_malloc(ctx,len+1),"gm_pkcs7_distinguished_name_verify.email");
                if ( name->email != NULL ) {
                    memset(name->email,0x00,len+1);
                    memcpy(name->email,gmverifier->email,len);
                }
            }
        }
        
//        name->email = (char *)Memento_label(fz_malloc(ctx,gmverifier->email.length()+1),"gm_pkcs7_distinguished_name_verify.email");
//        memset(name->email,0x00,gmverifier->email.length()+1);
//        memcpy(name->email,gmverifier->email.c_str(),gmverifier->email.length());
        if ( gmverifier->c != NULL ) {
            len = strlen(gmverifier->c);
            name->c = NULL;
            if ( len > 0 ) {
                name->c = (char *)Memento_label(fz_malloc(ctx,len+1),"gm_pkcs7_distinguished_name_verify.c");
                if ( name->c != NULL ) {
                    memset(name->c,0x00,len+1);
                    memcpy(name->c,gmverifier->c,len);
                }
            }
        }
        
//        name->c = (char *)Memento_label(fz_malloc(ctx,gmverifier->c.length()+1),"gm_pkcs7_distinguished_name_verify.c");
//        memset(name->c,0x00,gmverifier->c.length()+1);
//        memcpy(name->c,gmverifier->c.c_str(),gmverifier->c.length());
    }
    fz_catch(ctx)
    {
        pdf_signature_drop_distinguished_name(ctx, name);
        //fz_rethrow(ctx);
    }
    return name;
    //return NULL;
}
//-----------------------------------------------------------------------------------------------------------------
static pdf_signature_error
check_certificate(fz_context *ctx, pdf_pkcs7_verifier *verifier, unsigned char *sig, size_t sig_len)
{
    pdf_signature_error res = PDF_SIGNATURE_ERROR_UNKNOWN;
    if ( verifier == NULL || sig == NULL || sig_len <= 0) {
        return res;
    }
    FZZContentInfo contentInfo(sig,sig_len);
    FZZSignedData* signedData = contentInfo.getContent();
    if ( signedData == NULL ) {
        return res;
    }

    //GM_VERIFIER * gmverifier = (GM_VERIFIER *)verifier;
    vector<FZZSignerInfo*>* signerInfoList = signedData->getSignerInfos();
    vector<FZZSignerInfo *>::const_iterator SignerInfo_itr;
    for( SignerInfo_itr = signerInfoList->begin(); SignerInfo_itr != signerInfoList->end(); SignerInfo_itr++ ) {
        FZZSignerInfo* signerInfo = *SignerInfo_itr;
        if ( signerInfo == NULL ) {
            continue;
        }
        FZZCert cert = signedData->getCertSignCert(signerInfo->getIssuer(),signerInfo->getSerialNumber());
        //verify cert
        if ( ((GM_VERIFIER*)verifier)->cert_dn != NULL ) {
            free(((GM_VERIFIER*)verifier)->cert_dn);
            ((GM_VERIFIER*)verifier)->cert_dn = NULL;
        }
        ((GM_VERIFIER*)verifier)->cert_dn = (char *)malloc(cert.getSubject().length()+2);
        if ( ((GM_VERIFIER*)verifier)->cert_dn != NULL ) {
            strcpy(((GM_VERIFIER*)verifier)->cert_dn,cert.getSubject().c_str());
        }
        //((GM_VERIFIER*)verifier)->cert_dn = cert.getSubject();
    }
    
    res = PDF_SIGNATURE_ERROR_OKAY;
    return res;
}
//-----------------------------------------------------------------------------------------------------------------
static pdf_signature_error
//check_digest(fz_context *ctx, pdf_pkcs7_verifier *verifier, unsigned char *sourcedata, size_t sourcedatalen, unsigned char *sig, size_t sig_len)
check_digest(fz_context *ctx, pdf_pkcs7_verifier *verifier, fz_stream* stm, unsigned char *sig, size_t sig_len)
{
    
    pdf_signature_error res = PDF_SIGNATURE_ERROR_UNKNOWN;
    if ( verifier == NULL || sig == NULL || sig_len <= 0) {
        return res;
    }
    FZZContentInfo contentInfo(sig,sig_len);
    FZZSignedData* signedData = contentInfo.getContent();
    if ( signedData == NULL ) {
        return res;
    }

//    FZZBytes * oidsignedData = contentInfo.getContentType();
//    uint32_t oidsignedData_nodes[] = {1,2,156,10197,6,1,4,2,2};
//    if ( memcmp(oidsignedData_nodes,oidsignedData->getData(),oidsignedData->getLen() ) != 0 ) {
//        return PDF_SIGNATURE_ERROR_NO_SIGNATURES;
//    }



    FZZGMCrypto gmCrypto;
    FZZBytes digestAct;
    gmCrypto.Digest_Init("SM3");
    read_best(ctx, stm, 4096,gmCrypto);
    gmCrypto.Digest_Finish(digestAct);
    if ( digestAct.getLen() < 8 ) {
        return PDF_SIGNATURE_ERROR_NO_SIGNATURES;
    }

    FZZBytes plaintext_src;

    GM_VERIFIER * gmverifier = (GM_VERIFIER *)verifier;
    vector<FZZSignerInfo*>* signerInfoList = signedData->getSignerInfos();
    vector<FZZSignerInfo *>::const_iterator SignerInfo_itr;
    for( SignerInfo_itr = signerInfoList->begin(); SignerInfo_itr != signerInfoList->end(); SignerInfo_itr++ ) {
        FZZSignerInfo* signerInfo = *SignerInfo_itr;
        if ( signerInfo == NULL ) {
            continue;
        }

        FZZAuthenticatedAttributes* authenticatedAttributes = signerInfo->getAuthenticatedAttributes();
        if ( authenticatedAttributes != NULL ) {
            FZZBytes * digest = authenticatedAttributes->getMessageDigest();
            if ( digest->getLen() == 0 ) {
                continue;
            }
            if ( memcmp(digest->getData(),digestAct.getData(),digestAct.getLen() ) != 0 ) {
                return PDF_SIGNATURE_ERROR_DIGEST_FAILURE;
            }
            plaintext_src = authenticatedAttributes->getPlainText();
            if ( plaintext_src.getLen() <= 0 ) {
                return PDF_SIGNATURE_ERROR_DIGEST_FAILURE;
            }
            
            gmverifier->signtime = authenticatedAttributes->getSigningTime();
        }
        
        

        FZZCert cert = signedData->getCertSignCert(signerInfo->getIssuer(),signerInfo->getSerialNumber());
        FZZKey* pubkey = cert.getPublicKey();
        if ( pubkey == NULL || pubkey->getKeyDataLen() <= 0 ) {
            return PDF_SIGNATURE_ERROR_DIGEST_FAILURE;
        }
        FZZBytes * signature = signerInfo->getEncryptedDigest();
        if ( signature != NULL ) {
            if ( gmverifier->verifyFunc != NULL ) {
                FZZBytes bKey;
                bKey.setData(pubkey->getKeyData(), pubkey->getKeyDataLen());
                //fzz edit begin 2024.06.06
    //            if ( !gmverifier->verifyFunc(gmverifier->callback_param,0,bKey,plaintext_src,*signature) ) {
    //                return PDF_SIGNATURE_ERROR_DIGEST_FAILURE;
    //            } else {
    //                res = PDF_SIGNATURE_ERROR_OKAY;
    //            }
                if ( !gmverifier->verifyFunc(gmverifier->callback_param,0,bKey.getData(),(int)bKey.getLen(),plaintext_src.getData(),(int)plaintext_src.getLen(),signature->getData(),(int)signature->getLen()) ) {
                    return PDF_SIGNATURE_ERROR_DIGEST_FAILURE;
                } else {
                    res = PDF_SIGNATURE_ERROR_OKAY;
                }
                //fzz edit end 2024.06.06
            } else {
                if ( !gmCrypto.verifySign(*pubkey,plaintext_src,*signature) ) {
                    return PDF_SIGNATURE_ERROR_DIGEST_FAILURE;
                } else {
                    res = PDF_SIGNATURE_ERROR_OKAY;
                }
            }
        }//if ( signature != NULL )

    }


    return res;
}
//-----------------------------------------------------------------------------------------------------------------
/************************public function*******************/
//-----------------------------------------------------------------------------------------------------------------
pdf_pkcs7_signer *pkcs7_gm_create_signer(fz_context *ctx, bool isCallBack,FZZCert *x509,FZZKey *prikey,
                                         CallBack_Sign singFunc,const void * callback_param,
                                         FZZBytes * imagedata)
{

    GM_SIGNER * signer = fz_malloc_struct(ctx, GM_SIGNER);
    if ( signer == NULL ) {
        //delete cert;
        //delete priKey;
        return NULL;
    }
    
    signer->base.keep = keep_signer;
    signer->base.drop = drop_signer;
    signer->base.get_signing_name = signer_distinguished_name;
    signer->base.max_digest_size = max_digest_size;
    signer->base.create_digest = signer_create_digest;
    signer->refs = 1;
    signer->isSignCallBack = isCallBack;
    signer->x509 = x509;
    signer->pkey = prikey;
    signer->singFunc = singFunc;
    signer->callback_param = callback_param;
    signer->imagedata = imagedata;
    signer->c = NULL;
    signer->cn = NULL;
    signer->o = NULL;
    signer->ou = NULL;
    signer->email = NULL;
    
    string subjectstr = signer->x509->getSubject();
    vector<string> itmes;
    FZZConst::split(subjectstr.c_str(), ",", itmes);
    vector<string>::const_iterator itr;
    string tempstr = "";
    size_t pos = 0;
    string item_key;
    string item_value;
    for( itr = itmes.begin(); itr != itmes.end(); itr++ ) {
        tempstr = *itr;
        pos = tempstr.find("=");
        if (pos != string::npos) {
            item_key = tempstr.substr(0,pos);
            transform(item_key.begin(), item_key.end(), item_key.begin(), ::toupper);
            item_value = tempstr.substr(pos+1);
            if ( item_key == "C" ) {
                if ( signer->c != NULL ) {
                    free(signer->c);
                }
                signer->c = (char *)malloc(item_value.length()+2);
                if ( signer->c != NULL ) {
                    strcpy(signer->c,item_value.c_str());
                }
                //signer->c = item_value;
            } else if ( item_key == "CN" ) {
                //signer->cn = item_value;
                if ( signer->cn != NULL ) {
                    free(signer->cn);
                    
                }
                signer->cn = (char *)malloc(item_value.length()+2);
                if ( signer->cn != NULL ) {
                    strcpy(signer->cn,item_value.c_str());
                }
            } else if ( item_key == "O" ) {
                //signer->o = item_value;
                if ( signer->o != NULL ) {
                    free(signer->o);
                }
                signer->o = (char *)malloc(item_value.length()+2);
                if ( signer->o != NULL ) {
                    strcpy(signer->o,item_value.c_str());
                }
            } else if ( item_key == "OU" ) {
                //signer->ou = item_value;
                if ( signer->ou != NULL ) {
                    free(signer->ou);
                }
                
                signer->ou = (char *)malloc(item_value.length()+2);
                if ( signer->ou != NULL ) {
                    strcpy(signer->ou,item_value.c_str());
                }
            } else if ( item_key == "E" || item_key == "EMAIL" ) {
                //signer->email = item_value;
                if ( signer->email != NULL ) {
                    free(signer->email);
                }
                signer->email = (char *)malloc(item_value.length()+2);
                if ( signer->email != NULL ) {
                    strcpy(signer->email,item_value.c_str());
                }
            }
        }
    }
    
    return &signer->base;
}
//-----------------------------------------------------------------------------------------------------------------
pdf_pkcs7_verifier *pkcs7_gm_create_verifier(fz_context *ctx,CallBack_Verify verifyFunc,const void * callback_param)
{
    
    GM_VERIFIER *verifier = NULL;
    verifier = fz_malloc_struct(ctx, GM_VERIFIER);
    verifier->refs = 1;
    verifier->signtime = 0;
    verifier->base.drop = drop_verifier;
    verifier->base.check_digest = check_digest;
    verifier->base.check_certificate = check_certificate;
    verifier->base.get_signatory = get_signatory;
    verifier->imagedata = NULL;
    verifier->verifyFunc = verifyFunc;
    verifier->callback_param = callback_param;
    verifier->cert_dn = NULL;
    verifier->c = NULL;
    verifier->cn = NULL;
    verifier->o = NULL;
    verifier->ou = NULL;
    verifier->email = NULL;
    return &verifier->base;
}
//-----------------------------------------------------------------------------------------------------------------
/**********************new_stamp_device*****************/
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_close_device(fz_context *ctx, fz_device *dev)
{
    //last close
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    //DLOG("stamp_dev_close_device is call");
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_drop_device(fz_context *ctx, fz_device *dev)
{
    //free
    stamp_device *pdev = (stamp_device*)dev;
    
    if ( pdev->genFontList != NULL ) {
        map<string,FZZGenFont*>::iterator it;
        for (it = pdev->genFontList->begin(); it != pdev->genFontList->end(); it++) {
            if ( it->second != NULL ) {
                delete (it->second);
            }
        }
        pdev->genFontList->clear();
        delete pdev->genFontList;
    }
    
    //DLOG("stamp_dev_drop_device is call");
}
//-----------------------------------------------------------------------------------------------------------------

//static bool valueInRange(int value, int min, int max)
//{ return (value >= min) && (value <= max); }
//
//static bool rectOverlap(fz_rect* A, fz_rect* B)
//{
//    bool xOverlap = valueInRange(A->x0, B->x0, B->x1) ||
//                    valueInRange(B->x0, A->x0, A->x1);
//
//    bool yOverlap = valueInRange(A->y0, B->y0, B->y1) ||
//                    valueInRange(B->y0, A->y0, A->y1);
//
//    return xOverlap && yOverlap;
//}

//static bool isContain(fz_rect * rect,float x,float y)
//{
//    DLOG("isContain (%f,%f,%f,%f),(%f,%f) ",rect->x0,rect->y0,rect->x1,rect->y1,x,y);
//    if ( rect == NULL ) {
//        return false;
//    }
//    if ( rect->x0 <= x && rect->y0 <= y && rect->x1 >= x && rect->y1 >= y) {
//        return true;
//    } else {
//        return false;
//    }
//
//
//
//}
//-----------------------------------------------------------------------------------------------------------------
static void copy_path_moveto(fz_context *ctx, void *arg, float x, float y)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_moveto(ctx, temp, x, y);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
static void copy_path_lineto(fz_context *ctx, void *arg, float x, float y)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_lineto(ctx, temp, x, y);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void copy_path_curveto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2, float x3, float y3)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_curveto(ctx, temp, x1, y1, x2, y2,x3,y3);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void copy_path_close(fz_context *ctx, void *arg)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_closepath(ctx, temp);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void copy_path_quadto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_quadto(ctx, temp, x1, y1, x2, y2);
    }
}
//-----------------------------------------------------------------------------------------------------------------
//static void copy_path_curvetov(fz_context *ctx, void *arg, float x2, float y2, float x3, float y3)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_curvetov(ctx, temp, x2, y2, x3, y3);
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
//static void copy_path_curvetoy(fz_context *ctx, void *arg, float x1, float y1, float x3, float y3)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_curvetoy(ctx, temp, x1, y1, x3, y3);
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
static void copy_path_rectto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_rectto(ctx, temp, x1, y1, x2, y2);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static const fz_path_walker copy_path_proc =
{
    copy_path_moveto,
    copy_path_lineto,
    copy_path_curveto,
    copy_path_close,
    copy_path_quadto,
    NULL,//copy_dev_path_curvetov,
    NULL,//copy_dev_path_curvetoy,
    copy_path_rectto
};
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_fill_text(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    fz_rect rect = fz_bound_text(ctx,text,NULL,ctm);
    if (!rectOverlap(&pdev->write_rect,&rect)) {
        return;
    }
    float tempAlpha = alpha;
    if ( pdev->isGroup ) {
        tempAlpha = pdev->group_Alpha;
    }
    //DLOG("stamp_dev_fill_text fill_text alpha:%f",tempAlpha);
    fz_colorspace *cs = fz_device_rgb(ctx);
    for (fz_text_span * span = text->head; span; span = span->next) {

        fz_matrix tm, trm;
        //fz_matrix trmp;
        //int gid;

        if ( span->len <= 0 ) continue;

        tm = span->trm;

        //fz_font_flags_t * fontFlags = fz_font_flags(span->font);
        //string strfontname = fz_font_name(ctx, span->font);
        //FontCache* fontCache = GetFontCache::getFont(strfontname);
        
        //fontSetting->setBold(fontFlags->is_bold);
        //fontSetting->setItalic(fontFlags->is_italic);
        for (int i = 0; i < span->len; i++) {
            //if (span->items[i].ucs < 0)
            //    continue;
            //fz_runetochar(ptempstr, span->items[i].ucs);

            //fz_text* temptext = fz_new_text(ctx);
            //const char * fontName = fz_font_name(ctx, span->font);
            //DLOG(fontName);
            tm.e = span->items[i].x;
            tm.f = span->items[i].y;
            trm = fz_concat(tm, ctm);
            fz_path* fontPath = fz_outline_glyph(ctx,span->font,span->items[i].gid,trm);
            if ( fontPath != NULL ) {

                
//                static int aa = 0;
//                aa++;
//                if ( aa > 1 ) {
//                    return;
//                }
                //fz_show_string(ctx, temptext, span->font, trm, ptempstr, false, 0, FZ_BIDI_LTR, FZ_LANG_UNSET);
                
                //float text_rgb[3] = { (float)(75.0f / 255.0f),(float)(10.0f / 255.0f),(float)(28.0f / 255.0f) };
                //float text_rgb[3] = {0.0,0.0,0.0};
                //fz_fill_path(ctx, pdev->write_dev, fontPath, 0, MUPDF_fz_identity, cs, color, 0.75f, fz_default_color_params);
                
                fz_fill_path(ctx, pdev->write_dev, fontPath, 0, MUPDF_fz_identity, cs, color, tempAlpha, fz_default_color_params);
                
                //fz_rect area = fz_bound_path(ctx, fontPath, NULL, MUPDF_fz_identity);
                //fz_clip_path(ctx,pdev->write_dev,fontPath,true,MUPDF_fz_identity,pdev->write_rect);
                //pdev->path,
                //fz_walk_path(ctx, fontPath, &copy_path_proc, pdev->path);
                
                
                //fz_rect clipbox = { 0, 0, 900, 700 };
                //fz_clip_path(ctx,pdev->write_dev,fontPath,false,MUPDF_fz_identity,clipbox);
                
                //fz_clip_path(ctx, pdev->write_dev, fontPath, 0, MUPDF_fz_identity, MuPDF_infinite_rect);
                //fz_show_glyph(ctx, temptext, span->font,trm,span->items[i].gid,span->items[i].ucs,span->wmode, span->bidi_level, FZ_BIDI_NEUTRAL, FZ_LANG_UNSET);
                //fz_fill_text(ctx, pdev->write_dev, temptext, MUPDF_fz_identity, colorspace,color, alpha, color_params);
                //fz_drop_text(ctx, temptext);
                fz_drop_path(ctx, fontPath);
                

           }
     
        }

    }

//    rect.x0 = 42;
//    rect.y0 = -6;
//    rect.x1 = 161.055;
//    rect.y1 = 113.055;

    
    //fz_clip_text(ctx, pdev->write_dev, text,  ctm,  rect);
    //fz_ignore_text(ctx, pdev->write_dev, text,  ctm);
    //fz_pop_clip(ctx,dev);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_fill_text_path(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    
    //DLOG("stamp_dev_fill_text is call");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    
    fz_rect rect = fz_bound_text(ctx,text,NULL,ctm);
//    if (rectOverlap(&pdev->write_rect,&rect)) {
//        fz_fill_text(ctx, pdev->write_dev, text, ctm, colorspace,color, alpha, color_params);
//    }
    if (!rectOverlap(&pdev->write_rect,&rect)) {
        return;
    }
    
    float tempAlpha = alpha;
    if ( pdev->isGroup ) {
        tempAlpha = pdev->group_Alpha;
    }
    
    
    //string fontname = fz_font_name(ctx,text->head->font);
    //DLOG("stamp_dev_fill_text %s",fontname.c_str());
    
    //fz_rect MuPDF_infinite_rect = { FZ_MIN_INF_RECT, FZ_MIN_INF_RECT, FZ_MAX_INF_RECT, FZ_MAX_INF_RECT };
    //fz_colorspace *cs = fz_device_rgb(ctx);
    
    //char tempstr[6] = {0};
    //char * ptempstr = tempstr;
    for (fz_text_span * span = text->head; span; span = span->next) {

        fz_matrix tm, trm;
        //fz_matrix trmp;
        //int gid;

        if ( span->len <= 0 ) continue;

        tm = span->trm;

        //fz_font_flags_t * fontFlags = fz_font_flags(span->font);
        //string strfontname = fz_font_name(ctx, span->font);
        //FontCache* fontCache = GetFontCache::getFont(strfontname);
        
        //fontSetting->setBold(fontFlags->is_bold);
        //fontSetting->setItalic(fontFlags->is_italic);
        for (int i = 0; i < span->len; i++) {
            //if (span->items[i].ucs < 0)
            //    continue;
            //fz_runetochar(ptempstr, span->items[i].ucs);

            //fz_text* temptext = fz_new_text(ctx);
            //const char * fontName = fz_font_name(ctx, span->font);
            //DLOG(fontName);
            //tm.e = span->items[i].x-0.008;
            //tm.f = span->items[i].y-0.008;
            tm.e = span->items[i].x;
            tm.f = span->items[i].y;
            trm = fz_concat(tm, ctm);
            fz_path* fontPath = fz_outline_glyph(ctx,span->font,span->items[i].gid,trm);
            if ( fontPath != NULL ) {

                
//                static int aa = 0;
//                aa++;
//                if ( aa > 1 ) {
//                    return;
//                }
                //fz_show_string(ctx, temptext, span->font, trm, ptempstr, false, 0, FZ_BIDI_LTR, FZ_LANG_UNSET);
                
                //float text_rgb[3] = { (float)(75.0f / 255.0f),(float)(10.0f / 255.0f),(float)(28.0f / 255.0f) };
                //float text_rgb[3] = {0.0,0.0,0.0};
                //fz_fill_path(ctx, pdev->write_dev, fontPath, 0, MUPDF_fz_identity, cs, color, 0.75f, fz_default_color_params);
                
                //fz_fill_path(ctx, pdev->write_dev, fontPath, 0, MUPDF_fz_identity, cs, color, 0.3f, fz_default_color_params);
                
                //fz_rect area = fz_bound_path(ctx, fontPath, NULL, MUPDF_fz_identity);
                //fz_clip_path(ctx,pdev->write_dev,fontPath,true,MUPDF_fz_identity,pdev->write_rect);
                //pdev->path,
                fz_walk_path(ctx, fontPath, &copy_path_proc, pdev->path);
                
                //fz_rect clipbox = { 0, 0, 900, 700 };
                //fz_clip_path(ctx,pdev->write_dev,fontPath,false,MUPDF_fz_identity,clipbox);
                
                //fz_clip_path(ctx, pdev->write_dev, fontPath, 0, MUPDF_fz_identity, MuPDF_infinite_rect);
                //fz_show_glyph(ctx, temptext, span->font,trm,span->items[i].gid,span->items[i].ucs,span->wmode, span->bidi_level, FZ_BIDI_NEUTRAL, FZ_LANG_UNSET);
                //fz_fill_text(ctx, pdev->write_dev, temptext, MUPDF_fz_identity, colorspace,color, alpha, color_params);
                //fz_drop_text(ctx, temptext);
                fz_drop_path(ctx, fontPath);
                

           }
     
        }

    }

    

    //fz_drop_font(ctx, font);
}

//static void stamp_dev_fill_text1(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm,
//        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
//{
//    //DLOG("stamp_dev_fill_text is call");
//    
//    stamp_device *pdev = (stamp_device*)dev;
//    if ( pdev == NULL ) {
//        return;
//    }
//    
//    fz_rect rect = fz_bound_text(ctx,text,NULL,ctm);
////    if (rectOverlap(&pdev->write_rect,&rect)) {
////        fz_fill_text(ctx, pdev->write_dev, text, ctm, colorspace,color, alpha, color_params);
////    }
//    if (!rectOverlap(&pdev->write_rect,&rect)) {
//        return;
//    }
//    
//    //fz_matrix MUPDF_fz_identity = { 1, 0, 0, 1, 0, 0 };
//    char tempstr[6] = {0};
//    char * ptempstr = tempstr;
//    fz_font *font = NULL;
//    FZZGenFont* genFont = NULL;
//    FZZBytes fontdata;
//    if ( pdev->isGenFont ) {
//        
//        
//       
//        
//        
//        string fontname = fz_font_name(ctx,text->head->font);
//        transform(fontname.begin(), fontname.end(), fontname.begin(), ::tolower);
//        
//        if ( text->head->font->buffer != NULL ) {
//            fontdata.setData(text->head->font->buffer->data,text->head->font->buffer->len);
//            font = fz_new_font_from_memory(ctx, NULL, fontdata.getData(), fontdata.getLen(), 0, 0);
//            if ( strcmp(fz_font_name(ctx,font),fz_font_name(ctx,text->head->font)) != 0 ) {
//                fz_drop_font(ctx, font);
//                fontdata.clear();
//              
//                if (fontname.find("simsun") != string::npos) {
//                    fontname = "simsun";
//                    FZZConst::readfile(FZZConst::getDefaultFontFileName(),fontdata);
//                } if (fontname.find("simhei") != string::npos) {
//                    fontname = "simhei";
//                    FZZConst::readfile(FZZConst::getDefaultFontPath()+"simhei.ttf",fontdata);
//                } if (fontname.find("simfang") != string::npos|| fontname.find("fangsong") != string::npos) {
//                    fontname = "simfang";
//                    FZZConst::readfile(FZZConst::getDefaultFontPath()+"simfang.ttf",fontdata);
//                } if (fontname.find("simkai") != string::npos) {
//                    fontname = "simkai";
//                    FZZConst::readfile(FZZConst::getDefaultFontPath()+"simkai.ttf",fontdata);
//                } else {
//                    fontname = "simsun";
//                    FZZConst::readfile(FZZConst::getDefaultFontFileName(),fontdata);
//                }
//                
//                //font = fz_new_font_from_memory(ctx, NULL, fontdata.getData(), fontdata.getLen(), 0, 0);
//            }
//        } else {
//            fontdata.clear();
//            if (fontname.find("simsun") != string::npos) {
//                fontname = "simsun";
//                FZZConst::readfile(FZZConst::getDefaultFontFileName(),fontdata);
//            } if (fontname.find("simhei") != string::npos) {
//                fontname = "simhei";
//                FZZConst::readfile(FZZConst::getDefaultFontPath()+"simhei.ttf",fontdata);
//            } if (fontname.find("simfang") != string::npos|| fontname.find("fangsong") != string::npos) {
//                fontname = "simfang";
//                FZZConst::readfile(FZZConst::getDefaultFontPath()+"simfang.ttf",fontdata);
//            } if (fontname.find("simkai") != string::npos) {
//                fontname = "simkai";
//                FZZConst::readfile(FZZConst::getDefaultFontPath()+"simkai.ttf",fontdata);
//            } else {
//                fontname = "simsun";
//                FZZConst::readfile(FZZConst::getDefaultFontFileName(),fontdata);
//            }
//            
//            //font = fz_new_font_from_memory(ctx, NULL, fontdata.getData(), fontdata.getLen(), 0, 0);
//        }
//        
//     
//        
//        
//        map<string,FZZGenFont*>::iterator it = pdev->genFontList->find(fontname);
//        
//        if (it != pdev->genFontList->end()) {
//            genFont =  it->second;
//            if ( genFont == NULL ) {
//                genFont = new FZZGenFont();
//                (*(pdev->genFontList))[fontname] = genFont;
//                genFont->setOldFont(fontdata);
//            }
//        } else {
//            genFont = new FZZGenFont();
//            pdev->genFontList->insert(pair<string,FZZGenFont*>(fontname ,genFont));
//            genFont->setOldFont(fontdata);
//        }
//        
//        for (fz_text_span * span = text->head; span; span = span->next) {
//            for (int i = 0; i < span->len; i++) {
//                if (span->items[i].ucs < 0)
//                    continue;
//                //fz_runetochar(ptempstr, span->items[i].ucs);
//                //DLOG("stamp_dev_fill_text %s",ptempstr);
//                //genFont->addData(ptempstr);
//                genFont->addData(span->items[i].ucs);
//            }
//        }
//        
//        
//    } else { //if ( pdev->isGenFont )
//    
//        
//        string fontname = fz_font_name(ctx,text->head->font);
//        transform(fontname.begin(), fontname.end(), fontname.begin(), ::tolower);
//        if ( text->head->font->buffer != NULL ) {
//            fontdata.setData(text->head->font->buffer->data,text->head->font->buffer->len);
//            font = fz_new_font_from_memory(ctx, NULL, fontdata.getData(), fontdata.getLen(), 0, 0);
//            if ( strcmp(fz_font_name(ctx,font),fz_font_name(ctx,text->head->font)) != 0 ) {
//                
//                if (fontname.find("simsun") != string::npos) {
//                    fontname = "simsun";
//                    
//                } if (fontname.find("simhei") != string::npos) {
//                    fontname = "simhei";
//                    
//                } if (fontname.find("simfang") != string::npos || fontname.find("fangsong") != string::npos) {
//                    fontname = "simfang";
//                    
//                } if (fontname.find("simkai") != string::npos) {
//                    fontname = "simkai";
//                   
//                } else {
//                    fontname = "simsun";
//                    
//                }
//            }
//        } else {
//           
//            if (fontname.find("simsun") != string::npos) {
//                fontname = "simsun";
//              
//            } if (fontname.find("simhei") != string::npos) {
//                fontname = "simhei";
//              
//            } if (fontname.find("simfang") != string::npos|| fontname.find("fangsong") != string::npos) {
//                fontname = "simfang";
//               
//            } if (fontname.find("simkai") != string::npos) {
//                fontname = "simkai";
//             
//            } else {
//                fontname = "simsun";
//                
//            }
//            
//            
//        }
//        
//        fz_drop_font(ctx, font);
//        
//        map<string,FZZGenFont*>::iterator it = pdev->genFontList->find(fontname);
//        if (it != pdev->genFontList->end()) {
//            genFont =  it->second;
//            genFont->genNewFont();
//            FZZBytes * tempFontData = genFont->getNewFontData();
//            font = fz_new_font_from_memory(ctx, NULL, tempFontData->getData(), tempFontData->getLen(), 0, 0);
//        } else {
//            DLOG(" not find font data");
//            return;
//        }
//
//        for (fz_text_span * span = text->head; span; span = span->next) {
//
//            fz_matrix tm, trm,trmp;
//            int gid;
//
//            if ( span->len <= 0 ) continue;
//
//            tm = span->trm;
//
//            fz_font_flags_t * fontFlags = fz_font_flags(span->font);
//            
//            //fontSetting->setBold(fontFlags->is_bold);
//            //fontSetting->setItalic(fontFlags->is_italic);
//            for (int i = 0; i < span->len; i++) {
//                if (span->items[i].ucs < 0)
//                    continue;
//                fz_runetochar(ptempstr, span->items[i].ucs);
//
//                fz_text* temptext = fz_new_text(ctx);
//                if ( temptext != NULL ) {
//
//                    tm.e = span->items[i].x;
//                    tm.f = span->items[i].y;
//                    trm = fz_concat(tm, ctm);
//                    
//                    fz_show_string(ctx, temptext, font, trm, ptempstr, false, 0, FZ_BIDI_LTR, FZ_LANG_UNSET);
//                    fz_fill_text(ctx, pdev->write_dev, temptext, MUPDF_fz_identity, colorspace,color, alpha, color_params);
//                    fz_drop_text(ctx, temptext);
//
//                }
//         
//            }
//
//        }
//
//        
//    } //if ( pdev->isGenFont )
//    fz_drop_font(ctx, font);
//}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_stroke_text(fz_context *ctx, fz_device *dev, const fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    fz_rect rect = fz_bound_text(ctx,text,NULL,ctm);
    if (!rectOverlap(&pdev->write_rect,&rect)) {
        return;
    }
    DLOG("stamp_dev_stroke_text is call");
    fz_colorspace *cs = fz_device_rgb(ctx);
    for (fz_text_span * span = text->head; span; span = span->next) {

        fz_matrix tm, trm;
        if ( span->len <= 0 ) continue;
        tm = span->trm;
        for (int i = 0; i < span->len; i++) {
            tm.e = span->items[i].x;
            tm.f = span->items[i].y;
            trm = fz_concat(tm, ctm);
            fz_path* fontPath = fz_outline_glyph(ctx,span->font,span->items[i].gid,trm);
            if ( fontPath != NULL ) {
                
                fz_stroke_path(ctx, pdev->write_dev, fontPath, stroke, MUPDF_fz_identity, cs, color, alpha, fz_default_color_params);
                fz_drop_path(ctx, fontPath);
                 

           }
     
        }

    }
    //fz_stroke_text(ctx,  pdev->write_dev, text, stroke,  ctm, colorspace, color,  alpha,  color_params);
    
    //fz_clip_stroke_path(<#fz_context *ctx#>, <#fz_device *dev#>, <#const fz_path *path#>, <#const fz_stroke_state *stroke#>, <#fz_matrix ctm#>, <#fz_rect scissor#>);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_clip_text(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm, fz_rect scissor)
{
    DLOG("stamp_dev_clip_text is call");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    
    fz_rect rect = fz_bound_text(ctx,text,NULL,ctm);
    
    if (rectOverlap(&pdev->write_rect,&rect)) {
        fz_clip_text(ctx, pdev->write_dev, text,  ctm,  scissor);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_clip_stroke_text(fz_context *ctx, fz_device *dev, const fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor)
{
    DLOG("stamp_dev_clip_stroke_text is call");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    fz_rect rect = fz_bound_text(ctx,text,NULL,ctm);

    if (rectOverlap(&pdev->write_rect,&rect)) {
        fz_clip_stroke_text(ctx,pdev->write_dev,text, stroke,  ctm,  scissor);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_ignore_text(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm)
{
    DLOG("stamp_dev_ignore_text is call");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    fz_rect rect = fz_bound_text(ctx,text,NULL,ctm);
    
    if (rectOverlap(&pdev->write_rect,&rect)) {
        fz_ignore_text(ctx,pdev->write_dev,text,ctm);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_fill_path(fz_context *ctx, fz_device *dev, const fz_path *path, int even_odd, fz_matrix ctm,
    fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    //DLOG("stamp_dev_fill_path");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    
    fz_rect rect = fz_bound_path(ctx, path, NULL, ctm);
    if (!rectOverlap(&pdev->write_rect,&rect)) {
        //DLOG("!rectOverlap");
        return;
    }

    if (colorspace == fz_device_gray(ctx)) {
        //cspace = 1;
        if ( color == NULL || (color[0] == 1.0f ) ) {
            //DLOG("color = 1");
            return;
        }
        
        DLOG("stamp_dev_fill_path rect: x:%lf,y:%lf,cx:%lf,cy:%lf, color :%f",rect.x0,rect.y0,rect.x1-rect.x0,rect.y1-rect.y0,color[0]*255);
    } else if (colorspace == fz_device_rgb(ctx)) {
        //cspace = 3;
        if ( color == NULL || (color[0] == 1.0f && color[1] == 1.0f && color[2] == 1.0f) ) {
            //DLOG("color = 1");
            return;
        }
        
        DLOG("stamp_dev_fill_path rect: x:%lf,y:%lf,cx:%lf,cy:%lf, color r:%f,g:%f,b:%f",rect.x0,rect.y0,rect.x1-rect.x0,rect.y1-rect.y0,color[0]*255,color[1]*255,color[2]*255);
    } else if (colorspace == fz_device_cmyk(ctx)) {
        //cspace = 4;
//        if ( color == NULL || (color[0] == 1.0f && color[1] == 1.0f && color[2] == 1.0f) ) {
//            //DLOG("color = 1");
//            return;
//        }
        
        DLOG("stamp_dev_fill_path not supper rect: x:%lf,y:%lf,cx:%lf,cy:%lf, color r:%f,g:%f,b:%f,b4 :%f",rect.x0,rect.y0,rect.x1-rect.x0,rect.y1-rect.y0,color[0]*255,color[1]*255,color[2]*255,color[3]*255);
        return ;
    } else {
        float rgb[FZ_MAX_COLORS];
        fz_convert_color(ctx, colorspace, color, fz_device_rgb(ctx), rgb, NULL, color_params);
        if (  rgb[0] == 1.0f && rgb[1] == 1.0f && rgb[2] == 1.0f ) {
            //DLOG("color = 1");
            return;
        }
        DLOG("stamp_dev_fill_path not know  rect: x:%lf,y:%lf,cx:%lf,cy:%lf, color r:%f,g:%f,b:%f",rect.x0,rect.y0,rect.x1-rect.x0,rect.y1-rect.y0,rgb[0]*255,rgb[1]*255,rgb[2]*255);
    }
    
    
    fz_fill_path(ctx,pdev->write_dev,path, even_odd, ctm,colorspace, color, alpha, color_params);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_stroke_path(fz_context *ctx, fz_device *dev, const fz_path *path, const fz_stroke_state *stroke, fz_matrix ctm,
    fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    //DLOG("stamp_dev_stroke_path");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    
    fz_rect rect = fz_bound_path(ctx, path, stroke, ctm);
    
    if (!rectOverlap(&pdev->write_rect,&rect)) {
        return;
    }
    
    
    
    //DLOG("stamp_dev_stroke_path rect: x:%lf,y:%lf,cx:%lf,cy:%lf, color r:%f,g:%f,b:%f",rect.x0,rect.y0,rect.x1-rect.x0,rect.y1-rect.y0,color[0]*255,color[1]*255,color[2]*255);
    if (colorspace == fz_device_gray(ctx)) {
        //cspace = 1;
        if ( color == NULL || (color[0] == 1.0f ) ) {
            //DLOG("color = 1");
            return;
        }
        
        //DLOG("stamp_dev_stroke_path rect: x:%lf,y:%lf,cx:%lf,cy:%lf, color :%f",rect.x0,rect.y0,rect.x1-rect.x0,rect.y1-rect.y0,color[0]*255);
    } else if (colorspace == fz_device_rgb(ctx)) {
        //cspace = 3;
        if ( color == NULL || (color[0] == 1.0f && color[1] == 1.0f && color[2] == 1.0f) ) {
            //DLOG("color = 1");
            return;
        }
        
        //DLOG("stamp_dev_stroke_path rect: x:%lf,y:%lf,cx:%lf,cy:%lf, color r:%f,g:%f,b:%f",rect.x0,rect.y0,rect.x1-rect.x0,rect.y1-rect.y0,color[0]*255,color[1]*255,color[2]*255);
    } else if (colorspace == fz_device_cmyk(ctx)) {
        //cspace = 4;
//        if ( color == NULL || (color[0] == 1.0f && color[1] == 1.0f && color[2] == 1.0f) ) {
//            //DLOG("color = 1");
//            return;
//        }
        
        //DLOG("stamp_dev_stroke_path not supper rect: x:%lf,y:%lf,cx:%lf,cy:%lf, color r:%f,g:%f,b:%f,b4 :%f",rect.x0,rect.y0,rect.x1-rect.x0,rect.y1-rect.y0,color[0]*255,color[1]*255,color[2]*255,color[3]*255);
        return ;
    } else {
        float rgb[FZ_MAX_COLORS];
        fz_convert_color(ctx, colorspace, color, fz_device_rgb(ctx), rgb, NULL, color_params);
        if (  rgb[0] == 1.0f && rgb[1] == 1.0f && rgb[2] == 1.0f ) {
            //DLOG("color = 1");
            return;
        }
        //DLOG("stamp_dev_stroke_path not know  rect: x:%lf,y:%lf,cx:%lf,cy:%lf, color r:%f,g:%f,b:%f",rect.x0,rect.y0,rect.x1-rect.x0,rect.y1-rect.y0,rgb[0]*255,rgb[1]*255,rgb[2]*255);
    }
    
    fz_stroke_state* tempstroke = fz_keep_stroke_state(ctx, stroke);
    if ( stroke->linewidth < 0.255f ) {
        //Suspect that 0.254 is the default value
        tempstroke->linewidth = tempstroke->linewidth * 0.8;
        ctm.f = ctm.f+(tempstroke->linewidth * ((1-0.8)/2))*ctm.d;
    }
    fz_stroke_path(ctx,pdev->write_dev,path, tempstroke, ctm,colorspace, color, alpha, color_params);
    fz_drop_stroke_state(ctx, tempstroke);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_clip_path(fz_context *ctx, fz_device *dev, const fz_path *path, int even_odd, fz_matrix ctm, fz_rect scissor)
{
    DLOG("stamp_dev_clip_path");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    
    fz_rect rect = fz_bound_path(ctx, path, NULL, ctm);
    if (!rectOverlap(&pdev->write_rect,&rect)) {
        return;
    }
    
    fz_clip_path(ctx,pdev->write_dev,path, even_odd,  ctm,  scissor);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_clip_stroke_path(fz_context *ctx, fz_device *dev, const fz_path *path, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor)
{
    DLOG("stamp_dev_clip_stroke_path");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    
    fz_rect rect = fz_bound_path(ctx, path, stroke, ctm);
    if (!rectOverlap(&pdev->write_rect,&rect)) {
        return;
    }
    
    fz_clip_stroke_path(ctx,pdev->write_dev,path, stroke,  ctm,  scissor);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_fill_image(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm, float alpha, fz_color_params color_params)
{
    //DLOG("stamp_dev_fill_image");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    fz_rect rect;
    rect.x0 = ctm.e+ctm.c;
    rect.y0 = ctm.f;
    rect.x1 = rect.x0 + ctm.a-ctm.c;
    rect.y1 = rect.y0 + ctm.d+ctm.b;
    
    
    
    if (!rectOverlap(&pdev->write_rect,&rect)) {
        //DLOG("!rectOverlap");
        return;
    }
    DLOG("stamp_dev_fill_image rect: x:%lf,y:%lf,cx:%lf,cy:%lf,alpha:%f",rect.x0,rect.y0,rect.x1-rect.x0,rect.y1-rect.y0,alpha);
    fz_fill_image(ctx,pdev->write_dev,image,  ctm,  alpha,  color_params);
    
//    FZZBytes picdata;
//    FZZConst::readfile("/Users/fzz/work/cpp/ofd/ofdcreator/build/xcode/ofdcreate/test/companystamp.png",picdata);
//
//
//
//    fz_image * fzimage = NULL;
//    fz_buffer *fzbuffer = NULL;
//    fzbuffer = fz_new_buffer_from_copied_data(ctx, picdata.getData(), picdata.getLen());
//    if ( fzbuffer == NULL ) {
//        return;
//    }
//
//    fzimage = fz_new_image_from_buffer(ctx, fzbuffer);
//    if ( fzimage == NULL ) {
//        return;
//    }

    if ( pdev->showgraphic != NULL ) {
        fz_matrix stampcmt;
        stampcmt.a = pdev->write_rect.x1 - pdev->write_rect.x0;
        stampcmt.b = 0;
        stampcmt.c = -0;
        stampcmt.d = pdev->write_rect.y1 - pdev->write_rect.y0;
        stampcmt.e = pdev->write_rect.x0;
        stampcmt.f = pdev->write_rect.y0;

        fz_path *path = fz_new_path(ctx);

        fz_rect scissor;

        scissor.x0 = rect.x0 < pdev->write_rect.x0 ? pdev->write_rect.x0 : rect.x0;
        scissor.x1 = rect.x1 < pdev->write_rect.x1 ? rect.x1 : pdev->write_rect.x1;
        scissor.y0 = rect.y0 < pdev->write_rect.y0 ? pdev->write_rect.y0 : rect.y0;
        scissor.y1 = rect.y1 < pdev->write_rect.y1 ? rect.y1 : pdev->write_rect.y1;

        fz_moveto(ctx, path, scissor.x0, scissor.y0);
        fz_lineto(ctx, path, scissor.x1, scissor.y0);
        fz_lineto(ctx, path, scissor.x1, scissor.y1);
        fz_lineto(ctx, path, scissor.x0, scissor.y1);
        fz_closepath(ctx, path);

        fz_clip_path(ctx,pdev->write_dev,path, false,  MUPDF_fz_identity,  scissor);
        fz_fill_image(ctx,pdev->write_dev,pdev->showgraphic,  stampcmt,  1.0f,  color_params);
        fz_pop_clip(ctx,pdev->write_dev);

    //    fz_drop_buffer(ctx, fzbuffer);
    //    fz_drop_image(ctx, fzimage);
    }
    
    //------------
//    fz_pixmap * pix = fz_get_unscaled_pixmap_from_image(ctx,image);
//    if ( pix == NULL ) {
//        return;
//    }
//
//    fz_buffer *buf = fz_new_buffer(ctx, INCREMENT_BUFLEN_PNG);
//    if ( buf != NULL ) {
//        fz_output * out = fz_new_output_with_buffer(ctx, buf);
//        if ( out != NULL ) {
//            fz_write_pixmap_as_png(ctx, out, pix);
//
//            FZZBytes imagedata(buf->data, buf->len);
//
//            ImageUtil imageUtil;
//            if ( !imageUtil.LoadImage(imagedata) ) {
//                return;
//            }
//            float width = imageUtil.getWidth();
//            float height = imageUtil.getHeight();
//            imageUtil.CreateImage(imageUtil.getWidth(), imageUtil.getHeight(), 255, 255, 255, 0);
//            imageUtil.SetPaintAlpha(255);
//            imageUtil.setPaintAntiAlias(true);
//            imageUtil.DrawImage(imagedata, 0, 0);
//
//            imageUtil.DrawImage(picdata, pdev->write_rect.x0-rect.x0, pdev->write_rect.y0-rect.y0,pdev->write_rect.x1-pdev->write_rect.x0,pdev->write_rect.y1-pdev->write_rect.y0);
//
//            picdata = imageUtil.EncodeImage(ImageUtil::TYPE::TYPE_PNG);
//
//            fz_image * fzimage = NULL;
//            fz_buffer *fzbuffer = NULL;
//            fzbuffer = fz_new_buffer_from_copied_data(ctx, picdata.getData(), picdata.getLen());
//            if ( fzbuffer == NULL ) {
//                return;
//            }
//
//            fzimage = fz_new_image_from_buffer(ctx, fzbuffer);
//            if ( fzimage == NULL ) {
//                return;
//            }
//
//            fz_fill_image(ctx,pdev->write_dev,fzimage,  ctm,  alpha,  color_params);
//
//            fz_drop_buffer(ctx, fzbuffer);
//            fz_drop_image(ctx, fzimage);
//
//
//
//            fz_close_output(ctx, out);
//            fz_drop_output(ctx, out);
//        }
//        fz_drop_buffer(ctx, buf);
//    }
//    fz_drop_pixmap(ctx, pix);
    
    
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_fill_image_mask(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    DLOG("stamp_dev_fill_image_mask");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    fz_rect rect;
    rect.x0 = ctm.e+ctm.c;
    rect.y0 = ctm.f;
    rect.x1 = rect.x0 + ctm.a-ctm.c;
    rect.y1 = rect.y0 + ctm.d+ctm.b;
    
    if (!rectOverlap(&pdev->write_rect,&rect)) {
        return;
    }
    fz_fill_image_mask(ctx,pdev->write_dev,image,  ctm,  colorspace, color,  alpha,  color_params);
}
//-----------------------------------------------------------------------------------------------------------------
static void
stamp_dev_clip_image_mask(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm, fz_rect scissor)
{
    DLOG("stamp_dev_clip_image_mask");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }

    
    fz_rect rect;
    rect.x0 = ctm.e+ctm.c;
    rect.y0 = ctm.f;
    rect.x1 = rect.x0 + ctm.a-ctm.c;
    rect.y1 = rect.y0 + ctm.d+ctm.b;
    if (!rectOverlap(&pdev->write_rect,&rect)) {
        return;
    }
    fz_clip_image_mask(ctx,pdev->write_dev, image,  ctm,  scissor);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_fill_shade(fz_context *ctx, fz_device *dev, fz_shade *shade, fz_matrix ctm, float alpha, fz_color_params color_params)
{
    DLOG("stamp_dev_fill_shade");
    
}
//-----------------------------------------------------------------------------------------------------------------
static void
stamp_dev_pop_clip(fz_context *ctx, fz_device *dev)
{
    DLOG("stamp_dev_pop_clip is call");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    fz_pop_clip(ctx,pdev->write_dev);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_begin_mask(fz_context *ctx, fz_device *dev, fz_rect bbox, int luminosity, fz_colorspace *colorspace, const float *color, fz_color_params color_params)
{
    //DLOG("stamp_dev_begin_mask is call");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    fz_begin_mask(ctx,pdev->write_dev, bbox,  luminosity,  colorspace, color,  color_params);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_end_mask(fz_context *ctx, fz_device *dev,fz_function *tr)
{
    DLOG("stamp_dev_end_mask is call");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    fz_end_mask(ctx,pdev->write_dev);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_begin_group(fz_context *ctx, fz_device *dev, fz_rect bbox, fz_colorspace *cs, int isolated, int knockout, int blendmode, float alpha)
{
    //DLOG("stamp_dev_begin_group is call , alpha:%f",alpha);
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    pdev->isGroup = true;
    pdev->group_Alpha = alpha;
    //fz_begin_group(ctx,pdev->write_dev,bbox, cs,  isolated,  knockout,  blendmode,  alpha);
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_end_group(fz_context *ctx, fz_device *dev)
{
    
    
    //DLOG("stamp_dev_end_group is call");
    stamp_device *pdev = (stamp_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    
    pdev->isGroup = false;
    pdev->group_Alpha = 1.0f;
    //fz_end_group(ctx,pdev->write_dev);
}
//-----------------------------------------------------------------------------------------------------------------
static int stamp_dev_begin_tile(fz_context *ctx, fz_device *dev, fz_rect area, fz_rect view, float xstep, float ystep, fz_matrix ctm, int id)
{
    //Tile: Tiles the contents of an area into an area.
    
    DLOG("stamp_dev_begin_tile is call");
//    stamp_device *pdev = (stamp_device*)dev;
//    if ( pdev == NULL ) {
//        return 0;
//    }
//    fz_begin_tile(ctx,pdev->write_dev, area,  view,  xstep,  ystep,  ctm,  id);
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
static void stamp_dev_end_tile(fz_context *ctx, fz_device *dev)
{
    DLOG("stamp_dev_end_tile is call");
//    stamp_device *pdev = (stamp_device*)dev;
//    if ( pdev == NULL ) {
//        return ;
//    }
//    fz_end_tile(ctx,pdev->write_dev);
}
//-----------------------------------------------------------------------------------------------------------------
fz_device * new_stamp_device(fz_context *ctx,fz_device *write_dev,fz_rect write_rect,bool isText,fz_image *showgraphic,fz_path *path)
{
    stamp_device *dev = fz_new_derived_device(ctx, stamp_device);
    if ( dev == NULL ) {
        return NULL;
    }
    
    dev->write_dev = write_dev;
    dev->write_rect = write_rect;
    
    dev->super.close_device = stamp_dev_close_device;
    dev->super.drop_device = stamp_dev_drop_device;

    if ( isText ) {
        dev->super.fill_path = stamp_dev_fill_path;
        dev->super.stroke_path = stamp_dev_stroke_path;
        dev->super.clip_path = NULL;
        dev->super.clip_stroke_path = NULL;
//        dev->super.clip_path = stamp_dev_clip_path;
//        dev->super.clip_stroke_path = stamp_dev_clip_stroke_path;
        

        dev->super.fill_text = stamp_dev_fill_text;
        dev->super.stroke_text = stamp_dev_stroke_text;
//        dev->super.clip_text = stamp_dev_clip_text;
//        dev->super.clip_stroke_text = stamp_dev_clip_stroke_text;
        dev->super.clip_text = NULL;
        dev->super.clip_stroke_text = NULL;
        dev->super.ignore_text = stamp_dev_ignore_text;

        //dev->super.fill_shade = stamp_dev_fill_shade;
        dev->super.fill_shade = NULL;
        dev->super.fill_image = stamp_dev_fill_image;
        dev->super.fill_image_mask = stamp_dev_fill_image_mask;
        //dev->super.fill_image_mask = NULL;
        //dev->super.clip_image_mask = stamp_dev_clip_image_mask;
        dev->super.clip_image_mask = NULL;

        //dev->super.pop_clip = stamp_dev_pop_clip;
        dev->super.pop_clip = NULL;

        dev->super.begin_mask = NULL;
        dev->super.end_mask = NULL;
//        dev->super.begin_mask = stamp_dev_begin_mask;
//        dev->super.end_mask = stamp_dev_end_mask;
        
        dev->super.begin_group = stamp_dev_begin_group;
        dev->super.end_group = stamp_dev_end_group;

        dev->super.begin_tile = NULL;
        dev->super.end_tile = NULL;
//        dev->super.begin_tile = stamp_dev_begin_tile;
//        dev->super.end_tile = stamp_dev_end_tile;
    } else {
        dev->super.fill_path = NULL;
        dev->super.stroke_path = NULL;
        dev->super.clip_path = NULL;
        dev->super.clip_stroke_path = NULL;

        dev->super.fill_text = stamp_dev_fill_text_path;
        dev->super.stroke_text = NULL;
        dev->super.clip_text = NULL;
        dev->super.clip_stroke_text = NULL;
        dev->super.ignore_text = NULL;

        dev->super.fill_shade = NULL;
        dev->super.fill_image = NULL;
        dev->super.fill_image_mask = NULL;
        dev->super.clip_image_mask = NULL;

        dev->super.pop_clip = NULL;

        dev->super.begin_mask = NULL;
        dev->super.end_mask = NULL;
        dev->super.begin_group = NULL;
        dev->super.end_group = NULL;

        dev->super.begin_tile = NULL;
        dev->super.end_tile = NULL;
    }
    
    
    dev->genFontList = new map<string,FZZGenFont*>();
    dev->isGenFont = true;
    dev->showgraphic = showgraphic;
    dev->isGroup = false;
    dev->group_Alpha = 1.0f;
    dev->path = path;
    
    return (fz_device*)dev;
}
//-----------------------------------------------------------------------------------------------------------------

