//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPageLayout.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPageLayout**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageLayout::FZZOFDPageLayout() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPageLayout()");
    FZZConst::addClassCount("FZZOFDPageLayout");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageLayout::FZZOFDPageLayout(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDPageLayout");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageLayout::FZZOFDPageLayout(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPageLayout");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageLayout::FZZOFDPageLayout(const FZZOFDPageLayout& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPageLayout");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageLayout::~FZZOFDPageLayout()
{
    //DLOG("~FZZOFDPageLayout()");
    FZZConst::delClassCount("FZZOFDPageLayout");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageLayout::setType(FZZOFDPageLayout::TYPE value)
{

    string strtype = "OnePage";
    switch (value) {
        case FZZOFDPageLayout::TYPE::OnePage:
            strtype = "OnePage";
            break;
        case FZZOFDPageLayout::TYPE::OneColumn:
            strtype = "OneColumn";
            break;
        case FZZOFDPageLayout::TYPE::TwoPageL:
            strtype = "TwoPageL";
            break;
        case FZZOFDPageLayout::TYPE::TwoColumnL:
            strtype = "TwoColumnL";
            break;
        case FZZOFDPageLayout::TYPE::TwoPageR:
            strtype = "TwoPageR";
            break;
        case FZZOFDPageLayout::TYPE::TwoColumnR:
            strtype = "TwoColumnR";
            break;
        
        default:
            strtype = "OnePage";
            break;

    }
    setValue_String(strtype);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageLayout::TYPE FZZOFDPageLayout::getType()
{
    FZZOFDPageLayout::TYPE retvalue = FZZOFDPageLayout::TYPE::OnePage;
    string data = getValue_String();
    if (data == "OnePage") {
        retvalue = FZZOFDPageLayout::TYPE::OnePage;
    }
    else if (data == "OneColumn") {
        retvalue = FZZOFDPageLayout::TYPE::OneColumn;
    }
    else if (data == "TwoPageL") {
        retvalue = FZZOFDPageLayout::TYPE::TwoPageL;
    }
    else if (data == "TwoColumnL") {
        retvalue = FZZOFDPageLayout::TYPE::TwoColumnL;
    }
    else if (data == "TwoPageR") {
        retvalue = FZZOFDPageLayout::TYPE::TwoPageR;
    }
    else if (data == "TwoColumnR") {
        retvalue = FZZOFDPageLayout::TYPE::TwoColumnR;
    }
    return retvalue;
}
//-----------------------------------------------------------------------------------------------------------------
