//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDSound.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDSound**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSound::FZZOFDSound() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDSound()");
    FZZConst::addClassCount("FZZOFDSound");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSound::FZZOFDSound(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDSound");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSound::FZZOFDSound(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDSound");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSound::FZZOFDSound(const FZZOFDSound& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDSound");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDSound::~FZZOFDSound()
{
    //DLOG("~FZZOFDSound()");
    FZZConst::delClassCount("FZZOFDSound");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSound::setResourceID(string value)
{
    setAttribute_String("ResourceID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDSound::getResourceID()
{
    return getAttribute_String("ResourceID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSound::setVolume(int value)
{
    setAttribute_Int("Volume",value);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDSound::getVolume()
{
    return getAttribute_Int("Volume");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSound::setRepeat(bool value)
{
    setAttribute_Bool("Repeat",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDSound::getRepeat()
{
    return getAttribute_Bool("Repeat",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDSound::setSynchronous(bool value)
{
    setAttribute_Bool("Synchronous",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDSound::getSynchronous()
{
    return getAttribute_Bool("Synchronous",false);
}
//-----------------------------------------------------------------------------------------------------------------
