//
//  Created by zizheng fan on 2023/09/15
//
#ifndef FZZWCOMPAT_H
#define FZZWCOMPAT_H

#include "office/FZZXMLElementObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUseFELayout.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUlTrailSpace.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSpaceForUL.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDoNotLeaveBackslashAlone.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDoNotExpandShiftReturn.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCompatSetting.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBalanceSingleByteDoubleByteWidth.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAdjustLineHeightInTable.h"

#define FZZWCOMPAT_Find_Key "schemas.openxmlformats.org/wordprocessingml/2006/main"
#define FZZWCOMPAT_Name "compat"

class FZZWCompat : public FZZXMLElementObject
{
public:
    
    FZZWCompat(FZZOfficeObject * parent);
    FZZWCompat(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZWCompat(const FZZWCompat& obj);
    virtual ~FZZWCompat();
    
public:
    FZZWUseFELayout * setUseFELayout();
    FZZWUseFELayout * getUseFELayout();
    FZZWUlTrailSpace * setUlTrailSpace();
    FZZWUlTrailSpace * getUlTrailSpace();
    FZZWSpaceForUL * setSpaceForUL();
    FZZWSpaceForUL * getSpaceForUL();
    FZZWDoNotLeaveBackslashAlone * setDoNotLeaveBackslashAlone();
    FZZWDoNotLeaveBackslashAlone * getDoNotLeaveBackslashAlone();
    FZZWDoNotExpandShiftReturn * setDoNotExpandShiftReturn();
    FZZWDoNotExpandShiftReturn * getDoNotExpandShiftReturn();
    FZZWBalanceSingleByteDoubleByteWidth * setBalanceSingleByteDoubleByteWidth();
    FZZWBalanceSingleByteDoubleByteWidth * getBalanceSingleByteDoubleByteWidth();
    FZZWAdjustLineHeightInTable * setAdjustLineHeightInTable();
    FZZWAdjustLineHeightInTable * getAdjustLineHeightInTable();
    FZZWCompatSetting * addCompatSetting();
    vector<FZZWCompatSetting*> * getCompatSettings();
protected:
    FZZWCompat();
private:
    FZZWUseFELayout* m_FZZWUseFELayout;
    FZZWUlTrailSpace* m_FZZWUlTrailSpace;
    FZZWSpaceForUL * m_FZZWSpaceForUL;
    FZZWDoNotLeaveBackslashAlone * m_FZZWDoNotLeaveBackslashAlone;
    FZZWDoNotExpandShiftReturn * m_FZZWDoNotExpandShiftReturn;
    FZZWBalanceSingleByteDoubleByteWidth * m_FZZWBalanceSingleByteDoubleByteWidth;
    FZZWAdjustLineHeightInTable * m_FZZWAdjustLineHeightInTable;
    vector<FZZWCompatSetting*> m_FZZWCompatSettings;
};

#endif //FZZWCOMPAT_H
