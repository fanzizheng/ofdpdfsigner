//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDStampAnnot.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDStampAnnot**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStampAnnot::FZZOFDStampAnnot() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDStampAnnot()");
    FZZConst::addClassCount("FZZOFDStampAnnot");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStampAnnot::FZZOFDStampAnnot(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDStampAnnot");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStampAnnot::FZZOFDStampAnnot(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDStampAnnot");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStampAnnot::FZZOFDStampAnnot(const FZZOFDStampAnnot& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDStampAnnot");
    if ( this == &obj ) {
        return;
    }
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDStampAnnot::~FZZOFDStampAnnot()
{
    //DLOG("~FZZOFDStampAnnot()");
    FZZConst::delClassCount("FZZOFDStampAnnot");
   
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDStampAnnot::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDStampAnnot::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDStampAnnot::setPageRef(string value)
{
    setAttribute_String("PageRef",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDStampAnnot::getPageRef()
{
    return getAttribute_String("PageRef");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDStampAnnot::setBoundary(string value)
{
    setAttribute_String("Boundary",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDStampAnnot::getBoundary()
{
    return getAttribute_String("Boundary");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDStampAnnot::setClip(string value)
{
    setAttribute_String("Clip",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDStampAnnot::getClip()
{
    return getAttribute_String("Clip");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDStampAnnot::setPageRef(long value)
{
    setAttribute_long("PageRef",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDStampAnnot::getPageRef_long()
{
    return getAttribute_long("PageRef");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDStampAnnot::setBoundary(double x, double y,double width, double height)
{
    string strValue;
    ST_Box_ToString(x,y,width,height,strValue);
    setAttribute_String("Boundary",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDStampAnnot::getBoundary(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    string strid = getAttribute_String("Boundary");
    ST_Box_ToDouble(strid, x,y,width,height);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDStampAnnot::setClip(double x, double y,double width, double height)
{
    string strValue;
    ST_Box_ToString(x,y,width,height,strValue);
    setAttribute_String("Clip",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDStampAnnot::getClip(/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    string strid = getAttribute_String("Clip");
    ST_Box_ToDouble(strid, x,y,width,height);
}
//-----------------------------------------------------------------------------------------------------------------
