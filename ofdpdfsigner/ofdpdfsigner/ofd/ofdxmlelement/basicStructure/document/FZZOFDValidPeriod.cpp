//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDValidPeriod.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDValidPeriod**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDValidPeriod::FZZOFDValidPeriod() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDValidPeriod()");
    FZZConst::addClassCount("FZZOFDValidPeriod");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDValidPeriod::FZZOFDValidPeriod(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDValidPeriod");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDValidPeriod::FZZOFDValidPeriod(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDValidPeriod");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDValidPeriod::FZZOFDValidPeriod(const FZZOFDValidPeriod& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDValidPeriod");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDValidPeriod::~FZZOFDValidPeriod()
{
    //DLOG("~FZZOFDValidPeriod()");
    FZZConst::delClassCount("FZZOFDValidPeriod");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDValidPeriod::setStartDate(string value)
{
    setAttribute_String("StartDate",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDValidPeriod::getStartDate()
{
    return getAttribute_String("StartDate");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDValidPeriod::setEndDate(string value)
{
    setAttribute_String("EndDate",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDValidPeriod::getEndDate()
{
    return getAttribute_String("EndDate");
}
//-----------------------------------------------------------------------------------------------------------------
