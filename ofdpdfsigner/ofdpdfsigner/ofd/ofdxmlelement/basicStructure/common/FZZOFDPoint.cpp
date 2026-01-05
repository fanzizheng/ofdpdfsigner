//
//  Created by zizheng fan on 2024/03/04.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPoint.h"
#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDColor.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPoint**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPoint::FZZOFDPoint() : FZZOFDXMLElementObject(),m_FZZOFDColor(NULL)
{
    //DLOG("FZZOFDPoint()");
    FZZConst::addClassCount("FZZOFDPoint");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPoint::FZZOFDPoint(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDColor(NULL)
{
    
    FZZConst::addClassCount("FZZOFDPoint");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPoint::FZZOFDPoint(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDColor(NULL)
{
    FZZConst::addClassCount("FZZOFDPoint");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPoint::FZZOFDPoint(const FZZOFDPoint& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPoint");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDColor = obj.m_FZZOFDColor != NULL ? new FZZOFDColor(*obj.m_FZZOFDColor) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPoint::~FZZOFDPoint()
{
    //DLOG("~FZZOFDPoint()");
    FZZConst::delClassCount("FZZOFDPoint");
    if ( m_FZZOFDColor != NULL ) {
        delete m_FZZOFDColor;
        m_FZZOFDColor = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor * FZZOFDPoint::setColor()
{
    return m_FZZOFDColor = setElementObject(m_FZZOFDColor,FZZOFDCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColor * FZZOFDPoint::getColor()
{
    return m_FZZOFDColor = getElementObject(m_FZZOFDColor,FZZOFDCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPoint::setEdgeFlag(FZZOFDPoint::TYPE type)
{
    string temp = "0";
    switch (type) {
    case TYPE_0:
        temp = "0";
        break;
    case TYPE_1:
        temp = "1";
        break;
    case TYPE_2:
        temp = "2";
        break;
    }
    
    setAttribute_String("EdgeFlag",temp);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPoint::TYPE FZZOFDPoint::getEdgeFlag()
{
    string strType = getAttribute_String("EdgeFlag");
    FZZOFDPoint::TYPE temp = TYPE_0;
    if (strType == "0") {
        temp = TYPE_0;
    } else if (strType == "1") {
        temp = TYPE_1;
    }
    else if (strType == "2") {
        temp = TYPE_2;
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPoint::setX(double value)
{
    setAttribute_double("X",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDPoint::getX()
{
    return getAttribute_double("X");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPoint::setY(double value)
{
    setAttribute_double("Y",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDPoint::getY()
{
    return getAttribute_double("Y");
}
//-----------------------------------------------------------------------------------------------------------------
