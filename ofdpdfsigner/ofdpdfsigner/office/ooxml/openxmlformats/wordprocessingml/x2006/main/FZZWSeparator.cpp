//
//  Created by zizheng fan on 2023/11/08
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSeparator.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSeparator**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSeparator::FZZWSeparator() : FZZXMLElementObject()
{
    //DLOG("FZZWSeparator()");
    FZZConst::addClassCount("FZZWSeparator");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSeparator::FZZWSeparator(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSeparator");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSeparator::FZZWSeparator(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWSeparator");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSeparator::FZZWSeparator(const FZZWSeparator& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSeparator");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSeparator::~FZZWSeparator()
{
    //DLOG("~FZZWSeparator()");
    FZZConst::delClassCount("FZZWSeparator");
}
//-----------------------------------------------------------------------------------------------------------------

