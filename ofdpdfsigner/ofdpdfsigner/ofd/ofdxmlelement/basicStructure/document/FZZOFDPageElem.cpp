//
//  Created by zizheng fan on 2024/02/29.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPageElem.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPageElem**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageElem::FZZOFDPageElem() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPageElem()");
    FZZConst::addClassCount("FZZOFDPageElem");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageElem::FZZOFDPageElem(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDPageElem");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageElem::FZZOFDPageElem(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPageElem");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageElem::FZZOFDPageElem(const FZZOFDPageElem& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPageElem");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageElem::~FZZOFDPageElem()
{
    //DLOG("~FZZOFDPageElem()");
    FZZConst::delClassCount("FZZOFDPageElem");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageElem::setBaseLoc(string title)
{
    setAttribute_String("BaseLoc",title);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDPageElem::getBaseLoc()
{
    return getAttribute_String("BaseLoc");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageElem::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDPageElem::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageElem::setID(long value)
{
  
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDPageElem::getID_long()
{
    return getAttribute_long("ID");
}
//-----------------------------------------------------------------------------------------------------------------
