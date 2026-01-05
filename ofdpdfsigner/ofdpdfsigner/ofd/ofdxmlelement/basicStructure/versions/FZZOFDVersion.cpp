//
//  Created by zizheng fan on 2024/02/26.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/versions/FZZOFDVersion.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDVersion**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersion::FZZOFDVersion() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDVersion()");
    FZZConst::addClassCount("FZZOFDVersion");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersion::FZZOFDVersion(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{

    FZZConst::addClassCount("FZZOFDVersion");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersion::FZZOFDVersion(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDVersion");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersion::FZZOFDVersion(const FZZOFDVersion& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDVersion");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVersion::~FZZOFDVersion()
{
    FZZConst::delClassCount("FZZOFDVersion");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDVersion::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDVersion::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDVersion::setIndex(int value)
{
    setAttribute_Int("Index",value);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDVersion::getIndex()
{
    return getAttribute_Int("Index");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDVersion::setCurrent(bool value)
{
    setAttribute_Bool("Current",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDVersion::getCurrent()
{
    return getAttribute_Bool("Current",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDVersion::setBaseLoc(string value)
{
    setAttribute_String("BaseLoc",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDVersion::getBaseLoc()
{
    return getAttribute_String("BaseLoc");
}
//-----------------------------------------------------------------------------------------------------------------
