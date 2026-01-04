//
// Created on 2024/6/24.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ArkTSCrypto.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.h"
#include "../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZCInterface.h"
//-----------------------------------------------------------------------------------------------------------
napi_value GenerateRandom(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 1;  
    napi_value args[1];
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 1) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    int32_t length;
    napi_get_value_int32(env, args[0], &length);
    
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    bool isTF = generateRandom(length,&outData,&outDatalen);
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------
napi_value GenerateDigest(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 2;  
    napi_value args[2];
    FZZBytes algTypeData;
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 2) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    NapiStringUtf8ToString(env, args[0],algTypeData);
    if ( algTypeData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    string algType = (char *)algTypeData.getData();
    
    if ( algType != "SM3" ) {
        napi_throw_error(env, NULL, "algType not SM3");  
        return NULL;
    }
    
    size_t sourceDataLen = 0;  
    void* sourceData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[1], &valuetype, &sourceDataLen, &sourceData, nullptr, nullptr);
    if ( sourceDataLen <= 0 || sourceData == NULL ) {
        napi_throw_error(env, NULL, "sourceData is NULL");  
        return NULL;
    }
    //------------------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    bool isTF = generateDigest((unsigned char *)sourceData,sourceDataLen,&outData,&outDatalen);
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------
napi_value GenerateSymKey(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 2;  
    napi_value args[2];
    FZZBytes algTypeData;
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 2) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    NapiStringUtf8ToString(env, args[0],algTypeData);
    if ( algTypeData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    string algType = (char *)algTypeData.getData();
    
    if ( algType != "SM4" ) {
        napi_throw_error(env, NULL, "algType not SM4");  
        return NULL;
    }
    
    int32_t length;
    napi_get_value_int32(env, args[1], &length);
    
    //------------------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    bool isTF = generateSymKey(&outData,&outDatalen);
    
    napi_value keyData;
    DataToNapiUint8Array(env,outData,outDatalen,&keyData);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    napi_value keyType;
    StringToNapiString(env,"SM4",&keyType);
    
    napi_value result_obj = NULL;
    status = napi_create_object(env, &result_obj);
    if (status != napi_ok ) {  
        napi_throw_error(env, NULL, "Create result Obj error");  
        return NULL;  
    }
    napi_set_named_property(env, result_obj, "keyType", keyType);
    napi_set_named_property(env, result_obj, "key", keyData);
    
    return result_obj;
    
   
}
//-----------------------------------------------------------------------------------------------------------
napi_value GenerateAsymKey(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 2;  
    napi_value args[2];
    FZZBytes algTypeData;
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 2) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    
    NapiStringUtf8ToString(env, args[0],algTypeData);
    if ( algTypeData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    string algType = (char *)algTypeData.getData();
    
    if ( algType != "SM2" ) {
        napi_throw_error(env, NULL, "algType not SM2");  
        return NULL;
    }
    
    int32_t length;
    napi_get_value_int32(env, args[1], &length);
    
    //------------------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    unsigned char * outData2 = NULL;
    size_t outDatalen2 = 0;
    bool isTF = generateAsymKey(&outData,&outDatalen,&outData2,&outDatalen2);
    
    napi_value pubKey;
    DataToNapiUint8Array(env,outData,outDatalen,&pubKey);
    napi_value priKey;
    DataToNapiUint8Array(env,outData2,outDatalen2,&priKey);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    if ( outData2 != NULL ) {
        FZZFreeHandle(outData2);
        outData2 = NULL;
    }
    
    napi_value publicKeyType;
    StringToNapiString(env,"SM2_Public",&publicKeyType);
    
    napi_value privateKeyType;
    StringToNapiString(env,"SM2_Private",&privateKeyType);
    
    napi_value publicKey;
    status = napi_create_object(env, &publicKey);
    if (status != napi_ok ) {  
        napi_throw_error(env, NULL, "Create result Obj error");  
        return NULL;  
    }
    napi_set_named_property(env, publicKey, "keyType", publicKeyType);
    napi_set_named_property(env, publicKey, "key", pubKey);
    
    napi_value privateKey;
    status = napi_create_object(env, &privateKey);
    if (status != napi_ok ) {  
        napi_throw_error(env, NULL, "Create result Obj error");  
        return NULL;  
    }
    napi_set_named_property(env, privateKey, "keyType", privateKeyType);
    napi_set_named_property(env, privateKey, "key", priKey);
    
    napi_value result_obj = NULL;
    status = napi_create_object(env, &result_obj);
    if (status != napi_ok ) {  
        napi_throw_error(env, NULL, "Create result Obj error");  
        return NULL;  
    }
    napi_set_named_property(env, result_obj, "publicKey", publicKey);
    napi_set_named_property(env, result_obj, "privateKey", privateKey);
    
    return result_obj;
}
//-----------------------------------------------------------------------------------------------------------
napi_value Encrypt(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 3;  
    napi_value args[3];
    FZZBytes algTypeData;
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 3) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------------
    NapiStringUtf8ToString(env, args[0],algTypeData);
    if ( algTypeData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    string algType = (char *)algTypeData.getData();
    int intAlgType = 0;
    
    if ( algType == "SM4_CBC" ) {
        intAlgType = 1;
    } else if ( algType == "SM4_GCM" ) {
        intAlgType = 2;
    } else if ( algType == "SM4_CTR" ) {
        intAlgType = 3;
    } else if ( algType == "SM2_ENC" ) {
        intAlgType = 0;
    } else {
        napi_throw_error(env, NULL, "algType not SM4_CBC,SM4_GCM,SM4_CTR,SM2_ENC");
        return NULL;
    }
    
    //----------------------------------
    string keyType = "";
    NapiObjectPropertyToString(env,args[1],"keyType",keyType);
    FZZBytes keyData;
    NapiObjectPropertyToData(env,args[1],"key",keyData);
    
    int intKeyType = 0;
    
    if ( keyType == "SM2_Public" ) {
        intKeyType = 1;
    } else if ( keyType == "SM4" ) {
        intKeyType = 0;
    } else {
        napi_throw_error(env, NULL, "encryptKey not SM2_Public or SM4");
        return NULL;
    }
    //----------------------------------
    size_t sourceDataLen = 0;  
    void* sourceData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[2], &valuetype, &sourceDataLen, &sourceData, nullptr, nullptr);
    if ( sourceDataLen <= 0 || sourceData == NULL ) {
        napi_throw_error(env, NULL, "sourceData is NULL");  
        return NULL;
    }
    //----------------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    unsigned char * sm4GCMData = NULL;
    size_t sm4GCMDatalen = 0;
    bool isTF = encipher((int)intKeyType,keyData.getData(),(int)keyData.getLen(),(int)intAlgType,(unsigned char *)sourceData,(int)sourceDataLen,&outData,&outDatalen,&sm4GCMData,&sm4GCMDatalen);
    
    napi_value encryptData;
    DataToNapiUint8Array(env,outData,outDatalen,&encryptData);
    napi_value macData;
    DataToNapiUint8Array(env,sm4GCMData,sm4GCMDatalen,&macData);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    if ( sm4GCMData != NULL ) {
        FZZFreeHandle(sm4GCMData);
        sm4GCMData = NULL;
    }
    
    napi_value result_obj = NULL;
    status = napi_create_object(env, &result_obj);
    if (status != napi_ok ) {  
        napi_throw_error(env, NULL, "Create result Obj error");  
        return NULL;  
    }
    napi_set_named_property(env, result_obj, "encryptData", encryptData);
    napi_set_named_property(env, result_obj, "macData", macData);
    
    return result_obj;
}
//-----------------------------------------------------------------------------------------------------------
napi_value Decrypt(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 3;  
    napi_value args[3];
    FZZBytes algTypeData;
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 3) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------------
    NapiStringUtf8ToString(env, args[0],algTypeData);
    if ( algTypeData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    string algType = (char *)algTypeData.getData();
    int intAlgType = 0;
    
    if ( algType == "SM4_CBC" ) {
        intAlgType = 1;
    } else if ( algType == "SM4_GCM" ) {
        intAlgType = 2;
    } else if ( algType == "SM4_CTR" ) {
        intAlgType = 3;
    } else if ( algType == "SM2_ENC" ) {
        intAlgType = 0;
    } else {
        napi_throw_error(env, NULL, "algType not SM4_CBC,SM4_GCM,SM4_CTR,SM2_ENC");
        return NULL;
    }
    
    //----------------------------------
    string keyType = "";
    NapiObjectPropertyToString(env,args[1],"keyType",keyType);
    FZZBytes keyData;
    NapiObjectPropertyToData(env,args[1],"key",keyData);
    
    int intKeyType = 0;
    
    if ( keyType == "SM2_Private" ) {
        intKeyType = 2;
    } else if ( keyType == "SM4" ) {
        intKeyType = 0;
    } else {
        napi_throw_error(env, NULL, "encryptKey not SM2_Public or SM4");
        return NULL;
    }
    //----------------------------------
    FZZBytes encData;
    NapiObjectPropertyToData(env,args[2],"encryptData",encData);
    FZZBytes macData;
    if ( algType == "SM4_GCM" ) {
        NapiObjectPropertyToData(env,args[2],"macData",macData);
    } 
    //----------------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    bool isTF = decipher(intKeyType,keyData.getData(),(int)keyData.getLen(),intAlgType,encData.getData(),(int)encData.getLen(),macData.getData(),(int)macData.getLen(),&outData,&outDatalen);
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------
napi_value EncryptSM4CBC(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 3;  
    napi_value args[3];
  
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 3) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------------
    string keyType = "";
    NapiObjectPropertyToString(env,args[0],"keyType",keyType);
    FZZBytes keyData;
    NapiObjectPropertyToData(env,args[0],"key",keyData);
    
    if ( keyType != "SM4" ) {
        napi_throw_error(env, NULL, "encryptKey not SM4");
        return NULL;
    }
    //----------------------------------
    size_t ivDataLen = 0;  
    void* ivData = NULL;  
    napi_typedarray_type valuetype_iv = napi_uint8_array;
    napi_get_typedarray_info(env, args[1], &valuetype_iv, &ivDataLen, &ivData, nullptr, nullptr);
    if ( ivDataLen <= 0 || ivData == NULL ) {
        napi_throw_error(env, NULL, "ivData is NULL");  
        return NULL;
    }
    //----------------------------------
    size_t sourceDataLen = 0;  
    void* sourceData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[2], &valuetype, &sourceDataLen, &sourceData, nullptr, nullptr);
    if ( sourceDataLen <= 0 || sourceData == NULL ) {
        napi_throw_error(env, NULL, "encryptData is NULL");  
        return NULL;
    }
    //----------------------------------
   
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    bool isTF = encryptSM4CBC(keyData.getData(),(int)keyData.getLen(),(unsigned char *)ivData,(int)ivDataLen,(unsigned char *)sourceData,(int)sourceDataLen,&outData,&outDatalen);
    if ( !isTF ) {
        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        return NULL;
    }
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------
napi_value DecryptSM4CBC(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 3;  
    napi_value args[3];
  
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 3) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------------
    string keyType = "";
    NapiObjectPropertyToString(env,args[0],"keyType",keyType);
    FZZBytes keyData;
    NapiObjectPropertyToData(env,args[0],"key",keyData);
    
    if ( keyType != "SM4" ) {
        napi_throw_error(env, NULL, "encryptKey not SM4");
        return NULL;
    }
    //----------------------------------
    size_t ivDataLen = 0;  
    void* ivData = NULL;  
    napi_typedarray_type valuetype_iv = napi_uint8_array;
    napi_get_typedarray_info(env, args[1], &valuetype_iv, &ivDataLen, &ivData, nullptr, nullptr);
    if ( ivDataLen <= 0 || ivData == NULL ) {
        napi_throw_error(env, NULL, "ivData is NULL");  
        return NULL;
    }
    //----------------------------------
    size_t encDataLen = 0;  
    void* encData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[2], &valuetype, &encDataLen, &encData, nullptr, nullptr);
    if ( encDataLen <= 0 || encData == NULL ) {
        napi_throw_error(env, NULL, "encryptData is NULL");  
        return NULL;
    }
    //----------------------------------
   
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    bool isTF = decryptSM4CBC(keyData.getData(),(int)keyData.getLen(),(unsigned char *)ivData,(int)ivDataLen,(unsigned char *)encData,(int)encDataLen,&outData,&outDatalen);
    
    if ( !isTF ) {
        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        return NULL;
    }
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------
napi_value Sign(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 3;  
    napi_value args[3];
    FZZBytes algTypeData;
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 3) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------------
    NapiStringUtf8ToString(env, args[0],algTypeData);
    if ( algTypeData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    string algType = (char *)algTypeData.getData();
    
    
    //----------------------------------
    string keyType = "";
    NapiObjectPropertyToString(env,args[1],"keyType",keyType);
    FZZBytes keyData;
    NapiObjectPropertyToData(env,args[1],"key",keyData);
    
    int intAlgType = 0;
        
    if ( algType == "SM3_SM2" ) {
        if ( keyType != "SM2_Private" ) {
            napi_throw_error(env, NULL, "keyType not SM2_Private");
            return NULL;
        }
    } else {
        napi_throw_error(env, NULL, "algType not SM3_SM2");
        return NULL;
    }
    //----------------------------------
    size_t sourceDataLen = 0;  
    void* sourceData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[2], &valuetype, &sourceDataLen, &sourceData, nullptr, nullptr);
    if ( sourceDataLen <= 0 || sourceData == NULL ) {
        napi_throw_error(env, NULL, "sourceData is NULL");  
        return NULL;
    }
    //----------------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    bool isTF = sign(2,keyData.getData(),(int)keyData.getLen(),intAlgType,(unsigned char *)sourceData,(int)sourceDataLen,&outData,&outDatalen);
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------
napi_value Verify(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 4;  
    napi_value args[4];
    FZZBytes algTypeData;
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 4) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------------
    NapiStringUtf8ToString(env, args[0],algTypeData);
    if ( algTypeData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    
    string algType = (char *)algTypeData.getData();
    
    
    //----------------------------------
    string keyType = "";
    NapiObjectPropertyToString(env,args[1],"keyType",keyType);
    FZZBytes keyData;
    NapiObjectPropertyToData(env,args[1],"key",keyData);
    
    int intAlgType = 0;
        
    if ( algType == "SM3_SM2" ) {
        if ( keyType != "SM2_Public" ) {
            napi_throw_error(env, NULL, "keyType not SM2_Public");
            return NULL;
        }
    } else {
        napi_throw_error(env, NULL, "algType not SM3_SM2");
        return NULL;
    }
    //----------------------------------
    size_t sourceDataLen = 0;  
    void* sourceData = NULL;  
    napi_typedarray_type valuetype = napi_uint8_array;
    napi_get_typedarray_info(env, args[2], &valuetype, &sourceDataLen, &sourceData, nullptr, nullptr);
    if ( sourceDataLen <= 0 || sourceData == NULL ) {
        napi_throw_error(env, NULL, "sourceData is NULL");  
        return NULL;
    }
    //----------------------------------
    size_t signDataLen = 0;  
    void* signData = NULL;  
    napi_typedarray_type valuetype_sign = napi_uint8_array;
    napi_get_typedarray_info(env, args[3], &valuetype_sign, &signDataLen, &signData, nullptr, nullptr);
    if ( signDataLen <= 0 || signData == NULL ) {
        napi_throw_error(env, NULL, "signData is NULL");  
        return NULL;
    }
    //----------------------------------
    bool isTF = verify(1,keyData.getData(),(int)keyData.getLen(),intAlgType,(unsigned char *)sourceData,(int)sourceDataLen,(unsigned char *)signData,(int)signDataLen);
    
    return ReturnBool(env,isTF);
}
//-----------------------------------------------------------------------------------------------------------
napi_value GenerateRootCert(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 4;  
    napi_value args[4];
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 4) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------------
    FZZBytes certDNData;
    NapiStringUtf8ToString(env, args[0],certDNData);
    if ( certDNData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    //string certDN = (char *)certDNData.getData();
    //----------------------------------
    string keyType_public = "";
    NapiObjectPropertyToString(env,args[1],"keyType",keyType_public);
    FZZBytes keyData_public;
    NapiObjectPropertyToData(env,args[1],"key",keyData_public);
    
    if ( keyType_public != "SM2_Public" ) {
        napi_throw_error(env, NULL, "keyType not SM2_Public");
        return NULL;
    }
    //----------------------------------
    int32_t validDays;
    napi_get_value_int32(env, args[2], &validDays);
    //----------------------------------
    string keyType_rootPri = "";
    NapiObjectPropertyToString(env,args[3],"keyType",keyType_rootPri);
    FZZBytes keyData_rootPri;
    NapiObjectPropertyToData(env,args[3],"key",keyData_rootPri);
    
    if ( keyType_rootPri != "SM2_Private" ) {
        napi_throw_error(env, NULL, "keyType not SM2_Private");
        return NULL;
    }
    //----------------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    bool isTF = generateRootCert(0,keyData_public.getData(),(int)keyData_public.getLen(),certDNData.getData(),(int)certDNData.getLen(),validDays,keyData_rootPri.getData(),(int)keyData_rootPri.getLen(),&outData,&outDatalen);
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------
napi_value GenerateCert(napi_env env, napi_callback_info info)
{
    napi_status status;  
    size_t argc = 6;  
    napi_value args[6];
    
    // 获取参数  
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
    if (status != napi_ok || argc < 6) {  
        napi_throw_error(env, NULL, "Wrong number of arguments");  
        return NULL;  
    }
    //----------------------------------
    bool isSign = true;
    napi_get_value_bool(env, args[0], &isSign);
    //----------------------------------
    FZZBytes certDNData;
    NapiStringUtf8ToString(env, args[1],certDNData);
    if ( certDNData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    //string certDN = (char *)certDNData.getData();
    //----------------------------------
    string keyType_public = "";
    NapiObjectPropertyToString(env,args[2],"keyType",keyType_public);
    FZZBytes keyData_public;
    NapiObjectPropertyToData(env,args[2],"key",keyData_public);
    
    if ( keyType_public != "SM2_Public" ) {
        napi_throw_error(env, NULL, "keyType not SM2_Public");
        return NULL;
    }
    //----------------------------------
    int32_t validDays;
    napi_get_value_int32(env, args[3], &validDays);
    //----------------------------------
    FZZBytes rootCertDNData;
    NapiStringUtf8ToString(env, args[4],rootCertDNData);
    if ( rootCertDNData.getLen() <= 0 ) {
        napi_throw_error(env, NULL, "Could not convert string");  
        return NULL;  
    }
    //string rootCertDN = (char *)rootCertDNData.getData();
    //----------------------------------
    string keyType_rootPri = "";
    NapiObjectPropertyToString(env,args[5],"keyType",keyType_rootPri);
    FZZBytes keyData_rootPri;
    NapiObjectPropertyToData(env,args[5],"key",keyData_rootPri);
    
    if ( keyType_rootPri != "SM2_Private" ) {
        napi_throw_error(env, NULL, "keyType not SM2_Private");
        return NULL;
    }
    //----------------------------------
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    bool isTF = generateCert(0,isSign,keyData_public.getData(),(int)keyData_public.getLen(),certDNData.getData(),(int)certDNData.getLen(),rootCertDNData.getData(),(int)rootCertDNData.getLen(),validDays,keyData_rootPri.getData(),(int)keyData_rootPri.getLen(),&outData,&outDatalen);
    
    napi_value result_array = NULL;
    DataToNapiUint8Array(env,outData,outDatalen,&result_array);
    
    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
    
    return result_array;
}
//-----------------------------------------------------------------------------------------------------------



