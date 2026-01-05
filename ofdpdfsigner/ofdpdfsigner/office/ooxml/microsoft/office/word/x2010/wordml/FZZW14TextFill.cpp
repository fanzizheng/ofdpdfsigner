//
//  Created by zizheng fan on 2023/05/09.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2010/wordml/FZZW14TextFill.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZW14TextFill**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZW14TextFill::FZZW14TextFill() : FZZXMLElementObject(),m_FZZW14SolidFill(NULL)
{
    //DLOG("FZZW14TextFill()");
    FZZConst::addClassCount("FZZW14TextFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14TextFill::FZZW14TextFill(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZW14SolidFill(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZW14TextFill");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14TextFill::FZZW14TextFill(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZW14SolidFill(NULL)
{
    FZZConst::addClassCount("FZZW14TextFill");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14TextFill::FZZW14TextFill(const FZZW14TextFill& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZW14TextFill");
    if ( this == &obj ) {
        return;
    }
    m_FZZW14SolidFill = obj.m_FZZW14SolidFill != NULL ? new FZZW14SolidFill(*obj.m_FZZW14SolidFill) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14TextFill::~FZZW14TextFill()
{
    //DLOG("~FZZW14TextFill()");
    FZZConst::delClassCount("FZZW14TextFill");
    if ( m_FZZW14SolidFill != NULL ) {
        delete m_FZZW14SolidFill;
        m_FZZW14SolidFill = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZW14TextFill::setVal(string value)
{
    setAttribute_String("w14:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZW14TextFill::getVal()
{
    return getAttribute_String("w14:val");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SolidFill * FZZW14TextFill::setSolidFill()
{
    return m_FZZW14SolidFill = setElementObject(m_FZZW14SolidFill,FZZW14SOLIDFILL_Find_Key,FZZW14SOLIDFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14SolidFill * FZZW14TextFill::getSolidFill()
{
    return m_FZZW14SolidFill = getElementObject(m_FZZW14SolidFill,FZZW14SOLIDFILL_Find_Key,FZZW14SOLIDFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
