//
//  Created by zizheng fan on 2022/10/28.
//
#include "basic/FZZConst.h"
#include "gm/crypto/FZZCertGenerator.h"
#include "gmssl/sm2.h"
#include "gmssl/oid.h"
#include "gmssl/error.h"
#include "gmssl/rand.h"
#include "gmssl/x509_str.h"
#include "gmssl/x509_oid.h"
#include "gmssl/x509_alg.h"
#include "gmssl/x509_ext.h"


//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZCertGenerator******************************************************/
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZCertGenerator::FZZCertGenerator() : m_Issuer(""),m_Subject(""),m_AddDays(365),m_KeyUsage(X509_KU_DIGITAL_SIGNATURE|X509_KU_NON_REPUDIATION|X509_KU_KEY_CERT_SIGN|X509_KU_CRL_SIGN|X509_KU_KEY_ENCIPHERMENT|X509_KU_DATA_ENCIPHERMENT|X509_KU_KEY_AGREEMENT|X509_KU_ENCIPHER_ONLY)
{
    //DLOG("FZZCertGenerator()");
    FZZConst::addClassCount("FZZCertGenerator");
    
    time(&m_NotBefore);
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
FZZCertGenerator::~FZZCertGenerator()
{
    //DLOG("~FZZCertGenerator()");
    FZZConst::delClassCount("FZZCertGenerator");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZCertGenerator::clearData()
{
    m_Issuer = "";
    m_Subject = "";
    m_AddDays = 365;
    time(&m_NotBefore);
    m_SerialNumber.clear();
    m_PublicKey.clear();
    m_PrivateKey.clear();
    
    m_KeyUsage = (X509_KU_DIGITAL_SIGNATURE|X509_KU_NON_REPUDIATION|X509_KU_KEY_CERT_SIGN|X509_KU_CRL_SIGN|X509_KU_KEY_ENCIPHERMENT|X509_KU_DATA_ENCIPHERMENT|X509_KU_KEY_AGREEMENT|X509_KU_ENCIPHER_ONLY);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZCertGenerator::set_x509_name(string value,uint8_t *name, size_t *namelen, size_t maxlen)
{
    vector<string> itmes;
    FZZConst::split(value.c_str(), ",", itmes);
    vector<string>::const_iterator itr;
    string tempstr = "";
    size_t pos = 0;
    string item_key;
    string item_value;
    
    *namelen = 0;
    
    for( itr = itmes.begin(); itr != itmes.end(); itr++ ) {
        tempstr = *itr;
        pos = tempstr.find("=");
        if (pos != string::npos) {
            item_key = tempstr.substr(0,pos);
            transform(item_key.begin(), item_key.end(), item_key.begin(), ::toupper);
            item_value = tempstr.substr(pos+1);
            if ( item_key == "C" ) {
                if (x509_name_add_country_name(name, namelen, maxlen, item_value.c_str()) != 1 ) {
                    return -1;
                }
            } else if ( item_key == "S" ) {
                if ( x509_name_add_state_or_province_name(name, namelen, maxlen, ASN1_TAG_PrintableString, (uint8_t *)item_value.c_str(), item_value.length() ) != 1 ) {
                    return -1;
                }
            } else if ( item_key == "L" ) {
                if ( x509_name_add_locality_name(name, namelen, maxlen, ASN1_TAG_PrintableString, (uint8_t *)item_value.c_str(), item_value.length() ) != 1 ) {
                    return -1;
                }
            } else if ( item_key == "O" ) {
                if ( x509_name_add_organization_name(name, namelen, maxlen, ASN1_TAG_PrintableString, (uint8_t *)item_value.c_str(), item_value.length()) != 1 ) {
                    return -1;
                }
            } else if ( item_key == "OU" ) {
                if ( x509_name_add_organizational_unit_name(name, namelen, maxlen, ASN1_TAG_PrintableString, (uint8_t *)item_value.c_str(), item_value.length() ) != 1 ) {
                    return -1;
                }
            } else if ( item_key == "CN" ) {
                if ( x509_name_add_common_name(name, namelen, maxlen, ASN1_TAG_PrintableString, (uint8_t *)item_value.c_str(), item_value.length() ) != 1 ) {
                    return -1;
                }
            } else if ( item_key == "SN" ) {
                if ( x509_name_add_rdn(name, namelen, maxlen, OID_at_serial_number, ASN1_TAG_PrintableString, (uint8_t *)item_value.c_str(), item_value.length(), NULL, 0) != 1 ) {
                    return -1;
                }
            } else if ( item_key == "DC" ) {
                if ( x509_name_add_domain_component(name, namelen, maxlen, item_value.c_str(), item_value.length()) != 1 ) {
                    return -1;
                }
            } else if ( item_key == "E" || item_key == "EMAIL" ) {
//                if ( x509_name_add_rdn(name, namelen, maxlen, OID_email_address, ASN1_TAG_IA5String, (uint8_t *)item_value.c_str(), item_value.length() , NULL, 0) != 1 ) {
//                    return -1;
//                }
            }
                
        }
    }//for
    
    return 1;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZCertGenerator::genCert()
{
    FZZBytes retCertData;
    uint8_t *serial = NULL;
    size_t seriallen = 0;
    uint8_t issuer[256];
    size_t issuer_len = 0;
    time_t not_before, not_after;
    uint8_t subject[256];
    size_t subject_len = 0;
    SM2_KEY sm2_publickey;
    SM2_KEY sm2_privatekey;
    uint8_t cert[1024] = {0};
    //uint8_t *p = cert;
    //const uint8_t *cp = cert;
    size_t certlen = 0;
    
    uint8_t exts[512];
    size_t extslen = 0;
    
    int key_usage = 0;
    
    size_t prikeylen = 0;
    const uint8_t *cpprikey = NULL;
    size_t pubkeylen = 0;
    const uint8_t *cppubkey = NULL;
    
    if ( m_Issuer.empty() || m_Subject.empty() || m_SerialNumber.getLen() <= 0 || m_PublicKey.getKeyDataLen() <= 0 ) {
        return retCertData;
    }
    
    if ( m_PrivateKey.getKeyDataLen() <= 0 ) {
        return retCertData;
    }
    
    memset(&sm2_privatekey,0x00,sizeof(SM2_KEY));
    prikeylen = m_PrivateKey.getKeyDataLen();
    cpprikey = m_PrivateKey.getKeyData();
    if (sm2_private_key_from_der(&sm2_privatekey, &cpprikey, &prikeylen) != 1 ) {
        return retCertData;
    }
    
    memset(&sm2_publickey,0x00,sizeof(SM2_KEY));
    pubkeylen = m_PublicKey.getKeyDataLen();
    cppubkey = m_PublicKey.getKeyData();
    if (sm2_public_key_info_from_der(&sm2_publickey, &cppubkey, &pubkeylen) != 1 ) {
        return retCertData;
    }
    
    
    serial = m_SerialNumber.getData();
    seriallen = m_SerialNumber.getLen();

    set_x509_name(m_Issuer,issuer, &issuer_len, sizeof(issuer));
    set_x509_name(m_Subject,subject, &subject_len, sizeof(subject));
    
    not_before = m_NotBefore;
    x509_validity_add_days(&not_after, not_before, m_AddDays);
    

    key_usage = m_KeyUsage;
    x509_exts_add_key_usage(exts, &extslen, sizeof(exts), 1, key_usage);

    if (x509_cert_sign(
        cert, &certlen, sizeof(cert),
        X509_version_v3,
        serial, seriallen,
        OID_sm2sign_with_sm3,
        issuer, issuer_len,
        not_before, not_after,
        subject, subject_len,
        &sm2_publickey,
        NULL, 0,
        NULL, 0,
        exts, extslen,
        &sm2_privatekey, SM2_DEFAULT_ID, strlen(SM2_DEFAULT_ID)) != 1) {
       
        return retCertData;
    }
    retCertData.setData(cert, certlen);
    return retCertData;
}
//-----------------------------------------------------------------------------------------------------------------

