//
//  Created by zizheng fan on 2023/09/18
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUseFELayout.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWUseFELayout**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWUseFELayout::FZZWUseFELayout() : FZZXMLElementObject()
{
    //DLOG("FZZWUseFELayout()");
    FZZConst::addClassCount("FZZWUseFELayout");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUseFELayout::FZZWUseFELayout(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWUseFELayout");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUseFELayout::FZZWUseFELayout(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWUseFELayout");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUseFELayout::FZZWUseFELayout(const FZZWUseFELayout& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWUseFELayout");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUseFELayout::~FZZWUseFELayout()
{
    //DLOG("~FZZWUseFELayout()");
    FZZConst::delClassCount("FZZWUseFELayout");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
