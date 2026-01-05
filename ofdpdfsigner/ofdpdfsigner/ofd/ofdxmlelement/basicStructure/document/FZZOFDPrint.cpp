//
//  Created by zizheng fan on 2024/02/27.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDPrint.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPrint**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrint::FZZOFDPrint() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPrint()");
    FZZConst::addClassCount("FZZOFDPrint");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrint::FZZOFDPrint(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDPrint");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrint::FZZOFDPrint(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPrint");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrint::FZZOFDPrint(const FZZOFDPrint& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPrint");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPrint::~FZZOFDPrint()
{
    //DLOG("~FZZOFDPrint()");
    FZZConst::delClassCount("FZZOFDPrint");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPrint::setPrintable(bool value)
{
    setAttribute_Bool("Printable",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDPrint::getPrintable()
{
    return getAttribute_Bool("Printable",true);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPrint::setCopies(int value)
{
    setAttribute_Int("Copies",value);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDPrint::getCopies()
{
    return getAttribute_Int("Copies");
}
//-----------------------------------------------------------------------------------------------------------------
