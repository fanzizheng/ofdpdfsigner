//
//  Created by zizheng fan on 2023/09/15
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCompat.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWCompat**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWCompat::FZZWCompat() : FZZXMLElementObject(),m_FZZWUseFELayout(NULL),m_FZZWUlTrailSpace(NULL),m_FZZWSpaceForUL(NULL),m_FZZWDoNotLeaveBackslashAlone(NULL),m_FZZWDoNotExpandShiftReturn(NULL),m_FZZWBalanceSingleByteDoubleByteWidth(NULL),m_FZZWAdjustLineHeightInTable(NULL)
{
    //DLOG("FZZWCompat()");
    FZZConst::addClassCount("FZZWCompat");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompat::FZZWCompat(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWUseFELayout(NULL),m_FZZWUlTrailSpace(NULL),m_FZZWSpaceForUL(NULL),m_FZZWDoNotLeaveBackslashAlone(NULL),m_FZZWDoNotExpandShiftReturn(NULL),m_FZZWBalanceSingleByteDoubleByteWidth(NULL),m_FZZWAdjustLineHeightInTable(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWCompat");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompat::FZZWCompat(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWUseFELayout(NULL),m_FZZWUlTrailSpace(NULL),m_FZZWSpaceForUL(NULL),m_FZZWDoNotLeaveBackslashAlone(NULL),m_FZZWDoNotExpandShiftReturn(NULL),m_FZZWBalanceSingleByteDoubleByteWidth(NULL),m_FZZWAdjustLineHeightInTable(NULL)
{
    FZZConst::addClassCount("FZZWCompat");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompat::FZZWCompat(const FZZWCompat& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWCompat");
    if ( this == &obj ) {
        return;
    }
    m_FZZWUseFELayout = obj.m_FZZWUseFELayout != NULL ? new FZZWUseFELayout(*obj.m_FZZWUseFELayout) : NULL;
    m_FZZWUlTrailSpace = obj.m_FZZWUlTrailSpace != NULL ? new FZZWUlTrailSpace(*obj.m_FZZWUlTrailSpace) : NULL;
    m_FZZWSpaceForUL = obj.m_FZZWSpaceForUL != NULL ? new FZZWSpaceForUL(*obj.m_FZZWSpaceForUL) : NULL;
    m_FZZWDoNotLeaveBackslashAlone = obj.m_FZZWDoNotLeaveBackslashAlone != NULL ? new FZZWDoNotLeaveBackslashAlone(*obj.m_FZZWDoNotLeaveBackslashAlone) : NULL;
    m_FZZWDoNotExpandShiftReturn = obj.m_FZZWDoNotExpandShiftReturn != NULL ? new FZZWDoNotExpandShiftReturn(*obj.m_FZZWDoNotExpandShiftReturn) : NULL;
    m_FZZWBalanceSingleByteDoubleByteWidth = obj.m_FZZWBalanceSingleByteDoubleByteWidth != NULL ? new FZZWBalanceSingleByteDoubleByteWidth(*obj.m_FZZWBalanceSingleByteDoubleByteWidth) : NULL;
    m_FZZWAdjustLineHeightInTable = obj.m_FZZWAdjustLineHeightInTable != NULL ? new FZZWAdjustLineHeightInTable(*obj.m_FZZWAdjustLineHeightInTable) : NULL;
    vector<FZZWCompatSetting*>::const_iterator itr;
    for( itr = obj.m_FZZWCompatSettings.begin(); itr != obj.m_FZZWCompatSettings.end(); itr++ ) {
        FZZWCompatSetting * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWCompatSettings.push_back(new FZZWCompatSetting(*temp));
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompat::~FZZWCompat()
{
    //DLOG("~FZZWCompat()");
    FZZConst::delClassCount("FZZWCompat");
    if ( m_FZZWUseFELayout != NULL ) {
        delete m_FZZWUseFELayout;
        m_FZZWUseFELayout = NULL;
    }
    if ( m_FZZWUlTrailSpace != NULL ) {
        delete m_FZZWUlTrailSpace;
        m_FZZWUlTrailSpace = NULL;
    }
    if ( m_FZZWSpaceForUL != NULL ) {
        delete m_FZZWSpaceForUL;
        m_FZZWSpaceForUL = NULL;
    }
    if ( m_FZZWDoNotLeaveBackslashAlone != NULL ) {
        delete m_FZZWDoNotLeaveBackslashAlone;
        m_FZZWDoNotLeaveBackslashAlone = NULL;
    }
    if ( m_FZZWDoNotExpandShiftReturn != NULL ) {
        delete m_FZZWDoNotExpandShiftReturn;
        m_FZZWDoNotExpandShiftReturn = NULL;
    }
    if ( m_FZZWBalanceSingleByteDoubleByteWidth != NULL ) {
        delete m_FZZWBalanceSingleByteDoubleByteWidth;
        m_FZZWBalanceSingleByteDoubleByteWidth = NULL;
    }
    if ( m_FZZWAdjustLineHeightInTable != NULL ) {
        delete m_FZZWAdjustLineHeightInTable;
        m_FZZWAdjustLineHeightInTable = NULL;
    }
    
    vector<FZZWCompatSetting*>::const_iterator itr;
    for( itr = m_FZZWCompatSettings.begin(); itr != m_FZZWCompatSettings.end(); itr++ ) {
        FZZWCompatSetting * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWCompatSettings.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWCompatSetting * FZZWCompat::addCompatSetting()
{
    return addElementObject(&m_FZZWCompatSettings,FZZWCOMPATSETTING_Find_Key,FZZWCOMPATSETTING_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWCompatSetting*> * FZZWCompat::getCompatSettings()
{
    getElementObjectList(&m_FZZWCompatSettings,FZZWCOMPATSETTING_Find_Key,FZZWCOMPATSETTING_Name);
    return &m_FZZWCompatSettings;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUseFELayout * FZZWCompat::setUseFELayout()
{
    return m_FZZWUseFELayout = setElementObject(m_FZZWUseFELayout,FZZWUSEFELAYOUT_Find_Key,FZZWUSEFELAYOUT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUseFELayout * FZZWCompat::getUseFELayout()
{
    return m_FZZWUseFELayout = getElementObject(m_FZZWUseFELayout,FZZWUSEFELAYOUT_Find_Key,FZZWUSEFELAYOUT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUlTrailSpace * FZZWCompat::setUlTrailSpace()
{
    return m_FZZWUlTrailSpace = setElementObject(m_FZZWUlTrailSpace,FZZWULTRAILSPACE_Find_Key,FZZWULTRAILSPACE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWUlTrailSpace * FZZWCompat::getUlTrailSpace()
{
    return m_FZZWUlTrailSpace = getElementObject(m_FZZWUlTrailSpace,FZZWULTRAILSPACE_Find_Key,FZZWULTRAILSPACE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpaceForUL * FZZWCompat::setSpaceForUL()
{
    return m_FZZWSpaceForUL = setElementObject(m_FZZWSpaceForUL,FZZWSPACEFORUL_Find_Key,FZZWSPACEFORUL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSpaceForUL * FZZWCompat::getSpaceForUL()
{
    return m_FZZWSpaceForUL = getElementObject(m_FZZWSpaceForUL,FZZWSPACEFORUL_Find_Key,FZZWSPACEFORUL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotLeaveBackslashAlone * FZZWCompat::setDoNotLeaveBackslashAlone()
{
    return m_FZZWDoNotLeaveBackslashAlone = setElementObject(m_FZZWDoNotLeaveBackslashAlone,FZZWDONOTLEAVEBACKSLASHALONE_Find_Key,FZZWDONOTLEAVEBACKSLASHALONE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotLeaveBackslashAlone * FZZWCompat::getDoNotLeaveBackslashAlone()
{
    return m_FZZWDoNotLeaveBackslashAlone = getElementObject(m_FZZWDoNotLeaveBackslashAlone,FZZWDONOTLEAVEBACKSLASHALONE_Find_Key,FZZWDONOTLEAVEBACKSLASHALONE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotExpandShiftReturn * FZZWCompat::setDoNotExpandShiftReturn()
{
    return m_FZZWDoNotExpandShiftReturn = setElementObject(m_FZZWDoNotExpandShiftReturn,FZZWDONOTEXPANDSHIFTRETURN_Find_Key,FZZWDONOTEXPANDSHIFTRETURN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWDoNotExpandShiftReturn * FZZWCompat::getDoNotExpandShiftReturn()
{
    return m_FZZWDoNotExpandShiftReturn = getElementObject(m_FZZWDoNotExpandShiftReturn,FZZWDONOTEXPANDSHIFTRETURN_Find_Key,FZZWDONOTEXPANDSHIFTRETURN_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBalanceSingleByteDoubleByteWidth * FZZWCompat::setBalanceSingleByteDoubleByteWidth()
{
    return m_FZZWBalanceSingleByteDoubleByteWidth = setElementObject(m_FZZWBalanceSingleByteDoubleByteWidth,FZZWBALANCESINGLEBYTEDOUBLEBYTEWIDTH_Find_Key,FZZWBALANCESINGLEBYTEDOUBLEBYTEWIDTH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBalanceSingleByteDoubleByteWidth * FZZWCompat::getBalanceSingleByteDoubleByteWidth()
{
    return m_FZZWBalanceSingleByteDoubleByteWidth = getElementObject(m_FZZWBalanceSingleByteDoubleByteWidth,FZZWBALANCESINGLEBYTEDOUBLEBYTEWIDTH_Find_Key,FZZWBALANCESINGLEBYTEDOUBLEBYTEWIDTH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAdjustLineHeightInTable * FZZWCompat::setAdjustLineHeightInTable()
{
    return m_FZZWAdjustLineHeightInTable = setElementObject(m_FZZWAdjustLineHeightInTable,FZZWADJUSTLINEHEIGHTINTABLE_Find_Key,FZZWADJUSTLINEHEIGHTINTABLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAdjustLineHeightInTable * FZZWCompat::getAdjustLineHeightInTable()
{
    return m_FZZWAdjustLineHeightInTable = getElementObject(m_FZZWAdjustLineHeightInTable,FZZWADJUSTLINEHEIGHTINTABLE_Find_Key,FZZWADJUSTLINEHEIGHTINTABLE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
