//
//  Created by zizheng fan on 2023/12/15.
//
#include "basic/FZZConst.h"
#include "interface/FZZErrorCode.h"
#include "interface/FZZCInterface.h"
#include "interface/FZZJNIInterface.h"





//-----------------------------------------------------------------------------------------------------------------
#define JNI_SUCCESS 0
#define JNI_SUCCESS_MSG "success"

#define JNI_UNKNOW_FAIL -10001
#define JNI_UNKNOW_FAIL_MSG "error"

#define JNI_ALLOC_MEMORY_FAIL -10002
#define JNI_ALLOC_MEMORY_FAIL_MSG "Failed to allocate memory"

#define JNI_OFD_2_IMAGE_FAIL -10003
#define JNI_OFD_2_IMAGE_FAIL_MSG "Failed to convert picture"





#define JNI_NEWBYTEARRAY_FAIL 11004
#define JNI_NEWBYTEARRAY_FAIL_MSG "JNI library returned data processing, and failed to allocate memory for resultData data"
//-----------------------------------------------------------------------------------------------------------------
const char * JNI_GetErrorMessage(int64_t nError)
{
    switch(nError)
    {
        case JNI_SUCCESS:
            return JNI_SUCCESS_MSG;
        case JNI_UNKNOW_FAIL:
            return JNI_UNKNOW_FAIL_MSG;
        case JNI_ALLOC_MEMORY_FAIL:
            return JNI_ALLOC_MEMORY_FAIL_MSG;
        case JNI_OFD_2_IMAGE_FAIL:
            return JNI_OFD_2_IMAGE_FAIL_MSG;
        case JNI_NEWBYTEARRAY_FAIL:
            return JNI_NEWBYTEARRAY_FAIL_MSG;
        default:
            return JNI_UNKNOW_FAIL_MSG;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void JNI_SetObject(JNIEnv * env, jobject obj, jobject &jout, int64_t error,unsigned char * data,int datalen,
                 unsigned char * pubkey,int pubkeylen,unsigned char * prikey,int prikeylen)
{
    int64_t nError = error;
    

    do
    {
        jclass objectClass = env->GetObjectClass(jout);

        if (!objectClass)
        {
            
            break;
        }

        //resultData
        {
            jfieldID resultID = env->GetFieldID(objectClass, "resultData", "[B");
            if (resultID == NULL)
            {
                
                //break;
            }
            else
            {
                if (data && datalen)
                {
                    jbyteArray pResultArray = env->NewByteArray(datalen);

                    if (!pResultArray)
                    {
                        nError = JNI_NEWBYTEARRAY_FAIL;
                        env->SetObjectField(jout, resultID, NULL);
                        
                    }
                    else
                    {
                        env->SetByteArrayRegion(pResultArray, 0, datalen, (const jbyte*)data);
                        env->SetObjectField(jout, resultID, pResultArray);
                        env->DeleteLocalRef(pResultArray);
                    }
                }
                else
                {
                    env->SetObjectField(jout, resultID, NULL);
                    
                }
            }
        }
        //pubkey
        {
            jfieldID resultID = env->GetFieldID(objectClass, "resultData1", "[B");
            if (resultID == NULL)
            {
                
                //break;
            }
            else
            {
                if (pubkey && pubkeylen)
                {
                    jbyteArray pResultArray = env->NewByteArray(pubkeylen);

                    if (!pResultArray)
                    {
                        nError = JNI_NEWBYTEARRAY_FAIL;
                        env->SetObjectField(jout, resultID, NULL);
                        
                    }
                    else
                    {
                        env->SetByteArrayRegion(pResultArray, 0, pubkeylen, (const jbyte*)pubkey);
                        env->SetObjectField(jout, resultID, pResultArray);
                        env->DeleteLocalRef(pResultArray);
                    }
                }
                else
                {
                    env->SetObjectField(jout, resultID, NULL);
                    
                }
            }
        }
        //prikey
        {
            jfieldID resultID = env->GetFieldID(objectClass, "resultData2", "[B");
            if (resultID == NULL)
            {
                
                //break;
            }
            else
            {
                if (prikey && prikeylen)
                {
                    jbyteArray pResultArray = env->NewByteArray(prikeylen);

                    if (!pResultArray)
                    {
                        nError = JNI_NEWBYTEARRAY_FAIL;
                        env->SetObjectField(jout, resultID, NULL);
                        
                    }
                    else
                    {
                        env->SetByteArrayRegion(pResultArray, 0, prikeylen, (const jbyte*)prikey);
                        env->SetObjectField(jout, resultID, pResultArray);
                        env->DeleteLocalRef(pResultArray);
                    }
                }
                else
                {
                    env->SetObjectField(jout, resultID, NULL);
                    //jit_log_debug("JNI库返回数据处理，没有返回数据");
                }
            }
        }
        //errorCode
        {
            jfieldID errorID = env->GetFieldID(objectClass, "errorCode", "J");
            if (errorID == NULL)
            {
                
                //break;
            }
            else
            {
                env->SetLongField(jout, errorID, nError);
            }
        }

        //errorDescription
        {
            

            const char * pbErrorMessage = JNI_GetErrorMessage(nError);
            jfieldID ErrorMessageID = env->GetFieldID(objectClass, "errorDescription", "[B");
            if (ErrorMessageID == NULL)
            {
                
                //break;
            }
            else
            {
                if (pbErrorMessage )
                {
                    jbyteArray pErrorMessageArray = env->NewByteArray((jsize)strlen(pbErrorMessage));

                    if (!pErrorMessageArray)
                    {
                        nError = JNI_NEWBYTEARRAY_FAIL;
                        env->SetObjectField(jout, ErrorMessageID, NULL);
                        
                    }
                    else
                    {
                        env->SetByteArrayRegion(pErrorMessageArray, 0, (jsize)strlen(pbErrorMessage), (const jbyte*)pbErrorMessage);
                        env->SetObjectField(jout, ErrorMessageID, pErrorMessageArray);
                        env->DeleteLocalRef(pErrorMessageArray);
                    }
                }
                else
                    env->SetObjectField(jout, ErrorMessageID, NULL);
            }
        }
    } while (0);

    //free(pbErrorMessage);
}

//-----------------------------------------------------------------------------------------------------------------
int JNI_GetJbyteFromJbyteArray(JNIEnv * env, jbyteArray jbtA, jbyte** jbt, jsize* jsz)
{
    int nError = JNI_SUCCESS;
    do
    {
        if (jbtA)
        {
            jsize jLen = env->GetArrayLength(jbtA);
            *jbt = (jbyte*)malloc(jLen + 1);
            if (*jbt == NULL)
            {
                nError = JNI_ALLOC_MEMORY_FAIL;
                break;
            }
            memset(*jbt, 0, jLen + 1);
            env->GetByteArrayRegion(jbtA, 0, jLen, *jbt);
            *jsz = jLen;
        }
    } while (0);
    return nError;
}
//-----------------------------------------------------------------------------------------------------------------
int JNI_GetCharFromJstring(JNIEnv * env, jstring jstr, char** psz, jsize* jsz)
{
    int nError = JNI_SUCCESS;
    do
    {
        if (jstr)
        {
            jsize jLen = env->GetStringUTFLength(jstr);
            *psz = (char*)malloc(jLen + 1);
            if (*psz == NULL)
            {
                nError = JNI_ALLOC_MEMORY_FAIL;
                break;
            }

            memset(*psz, 0, jLen + 1);
            env->GetStringUTFRegion(jstr, 0, jLen, *psz);
            *jsz = jLen;
        }
    } while (0);

    return nError;
}
//-----------------------------------------------------------------------------------------------------------------
//fzz edit begin 2024.06.07
//FZZBytes CB_Sign(const void * param,const FZZBytes & sourceData)
//{
//    FZZBytes ret;
//    //DLOG("CB_Sign ...... beegin");
//    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
//    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
//        return ret;
//    }
//
//    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
//    if ( cls == NULL ) {
//        return ret;
//    }
//    jmethodID mid = p_param->env->GetMethodID(cls, "sign", "([B)[B");
//    if ( mid == NULL ) {
//        return ret;
//    }
//
//    jbyteArray jsourceData = p_param->env->NewByteArray((int)sourceData.getLen()); // 替换yourLength为你的数据长度
//    p_param->env->SetByteArrayRegion(jsourceData, 0, (int)sourceData.getLen(), (jbyte*)sourceData.getData());
//    // 调用Sign方法
//    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid, jsourceData);
//    p_param->env->DeleteLocalRef(jsourceData);
//
//    jbyte* pjbresult = NULL;
//    jsize jresultLen = 0;
//
//    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
//    {
//        ret.setData((unsigned char *)pjbresult, jresultLen);
//    }
//
//    if ( pjbresult != NULL ) {
//        free(pjbresult);
//        pjbresult = NULL;
//    }
//    //DLOG("CB_Sign ...... end");
//    return ret;
//}
////-----------------------------------------------------------------------------------------------------------------
//FZZBytes CB_getCert(const void * param)
//{
//    FZZBytes ret;
//    //DLOG("CB_getCert ...... beegin");
//    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
//    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
//        return ret;
//    }
//
//    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
//    if ( cls == NULL ) {
//        return ret;
//    }
//    jmethodID mid = p_param->env->GetMethodID(cls, "getUserCert", "()[B");
//    if ( mid == NULL ) {
//        return ret;
//    }
//
//    // 调用Sign方法
//    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid);
//
//
//    jbyte* pjbresult = NULL;
//    jsize jresultLen = 0;
//
//    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
//    {
//        ret.setData((unsigned char *)pjbresult, jresultLen);
//    }
//
//    if ( pjbresult != NULL ) {
//        free(pjbresult);
//        pjbresult = NULL;
//    }
//    //DLOG("CB_getCert ...... end");
//    return ret;
//}
////-----------------------------------------------------------------------------------------------------------------
//FZZBytes CB_getSealCert(const void * param)
//{
//    FZZBytes ret;
//    DLOG("CB_getSealCert ...... beegin");
//    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
//    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
//        return ret;
//    }
//
//    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
//    if ( cls == NULL ) {
//        return ret;
//    }
//
//    jmethodID mid = p_param->env->GetMethodID(cls, "getSealCert", "()[B");
//    if ( mid == NULL ) {
//        return ret;
//    }
//
//    // 调用Sign方法
//    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid);
//
//
//    jbyte* pjbresult = NULL;
//    jsize jresultLen = 0;
//
//    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
//    {
//        ret.setData((unsigned char *)pjbresult, jresultLen);
//    }
//
//    if ( pjbresult != NULL ) {
//        free(pjbresult);
//        pjbresult = NULL;
//    }
//    DLOG("CB_getSealCert ...... beegin");
//    return ret;
//}
////-----------------------------------------------------------------------------------------------------------------
//bool CB_Verify(const void * param,int algType,const FZZBytes & keyData,const FZZBytes & sourceData,const FZZBytes & signData)
//{
//    bool ret = false;
//
//    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
//    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
//        return ret;
//    }
//
//    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
//    if ( cls == NULL ) {
//        return ret;
//    }
//    jmethodID mid = p_param->env->GetMethodID(cls, "verify", "(I[B[B[B)Z");
//    if ( mid == NULL ) {
//        return ret;
//    }
//
//    jbyteArray jsourceData = p_param->env->NewByteArray((int)sourceData.getLen()); // 替换yourLength为你的数据长度
//    p_param->env->SetByteArrayRegion(jsourceData, 0, (int)sourceData.getLen(), (jbyte*)sourceData.getData());
//
//    jbyteArray jkeyData = p_param->env->NewByteArray((int)keyData.getLen()); // 替换yourLength为你的数据长度
//    p_param->env->SetByteArrayRegion(jkeyData, 0, (int)keyData.getLen(), (jbyte*)keyData.getData());
//
//    jbyteArray jsignData = p_param->env->NewByteArray((int)signData.getLen()); // 替换yourLength为你的数据长度
//    p_param->env->SetByteArrayRegion(jsignData, 0, (int)signData.getLen(), (jbyte*)signData.getData());
//    // 调用verify方法
//
//
//    jboolean javaBool = p_param->env->CallBooleanMethod(p_param->CallBack_obj, mid, (jint)algType,jkeyData,jsourceData,jsignData);
//
//    ret = static_cast<bool>(javaBool);
//
//    p_param->env->DeleteLocalRef(jsourceData);
//    p_param->env->DeleteLocalRef(jkeyData);
//    p_param->env->DeleteLocalRef(jsignData);
//
//    return ret;
//}
//-----------------------------------------------------------------------------------------------------------------
void CB_Sign(const void * param,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
   
    //DLOG("CB_Sign ...... beegin");
    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
    if ( outData == NULL || *outData == NULL  ) {
        *outDatalen = 5120;
        return ;
    }
    
    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
        return ;
    }
    
    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
    if ( cls == NULL ) {
        return ;
    }
    jmethodID mid = p_param->env->GetMethodID(cls, "sign", "([B)[B");
    if ( mid == NULL ) {
        return ;
    }
    
    jbyteArray jsourceData = p_param->env->NewByteArray((int)sourceDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jsourceData, 0, (int)sourceDatalen, (jbyte*)sourceData);
    // 调用Sign方法
    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid, jsourceData);
    p_param->env->DeleteLocalRef(jsourceData);
    
    jbyte* pjbresult = NULL;
    jsize jresultLen = 0;
  
    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
    {
        //ret.setData((unsigned char *)pjbresult, jresultLen);
        if ( *outDatalen >= jresultLen ) {
            *outDatalen = jresultLen;
            memcpy(*outData,(unsigned char *)pjbresult, jresultLen);
        }
    }
        
    if ( pjbresult != NULL ) {
        free(pjbresult);
        pjbresult = NULL;
    }
    //DLOG("CB_Sign ...... end");

}
//-----------------------------------------------------------------------------------------------------------------
void CB_getCert(const void * param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{

    //DLOG("CB_getCert ...... beegin");
    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
        return ;
    }
    
    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
    if ( cls == NULL ) {
        return ;
    }
    jmethodID mid = p_param->env->GetMethodID(cls, "getUserCert", "()[B");
    if ( mid == NULL ) {
        return ;
    }
    
    // 调用Sign方法
    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid);
    
    
    jbyte* pjbresult = NULL;
    jsize jresultLen = 0;
  
    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
    {
        if ( outData == NULL || *outData == NULL ) {
            *outDatalen = jresultLen;
        } else {
            if ( *outDatalen >= jresultLen ) {
                *outDatalen = jresultLen;
                memcpy(*outData,(unsigned char *)pjbresult, jresultLen);
            } else {
                *outDatalen = jresultLen;
            }
        }
    }
        
    if ( pjbresult != NULL ) {
        free(pjbresult);
        pjbresult = NULL;
    }
    //DLOG("CB_getCert ...... end");
   
}
//-----------------------------------------------------------------------------------------------------------------
void CB_getSealCert(const void * param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
  
    DLOG("CB_getSealCert ...... beegin");
    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
        return ;
    }
    
    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
    if ( cls == NULL ) {
        return ;
    }
    
    jmethodID mid = p_param->env->GetMethodID(cls, "getSealCert", "()[B");
    if ( mid == NULL ) {
        return ;
    }
    
    // 调用Sign方法
    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid);
    
    
    jbyte* pjbresult = NULL;
    jsize jresultLen = 0;
  
    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
    {
        if ( outData == NULL || *outData == NULL ) {
            *outDatalen = jresultLen;
        } else {
            if ( *outDatalen >= jresultLen ) {
                *outDatalen = jresultLen;
                memcpy(*outData,(unsigned char *)pjbresult, jresultLen);
            } else {
                *outDatalen = jresultLen;
            }
        }
    }
        
    if ( pjbresult != NULL ) {
        free(pjbresult);
        pjbresult = NULL;
    }
    DLOG("CB_getSealCert ...... beegin");
 
}
//-----------------------------------------------------------------------------------------------------------------
bool CB_Verify(const void * param,int algType,unsigned char * keyData,int keyDatalen,unsigned char * sourceData,int sourceDatalen,unsigned char * signData,int signDatalen)
{
    bool ret = false;
    
    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
        return ret;
    }
    
    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
    if ( cls == NULL ) {
        return ret;
    }
    jmethodID mid = p_param->env->GetMethodID(cls, "verify", "(I[B[B[B)Z");
    if ( mid == NULL ) {
        return ret;
    }
    
    jbyteArray jsourceData = p_param->env->NewByteArray((int)sourceDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jsourceData, 0, (int)sourceDatalen, (jbyte*)sourceData);
    
    jbyteArray jkeyData = p_param->env->NewByteArray((int)keyDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jkeyData, 0, (int)keyDatalen, (jbyte*)keyData);
    
    jbyteArray jsignData = p_param->env->NewByteArray((int)signDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jsignData, 0, (int)signDatalen, (jbyte*)signData);
    // 调用verify方法
    
    
    jboolean javaBool = p_param->env->CallBooleanMethod(p_param->CallBack_obj, mid, (jint)algType,jkeyData,jsourceData,jsignData);
    
    ret = static_cast<bool>(javaBool);
    
    p_param->env->DeleteLocalRef(jsourceData);
    p_param->env->DeleteLocalRef(jkeyData);
    p_param->env->DeleteLocalRef(jsignData);
    
    return ret;
}
//fzz edit end 2024.06.07
//-----------------------------------------------------------------------------------------------------------------
void CB_SystemFontFileName(const void * param,const char* const fullFileName)
{
    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
        return;
    }
    
    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
    if ( cls == NULL ) {
        return;
    }
    
    jmethodID mid = p_param->env->GetMethodID(cls, "systemFontFileName", "([B)V");
    if ( mid == NULL ) {
        return;
    }
    
    int len = (int)strlen(fullFileName);
    jbyteArray jsourceData = p_param->env->NewByteArray(len); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jsourceData, 0, len, (jbyte*)fullFileName);
    // 调用Sign方法
    p_param->env->CallVoidMethod(p_param->CallBack_obj, mid, jsourceData);
    p_param->env->DeleteLocalRef(jsourceData);
}
//-----------------------------------------------------------------------------------------------------------------
void CB_EncryptSM4CBC(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
    if ( outData == NULL || *outData == NULL  ) {
        *outDatalen = sourceDatalen+16;
        return ;
    }
    
    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
        return ;
    }
    
    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
    if ( cls == NULL ) {
        return ;
    }
    
    jmethodID mid = p_param->env->GetMethodID(cls, "encryptSM4CBC", "([B[B[B)[B");
    if ( mid == NULL ) {
        return ;
    }
    
    jbyteArray jsourceData = p_param->env->NewByteArray((int)sourceDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jsourceData, 0, (int)sourceDatalen, (jbyte*)sourceData);
    
    jbyteArray jKeyData = p_param->env->NewByteArray((int)KeyDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jKeyData, 0, (int)KeyDatalen, (jbyte*)keyData);
    
    jbyteArray jivData = p_param->env->NewByteArray((int)ivDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jivData, 0, (int)ivDatalen, (jbyte*)ivData);
    // 调用Sign方法
    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid, jKeyData,jivData,jsourceData);
    
    p_param->env->DeleteLocalRef(jsourceData);
    p_param->env->DeleteLocalRef(jKeyData);
    p_param->env->DeleteLocalRef(jivData);
    
    jbyte* pjbresult = NULL;
    jsize jresultLen = 0;
  
    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
    {
        //ret.setData((unsigned char *)pjbresult, jresultLen);
        if ( *outDatalen >= jresultLen ) {
            *outDatalen = jresultLen;
            memcpy(*outData,(unsigned char *)pjbresult, jresultLen);
        }
    }
        
    if ( pjbresult != NULL ) {
        free(pjbresult);
        pjbresult = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void CB_DecryptSM4CBC(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * encData,int encDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
    if ( outData == NULL || *outData == NULL  ) {
        *outDatalen = encDatalen;
        return ;
    }
    
    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
        return ;
    }
    
    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
    if ( cls == NULL ) {
        return ;
    }
    
    jmethodID mid = p_param->env->GetMethodID(cls, "decryptSM4CBC", "([B[B[B)[B");
    if ( mid == NULL ) {
        return ;
    }
    
    jbyteArray jencData = p_param->env->NewByteArray((int)encDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jencData, 0, (int)encDatalen, (jbyte*)encData);
    
    jbyteArray jKeyData = p_param->env->NewByteArray((int)KeyDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jKeyData, 0, (int)KeyDatalen, (jbyte*)keyData);
    
    jbyteArray jivData = p_param->env->NewByteArray((int)ivDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jivData, 0, (int)ivDatalen, (jbyte*)ivData);
    // 调用Sign方法
    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid, jKeyData,jivData,jencData);
    
    p_param->env->DeleteLocalRef(jencData);
    p_param->env->DeleteLocalRef(jKeyData);
    p_param->env->DeleteLocalRef(jivData);
    
    jbyte* pjbresult = NULL;
    jsize jresultLen = 0;
  
    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
    {
        //ret.setData((unsigned char *)pjbresult, jresultLen);
        if ( *outDatalen >= jresultLen ) {
            *outDatalen = jresultLen;
            memcpy(*outData,(unsigned char *)pjbresult, jresultLen);
        }
    }
        
    if ( pjbresult != NULL ) {
        free(pjbresult);
        pjbresult = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void CB_EncryptSM2(const void * param,unsigned char * keyData,int KeyDatalen,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
    if ( outData == NULL || *outData == NULL  ) {
        *outDatalen = sourceDatalen+120;
        return ;
    }
    
    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
        return ;
    }
    
    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
    if ( cls == NULL ) {
        return ;
    }
    
    jmethodID mid = p_param->env->GetMethodID(cls, "encryptSM2", "([B[B)[B");
    if ( mid == NULL ) {
        return ;
    }
    
    jbyteArray jsrcData = p_param->env->NewByteArray((int)sourceDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jsrcData, 0, (int)sourceDatalen, (jbyte*)sourceData);
    
    jbyteArray jKeyData = p_param->env->NewByteArray((int)KeyDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jKeyData, 0, (int)KeyDatalen, (jbyte*)keyData);
    
   
    // 调用Sign方法
    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid, jKeyData,jsrcData);
    
    p_param->env->DeleteLocalRef(jsrcData);
    p_param->env->DeleteLocalRef(jKeyData);
  
    
    jbyte* pjbresult = NULL;
    jsize jresultLen = 0;
  
    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
    {
        //ret.setData((unsigned char *)pjbresult, jresultLen);
        if ( *outDatalen >= jresultLen ) {
            *outDatalen = jresultLen;
            memcpy(*outData,(unsigned char *)pjbresult, jresultLen);
        }
    }
        
    if ( pjbresult != NULL ) {
        free(pjbresult);
        pjbresult = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void CB_DecryptSM2(const void * param,unsigned char * encData,int encDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
    if ( outData == NULL || *outData == NULL  ) {
        *outDatalen = encDatalen;
        return ;
    }
    
    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
        return ;
    }
    
    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
    if ( cls == NULL ) {
        return ;
    }
    
    jmethodID mid = p_param->env->GetMethodID(cls, "decryptSM2", "([B)[B");
    if ( mid == NULL ) {
        return ;
    }
    
    jbyteArray jencData = p_param->env->NewByteArray((int)encDatalen); // 替换yourLength为你的数据长度
    p_param->env->SetByteArrayRegion(jencData, 0, (int)encDatalen, (jbyte*)encData);
    
    // 调用Sign方法
    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid,jencData);
    
    p_param->env->DeleteLocalRef(jencData);
    
  
    
    jbyte* pjbresult = NULL;
    jsize jresultLen = 0;
  
    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
    {
        //ret.setData((unsigned char *)pjbresult, jresultLen);
        if ( *outDatalen >= jresultLen ) {
            *outDatalen = jresultLen;
            memcpy(*outData,(unsigned char *)pjbresult, jresultLen);
        }
    }
        
    if ( pjbresult != NULL ) {
        free(pjbresult);
        pjbresult = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void CB_GenerateRandom(const void * param,size_t len,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen)
{
   
    JNICALLBACKFUNC_PARAM * p_param = (JNICALLBACKFUNC_PARAM *)param;
    if ( outData == NULL || *outData == NULL  ) {
        *outDatalen = len;
        return ;
    }
    
    if ( p_param == NULL || p_param->env == NULL || p_param->CallBack_obj == NULL ) {
        return ;
    }
    
    jclass cls = p_param->env->GetObjectClass(p_param->CallBack_obj);
    if ( cls == NULL ) {
        return ;
    }
    
    jmethodID mid = p_param->env->GetMethodID(cls, "generateRandom", "(J)[B");
    if ( mid == NULL ) {
        return ;
    }
    
    // 调用Sign方法
    jbyteArray result = (jbyteArray)p_param->env->CallObjectMethod(p_param->CallBack_obj, mid,len);
    
    
    jbyte* pjbresult = NULL;
    jsize jresultLen = 0;
  
    if (JNI_GetJbyteFromJbyteArray(p_param->env, result, &pjbresult, &jresultLen) == JNI_SUCCESS)
    {
        //ret.setData((unsigned char *)pjbresult, jresultLen);
        if ( *outDatalen >= jresultLen ) {
            *outDatalen = jresultLen;
            memcpy(*outData,(unsigned char *)pjbresult, jresultLen);
        }
    }
        
    if ( pjbresult != NULL ) {
        free(pjbresult);
        pjbresult = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
/***********************************************JNIInterface**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
/***********************************************Crypto**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_generateRandom
  (JNIEnv * env, jobject obj, jint len, jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {

        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        
        bool isTF = generateRandom(len,&outData,&outDatalen);

        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_digest
  (JNIEnv * env, jobject obj, jint type, jbyteArray sourceData, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbSource = NULL;
    do {
        if ( type != JNI_TYPE_SM3 ) {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        jsize jSourceLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sourceData, &pjbSource, &jSourceLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        
        bool isTF = generateDigest((unsigned char *)pjbSource,jSourceLen,&outData,&outDatalen);
        
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbSource != NULL ) {
        free(pjbSource);
        pjbSource = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_generateKey
  (JNIEnv * env, jobject obj, jint algType, jint keyLength, jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        if ( algType != JNI_TYPE_SM4 ) {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        bool isTF = generateSymKey(&outData,&outDatalen);

        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_generateKeyPair
  (JNIEnv * env, jobject obj, jint algType, jint keyLength, jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        if ( algType != JNI_TYPE_SM2 ) {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        unsigned char * outData2 = NULL;
        size_t outDatalen2 = 0;
        bool isTF = generateAsymKey(&outData,&outDatalen,&outData2,&outDatalen2);

        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,outData2,(int)outDatalen2,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        if ( outData2 != NULL ) {
            FZZFreeHandle(outData2);
            outData2 = NULL;
        }
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_encrypt
  (JNIEnv * env, jobject obj, jint keyType, jbyteArray keyData, jint cryptoType, jbyteArray sourceData, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbSource = NULL;
    jbyte* pjbKey = NULL;
    do {
        if ( !(keyType == FZZKEYTYPE_SM4 || keyType == FZZKEYTYPE_SM2_PUB) ) {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        if ( !(cryptoType == FZZCRYPTOTYPEE_SM2 || cryptoType == FZZCRYPTOTYPEE_SM4_CBC || cryptoType == FZZCRYPTOTYPEE_SM4_GCM || cryptoType == FZZCRYPTOTYPEE_SM4_CTR) ) {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        jsize jSourceLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sourceData, &pjbSource, &jSourceLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jKeyLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, keyData, &pjbKey, &jKeyLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        unsigned char * sm4GCMData = NULL;
        size_t sm4GCMDatalen = 0;
        
        bool isTF = encipher((int)keyType,(unsigned char *)pjbKey,(int)jKeyLen,(int)cryptoType,(unsigned char *)pjbSource,(int)jSourceLen,&outData,&outDatalen,&sm4GCMData,&sm4GCMDatalen);
        
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,sm4GCMData,(int)sm4GCMDatalen,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        if ( sm4GCMData != NULL ) {
            FZZFreeHandle(sm4GCMData);
            sm4GCMData = NULL;
        }
        
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbSource != NULL ) {
        free(pjbSource);
        pjbSource = NULL;
    }
    if ( pjbKey != NULL ) {
        free(pjbKey);
        pjbKey = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_decrypt
  (JNIEnv * env, jobject obj, jint keyType, jbyteArray keyData, jint cryptoType, jbyteArray encData, jbyteArray sm4GCMData, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbEncData = NULL;
    jbyte* pjbKey = NULL;
    jbyte* pjbSm4GCMData = NULL;
    do {
        if ( !(keyType == FZZKEYTYPE_SM4 || keyType == FZZKEYTYPE_SM2_PRI) ) {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        if ( !(cryptoType == FZZCRYPTOTYPEE_SM2 || cryptoType == FZZCRYPTOTYPEE_SM4_CBC || cryptoType == FZZCRYPTOTYPEE_SM4_GCM || cryptoType == FZZCRYPTOTYPEE_SM4_CTR) ) {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        jsize jEncLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, encData, &pjbEncData, &jEncLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jSm4GCMLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sm4GCMData, &pjbSm4GCMData, &jSm4GCMLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jKeyLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, keyData, &pjbKey, &jKeyLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        
        bool isTF = decipher(keyType,(unsigned char *)pjbKey,(int)jKeyLen,cryptoType,(unsigned char *)pjbEncData,(int)jEncLen,(unsigned char *)pjbSm4GCMData,(int)jSm4GCMLen,&outData,&outDatalen);
        
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbEncData != NULL ) {
        free(pjbEncData);
        pjbEncData = NULL;
    }
    if ( pjbKey != NULL ) {
        free(pjbKey);
        pjbKey = NULL;
    }
    if ( pjbSm4GCMData != NULL ) {
        free(pjbSm4GCMData);
        pjbSm4GCMData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_sign
  (JNIEnv * env, jobject obj, jint cryptoType, jbyteArray keyData, jbyteArray sourceData, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbSourceData = NULL;
    jbyte* pjbKey = NULL;
    do {

        int keyType = FZZKEYTYPE_SM2_PRI;
        if ( cryptoType == FZZCRYPTOTYPEE_SM2 ) {
            keyType = FZZKEYTYPE_SM2_PRI;
        } else {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        jsize jSourceLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sourceData, &pjbSourceData, &jSourceLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jKeyLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, keyData, &pjbKey, &jKeyLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        
        bool isTF = sign(keyType,(unsigned char *)pjbKey,(int)jKeyLen,cryptoType,(unsigned char *)pjbSourceData,(int)jSourceLen,&outData,&outDatalen);
        
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbSourceData != NULL ) {
        free(pjbSourceData);
        pjbSourceData = NULL;
    }
    if ( pjbKey != NULL ) {
        free(pjbKey);
        pjbKey = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_verifySign
  (JNIEnv * env, jobject obj, jint cryptoType, jbyteArray keyData, jbyteArray sourceData, jbyteArray signData, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbSourceData = NULL;
    jbyte* pjbKey = NULL;
    jbyte* pjbSignData = NULL;
    do {

        int keyType = FZZKEYTYPE_SM2_PUB;
        if ( cryptoType == FZZCRYPTOTYPEE_SM2 ) {
            keyType = FZZKEYTYPE_SM2_PUB;
        } else {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        jsize jSourceLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sourceData, &pjbSourceData, &jSourceLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jSignLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, signData, &pjbSignData, &jSignLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jKeyLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, keyData, &pjbKey, &jKeyLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        bool isTF = verify(keyType,(unsigned char *)pjbKey,(int)jKeyLen,cryptoType,(unsigned char *)pjbSourceData,(int)jSourceLen,(unsigned char *)pjbSignData,(int)jSignLen);
        
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, NULL,0,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        
        
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbSourceData != NULL ) {
        free(pjbSourceData);
        pjbSourceData = NULL;
    }
    if ( pjbKey != NULL ) {
        free(pjbKey);
        pjbKey = NULL;
    }
    if ( pjbSignData != NULL ) {
        free(pjbSignData);
        pjbSignData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_generateRootCert
  (JNIEnv * env, jobject obj, jint keyType, jbyteArray DN, jbyteArray pubKey,jint days, jbyteArray rootPriKey, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbDNData = NULL;
    jbyte* pjbKey = NULL;
    jbyte* pjbRootPriKey = NULL;
    do {

        if ( keyType != FZZCRYPTOTYPEE_SM2 ) {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        jsize jDnLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, DN, &pjbDNData, &jDnLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jKeyLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, pubKey, &pjbKey, &jKeyLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jRootPriKeyLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, rootPriKey, &pjbRootPriKey, &jRootPriKeyLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        
        
        bool isTF = generateRootCert(keyType,(unsigned char *)pjbKey,(int)jKeyLen,(unsigned char *)pjbDNData,(int)jDnLen,days,(unsigned char *)pjbRootPriKey,(int)jRootPriKeyLen,&outData,&outDatalen);
        
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbDNData != NULL ) {
        free(pjbDNData);
        pjbDNData = NULL;
    }
    if ( pjbKey != NULL ) {
        free(pjbKey);
        pjbKey = NULL;
    }
    if ( pjbRootPriKey != NULL ) {
        free(pjbRootPriKey);
        pjbRootPriKey = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_generateCert
  (JNIEnv * env, jobject obj, jint keyType, jint isSign, jbyteArray DN, jbyteArray pubKey,jint days, jbyteArray rootDN, jbyteArray rootPriKey, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbDNData = NULL;
    jbyte* pjbRootDNData = NULL;
    jbyte* pjbKey = NULL;
    jbyte* pjbRootPriKey = NULL;
    do {

        if ( keyType != FZZCRYPTOTYPEE_SM2 ) {
            nError = JNI_UNKNOW_FAIL;
            break;
        }
        
        jsize jDnLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, DN, &pjbDNData, &jDnLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jKeyLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, pubKey, &pjbKey, &jKeyLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jRootPriKeyLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, rootPriKey, &pjbRootPriKey, &jRootPriKeyLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jRootDnLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, rootDN, &pjbRootDNData, &jRootDnLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        
        
        bool isTF = generateCert(keyType,isSign,(unsigned char *)pjbKey,(int)jKeyLen,(unsigned char *)pjbDNData,(int)jDnLen,(unsigned char *)pjbRootDNData,(int)jRootDnLen,days,(unsigned char *)pjbRootPriKey,(int)jRootPriKeyLen,&outData,&outDatalen);
        
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbDNData != NULL ) {
        free(pjbDNData);
        pjbDNData = NULL;
    }
    if ( pjbKey != NULL ) {
        free(pjbKey);
        pjbKey = NULL;
    }
    if ( pjbRootPriKey != NULL ) {
        free(pjbRootPriKey);
        pjbRootPriKey = NULL;
    }
    if ( pjbRootDNData != NULL ) {
        free(pjbRootDNData);
        pjbRootDNData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_encryptSM4CBC
  (JNIEnv * env, jobject obj, jbyteArray keyData, jbyteArray ivData, jbyteArray sourceData, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbSource = NULL;
    jbyte* pjbKey = NULL;
    jbyte* pjbIV = NULL;
    do {
        jsize jSourceLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sourceData, &pjbSource, &jSourceLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jKeyLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, keyData, &pjbKey, &jKeyLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jIVLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, ivData, &pjbIV, &jIVLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
       
        
        bool isTF = encryptSM4CBC((unsigned char *)pjbKey,(int)jKeyLen,(unsigned char *)pjbIV,(int)jIVLen,(unsigned char *)pjbSource,(int)jSourceLen,&outData,&outDatalen);
        
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbSource != NULL ) {
        free(pjbSource);
        pjbSource = NULL;
    }
    if ( pjbKey != NULL ) {
        free(pjbKey);
        pjbKey = NULL;
    }
    if ( pjbIV != NULL ) {
        free(pjbIV);
        pjbIV = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_decryptSM4CBC
  (JNIEnv * env, jobject obj,  jbyteArray keyData, jbyteArray ivData, jbyteArray encData, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbEncData = NULL;
    jbyte* pjbKey = NULL;
    jbyte* pjbIVData = NULL;
    do {
        
        jsize jEncLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, encData, &pjbEncData, &jEncLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jIVLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, ivData, &pjbIVData, &jIVLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jKeyLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, keyData, &pjbKey, &jKeyLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        
        bool isTF = decryptSM4CBC((unsigned char *)pjbKey,(int)jKeyLen,(unsigned char *)pjbIVData,(int)jIVLen,(unsigned char *)pjbEncData,(int)jEncLen,&outData,&outDatalen);
        
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        
    } while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbEncData != NULL ) {
        free(pjbEncData);
        pjbEncData = NULL;
    }
    if ( pjbKey != NULL ) {
        free(pjbKey);
        pjbKey = NULL;
    }
    if ( pjbIVData != NULL ) {
        free(pjbIVData);
        pjbIVData = NULL;
    }
}

//-----------------------------------------------------------------------------------------------------------------
/****************************************************Seal*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_createSeal
  (JNIEnv * env, jobject obj, jbyteArray sealid,jint type,jbyteArray sealname,jint width,jint height,jbyteArray createTime,jbyteArray startTime ,jbyteArray endTime,jbyteArray imageType,jbyteArray imageData,jobject signCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbSource = NULL;
    jbyte* pjbsealid = NULL;
    jbyte* pjbsealname = NULL;
    jbyte* pjbstartTime = NULL;
    jbyte* pjbimageType = NULL;
    
    jbyte* pjbcreateTime = NULL;
    jbyte* pjbendTime = NULL;
    do {
        jsize jSourceLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, imageData, &pjbSource, &jSourceLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jsealidLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sealid, &pjbsealid, &jsealidLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jsealnameLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sealname, &pjbsealname, &jsealnameLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jstartTimeLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, startTime, &pjbstartTime, &jstartTimeLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        jsize jimageTypeLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, imageType, &pjbimageType, &jimageTypeLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jcreateTimeLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, createTime, &pjbcreateTime, &jcreateTimeLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jendTimeLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, endTime, &pjbendTime, &jendTimeLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_sealid;
        b_sealid.setMaxLen(jsealidLen+3);
        b_sealid.setData_NotMalloc((unsigned char *)pjbsealid, jsealidLen);
        
        FZZBytes b_sealname;
        b_sealname.setMaxLen(jsealnameLen+3);
        b_sealname.setData_NotMalloc((unsigned char *)pjbsealname, jsealnameLen);
        
        FZZBytes b_starttime;
        b_starttime.setMaxLen(jstartTimeLen+3);
        b_starttime.setData_NotMalloc((unsigned char *)pjbstartTime,jstartTimeLen);
        
        FZZBytes b_imagetype;
        b_imagetype.setMaxLen(jimageTypeLen+3);
        b_imagetype.setData_NotMalloc((unsigned char *)pjbimageType, jimageTypeLen);

        FZZBytes b_createTime;
        b_createTime.setMaxLen(jcreateTimeLen+3);
        b_createTime.setData_NotMalloc((unsigned char *)pjbcreateTime,jcreateTimeLen);
        
        FZZBytes b_endTime;
        b_endTime.setMaxLen(jendTimeLen+3);
        b_endTime.setData_NotMalloc((unsigned char *)pjbendTime,jendTimeLen);
        

        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = signCallBack;
        
        bool isTF = createSeal((char *)b_sealid.getData(),type,(char *)b_sealname.getData(),width, height,(char *)b_createTime.getData(),(char *)b_starttime.getData(),(char *)b_endTime.getData(),(char *)b_imagetype.getData(),(unsigned char *)pjbSource, jSourceLen,CB_Sign,CB_getCert,CB_getSealCert,(void *)(&param),&outData,&outDatalen) == 0;
        //DLOG("outDatalen = %d",outDatalen);
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbSource != NULL ) {
        free(pjbSource);
        pjbSource = NULL;
    }
    if ( pjbsealid != NULL ) {
        free(pjbsealid);
        pjbsealid = NULL;
    }
    if ( pjbsealname != NULL ) {
        free(pjbsealname);
        pjbsealname = NULL;
    }
    if ( pjbstartTime != NULL ) {
        free(pjbstartTime);
        pjbstartTime = NULL;
    }
    if ( pjbimageType != NULL ) {
        free(pjbimageType);
        pjbimageType = NULL;
    }
    
    if ( pjbcreateTime != NULL ) {
        free(pjbcreateTime);
        pjbcreateTime = NULL;
    }
    
    if ( pjbendTime != NULL ) {
        free(pjbendTime);
        pjbendTime = NULL;
    }

}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_verifySeal
(JNIEnv * env, jobject obj, jbyteArray sealData,jobject verifyCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbSource = NULL;
    
    do {
        jsize jSourceLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sealData, &pjbSource, &jSourceLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = verifyCallBack;
        
        int ret = verifySeal((unsigned char *)pjbSource, jSourceLen,CB_Verify,(void *)(&param));
        //DLOG("outDatalen = %d",outDatalen);
        if ( ret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, NULL,0,NULL,0,NULL,0);
        } else {
            nError = ret;
        }

        

    }while(false);
    
    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbSource != NULL ) {
        free(pjbSource);
        pjbSource = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getSealImageData
(JNIEnv *env, jobject obj, jbyteArray sealData,jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbSource = NULL;

    do {
        jsize jSourceLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sealData, &pjbSource, &jSourceLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }

        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        bool isTF = getSealImageData((unsigned char *)pjbSource, jSourceLen,&outData,&outDatalen) == 0;
        //DLOG("outDatalen = %d",outDatalen);
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbSource != NULL ) {
        free(pjbSource);
        pjbSource = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getSealUserCertData
(JNIEnv * env, jobject obj, jbyteArray sealData,jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbSource = NULL;

    do {
        jsize jSourceLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, sealData, &pjbSource, &jSourceLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }

        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        bool isTF = getSealUserCertData((unsigned char *)pjbSource, jSourceLen,&outData,&outDatalen) == 0;
        //DLOG("outDatalen = %d",outDatalen);
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbSource != NULL ) {
        free(pjbSource);
        pjbSource = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************OFDStamp*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDVerifyDocment
(JNIEnv * env, jobject obj, jbyteArray docData,jobject verifyCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbdocData = NULL;
    
    do {
        jsize jdocDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, docData, &pjbdocData, &jdocDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = verifyCallBack;
        
        int iret = verifyDocment((unsigned char *)pjbdocData, jdocDataLen,1,NULL,CB_Verify,(void *)(&param),&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    
    if ( pjbdocData != NULL ) {
        free(pjbdocData);
        pjbdocData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDFStamp*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFVerifyDocment
(JNIEnv * env, jobject obj, jbyteArray docData,jbyteArray passWord,jobject verifyCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbdocData = NULL;
    jbyte* pjbpassWord = NULL;
    do {
        jsize jdocDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, docData, &pjbdocData, &jdocDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jpassWordLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, passWord, &pjbpassWord, &jpassWordLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_passWord;
        if ( jpassWordLen > 0 ) {
            b_passWord.setMaxLen(jpassWordLen+3);
            b_passWord.setData_NotMalloc((unsigned char *)pjbpassWord, jpassWordLen);
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = verifyCallBack;
        
        int iret = verifyDocment((unsigned char *)pjbdocData, jdocDataLen,2,b_passWord.getLen() > 0? (char *)(b_passWord.getData()):NULL,  CB_Verify,(void *)(&param),&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    
    if ( pjbdocData != NULL ) {
        free(pjbdocData);
        pjbdocData = NULL;
    }
    
    if ( pjbpassWord != NULL ) {
        free(pjbpassWord);
        pjbpassWord = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************FONT*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_GetAllSystemFontFileName
(JNIEnv * env, jobject obj, jobject systemFontFileNameCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = systemFontFileNameCallBack;
        
        
        bool iret = getAllSystemFontFileName(CB_SystemFontFileName,(void *)(&param));
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, NULL,0,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_saveFontFileNameCache
(JNIEnv * env, jobject obj, jbyteArray fontFileName, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbfontFileName = NULL;
    
    do {
        jsize jfontFileNameLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, fontFileName, &pjbfontFileName, &jfontFileNameLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
    
        FZZBytes b_fontFileName;
        b_fontFileName.setMaxLen(jfontFileNameLen+3);
        b_fontFileName.setData_NotMalloc((unsigned char *)pjbfontFileName, jfontFileNameLen);

        
        bool isTF = saveFontFileNameCache((char *)b_fontFileName.getData());
        //DLOG("outDatalen = %d",outDatalen);
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, NULL,0,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbfontFileName != NULL ) {
        free(pjbfontFileName);
        pjbfontFileName = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************Util*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_SetWorkPath
(JNIEnv * env, jobject obj, jbyteArray path, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbpath = NULL;
    
    do {
        jsize jpathLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, path, &pjbpath, &jpathLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
    
        FZZBytes b_path;
        b_path.setMaxLen(jpathLen+3);
        b_path.setData_NotMalloc((unsigned char *)pjbpath, jpathLen);

        
        bool isTF = setWorkPath((char *)b_path.getData());
        //DLOG("outDatalen = %d",outDatalen);
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, NULL,0,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbpath != NULL ) {
        free(pjbpath);
        pjbpath = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_SetTempPath
(JNIEnv * env, jobject obj, jbyteArray path, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbpath = NULL;
    
    do {
        jsize jpathLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, path, &pjbpath, &jpathLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
    
        FZZBytes b_path;
        b_path.setMaxLen(jpathLen+3);
        b_path.setData_NotMalloc((unsigned char *)pjbpath, jpathLen);

        
        bool isTF = setTempPath((char *)b_path.getData());
        
        //DLOG("outDatalen = %d",outDatalen);
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, NULL,0,NULL,0,NULL,0);
        } else {
            nError = JNI_UNKNOW_FAIL;
        }

        

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbpath != NULL ) {
        free(pjbpath);
        pjbpath = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************打开关闭文件句柄*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_openOFD
(JNIEnv * env, jobject obj, jbyteArray fileData, jobject retdata)
{
    int nError = 0;
    jbyte* pjbfileData = NULL;
    
    do {
        jsize jfileDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, fileData, &pjbfileData, &jfileDataLen);
        if (nError != JNI_SUCCESS)
        {
            JNI_SetObject(env, obj, retdata, 0, NULL,0,NULL,0,NULL,0);
            break;
        }
    
        HANDLE handle = ofd_open((unsigned char *)pjbfileData, jfileDataLen);
        if ( handle != NULL ) {
            intptr_t ptrValue = reinterpret_cast<intptr_t>(handle);
            JNI_SetObject(env, obj, retdata, ptrValue, NULL,0,NULL,0,NULL,0);
        } else {
            JNI_SetObject(env, obj, retdata, 0, NULL,0,NULL,0,NULL,0);
        }

    }while(false);

    if ( pjbfileData != NULL ) {
        free(pjbfileData);
        pjbfileData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_closeOFD
(JNIEnv * env, jobject obj, jlong handle)
{
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    if ( filehandle != NULL ) {
        ofd_close(filehandle);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_openPDF
(JNIEnv * env, jobject obj, jbyteArray fileData, jobject retdata)
{
    int nError = 0;
    jbyte* pjbfileData = NULL;
    
    do {
        jsize jfileDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, fileData, &pjbfileData, &jfileDataLen);
        if (nError != JNI_SUCCESS)
        {
            JNI_SetObject(env, obj, retdata, 0, NULL,0,NULL,0,NULL,0);
            break;
        }
    
        HANDLE handle = pdf_open((unsigned char *)pjbfileData, jfileDataLen);
        if ( handle != NULL ) {
            intptr_t ptrValue = reinterpret_cast<intptr_t>(handle);
            JNI_SetObject(env, obj, retdata, ptrValue, NULL,0,NULL,0,NULL,0);
        } else {
            JNI_SetObject(env, obj, retdata, 0, NULL,0,NULL,0,NULL,0);
        }

    }while(false);

    if ( pjbfileData != NULL ) {
        free(pjbfileData);
        pjbfileData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_closePDF
(JNIEnv * env, jobject obj, jlong handle)
{
    HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
    if ( filehandle != NULL ) {
        pdf_close(filehandle);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************OFDStamp handle*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDSignStamp_1Pos_1Handle
(JNIEnv * env, jobject obj, jlong fileHandle,jbyteArray stampData,jint pageIndex,jdouble x,jdouble y,jdouble stampwidth,jdouble stampheight,jboolean isContinueSign,jobject signCallBack, jobject retdata)
{
     int nError = JNI_SUCCESS;
     jbyte* pjbstampData = NULL;
     
     do {
         HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
         if (handle == NULL)
         {
             nError = ERR_OFD_LOAD;
             break;
         }
         
         jsize jstampDataLen = 0;
         nError = JNI_GetJbyteFromJbyteArray(env, stampData, &pjbstampData, &jstampDataLen);
         if (nError != JNI_SUCCESS)
         {
             break;
         }
         
         
         
         unsigned char * outData = NULL;
         size_t outDatalen = 0;

         //DLOG("ofd Datalen = %d",jSourceLen);
         JNICALLBACKFUNC_PARAM param;
         param.env = env;
         param.CallBack_obj = signCallBack;
         
         int iret = ofd_positionSign(handle,(unsigned char *)pjbstampData, jstampDataLen,pageIndex,x,y,stampwidth,stampheight,isContinueSign == 1 ? true : false,CB_Sign,CB_getCert,(void *)(&param),&outData,&outDatalen);
         //DLOG("outDatalen = %d",outDatalen);
         if ( iret == 0 ) {
             JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
         } else {
             nError = iret;
         }

         if ( outData != NULL ) {
             FZZFreeHandle(outData);
             outData = NULL;
         }

     }while(false);

     if (nError != JNI_SUCCESS) {
         JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
     }

     if ( pjbstampData != NULL ) {
         free(pjbstampData);
         pjbstampData = NULL;
     }
     
     
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDSignStamp_1Riding_1Handle
(JNIEnv * env, jobject obj, jlong fileHandle,jbyteArray stampData,jint RidingType,jdouble stampwidth,jdouble stampheight,jboolean isContinueSign,jobject signCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbstampData = NULL;
    
    
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }
        jsize jstampDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, stampData, &pjbstampData, &jstampDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = signCallBack;
        
        
        
        int iret = ofd_ridingSign(handle,(unsigned char *)pjbstampData, jstampDataLen,RidingType,stampwidth,stampheight,isContinueSign == 1 ? true : false,CB_Sign,CB_getCert,(void *)(&param),&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbstampData != NULL ) {
        free(pjbstampData);
        pjbstampData = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDSignStamp_1KeyWord_1Handle
 (JNIEnv * env, jobject obj, jlong fileHandle,jbyteArray stampData,jbyteArray keyword,jbyteArray KeywordRule,jdouble stampwidth,jdouble stampheight,jboolean isContinueSign,jobject signCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbstampData = NULL;
    jbyte* pjbkeywordData = NULL;
    jbyte* pjbKeywordRuleData = NULL;
    
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }
        
        jsize jstampDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, stampData, &pjbstampData, &jstampDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jkeywordDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, keyword, &pjbkeywordData, &jkeywordDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jKeywordRuleDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, KeywordRule, &pjbKeywordRuleData, &jKeywordRuleDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_keyword;
        b_keyword.setMaxLen(jkeywordDataLen+3);
        b_keyword.setData_NotMalloc((unsigned char *)pjbkeywordData, jkeywordDataLen);
        
        FZZBytes b_KeywordRule;
        b_KeywordRule.setMaxLen(jKeywordRuleDataLen+3);
        b_KeywordRule.setData_NotMalloc((unsigned char *)pjbKeywordRuleData, jKeywordRuleDataLen);
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = signCallBack;
        
        int iret = ofd_keywordSign(handle,(unsigned char *)pjbstampData, jstampDataLen,(char *)b_keyword.getData(),(char *)b_KeywordRule.getData(),stampwidth,stampheight,isContinueSign == 1 ? true : false,CB_Sign,CB_getCert,(void *)(&param),&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbstampData != NULL ) {
        free(pjbstampData);
        pjbstampData = NULL;
    }
    
    if ( pjbkeywordData != NULL ) {
        free(pjbkeywordData);
        pjbkeywordData = NULL;
    }
    if ( pjbKeywordRuleData != NULL ) {
        free(pjbKeywordRuleData);
        pjbKeywordRuleData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDClearStamps
(JNIEnv * env, jobject obj, jlong fileHandle, jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        
        int iret = ofd_clearSigns(handle,&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}

//-----------------------------------------------------------------------------------------------------------------
/****************************************************OFDConverter handle*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getOFDPageCount_1Handle
(JNIEnv * env, jobject obj, jlong fileHandle, jobject retdata)
{
      int nError = JNI_SUCCESS;
      
      do {
          HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
          if (handle == NULL)
          {
              nError = ERR_OFD_LOAD;
              break;
          }
          
          int pageCount = ofd_getPageCount(handle);

          JNI_SetObject(env, obj, retdata, pageCount, NULL,0,NULL,0,NULL,0);
      }while(false);

      if (nError != JNI_SUCCESS) {
          JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
      }

      
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getOFDPageSize_1Handle
  (JNIEnv *env, jobject obj, jlong fileHandle, jint pageNumber, jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }

        double pageWidth = 0;
        double pageHeight = 0;
        ofd_getPageSize(handle,pageNumber,pageWidth,pageHeight);
        if ( pageWidth != 0 && pageHeight != 0 ) {
            string strWidth = FZZConst::fmt(pageWidth);
            string strHeight = FZZConst::fmt(pageHeight);
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, (unsigned char *)strWidth.c_str(),(int)strWidth.length(),(unsigned char *)strHeight.c_str(),(int)strHeight.length(),NULL,0);
        } else {
            nError = ERR_PDF_PAGE_LOAD;
            break;
        }
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}

//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_ofdPage2Image_1Handle
  (JNIEnv * env, jobject obj, jlong fileHandle,jint jimagetype,jint jpageindex,jdouble jscale, jobject retdata)
{
    int nError = JNI_SUCCESS;
    
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }
        
        
        string type = "PNG";
        if ( jimagetype == 0 ) {
            type = "PNG";
        } else if ( jimagetype == 1 ) {
            type = "JPG";
        } else if ( jimagetype == 2 ) {
            type = "SVG";
        }

        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        bool isTF = ofd_pageToImage(handle,type.c_str(),jpageindex,jscale,&outData,&outDatalen);

        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_OFD_2_IMAGE_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_ofd2Image_1Handle
  (JNIEnv * env, jobject obj, jlong fileHandle,jint jimagetype,jdouble jscale, jobject retdata)
{
    int nError = JNI_SUCCESS;
    
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }
        string type = "PNG";
        if ( jimagetype == 0 ) {
            type = "PNG";
        } else if ( jimagetype == 1 ) {
            type = "JPG";
        } else if ( jimagetype == 2 ) {
            type = "SVG";
        }

        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        char * stroutDatalen = NULL;

        bool isTF = ofd_toImage(handle,type.c_str(),jscale,&outData,&outDatalen,&stroutDatalen);

        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,(unsigned char *)stroutDatalen,(int)(strlen(stroutDatalen)),NULL,0);
        } else {
            nError = JNI_OFD_2_IMAGE_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        if ( stroutDatalen != NULL ) {
            FZZFreeHandle(stroutDatalen);
            stroutDatalen = NULL;
        }
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_ofd2ImageToZip_1Handle
  (JNIEnv * env, jobject obj, jlong fileHandle,jint jimagetype,jdouble jscale, jobject retdata)
{
    int nError = JNI_SUCCESS;
    

    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }

        string type = "PNG";
        if ( jimagetype == 0 ) {
            type = "PNG";
        } else if ( jimagetype == 1 ) {
            type = "JPG";
        } else if ( jimagetype == 2 ) {
            type = "SVG";
        }

        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        bool isTF = ofd_toImageZip(handle,type.c_str(),jscale,&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_OFD_2_IMAGE_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_ofd2PDF_1Handle
  (JNIEnv * env, jobject obj, jlong fileHandle,jint isNoStamp,jint isEncrypt,jbyteArray passWord, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbpassWord = NULL;
    
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }
        
        jsize jPassWordLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, passWord, &pjbpassWord, &jPassWordLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_password;
        b_password.setMaxLen(jPassWordLen+3);
        b_password.setData_NotMalloc((unsigned char *)pjbpassWord, jPassWordLen);
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        bool isTF = ofdToPdf(handle,isNoStamp == 1?true:false,isEncrypt == 1?true:false,(char *)b_password.getData(),&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_OFD_2_IMAGE_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbpassWord != NULL ) {
        free(pjbpassWord);
        pjbpassWord = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDFConverter handle*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getPDFPageCount_1Handle
  (JNIEnv * env, jobject obj, jlong fileHandle, jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }

        int pageCount = pdf_getPageCount(handle);

        JNI_SetObject(env, obj, retdata, pageCount, NULL,0,NULL,0,NULL,0);
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_getPDFPageSize_1Handle
  (JNIEnv *env, jobject obj, jlong fileHandle, jint pageNumber, jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }

        double pageWidth = 0;
        double pageHeight = 0;
        pdf_getPageSize(handle,pageNumber,pageWidth,pageHeight);
        if ( pageWidth != 0 && pageHeight != 0 ) {
            string strWidth = FZZConst::fmt(pageWidth);
            string strHeight = FZZConst::fmt(pageHeight);
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, (unsigned char *)strWidth.c_str(),(int)strWidth.length(),(unsigned char *)strHeight.c_str(),(int)strHeight.length(),NULL,0);
        } else {
            nError = ERR_PDF_PAGE_LOAD;
            break;
        }
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_pdfPage2Image_1Handle
  (JNIEnv * env, jobject obj, jlong fileHandle,jint jimagetype,jint jpageindex, jdouble jscale, jobject retdata)
{
    int nError = JNI_SUCCESS;
    
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }
        string type = "PNG";
        if ( jimagetype == 0 ) {
            type = "PNG";
        } else if ( jimagetype == 1 ) {
            type = "JPG";
        } else if ( jimagetype == 2 ) {
            type = "SVG";
        }

        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        bool isTF = pdf_pageToImage(handle,type.c_str(),jpageindex,jscale,&outData,&outDatalen);

        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_OFD_2_IMAGE_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_pdf2Image_1Handle
  (JNIEnv * env, jobject obj, jlong fileHandle,jint jimagetype, jdouble jscale,jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }
        string type = "PNG";
        if ( jimagetype == 0 ) {
            type = "PNG";
        } else if ( jimagetype == 1 ) {
            type = "JPG";
        } else if ( jimagetype == 2 ) {
            type = "SVG";
        }

        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        char * stroutDatalen = NULL;

        bool isTF = pdf_toImage(handle,type.c_str(),jscale,&outData,&outDatalen,&stroutDatalen);

        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,(unsigned char *)stroutDatalen,(int)(strlen(stroutDatalen)),NULL,0);
        } else {
            nError = JNI_OFD_2_IMAGE_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        if ( stroutDatalen != NULL ) {
            FZZFreeHandle(stroutDatalen);
            stroutDatalen = NULL;
        }
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_pdf2ImageToZip_1Handle
  (JNIEnv * env, jobject obj, jlong fileHandle,jint jimagetype,jdouble jscale, jobject retdata)
{
    int nError = JNI_SUCCESS;
 

    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }

        string type = "PNG";
        if ( jimagetype == 0 ) {
            type = "PNG";
        } else if ( jimagetype == 1 ) {
            type = "JPG";
        } else if ( jimagetype == 2 ) {
            type = "SVG";
        }

        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        bool isTF = pdf_toImageZip(handle,type.c_str(),jscale,&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_OFD_2_IMAGE_FAIL;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

}
//-----------------------------------------------------------------------------------------------------------------
//1: true 0: false
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_pdf2OFD_1Handle
  (JNIEnv * env, jobject obj, jlong fileHandle,jint isNoStamp, jobject retdata)
{
    int nError = JNI_SUCCESS;
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }
        
        //DLOG("ofd Datalen = %d",jSourceLen);
        bool isTF = pdfToOfd(handle,isNoStamp == 1?true:false,&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( isTF ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = JNI_OFD_2_IMAGE_FAIL;
        }

        

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( outData != NULL ) {
        FZZFreeHandle(outData);
        outData = NULL;
    }
        
    
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDFStamp handle*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFSignStamp_1Pos_1Handle
(JNIEnv * env, jobject obj, jlong fileHandle,jbyteArray imageData,jdouble alpha,jint pageIndex,jdouble x,jdouble y,jdouble stampwidth,jdouble stampheight,jobject signCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbstampData = NULL;

    //DLOG("PDFSignStamp_1Pos....begin");
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }
        
        jsize jstampDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, imageData, &pjbstampData, &jstampDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = signCallBack;
        
        int iret = pdf_positionSign(handle,(unsigned char *)pjbstampData, jstampDataLen,alpha,pageIndex,x,y,stampwidth,stampheight,CB_Sign,CB_getCert,(void *)(&param),&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbstampData != NULL ) {
        free(pjbstampData);
        pjbstampData = NULL;
    }
    
    //DLOG("PDFSignStamp_1Pos....end");
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFSignStamp_1Riding_1Handle
(JNIEnv * env, jobject obj, jlong fileHandle,jbyteArray imageData,jdouble alpha,jint RidingType,jdouble stampwidth,jdouble stampheight,jobject signCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbstampData = NULL;
    
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }
        
        jsize jstampDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, imageData, &pjbstampData, &jstampDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = signCallBack;
        
        int iret = pdf_ridingSign(handle,(unsigned char *)pjbstampData, jstampDataLen,alpha,RidingType,stampwidth,stampheight,CB_Sign,CB_getCert,(void *)(&param),&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbstampData != NULL ) {
        free(pjbstampData);
        pjbstampData = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFSignStamp_1KeyWord_1Handle
(JNIEnv * env, jobject obj, jlong fileHandle,jbyteArray imageData,jdouble alpha,jbyteArray keyword,jbyteArray KeywordRule,jdouble stampwidth,jdouble stampheight,jobject signCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbstampData = NULL;
    jbyte* pjbkeywordData = NULL;
    jbyte* pjbKeywordRuleData = NULL;
    
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }
        jsize jstampDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, imageData, &pjbstampData, &jstampDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jkeywordDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, keyword, &pjbkeywordData, &jkeywordDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jKeywordRuleDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, KeywordRule, &pjbKeywordRuleData, &jKeywordRuleDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_keyword;
        b_keyword.setMaxLen(jkeywordDataLen+3);
        b_keyword.setData_NotMalloc((unsigned char *)pjbkeywordData, jkeywordDataLen);
        
        FZZBytes b_KeywordRule;
        b_KeywordRule.setMaxLen(jKeywordRuleDataLen+3);
        b_KeywordRule.setData_NotMalloc((unsigned char *)pjbKeywordRuleData, jKeywordRuleDataLen);
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = signCallBack;
        
        int iret = pdf_keywordSign(handle,(unsigned char *)pjbstampData, jstampDataLen,alpha,(char *)b_keyword.getData(),(char *)b_KeywordRule.getData(),stampwidth,stampheight,CB_Sign,CB_getCert,(void *)(&param),&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbstampData != NULL ) {
        free(pjbstampData);
        pjbstampData = NULL;
    }
    
    if ( pjbkeywordData != NULL ) {
        free(pjbkeywordData);
        pjbkeywordData = NULL;
    }
    
    if ( pjbKeywordRuleData != NULL ) {
        free(pjbKeywordRuleData);
        pjbKeywordRuleData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFClearStamps
(JNIEnv * env, jobject obj, jlong fileHandle, jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        HANDLE handle = reinterpret_cast<HANDLE>(fileHandle);
        if (handle == NULL)
        {
            nError = ERR_PDF_LOAD;
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
        
        int iret = pdf_clearSigns(handle,&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }
        
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************************Watermark image*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_CreateWaterMark
(JNIEnv * env, jobject obj, jboolean isTile,jboolean isImage,jdouble pageWidth,jdouble pageHeight,jdouble beginPosX,jdouble beginPosY,jbyteArray imageData,jint textAlign,jdouble horizontalSpacing,jdouble verticalSpacing,
 jbyteArray firstLineText,jbyteArray firstLineText_FontName,jdouble firstLineText_fontSize,jboolean isBlob_first,jboolean isItalic_first,jdouble firstLineText_color_R,
 jdouble firstLineText_color_G,jdouble firstLineText_color_B,jdouble firstLineText_alpha,
 
 jbyteArray secondLineText,jbyteArray secondLineText_FontName,jdouble secondLineText_fontSize,jboolean isBlob_second,jboolean isItalic_second,jdouble secondLineText_color_R,
 jdouble secondLineText_color_G,jdouble secondLineText_color_B,jdouble secondLineText_alpha,
 
 jbyteArray thirdLineText,jbyteArray thirdLineText_FontName,jdouble thirdLineText_fontSize,jboolean isBlob_third,jboolean isItalic_third,jdouble thirdLineText_color_R,
 jdouble thirdLineText_color_G,jdouble thirdLineText_color_B,jdouble thirdLineText_alpha,
 jdouble lineSpacing0_1,jdouble lineSpacing1_2,jdouble rotate,jdouble scaled, jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbfirstLineText = NULL;
    jbyte* pjbfirstLineText_FontName = NULL;
    jbyte* pjbsecondLineText = NULL;
    jbyte* pjbsecondLineText_FontName = NULL;
    jbyte* pjbthirdLineText = NULL;
    jbyte* pjbthirdLineText_FontName = NULL;
    
    jbyte* pjbImageData = NULL;
    
    do {
        jsize jfirstLineTextLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, firstLineText, &pjbfirstLineText, &jfirstLineTextLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jfirstLineText_FontNameLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, firstLineText_FontName, &pjbfirstLineText_FontName, &jfirstLineText_FontNameLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jsecondLineTextLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, secondLineText, &pjbsecondLineText, &jsecondLineTextLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jsecondLineText_FontNameLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, secondLineText_FontName, &pjbsecondLineText_FontName, &jsecondLineText_FontNameLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jthirdLineTextLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, thirdLineText, &pjbthirdLineText, &jthirdLineTextLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jthirdLineText_FontNameLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, thirdLineText_FontName, &pjbthirdLineText_FontName, &jthirdLineText_FontNameLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        jsize jimageDataLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, imageData, &pjbImageData, &jimageDataLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_firstLineText;
        b_firstLineText.setMaxLen(jfirstLineTextLen+3);
        b_firstLineText.setData_NotMalloc((unsigned char *)pjbfirstLineText, jfirstLineTextLen);
        
        FZZBytes b_firstLineText_FontName;
        b_firstLineText_FontName.setMaxLen(jfirstLineText_FontNameLen+3);
        b_firstLineText_FontName.setData_NotMalloc((unsigned char *)pjbfirstLineText_FontName, jfirstLineText_FontNameLen);
        
        FZZBytes b_secondLineText;
        b_secondLineText.setMaxLen(jsecondLineTextLen+3);
        b_secondLineText.setData_NotMalloc((unsigned char *)pjbsecondLineText, jsecondLineTextLen);
        
        FZZBytes b_secondLineText_FontName;
        b_secondLineText_FontName.setMaxLen(jsecondLineText_FontNameLen+3);
        b_secondLineText_FontName.setData_NotMalloc((unsigned char *)pjbsecondLineText_FontName, jsecondLineText_FontNameLen);
        
        FZZBytes b_thirdLineText;
        b_thirdLineText.setMaxLen(jthirdLineTextLen+3);
        b_thirdLineText.setData_NotMalloc((unsigned char *)pjbthirdLineText, jthirdLineTextLen);
        
        FZZBytes b_thirdLineText_FontName;
        b_thirdLineText_FontName.setMaxLen(jthirdLineText_FontNameLen+3);
        b_thirdLineText_FontName.setData_NotMalloc((unsigned char *)pjbthirdLineText_FontName, jthirdLineText_FontNameLen);
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        double imageWidth = 0;
        double imageHeight = 0;
        
        int iret = createWaterMarkImage(isTile,isImage,pageWidth,pageHeight,beginPosX,beginPosY,(unsigned char *)pjbImageData,jimageDataLen,textAlign,horizontalSpacing,verticalSpacing,
                                          (char *)b_firstLineText.getData(),(char *)b_firstLineText_FontName.getData(),firstLineText_fontSize,isBlob_first,isItalic_first,firstLineText_color_R,
                                          firstLineText_color_G,firstLineText_color_B,firstLineText_alpha,
                                          lineSpacing0_1,
                                          (char *)b_secondLineText.getData(),(char *)b_secondLineText_FontName.getData(), secondLineText_fontSize, isBlob_second, isItalic_second, secondLineText_color_R,
                                           secondLineText_color_G, secondLineText_color_B, secondLineText_alpha,
                                           lineSpacing1_2,
                                          (char *)b_thirdLineText.getData(),(char *)b_thirdLineText_FontName.getData(), thirdLineText_fontSize, isBlob_third, isItalic_third, thirdLineText_color_R,
                                           thirdLineText_color_G, thirdLineText_color_B, thirdLineText_alpha,
                                           rotate, scaled,&outData,&outDatalen,&imageWidth,&imageHeight);
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret == 0 ) {
            string strWidth = FZZConst::fmt(imageWidth);
            string strHeight = FZZConst::fmt(imageHeight);
            
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,(unsigned char *)strWidth.c_str(),(int)strWidth.length(),(unsigned char *)strHeight.c_str(),(int)strHeight.length());
        } else {
            nError = iret;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbfirstLineText != NULL ) {
        free(pjbfirstLineText);
        pjbfirstLineText = NULL;
    }
    
    if ( pjbfirstLineText_FontName != NULL ) {
        free(pjbfirstLineText_FontName);
        pjbfirstLineText_FontName = NULL;
    }
    
    if ( pjbsecondLineText != NULL ) {
        free(pjbsecondLineText);
        pjbsecondLineText = NULL;
    }
    
    if ( pjbsecondLineText_FontName != NULL ) {
        free(pjbsecondLineText_FontName);
        pjbsecondLineText_FontName = NULL;
    }
    
    if ( pjbthirdLineText != NULL ) {
        free(pjbthirdLineText);
        pjbthirdLineText = NULL;
    }
    
    if ( pjbthirdLineText_FontName != NULL ) {
        free(pjbthirdLineText_FontName);
        pjbthirdLineText_FontName = NULL;
    }
    
    if ( pjbImageData != NULL ) {
        free(pjbImageData);
        pjbImageData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
/****************************************PDFEncrypt****************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFIsEncryptPassward
 (JNIEnv * env, jobject obj,jlong handle,jobject retdata)
{
    int nError = JNI_SUCCESS;
    
    
    do {
        HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
        if ( filehandle == NULL ) {
            nError = ERR_PDF_LOAD;
            break;
        }

        bool isTF = pdf_isNeedPassWord(filehandle);
        
        JNI_SetObject(env, obj, retdata, isTF ? JNI_SUCCESS : ERR_PDF_NOT_NEED_PW, NULL,0,NULL,0,NULL,0);
        
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFSetPassword
 (JNIEnv * env, jobject obj,jlong handle,jbyteArray password ,jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbpassword = NULL;
    
    do {
        jsize jpasswordLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, password, &pjbpassword, &jpasswordLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
        if ( filehandle == NULL ) {
            nError = ERR_PDF_LOAD;
            break;
        }
    
        FZZBytes b_password;
        b_password.setMaxLen(jpasswordLen+3);
        b_password.setData_NotMalloc((unsigned char *)pjbpassword, jpasswordLen);

        pdf_setPassWord(filehandle,(char *)b_password.getData());
        
        JNI_SetObject(env, obj, retdata, JNI_SUCCESS, NULL,0,NULL,0,NULL,0);
        
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    if ( pjbpassword != NULL ) {
        free(pjbpassword);
        pjbpassword = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_PDFEncryptDecrypt
 (JNIEnv * env, jobject obj,jlong handle,jint isEncrypt,jbyteArray password ,jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbpassword = NULL;
    do {
        HANDLE fileHandle = reinterpret_cast<HANDLE>(handle);
        if (fileHandle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }
        
        jsize jpasswordLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, password, &pjbpassword, &jpasswordLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_password;
        b_password.setMaxLen(jpasswordLen+3);
        b_password.setData_NotMalloc((unsigned char *)pjbpassword, jpasswordLen);
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;
       
        int iret = pdf_documnetEncryptDecrypt(fileHandle,isEncrypt==1?true:false,(char *)b_password.getData(),&outData,&outDatalen);
        
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
            
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbpassword != NULL ) {
        free(pjbpassword);
        pjbpassword = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************OFDProtect****************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDIsProtect
 (JNIEnv * env, jobject obj,jlong handle,jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
        if ( filehandle == NULL ) {
            nError = ERR_OFD_LOAD;
            break;
        }

        bool isTF = ofd_isProtect(filehandle);
        
        JNI_SetObject(env, obj, retdata, isTF ? JNI_SUCCESS : ERR_OFD_NOT_PROTECT, NULL,0,NULL,0,NULL,0);
        
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDProtect_1Handle
(JNIEnv * env, jobject obj,jlong handle,jobject signCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;
 

    //DLOG("PDFSignStamp_1Pos....begin");
    do {
        HANDLE fileHandle = reinterpret_cast<HANDLE>(handle);
        if (fileHandle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = signCallBack;
       
        int iret = ofd_protect(fileHandle,CB_Sign,CB_getCert,(void *)(&param),&outData,&outDatalen);
        
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
            
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDProtectionVerify_1Handle
(JNIEnv * env, jobject obj,jlong handle,jobject verifyCallBack, jobject retdata)
{
    int nError = JNI_SUCCESS;

    do {
        HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
        if ( filehandle == NULL ) {
            nError = ERR_OFD_LOAD;
            break;
        }
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = verifyCallBack;
        
        int iret = ofd_protectionVerify(filehandle,CB_Verify,(void *)(&param),&outData,&outDatalen);
        //DLOG("outDatalen = %d",outDatalen);
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
            JNI_SetObject(env, obj, retdata, nError, outData,(int)outDatalen,NULL,0,NULL,0);
            nError = JNI_SUCCESS;
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }

    
    
}
//-----------------------------------------------------------------------------------------------------------------
/****************************************OFDEncrypt****************************/
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDIsEncrypt
 (JNIEnv * env, jobject obj,jlong handle,jobject retdata)
{
    int nError = JNI_SUCCESS;
    do {
        HANDLE filehandle = reinterpret_cast<HANDLE>(handle);
        if ( filehandle == NULL ) {
            nError = ERR_OFD_LOAD;
            break;
        }

        bool isTF = ofd_isEncrypt(filehandle);
        
        JNI_SetObject(env, obj, retdata, isTF ? JNI_SUCCESS : ERR_OFD_NOT_ENCRYPT, NULL,0,NULL,0,NULL,0);
        
    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDEncryptDocument_1Handle
 (JNIEnv * env, jobject obj,jlong handle,jbyteArray userInfo,jobject encryptCallBack,jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbUserInfo = NULL;
    do {
        HANDLE fileHandle = reinterpret_cast<HANDLE>(handle);
        if (fileHandle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }
        
        jsize jUserInfoLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, userInfo, &pjbUserInfo, &jUserInfoLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_userinfo;
        b_userinfo.setMaxLen(jUserInfoLen+3);
        b_userinfo.setData_NotMalloc((unsigned char *)pjbUserInfo, jUserInfoLen);
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = encryptCallBack;
       
        int iret = ofd_encryptDocument(fileHandle,(char *)b_userinfo.getData(),CB_EncryptSM4CBC,CB_DecryptSM4CBC,CB_EncryptSM2,CB_DecryptSM2,CB_GenerateRandom,(void *)(&param),&outData,&outDatalen);
        
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
            
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbUserInfo != NULL ) {
        free(pjbUserInfo);
        pjbUserInfo = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_com_fzz_ess_jni_document_utils_JNIInterface_OFDDecryptDocument_1Handle
 (JNIEnv * env, jobject obj,jlong handle,jint mode,jbyteArray passWord,jbyteArray userName,jbyteArray userType,jobject encryptCallBack,jobject retdata)
{
    int nError = JNI_SUCCESS;
    jbyte* pjbpassWord = NULL;
    jbyte* pjbuserName = NULL;
    jbyte* pjbuserType = NULL;
    do {
        HANDLE fileHandle = reinterpret_cast<HANDLE>(handle);
        if (fileHandle == NULL)
        {
            nError = ERR_OFD_LOAD;
            break;
        }
        
        jsize jPassWordLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, passWord, &pjbpassWord, &jPassWordLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_password;
        b_password.setMaxLen(jPassWordLen+3);
        b_password.setData_NotMalloc((unsigned char *)pjbpassWord, jPassWordLen);
        
        jsize juserNameLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, userName, &pjbuserName, &juserNameLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_username;
        b_username.setMaxLen(juserNameLen+3);
        b_username.setData_NotMalloc((unsigned char *)pjbuserName, juserNameLen);
        
        jsize juserTypeLen = 0;
        nError = JNI_GetJbyteFromJbyteArray(env, userType, &pjbuserType, &juserTypeLen);
        if (nError != JNI_SUCCESS)
        {
            break;
        }
        
        FZZBytes b_userType;
        b_userType.setMaxLen(juserTypeLen+3);
        b_userType.setData_NotMalloc((unsigned char *)pjbuserType, juserTypeLen);
        
        unsigned char * outData = NULL;
        size_t outDatalen = 0;

        //DLOG("ofd Datalen = %d",jSourceLen);
        JNICALLBACKFUNC_PARAM param;
        param.env = env;
        param.CallBack_obj = encryptCallBack;
       
        int iret = ofd_decryptDocument(fileHandle,mode,(char *)b_password.getData(),(char *)b_username.getData(),(char *)b_userType.getData(),CB_EncryptSM4CBC,CB_DecryptSM4CBC,CB_EncryptSM2,CB_DecryptSM2,CB_GenerateRandom,(void *)(&param),&outData,&outDatalen);
        
        if ( iret == 0 ) {
            JNI_SetObject(env, obj, retdata, JNI_SUCCESS, outData,(int)outDatalen,NULL,0,NULL,0);
        } else {
            nError = iret;
            
        }

        if ( outData != NULL ) {
            FZZFreeHandle(outData);
            outData = NULL;
        }

    }while(false);

    if (nError != JNI_SUCCESS) {
        JNI_SetObject(env, obj, retdata, nError, NULL,0,NULL,0,NULL,0);
    }
    
    if ( pjbpassWord != NULL ) {
        free(pjbpassWord);
        pjbpassWord = NULL;
    }
    
    if ( pjbuserName != NULL ) {
        free(pjbuserName);
        pjbuserName = NULL;
    }
    
    if ( pjbuserType != NULL ) {
        free(pjbuserType);
        pjbuserType = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
