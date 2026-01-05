//
//  Created by zizheng fan on 2023/07/18
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAalpha.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAalpha**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAalpha::FZZAalpha() : FZZXMLElementObject()
{
    //DLOG("FZZAalpha()");
    FZZConst::addClassCount("FZZAalpha");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAalpha::FZZAalpha(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAalpha");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAalpha::FZZAalpha(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAalpha");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAalpha::FZZAalpha(const FZZAalpha& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAalpha");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAalpha::~FZZAalpha()
{
    //DLOG("~FZZAalpha()");
    FZZConst::delClassCount("FZZAalpha");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAalpha::setVal(string value)
{
    setAttribute_String("val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAalpha::getVal()
{
    return getAttribute_String("val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
