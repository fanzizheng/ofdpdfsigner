//
//  Created by zizheng fan on 2024/03/04.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlock.h"
#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCellContent.h"
//#include "ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAppearance.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLayer.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCompositeObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDImageObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPathObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTextObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPageBlock**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageBlock::FZZOFDPageBlock() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPageBlock()");
    FZZConst::addClassCount("FZZOFDPageBlock");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageBlock::FZZOFDPageBlock(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDPageBlock");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageBlock::FZZOFDPageBlock(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPageBlock");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageBlock::FZZOFDPageBlock(const FZZOFDPageBlock& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPageBlock");
    if ( this == &obj ) {
        return;
    }
    
    FZZOFDPageBlockType * ofdPageBlockType = NULL;
    vector<FZZOFDPageBlockType*>::const_iterator itr;
    for( itr = obj.m_PageBlockTypes.begin(); itr != obj.m_PageBlockTypes.end(); itr++ ) {
        FZZOFDPageBlockType * temp = *itr;
        if ( temp != NULL ) {
            ofdPageBlockType = Copy_PageBlockType(temp);
            if ( ofdPageBlockType != NULL ) {
                m_PageBlockTypes.push_back(ofdPageBlockType);
            }
        
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageBlock::~FZZOFDPageBlock()
{
    //DLOG("~FZZOFDPageBlock()");
    FZZConst::delClassCount("FZZOFDPageBlock");
    
    vector<FZZOFDPageBlockType*>::const_iterator itr;
    for( itr = m_PageBlockTypes.begin(); itr != m_PageBlockTypes.end(); itr++ ) {
        FZZOFDPageBlockType * temp = *itr;
        if ( temp != NULL ) {
            Delete_PageBlockType(temp);
        }
    }
    m_PageBlockTypes.clear();
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageBlock::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDPageBlock::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageBlock::setID(long value)
{
    
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDPageBlock::getID_long()
{
    return getAttribute_long("ID");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageBlock::setBoundary(string value)
{
    setAttribute_String("Boundary",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDPageBlock::getBoundary()
{
    return getAttribute_String("Boundary");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageBlock::setBoundary(double x, double y,double width, double height)
{
    string strValue;
    ST_Box_ToString(x,y,width,height,strValue);
    setAttribute_String("Boundary",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageBlock::getBoundary(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    string strid = getAttribute_String("Boundary");
    ST_Box_ToDouble(strid, x,y,width,height);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageBlockType* FZZOFDPageBlock::addPageBlock(FZZOFDPageBlockType::TYPE type)
{
    
    FZZOFDPageBlockType* temp = NULL;
  
    switch(type) {
        case FZZOFDPageBlockType::TYPE::TYPE_PageBlock:
            temp = (FZZOFDPageBlockType*)addElementObject_NoAddList((FZZOFDPageBlock*)NULL,FZZOFDPAGEBLOCK_Name);
            break;
        case FZZOFDPageBlockType::TYPE::TYPE_Layer:
            temp = (FZZOFDPageBlockType*)addElementObject_NoAddList((FZZOFDLayer*)NULL,FZZOFDLAYER_Name);
            break;
        case FZZOFDPageBlockType::TYPE::TYPE_CellContent:
            temp = (FZZOFDPageBlockType*)addElementObject_NoAddList((FZZOFDCellContent*)NULL,FZZOFDCELLCONTENT_Name);
            break;
        case FZZOFDPageBlockType::TYPE::TYPT_CompositeObject:
            temp = (FZZOFDPageBlockType*)addElementObject_NoAddList((FZZOFDCompositeObject*)NULL,FZZOFDCOMPOSITEOBJECT_Name);
            break;
        case FZZOFDPageBlockType::TYPE::TYPT_ImageObject:
            temp = (FZZOFDPageBlockType*)addElementObject_NoAddList((FZZOFDImageObject*)NULL,FZZOFDIMAGEOBJECT_Name);
            break;
        case FZZOFDPageBlockType::TYPE::TYPT_PathObject:
            temp = (FZZOFDPageBlockType*)addElementObject_NoAddList((FZZOFDPathObject*)NULL,FZZOFDPATHOBJECT_Name);
            break;
        case FZZOFDPageBlockType::TYPE::TYPT_TextObject:
            temp = (FZZOFDPageBlockType*)addElementObject_NoAddList((FZZOFDTextObject*)NULL,FZZOFDTEXTOBJECT_Name);
            break;
    }
    
    
    if ( temp != NULL ) {
        m_PageBlockTypes.push_back(temp);
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDPageBlockType* >* FZZOFDPageBlock::getPageBlockList()
{
    if ( m_PageBlockTypes.size() <= 0 ) {
        XMLElement* ele = m_ofd_Node->FirstChildElement();
        while (ele != NULL) {
            const char* elename = ele->Name();
            FZZOFDPageBlockType * tempObject = NULL;
            
            if (strcmp(elename, FZZOFDCELLCONTENT_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDCellContent*)NULL);
            } else if (strcmp(elename, FZZOFDLAYER_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDLayer*)NULL);
            } else if (strcmp(elename, FZZOFDPAGEBLOCK_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDPageBlock*)NULL);
            } else if (strcmp(elename, FZZOFDCOMPOSITEOBJECT_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDCompositeObject*)NULL);
            } else if (strcmp(elename, FZZOFDIMAGEOBJECT_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDImageObject*)NULL);
            } else if (strcmp(elename, FZZOFDPATHOBJECT_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDPathObject*)NULL);
            } else if (strcmp(elename, FZZOFDTEXTOBJECT_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDTextObject*)NULL);
            }
            
            if ( tempObject != NULL ) {
                m_PageBlockTypes.push_back(tempObject);
            }

            ele = ele->NextSiblingElement();
        }//while
    }//if ( m_PageBlockTypes.size() <= 0 )
    
    return &m_PageBlockTypes;
}
//-----------------------------------------------------------------------------------------------------------------
