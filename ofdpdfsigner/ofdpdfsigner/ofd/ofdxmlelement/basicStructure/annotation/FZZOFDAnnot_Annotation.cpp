//
//  Created by zizheng fan on 2024/03/08.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAnnot_Annotation.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDAnnot_Annotation**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot_Annotation::FZZOFDAnnot_Annotation() : FZZOFDXMLElementObject(),m_FZZOFDRemark(NULL),m_FZZOFDAppearance(NULL)
,m_FZZOFDParameters(NULL)
{
    //DLOG("FZZOFDAnnot_Annotation()");
    FZZConst::addClassCount("FZZOFDAnnot_Annotation");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot_Annotation::FZZOFDAnnot_Annotation(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
,m_FZZOFDRemark(NULL),m_FZZOFDAppearance(NULL),m_FZZOFDParameters(NULL)
{
    
    FZZConst::addClassCount("FZZOFDAnnot_Annotation");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot_Annotation::FZZOFDAnnot_Annotation(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent),m_FZZOFDRemark(NULL)
,m_FZZOFDAppearance(NULL),m_FZZOFDParameters(NULL)
{
    FZZConst::addClassCount("FZZOFDAnnot_Annotation");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot_Annotation::FZZOFDAnnot_Annotation(const FZZOFDAnnot_Annotation& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDAnnot_Annotation");
    if ( this == &obj ) {
        return;
    }
    m_FZZOFDRemark = obj.m_FZZOFDRemark != NULL ? new FZZOFDRemark(*obj.m_FZZOFDRemark) : NULL;
    m_FZZOFDAppearance = obj.m_FZZOFDAppearance != NULL ? new FZZOFDAppearance(*obj.m_FZZOFDAppearance) : NULL;
    m_FZZOFDParameters = obj.m_FZZOFDParameters != NULL ? new FZZOFDParameters(*obj.m_FZZOFDParameters) : NULL;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnot_Annotation::~FZZOFDAnnot_Annotation()
{
    //DLOG("~FZZOFDAnnot_Annotation()");
    FZZConst::delClassCount("FZZOFDAnnot_Annotation");
    
    if ( m_FZZOFDRemark != NULL ) {
        delete m_FZZOFDRemark;
        m_FZZOFDRemark = NULL;
    }
    if ( m_FZZOFDAppearance != NULL ) {
        delete m_FZZOFDAppearance;
        m_FZZOFDAppearance = NULL;
    }
    if ( m_FZZOFDParameters != NULL ) {
        delete m_FZZOFDParameters;
        m_FZZOFDParameters = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setID(string value)
{
    setAttribute_String("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAnnot_Annotation::getID()
{
    return getAttribute_String("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setID(long value)
{
    
    setAttribute_long("ID",value);
}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFDAnnot_Annotation::getID_long()
{
    return getAttribute_long("ID");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setType(FZZOFDAnnotType::TYPE value)
{
    setAttribute_String("Type",FZZOFDAnnotType::toString(value));
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAnnotType::TYPE FZZOFDAnnot_Annotation::getType()
{
    return FZZOFDAnnotType::toType( getAttribute_String("Type").c_str() );
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setCreator(string value)
{
    setAttribute_String("Creator",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAnnot_Annotation::getCreator()
{
    return getAttribute_String("Creator");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setLastModDate(string value)
{
    setAttribute_String("LastModDate",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAnnot_Annotation::getLastModDate()
{
    return getAttribute_String("LastModDate");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setSubtype(string value)
{
    setAttribute_String("Subtype",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDAnnot_Annotation::getSubtype()
{
    return getAttribute_String("Subtype");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setVisible(bool value)
{
    setAttribute_Bool("Visible",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDAnnot_Annotation::getVisible()
{
    return getAttribute_Bool("Visible",true);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setPrint(bool value)
{
    setAttribute_Bool("Print",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDAnnot_Annotation::getPrint()
{
    return getAttribute_Bool("Print",true);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setNoZoom(bool value)
{
    setAttribute_Bool("NoZoom",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDAnnot_Annotation::getNoZoom()
{
    return getAttribute_Bool("NoZoom",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setNoRotate(bool value)
{
    setAttribute_Bool("NoRotate",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDAnnot_Annotation::getNoRotate()
{
    return getAttribute_Bool("NoRotate",false);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDAnnot_Annotation::setReadOnly(bool value)
{
    setAttribute_Bool("ReadOnly",value);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDAnnot_Annotation::getReadOnly()
{
    return getAttribute_Bool("ReadOnly",false);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRemark * FZZOFDAnnot_Annotation::setRemark()
{
    return m_FZZOFDRemark = setElementObject(m_FZZOFDRemark,FZZOFDREMARK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDRemark * FZZOFDAnnot_Annotation::getRemark()
{
    return m_FZZOFDRemark = getElementObject(m_FZZOFDRemark,FZZOFDREMARK_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAppearance * FZZOFDAnnot_Annotation::setAppearance()
{
    return m_FZZOFDAppearance = setElementObject(m_FZZOFDAppearance,FZZOFDAPPEARANCE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDAppearance * FZZOFDAnnot_Annotation::getAppearance()
{
    return m_FZZOFDAppearance = getElementObject(m_FZZOFDAppearance,FZZOFDAPPEARANCE_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameters * FZZOFDAnnot_Annotation::setParameters()
{
    return m_FZZOFDParameters = setElementObject(m_FZZOFDParameters,CPARAMETERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDParameters * FZZOFDAnnot_Annotation::getParameters()
{
    return m_FZZOFDParameters = getElementObject(m_FZZOFDParameters,CPARAMETERS_Name);
}
//-----------------------------------------------------------------------------------------------------------------
