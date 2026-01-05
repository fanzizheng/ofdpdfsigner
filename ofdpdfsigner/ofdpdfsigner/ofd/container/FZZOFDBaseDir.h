//
//  Created by zizheng fan on 2024/02/23.
//
#ifndef FZZOFDBASEDIR_H
#define FZZOFDBASEDIR_H

#include "basic/FZZOFDFilesContainer.h"
#include "ofd/FZZOFDXMLFileObject.h"

class FZZOFDBaseDir
{
public:
    FZZOFDBaseDir(FZZOFDFilesContainer* filesContainer,string Root);
    virtual ~FZZOFDBaseDir();
    
public:
    string getRoot() { return m_Root; }
    void setPath(string path) { m_Path = path; }
    string getPath() { return m_Path; }
    FZZOFDFilesContainer* getFileContainer() { return m_OFDFilesContainer; }
    
    //free
    XMLDocument * getXMLDocument(string filename);
    
    FZZBytes * getResFile(string filename);
    
    void FlushXMLObject(FZZOFDXMLFileObject * ofdXMLFileObject);
    
    void FlushResFile(string filename,FZZBytes * filedata);
    void FlushResFile(string filename,const unsigned char* const filedata,int filedataLen);
    
    void setResFile(string fullfilename,FZZBytes * filedata);
    void deleteResFile(string fullfilename);
    
    void deleteDirFile(string dirName);
    
    bool existsFile(string dirName);
    
    string getFileName_RelativePath(string fullpath);
  
protected:
    FZZOFDBaseDir();
    
    int getPathIndex(string path);
    
    string m_Root;
    string m_Path;
    FZZOFDFilesContainer* m_OFDFilesContainer;
private:
    
};

#endif //FZZOFDBASEDIR_H
