//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPath.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPath**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPath::FZZOFDPath() : FZZOFDBaseGraphic(),m_FZZOFDFillColor(NULL),m_FZZOFDStrokeColor(NULL),m_FZZOFDAbbreviatedData(NULL)
{
    //DLOG("FZZOFDPath()");
    FZZConst::addClassCount("FZZOFDPath");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPath::FZZOFDPath(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDBaseGraphic(parent,doc,node,key)
,m_FZZOFDFillColor(NULL),m_FZZOFDStrokeColor(NULL),m_FZZOFDAbbreviatedData(NULL)
{
    
    FZZConst::addClassCount("FZZOFDPath");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPath::FZZOFDPath(FZZOFDXMLFileObject * parent) : FZZOFDBaseGraphic(parent)
,m_FZZOFDFillColor(NULL),m_FZZOFDStrokeColor(NULL),m_FZZOFDAbbreviatedData(NULL)
{
    FZZConst::addClassCount("FZZOFDPath");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPath::FZZOFDPath(const FZZOFDPath& obj) : FZZOFDBaseGraphic(obj)
{
    
    FZZConst::addClassCount("FZZOFDPath");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDFillColor = obj.m_FZZOFDFillColor != NULL ? new FZZOFDFillColor(*obj.m_FZZOFDFillColor) : NULL;
    m_FZZOFDStrokeColor = obj.m_FZZOFDStrokeColor != NULL ? new FZZOFDStrokeColor(*obj.m_FZZOFDStrokeColor) : NULL;
    m_FZZOFDAbbreviatedData = obj.m_FZZOFDAbbreviatedData != NULL ? new FZZOFDAbbreviatedData(*obj.m_FZZOFDAbbreviatedData) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPath::~FZZOFDPath()
{
    //DLOG("~FZZOFDPath()");
    FZZConst::delClassCount("FZZOFDPath");
    if ( m_FZZOFDFillColor != NULL ) {
        delete m_FZZOFDFillColor;
        m_FZZOFDFillColor = NULL;
    }
    if ( m_FZZOFDStrokeColor != NULL ) {
        delete m_FZZOFDStrokeColor;
        m_FZZOFDStrokeColor = NULL;
    }
    if ( m_FZZOFDAbbreviatedData != NULL ) {
        delete m_FZZOFDAbbreviatedData;
        m_FZZOFDAbbreviatedData = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPath::setStroke(bool value)
{
    setAttribute_Bool("Stroke",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDPath::getStroke()
{
    return getAttribute_Bool("Stroke",true);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPath::setFill(bool value)
{
    setAttribute_Bool("Fill",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDPath::getFill()
{
    return getAttribute_Bool("Fill",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPath::setRule(FZZOFDRule::TYPE rule)
{
    setAttribute_String("Rule",FZZOFDRule::toString(rule));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRule::TYPE FZZOFDPath::getRule()
{
    return FZZOFDRule::toType( getAttribute_String("Rule").c_str() );
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFillColor * FZZOFDPath::setFillColor()
{
    return m_FZZOFDFillColor = setElementObject(m_FZZOFDFillColor,FZZOFDFILLCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFillColor * FZZOFDPath::getFillColor()
{
    return m_FZZOFDFillColor = getElementObject(m_FZZOFDFillColor,FZZOFDFILLCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStrokeColor * FZZOFDPath::setStrokeColor()
{
    return m_FZZOFDStrokeColor = setElementObject(m_FZZOFDStrokeColor,FZZOFDSTROKECOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStrokeColor * FZZOFDPath::getStrokeColor()
{
    return m_FZZOFDStrokeColor = getElementObject(m_FZZOFDStrokeColor,FZZOFDSTROKECOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbbreviatedData * FZZOFDPath::setAbbreviatedData()
{
    return m_FZZOFDAbbreviatedData = setElementObject(m_FZZOFDAbbreviatedData,FZZOFDABBREVIATEDDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAbbreviatedData * FZZOFDPath::getAbbreviatedData()
{
    return m_FZZOFDAbbreviatedData = getElementObject(m_FZZOFDAbbreviatedData,FZZOFDABBREVIATEDDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
