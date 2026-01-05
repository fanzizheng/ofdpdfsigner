//
//  Created by zizheng fan on 2024/03/11.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/page/FZZOFDPageRes.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPageRes**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageRes::FZZOFDPageRes() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDPageRes()");
    FZZConst::addClassCount("FZZOFDPageRes");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageRes::FZZOFDPageRes(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    
    FZZConst::addClassCount("FZZOFDPageRes");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageRes::FZZOFDPageRes(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDPageRes");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageRes::FZZOFDPageRes(const FZZOFDPageRes& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDPageRes");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageRes::~FZZOFDPageRes()
{
    //DLOG("~FZZOFDPageRes()");
    FZZConst::delClassCount("FZZOFDPageRes");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageRes::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDPageRes::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------

