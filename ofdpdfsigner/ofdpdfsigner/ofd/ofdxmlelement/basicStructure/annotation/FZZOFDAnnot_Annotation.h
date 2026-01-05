//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDANNOT_ANNOTATION_H
#define FZZOFDANNOT_ANNOTATION_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAnnotType.h"
#include "ofd/ofdxmlelement/basicStructure/annotation/FZZOFDRemark.h"
#include "ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAppearance.h"
#include "ofd/ofdxmlelement/basicStructure/signatures/FZZOFDParameters.h"

#define FZZOFDANNOT_ANNOTATION_Name "ofd:Annot"


class FZZOFDAnnot_Annotation : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDAnnot_Annotation(FZZOFDXMLFileObject * parent);
    FZZOFDAnnot_Annotation(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDAnnot_Annotation(const FZZOFDAnnot_Annotation& obj);
    virtual ~FZZOFDAnnot_Annotation();
    
public:
    void setID(string value);
    string getID();
    void setID(long value);
    long getID_long();
    void setType(FZZOFDAnnotType::TYPE value);
    FZZOFDAnnotType::TYPE getType();
    void setCreator(string value);
    string getCreator();
    void setLastModDate(string value);
    string getLastModDate();
    void setSubtype(string value);
    string getSubtype();
    void setVisible(bool value);
    bool getVisible();
    void setPrint(bool value);
    bool getPrint();
    void setNoZoom(bool value);
    bool getNoZoom();
    void setNoRotate(bool value);
    bool getNoRotate();
    void setReadOnly(bool value);
    bool getReadOnly();
    
    FZZOFDRemark * setRemark();
    FZZOFDRemark * getRemark();
    FZZOFDAppearance * setAppearance();
    FZZOFDAppearance * getAppearance();
    FZZOFDParameters * setParameters();
    FZZOFDParameters * getParameters();
    
protected:
    FZZOFDAnnot_Annotation();
private:
    FZZOFDRemark * m_FZZOFDRemark;
    FZZOFDAppearance * m_FZZOFDAppearance;
    FZZOFDParameters * m_FZZOFDParameters;
};

#endif //FZZOFDANNOT_ANNOTATION_H
