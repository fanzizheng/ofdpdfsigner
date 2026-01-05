//
//  Created by zizheng fan on 2023/09/11
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWZoom.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWZoom**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWZoom::FZZWZoom() : FZZXMLElementObject()
{
    //DLOG("FZZWZoom()");
    FZZConst::addClassCount("FZZWZoom");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWZoom::FZZWZoom(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWZoom");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWZoom::FZZWZoom(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWZoom");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWZoom::FZZWZoom(const FZZWZoom& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWZoom");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWZoom::~FZZWZoom()
{
    //DLOG("~FZZWZoom()");
    FZZConst::delClassCount("FZZWZoom");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWZoom::setPercent(string value)
{
    setAttribute_String("w:percent",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWZoom::getPercent()
{
    return getAttribute_String("w:percent");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
