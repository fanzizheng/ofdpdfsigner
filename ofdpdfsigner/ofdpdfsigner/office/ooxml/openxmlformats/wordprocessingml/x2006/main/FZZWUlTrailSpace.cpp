//
//  Created by zizheng fan on 2023/09/19
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUlTrailSpace.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWUlTrailSpace**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWUlTrailSpace::FZZWUlTrailSpace() : FZZXMLElementObject()
{
    //DLOG("FZZWUlTrailSpace()");
    FZZConst::addClassCount("FZZWUlTrailSpace");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUlTrailSpace::FZZWUlTrailSpace(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWUlTrailSpace");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUlTrailSpace::FZZWUlTrailSpace(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWUlTrailSpace");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUlTrailSpace::FZZWUlTrailSpace(const FZZWUlTrailSpace& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWUlTrailSpace");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUlTrailSpace::~FZZWUlTrailSpace()
{
    //DLOG("~FZZWUlTrailSpace()");
    FZZConst::delClassCount("FZZWUlTrailSpace");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
