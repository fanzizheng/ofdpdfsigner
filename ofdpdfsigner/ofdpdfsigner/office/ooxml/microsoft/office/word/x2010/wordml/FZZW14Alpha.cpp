//
//  Created by zizheng fan on 2023/05/07.
//
#include "basic/FZZConst.h"
#include "office/ooxml/microsoft/office/word/x2010/wordml/FZZW14Alpha.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZW14Alpha**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZW14Alpha::FZZW14Alpha() : FZZXMLElementObject()
{
    //DLOG("FZZW14Alpha()");
    FZZConst::addClassCount("FZZW14Alpha");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14Alpha::FZZW14Alpha(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZW14Alpha");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14Alpha::FZZW14Alpha(FZZOfficeObject * parent) : FZZXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZW14Alpha");
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14Alpha::FZZW14Alpha(const FZZW14Alpha& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZW14Alpha");
    if ( this == &obj ) {
        return;
    }

    
}
//-----------------------------------------------------------------------------------------------------------------
FZZW14Alpha::~FZZW14Alpha()
{
    //DLOG("~FZZW14Alpha()");
    FZZConst::delClassCount("FZZW14Alpha");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZW14Alpha::setVal(string value)
{
    setAttribute_String("w14:val",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZW14Alpha::getVal()
{
    return getAttribute_String("w14:val");
}
//-----------------------------------------------------------------------------------------------------------------
//float FZZW14Alpha::WordAlphaToAlpha(int wordAlpha)
//{
//    return wordAlpha * 255.0 / 100000;
//}
////-----------------------------------------------------------------------------------------------------------------
//int FZZW14Alpha::AlphaToWordAlpha(float Alpha)
//{
//    return (int)(Alpha * 100000 / 255.0);
//}
////-----------------------------------------------------------------------------------------------------------------
