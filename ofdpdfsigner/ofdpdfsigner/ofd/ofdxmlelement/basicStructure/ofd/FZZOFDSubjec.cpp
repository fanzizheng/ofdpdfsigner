//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/ofd/FZZOFDSubjec.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSubjec**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubjec::FZZOFDSubjec() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDSubjec()");
    FZZConst::addClassCount("FZZOFDSubjec");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubjec::FZZOFDSubjec(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDSubjec");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubjec::FZZOFDSubjec(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDSubjec");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubjec::FZZOFDSubjec(const FZZOFDSubjec& obj) : FZZOFDXMLElementObject(obj)
{

    FZZConst::addClassCount("FZZOFDSubjec");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubjec::~FZZOFDSubjec()
{
    //DLOG("~FZZOFDSubjec()");
    FZZConst::delClassCount("FZZOFDSubjec");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSubjec::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSubjec::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
