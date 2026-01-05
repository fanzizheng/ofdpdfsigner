//
//  Created by zizheng fan on 2023/09/13
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDefaultTabStop.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWDefaultTabStop**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWDefaultTabStop::FZZWDefaultTabStop() : FZZXMLElementObject()
{
    //DLOG("FZZWDefaultTabStop()");
    FZZConst::addClassCount("FZZWDefaultTabStop");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDefaultTabStop::FZZWDefaultTabStop(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWDefaultTabStop");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDefaultTabStop::FZZWDefaultTabStop(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWDefaultTabStop");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDefaultTabStop::FZZWDefaultTabStop(const FZZWDefaultTabStop& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWDefaultTabStop");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDefaultTabStop::~FZZWDefaultTabStop()
{
    //DLOG("~FZZWDefaultTabStop()");
    FZZConst::delClassCount("FZZWDefaultTabStop");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWDefaultTabStop::setVal(string value)
{
    setAttribute_String("w:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWDefaultTabStop::getVal()
{
    return getAttribute_String("w:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
