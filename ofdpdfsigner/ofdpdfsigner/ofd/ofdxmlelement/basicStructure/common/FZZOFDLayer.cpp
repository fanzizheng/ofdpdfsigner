//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLayer.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDLayer**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLayer::FZZOFDLayer() : FZZOFDPageBlock()
{
    //DLOG("FZZOFDLayer()");
    FZZConst::addClassCount("FZZOFDLayer");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLayer::FZZOFDLayer(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDPageBlock(parent,doc,node,key)
{
    
    FZZConst::addClassCount("FZZOFDLayer");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLayer::FZZOFDLayer(FZZOFDXMLFileObject * parent) : FZZOFDPageBlock(parent)
{
    FZZConst::addClassCount("FZZOFDLayer");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLayer::FZZOFDLayer(const FZZOFDLayer& obj) : FZZOFDPageBlock(obj)
{
    
    FZZConst::addClassCount("FZZOFDLayer");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLayer::~FZZOFDLayer()
{
    //DLOG("~FZZOFDLayer()");
    FZZConst::delClassCount("FZZOFDLayer");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDLayer::setDrawParam(long value)
{
    setAttribute_long("DrawParam",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDLayer::getDrawParam()
{
    return getAttribute_long("DrawParam");
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDLayer::getDrawParam_String()
{
    return getAttribute_String("DrawParam");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDLayer::setType(Type type)
{
    string value = "Body";
    
    switch (type) {
    case Type::Body:
        value = "Body";
        break;
    case Type::Background:
        value = "Background";
        break;
    case Type::Foreground:
        value = "Foreground";
        break;
    default:
        value = "Body";
        break;
    }
    setAttribute_String("Type",value);
}
//-----------------------------------------------------------------------------------------------------------------
Type FZZOFDLayer::getType()
{
    string strValue = getAttribute_String("Type");
    Type type = Type::Body;
    if (strValue == "Body") {
        type = Type::Body;
    }
    else if (strValue == "Background") {
        type = Type::Background;
    }
    else if (strValue == "Foreground") {
        type = Type::Foreground;
    }
    else {
        type = Type::Body;
    }
    
    return type;
}
//-----------------------------------------------------------------------------------------------------------------
