//
//  Created by zizheng fan on 2023/06/13
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPPositionH.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPPositionH**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionH::FZZWPPositionH() : FZZXMLElementObject(),m_FZZWPPosOffset(NULL),m_FZZWPAlign(NULL)
{
    //DLOG("FZZWPPositionH()");
    FZZConst::addClassCount("FZZWPPositionH");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionH::FZZWPPositionH(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWPPosOffset(NULL),m_FZZWPAlign(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPPositionH");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionH::FZZWPPositionH(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWPPosOffset(NULL),m_FZZWPAlign(NULL)
{
    FZZConst::addClassCount("FZZWPPositionH");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionH::FZZWPPositionH(const FZZWPPositionH& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPPositionH");
    if ( this == &obj ) {
        return;
    }
    m_FZZWPPosOffset = obj.m_FZZWPPosOffset != NULL ? new FZZWPPosOffset(*obj.m_FZZWPPosOffset) : NULL;
    m_FZZWPAlign = obj.m_FZZWPAlign != NULL ? new FZZWPAlign(*obj.m_FZZWPAlign) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionH::~FZZWPPositionH()
{
    //DLOG("~FZZWPPositionH()");
    FZZConst::delClassCount("FZZWPPositionH");
    if ( m_FZZWPPosOffset != NULL ) {
        delete m_FZZWPPosOffset;
        m_FZZWPPosOffset = NULL;
    }
    if ( m_FZZWPAlign != NULL ) {
        delete m_FZZWPAlign;
        m_FZZWPAlign = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPPositionH::setRelativeFrom(string value)
{
    setAttribute_String("relativeFrom",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPPositionH::getRelativeFrom()
{
    return getAttribute_String("relativeFrom");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPosOffset * FZZWPPositionH::setPosOffset()
{
    return m_FZZWPPosOffset = setElementObject(m_FZZWPPosOffset,FZZWPPOSOFFSET_Find_Key,FZZWPPOSOFFSET_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPosOffset * FZZWPPositionH::getPosOffset()
{
    return m_FZZWPPosOffset = getElementObject(m_FZZWPPosOffset,FZZWPPOSOFFSET_Find_Key,FZZWPPOSOFFSET_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAlign * FZZWPPositionH::setAlign()
{
    return m_FZZWPAlign = setElementObject(m_FZZWPAlign,FZZWPALIGN_Find_Key,FZZWPALIGN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPAlign * FZZWPPositionH::getAlign()
{
    return m_FZZWPAlign = getElementObject(m_FZZWPAlign,FZZWPALIGN_Find_Key,FZZWPALIGN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
