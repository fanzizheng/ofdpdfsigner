//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDRESXML_H
#define FZZOFDRESXML_H


#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDFonts.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDColorSpaces.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDDrawParams.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDMultiMedias.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDCompositeGraphicUnits.h"

#define FZZOFDPUBLICRESXML_FILENAME "PublicRes.xml"
#define FZZOFDDOCUMENTRESXML_FILENAME "DocumentRes.xml"
#define FZZOFDPAGERESXML_FILENAME "PageRes.xml"

//-----------------------------------------------------------------------------------------------------------------

//
class FZZOFDResXML : public FZZOFDXMLFileObject
{
public:
    FZZOFDResXML();
    FZZOFDResXML(XMLDocument * doc);
    FZZOFDResXML(const FZZOFDResXML& obj);
    virtual ~FZZOFDResXML();

public:
    void setBaseLoc(string value);
    string getBaseLoc();
    
    FZZOFDFonts* setFonts();
    //FZZOFDFonts* addFonts();
    FZZOFDColorSpaces* addColorSpaces();
    FZZOFDDrawParams* addDrawParams();
    FZZOFDMultiMedias* addMultiMedias();
    FZZOFDCompositeGraphicUnits* addCompositeGraphicUnits();
    
    vector<FZZOFDBaseRes*> * getResourceList();
    
public:
  
protected:
    
private:
    vector<FZZOFDBaseRes*> m_FZZOFDBaseRess;
    FZZOFDFonts * m_Fonts;
};
//-----------------------------------------------------------------------------------------------------------------
class FZZOFDPublicResXML : public FZZOFDResXML
{
public:
    FZZOFDPublicResXML() : FZZOFDResXML() { m_FileName = FZZOFDPUBLICRESXML_FILENAME; }
    FZZOFDPublicResXML(XMLDocument * doc) : FZZOFDResXML(doc) { m_FileName = FZZOFDPUBLICRESXML_FILENAME; }
    FZZOFDPublicResXML(const FZZOFDPublicResXML& obj) : FZZOFDResXML(obj) {}
    virtual ~FZZOFDPublicResXML() {}
};
//-----------------------------------------------------------------------------------------------------------------
class FZZOFDDocumentResXML : public FZZOFDResXML
{
public:
    FZZOFDDocumentResXML() : FZZOFDResXML() { m_FileName = FZZOFDDOCUMENTRESXML_FILENAME; }
    FZZOFDDocumentResXML(XMLDocument * doc) : FZZOFDResXML(doc) { m_FileName = FZZOFDDOCUMENTRESXML_FILENAME; }
    FZZOFDDocumentResXML(const FZZOFDDocumentResXML& obj) : FZZOFDResXML(obj) {}
    virtual ~FZZOFDDocumentResXML() {}
};
//-----------------------------------------------------------------------------------------------------------------
class FZZOFDPageResXML : public FZZOFDResXML
{
public:
    FZZOFDPageResXML() : FZZOFDResXML() { m_FileName = FZZOFDPAGERESXML_FILENAME; }
    FZZOFDPageResXML(XMLDocument * doc) : FZZOFDResXML(doc) { m_FileName = FZZOFDPAGERESXML_FILENAME; }
    FZZOFDPageResXML(const FZZOFDPageResXML& obj) : FZZOFDResXML(obj) {}
    virtual ~FZZOFDPageResXML() {}
};
//-----------------------------------------------------------------------------------------------------------------
#endif //FZZOFDRESXML_H
