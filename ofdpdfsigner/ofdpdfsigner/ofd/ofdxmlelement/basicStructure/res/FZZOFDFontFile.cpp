//
//  Created by zizheng fan on 2024/03/01.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDFontFile.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDFontFile**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFontFile::FZZOFDFontFile() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDFontFile()");
    FZZConst::addClassCount("FZZOFDFontFile");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFontFile::FZZOFDFontFile(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,true)
{
    FZZConst::addClassCount("FZZOFDFontFile");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFontFile::FZZOFDFontFile(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDFontFile");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFontFile::FZZOFDFontFile(const FZZOFDFontFile& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDFontFile");
    if ( this == &obj ) {
        return;
    }
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFontFile::~FZZOFDFontFile()
{
    //DLOG("~FZZOFDFontFile()");
    FZZConst::delClassCount("FZZOFDFontFile");
        
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFontFile::setValue(string value)
{
    setValue_String(value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDFontFile::getValue()
{
    return getValue_String();
}
//-----------------------------------------------------------------------------------------------------------------
