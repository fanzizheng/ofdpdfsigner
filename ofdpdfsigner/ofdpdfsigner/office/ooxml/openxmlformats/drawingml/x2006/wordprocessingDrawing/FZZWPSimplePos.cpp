//
//  Created by zizheng fan on 2023/06/15
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPSimplePos.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPSimplePos**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPSimplePos::FZZWPSimplePos() : FZZXMLElementObject()
{
    //DLOG("FZZWPSimplePos()");
    FZZConst::addClassCount("FZZWPSimplePos");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSimplePos::FZZWPSimplePos(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPSimplePos");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSimplePos::FZZWPSimplePos(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWPSimplePos");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSimplePos::FZZWPSimplePos(const FZZWPSimplePos& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPSimplePos");
    if ( this == &obj ) {
        return;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPSimplePos::~FZZWPSimplePos()
{
    //DLOG("~FZZWPSimplePos()");
    FZZConst::delClassCount("FZZWPSimplePos");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPSimplePos::setX(string value)
{
    setAttribute_String("x",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPSimplePos::getX()
{
    return getAttribute_String("x");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPSimplePos::setY(string value)
{
    setAttribute_String("y",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPSimplePos::getY()
{
    return getAttribute_String("y");
}
//-----------------------------------------------------------------------------------------------------------------

