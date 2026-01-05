//
//  Created by zizheng fan on 2023/05/10.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/thememl/x2012/main/FZZThemeFamily.h"
#include "office/FZZOfficeObject.h"
#include "office/docx/FZZDocXConst.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZThemeFamily**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZThemeFamily::FZZThemeFamily() : FZZXMLElementObject()
{
    //DLOG("FZZThemeFamily()");
    FZZConst::addClassCount("FZZThemeFamily");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeFamily::FZZThemeFamily(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZThemeFamily");
    setAttribute_String(MICROSOFT_OFFICE_THEMEML_2012_MAIN_NAME,MICROSOFT_OFFICE_THEMEML_2012_MAIN_VALUE);
    setAttribute_String("name","Office Theme");
    setAttribute_String("id","{62F939B6-93AF-4DB8-9C6B-D6C7DFDC589F}");
    setAttribute_String("vid","{4A3C46E8-61CC-4603-A589-7422A47A8E4A}");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeFamily::FZZThemeFamily(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZThemeFamily");
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeFamily::FZZThemeFamily(const FZZThemeFamily& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZThemeFamily");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZThemeFamily::~FZZThemeFamily()
{
    //DLOG("~FZZThemeFamily()");
    FZZConst::delClassCount("FZZThemeFamily");
}
//-----------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
