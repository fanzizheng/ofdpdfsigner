//
//  Created by zizheng fan on 2023/09/12
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBordersDoNotSurroundFooter.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWBordersDoNotSurroundFooter**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundFooter::FZZWBordersDoNotSurroundFooter() : FZZXMLElementObject()
{
    //DLOG("FZZWBordersDoNotSurroundFooter()");
    FZZConst::addClassCount("FZZWBordersDoNotSurroundFooter");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundFooter::FZZWBordersDoNotSurroundFooter(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWBordersDoNotSurroundFooter");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundFooter::FZZWBordersDoNotSurroundFooter(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWBordersDoNotSurroundFooter");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundFooter::FZZWBordersDoNotSurroundFooter(const FZZWBordersDoNotSurroundFooter& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWBordersDoNotSurroundFooter");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundFooter::~FZZWBordersDoNotSurroundFooter()
{
    //DLOG("~FZZWBordersDoNotSurroundFooter()");
    FZZConst::delClassCount("FZZWBordersDoNotSurroundFooter");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
