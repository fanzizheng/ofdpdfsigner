//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDText.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDText**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDText::FZZOFDText() : FZZOFDBaseGraphic(),m_FZZOFDFillColor(NULL),m_FZZOFDStrokeColor(NULL)
{
    //DLOG("FZZOFDText()");
    FZZConst::addClassCount("FZZOFDText");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDText::FZZOFDText(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDBaseGraphic(parent,doc,node,key)
,m_FZZOFDFillColor(NULL),m_FZZOFDStrokeColor(NULL)
{
    
    FZZConst::addClassCount("FZZOFDText");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDText::FZZOFDText(FZZOFDXMLFileObject * parent) : FZZOFDBaseGraphic(parent),m_FZZOFDFillColor(NULL),m_FZZOFDStrokeColor(NULL)
{
    FZZConst::addClassCount("FZZOFDText");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDText::FZZOFDText(const FZZOFDText& obj) : FZZOFDBaseGraphic(obj)
{
    
    FZZConst::addClassCount("FZZOFDText");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDFillColor = obj.m_FZZOFDFillColor != NULL ? new FZZOFDFillColor(*obj.m_FZZOFDFillColor) : NULL;
    m_FZZOFDStrokeColor = obj.m_FZZOFDStrokeColor != NULL ? new FZZOFDStrokeColor(*obj.m_FZZOFDStrokeColor) : NULL;
    
    vector<FZZOFDTextCode*>::const_iterator itr_tc;
    for( itr_tc = obj.m_FZZOFDTextCodes.begin(); itr_tc != obj.m_FZZOFDTextCodes.end(); itr_tc++ ) {
        FZZOFDTextCode * temp = *itr_tc;
        if ( temp != NULL ) {
            m_FZZOFDTextCodes.push_back(new FZZOFDTextCode(*temp));
        }
    }
    
    vector<FZZOFDCGTransform*>::const_iterator itr_cgt;
    for( itr_cgt = obj.m_FZZOFDCGTransforms.begin(); itr_cgt != obj.m_FZZOFDCGTransforms.end(); itr_cgt++ ) {
        FZZOFDCGTransform * temp = *itr_cgt;
        if ( temp != NULL ) {
            m_FZZOFDCGTransforms.push_back(new FZZOFDCGTransform(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDText::~FZZOFDText()
{
    //DLOG("~FZZOFDText()");
    FZZConst::delClassCount("FZZOFDText");
    if ( m_FZZOFDFillColor != NULL ) {
        delete m_FZZOFDFillColor;
        m_FZZOFDFillColor = NULL;
    }
    if ( m_FZZOFDStrokeColor != NULL ) {
        delete m_FZZOFDStrokeColor;
        m_FZZOFDStrokeColor = NULL;
    }
    
    vector<FZZOFDTextCode*>::const_iterator itr_tc;
    for( itr_tc = m_FZZOFDTextCodes.begin(); itr_tc != m_FZZOFDTextCodes.end(); itr_tc++ ) {
        FZZOFDTextCode * temp = *itr_tc;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDTextCodes.clear();
    
    vector<FZZOFDCGTransform*>::const_iterator itr_cgt;
    for( itr_cgt = m_FZZOFDCGTransforms.begin(); itr_cgt != m_FZZOFDCGTransforms.end(); itr_cgt++ ) {
        FZZOFDCGTransform * temp = *itr_cgt;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZOFDCGTransforms.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDText::setFont(string value)
{
    setAttribute_String("Font",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDText::getFont()
{
    return getAttribute_String("Font");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDText::setFont(long value)
{
    setAttribute_long("Font",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDText::getFont_long()
{
    return getAttribute_long("Font");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDText::setSize(double value)
{
    setAttribute_double("Size",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDText::getSize()
{
    return getAttribute_double("Size");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDText::setStroke(bool value)
{
    setAttribute_Bool("Stroke",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDText::getStroke()
{
    return getAttribute_Bool("Stroke",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDText::setFill(bool value)
{
    setAttribute_Bool("Fill",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDText::getFill()
{
    return getAttribute_Bool("Fill",true);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDText::setHScale(double value)
{
    setAttribute_double("HScale",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDText::getHScale()
{
    return getAttribute_double("HScale");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDText::setReadDirection(FZZOFDDirection::TYPE readDirection)
{
    setAttribute_String("ReadDirection",FZZOFDDirection::toString(readDirection));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDirection::TYPE FZZOFDText::getReadDirection()
{
    return FZZOFDDirection::toType(getAttribute_String("ReadDirection").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDText::setCharDirection(FZZOFDDirection::TYPE charDirection)
{
    setAttribute_String("CharDirection",FZZOFDDirection::toString(charDirection));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDirection::TYPE FZZOFDText::getCharDirection()
{
    return FZZOFDDirection::toType(getAttribute_String("CharDirection").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDText::setWeight(FZZOFDWeight::TYPE weight)
{
    setAttribute_String("Weight",FZZOFDWeight::toString(weight));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDWeight::TYPE FZZOFDText::getWeight()
{
    return FZZOFDWeight::toType(getAttribute_String("Weight").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDText::setItalic(bool value)
{
    setAttribute_Bool("Italic",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDText::getItalic()
{
    return getAttribute_Bool("Italic",false);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFillColor * FZZOFDText::setFillColor()
{
    return m_FZZOFDFillColor = setElementObject(m_FZZOFDFillColor,FZZOFDFILLCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFillColor * FZZOFDText::getFillColor()
{
    return m_FZZOFDFillColor = getElementObject(m_FZZOFDFillColor,FZZOFDFILLCOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStrokeColor * FZZOFDText::setStrokeColor()
{
    return m_FZZOFDStrokeColor = setElementObject(m_FZZOFDStrokeColor,FZZOFDSTROKECOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStrokeColor * FZZOFDText::getStrokeColor()
{
    return m_FZZOFDStrokeColor = getElementObject(m_FZZOFDStrokeColor,FZZOFDSTROKECOLOR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDTextCode * FZZOFDText::addTextCode()
{
    return addElementObject(&m_FZZOFDTextCodes,FZZOFDTEXTCODE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDTextCode*> * FZZOFDText::getTextCodeList()
{
    getElementObjectList(&m_FZZOFDTextCodes,FZZOFDTEXTCODE_Name);
    return &m_FZZOFDTextCodes;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCGTransform * FZZOFDText::addCGTransform()
{
    return addElementObject(&m_FZZOFDCGTransforms,FZZOFDCGTRANSFORM_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDCGTransform*> * FZZOFDText::getCGTransformList()
{
    getElementObjectList(&m_FZZOFDCGTransforms,FZZOFDCGTRANSFORM_Name);
    return &m_FZZOFDCGTransforms;
}
//-----------------------------------------------------------------------------------------------------------------
