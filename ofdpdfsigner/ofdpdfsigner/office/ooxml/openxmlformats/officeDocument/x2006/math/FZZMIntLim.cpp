//
//  Created by zizheng fan on 2023/05/19.
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMIntLim.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMIntLim**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMIntLim::FZZMIntLim() : FZZXMLElementObject()
{
    //DLOG("FZZMIntLim()");
    FZZConst::addClassCount("FZZMIntLim");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMIntLim::FZZMIntLim(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMIntLim");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMIntLim::FZZMIntLim(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMIntLim");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMIntLim::FZZMIntLim(const FZZMIntLim& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMIntLim");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMIntLim::~FZZMIntLim()
{
    //DLOG("~FZZMIntLim()");
    FZZConst::delClassCount("FZZMIntLim");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMIntLim::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMIntLim::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
