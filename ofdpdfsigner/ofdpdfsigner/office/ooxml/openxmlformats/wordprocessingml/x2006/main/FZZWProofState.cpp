//
//  Created by zizheng fan on 2023/09/27
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWProofState.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWProofState**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWProofState::FZZWProofState() : FZZXMLElementObject()
{
    //DLOG("FZZWProofState()");
    FZZConst::addClassCount("FZZWProofState");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWProofState::FZZWProofState(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWProofState");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWProofState::FZZWProofState(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWProofState");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWProofState::FZZWProofState(const FZZWProofState& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWProofState");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWProofState::~FZZWProofState()
{
    //DLOG("~FZZWProofState()");
    FZZConst::delClassCount("FZZWProofState");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWProofState::setSpelling(string value)
{
    setAttribute_String("w:spelling",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWProofState::getSpelling()
{
    return getAttribute_String("w:spelling");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWProofState::setGrammar(string value)
{
    setAttribute_String("w:grammar",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWProofState::getGrammar()
{
    return getAttribute_String("w:grammar");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
