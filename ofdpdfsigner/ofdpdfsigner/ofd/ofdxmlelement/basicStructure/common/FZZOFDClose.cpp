//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClose.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDClose**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClose::FZZOFDClose() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDClose()");
    FZZConst::addClassCount("FZZOFDClose");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClose::FZZOFDClose(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDClose");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClose::FZZOFDClose(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDClose");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClose::FZZOFDClose(const FZZOFDClose& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDClose");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClose::~FZZOFDClose()
{
    //DLOG("~FZZOFDClose()");
    FZZConst::delClassCount("FZZOFDClose");
    
    
}
//-----------------------------------------------------------------------------------------------------------------

