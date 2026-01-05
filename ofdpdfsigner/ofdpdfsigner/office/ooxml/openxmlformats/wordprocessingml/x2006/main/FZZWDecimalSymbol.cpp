//
//  Created by zizheng fan on 2023/09/28
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDecimalSymbol.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWDecimalSymbol**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWDecimalSymbol::FZZWDecimalSymbol() : FZZXMLElementObject()
{
    //DLOG("FZZWDecimalSymbol()");
    FZZConst::addClassCount("FZZWDecimalSymbol");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDecimalSymbol::FZZWDecimalSymbol(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWDecimalSymbol");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDecimalSymbol::FZZWDecimalSymbol(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWDecimalSymbol");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDecimalSymbol::FZZWDecimalSymbol(const FZZWDecimalSymbol& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWDecimalSymbol");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDecimalSymbol::~FZZWDecimalSymbol()
{
    //DLOG("~FZZWDecimalSymbol()");
    FZZConst::delClassCount("FZZWDecimalSymbol");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWDecimalSymbol::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWDecimalSymbol::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
