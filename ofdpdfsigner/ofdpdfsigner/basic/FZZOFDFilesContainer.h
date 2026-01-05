//
//  Created by zizheng fan on 2022/10/16.
//
#ifndef FZZOFDFILESCONTAINER_H
#define FZZOFDFILESCONTAINER_H

#include "basic/FZZBytes.h"

class FZZOFDFilesContainer
{
public:
    FZZOFDFilesContainer();
    virtual ~FZZOFDFilesContainer();
public:
    void addFile(string root,string name,unsigned char * data,size_t len);
    void updateFile(string root,string name,unsigned char * data,size_t len) {addFile(root,name,data,len);}
    bool exists(string root,string name);
    void removeAll();
    void removeFils(string root);
    //void getRootsName(vector<string> & RootNames);
    void getFilesName(string root,vector<string> & fileNames);
    FZZBytes* getFileData(string root,string name);
    void removeFile(string root,string name);
    void removeDirFile(string root,string name);
protected:
    
private:
    //void removeFils_pri(string root);
private:
    //map<string, map<string,FZZBytes*>*> m_ofdFilesContainer;
    map<string,FZZBytes*> m_ofdFilesContainer;
};

#endif //FZZOFDFILESCONTAINER_H

