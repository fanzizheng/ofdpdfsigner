//
//  Created by zizheng fan on 2023/08/16
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfont_ea_cs.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZAfont_ea_cs**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs::FZZAfont_ea_cs() : FZZXMLElementObject()
{
    //DLOG("FZZAfont_ea_cs()");
    FZZConst::addClassCount("FZZAfont_ea_cs");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs::FZZAfont_ea_cs(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZAfont_ea_cs");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs::FZZAfont_ea_cs(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZAfont_ea_cs");
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs::FZZAfont_ea_cs(const FZZAfont_ea_cs& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZAfont_ea_cs");
    if ( this == &obj ) {
        return;
    }

    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZAfont_ea_cs::~FZZAfont_ea_cs()
{
    //DLOG("~FZZAfont_ea_cs()");
    FZZConst::delClassCount("FZZAfont_ea_cs");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAfont_ea_cs::setScript(string value)
{
    setAttribute_String("script",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAfont_ea_cs::getScript()
{
    return getAttribute_String("script");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAfont_ea_cs::setTypeface(string value)
{
    setAttribute_String("typeface",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAfont_ea_cs::getTypeface()
{
    return getAttribute_String("typeface");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZAfont_ea_cs::setPanose(string value)
{
    setAttribute_String("panose",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZAfont_ea_cs::getPanose()
{
    return getAttribute_String("panose");
}
//-----------------------------------------------------------------------------------------------------------------
