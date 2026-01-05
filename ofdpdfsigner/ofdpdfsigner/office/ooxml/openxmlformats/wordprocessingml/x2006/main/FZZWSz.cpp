//
//  Created by zizheng fan on 2023/10/08
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSz.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSz**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSz::FZZWSz() : FZZXMLElementObject()
{
    //DLOG("FZZWSz()");
    FZZConst::addClassCount("FZZWSz");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSz::FZZWSz(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSz");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSz::FZZWSz(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWSz");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSz::FZZWSz(const FZZWSz& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSz");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSz::~FZZWSz()
{
    //DLOG("~FZZWSz()");
    FZZConst::delClassCount("FZZWSz");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSz::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSz::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
