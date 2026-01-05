//
//  Created by zizheng fan on 2023/05/26
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMRMargin.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMRMargin**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMRMargin::FZZMRMargin() : FZZXMLElementObject()
{
    //DLOG("FZZMRMargin()");
    FZZConst::addClassCount("FZZMRMargin");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMRMargin::FZZMRMargin(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMRMargin");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMRMargin::FZZMRMargin(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMRMargin");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMRMargin::FZZMRMargin(const FZZMRMargin& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMRMargin");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMRMargin::~FZZMRMargin()
{
    //DLOG("~FZZMRMargin()");
    FZZConst::delClassCount("FZZMRMargin");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMRMargin::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMRMargin::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
