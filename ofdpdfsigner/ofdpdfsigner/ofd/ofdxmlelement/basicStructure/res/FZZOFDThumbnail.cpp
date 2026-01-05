//
//  Created by zizheng fan on 2024/03/11.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDThumbnail.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDThumbnail**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDThumbnail::FZZOFDThumbnail() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDThumbnail()");
    FZZConst::addClassCount("FZZOFDThumbnail");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDThumbnail::FZZOFDThumbnail(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    FZZConst::addClassCount("FZZOFDThumbnail");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDThumbnail::FZZOFDThumbnail(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDThumbnail");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDThumbnail::FZZOFDThumbnail(const FZZOFDThumbnail& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDThumbnail");
    if ( this == &obj ) {
        return;
    }
    
    
 
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDThumbnail::~FZZOFDThumbnail()
{
    //DLOG("~FZZOFDThumbnail()");
    FZZConst::delClassCount("FZZOFDThumbnail");
        
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDThumbnail::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDThumbnail::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDThumbnail::setValue(long value)
{
    setValue_long(value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDThumbnail::getLongValue()
{
    return getValue_long();
}
//-----------------------------------------------------------------------------------------------------------------
