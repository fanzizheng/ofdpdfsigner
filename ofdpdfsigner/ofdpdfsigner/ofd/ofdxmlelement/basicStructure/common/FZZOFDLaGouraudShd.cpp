//
//  Created by zizheng fan on 2024/03/04.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLaGouraudShd.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDLaGouraudShd**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLaGouraudShd::FZZOFDLaGouraudShd() : FZZOFDGouraudShd()
{
    //DLOG("FZZOFDLaGouraudShd()");
    FZZConst::addClassCount("FZZOFDLaGouraudShd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLaGouraudShd::FZZOFDLaGouraudShd(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDGouraudShd(parent,doc,node,key)
{
    
    FZZConst::addClassCount("FZZOFDLaGouraudShd");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLaGouraudShd::FZZOFDLaGouraudShd(FZZOFDXMLFileObject * parent) : FZZOFDGouraudShd(parent)
{
    FZZConst::addClassCount("FZZOFDLaGouraudShd");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLaGouraudShd::FZZOFDLaGouraudShd(const FZZOFDLaGouraudShd& obj) : FZZOFDGouraudShd(obj)
{
    
    FZZConst::addClassCount("FZZOFDLaGouraudShd");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLaGouraudShd::~FZZOFDLaGouraudShd()
{
    //DLOG("~FZZOFDLaGouraudShd()");
    FZZConst::delClassCount("FZZOFDLaGouraudShd");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDLaGouraudShd::setVerticesPerRow(int value)
{
    setAttribute_Int("VerticesPerRow",value);
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDLaGouraudShd::getVerticesPerRow()
{
    return getAttribute_Int("VerticesPerRow");
}
//-----------------------------------------------------------------------------------------------------------------
