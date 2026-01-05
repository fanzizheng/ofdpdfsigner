//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDImage.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDImage**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDImage::FZZOFDImage() : FZZOFDBaseGraphic(),m_FZZOFDBorder(NULL)
{
    //DLOG("FZZOFDImage()");
    FZZConst::addClassCount("FZZOFDImage");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDImage::FZZOFDImage(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDBaseGraphic(parent,doc,node,key)
,m_FZZOFDBorder(NULL)
{
    
    FZZConst::addClassCount("FZZOFDImage");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDImage::FZZOFDImage(FZZOFDXMLFileObject * parent) : FZZOFDBaseGraphic(parent),m_FZZOFDBorder(NULL)
{
    FZZConst::addClassCount("FZZOFDImage");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDImage::FZZOFDImage(const FZZOFDImage& obj) : FZZOFDBaseGraphic(obj)
{
    
    FZZConst::addClassCount("FZZOFDImage");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDBorder = obj.m_FZZOFDBorder != NULL ? new FZZOFDBorder(*obj.m_FZZOFDBorder) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDImage::~FZZOFDImage()
{
    //DLOG("~FZZOFDImage()");
    FZZConst::delClassCount("FZZOFDImage");
    
    if ( m_FZZOFDBorder != NULL ) {
        delete m_FZZOFDBorder;
        m_FZZOFDBorder = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDImage::setResourceID(string value)
{
    setAttribute_String("ResourceID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDImage::getResourceID()
{
    return getAttribute_String("ResourceID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDImage::setSubstitution(string value)
{
    setAttribute_String("Substitution",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDImage::getSubstitution()
{
    return getAttribute_String("Substitution");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDImage::setImageMask(string value)
{
    setAttribute_String("ImageMask",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDImage::getImageMask()
{
    return getAttribute_String("ImageMask");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBorder * FZZOFDImage::setBorder()
{
    return m_FZZOFDBorder = setElementObject(m_FZZOFDBorder,FZZOFDBORDER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDBorder * FZZOFDImage::getBorder()
{
    return m_FZZOFDBorder = getElementObject(m_FZZOFDBorder,FZZOFDBORDER_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDImage::setResourceID(long value)
{
    setAttribute_long("ResourceID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDImage::getResourceID_long()
{
    return getAttribute_long("ResourceID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDImage::setSubstitution(long value)
{
    setAttribute_long("Substitution",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDImage::getSubstitution_long()
{
    return getAttribute_long("Substitution");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDImage::setImageMask(long value)
{
    setAttribute_long("ImageMask",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDImage::getImageMask_long()
{
    return getAttribute_long("ImageMask");
}
//-----------------------------------------------------------------------------------------------------------------
