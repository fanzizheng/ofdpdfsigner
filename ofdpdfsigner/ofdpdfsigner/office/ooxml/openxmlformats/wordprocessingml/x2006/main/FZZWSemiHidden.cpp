//
//  Created by zizheng fan on 2023/10/24
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSemiHidden.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSemiHidden**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSemiHidden::FZZWSemiHidden() : FZZXMLElementObject()
{
    //DLOG("FZZWSemiHidden()");
    FZZConst::addClassCount("FZZWSemiHidden");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSemiHidden::FZZWSemiHidden(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSemiHidden");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSemiHidden::FZZWSemiHidden(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWSemiHidden");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSemiHidden::FZZWSemiHidden(const FZZWSemiHidden& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSemiHidden");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSemiHidden::~FZZWSemiHidden()
{
    //DLOG("~FZZWSemiHidden()");
    FZZConst::delClassCount("FZZWSemiHidden");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSemiHidden::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSemiHidden::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
