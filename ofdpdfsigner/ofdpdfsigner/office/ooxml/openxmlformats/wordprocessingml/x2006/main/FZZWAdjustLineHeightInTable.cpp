//
//  Created by zizheng fan on 2023/09/22
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAdjustLineHeightInTable.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWAdjustLineHeightInTable**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWAdjustLineHeightInTable::FZZWAdjustLineHeightInTable() : FZZXMLElementObject()
{
    //DLOG("FZZWAdjustLineHeightInTable()");
    FZZConst::addClassCount("FZZWAdjustLineHeightInTable");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAdjustLineHeightInTable::FZZWAdjustLineHeightInTable(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWAdjustLineHeightInTable");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAdjustLineHeightInTable::FZZWAdjustLineHeightInTable(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZWAdjustLineHeightInTable");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAdjustLineHeightInTable::FZZWAdjustLineHeightInTable(const FZZWAdjustLineHeightInTable& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWAdjustLineHeightInTable");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWAdjustLineHeightInTable::~FZZWAdjustLineHeightInTable()
{
    //DLOG("~FZZWAdjustLineHeightInTable()");
    FZZConst::delClassCount("FZZWAdjustLineHeightInTable");
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
