//
//  Created by zizheng fan on 2023/10/19
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblInd.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWTblInd**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblInd::FZZWTblInd() : FZZXMLElementObject()
{
    //DLOG("FZZWTblInd()");
    FZZConst::addClassCount("FZZWTblInd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblInd::FZZWTblInd(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblInd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblInd::FZZWTblInd(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTblInd");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblInd::FZZWTblInd(const FZZWTblInd& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblInd");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblInd::~FZZWTblInd()
{
    //DLOG("~FZZWTblInd()");
    FZZConst::delClassCount("FZZWTblInd");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblInd::setW(string value)
{
    setAttribute_String("w:w",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblInd::getW()
{
    return getAttribute_String("w:w");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblInd::setType(string value)
{
    setAttribute_String("w:type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblInd::getType()
{
    return getAttribute_String("w:type");
}
//-----------------------------------------------------------------------------------------------------------------
