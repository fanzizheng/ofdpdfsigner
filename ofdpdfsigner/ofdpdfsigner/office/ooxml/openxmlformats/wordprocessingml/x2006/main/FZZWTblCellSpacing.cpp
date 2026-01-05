//
//  Created by zizheng fan on 2024/02/21
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblCellSpacing.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblCellSpacing**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellSpacing::FZZWTblCellSpacing() : FZZXMLElementObject()
{
    //DLOG("FZZWTblCellSpacing()");
    FZZConst::addClassCount("FZZWTblCellSpacing");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellSpacing::FZZWTblCellSpacing(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblCellSpacing");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellSpacing::FZZWTblCellSpacing(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTblCellSpacing");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellSpacing::FZZWTblCellSpacing(const FZZWTblCellSpacing& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblCellSpacing");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblCellSpacing::~FZZWTblCellSpacing()
{
    //DLOG("~FZZWTblCellSpacing()");
    FZZConst::delClassCount("FZZWTblCellSpacing");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblCellSpacing::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblCellSpacing::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblCellSpacing::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblCellSpacing::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
