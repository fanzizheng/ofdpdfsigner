//
//  Created by zizheng fan on 2023/04/26.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2012/wordml/FZZW15ChartTrackingRefBased.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZW15ChartTrackingRefBased**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZW15ChartTrackingRefBased::FZZW15ChartTrackingRefBased() : FZZXMLElementObject()
{
    //DLOG("FZZW15ChartTrackingRefBased()");
    FZZConst::addClassCount("FZZW15ChartTrackingRefBased");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15ChartTrackingRefBased::FZZW15ChartTrackingRefBased(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZW15ChartTrackingRefBased");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15ChartTrackingRefBased::FZZW15ChartTrackingRefBased(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZW15ChartTrackingRefBased");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15ChartTrackingRefBased::FZZW15ChartTrackingRefBased(const FZZW15ChartTrackingRefBased& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZW15ChartTrackingRefBased");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW15ChartTrackingRefBased::~FZZW15ChartTrackingRefBased()
{
    //DLOG("~FZZW15ChartTrackingRefBased()");
    FZZConst::delClassCount("FZZW15ChartTrackingRefBased");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZW15ChartTrackingRefBased::setVal(string value)
{
    setAttribute_String("w15:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZW15ChartTrackingRefBased::getVal()
{
    return getAttribute_String("w15:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
