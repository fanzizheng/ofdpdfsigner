//
//  Created by zizheng fan on 2023/04/18.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVShapeType.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVShapeType**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVShapeType::FZZVShapeType() : FZZXMLElementObject(),m_FZZVStroke(NULL),m_FZZVPath(NULL),m_FZZOLock(NULL),m_FZZVFormulas(NULL)
{
    //DLOG("FZZVShape()");
    FZZConst::addClassCount("FZZVShapeType");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShapeType::FZZVShapeType(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZVStroke(NULL),m_FZZVPath(NULL),m_FZZOLock(NULL),m_FZZVFormulas(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVShapeType");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShapeType::FZZVShapeType(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZVStroke(NULL),m_FZZVPath(NULL),m_FZZOLock(NULL),m_FZZVFormulas(NULL)
{
    FZZConst::addClassCount("FZZVShapeType");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShapeType::FZZVShapeType(const FZZVShapeType& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVShapeType");
    if ( this == &obj ) {
        return;
    }
    m_FZZVStroke = obj.m_FZZVStroke != NULL ? new FZZVStroke(*obj.m_FZZVStroke) : NULL;
    m_FZZOLock = obj.m_FZZOLock != NULL ? new FZZOLock(*obj.m_FZZOLock) : NULL;
    m_FZZVPath = obj.m_FZZVPath != NULL ? new FZZVPath(*obj.m_FZZVPath) : NULL;
    m_FZZVFormulas = obj.m_FZZVFormulas != NULL ? new FZZVFormulas(*obj.m_FZZVFormulas) : NULL;
    //m_FZZVImageData = obj.m_FZZVImageData != NULL ? new FZZVImageData(*obj.m_FZZVImageData) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShapeType::~FZZVShapeType()
{
    //DLOG("~FZZVShapeType()");
    FZZConst::delClassCount("FZZVShapeType");
    if ( m_FZZVStroke != NULL ) {
        delete m_FZZVStroke;
        m_FZZVStroke = NULL;
    }
    if ( m_FZZOLock != NULL ) {
        delete m_FZZOLock;
        m_FZZOLock = NULL;
    }
    if ( m_FZZVPath != NULL ) {
        delete m_FZZVPath;
        m_FZZVPath = NULL;
    }
    if ( m_FZZVFormulas != NULL ) {
        delete m_FZZVFormulas;
        m_FZZVFormulas = NULL;
    }
//    if ( m_FZZVImageData != NULL ) {
//        delete m_FZZVImageData;
//        m_FZZVImageData = NULL;
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShapeType::setId(string value)
{
    setAttribute_String("id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShapeType::getId()
{
    return getAttribute_String("id");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShapeType::setCoordSize(string value)
{
    setAttribute_String("coordsize",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShapeType::getCoordSize()
{
    return getAttribute_String("coordsize");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShapeType::setSpt(string value)
{
    setAttribute_String("o:spt",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShapeType::getSpt()
{
    return getAttribute_String("o:spt");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShapeType::setPreferrelative(string value)
{
    setAttribute_String("o:preferrelative",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShapeType::getPreferrelative()
{
    return getAttribute_String("o:preferrelative");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShapeType::setPath_Attribute(string value)
{
    setAttribute_String("path",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShapeType::getPath_Attribute()
{
    return getAttribute_String("path");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShapeType::setFilled(string value)
{
    setAttribute_String("filled",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShapeType::getFilled()
{
    return getAttribute_String("filled");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShapeType::setStroked(string value)
{
    setAttribute_String("stroked",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShapeType::getStroked()
{
    return getAttribute_String("stroked");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVStroke * FZZVShapeType::setStroke()
{
    return m_FZZVStroke = setElementObject(m_FZZVStroke,FZZVSTROKE_Find_Key,FZZVSTROKE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVStroke * FZZVShapeType::getStroke()
{
    return m_FZZVStroke = getElementObject(m_FZZVStroke,FZZVSTROKE_Find_Key,FZZVSTROKE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVPath * FZZVShapeType::setPath()
{
    return m_FZZVPath = setElementObject(m_FZZVPath,FZZVPATH_Find_Key,FZZVPATH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVPath * FZZVShapeType::getPath()
{
    return m_FZZVPath = getElementObject(m_FZZVPath,FZZVPATH_Find_Key,FZZVPATH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock * FZZVShapeType::setLock()
{
    return m_FZZOLock = setElementObject(m_FZZOLock,FZZOLOCK_Find_Key,FZZOLOCK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock * FZZVShapeType::getLock()
{
    return m_FZZOLock = getElementObject(m_FZZOLock,FZZOLOCK_Find_Key,FZZOLOCK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFormulas * FZZVShapeType::setFormulas()
{
    return m_FZZVFormulas = setElementObject(m_FZZVFormulas,FZZVFORMULAS_Find_Key,FZZVFORMULAS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFormulas * FZZVShapeType::getFormulas()
{
    return m_FZZVFormulas = getElementObject(m_FZZVFormulas,FZZVFORMULAS_Find_Key,FZZVFORMULAS_Name);
}
//-----------------------------------------------------------------------------------------------------------------

