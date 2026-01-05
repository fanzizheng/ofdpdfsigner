//
//  Created by zizheng fan on 2023/11/01
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVertAlign.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWVertAlign**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWVertAlign::FZZWVertAlign() : FZZXMLElementObject()
{
    //DLOG("FZZWVertAlign()");
    FZZConst::addClassCount("FZZWVertAlign");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVertAlign::FZZWVertAlign(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWVertAlign");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVertAlign::FZZWVertAlign(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWVertAlign");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVertAlign::FZZWVertAlign(const FZZWVertAlign& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWVertAlign");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVertAlign::~FZZWVertAlign()
{
    //DLOG("~FZZWVertAlign()");
    FZZConst::delClassCount("FZZWVertAlign");
    
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
void FZZWVertAlign::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWVertAlign::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

