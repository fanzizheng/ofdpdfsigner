//
//  Created by zizheng fan on 2024/09/25.
//
#ifndef FZZOFDFILELIST_H
#define FZZOFDFILELIST_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/entries/FZZOFDFile.h"


#define FZZOFDFILELIST_Name "ofd:FileList"

class FZZOFDFileList : public FZZOFDXMLElementObject
{

public:
    
    FZZOFDFileList(FZZOFDXMLFileObject * parent);
    FZZOFDFileList(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDFileList(const FZZOFDFileList& obj);
    virtual ~FZZOFDFileList();
    
public:
    
    FZZOFDFile * addFile();
    vector<FZZOFDFile*> * getFileList();
    void clearFile();
    
protected:
    FZZOFDFileList();
private:
    vector<FZZOFDFile*> m_FZZOFDFiles;
    
};

#endif //FZZOFDFILELIST_H
