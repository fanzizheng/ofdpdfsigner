//
//  Created by zizheng fan on 2023/09/26
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRsid.h"
#include "office/FZZOfficeObject.h"

unsigned int FZZWRsid::g_CurrRsid = 0;
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWRsid**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWRsid::FZZWRsid() : FZZXMLElementObject()
{
    //DLOG("FZZWRsid()");
    FZZConst::addClassCount("FZZWRsid");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsid::FZZWRsid(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWRsid");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsid::FZZWRsid(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWRsid");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsid::FZZWRsid(const FZZWRsid& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWRsid");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsid::~FZZWRsid()
{
    //DLOG("~FZZWRsid()");
    FZZConst::delClassCount("FZZWRsid");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRsid::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRsid::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRsid::ToString(unsigned int data)
{
    char buffer[10] = { 0 };
    sprintf(buffer, "%08X", data);
    string ret = buffer;
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
unsigned int FZZWRsid::ToUInt(string data)
{
    unsigned int ret = (unsigned int)strtol(data.c_str(), NULL, 16);
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
unsigned int FZZWRsid::GetCurrRsid()
{
    return g_CurrRsid;
}
//-----------------------------------------------------------------------------------------------------------------
unsigned int FZZWRsid::GetCurrRsid_Next()
{
    return g_CurrRsid = g_CurrRsid + 10;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRsid::GetCurrRsid_String()
{
    return ToString(GetCurrRsid());
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRsid::GetCurrRsid_Next_String()
{
    return ToString(GetCurrRsid_Next());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRsid::SetCurrRsid(string rsid)
{
    g_CurrRsid = ToUInt(rsid);
}
//-----------------------------------------------------------------------------------------------------------------
