//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTextCode.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDTextCode**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextCode::FZZOFDTextCode() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDTextCode()");
    FZZConst::addClassCount("FZZOFDTextCode");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextCode::FZZOFDTextCode(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDTextCode");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextCode::FZZOFDTextCode(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDTextCode");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextCode::FZZOFDTextCode(const FZZOFDTextCode& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDTextCode");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextCode::~FZZOFDTextCode()
{
    //DLOG("~FZZOFDTextCode()");
    FZZConst::delClassCount("FZZOFDTextCode");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::setContent(string content)
{
    setValue_String(content);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDTextCode::getContent()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::setCoordinate(double x, double y)
{
    setX(x);
    setY(y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::setX(double value)
{
    setAttribute_double("X",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDTextCode::getX()
{
    return getAttribute_double("X");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::setY(double value)
{
    setAttribute_double("Y",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDTextCode::getY()
{
    return getAttribute_double("Y");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::setDeltaX(string value)
{
    setAttribute_String("DeltaX",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDTextCode::getDeltaX()
{
    return getAttribute_String("DeltaX");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::setDeltaY(string value)
{
    setAttribute_String("DeltaY",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDTextCode::getDeltaY()
{
    return getAttribute_String("DeltaY");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::deltaFormatter(string delta,/*out*/vector<string> & array)
{

    size_t indexOf = delta.find('g');
    if (indexOf == string::npos) {
        FZZConst::split(delta.c_str()," ", array);
    }
    else {
        vector<string> temp;
        FZZConst::split(delta.c_str()," ", temp);
        if ( temp.size() > 0 ) {
            bool gFlag = false;
            bool gProcessing = false;
            long gItemCount = 0;

            vector<string>::const_iterator iter;
            for (iter = temp.begin(); iter != temp.end(); iter++) {
                string item_s = *iter;
                if (item_s == "g") {
                    gFlag = true;
                }
                else {
                    if (item_s.empty()) {
                        continue;
                    }
                    if (gFlag) {
                        gItemCount = strtol(item_s.c_str(),NULL,10);
                        gProcessing = true;
                        gFlag = false;
                    }
                    else if (gProcessing) {
                        for (int j = 0; j < gItemCount; j++) {
                            array.push_back(item_s);
                        }
                        gProcessing = false;
                    }
                    else {
                        array.push_back(item_s);
                    }
                }
            }
        }//if ( temp.size() > 0 ) {
        
    }//if (indexOf == string::npos)
   
}

//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::setDeltaX(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setAttribute_String("DeltaX",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::getDeltaX(/*out*/vector<string> & array)
{
    deltaFormatter( getAttribute_String("DeltaX"),array);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::setDeltaY(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setAttribute_String("DeltaY",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDTextCode::getDeltaY(/*out*/vector<string> & array)
{
    deltaFormatter( getAttribute_String("DeltaY"),array);
}
//-----------------------------------------------------------------------------------------------------------------
