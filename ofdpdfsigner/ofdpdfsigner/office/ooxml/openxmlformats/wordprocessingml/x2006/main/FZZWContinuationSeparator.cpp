//
//  Created by zizheng fan on 2023/11/09
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWContinuationSeparator.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWSeparator**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWContinuationSeparator::FZZWContinuationSeparator() : FZZXMLElementObject()
{
    //DLOG("FZZWContinuationSeparator()");
    FZZConst::addClassCount("FZZWContinuationSeparator");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWContinuationSeparator::FZZWContinuationSeparator(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWContinuationSeparator");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWContinuationSeparator::FZZWContinuationSeparator(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWContinuationSeparator");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWContinuationSeparator::FZZWContinuationSeparator(const FZZWContinuationSeparator& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWContinuationSeparator");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWContinuationSeparator::~FZZWContinuationSeparator()
{
    //DLOG("~FZZWContinuationSeparator()");
    FZZConst::delClassCount("FZZWContinuationSeparator");
}
//-----------------------------------------------------------------------------------------------------------------

