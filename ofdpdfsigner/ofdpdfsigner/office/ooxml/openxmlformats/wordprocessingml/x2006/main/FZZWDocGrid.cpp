//
//  Created by zizheng fan on 2023/10/26
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDocGrid.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWDocGrid**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWDocGrid::FZZWDocGrid() : FZZXMLElementObject()
{
    //DLOG("FZZWDocGrid()");
    FZZConst::addClassCount("FZZWDocGrid");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocGrid::FZZWDocGrid(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWDocGrid");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocGrid::FZZWDocGrid(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWDocGrid");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocGrid::FZZWDocGrid(const FZZWDocGrid& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWDocGrid");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDocGrid::~FZZWDocGrid()
{
    //DLOG("~FZZWDocGrid()");
    FZZConst::delClassCount("FZZWDocGrid");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWDocGrid::setLinePitch(string value)
{
    setAttribute_String("w:linePitch",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWDocGrid::getLinePitch()
{
    return getAttribute_String("w:linePitch");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWDocGrid::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWDocGrid::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWDocGrid::setCharSpace(string value)
{
    setAttribute_String("w:charSpace",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWDocGrid::getCharSpace()
{
    return getAttribute_String("w:charSpace");
}
//-----------------------------------------------------------------------------------------------------------------
