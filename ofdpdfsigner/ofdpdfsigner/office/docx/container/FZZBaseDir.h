//
//  Created by zizheng fan on 2023/04/03.
//
#ifndef FZZBASEDIR_H
#define FZZBASEDIR_H

#include "basic/FZZOFDFilesContainer.h"
#include "office/FZZOfficeObject.h"

class FZZBaseDir
{
public:
    FZZBaseDir(FZZOFDFilesContainer* filesContainer,string Root);
    virtual ~FZZBaseDir();
    
public:
    void setPath(string path) { m_Path = path; }
    
    //free
    XMLDocument * getXMLDocument(string filename);
    
    FZZBytes * getResFile(string filename);
    
    void FlushOfficeObject(FZZOfficeObject * officeObject);
    
    void FlushResFile(string filename,FZZBytes * filedata);
    
    string getResFileName(string inName,string inExtName,int & ID);
  
protected:
    FZZBaseDir();
    
    string m_Root;
    string m_Path;
    FZZOFDFilesContainer* m_OFDFilesContainer;
private:
    
};

#endif //FZZBASEDIR_H
