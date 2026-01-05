//
//  Created by zizheng fan on 2023/11/06
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblLook.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWB**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLook::FZZWTblLook() : FZZXMLElementObject()
{
    //DLOG("FZZWTblLook()");
    FZZConst::addClassCount("FZZWTblLook");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLook::FZZWTblLook(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWTblLook");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLook::FZZWTblLook(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWTblLook");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLook::FZZWTblLook(const FZZWTblLook& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWTblLook");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTblLook::~FZZWTblLook()
{
    //DLOG("~FZZWTblLook()");
    FZZConst::delClassCount("FZZWTblLook");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblLook::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblLook::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblLook::setFirstRow(string value)
{
    setAttribute_String("w:firstRow",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblLook::getFirstRow()
{
    return getAttribute_String("w:firstRow");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblLook::setLastRow(string value)
{
    setAttribute_String("w:lastRow",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblLook::getLastRow()
{
    return getAttribute_String("w:lastRow");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblLook::setFirstColumn(string value)
{
    setAttribute_String("w:firstColumn",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblLook::getFirstColumn()
{
    return getAttribute_String("w:firstColumn");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblLook::setLastColumn(string value)
{
    setAttribute_String("w:lastColumn",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblLook::getLastColumn()
{
    return getAttribute_String("w:lastColumn");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblLook::setNoHBand(string value)
{
    setAttribute_String("w:noHBand",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblLook::getNoHBand()
{
    return getAttribute_String("w:noHBand");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWTblLook::setNoVBand(string value)
{
    setAttribute_String("w:noVBand",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWTblLook::getNoVBand()
{
    return getAttribute_String("w:noVBand");
}
//-----------------------------------------------------------------------------------------------------------------
