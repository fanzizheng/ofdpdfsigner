//
//  Created by zizheng fan on 2023/04/27.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2012/wordml/FZZW15DocId.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZW15DocId**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZW15DocId::FZZW15DocId() : FZZXMLElementObject()
{
    //DLOG("FZZW15DocId()");
    FZZConst::addClassCount("FZZW15DocId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15DocId::FZZW15DocId(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZW15DocId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15DocId::FZZW15DocId(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZW15DocId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15DocId::FZZW15DocId(const FZZW15DocId& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZW15DocId");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15DocId::~FZZW15DocId()
{
    //DLOG("~FZZW15DocId()");
    FZZConst::delClassCount("FZZW15DocId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZW15DocId::setVal(string value)
{
    setAttribute_String("w15:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZW15DocId::getVal()
{
    return getAttribute_String("w15:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
