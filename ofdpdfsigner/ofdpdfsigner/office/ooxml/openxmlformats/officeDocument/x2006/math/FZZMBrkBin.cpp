//
//  Created by zizheng fan on 2023/05/16.
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMBrkBin.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMBrkBin**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBin::FZZMBrkBin() : FZZXMLElementObject()
{
    //DLOG("FZZMBrkBin()");
    FZZConst::addClassCount("FZZMBrkBin");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBin::FZZMBrkBin(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMBrkBin");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBin::FZZMBrkBin(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMBrkBin");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBin::FZZMBrkBin(const FZZMBrkBin& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMBrkBin");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMBrkBin::~FZZMBrkBin()
{
    //DLOG("~FZZMBrkBin()");
    FZZConst::delClassCount("FZZMBrkBin");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMBrkBin::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMBrkBin::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
