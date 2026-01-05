//
//  Created by zizheng fan on 2024/03/11.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDVectorG.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDVectorG**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVectorG::FZZOFDVectorG() : FZZOFDXMLElementObject(),m_FZZOFDThumbnail(NULL),m_FZZOFDSubstitution(NULL),m_FZZOFDPageBlock(NULL)
{
    //DLOG("FZZOFDVectorG()");
    FZZConst::addClassCount("FZZOFDVectorG");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVectorG::FZZOFDVectorG(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDThumbnail(NULL),m_FZZOFDSubstitution(NULL),m_FZZOFDPageBlock(NULL)
{
    FZZConst::addClassCount("FZZOFDVectorG");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVectorG::FZZOFDVectorG(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDThumbnail(NULL),m_FZZOFDSubstitution(NULL)
,m_FZZOFDPageBlock(NULL)
{
    FZZConst::addClassCount("FZZOFDVectorG");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVectorG::FZZOFDVectorG(const FZZOFDVectorG& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDVectorG");
    if ( this == &obj ) {
        return;
    }
    
    m_FZZOFDThumbnail = obj.m_FZZOFDThumbnail != NULL ? new FZZOFDThumbnail(*obj.m_FZZOFDThumbnail) : NULL;
    m_FZZOFDSubstitution = obj.m_FZZOFDSubstitution != NULL ? new FZZOFDSubstitution(*obj.m_FZZOFDSubstitution) : NULL;
    m_FZZOFDPageBlock = obj.m_FZZOFDPageBlock != NULL ? new FZZOFDPageBlock(*obj.m_FZZOFDPageBlock) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVectorG::~FZZOFDVectorG()
{
    //DLOG("~FZZOFDVectorG()");
    FZZConst::delClassCount("FZZOFDVectorG");
        
    if ( m_FZZOFDThumbnail != NULL ) {
        delete m_FZZOFDThumbnail;
        m_FZZOFDThumbnail = NULL;
    }
    if ( m_FZZOFDSubstitution != NULL ) {
        delete m_FZZOFDSubstitution;
        m_FZZOFDSubstitution = NULL;
    }
    if ( m_FZZOFDPageBlock != NULL ) {
        delete m_FZZOFDPageBlock;
        m_FZZOFDPageBlock = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDVectorG::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDVectorG::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDVectorG::setID(long value)
{
    
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDVectorG::getID_long()
{
    return getAttribute_long("ID");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDVectorG::setWidth(double value)
{
    setAttribute_double("Width",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDVectorG::getWidth()
{
    return getAttribute_double("Width");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDVectorG::setHeight(double value)
{
    setAttribute_double("Height",value);
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDVectorG::getHeight()
{
    return getAttribute_double("Height");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDThumbnail * FZZOFDVectorG::setThumbnail()
{
    return m_FZZOFDThumbnail = setElementObject(m_FZZOFDThumbnail,FZZOFDTHUMBNAIL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDThumbnail * FZZOFDVectorG::getThumbnail()
{
    return m_FZZOFDThumbnail = getElementObject(m_FZZOFDThumbnail,FZZOFDTHUMBNAIL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubstitution * FZZOFDVectorG::setSubstitution()
{
    return m_FZZOFDSubstitution = setElementObject(m_FZZOFDSubstitution,FZZOFDSUBSTITUTION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSubstitution * FZZOFDVectorG::getSubstitution()
{
    return m_FZZOFDSubstitution = getElementObject(m_FZZOFDSubstitution,FZZOFDSUBSTITUTION_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageBlock * FZZOFDVectorG::setContent()
{
    return m_FZZOFDPageBlock = setElementObject(m_FZZOFDPageBlock,FZZOFDPAGEBLOCK_CONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageBlock * FZZOFDVectorG::getContent()
{
    return m_FZZOFDPageBlock = getElementObject(m_FZZOFDPageBlock,FZZOFDPAGEBLOCK_CONTENT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
