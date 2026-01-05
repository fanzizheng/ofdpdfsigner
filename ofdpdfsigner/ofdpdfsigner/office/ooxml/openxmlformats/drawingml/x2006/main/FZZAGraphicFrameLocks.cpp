//
//  Created by zizheng fan on 2023/07/15
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphicFrameLocks.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAGraphicFrameLocks**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicFrameLocks::FZZAGraphicFrameLocks() : FZZXMLElementObject()
{
    //DLOG("FZZAGraphicFrameLocks()");
    FZZConst::addClassCount("FZZAGraphicFrameLocks");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicFrameLocks::FZZAGraphicFrameLocks(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAGraphicFrameLocks");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicFrameLocks::FZZAGraphicFrameLocks(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAGraphicFrameLocks");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicFrameLocks::FZZAGraphicFrameLocks(const FZZAGraphicFrameLocks& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAGraphicFrameLocks");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAGraphicFrameLocks::~FZZAGraphicFrameLocks()
{
    //DLOG("~FZZAGraphicFrameLocks()");
    FZZConst::delClassCount("FZZAGraphicFrameLocks");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAGraphicFrameLocks::setNoChangeAspect(string value)
{
    setAttribute_String("noChangeAspect",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAGraphicFrameLocks::getNoChangeAspect()
{
    return getAttribute_String("noChangeAspect");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAGraphicFrameLocks::setXmlnsA(string value)
{
    setAttribute_String("xmlns:a",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAGraphicFrameLocks::getXmlnsA()
{
    return getAttribute_String("xmlns:a");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
