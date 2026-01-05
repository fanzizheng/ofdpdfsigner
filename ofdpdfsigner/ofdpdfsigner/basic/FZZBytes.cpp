//
//  Created by zizheng fan on 2022/10/16.
//
//#include "basic/FZZConst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basic/FZZBytes.h"


//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZBytes*******************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZBytes::FZZBytes() : m_Data(NULL),m_Len(0)
{
    //DLOG("FZZBytes()");
    //FZZConst::addClassCount("FZZBytes");
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes::FZZBytes(const unsigned char * const data,size_t len) :FZZBytes()
{
    //DLOG("FZZBytes(const unsigned char * const data,size_t len)");
    setData(data,len);
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes::FZZBytes(const FZZBytes& obj) :FZZBytes()
{
    //DLOG("FZZBytes(const FZZBytes& obj)");
    if ( this == &obj ) {
        return;
    }
    this->setData(obj.m_Data,obj.m_Len);
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes::~FZZBytes()
{
    //DLOG("~FZZBytes()");
    //FZZConst::delClassCount("FZZBytes");
    clear();
}
//-----------------------------------------------------------------------------------------------------------------
const FZZBytes& FZZBytes::operator=(const FZZBytes& data)
{
//    if ( &data == NULL ) {
//        return *this;
//    }
    if ( this == &data ) {
        return *this;
    }
    
    if ( data.m_Len <= 0 ) {
        return *this;
    }
    
    if ( data.m_Data == NULL ) {
        return *this;
    }
    
    this->setData(data.m_Data,data.m_Len);
    return *this;
}

//-----------------------------------------------------------------------------------------------------------------
void FZZBytes::updataData(size_t index,unsigned char value)
{
    if ( index+1 > m_Len ) {
        return;
    }
    *(m_Data+index) = value;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZBytes::setData(const unsigned char * const data,size_t len)
{
    if ( data == NULL || len <= 0 ) {
        return false;
    }
    //clear();
    m_Len = len;
    m_Data = (unsigned char *)realloc(m_Data,len);
    if ( m_Data == NULL ) {
        m_Len = 0;
        return false;
    }
    //memset(m_Data,0x00,len);
    memcpy(m_Data,data,len);
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZBytes::setData_NotMalloc(const unsigned char * const data,size_t len)
{
    if ( data == NULL || len <= 0 || m_Len < len ) {
        return false;
    }
    m_Len = len;
    //memset(m_Data,0x00,len);
    memcpy(m_Data,data,len);
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZBytes::setMaxLen(size_t bufferlen)
{
    if ( bufferlen <= 0 ) {
        return false;
    }
    //clear();
    m_Len = bufferlen;
    m_Data = (unsigned char *)realloc(m_Data,bufferlen);
    if ( m_Data == NULL ) {
        m_Len = 0;
        return false;
    }
    memset(m_Data,0x00,bufferlen);
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZBytes::addData(const unsigned char * const data,size_t len)
{
    if ( data == NULL || len <= 0 ) {
        return false;
    }
    unsigned char * tempdata = (unsigned char *)realloc(m_Data, m_Len + len);
    if ( tempdata == NULL ) {
        return false;
    }
    memcpy(tempdata+m_Len,data,len);
    m_Len = m_Len + len;
    m_Data = tempdata;
    return true;
//    if ( m_Data == NULL ) {
//        return setData(data,len);
//    } else {
//        unsigned char * tempdata = (unsigned char *)malloc(m_Len + len);
//        if ( tempdata == NULL ) {
//            return false;
//        }
//        memset(tempdata,0x00,m_Len + len);
//        memcpy(tempdata,m_Data,m_Len);
//        memcpy(tempdata+m_Len,data,len);
//        if ( m_Data != NULL ) {
//            free(m_Data);
//            m_Data = NULL;
//        }
//        m_Len = m_Len + len;
//        m_Data = tempdata;
//        return true;
//    }
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZBytes::addData(const FZZBytes & data)
{
    return addData(data.getData(),data.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZBytes::clear()
{
    if ( m_Data != NULL ) {
        free(m_Data);
        m_Data = NULL;
    }
    m_Len = 0;
}
//-----------------------------------------------------------------------------------------------------------------


