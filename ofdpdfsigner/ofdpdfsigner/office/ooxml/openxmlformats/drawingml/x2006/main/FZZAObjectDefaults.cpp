//
//  Created by zizheng fan on 2023/08/29
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAObjectDefaults.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAObjectDefaults**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAObjectDefaults::FZZAObjectDefaults() : FZZXMLElementObject()
{
    //DLOG("FZZAObjectDefaults()");
    FZZConst::addClassCount("FZZAObjectDefaults");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAObjectDefaults::FZZAObjectDefaults(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAObjectDefaults");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAObjectDefaults::FZZAObjectDefaults(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAObjectDefaults");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAObjectDefaults::FZZAObjectDefaults(const FZZAObjectDefaults& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAObjectDefaults");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAObjectDefaults::~FZZAObjectDefaults()
{
    //DLOG("~FZZAObjectDefaults()");
    FZZConst::delClassCount("FZZAObjectDefaults");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
