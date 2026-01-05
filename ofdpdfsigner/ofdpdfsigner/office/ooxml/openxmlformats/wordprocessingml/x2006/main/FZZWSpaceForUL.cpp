//
//  Created by zizheng fan on 2023/09/20
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSpaceForUL.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSpaceForUL**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWSpaceForUL::FZZWSpaceForUL() : FZZXMLElementObject()
{
    //DLOG("FZZWSpaceForUL()");
    FZZConst::addClassCount("FZZWSpaceForUL");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpaceForUL::FZZWSpaceForUL(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWSpaceForUL");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpaceForUL::FZZWSpaceForUL(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWSpaceForUL");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpaceForUL::FZZWSpaceForUL(const FZZWSpaceForUL& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWSpaceForUL");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpaceForUL::~FZZWSpaceForUL()
{
    //DLOG("~FZZWSpaceForUL()");
    FZZConst::delClassCount("FZZWSpaceForUL");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
