//
//  FZZString.cpp
//  ofdcreate
//
//  Created by zizheng fan on 2022/1/18.
//

#include "basic/FZZConst.h"
#include "basic/FZZStringItem.h"

//--------------------------------------------------------------------------------------------------------
/*****************************************************FZZString****************************************************/
//--------------------------------------------------------------------------------------------------------
FZZStringItem::FZZStringItem() : m_data(""),m_dataindex(-1),m_index(-1)
{
    //FZZConst::addClassCount("FZZStringItem");
    //DLOG("FZZStringItem()");
}
//--------------------------------------------------------------------------------------------------------
FZZStringItem::FZZStringItem(const string& data,int dataindex,int index) :FZZStringItem()
{
    this->m_data = data;
    this->m_dataindex = dataindex;
    this->m_index = index;

    //DLOG("FZZStringItem(const string& data,int dataindex,int index)");
}
//--------------------------------------------------------------------------------------------------------
FZZStringItem::FZZStringItem(const FZZStringItem& obj) :FZZStringItem()
{
    //DLOG("FZZStringItem(const FZZStringItem& obj)");
    if ( this == &obj ) {
        return;
    }
    this->m_data = obj.m_data;
    this->m_dataindex = obj.m_dataindex;
    this->m_index = obj.m_index;
    
}
//--------------------------------------------------------------------------------------------------------
const FZZStringItem& FZZStringItem::operator=(const FZZStringItem& data)
{
   // DLOG("FZZStringItem::operator=");
    if ( this == &data ) {
        return *this;
    }
    this->m_data = data.m_data;
    this->m_dataindex = data.m_dataindex;
    this->m_index = data.m_index;
    return *this;
}
//--------------------------------------------------------------------------------------------------------

FZZStringItem::~FZZStringItem()
{
    //FZZConst::delClassCount("FZZStringItem");
    //DLOG("~FZZStringItem()");
    m_data = "";
    m_dataindex = -1;
    m_index = -1;
}
//--------------------------------------------------------------------------------------------------------




