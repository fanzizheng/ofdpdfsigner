//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDBaseGraphic.h"
#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClips.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDActions.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDBaseGraphic**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBaseGraphic::FZZOFDBaseGraphic() : FZZOFDXMLElementObject(),m_FZZOFDClips(NULL),m_FZZOFDActions(NULL)
{
    //DLOG("FZZOFDBaseGraphic()");
    FZZConst::addClassCount("FZZOFDBaseGraphic");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBaseGraphic::FZZOFDBaseGraphic(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDClips(NULL),m_FZZOFDActions(NULL)
{
    
    FZZConst::addClassCount("FZZOFDBaseGraphic");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBaseGraphic::FZZOFDBaseGraphic(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
,m_FZZOFDClips(NULL),m_FZZOFDActions(NULL)
{
    FZZConst::addClassCount("FZZOFDBaseGraphic");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBaseGraphic::FZZOFDBaseGraphic(const FZZOFDBaseGraphic& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDBaseGraphic");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDClips = obj.m_FZZOFDClips != NULL ? new FZZOFDClips(*obj.m_FZZOFDClips) : NULL;
    m_FZZOFDActions = obj.m_FZZOFDActions != NULL ? new FZZOFDActions(*obj.m_FZZOFDActions) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBaseGraphic::~FZZOFDBaseGraphic()
{
    //DLOG("~FZZOFDBaseGraphic()");
    FZZConst::delClassCount("FZZOFDBaseGraphic");
    if ( m_FZZOFDClips != NULL ) {
        delete m_FZZOFDClips;
        m_FZZOFDClips = NULL;
    }
    if ( m_FZZOFDActions != NULL ) {
        delete m_FZZOFDActions;
        m_FZZOFDActions = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setBoundary(string value)
{
    setAttribute_String("Boundary",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDBaseGraphic::getBoundary()
{
    return getAttribute_String("Boundary");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setBoundary(double x, double y,double width, double height)
{
    string strValue;
    ST_Box_ToString(x,y,width,height,strValue);
    setAttribute_String("Boundary",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::getBoundary(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    string strid = getAttribute_String("Boundary");
    ST_Box_ToDouble(strid, x,y,width,height);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setName(string value)
{
    setAttribute_String("Name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDBaseGraphic::getName()
{
    return getAttribute_String("Name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setVisible(bool value)
{
    setAttribute_Bool("Visible",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDBaseGraphic::getVisible()
{
    return getAttribute_Bool("Visible",true);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setCTM(string value)
{
    if ( !value.empty() ) {
        setAttribute_String("CTM",value);
    }
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDBaseGraphic::getCTM()
{
    return getAttribute_String("CTM");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setCTM(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setAttribute_String("CTM",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::getCTM(/*out*/vector<string> & array)
{
    string strid = getAttribute_String("CTM");
    ST_Array_ToArray(strid, array);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::getCTM(/*out*/vector<double> & array)
{
    string strid = getAttribute_String("CTM");
    ST_Array_ToArray(strid, array);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setDrawParam(long value)
{
    setAttribute_long("DrawParam",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDBaseGraphic::getDrawParam()
{
    return getAttribute_long("DrawParam");
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDBaseGraphic::getDrawParam_String()
{
    return getAttribute_String("DrawParam");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setLineWidth(double value)
{
    setAttribute_double("LineWidth",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDBaseGraphic::getLineWidth()
{
    return getAttribute_double("LineWidth");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setCap(FZZOFDLineCapType::TYPE type)
{
    setAttribute_String("Cap",FZZOFDLineCapType::toString(type));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLineCapType::TYPE FZZOFDBaseGraphic::getCap()
{
    return FZZOFDLineCapType::toType(getAttribute_String("Cap").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setJoin(FZZOFDLineJoinType::TYPE type)
{
    setAttribute_String("Join",FZZOFDLineJoinType::toString(type));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLineJoinType::TYPE FZZOFDBaseGraphic::getJoin()
{
    return FZZOFDLineJoinType::toType(getAttribute_String("Join").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setMiterLimit(double value)
{
    setAttribute_double("MiterLimit",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDBaseGraphic::getMiterLimit()
{
    return getAttribute_double("MiterLimit");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setDashOffset(double value)
{
    setAttribute_double("DashOffset",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDBaseGraphic::getDashOffset()
{
    return getAttribute_double("DashOffset");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setDashPattern(string value)
{
    setAttribute_String("DashPattern",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDBaseGraphic::getDashPattern()
{
    return getAttribute_String("DashPattern");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setDashPattern(const vector<string> & array)
{
    string strValue;
    ST_Array_ToString(array,strValue);
    setAttribute_String("DashPattern",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::getDashPattern(/*out*/vector<double> & array)
{
    string strid = getAttribute_String("DashPattern");
    ST_Array_ToArray(strid, array);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDBaseGraphic::setAlpha(int value)
{
    if (value < 0) {
        value = 0;
    }
    if (value > 255) {
        value = 255;
    }
    setAttribute_Int("Alpha",value);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDBaseGraphic::getAlpha()
{
    //return getAttribute_Int("Alpha");
    //int
    string strAlpha = getAttribute_String("Alpha");
    if ( strAlpha.empty() ) {
        return 255;
    } else {
        return (int)strtol(strAlpha.c_str(),NULL,10);
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClips * FZZOFDBaseGraphic::setClips()
{
    return m_FZZOFDClips = setElementObject(m_FZZOFDClips,FZZOFDCLIPS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClips * FZZOFDBaseGraphic::getClips()
{
    return m_FZZOFDClips = getElementObject(m_FZZOFDClips,FZZOFDCLIPS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions * FZZOFDBaseGraphic::setActions()
{
    return m_FZZOFDActions = setElementObject(m_FZZOFDActions,FZZOFDACTIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDActions * FZZOFDBaseGraphic::getActions()
{
    return m_FZZOFDActions = getElementObject(m_FZZOFDActions,FZZOFDACTIONS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
