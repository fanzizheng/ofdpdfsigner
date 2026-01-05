//
//  Created by zizheng fan on 2023/10/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSzCS.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSzCS**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSzCS::FZZWSzCS() : FZZXMLElementObject()
{
    //DLOG("FZZWSzCS()");
    FZZConst::addClassCount("FZZWSzCS");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSzCS::FZZWSzCS(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSzCS");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSzCS::FZZWSzCS(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWSzCS");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSzCS::FZZWSzCS(const FZZWSzCS& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSzCS");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSzCS::~FZZWSzCS()
{
    //DLOG("~FZZWSzCS()");
    FZZConst::delClassCount("FZZWSzCS");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWSzCS::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWSzCS::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
