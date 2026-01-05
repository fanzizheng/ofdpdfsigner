//
//  Created by zizheng fan on 2023/10/30
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAllowPNG.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWAllowPNG**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWAllowPNG::FZZWAllowPNG() : FZZXMLElementObject()
{
    //DLOG("FZZWAllowPNG()");
    FZZConst::addClassCount("FZZWAllowPNG");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAllowPNG::FZZWAllowPNG(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWAllowPNG");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAllowPNG::FZZWAllowPNG(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWAllowPNG");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAllowPNG::FZZWAllowPNG(const FZZWAllowPNG& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWAllowPNG");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAllowPNG::~FZZWAllowPNG()
{
    //DLOG("~FZZWAllowPNG()");
    FZZConst::delClassCount("FZZWAllowPNG");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
