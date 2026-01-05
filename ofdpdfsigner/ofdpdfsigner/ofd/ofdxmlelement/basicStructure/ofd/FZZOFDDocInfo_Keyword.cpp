//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocInfo_Keyword.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDocInfo_Keyword**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keyword::FZZOFDDocInfo_Keyword() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDDocInfo_Keyword()");
    FZZConst::addClassCount("FZZOFDDocInfo_Keyword");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keyword::FZZOFDDocInfo_Keyword(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{

    FZZConst::addClassCount("FZZOFDDocBody");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keyword::FZZOFDDocInfo_Keyword(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDDocInfo_Keyword");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keyword::FZZOFDDocInfo_Keyword(const FZZOFDDocInfo_Keyword& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDDocInfo_Keyword");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocInfo_Keyword::~FZZOFDDocInfo_Keyword()
{
    //DLOG("~FZZOFDDocInfo_Keyword()");
    FZZConst::delClassCount("FZZOFDDocInfo_Keyword");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDocInfo_Keyword::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDDocInfo_Keyword::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
