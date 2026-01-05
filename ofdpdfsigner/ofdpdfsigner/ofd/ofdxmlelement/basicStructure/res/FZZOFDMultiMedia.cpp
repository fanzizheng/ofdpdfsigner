//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDMultiMedia.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDMultiMedia**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedia::FZZOFDMultiMedia() : FZZOFDXMLElementObject(),m_FZZOFDFileLoc(NULL)
{
    //DLOG("FZZOFDMultiMedia()");
    FZZConst::addClassCount("FZZOFDMultiMedia");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedia::FZZOFDMultiMedia(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDFileLoc(NULL)
{
    FZZConst::addClassCount("FZZOFDMultiMedia");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedia::FZZOFDMultiMedia(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDFileLoc(NULL)
{
    FZZConst::addClassCount("FZZOFDMultiMedia");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedia::FZZOFDMultiMedia(const FZZOFDMultiMedia& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDMultiMedia");
    if ( this == &obj ) {
        return;
    }
    
    m_FZZOFDFileLoc = obj.m_FZZOFDFileLoc != NULL ? new FZZOFDFileLoc(*obj.m_FZZOFDFileLoc) : NULL;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedia::~FZZOFDMultiMedia()
{
    //DLOG("~FZZOFDMultiMedia()");
    FZZConst::delClassCount("FZZOFDMultiMedia");
        
    if ( m_FZZOFDFileLoc != NULL ) {
        delete m_FZZOFDFileLoc;
        m_FZZOFDFileLoc = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMultiMedia::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDMultiMedia::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMultiMedia::setID(long value)
{
    
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDMultiMedia::getID_long()
{
    return getAttribute_long("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMultiMedia::setFormat(string value)
{
    setAttribute_String("Format",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDMultiMedia::getFormat()
{
    return getAttribute_String("Format");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMultiMedia::setType(FZZOFDMediaType::TYPE type)
{
    setAttribute_String("Type",FZZOFDMediaType::toString(type));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMediaType::TYPE FZZOFDMultiMedia::getType()
{
    return FZZOFDMediaType::toType(getAttribute_String("Type").c_str());
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDMultiMedia::setMediaFile()
{
    return m_FZZOFDFileLoc = setElementObject(m_FZZOFDFileLoc,FZZOFDMEDIAFILELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFileLoc * FZZOFDMultiMedia::getMediaFile()
{
    return m_FZZOFDFileLoc = getElementObject(m_FZZOFDFileLoc,FZZOFDMEDIAFILELOC_Name);
}
//-----------------------------------------------------------------------------------------------------------------
