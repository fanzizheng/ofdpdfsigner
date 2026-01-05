//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDAuthor.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAuthor**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAuthor::FZZOFDAuthor() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDAuthor()");
    FZZConst::addClassCount("FZZOFDAuthor");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAuthor::FZZOFDAuthor(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDAuthor");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAuthor::FZZOFDAuthor(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDAuthor");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAuthor::FZZOFDAuthor(const FZZOFDAuthor& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDAuthor");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAuthor::~FZZOFDAuthor()
{
    //DLOG("~FZZOFDAuthor()");
    FZZConst::delClassCount("FZZOFDAuthor");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAuthor::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAuthor::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
