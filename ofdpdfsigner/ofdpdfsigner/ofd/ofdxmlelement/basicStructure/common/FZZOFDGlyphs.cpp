//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDGlyphs.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDGlyphs**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGlyphs::FZZOFDGlyphs() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDGlyphs()");
    FZZConst::addClassCount("FZZOFDGlyphs");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGlyphs::FZZOFDGlyphs(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDGlyphs");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGlyphs::FZZOFDGlyphs(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDGlyphs");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGlyphs::FZZOFDGlyphs(const FZZOFDGlyphs& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDGlyphs");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGlyphs::~FZZOFDGlyphs()
{
    //DLOG("~FZZOFDGlyphs()");
    FZZConst::delClassCount("FZZOFDGlyphs");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDGlyphs::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDGlyphs::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDGlyphs::setValue(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setValue_String(strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDGlyphs::getValue(/*out*/vector<string> & array)
{
    string strid = getValue_String();
    ST_Array_ToArray(strid, array);
}
//-----------------------------------------------------------------------------------------------------------------
