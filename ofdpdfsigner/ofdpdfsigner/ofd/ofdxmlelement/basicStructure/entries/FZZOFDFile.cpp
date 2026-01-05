//
//  Created by zizheng fan on 2024/09/25.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/entries/FZZOFDFile.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDFile**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFile::FZZOFDFile() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDFile()");
    FZZConst::addClassCount("FZZOFDFile");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFile::FZZOFDFile(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDFile");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFile::FZZOFDFile(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDFile");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFile::FZZOFDFile(const FZZOFDFile& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDFile");
    if ( this == &obj ) {
        return;
    }

}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFile::~FZZOFDFile()
{
    //DLOG("~FZZOFDFile()");
    FZZConst::delClassCount("FZZOFDFile");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFile::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDFile::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFile::setFileLoc(string value)
{
    setAttribute_String("FileLoc",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDFile::getFileLoc()
{
    return getAttribute_String("FileLoc");
}
//-----------------------------------------------------------------------------------------------------------------

