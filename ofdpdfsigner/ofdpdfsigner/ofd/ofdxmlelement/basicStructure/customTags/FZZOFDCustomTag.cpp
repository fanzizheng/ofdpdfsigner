//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/customTags/FZZOFDCustomTag.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCustomTag**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTag::FZZOFDCustomTag() : FZZOFDXMLElementObject(),m_SchemaLoc(NULL),m_FZZOFDFileLoc(NULL)
{
    //DLOG("FZZOFDCustomTag()");
    FZZConst::addClassCount("FZZOFDCustomTag");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTag::FZZOFDCustomTag(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_SchemaLoc(NULL),m_FZZOFDFileLoc(NULL)
{
    
    FZZConst::addClassCount("FZZOFDCustomTag");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTag::FZZOFDCustomTag(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_SchemaLoc(NULL),m_FZZOFDFileLoc(NULL)
{
    FZZConst::addClassCount("FZZOFDCustomTag");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTag::FZZOFDCustomTag(const FZZOFDCustomTag& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDCustomTag");
    if ( this == &obj ) {
        return;
    }
    m_SchemaLoc = obj.m_SchemaLoc != NULL ? new FZZOFDFileLoc(*obj.m_SchemaLoc) : NULL;
    m_FZZOFDFileLoc = obj.m_FZZOFDFileLoc != NULL ? new FZZOFDFileLoc(*obj.m_FZZOFDFileLoc) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCustomTag::~FZZOFDCustomTag()
{
    //DLOG("~FZZOFDCustomTag()");
    FZZConst::delClassCount("FZZOFDCustomTag");
    if ( m_SchemaLoc != NULL ) {
        delete m_SchemaLoc;
        m_SchemaLoc = NULL;
    }
    if ( m_FZZOFDFileLoc != NULL ) {
        delete m_FZZOFDFileLoc;
        m_FZZOFDFileLoc = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCustomTag::setTypeID(string value)
{
    setAttribute_String("TypeID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCustomTag::getTypeID()
{
    return getAttribute_String("TypeID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCustomTag::setNameSpace(string value)
{
    setAttribute_String("NameSpace",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCustomTag::getNameSpace()
{
    return getAttribute_String("NameSpace");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDCustomTag::setSchemaLoc()
{
    return m_SchemaLoc = setElementObject(m_SchemaLoc,FZZOFDSCHEMALOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDCustomTag::getSchemaLoc()
{
    return m_SchemaLoc = getElementObject(m_SchemaLoc,FZZOFDSCHEMALOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDCustomTag::setFileLoc()
{
    return m_FZZOFDFileLoc = setElementObject(m_FZZOFDFileLoc,FZZOFDFILELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDCustomTag::getFileLoc()
{
    return m_FZZOFDFileLoc = getElementObject(m_FZZOFDFileLoc,FZZOFDFILELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
