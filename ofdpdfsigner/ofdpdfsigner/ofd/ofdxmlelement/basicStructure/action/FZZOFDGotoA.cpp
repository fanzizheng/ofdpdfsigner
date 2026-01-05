//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDGotoA.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDGotoA**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGotoA::FZZOFDGotoA() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDGotoA()");
    FZZConst::addClassCount("FZZOFDGotoA");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGotoA::FZZOFDGotoA(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDGotoA");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGotoA::FZZOFDGotoA(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDGotoA");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGotoA::FZZOFDGotoA(const FZZOFDGotoA& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDGotoA");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDGotoA::~FZZOFDGotoA()
{
    //DLOG("~FZZOFDGotoA()");
    FZZConst::delClassCount("FZZOFDGotoA");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDGotoA::setAttachID(string value)
{
    setAttribute_String("AttachID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDGotoA::getAttachID()
{
    return getAttribute_String("AttachID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDGotoA::setNewWindow(bool value)
{
    setAttribute_Bool("NewWindow",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDGotoA::getNewWindow()
{
    return getAttribute_Bool("NewWindow",false);
}
//-----------------------------------------------------------------------------------------------------------------
