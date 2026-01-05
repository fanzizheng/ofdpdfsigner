//
//  Created by zizheng fan on 2024/09/25.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/xmlfiles/FZZOFDEntriesXML.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDEntriesXML**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesXML::FZZOFDEntriesXML() : FZZOFDXMLFileObject(),m_FZZOFDSignedValueLoc(NULL),m_FZZOFDFileList(NULL)
{
    //DLOG("FZZOFDEntriesXML()");
    FZZConst::addClassCount("FZZOFDEntriesXML");
    m_doc = new XMLDocument();
    if ( m_doc == NULL ) {
        return;
    }
    m_doc->InsertEndChild(m_doc->NewDeclaration(OFD_XMLHEADER));
    XMLElement* ofd_Document = m_doc->NewElement("ofd:DocEntries");
    ofd_Document->SetAttribute("xmlns:ofd", OFD_NAMESPACE_URI);
    m_ofd_Node = m_doc->InsertEndChild(ofd_Document);
    
    
 
    m_FileName = FZZOFDENTRIESXML_FILENAME;
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesXML::FZZOFDEntriesXML(XMLDocument * doc) : FZZOFDXMLFileObject(doc),m_FZZOFDSignedValueLoc(NULL),m_FZZOFDFileList(NULL)
{
    FZZConst::addClassCount("FZZOFDEntriesXML");
    m_FileName = FZZOFDENTRIESXML_FILENAME;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesXML::FZZOFDEntriesXML(const FZZOFDEntriesXML& obj) : FZZOFDXMLFileObject(obj)
{
    FZZConst::addClassCount("FZZOFDEntriesXML");
    if ( this == &obj ) {
        return;
    }
    
    m_FZZOFDSignedValueLoc = obj.m_FZZOFDSignedValueLoc != NULL ? new FZZOFDSignedValueLoc(*obj.m_FZZOFDSignedValueLoc) : NULL;
    m_FZZOFDFileList = obj.m_FZZOFDFileList != NULL ? new FZZOFDFileList(*obj.m_FZZOFDFileList) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesXML::~FZZOFDEntriesXML()
{
    //DLOG("~FZZOFDEntriesXML()");
    FZZConst::delClassCount("FZZOFDEntriesXML");

    if ( m_FZZOFDSignedValueLoc != NULL ) {
        delete m_FZZOFDSignedValueLoc;
        m_FZZOFDSignedValueLoc = NULL;
    }
    if ( m_FZZOFDFileList != NULL ) {
        delete m_FZZOFDFileList;
        m_FZZOFDFileList = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEntriesXML::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEntriesXML::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEntriesXML::setCreatorName(string value)
{
    setAttribute_String("CreatorName",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEntriesXML::getCreatorName()
{
    return getAttribute_String("CreatorName");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEntriesXML::setVersion(string value)
{
    setAttribute_String("Version",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEntriesXML::getVersion()
{
    return getAttribute_String("Version");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDEntriesXML::setCreationDate(string value)
{
    setAttribute_String("CreationDate",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDEntriesXML::getCreationDate()
{
    return getAttribute_String("CreationDate");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValueLoc * FZZOFDEntriesXML::setSignedValueLoc()
{
    return m_FZZOFDSignedValueLoc = setElementObject(m_FZZOFDSignedValueLoc,FZZOFDSIGNEDVALUELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSignedValueLoc * FZZOFDEntriesXML::getSignedValueLoc()
{
    return m_FZZOFDSignedValueLoc = getElementObject(m_FZZOFDSignedValueLoc,FZZOFDSIGNEDVALUELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileList * FZZOFDEntriesXML::setFileList()
{
    return m_FZZOFDFileList = setElementObject(m_FZZOFDFileList,FZZOFDFILELIST_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileList * FZZOFDEntriesXML::getFileList()
{
    return m_FZZOFDFileList = getElementObject(m_FZZOFDFileList,FZZOFDFILELIST_Name);
}
//-----------------------------------------------------------------------------------------------------------------

