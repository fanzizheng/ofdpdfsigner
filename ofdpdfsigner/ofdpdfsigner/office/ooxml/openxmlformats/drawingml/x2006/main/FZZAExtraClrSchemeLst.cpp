//
//  Created by zizheng fan on 2023/08/28
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExtraClrSchemeLst.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAExtraClrSchemeLst**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAExtraClrSchemeLst::FZZAExtraClrSchemeLst() : FZZXMLElementObject()
{
    //DLOG("FZZAExtraClrSchemeLst()");
    FZZConst::addClassCount("FZZAExtraClrSchemeLst");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtraClrSchemeLst::FZZAExtraClrSchemeLst(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAExtraClrSchemeLst");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtraClrSchemeLst::FZZAExtraClrSchemeLst(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAExtraClrSchemeLst");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtraClrSchemeLst::FZZAExtraClrSchemeLst(const FZZAExtraClrSchemeLst& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAExtraClrSchemeLst");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAExtraClrSchemeLst::~FZZAExtraClrSchemeLst()
{
    //DLOG("~FZZAExtraClrSchemeLst()");
    FZZConst::delClassCount("FZZAExtraClrSchemeLst");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
