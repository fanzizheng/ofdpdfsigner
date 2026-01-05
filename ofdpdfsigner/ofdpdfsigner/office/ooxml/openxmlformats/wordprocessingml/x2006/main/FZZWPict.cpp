//
//  Created by zizheng fan on 2023/11/08
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPict.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWPict**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWPict::FZZWPict() : FZZXMLElementObject(),m_DocXDir(NULL)
{
    //DLOG("FZZWPict()");
    FZZConst::addClassCount("FZZWPict");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPict::FZZWPict(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_DocXDir(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWPict");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPict::FZZWPict(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_DocXDir(NULL)
{
    FZZConst::addClassCount("FZZWPict");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPict::FZZWPict(const FZZWPict& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWPict");
    if ( this == &obj ) {
        return;
    }
    
    m_DocXDir = obj.m_DocXDir;
    
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
    
    vector<FZZVRect*>::const_iterator FZZVRect_itr;
    for( FZZVRect_itr = obj.m_FZZVRects.begin(); FZZVRect_itr != obj.m_FZZVRects.end(); FZZVRect_itr++ ) {
        FZZVRect * temp = *FZZVRect_itr;
        if ( temp != NULL ) {
            m_FZZVRects.push_back(new FZZVRect(*temp));
        }
    }
    
    
    vector<FZZVShapeType*>::const_iterator FZZVShapeType_itr;
    for( FZZVShapeType_itr = obj.m_FZZVShapeTypes.begin(); FZZVShapeType_itr != obj.m_FZZVShapeTypes.end(); FZZVShapeType_itr++ ) {
        FZZVShapeType * temp = *FZZVShapeType_itr;
        if ( temp != NULL ) {
            m_FZZVShapeTypes.push_back(new FZZVShapeType(*temp));
        }
    }
    
    vector<FZZVGroup*>::const_iterator FZZVGroup_itr;
    for( FZZVGroup_itr = obj.m_FZZVGroups.begin(); FZZVGroup_itr != obj.m_FZZVGroups.end(); FZZVGroup_itr++ ) {
        FZZVGroup * temp = *FZZVGroup_itr;
        if ( temp != NULL ) {
            m_FZZVGroups.push_back(new FZZVGroup(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWPict::~FZZWPict()
{
    //DLOG("~FZZWPict()");
    FZZConst::delClassCount("FZZWPict");
    
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
    
    vector<FZZVRect*>::const_iterator FZZVRect_itr;
    for( FZZVRect_itr = m_FZZVRects.begin(); FZZVRect_itr != m_FZZVRects.end(); FZZVRect_itr++ ) {
        FZZVRect * temp = *FZZVRect_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZVRects.clear();

    vector<FZZVShapeType*>::const_iterator FZZVShapeType_itr;
    for( FZZVShapeType_itr = m_FZZVShapeTypes.begin(); FZZVShapeType_itr != m_FZZVShapeTypes.end(); FZZVShapeType_itr++ ) {
        FZZVShapeType * temp = *FZZVShapeType_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZVShapeTypes.clear();
    
    vector<FZZVGroup*>::const_iterator FZZVGroup_itr;
    for( FZZVGroup_itr = m_FZZVGroups.begin(); FZZVGroup_itr != m_FZZVGroups.end(); FZZVGroup_itr++ ) {
        FZZVGroup * temp = *FZZVGroup_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZVGroups.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZVLine * FZZWPict::addLine()
{
    return addElementObject(&m_FZZVLines,FZZVLINE_Find_Key,FZZVLINE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZVLine*> * FZZWPict::getLineList()
{
    getElementObjectList(&m_FZZVLines,FZZVLINE_Find_Key,FZZVLINE_Name);
    return &m_FZZVLines;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWPict::setDocXDir(FZZDocXDir * docXDir)
{
    m_DocXDir = docXDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShape * FZZWPict::addShape()
{
    return addElementObject(&m_FZZVShapes,FZZVSHAPE_Find_Key,FZZVSHAPE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZVShape*> * FZZWPict::getShapeList()
{
    getElementObjectList(&m_FZZVShapes,FZZVSHAPE_Find_Key,FZZVSHAPE_Name);
    return &m_FZZVShapes;
}
//-----------------------------------------------------------------------------------------------------------------
FZZVRect * FZZWPict::addRect()
{
    return addElementObject(&m_FZZVRects,FZZVRECT_Find_Key,FZZVRECT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZVRect*> * FZZWPict::getRectList()
{
    getElementObjectList(&m_FZZVRects,FZZVRECT_Find_Key,FZZVRECT_Name);
    return &m_FZZVRects;
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShapeType * FZZWPict::addShapeType()
{
    return addElementObject(&m_FZZVShapeTypes,FZZVSHAPETYPE_Find_Key,FZZVSHAPETYPE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZVShapeType*> * FZZWPict::getShapeTypeList()
{
    getElementObjectList(&m_FZZVShapeTypes,FZZVSHAPETYPE_Find_Key,FZZVSHAPETYPE_Name);
    return &m_FZZVShapeTypes;
}
//-----------------------------------------------------------------------------------------------------------------
FZZVGroup * FZZWPict::addGroup()
{
    return addElementObject(&m_FZZVGroups,FZZVGROUP_Find_Key,FZZVGROUP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZVGroup*> * FZZWPict::getGroupList()
{
    getElementObjectList(&m_FZZVGroups,FZZVGROUP_Find_Key,FZZVGROUP_Name);
    return &m_FZZVGroups;
}
//-----------------------------------------------------------------------------------------------------------------

