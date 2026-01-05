//
//  Created by zizheng fan on 2024/02/02.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVGroup.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVGroup**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVGroup::FZZVGroup() : FZZXMLElementObject(),m_FZZOLock(NULL)
{
    //DLOG("FZZVGroup()");
    FZZConst::addClassCount("FZZVGroup");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVGroup::FZZVGroup(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZOLock(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVGroup");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVGroup::FZZVGroup(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZOLock(NULL)
{
    FZZConst::addClassCount("FZZVGroup");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVGroup::FZZVGroup(const FZZVGroup& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVGroup");
    if ( this == &obj ) {
        return;
    }
    
    vector<FZZVLine*>::const_iterator itr;
    for( itr = obj.m_FZZVLines.begin(); itr != obj.m_FZZVLines.end(); itr++ ) {
        FZZVLine * temp = *itr;
        if ( temp != NULL ) {
            m_FZZVLines.push_back(new FZZVLine(*temp));
        }
    }
    
    vector<FZZVShape*>::const_iterator FZZVShape_itr;
    for( FZZVShape_itr = obj.m_FZZVShapes.begin(); FZZVShape_itr != obj.m_FZZVShapes.end(); FZZVShape_itr++ ) {
        FZZVShape * temp = *FZZVShape_itr;
        if ( temp != NULL ) {
            m_FZZVShapes.push_back(new FZZVShape(*temp));
        }
    }
    
    vector<FZZVShapeType*>::const_iterator FZZVShapeType_itr;
    for( FZZVShapeType_itr = obj.m_FZZVShapeTypes.begin(); FZZVShapeType_itr != obj.m_FZZVShapeTypes.end(); FZZVShapeType_itr++ ) {
        FZZVShapeType * temp = *FZZVShapeType_itr;
        if ( temp != NULL ) {
            m_FZZVShapeTypes.push_back(new FZZVShapeType(*temp));
        }
    }
    
    m_FZZOLock = obj.m_FZZOLock != NULL ? new FZZOLock(*obj.m_FZZOLock) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVGroup::~FZZVGroup()
{
    //DLOG("~FZZVGroup()");
    FZZConst::delClassCount("FZZVGroup");
    
    vector<FZZVLine*>::const_iterator itr;
    for( itr = m_FZZVLines.begin(); itr != m_FZZVLines.end(); itr++ ) {
        FZZVLine * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZVLines.clear();
    
    vector<FZZVShape*>::const_iterator FZZVShape_itr;
    for( FZZVShape_itr = m_FZZVShapes.begin(); FZZVShape_itr != m_FZZVShapes.end(); FZZVShape_itr++ ) {
        FZZVShape * temp = *FZZVShape_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZVShapes.clear();
    
    vector<FZZVShapeType*>::const_iterator FZZVShapeType_itr;
    for( FZZVShapeType_itr = m_FZZVShapeTypes.begin(); FZZVShapeType_itr != m_FZZVShapeTypes.end(); FZZVShapeType_itr++ ) {
        FZZVShapeType * temp = *FZZVShapeType_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZVShapeTypes.clear();
    
    if ( m_FZZOLock != NULL ) {
        delete m_FZZOLock;
        m_FZZOLock = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZVLine * FZZVGroup::addLine()
{
    return addElementObject(&m_FZZVLines,FZZVLINE_Find_Key,FZZVLINE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZVLine*> * FZZVGroup::getLineList()
{
    getElementObjectList(&m_FZZVLines,FZZVLINE_Find_Key,FZZVLINE_Name);
    return &m_FZZVLines;
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShape * FZZVGroup::addShape()
{
    return addElementObject(&m_FZZVShapes,FZZVSHAPE_Find_Key,FZZVSHAPE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZVShape*> * FZZVGroup::getShapeList()
{
    getElementObjectList(&m_FZZVShapes,FZZVSHAPE_Find_Key,FZZVSHAPE_Name);
    return &m_FZZVShapes;
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShapeType * FZZVGroup::addShapeType()
{
    return addElementObject(&m_FZZVShapeTypes,FZZVSHAPETYPE_Find_Key,FZZVSHAPETYPE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZVShapeType*> * FZZVGroup::getShapeTypeList()
{
    getElementObjectList(&m_FZZVShapeTypes,FZZVSHAPETYPE_Find_Key,FZZVSHAPETYPE_Name);
    return &m_FZZVShapeTypes;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock * FZZVGroup::setLock()
{
    return m_FZZOLock = setElementObject(m_FZZOLock,FZZOLOCK_Find_Key,FZZOLOCK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock * FZZVGroup::getLock()
{
    return m_FZZOLock = getElementObject(m_FZZOLock,FZZOLOCK_Find_Key,FZZOLOCK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVGroup::setId(string value)
{
    setAttribute_String("id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVGroup::getId()
{
    return getAttribute_String("id");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVGroup::setSpId(string value)
{
    setAttribute_String("o:spid",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVGroup::getSpId()
{
    return getAttribute_String("o:spid");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVGroup::setStyle(string value)
{
    setAttribute_String("style",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVGroup::getStyle()
{
    return getAttribute_String("style");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVGroup::setCoordorigin(string value)
{
    setAttribute_String("coordorigin",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVGroup::getCoordorigin()
{
    return getAttribute_String("coordorigin");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVGroup::setCoordsize(string value)
{
    setAttribute_String("coordsize",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVGroup::getCoordsize()
{
    return getAttribute_String("coordsize");
}
//-----------------------------------------------------------------------------------------------------------------
