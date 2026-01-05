//
//  Created by zizheng fan on 2023/09/12
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDrawingGridVerticalSpacing.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWDrawingGridVerticalSpacing**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawingGridVerticalSpacing::FZZWDrawingGridVerticalSpacing() : FZZXMLElementObject()
{
    //DLOG("FZZWDrawingGridVerticalSpacing()");
    FZZConst::addClassCount("FZZWDrawingGridVerticalSpacing");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawingGridVerticalSpacing::FZZWDrawingGridVerticalSpacing(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWDrawingGridVerticalSpacing");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawingGridVerticalSpacing::FZZWDrawingGridVerticalSpacing(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWDrawingGridVerticalSpacing");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawingGridVerticalSpacing::FZZWDrawingGridVerticalSpacing(const FZZWDrawingGridVerticalSpacing& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWDrawingGridVerticalSpacing");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDrawingGridVerticalSpacing::~FZZWDrawingGridVerticalSpacing()
{
    //DLOG("~FZZWDrawingGridVerticalSpacing()");
    FZZConst::delClassCount("FZZWDrawingGridVerticalSpacing");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWDrawingGridVerticalSpacing::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWDrawingGridVerticalSpacing::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
