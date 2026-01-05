//
//  Created by zizheng fan on 2023/06/12
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPPositionV.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPPositionV**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionV::FZZWPPositionV() : FZZXMLElementObject(),m_FZZWPPosOffset(NULL)
{
    //DLOG("FZZWPPositionV()");
    FZZConst::addClassCount("FZZWPPositionV");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionV::FZZWPPositionV(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWPPosOffset(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPPositionV");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionV::FZZWPPositionV(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWPPosOffset(NULL)
{
    FZZConst::addClassCount("FZZWPPositionV");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionV::FZZWPPositionV(const FZZWPPositionV& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPPositionV");
    if ( this == &obj ) {
        return;
    }
    m_FZZWPPosOffset = obj.m_FZZWPPosOffset != NULL ? new FZZWPPosOffset(*obj.m_FZZWPPosOffset) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPositionV::~FZZWPPositionV()
{
    //DLOG("~FZZWPPositionV()");
    FZZConst::delClassCount("FZZWPPositionV");
    if ( m_FZZWPPosOffset != NULL ) {
        delete m_FZZWPPosOffset;
        m_FZZWPPosOffset = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPPositionV::setRelativeFrom(string value)
{
    setAttribute_String("relativeFrom",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWPPositionV::getRelativeFrom()
{
    return getAttribute_String("relativeFrom");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPosOffset * FZZWPPositionV::setPosOffset()
{
    return m_FZZWPPosOffset = setElementObject(m_FZZWPPosOffset,FZZWPPOSOFFSET_Find_Key,FZZWPPOSOFFSET_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPPosOffset * FZZWPPositionV::getPosOffset()
{
    return m_FZZWPPosOffset = getElementObject(m_FZZWPPosOffset,FZZWPPOSOFFSET_Find_Key,FZZWPPOSOFFSET_Name);
}
//-----------------------------------------------------------------------------------------------------------------

