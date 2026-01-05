//
//  Created by zizheng fan on 2023/09/07
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFamily.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWFamily**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWFamily::FZZWFamily() : FZZXMLElementObject()
{
    //DLOG("FZZWFamily()");
    FZZConst::addClassCount("FZZWFamily");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFamily::FZZWFamily(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWFamily");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFamily::FZZWFamily(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWFamily");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFamily::FZZWFamily(const FZZWFamily& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWFamily");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWFamily::~FZZWFamily()
{
    //DLOG("~FZZWFamily()");
    FZZConst::delClassCount("FZZWFamily");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWFamily::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWFamily::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
