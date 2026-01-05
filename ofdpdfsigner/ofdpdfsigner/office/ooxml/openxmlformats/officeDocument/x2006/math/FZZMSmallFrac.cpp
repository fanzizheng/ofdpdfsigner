//
//  Created by zizheng fan on 2023/05/29
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMSmallFrac.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMSmallFrac**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMSmallFrac::FZZMSmallFrac() : FZZXMLElementObject()
{
    //DLOG("FZZMSmallFrac()");
    FZZConst::addClassCount("FZZMSmallFrac");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMSmallFrac::FZZMSmallFrac(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMSmallFrac");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMSmallFrac::FZZMSmallFrac(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMSmallFrac");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMSmallFrac::FZZMSmallFrac(const FZZMSmallFrac& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMSmallFrac");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMSmallFrac::~FZZMSmallFrac()
{
    //DLOG("~FZZMSmallFrac()");
    FZZConst::delClassCount("FZZMSmallFrac");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMSmallFrac::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMSmallFrac::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
