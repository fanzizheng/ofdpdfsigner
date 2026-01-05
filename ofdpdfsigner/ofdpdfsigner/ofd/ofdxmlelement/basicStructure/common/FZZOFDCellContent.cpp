//
//  Created by zizheng fan on 2024/03/04.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCellContent.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDCellContent**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCellContent::FZZOFDCellContent() : FZZOFDPageBlock()
{
    //DLOG("FZZOFDCellContent()");
    FZZConst::addClassCount("FZZOFDCellContent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCellContent::FZZOFDCellContent(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDPageBlock(parent,doc,node,key)
{
    
    FZZConst::addClassCount("FZZOFDCellContent");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCellContent::FZZOFDCellContent(FZZOFDXMLFileObject * parent) : FZZOFDPageBlock(parent)
{
    FZZConst::addClassCount("FZZOFDCellContent");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCellContent::FZZOFDCellContent(const FZZOFDCellContent& obj) : FZZOFDPageBlock(obj)
{
    
    FZZConst::addClassCount("FZZOFDCellContent");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCellContent::~FZZOFDCellContent()
{
    //DLOG("~FZZOFDCellContent()");
    FZZConst::delClassCount("FZZOFDCellContent");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCellContent::setThumbnail(string value)
{
    setAttribute_String("Thumbnail",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDCellContent::getThumbnail()
{
    return getAttribute_String("Thumbnail");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDCellContent::setThumbnail(long value)
{
    setAttribute_long("Thumbnail",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDCellContent::getThumbnail_long()
{
    return getAttribute_long("Thumbnail");
}
//-----------------------------------------------------------------------------------------------------------------
