//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDReference.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDReference**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReference::FZZOFDReference() : FZZOFDXMLElementObject(),m_FZZOFDCheckValue(NULL)
{
    //DLOG("FZZOFDReference()");
    FZZConst::addClassCount("FZZOFDReference");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReference::FZZOFDReference(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDCheckValue(NULL)
{
    
    FZZConst::addClassCount("FZZOFDReference");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReference::FZZOFDReference(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDCheckValue(NULL)
{
    FZZConst::addClassCount("FZZOFDReference");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReference::FZZOFDReference(const FZZOFDReference& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDReference");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDCheckValue = obj.m_FZZOFDCheckValue != NULL ? new FZZOFDCheckValue(*obj.m_FZZOFDCheckValue) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDReference::~FZZOFDReference()
{
    //DLOG("~FZZOFDReference()");
    FZZConst::delClassCount("FZZOFDReference");
   
    if ( m_FZZOFDCheckValue != NULL ) {
        delete m_FZZOFDCheckValue;
        m_FZZOFDCheckValue = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDReference::setFileRef(string value)
{
//    if ( value[0] != '/' ) {
//        value = "/" + value;
//    }
    setAttribute_String("FileRef",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDReference::getFileRef()
{
    return getAttribute_String("FileRef");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCheckValue * FZZOFDReference::setCheckValue()
{
    return m_FZZOFDCheckValue = setElementObject(m_FZZOFDCheckValue,FZZOFDCHECKVALUE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCheckValue * FZZOFDReference::getCheckValue()
{
    return m_FZZOFDCheckValue = getElementObject(m_FZZOFDCheckValue,FZZOFDCHECKVALUE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
