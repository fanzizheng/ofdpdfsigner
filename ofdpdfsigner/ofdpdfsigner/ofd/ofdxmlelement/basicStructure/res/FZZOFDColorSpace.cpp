//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDColorSpace.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDColorSpace**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpace::FZZOFDColorSpace() : FZZOFDXMLElementObject(),m_FZZOFDPalette(NULL)
{
    //DLOG("FZZOFDColorSpace()");
    FZZConst::addClassCount("FZZOFDColorSpace");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpace::FZZOFDColorSpace(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDPalette(NULL)
{
    FZZConst::addClassCount("FZZOFDColorSpace");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpace::FZZOFDColorSpace(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDPalette(NULL)
{
    FZZConst::addClassCount("FZZOFDColorSpace");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpace::FZZOFDColorSpace(const FZZOFDColorSpace& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDColorSpace");
    if ( this == &obj ) {
        return;
    }
    
    m_FZZOFDPalette = obj.m_FZZOFDPalette != NULL ? new FZZOFDPalette(*obj.m_FZZOFDPalette) : NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpace::~FZZOFDColorSpace()
{
    //DLOG("~FZZOFDColorSpace()");
    FZZConst::delClassCount("FZZOFDColorSpace");
        
    if ( m_FZZOFDPalette != NULL ) {
        delete m_FZZOFDPalette;
        m_FZZOFDPalette = NULL;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPalette * FZZOFDColorSpace::setPalette()
{
    return m_FZZOFDPalette = setElementObject(m_FZZOFDPalette,FZZOFDPALETTE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPalette * FZZOFDColorSpace::getPalette()
{
    return m_FZZOFDPalette = getElementObject(m_FZZOFDPalette,FZZOFDPALETTE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColorSpace::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDColorSpace::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColorSpace::setID(long value)
{
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDColorSpace::getID_long()
{
    return getAttribute_long("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColorSpace::setType(FZZOFDColorSpace::TYPE type)
{
    string temp = "RGB";
    switch (type) {
    case TYPE_RGB:
        temp = "RGB";
        break;
    case TYPE_GRAY:
        temp = "GRAY";
        break;
    case TYPE_CMYK:
        temp = "CMYK";
        break;
    }
    
    setAttribute_String("Type",temp);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpace::TYPE FZZOFDColorSpace::getType()
{
    string strtype = getAttribute_String("Type");
    FZZOFDColorSpace::TYPE temp = TYPE_RGB;
    if (strtype == "RGB") {
        temp = TYPE_RGB;
    } else if (strtype == "GRAY") {
        temp = TYPE_GRAY;
    }
    else if (strtype == "CMYK") {
        temp = TYPE_CMYK;
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColorSpace::setBitsPerComponent(FZZOFDColorSpace::BIT_TYPE type)
{
    string temp = "1";
    switch (type) {
    case TYPE_BIT_1:
        temp = "1";
        break;
    case TYPE_BIT_2:
        temp = "2";
        break;
    case TYPE_BIT_4:
        temp = "4";
        break;
    case TYPE_BIT_8:
        temp = "8";
        break;
    case TYPE_BIT_16:
        temp = "16";
        break;
    }
    
    setAttribute_String("BitsPerComponent",temp);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpace::BIT_TYPE FZZOFDColorSpace::getBitsPerComponent()
{
    string strtype = getAttribute_String("BitsPerComponent");
    FZZOFDColorSpace::BIT_TYPE temp = TYPE_BIT_1;
    if (strtype == "1") {
        temp = TYPE_BIT_1;
    } else if (strtype == "2") {
        temp = TYPE_BIT_2;
    }
    else if (strtype == "4") {
        temp = TYPE_BIT_4;
    }
    else if (strtype == "8") {
        temp = TYPE_BIT_8;
    }
    else if (strtype == "16") {
        temp = TYPE_BIT_16;
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDColorSpace::setProfile(string value)
{
    setAttribute_String("Profile",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDColorSpace::getProfile()
{
    return getAttribute_String("Profile");
}
//-----------------------------------------------------------------------------------------------------------------
