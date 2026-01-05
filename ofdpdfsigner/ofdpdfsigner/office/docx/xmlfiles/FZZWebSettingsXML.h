//
//  Created by zizheng fan on 2023/04/08.
//
#ifndef FZZWEBSETTINGSXML_H
#define FZZWEBSETTINGSXML_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWOptimizeForBrowser.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAllowPNG.h"

#define WEBSETTINGSXML_FILENAME "webSettings.xml"

class FZZWebSettingsXML : public FZZOfficeObject
{
public:
    FZZWebSettingsXML();
    FZZWebSettingsXML(XMLDocument * doc);
    FZZWebSettingsXML(const FZZWebSettingsXML& obj);
    virtual ~FZZWebSettingsXML();
    
 
public:
    FZZWOptimizeForBrowser * setOptimizeForBrowser();
    FZZWOptimizeForBrowser * getOptimizeForBrowser();
    FZZWAllowPNG * setAllowPNG();
    FZZWAllowPNG * getAllowPNG();
protected:
    void defaultInit();
private:
    FZZWOptimizeForBrowser * m_FZZWOptimizeForBrowser;
    FZZWAllowPNG * m_FZZWAllowPNG;

    
};

#endif //FZZWEBSETTINGSXML_H
