//
//  Created by zizheng fan on 2024/03/08.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/annotation/FZZOFDRemark.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDRemark**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRemark::FZZOFDRemark() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDRemark()");
    FZZConst::addClassCount("FZZOFDRemark");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRemark::FZZOFDRemark(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDRemark");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRemark::FZZOFDRemark(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDRemark");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRemark::FZZOFDRemark(const FZZOFDRemark& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDRemark");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRemark::~FZZOFDRemark()
{
    //DLOG("~FZZOFDRemark()");
    FZZConst::delClassCount("FZZOFDRemark");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDRemark::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDRemark::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------

