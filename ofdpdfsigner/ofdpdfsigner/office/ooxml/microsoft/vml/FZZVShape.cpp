//
//  Created by zizheng fan on 2023/04/21.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/vml/FZZVShape.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZVShape**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZVShape::FZZVShape() : FZZXMLElementObject(),m_FZZVStroke(NULL),m_FZZVPath(NULL),m_FZZVTextbox(NULL),m_FZZW10Wrap(NULL),m_FZZVImageData(NULL),m_FZZOLock(NULL),m_FZZVTextpath(NULL)
{
    //DLOG("FZZVShape()");
    FZZConst::addClassCount("FZZVShape");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShape::FZZVShape(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,false),m_FZZVStroke(NULL),m_FZZVPath(NULL),m_FZZVTextbox(NULL),m_FZZW10Wrap(NULL),m_FZZVImageData(NULL),m_FZZOLock(NULL),m_FZZVTextpath(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZVShape");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShape::FZZVShape(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZVStroke(NULL),m_FZZVPath(NULL),m_FZZVTextbox(NULL),m_FZZW10Wrap(NULL),m_FZZVImageData(NULL),m_FZZOLock(NULL),m_FZZVTextpath(NULL)
{
    FZZConst::addClassCount("FZZVShape");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShape::FZZVShape(const FZZVShape& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZVShape");
    if ( this == &obj ) {
        return;
    }
    m_FZZVStroke = obj.m_FZZVStroke != NULL ? new FZZVStroke(*obj.m_FZZVStroke) : NULL;
    m_FZZW10Wrap = obj.m_FZZW10Wrap != NULL ? new FZZW10Wrap(*obj.m_FZZW10Wrap) : NULL;
    m_FZZVPath = obj.m_FZZVPath != NULL ? new FZZVPath(*obj.m_FZZVPath) : NULL;
    m_FZZVTextbox = obj.m_FZZVTextbox != NULL ? new FZZVTextbox(*obj.m_FZZVTextbox) : NULL;
    m_FZZVImageData = obj.m_FZZVImageData != NULL ? new FZZVImageData(*obj.m_FZZVImageData) : NULL;
    m_FZZOLock = obj.m_FZZOLock != NULL ? new FZZOLock(*obj.m_FZZOLock) : NULL;
    m_FZZVTextpath = obj.m_FZZVTextpath != NULL ? new FZZVTextpath(*obj.m_FZZVTextpath) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZVShape::~FZZVShape()
{
    //DLOG("~FZZVShape()");
    FZZConst::delClassCount("FZZVShape");
    if ( m_FZZVStroke != NULL ) {
        delete m_FZZVStroke;
        m_FZZVStroke = NULL;
    }
    if ( m_FZZW10Wrap != NULL ) {
        delete m_FZZW10Wrap;
        m_FZZW10Wrap = NULL;
    }
    if ( m_FZZVPath != NULL ) {
        delete m_FZZVPath;
        m_FZZVPath = NULL;
    }
    if ( m_FZZVTextbox != NULL ) {
        delete m_FZZVTextbox;
        m_FZZVTextbox = NULL;
    }
    if ( m_FZZVImageData != NULL ) {
        delete m_FZZVImageData;
        m_FZZVImageData = NULL;
    }
    if ( m_FZZOLock != NULL ) {
        delete m_FZZOLock;
        m_FZZOLock = NULL;
    }
    if ( m_FZZVTextpath != NULL ) {
        delete m_FZZVTextpath;
        m_FZZVTextpath = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------

FZZVStroke * FZZVShape::setStroke()
{
    return m_FZZVStroke = setElementObject(m_FZZVStroke,FZZVSTROKE_Find_Key,FZZVSTROKE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVStroke * FZZVShape::getStroke()
{
    return m_FZZVStroke = getElementObject(m_FZZVStroke,FZZVSTROKE_Find_Key,FZZVSTROKE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setAnchorId(string value)
{
    setAttribute_String("w14:anchorId",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getAnchorId()
{
    return getAttribute_String("w14:anchorId");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setId(string value)
{
    setAttribute_String("id",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getId()
{
    return getAttribute_String("id");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setSpId(string value)
{
    setAttribute_String("o:spid",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getSpId()
{
    return getAttribute_String("o:spid");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setStyle(string value)
{
    setAttribute_String("style",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getStyle()
{
    return getAttribute_String("style");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setOle(string value)
{
    setAttribute_String("o:ole",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getOle()
{
    return getAttribute_String("o:ole");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setFillcolor(string value)
{
    setAttribute_String("fillcolor",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getFillcolor()
{
    return getAttribute_String("fillcolor");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setGfxdata(string value)
{
    setAttribute_String("o:gfxdata",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getGfxdata()
{
    return getAttribute_String("o:gfxdata");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setStrokecolor(string value)
{
    setAttribute_String("strokecolor",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getStrokecolor()
{
    return getAttribute_String("strokecolor");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setStrokeweight(string value)
{
    setAttribute_String("strokeweight",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getStrokeweight()
{
    return getAttribute_String("strokeweight");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap * FZZVShape::setWrap()
{
    return m_FZZW10Wrap = setElementObject(m_FZZW10Wrap,FZZW10WRAP_Find_Key,FZZW10WRAP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZW10Wrap * FZZVShape::getWrap()
{
    return m_FZZW10Wrap = getElementObject(m_FZZW10Wrap,FZZW10WRAP_Find_Key,FZZW10WRAP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setType(string value)
{
    setAttribute_String("type",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getType()
{
    return getAttribute_String("type");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setFilled(string value)
{
    setAttribute_String("filled",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getFilled()
{
    return getAttribute_String("filled");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setStroked(string value)
{
    setAttribute_String("stroked",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getStroked()
{
    return getAttribute_String("stroked");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setPreferrelative(string value)
{
    setAttribute_String("o:preferrelative",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getPreferrelative()
{
    return getAttribute_String("o:preferrelative");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setCoordorigin(string value)
{
    setAttribute_String("coordorigin",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getCoordorigin()
{
    return getAttribute_String("coordorigin");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setCoordsize(string value)
{
    setAttribute_String("coordsize",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getCoordsize()
{
    return getAttribute_String("coordsize");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZVShape::setAdj(string value)
{
    setAttribute_String("adj",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZVShape::getAdj()
{
    return getAttribute_String("adj");
}
//-----------------------------------------------------------------------------------------------------------------
FZZVPath * FZZVShape::setPath()
{
    return m_FZZVPath = setElementObject(m_FZZVPath,FZZVPATH_Find_Key,FZZVPATH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVPath * FZZVShape::getPath()
{
    return m_FZZVPath = getElementObject(m_FZZVPath,FZZVPATH_Find_Key,FZZVPATH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextbox * FZZVShape::setTextbox()
{
    return m_FZZVTextbox = setElementObject(m_FZZVTextbox,FZZVTEXTBOX_Find_Key,FZZVTEXTBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextbox * FZZVShape::getTextbox()
{
    return m_FZZVTextbox = getElementObject(m_FZZVTextbox,FZZVTEXTBOX_Find_Key,FZZVTEXTBOX_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData * FZZVShape::setImageData()
{
    return m_FZZVImageData = setElementObject(m_FZZVImageData,FZZVIMAGEDATA_Find_Key,FZZVIMAGEDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVImageData * FZZVShape::getImageData()
{
    return m_FZZVImageData = getElementObject(m_FZZVImageData,FZZVIMAGEDATA_Find_Key,FZZVIMAGEDATA_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock * FZZVShape::setLock()
{
    return m_FZZOLock = setElementObject(m_FZZOLock,FZZOLOCK_Find_Key,FZZOLOCK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOLock * FZZVShape::getLock()
{
    return m_FZZOLock = getElementObject(m_FZZOLock,FZZOLOCK_Find_Key,FZZOLOCK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextpath * FZZVShape::setTextpath()
{
    return m_FZZVTextpath = setElementObject(m_FZZVTextpath,FZZVTEXTPATH_Find_Key,FZZVTEXTPATH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZVTextpath * FZZVShape::getTextpath()
{
    return m_FZZVTextpath = getElementObject(m_FZZVTextpath,FZZVTEXTPATH_Find_Key,FZZVTEXTPATH_Name);
}
//-----------------------------------------------------------------------------------------------------------------
