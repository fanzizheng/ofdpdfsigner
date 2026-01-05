//
//  Created by zizheng fan on 2023/11/01
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNoProof.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWNoProof**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWNoProof::FZZWNoProof() : FZZXMLElementObject()
{
    //DLOG("FZZWNoProof()");
    FZZConst::addClassCount("FZZWNoProof");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNoProof::FZZWNoProof(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWNoProof");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNoProof::FZZWNoProof(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWNoProof");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNoProof::FZZWNoProof(const FZZWNoProof& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWNoProof");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWNoProof::~FZZWNoProof()
{
    //DLOG("~FZZWNoProof()");
    FZZConst::delClassCount("FZZWNoProof");
    
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
void FZZWNoProof::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWNoProof::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

