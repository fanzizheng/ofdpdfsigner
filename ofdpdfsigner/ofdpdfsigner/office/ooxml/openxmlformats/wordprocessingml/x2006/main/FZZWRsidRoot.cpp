//
//  Created by zizheng fan on 2023/09/26
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRsidRoot.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWRsidRoot**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWRsidRoot::FZZWRsidRoot() : FZZXMLElementObject()
{
    //DLOG("FZZWRsidRoot()");
    FZZConst::addClassCount("FZZWRsidRoot");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsidRoot::FZZWRsidRoot(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWRsidRoot");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsidRoot::FZZWRsidRoot(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWRsidRoot");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsidRoot::FZZWRsidRoot(const FZZWRsidRoot& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWRsidRoot");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWRsidRoot::~FZZWRsidRoot()
{
    //DLOG("~FZZWRsidRoot()");
    FZZConst::delClassCount("FZZWRsidRoot");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWRsidRoot::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWRsidRoot::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
