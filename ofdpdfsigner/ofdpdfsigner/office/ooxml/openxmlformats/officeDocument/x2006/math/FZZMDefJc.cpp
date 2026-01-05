//
//  Created by zizheng fan on 2023/05/17.
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMDefJc.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMDefJc**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMDefJc::FZZMDefJc() : FZZXMLElementObject()
{
    //DLOG("FZZWRsidRoot()");
    FZZConst::addClassCount("FZZMDefJc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDefJc::FZZMDefJc(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMDefJc");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDefJc::FZZMDefJc(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMDefJc");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDefJc::FZZMDefJc(const FZZMDefJc& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMDefJc");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMDefJc::~FZZMDefJc()
{
    //DLOG("~FZZMDefJc()");
    FZZConst::delClassCount("FZZMDefJc");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMDefJc::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMDefJc::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
