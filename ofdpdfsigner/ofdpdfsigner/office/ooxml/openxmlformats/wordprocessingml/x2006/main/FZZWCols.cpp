//
//  Created by zizheng fan on 2023/10/26
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCols.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWCols**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWCols::FZZWCols() : FZZXMLElementObject()
{
    //DLOG("FZZWCols()");
    FZZConst::addClassCount("FZZWCols");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCols::FZZWCols(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWCols");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCols::FZZWCols(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWCols");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCols::FZZWCols(const FZZWCols& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWCols");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCols::~FZZWCols()
{
    //DLOG("~FZZWCols()");
    FZZConst::delClassCount("FZZWCols");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWCols::setSpace(string value)
{
    setAttribute_String("w:space",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWCols::getSpace()
{
    return getAttribute_String("w:space");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWCols::setNum(string value)
{
    setAttribute_String("w:num",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWCols::getNum()
{
    return getAttribute_String("w:num");
}
//-----------------------------------------------------------------------------------------------------------------
