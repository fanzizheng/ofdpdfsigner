//
//  Created by zizheng fan on 2024/03/05.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAppearance.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAppearance**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAppearance::FZZOFDAppearance() : FZZOFDPageBlock()
{
    //DLOG("FZZOFDAppearance()");
    FZZConst::addClassCount("FZZOFDAppearance");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAppearance::FZZOFDAppearance(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDPageBlock(parent,doc,node,key)
{
    
    FZZConst::addClassCount("FZZOFDAppearance");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAppearance::FZZOFDAppearance(FZZOFDXMLFileObject * parent) : FZZOFDPageBlock(parent)
{
    FZZConst::addClassCount("FZZOFDAppearance");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAppearance::FZZOFDAppearance(const FZZOFDAppearance& obj) : FZZOFDPageBlock(obj)
{
    
    FZZConst::addClassCount("FZZOFDAppearance");
    if ( this == &obj ) {
        return;
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAppearance::~FZZOFDAppearance()
{
    //DLOG("~FZZOFDAppearance()");
    FZZConst::delClassCount("FZZOFDAppearance");
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAppearance::setBoundary(string value)
{
    setAttribute_String("Boundary",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAppearance::getBoundary()
{
    return getAttribute_String("Boundary");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAppearance::setBoundary(double x, double y,double width, double height)
{
    string strValue;
    ST_Box_ToString(x,y,width,height,strValue);
    setAttribute_String("Boundary",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAppearance::getBoundary(double &x, double &y,double &width, double &height)
{
    string strid = getAttribute_String("Boundary");
    ST_Box_ToDouble(strid, x,y,width,height);
}
//-----------------------------------------------------------------------------------------------------------------
