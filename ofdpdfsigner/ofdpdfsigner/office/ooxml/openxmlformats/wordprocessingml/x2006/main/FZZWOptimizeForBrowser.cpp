//
//  Created by zizheng fan on 2023/10/30
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWOptimizeForBrowser.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWOptimizeForBrowser**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWOptimizeForBrowser::FZZWOptimizeForBrowser() : FZZXMLElementObject()
{
    //DLOG("FZZWOptimizeForBrowser()");
    FZZConst::addClassCount("FZZWOptimizeForBrowser");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWOptimizeForBrowser::FZZWOptimizeForBrowser(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWOptimizeForBrowser");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWOptimizeForBrowser::FZZWOptimizeForBrowser(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWOptimizeForBrowser");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWOptimizeForBrowser::FZZWOptimizeForBrowser(const FZZWOptimizeForBrowser& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWOptimizeForBrowser");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWOptimizeForBrowser::~FZZWOptimizeForBrowser()
{
    //DLOG("~FZZWOptimizeForBrowser()");
    FZZConst::delClassCount("FZZWOptimizeForBrowser");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
