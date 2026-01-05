//
//  Created by zizheng fan on 2023/11/27
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWHyperlink.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWHyperlink**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWHyperlink::FZZWHyperlink() : FZZXMLElementObject(),m_FZZWR(NULL)
{
    //DLOG("FZZWHyperlink()");
    FZZConst::addClassCount("FZZWHyperlink");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWHyperlink::FZZWHyperlink(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZWR(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWHyperlink");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWHyperlink::FZZWHyperlink(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWR(NULL)
{
    FZZConst::addClassCount("FZZWHyperlink");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWHyperlink::FZZWHyperlink(const FZZWHyperlink& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWHyperlink");
    if ( this == &obj ) {
        return;
    }

    m_FZZWR = obj.m_FZZWR != NULL ? new FZZWR(*obj.m_FZZWR) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWHyperlink::~FZZWHyperlink()
{
    //DLOG("~FZZWHyperlink()");
    FZZConst::delClassCount("FZZWHyperlink");
    if ( m_FZZWR != NULL ) {
        delete m_FZZWR;
        m_FZZWR = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWHyperlink::setID(string value)
{
    setAttribute_String("r:id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWHyperlink::getID()
{
    string retstr = getAttribute_String("r:id");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWHyperlink::setTgtFrame(string value)
{
    setAttribute_String("w:tgtFrame",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWHyperlink::getTgtFrame()
{
    string retstr = getAttribute_String("w:tgtFrame");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWHyperlink::setHistory(string value)
{
    setAttribute_String("w:history",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZWHyperlink::getHistory()
{
    string retstr = getAttribute_String("w:history");
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWR * FZZWHyperlink::setR()
{
    return m_FZZWR = setElementObject(m_FZZWR,FZZWR_Find_Key,FZZWR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWR * FZZWHyperlink::getR()
{
    return m_FZZWR = getElementObject(m_FZZWR,FZZWR_Find_Key,FZZWR_Name);
}
//-----------------------------------------------------------------------------------------------------------------
