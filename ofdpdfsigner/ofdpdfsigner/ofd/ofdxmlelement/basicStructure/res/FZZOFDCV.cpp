//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDCV.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCV**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCV::FZZOFDCV() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDCV()");
    FZZConst::addClassCount("FZZOFDCV");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCV::FZZOFDCV(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    FZZConst::addClassCount("FZZOFDCV");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCV::FZZOFDCV(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDCV");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCV::FZZOFDCV(const FZZOFDCV& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDCV");
    if ( this == &obj ) {
        return;
    }
    
    
 
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCV::~FZZOFDCV()
{
    //DLOG("~FZZOFDCV()");
    FZZConst::delClassCount("FZZOFDCV");
        
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCV::setColor(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCV::getColor()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCV::setColor(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setValue_String(strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCV::getColor(/*out*/vector<string> & array)
{
    string strid = getValue_String();
    ST_Array_ToArray(strid, array);
}
//-----------------------------------------------------------------------------------------------------------------
