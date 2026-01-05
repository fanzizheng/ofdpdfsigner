//
//  Created by zizheng fan on 2023/05/10.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2010/wordml/FZZW14DocId.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZW14DocId**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZW14DocId::FZZW14DocId() : FZZXMLElementObject()
{
    //DLOG("FZZW14DocId()");
    FZZConst::addClassCount("FZZW14DocId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14DocId::FZZW14DocId(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZW14DocId");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14DocId::FZZW14DocId(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZW14DocId");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14DocId::FZZW14DocId(const FZZW14DocId& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZW14DocId");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14DocId::~FZZW14DocId()
{
    //DLOG("~FZZW14DocId()");
    FZZConst::delClassCount("FZZW14DocId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZW14DocId::setVal(string value)
{
    setAttribute_String("w14:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZW14DocId::getVal()
{
    return getAttribute_String("w14:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
