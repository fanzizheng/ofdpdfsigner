//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/attachment/FZZOFDAttachment.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAttachment**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachment::FZZOFDAttachment() : FZZOFDXMLElementObject(),m_FZZOFDFileLoc(NULL)
{
    //DLOG("FZZOFDAttachment()");
    FZZConst::addClassCount("FZZOFDAttachment");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachment::FZZOFDAttachment(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDFileLoc(NULL)
{
    
    FZZConst::addClassCount("FZZOFDAttachment");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachment::FZZOFDAttachment(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDFileLoc(NULL)
{
    FZZConst::addClassCount("FZZOFDAttachment");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachment::FZZOFDAttachment(const FZZOFDAttachment& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDAttachment");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDFileLoc = obj.m_FZZOFDFileLoc != NULL ? new FZZOFDFileLoc(*obj.m_FZZOFDFileLoc) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAttachment::~FZZOFDAttachment()
{
    //DLOG("~FZZOFDAttachment()");
    FZZConst::delClassCount("FZZOFDAttachment");
    if ( m_FZZOFDFileLoc != NULL ) {
        delete m_FZZOFDFileLoc;
        m_FZZOFDFileLoc = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAttachment::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAttachment::setID(long value)
{
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAttachment::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAttachment::setName(string value)
{
    setAttribute_String("Name",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAttachment::getName()
{
    return getAttribute_String("Name");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAttachment::setFormat(string value)
{
    setAttribute_String("Format",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAttachment::getFormat()
{
    return getAttribute_String("Format");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAttachment::setCreationDate(string value)
{
    setAttribute_String("CreationDate",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAttachment::getCreationDate()
{
    return getAttribute_String("CreationDate");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAttachment::setModDate(string value)
{
    setAttribute_String("ModDate",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAttachment::getModDate()
{
    return getAttribute_String("ModDate");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAttachment::setSize(double value)
{
    setAttribute_double("Size",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDAttachment::getSize()
{
    return getAttribute_double("Size");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAttachment::setVisible(bool value)
{
    setAttribute_Bool("Visible",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDAttachment::getVisible()
{
    return getAttribute_Bool("Visible",true);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAttachment::setUsage(string value)
{
    setAttribute_String("Usage",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAttachment::getUsage()
{
    return getAttribute_String("Usage");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDAttachment::setFileLoc()
{
    return m_FZZOFDFileLoc = setElementObject(m_FZZOFDFileLoc,FZZOFDFILELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDAttachment::getFileLoc()
{
    return m_FZZOFDFileLoc = getElementObject(m_FZZOFDFileLoc,FZZOFDFILELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
