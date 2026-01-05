//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDAbbreviatedData.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAbbreviatedData**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbbreviatedData::FZZOFDAbbreviatedData() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDAbbreviatedData()");
    FZZConst::addClassCount("FZZOFDAbbreviatedData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbbreviatedData::FZZOFDAbbreviatedData(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDAbbreviatedData");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbbreviatedData::FZZOFDAbbreviatedData(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDAbbreviatedData");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbbreviatedData::FZZOFDAbbreviatedData(const FZZOFDAbbreviatedData& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDAbbreviatedData");
    if ( this == &obj ) {
        return;
    }
    vector<string>::const_iterator iter;
    for (iter = obj.m_dataQueue.begin(); iter != obj.m_dataQueue.end(); iter++) {
        m_dataQueue.push_back(*iter);
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbbreviatedData::~FZZOFDAbbreviatedData()
{
    //DLOG("~FZZOFDAbbreviatedData()");
    FZZConst::delClassCount("FZZOFDAbbreviatedData");
    
    m_dataQueue.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAbbreviatedData::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAbbreviatedData::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAbbreviatedData::flush()
{
    
    setValue_String(toString());
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAbbreviatedData::toString()
{
    if (m_dataQueue.size() == 0) {
        return "";
    }
    int cnt = 0;
    string ret = "";
    vector<string>::const_iterator iter;
    for (iter = m_dataQueue.begin(); iter != m_dataQueue.end(); iter++) {
        cnt++;
        if (cnt != 1) {
            
            ret += " ";
        }
        ret += *iter;
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAbbreviatedData::defineStart(double x, double y)
{
    m_dataQueue.push_back("S "+FZZConst::fmt(x)+" "+FZZConst::fmt(y));
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAbbreviatedData::moveTo(double x, double y)
{
    m_dataQueue.push_back("M "+FZZConst::fmt(x)+" "+FZZConst::fmt(y));
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAbbreviatedData::lineTo(double x, double y)
{
    m_dataQueue.push_back("L "+FZZConst::fmt(x)+" "+FZZConst::fmt(y));
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAbbreviatedData::quadraticBezier(double x1, double y1, double x2, double y2)
{
    m_dataQueue.push_back("Q "+FZZConst::fmt(x1)+" "+FZZConst::fmt(y1)+" "+FZZConst::fmt(x2)+" "+FZZConst::fmt(y2));
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAbbreviatedData::cubicBezier(double x1, double y1, double x2, double y2, double x3, double y3)
{
    m_dataQueue.push_back("B "+FZZConst::fmt(x1)+" "+FZZConst::fmt(y1)+" "+FZZConst::fmt(x2)+" "+FZZConst::fmt(y2)+" "+FZZConst::fmt(x3)+" "+FZZConst::fmt(y3));
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAbbreviatedData::arc(double rx, double ry, double angle, int large, int sweep, double x, double y)
{
    m_dataQueue.push_back("A "+FZZConst::fmt(rx)+" "+FZZConst::fmt(ry)+" "+FZZConst::fmt(angle)+" "+FZZConst::fmt(large)+" "+FZZConst::fmt(sweep)+" "+FZZConst::fmt(x)+" "+FZZConst::fmt(y));
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAbbreviatedData::copy(FZZOFDAbbreviatedData * obj)
{
    if ( this == obj ) {
        return;
    }
    
    this->m_dataQueue = obj->m_dataQueue;
}
//-----------------------------------------------------------------------------------------------------------------
