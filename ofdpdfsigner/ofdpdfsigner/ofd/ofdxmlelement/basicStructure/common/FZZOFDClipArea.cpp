//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClipArea.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDClipArea**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClipArea::FZZOFDClipArea() : FZZOFDXMLElementObject(),m_FZZOFDText(NULL),m_FZZOFDPath(NULL)
{
    //DLOG("FZZOFDClipArea()");
    FZZConst::addClassCount("FZZOFDClipArea");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClipArea::FZZOFDClipArea(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDText(NULL),m_FZZOFDPath(NULL)
{
    
    FZZConst::addClassCount("FZZOFDClipArea");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClipArea::FZZOFDClipArea(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDText(NULL),m_FZZOFDPath(NULL)
{
    FZZConst::addClassCount("FZZOFDClipArea");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClipArea::FZZOFDClipArea(const FZZOFDClipArea& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDClipArea");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDText = obj.m_FZZOFDText != NULL ? new FZZOFDText(*obj.m_FZZOFDText) : NULL;
    m_FZZOFDPath = obj.m_FZZOFDPath != NULL ? new FZZOFDPath(*obj.m_FZZOFDPath) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClipArea::~FZZOFDClipArea()
{
    //DLOG("~FZZOFDClipArea()");
    FZZConst::delClassCount("FZZOFDClipArea");
    
    if ( m_FZZOFDText != NULL ) {
        delete m_FZZOFDText;
        m_FZZOFDText = NULL;
    }
    if ( m_FZZOFDPath != NULL ) {
        delete m_FZZOFDPath;
        m_FZZOFDPath = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDClipArea::setDrawParam(string value)
{
    setAttribute_String("DrawParam",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDClipArea::getDrawParam()
{
    return getAttribute_String("DrawParam");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDClipArea::setCTM(string value)
{
    setAttribute_String("CTM",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDClipArea::getCTM()
{
    return getAttribute_String("CTM");
}
//-----------------------------------------------------------------------------------------------------------------
//FZZOFDClipAble* FZZOFDClipArea::setClipObj(const char * const elsname)
//{
//    return m_FZZOFDDocInfo = setElementObject(m_FZZOFDDocInfo,FZZOFDDOCINFO_Name);
//}
////-----------------------------------------------------------------------------------------------------------------
//FZZOFDClipAble* FZZOFDClipArea::getClipObj()
//{
//    return m_FZZOFDDocInfo = getElementObject(m_FZZOFDDocInfo,FZZOFDDOCINFO_Name);
//}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDClipArea::deleteObject()
{
    if ( m_FZZOFDText != NULL ) {
        delete m_FZZOFDText;
        m_FZZOFDText = NULL;
    }
    if ( m_FZZOFDPath != NULL ) {
        delete m_FZZOFDPath;
        m_FZZOFDPath = NULL;
    }
    deleteElement(FZZOFDTEXT_Name);
    deleteElement(FZZOFDPATH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDText * FZZOFDClipArea::setText()
{
    deleteObject();
    return m_FZZOFDText = setElementObject(m_FZZOFDText,FZZOFDTEXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDText * FZZOFDClipArea::getText()
{
    return m_FZZOFDText = getElementObject(m_FZZOFDText,FZZOFDTEXT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPath * FZZOFDClipArea::setPath()
{
    deleteObject();
    return m_FZZOFDPath = setElementObject(m_FZZOFDPath,FZZOFDPATH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPath * FZZOFDClipArea::getPath()
{
    return m_FZZOFDPath = getElementObject(m_FZZOFDPath,FZZOFDPATH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDClipArea::setDrawParam(long value)
{
    setAttribute_long("DrawParam",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDClipArea::getDrawParam_long()
{
    return getAttribute_long("DrawParam");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDClipArea::setCTM(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setAttribute_String("CTM",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDClipArea::getCTM(/*out*/vector<double> & array)
{
    string strid = getAttribute_String("CTM");
    ST_Array_ToArray(strid, array);
}
//-----------------------------------------------------------------------------------------------------------------
