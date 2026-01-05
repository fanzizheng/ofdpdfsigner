//
//  Created by zizheng fan on 2023/04/19.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVImageData.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVImageData**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData::FZZVImageData() : FZZXMLElementObject()
{
    //DLOG("FZZVImageData()");
    FZZConst::addClassCount("FZZVImageData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData::FZZVImageData(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVImageData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData::FZZVImageData(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZVImageData");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData::FZZVImageData(const FZZVImageData& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVImageData");
    if ( this == &obj ) {
        return;
    }
    //m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData::~FZZVImageData()
{
    //DLOG("~FZZVImageData()");
    FZZConst::delClassCount("FZZVImageData");
//    if ( m_FZZWPPr != NULL ) {
//        delete m_FZZWPPr;
//        m_FZZWPPr = NULL;
//    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVImageData::setRID(string value)
{
    setAttribute_String("r:id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVImageData::getRID()
{
    return getAttribute_String("r:id");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVImageData::setTitle(string value)
{
    setAttribute_String("o:title",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVImageData::getTitle()
{
    return getAttribute_String("o:title");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVImageData::setGain(string value)
{
    setAttribute_String("gain",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVImageData::getGain()
{
    return getAttribute_String("gain");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVImageData::setBlacklevel(string value)
{
    setAttribute_String("blacklevel",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVImageData::getBlacklevel()
{
    return getAttribute_String("blacklevel");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVImageData::setGamma(string value)
{
    setAttribute_String("gamma",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVImageData::getGamma()
{
    return getAttribute_String("gamma");
}
//-----------------------------------------------------------------------------------------------------------------
