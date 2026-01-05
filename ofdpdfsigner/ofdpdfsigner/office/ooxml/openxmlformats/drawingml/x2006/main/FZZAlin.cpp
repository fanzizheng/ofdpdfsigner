//
//  Created by zizheng fan on 2023/08/02
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAlin.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAlin**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAlin::FZZAlin() : FZZXMLElementObject()
{
    //DLOG("FZZAlin()");
    FZZConst::addClassCount("FZZAlin");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlin::FZZAlin(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAlin");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlin::FZZAlin(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAlin");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlin::FZZAlin(const FZZAlin& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAlin");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAlin::~FZZAlin()
{
    //DLOG("~FZZAlin()");
    FZZConst::delClassCount("FZZAlin");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAlin::setAng(string value)
{
    setAttribute_String("ang",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAlin::getAng()
{
    return getAttribute_String("ang");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAlin::setScaled(string value)
{
    setAttribute_String("scaled",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAlin::getScaled()
{
    return getAttribute_String("scaled");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
