//
//  Created by zizheng fan on 2023/07/28
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAmiter.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAmiter**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAmiter::FZZAmiter() : FZZXMLElementObject()
{
    //DLOG("FZZAmiter()");
    FZZConst::addClassCount("FZZAmiter");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAmiter::FZZAmiter(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAmiter");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAmiter::FZZAmiter(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAmiter");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAmiter::FZZAmiter(const FZZAmiter& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAmiter");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAmiter::~FZZAmiter()
{
    //DLOG("~FZZAmiter()");
    FZZConst::delClassCount("FZZAmiter");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAmiter::setLim(string value)
{
    setAttribute_String("lim",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAmiter::getLim()
{
    return getAttribute_String("lim");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
