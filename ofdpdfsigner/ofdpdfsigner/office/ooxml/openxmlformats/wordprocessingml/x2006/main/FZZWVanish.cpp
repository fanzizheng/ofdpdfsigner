//
//  Created by zizheng fan on 2023/11/27
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVanish.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWVanish**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWVanish::FZZWVanish() : FZZXMLElementObject()
{
    //DLOG("FZZWVanish()");
    FZZConst::addClassCount("FZZWVanish");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVanish::FZZWVanish(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWVanish");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVanish::FZZWVanish(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWVanish");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVanish::FZZWVanish(const FZZWVanish& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWVanish");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWVanish::~FZZWVanish()
{
    //DLOG("~FZZWVanish()");
    FZZConst::delClassCount("FZZWVanish");
}
//-----------------------------------------------------------------------------------------------------------------

