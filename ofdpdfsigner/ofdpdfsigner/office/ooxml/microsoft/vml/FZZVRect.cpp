//
//  Created by zizheng fan on 2023/04/20.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVRect.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVRect**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVRect::FZZVRect() : FZZXMLElementObject(),m_FZZVTextbox(NULL),m_FZZVFill(NULL),m_FZZVImageData(NULL),m_FZZOLock(NULL),m_FZZW10Wrap(NULL)//,m_FZZVStroke(NULL)
{
    //DLOG("FZZVRect()");
    FZZConst::addClassCount("FZZVRect");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVRect::FZZVRect(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZVTextbox(NULL),m_FZZVFill(NULL),m_FZZVImageData(NULL),m_FZZOLock(NULL),m_FZZW10Wrap(NULL)//,m_FZZVStroke(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVRect");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVRect::FZZVRect(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZVTextbox(NULL),m_FZZVFill(NULL),m_FZZVImageData(NULL),m_FZZOLock(NULL),m_FZZW10Wrap(NULL)//,m_FZZVStroke(NULL)
{
    FZZConst::addClassCount("FZZVRect");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVRect::FZZVRect(const FZZVRect& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVRect");
    if ( this == &obj ) {
        return;
    }
    //m_FZZVStroke = obj.m_FZZVStroke != NULL ? new FZZVStroke(*obj.m_FZZVStroke) : NULL;
    m_FZZW10Wrap = obj.m_FZZW10Wrap != NULL ? new FZZW10Wrap(*obj.m_FZZW10Wrap) : NULL;
    m_FZZVTextbox = obj.m_FZZVTextbox != NULL ? new FZZVTextbox(*obj.m_FZZVTextbox) : NULL;
    m_FZZVFill = obj.m_FZZVFill != NULL ? new FZZVFill(*obj.m_FZZVFill) : NULL;
    m_FZZVImageData = obj.m_FZZVImageData != NULL ? new FZZVImageData(*obj.m_FZZVImageData) : NULL;
    m_FZZOLock = obj.m_FZZOLock != NULL ? new FZZOLock(*obj.m_FZZOLock) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZVRect::~FZZVRect()
{
    //DLOG("~FZZVRect()");
    FZZConst::delClassCount("FZZVRect");
//    if ( m_FZZVStroke != NULL ) {
//        delete m_FZZVStroke;
//        m_FZZVStroke = NULL;
//    }
    if ( m_FZZW10Wrap != NULL ) {
        delete m_FZZW10Wrap;
        m_FZZW10Wrap = NULL;
    }
    
    if ( m_FZZVTextbox != NULL ) {
        delete m_FZZVTextbox;
        m_FZZVTextbox = NULL;
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

//FZZVStroke * FZZVRect::setStroke()
//{
//    return m_FZZVStroke = setElementObject(m_FZZVStroke,FZZVSTROKE_Find_Key,FZZVSTROKE_Name);
//}
////-----------------------------------------------------------------------------------------------------------------
//FZZVStroke * FZZVRect::getStroke()
//{
//    return m_FZZVStroke = getElementObject(m_FZZVStroke,FZZVSTROKE_Find_Key,FZZVSTROKE_Name);
//}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setAnchorId(string value)
{
    setAttribute_String("w14:anchorId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getAnchorId()
{
    return getAttribute_String("w14:anchorId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setId(string value)
{
    setAttribute_String("id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getId()
{
    return getAttribute_String("id");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setSpId(string value)
{
    setAttribute_String("o:spid",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getSpId()
{
    return getAttribute_String("o:spid");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setStyle(string value)
{
    setAttribute_String("style",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getStyle()
{
    return getAttribute_String("style");
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZVRect::setFrom(string value)
//{
//    setAttribute_String("from",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZVRect::getFrom()
//{
//    return getAttribute_String("from");
//}
////-----------------------------------------------------------------------------------------------------------------
//void FZZVRect::setTo(string value)
//{
//    setAttribute_String("to",value);
//}
////-----------------------------------------------------------------------------------------------------------------
//string FZZVRect::getTo()
//{
//    return getAttribute_String("to");
//}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setGfxdata(string value)
{
    setAttribute_String("o:gfxdata",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getGfxdata()
{
    return getAttribute_String("o:gfxdata");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setStrokecolor(string value)
{
    setAttribute_String("strokecolor",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getStrokecolor()
{
    return getAttribute_String("strokecolor");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setStrokeweight(string value)
{
    setAttribute_String("strokeweight",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getStrokeweight()
{
    return getAttribute_String("strokeweight");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap * FZZVRect::setWrap()
{
    return m_FZZW10Wrap = setElementObject(m_FZZW10Wrap,FZZW10WRAP_Find_Key,FZZW10WRAP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap * FZZVRect::getWrap()
{
    return m_FZZW10Wrap = getElementObject(m_FZZW10Wrap,FZZW10WRAP_Find_Key,FZZW10WRAP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setFillcolor(string value)
{
    setAttribute_String("fillcolor",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getFillcolor()
{
    return getAttribute_String("fillcolor");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setType(string value)
{
    setAttribute_String("type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getType()
{
    return getAttribute_String("type");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextbox * FZZVRect::setTextbox()
{
    return m_FZZVTextbox = setElementObject(m_FZZVTextbox,FZZVTEXTBOX_Find_Key,FZZVTEXTBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextbox * FZZVRect::getTextbox()
{
    return m_FZZVTextbox = getElementObject(m_FZZVTextbox,FZZVTEXTBOX_Find_Key,FZZVTEXTBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setPreferrelative(string value)
{
    setAttribute_String("o:preferrelative",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getPreferrelative()
{
    return getAttribute_String("o:preferrelative");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setOle(string value)
{
    setAttribute_String("o:ole",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getOle()
{
    return getAttribute_String("o:ole");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setFilled(string value)
{
    setAttribute_String("filled",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getFilled()
{
    return getAttribute_String("filled");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setStroked(string value)
{
    setAttribute_String("stroked",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getStroked()
{
    return getAttribute_String("stroked");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setCoordorigin(string value)
{
    setAttribute_String("coordorigin",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getCoordorigin()
{
    return getAttribute_String("coordorigin");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVRect::setCoordsize(string value)
{
    setAttribute_String("coordsize",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVRect::getCoordsize()
{
    return getAttribute_String("coordsize");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData * FZZVRect::setImageData()
{
    return m_FZZVImageData = setElementObject(m_FZZVImageData,FZZVIMAGEDATA_Find_Key,FZZVIMAGEDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData * FZZVRect::getImageData()
{
    return m_FZZVImageData = getElementObject(m_FZZVImageData,FZZVIMAGEDATA_Find_Key,FZZVIMAGEDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock * FZZVRect::setLock()
{
    return m_FZZOLock = setElementObject(m_FZZOLock,FZZOLOCK_Find_Key,FZZOLOCK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock * FZZVRect::getLock()
{
    return m_FZZOLock = getElementObject(m_FZZOLock,FZZOLOCK_Find_Key,FZZOLOCK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFill * FZZVRect::setFill()
{
    return m_FZZVFill = setElementObject(m_FZZVFill,FZZVFILL_Find_Key,FZZVFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVFill * FZZVRect::getFill()
{
    return m_FZZVFill = getElementObject(m_FZZVFill,FZZVFILL_Find_Key,FZZVFILL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
