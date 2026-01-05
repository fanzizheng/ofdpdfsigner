//
//  Created by zizheng fan on 2022/11/18.
//
#include "basic/FZZConst.h"
#include "gm/ses/parse/FZZVersionParser.h"
#include "gm/ses/parse/FZZSESVersion.h"
#include "gmssl/asn1.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZVersionParser******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVersionParser::FZZVersionParser()
{
    //DLOG("FZZVersionParser()");
    FZZConst::addClassCount("FZZVersionParser");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
FZZVersionParser::FZZVersionParser(const FZZVersionParser& obj):FZZVersionParser()
{
    //DLOG("FZZVersionParser(const FZZVersionParser& obj)");
    if ( this == &obj ) {
        return;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZVersionParser ::~FZZVersionParser()
{
    //DLOG("~FZZVersionParser()");
    FZZConst::delClassCount("FZZVersionParser");
}
//-----------------------------------------------------------------------------------------------------------------
FZZSESVersionHolder* FZZVersionParser::parseSES_SealVersion(const FZZBytes& o)
{
    FZZSESVersion::TYPE version;
    
//    if ( isV4Version(o) ) {
//        version = FZZSESVersion::TYPE::v4;
//    } else {
//        version = FZZSESVersion::TYPE::v1;
//    }
    version = isV4Version(o);
    
    return new FZZSESVersionHolder(version, o);
}
//-----------------------------------------------------------------------------------------------------------------

FZZSESVersionHolder* FZZVersionParser::parseSES_SignatureVersion(const FZZBytes& o)
{
    FZZSESVersion::TYPE version;
    
//    if ( isV4Version(o) ) {
//        version = FZZSESVersion::TYPE::v4;
//    } else {
//        version = FZZSESVersion::TYPE::v1;
//    }
    version = isV4Version(o);
    
    return new FZZSESVersionHolder(version, o);
}
//-----------------------------------------------------------------------------------------------------------------
//sign seal data
// v4:
//    sequence                      v4_1
//      ->sequence                  v4_1_1      //sign seal info
//      ->octet string              v4_1_2      //Certificate of seal maker
//      ->object identifier         v4_1_3      //signature algorithm identifier
//      ->bit string                v4_1_4      //sign value
//      ->bit string                v4_1_5      //[0] Timestamp of the signature value [Optional]

//seal data
// v4:
//    sequence                      v4_1
//      ->sequence                  v4_1_1      //seal info
//      ->octet string              v4_1_2      //Certificate of seal maker
//      ->object identifier         v4_1_3      //signature algorithm identifier
//      ->bit string                v4_1_4      //sign value
FZZSESVersion::TYPE FZZVersionParser::isV4Version(const FZZBytes& o)
{
    FZZSESVersion::TYPE isV4 = FZZSESVersion::TYPE::v1;
    const uint8_t * src_p = o.getData();
    size_t src_len = o.getLen();
    
    const uint8_t * in = src_p;
    size_t inlen = src_len;
    const uint8_t * data = NULL;
    size_t datalen = 0;
    
    int ret = 0;
    //v4_1
    
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        //DLOG(".......1");
        //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/aaa.dat", o.getData(), o.getLen());
        return isV4;
    }
    
    if ( *data == 0x06 ) {
        isV4 = FZZSESVersion::TYPE::vdata;
        return isV4;
    }
    
    in = data;
    inlen = datalen;
    //v4_1_1
    if ((ret = asn1_sequence_from_der(&data, &datalen, &in, &inlen)) != 1) {
        //DLOG(".......2");
        //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/aaa.dat", o.getData(), o.getLen());
        return isV4;
    }
    
    //in = data+datalen;
    //inlen = src_len - ((data - src_p) + datalen);
    //v4_1_2
    if ((ret = asn1_octet_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        //DLOG(".......3");
        //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/aaa.dat", o.getData(), o.getLen());
        return isV4;
    }
    
    uint32_t nodes[32];
    size_t nodes_count = 0;
    //v4_1_4
    if ((ret = asn1_object_identifier_from_der(nodes, &nodes_count, &in, &inlen)) != 1) {
        //DLOG(".......4");
        //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/aaa.dat", o.getData(), o.getLen());
        return isV4;
    }
    
    //v4_1_3
    if ((ret = asn1_bit_string_from_der(&data, &datalen, &in, &inlen)) != 1) {
        //DLOG(".......5");
        //FZZConst::writefile("/Users/fzz/Virtual Machines.localized/win10/share/aaa.dat", o.getData(), o.getLen());
        return isV4;
    }
    
    isV4 = FZZSESVersion::TYPE::v4;
    
    return isV4;
}
//-----------------------------------------------------------------------------------------------------------------





