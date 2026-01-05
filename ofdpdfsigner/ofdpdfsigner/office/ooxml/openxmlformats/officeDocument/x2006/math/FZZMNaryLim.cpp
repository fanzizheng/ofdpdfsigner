//
//  Created by zizheng fan on 2023/05/25
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMNaryLim.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMNaryLim**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMNaryLim::FZZMNaryLim() : FZZXMLElementObject()
{
    //DLOG("FZZMNaryLim()");
    FZZConst::addClassCount("FZZMNaryLim");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMNaryLim::FZZMNaryLim(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMNaryLim");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMNaryLim::FZZMNaryLim(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMNaryLim");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMNaryLim::FZZMNaryLim(const FZZMNaryLim& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMNaryLim");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMNaryLim::~FZZMNaryLim()
{
    //DLOG("~FZZMNaryLim()");
    FZZConst::delClassCount("FZZMNaryLim");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMNaryLim::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMNaryLim::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
