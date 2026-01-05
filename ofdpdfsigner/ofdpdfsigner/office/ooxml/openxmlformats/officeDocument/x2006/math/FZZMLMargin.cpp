//
//  Created by zizheng fan on 2023/05/22
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMLMargin.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMLMargin**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMLMargin::FZZMLMargin() : FZZXMLElementObject()
{
    //DLOG("FZZMLMargin()");
    FZZConst::addClassCount("FZZMLMargin");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMLMargin::FZZMLMargin(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMLMargin");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMLMargin::FZZMLMargin(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMLMargin");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMLMargin::FZZMLMargin(const FZZMLMargin& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMLMargin");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMLMargin::~FZZMLMargin()
{
    //DLOG("~FZZMLMargin()");
    FZZConst::delClassCount("FZZMLMargin");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMLMargin::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMLMargin::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
