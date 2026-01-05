//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDMovie.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDMovie**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMovie::FZZOFDMovie() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDMovie()");
    FZZConst::addClassCount("FZZOFDMovie");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMovie::FZZOFDMovie(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDMovie");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMovie::FZZOFDMovie(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDMovie");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMovie::FZZOFDMovie(const FZZOFDMovie& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDMovie");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMovie::~FZZOFDMovie()
{
    //DLOG("~FZZOFDMovie()");
    FZZConst::delClassCount("FZZOFDMovie");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMovie::setResourceID(string value)
{
    setAttribute_String("ResourceID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDMovie::getResourceID()
{
    return getAttribute_String("ResourceID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMovie::setResourceID(long value)
{
    
    setAttribute_long("ResourceID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDMovie::getResourceID_long()
{
    return getAttribute_long("ResourceID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDMovie::setOperator(PlayType type)
{
    string value = "Play";

    switch (type) {
    case PlayType::Play:
        value = "Play";
        break;
    case PlayType::Stop:
        value = "Stop";
        break;
    case PlayType::Pause:
        value = "Pause";
        break;
    case PlayType::Resume:
        value = "Resume";
        break;
    default:
        value = "Play";
        break;
    }
    setAttribute_String("Operator",value);
}
//-----------------------------------------------------------------------------------------------------------------
PlayType FZZOFDMovie::getOperator()
{
    string value = getAttribute_String("Operator");
    PlayType playType = PlayType::Play;
    if (value == "Play") {
        playType = PlayType::Play;
    }
    else if (value == "Stop") {
        playType = PlayType::Stop;
    }
    else if (value == "Resume") {
        playType = PlayType::Resume;
    }
    else if (value == "Pause") {
        playType = PlayType::Pause;
    }
    else {
        playType = PlayType::Play;
    }
    return playType;
}
//-----------------------------------------------------------------------------------------------------------------
