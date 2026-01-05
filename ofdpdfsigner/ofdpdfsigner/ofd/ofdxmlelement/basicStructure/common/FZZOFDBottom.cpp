//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDBottom.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDBottom**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBottom::FZZOFDBottom() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDBottom()");
    FZZConst::addClassCount("FZZOFDBottom");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBottom::FZZOFDBottom(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDBottom");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBottom::FZZOFDBottom(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDBottom");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBottom::FZZOFDBottom(const FZZOFDBottom& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDBottom");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBottom::~FZZOFDBottom()
{
    //DLOG("~FZZOFDBottom()");
    FZZConst::delClassCount("FZZOFDBottom");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBottom::setValue(double value)
{
    setValue_double(value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDBottom::getValue()
{
    return getValue_double();
}
//-----------------------------------------------------------------------------------------------------------------
