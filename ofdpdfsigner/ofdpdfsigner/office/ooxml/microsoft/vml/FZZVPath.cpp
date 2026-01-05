//
//  Created by zizheng fan on 2023/04/19.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVPath.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVPath**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVPath::FZZVPath() : FZZXMLElementObject()
{
    //DLOG("FZZVPath()");
    FZZConst::addClassCount("FZZVPath");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVPath::FZZVPath(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVPath");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVPath::FZZVPath(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZVPath");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVPath::FZZVPath(const FZZVPath& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVPath");
    if ( this == &obj ) {
        return;
    }
    //m_FZZWPPr = obj.m_FZZWPPr != NULL ? new FZZWPPr(*obj.m_FZZWPPr) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVPath::~FZZVPath()
{
    //DLOG("~FZZVPath()");
    FZZConst::delClassCount("FZZVPath");
//    if ( m_FZZWPPr != NULL ) {
//        delete m_FZZWPPr;
//        m_FZZWPPr = NULL;
//    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVPath::setArrowok(string value)
{
    setAttribute_String("arrowok",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVPath::getArrowok()
{
    return getAttribute_String("arrowok");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVPath::setExtrusionok(string value)
{
    setAttribute_String("o:extrusionok",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVPath::getExtrusionok()
{
    return getAttribute_String("o:extrusionok");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVPath::setGradientshapeok(string value)
{
    setAttribute_String("gradientshapeok",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVPath::getGradientshapeok()
{
    return getAttribute_String("gradientshapeok");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVPath::setConnecttype(string value)
{
    setAttribute_String("o:connecttype",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVPath::getConnecttype()
{
    return getAttribute_String("o:connecttype");
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZVPath::setWeight(string value)
//{
//    setAttribute_String("weight",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZVPath::getWeight()
//{
//    return getAttribute_String("weight");
//}
////-----------------------------------------------------------------------------------------------------------------
//void FZZVPath::setEndarrow(string value)
//{
//    setAttribute_String("endarrow",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZVPath::getEndarrow()
//{
//    return getAttribute_String("endarrow");
//}
////-----------------------------------------------------------------------------------------------------------------
