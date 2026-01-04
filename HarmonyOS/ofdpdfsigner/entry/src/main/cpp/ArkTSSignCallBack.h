//
// Created on 2024/7/1.
// zizheng fan
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef ofdpdfsigner_ArkTSSignCallBack_H
#define ofdpdfsigner_ArkTSSignCallBack_H

#include "ArkTSUtils.h"


void SignCallBackFunc(const void * param,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
void getUserCertCallBackFunc(const void * param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
void getSealCertCallBackFunc(const void * param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
bool VerifyCallBackFunc(const void * param,int algType,unsigned char * keyData,int keyDatalen,unsigned char * sourceData,int sourceDatalen,unsigned char * signData,int signDatalen);

void EncryptSM4CBCCallBackFunc(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
void DecryptSM4CBCCallBackFunc(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * encData,int encDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
void EncryptSM2CallBackFunc(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
void DecryptSM2CallBackFunc(const void * param,unsigned char * encData,int encDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
void GenerateRandomCallBackFunc(const void * param,size_t len,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);

#endif //ofdpdfsigner_ArkTSSignCallBack_H
