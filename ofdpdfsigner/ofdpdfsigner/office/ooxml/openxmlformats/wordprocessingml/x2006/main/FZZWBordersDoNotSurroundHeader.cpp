//
//  Created by zizheng fan on 2023/09/11
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBordersDoNotSurroundHeader.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWBordersDoNotSurroundHeader**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundHeader::FZZWBordersDoNotSurroundHeader() : FZZXMLElementObject()
{
    //DLOG("FZZWBordersDoNotSurroundHeader()");
    FZZConst::addClassCount("FZZWBordersDoNotSurroundHeader");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundHeader::FZZWBordersDoNotSurroundHeader(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWBordersDoNotSurroundHeader");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundHeader::FZZWBordersDoNotSurroundHeader(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWBordersDoNotSurroundHeader");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundHeader::FZZWBordersDoNotSurroundHeader(const FZZWBordersDoNotSurroundHeader& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWBordersDoNotSurroundHeader");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBordersDoNotSurroundHeader::~FZZWBordersDoNotSurroundHeader()
{
    //DLOG("~FZZWBordersDoNotSurroundHeader()");
    FZZConst::delClassCount("FZZWBordersDoNotSurroundHeader");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
