//
//  Created by zizheng fan on 2024/03/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCGTransform.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCGTransform**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCGTransform::FZZOFDCGTransform() : FZZOFDXMLElementObject(),m_FZZOFDGlyphs(NULL)
{
    //DLOG("FZZOFDCGTransform()");
    FZZConst::addClassCount("FZZOFDCGTransform");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCGTransform::FZZOFDCGTransform(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDGlyphs(NULL)
{
    
    FZZConst::addClassCount("FZZOFDCGTransform");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCGTransform::FZZOFDCGTransform(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDGlyphs(NULL)
{
    FZZConst::addClassCount("FZZOFDCGTransform");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCGTransform::FZZOFDCGTransform(const FZZOFDCGTransform& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDCGTransform");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDGlyphs = obj.m_FZZOFDGlyphs != NULL ? new FZZOFDGlyphs(*obj.m_FZZOFDGlyphs) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCGTransform::~FZZOFDCGTransform()
{
    //DLOG("~FZZOFDCGTransform()");
    FZZConst::delClassCount("FZZOFDCGTransform");
    if ( m_FZZOFDGlyphs != NULL ) {
        delete m_FZZOFDGlyphs;
        m_FZZOFDGlyphs = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCGTransform::setCodePosition(int value)
{
    setAttribute_Int("CodePosition",value);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDCGTransform::getCodePosition()
{
    return getAttribute_Int("CodePosition");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCGTransform::setCodeCount(int value)
{
    if ( value < 0 ) {
        value = 0;
    }
    setAttribute_Int("CodeCount",value);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDCGTransform::getCodeCount()
{
    return getAttribute_Int("CodeCount");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCGTransform::setGlyphCount(int value)
{
    if ( value < 0 ) {
        value = 0;
    }
    setAttribute_Int("GlyphCount",value);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDCGTransform::getGlyphCount()
{
    return getAttribute_Int("GlyphCount");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGlyphs * FZZOFDCGTransform::setGlyphs()
{
    return m_FZZOFDGlyphs = setElementObject(m_FZZOFDGlyphs,FZZOFDGLYPHS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGlyphs * FZZOFDCGTransform::getGlyphs()
{
    return m_FZZOFDGlyphs = getElementObject(m_FZZOFDGlyphs,FZZOFDGLYPHS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
