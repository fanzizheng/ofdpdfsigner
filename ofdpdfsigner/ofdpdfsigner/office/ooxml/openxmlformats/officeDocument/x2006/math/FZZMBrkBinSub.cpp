//
//  Created by zizheng fan on 2023/05/16.
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMBrkBinSub.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMBrkBinSub**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBinSub::FZZMBrkBinSub() : FZZXMLElementObject()
{
    //DLOG("FZZMBrkBinSub()");
    FZZConst::addClassCount("FZZMBrkBinSub");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBinSub::FZZMBrkBinSub(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMBrkBinSub");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBinSub::FZZMBrkBinSub(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMBrkBinSub");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBinSub::FZZMBrkBinSub(const FZZMBrkBinSub& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMBrkBinSub");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBinSub::~FZZMBrkBinSub()
{
    //DLOG("~FZZMBrkBinSub()");
    FZZConst::delClassCount("FZZMBrkBinSub");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMBrkBinSub::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMBrkBinSub::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
