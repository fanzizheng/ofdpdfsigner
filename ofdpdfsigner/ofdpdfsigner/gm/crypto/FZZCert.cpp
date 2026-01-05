//
//  Created by zizheng fan on 2022/10/28.
//
#include "basic/FZZConst.h"
#include "gm/crypto/FZZCert.h"
#include "gmssl/sm2.h"
#include "gmssl/oid.h"
#include "gmssl/error.h"
#include "gmssl/rand.h"
#include "gmssl/x509_str.h"
#include "gmssl/x509_oid.h"
#include "gmssl/x509_alg.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZCert******************************************************/
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZCert::FZZCert() : m_Version(X509_version_v3),m_SerialNumber(""),m_Issuer(""),m_Subject(""),m_NotBefore(""),m_NotAfter(""),
    m_SignatureAlgor(""),m_InnerSignatureAlgor("")
{
    //DLOG("FZZCert()");
    FZZConst::addClassCount("FZZCert");
}
//-----------------------------------------------------------------------------------------------------------------
FZZCert::FZZCert(const FZZCert& obj):FZZCert()
{
    if ( this == &obj ) {
        return;
    }
    m_CertData = obj.m_CertData;
    m_Version = obj.m_Version;
    m_SerialNumber = obj.m_SerialNumber;
    m_SerialNumberBytes = obj.m_SerialNumberBytes;
    m_Issuer = obj.m_Issuer;
    m_Subject = obj.m_Subject;
    m_NotBefore = obj.m_NotBefore;
    m_NotAfter = obj.m_NotAfter;
    m_SignatureAlgor = obj.m_SignatureAlgor;
    m_InnerSignatureAlgor = obj.m_InnerSignatureAlgor;
    m_PublicKey = obj.m_PublicKey;
}
//-----------------------------------------------------------------------------------------------------------------
FZZCert::~FZZCert()
{
    //DLOG("~FZZCert()");
    FZZConst::delClassCount("FZZCert");
}
//-----------------------------------------------------------------------------------------------------------------
const FZZCert& FZZCert::operator=(const FZZCert& obj)
{
    if ( this == &obj ) {
        return *this;
    }

    m_CertData = obj.m_CertData;
    m_Version = obj.m_Version;
    m_SerialNumber = obj.m_SerialNumber;
    m_SerialNumberBytes = obj.m_SerialNumberBytes;
    m_Issuer = obj.m_Issuer;
    m_Subject = obj.m_Subject;
    m_NotBefore = obj.m_NotBefore;
    m_NotAfter = obj.m_NotAfter;
    m_SignatureAlgor = obj.m_SignatureAlgor;
    m_InnerSignatureAlgor = obj.m_InnerSignatureAlgor;
    m_PublicKey = obj.m_PublicKey;
    
    return *this;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZCert::loadCert(const FZZBytes & certdata)
{
    return loadCert(certdata.getData(),certdata.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZCert::loadCert(const unsigned char * certdata, size_t certdatalen)
{
    bool ret = false;
    uint8_t *cert = NULL;
    size_t certlen = 0;
    int version = 0;
    const uint8_t *serial = NULL;
    size_t serial_len = 0;
    const uint8_t *issuer = NULL;
    size_t issuer_len = 0;
    SM2_KEY pub_key;
    uint8_t keybuf[512] = {0};
    uint8_t *pKeyBuf = keybuf;
    size_t keylen = 0;
    const uint8_t *subj;
    size_t subj_len;
    time_t not_before;
    time_t not_after;
    int signature_algor;
    int inner_signature_algor;
    
    m_CertData.setData(certdata, certdatalen);
    cert = m_CertData.getData();
    certlen = m_CertData.getLen();
    
    int interr = x509_cert_get_details(cert,certlen,
                                       &version,
                                       &serial,&serial_len,
                                       &inner_signature_algor,
                                       &issuer,&issuer_len,
                                       &not_before, &not_after,
                                       &subj,&subj_len,
                                       &pub_key,
                                       NULL,NULL,
                                       NULL,NULL,
                                       NULL,NULL,
                                       &signature_algor,
                                       NULL,NULL);
    
    if ( interr != 1 ) {
        ret = false;
        goto err;
    }
    
    if (sm2_public_key_info_to_der(&pub_key, &pKeyBuf, &keylen) != 1) {
        goto err;
    }
    m_PublicKey.setKeyID("");
    m_PublicKey.setKeyType(FZZKey::KEYTYPE_SM2_PUB_KEY);
    m_PublicKey.setKeyData(keybuf, (int)keylen);
    
    m_Version = (X509_Version)version;
    m_SerialNumberBytes.setData(serial, serial_len);
    m_SerialNumber = FZZConst::HexEncodeNoSpace(serial, serial_len);
    m_Issuer = get_x509_name_rdn(issuer, issuer_len);
    m_Subject = get_x509_name_rdn(subj, subj_len);
    m_NotBefore = FZZConst::format_time_YYYY_MM_DD_hh_mm_ss(not_before);
    m_NotAfter = FZZConst::format_time_YYYY_MM_DD_hh_mm_ss(not_after);
    m_SignatureAlgor = x509_signature_algor_name(signature_algor);
    m_InnerSignatureAlgor = x509_signature_algor_name(inner_signature_algor);
    
    ret = true;
err:
    return ret ;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZCert::CheckTermOfValidity()
{
    time_t not_before;
    time_t not_after;
    time_t now;

    const uint8_t *a = m_CertData.getData();
    size_t alen = m_CertData.getLen();
    
    x509_cert_get_details(a, alen,
        NULL, // version
        NULL, NULL, // serial
        NULL, // signature_algor
        NULL, NULL, // issuer
        &not_before, &not_after, // validity
        NULL, NULL, // subject
        NULL, // subject_public_key
        NULL, NULL, // issuer_unique_id
        NULL, NULL, // subject_unique_id
        NULL, NULL, // extensions
        NULL, // signature_algor
        NULL, NULL); // signature

    // not_before < now < not_after
    time(&now);
    if (not_before >= not_after) {
        return false;
    }
    if (now < not_before) {
      
        return false;
    }
    if (not_after < now) {
        
        return  false;
    }
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZCert::CheckCert(FZZBytes & rootCert)
{
    const uint8_t *a = m_CertData.getData();
    size_t alen = m_CertData.getLen();
    
    const uint8_t *root = rootCert.getData();
    size_t rootlen = rootCert.getLen();
    
    int depth = 5;
    int verify_result = 0;
    
    if (x509_certs_verify(a, alen,root, rootlen, depth, &verify_result) != 1 ) {
        return false;
    }
    
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
//gmssl -> x509_name_print
string FZZCert::get_x509_name_rdn(const uint8_t *d, size_t dlen)
{
    string strRet = "";
    
    const uint8_t *p;
    size_t len;
    const uint8_t *inp = d;
    size_t inplen = dlen;
    int count = 0;
    while (inplen) {
        
        if (asn1_set_from_der(&p, &len, &inp, &inplen) != 1) {
            return "";
        }
        if ( count > 0 ) {
            strRet += ",";
        }
        count++;
        strRet += get_x509_rdn(p, len);
        
    }
    
    return strRet;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCert::get_x509_rdn(const uint8_t *d, size_t dlen)
{
    string strRet = "";
    const uint8_t *p;
    size_t len;

    if (asn1_sequence_from_der(&p, &len, &d, &dlen) != 1) {
        return "";
    }
    
    strRet += get_x509_attr_type_and_value(p, len);
    while (dlen) {
        if (asn1_sequence_from_der(&p, &len, &d, &dlen) != 1) {
            return "";
        }
        strRet += get_x509_attr_type_and_value(p, len);
    }
    return strRet;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCert::get_x509_attr_type_and_value(const uint8_t *d, size_t dlen)
{
    string strRet = "";
    int oid, tag;
    const uint8_t *val;
    size_t vlen;

    
    if (x509_name_type_from_der(&oid, &d, &dlen) != 1) { error_print(); goto err; }
    if (oid == OID_email_address) {
        if (asn1_ia5_string_from_der((const char **)&val, &vlen, &d, &dlen) != 1) goto err;
        strRet += "E=";
        //strRet += get_format_string(val, vlen);
        strRet += get_asn1_string(val, vlen);
    } else {
        switch (oid) {
            case OID_at_name:
                strRet += "=";
                break;
            case OID_at_surname:
                strRet += "=";
                break;
            case OID_at_given_name:
                strRet += "=";
                break;
            case OID_at_initials:
                strRet += "=";
                break;
            case OID_at_generation_qualifier:
                strRet += "=";
                break;
            case OID_at_common_name:
                strRet += "CN=";
                break;
            case OID_at_locality_name:
                strRet += "L=";
                break;
            case OID_at_state_or_province_name:
                strRet += "S=";
                break;
            case OID_at_organization_name:
                strRet += "O=";
                break;
            case OID_at_organizational_unit_name:
                strRet += "OU=";
                break;
            case OID_at_title:
                strRet += "=";
                break;
            case OID_at_dn_qualifier:
                strRet += "=";
                break;
            case OID_at_country_name:
                strRet += "C=";
                break;
            case OID_at_serial_number:
                strRet += "SN=";
                break;
            case OID_at_pseudonym:
                strRet += "=";
                break;
            case OID_domain_component:
                strRet += "DC=";
                break;
            default:
                goto err;
        }
        
        if (x509_directory_name_from_der(&tag, &val, &vlen, &d, &dlen) != 1) goto err;
        
        strRet += get_asn1_string(val, vlen);
    }
    
    if (asn1_length_is_zero(dlen) != 1) goto err;
    
    return strRet;
err:
    //error_print();
    return "";
    
    
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCert::get_format_string(const uint8_t *d, size_t dlen)
{
    string strRet = "";
    while (dlen--) {
        strRet += *d++;
    }
    return strRet;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZCert::get_asn1_string(const uint8_t *d, size_t dlen)
{
    string strRet = "";
    while (dlen--) {
        strRet += *d++;
    }
    return strRet;
}
//-----------------------------------------------------------------------------------------------------------------

