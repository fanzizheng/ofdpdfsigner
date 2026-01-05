//
//  Created by zizheng fan on 2023/04/21.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVLine.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVLine**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVLine::FZZVLine() : FZZXMLElementObject(),m_FZZVStroke(NULL),m_FZZW10Wrap(NULL),m_FZZVFill(NULL),m_FZZVImageData(NULL),m_FZZOLock(NULL)
{
    //DLOG("FZZVLine()");
    FZZConst::addClassCount("FZZVLine");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVLine::FZZVLine(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZVStroke(NULL),m_FZZW10Wrap(NULL),m_FZZVFill(NULL),m_FZZVImageData(NULL),m_FZZOLock(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVLine");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVLine::FZZVLine(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZVStroke(NULL),m_FZZW10Wrap(NULL),m_FZZVFill(NULL),m_FZZVImageData(NULL),m_FZZOLock(NULL)
{
    FZZConst::addClassCount("FZZVLine");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVLine::FZZVLine(const FZZVLine& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVLine");
    if ( this == &obj ) {
        return;
    }
    m_FZZVStroke = obj.m_FZZVStroke != NULL ? new FZZVStroke(*obj.m_FZZVStroke) : NULL;
    m_FZZW10Wrap = obj.m_FZZW10Wrap != NULL ? new FZZW10Wrap(*obj.m_FZZW10Wrap) : NULL;
    m_FZZVFill = obj.m_FZZVFill != NULL ? new FZZVFill(*obj.m_FZZVFill) : NULL;
    m_FZZVImageData = obj.m_FZZVImageData != NULL ? new FZZVImageData(*obj.m_FZZVImageData) : NULL;
    m_FZZOLock = obj.m_FZZOLock != NULL ? new FZZOLock(*obj.m_FZZOLock) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVLine::~FZZVLine()
{
    //DLOG("~FZZVLine()");
    FZZConst::delClassCount("FZZVLine");
    if ( m_FZZVStroke != NULL ) {
        delete m_FZZVStroke;
        m_FZZVStroke = NULL;
    }
    if ( m_FZZW10Wrap != NULL ) {
        delete m_FZZW10Wrap;
        m_FZZW10Wrap = NULL;
    }
    if ( m_FZZVFill != NULL ) {
        delete m_FZZVFill;
        m_FZZVFill = NULL;
    }
    if ( m_FZZVImageData != NULL ) {
        delete m_FZZVImageData;
        m_FZZVImageData = NULL;
    }
    if ( m_FZZOLock != NULL ) {
        delete m_FZZOLock;
        m_FZZOLock = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------

FZZVStroke * FZZVLine::setStroke()
{
    return m_FZZVStroke = setElementObject(m_FZZVStroke,FZZVSTROKE_Find_Key,FZZVSTROKE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVStroke * FZZVLine::getStroke()
{
    return m_FZZVStroke = getElementObject(m_FZZVStroke,FZZVSTROKE_Find_Key,FZZVSTROKE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setAnchorId(string value)
{
    setAttribute_String("w14:anchorId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getAnchorId()
{
    return getAttribute_String("w14:anchorId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setId(string value)
{
    setAttribute_String("id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getId()
{
    return getAttribute_String("id");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setSpId(string value)
{
    setAttribute_String("o:spid",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getSpId()
{
    return getAttribute_String("o:spid");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setStyle(string value)
{
    setAttribute_String("style",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getStyle()
{
    return getAttribute_String("style");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setFrom(string value)
{
    setAttribute_String("from",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getFrom()
{
    return getAttribute_String("from");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setTo(string value)
{
    setAttribute_String("to",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getTo()
{
    return getAttribute_String("to");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setGfxdata(string value)
{
    setAttribute_String("o:gfxdata",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getGfxdata()
{
    return getAttribute_String("o:gfxdata");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setStrokecolor(string value)
{
    setAttribute_String("strokecolor",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getStrokecolor()
{
    return getAttribute_String("strokecolor");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setStrokeweight(string value)
{
    setAttribute_String("strokeweight",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getStrokeweight()
{
    return getAttribute_String("strokeweight");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap * FZZVLine::setWrap()
{
    return m_FZZW10Wrap = setElementObject(m_FZZW10Wrap,FZZW10WRAP_Find_Key,FZZW10WRAP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap * FZZVLine::getWrap()
{
    return m_FZZW10Wrap = getElementObject(m_FZZW10Wrap,FZZW10WRAP_Find_Key,FZZW10WRAP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setType(string value)
{
    setAttribute_String("type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getType()
{
    return getAttribute_String("type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setOle(string value)
{
    setAttribute_String("o:ole",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getOle()
{
    return getAttribute_String("o:ole");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setFillcolor(string value)
{
    setAttribute_String("fillcolor",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getFillcolor()
{
    return getAttribute_String("fillcolor");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setFilled(string value)
{
    setAttribute_String("filled",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getFilled()
{
    return getAttribute_String("filled");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setPreferrelative(string value)
{
    setAttribute_String("o:preferrelative",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getPreferrelative()
{
    return getAttribute_String("o:preferrelative");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setStroked(string value)
{
    setAttribute_String("stroked",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getStroked()
{
    return getAttribute_String("stroked");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVLine::setCoordsize(string value)
{
    setAttribute_String("coordsize",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVLine::getCoordsize()
{
    return getAttribute_String("coordsize");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData * FZZVLine::setImageData()
{
    return m_FZZVImageData = setElementObject(m_FZZVImageData,FZZVIMAGEDATA_Find_Key,FZZVIMAGEDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData * FZZVLine::getImageData()
{
    return m_FZZVImageData = getElementObject(m_FZZVImageData,FZZVIMAGEDATA_Find_Key,FZZVIMAGEDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock * FZZVLine::setLock()
{
    return m_FZZOLock = setElementObject(m_FZZOLock,FZZOLOCK_Find_Key,FZZOLOCK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock * FZZVLine::getLock()
{
    return m_FZZOLock = getElementObject(m_FZZOLock,FZZOLOCK_Find_Key,FZZOLOCK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFill * FZZVLine::setFill()
{
    return m_FZZVFill = setElementObject(m_FZZVFill,FZZVFILL_Find_Key,FZZVFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFill * FZZVLine::getFill()
{
    return m_FZZVFill = getElementObject(m_FZZVFill,FZZVFILL_Find_Key,FZZVFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
