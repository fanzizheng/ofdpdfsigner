//
//  Created by zizheng fan on 2023/05/23
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMMathFont.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWRsidRoot**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMMathFont::FZZMMathFont() : FZZXMLElementObject()
{
    //DLOG("FZZMMathFont()");
    FZZConst::addClassCount("FZZMMathFont");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathFont::FZZMMathFont(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZMMathFont");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathFont::FZZMMathFont(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZMMathFont");
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathFont::FZZMMathFont(const FZZMMathFont& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZMMathFont");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMMathFont::~FZZMMathFont()
{
    //DLOG("~FZZMMathFont()");
    FZZConst::delClassCount("FZZMMathFont");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMMathFont::setVal(string value)
{
    setAttribute_String("m:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZMMathFont::getVal()
{
    return getAttribute_String("m:val");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
