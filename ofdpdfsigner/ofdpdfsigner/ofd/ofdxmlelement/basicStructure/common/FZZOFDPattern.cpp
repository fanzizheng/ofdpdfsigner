//
//  Created by zizheng fan on 2024/03/04.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPattern.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPattern**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPattern::FZZOFDPattern() : FZZOFDXMLElementObject(),m_FZZOFDCellContent(NULL)
{
    //DLOG("FZZOFDPattern()");
    FZZConst::addClassCount("FZZOFDPattern");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPattern::FZZOFDPattern(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
,m_FZZOFDCellContent(NULL)
{
    
    FZZConst::addClassCount("FZZOFDPattern");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPattern::FZZOFDPattern(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDCellContent(NULL)
{
    FZZConst::addClassCount("FZZOFDPattern");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPattern::FZZOFDPattern(const FZZOFDPattern& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPattern");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDCellContent = obj.m_FZZOFDCellContent != NULL ? new FZZOFDCellContent(*obj.m_FZZOFDCellContent) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPattern::~FZZOFDPattern()
{
    //DLOG("~FZZOFDPattern()");
    FZZConst::delClassCount("FZZOFDPattern");
    if ( m_FZZOFDCellContent != NULL ) {
        delete m_FZZOFDCellContent;
        m_FZZOFDCellContent = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPattern::setWidth(double value)
{
    setAttribute_double("Width",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDPattern::getWidth()
{
    return getAttribute_double("Width");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPattern::setHeight(double value)
{
    setAttribute_double("Height",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDPattern::getHeight()
{
    return getAttribute_double("Height");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPattern::setXStep(double value)
{
    setAttribute_double("XStep",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDPattern::getXStep()
{
    return getAttribute_double("XStep");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPattern::setYStep(double value)
{
    setAttribute_double("YStep",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDPattern::getYStep()
{
    return getAttribute_double("YStep");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPattern::setReflectMethod(ReflectMethod reflectMethod)
{
    string temp = "Normal";
    switch (reflectMethod) {
    case ReflectMethod::Normal:
        temp = "Normal";
        break;
    case ReflectMethod::Column:
        temp = "Column";
        break;
    case ReflectMethod::Row:
        temp = "Row";
        break;
    case ReflectMethod::RowAndColumn:
        temp = "RowAndColumn";
        break;
    default:
        temp = "Normal";
        break;
    }
    
    setAttribute_String("ReflectMethod",temp);
}
//-----------------------------------------------------------------------------------------------------------------
ReflectMethod FZZOFDPattern::getReflectMethod()
{
    string strType = getAttribute_String("ReflectMethod");
    ReflectMethod temp = ReflectMethod::Normal;
    if (strType == "Normal") {
        temp = ReflectMethod::Normal;
    }
    else if (strType == "Column") {
        temp = ReflectMethod::Column;
    }
    else if (strType == "RowAndColumn") {
        temp = ReflectMethod::RowAndColumn;
    }
    else if (strType == "Row") {
        temp = ReflectMethod::Row;
    }
    else {
        temp = ReflectMethod::Normal;
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPattern::setRelativeTo(RelativeTo relativeTo)
{
    string temp = "Page";
    switch (relativeTo) {
    case RelativeTo::RelativeTo_Page:
        temp = "Page";
        break;
    case RelativeTo::Object:
        temp = "Object";
        break;
    default:
        temp = "Page";
        break;
    }

    setAttribute_String("RelativeTo",temp);
}
//-----------------------------------------------------------------------------------------------------------------
RelativeTo FZZOFDPattern::getRelativeTo()
{
    string strType = getAttribute_String("RelativeTo");
    RelativeTo temp = RelativeTo::RelativeTo_Page;
    if (strType == "Page") {
        temp = RelativeTo::RelativeTo_Page;
    }
    else if (strType == "Object") {
        temp = RelativeTo::Object;
    }
    else {
        temp = RelativeTo::RelativeTo_Page;
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPattern::setCTM(string value)
{
    setAttribute_String("CTM",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDPattern::getCTM()
{
    return getAttribute_String("CTM");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCellContent * FZZOFDPattern::setCellContent()
{
    return m_FZZOFDCellContent = setElementObject(m_FZZOFDCellContent,FZZOFDCELLCONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCellContent * FZZOFDPattern::getCellContent()
{
    return m_FZZOFDCellContent = getElementObject(m_FZZOFDCellContent,FZZOFDCELLCONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
