//
//  Created by zizheng fan on 2022/10/16.
//
#include "basic/FZZConst.h"
#include "basic/FZZOFDFilesContainer.h"

#define DIFFTIME 60*30
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZOFDFilesContainer*******************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFilesContainer::FZZOFDFilesContainer()
{
    //DLOG("FZZOFDFilesContainer()");
    //FZZConst::addClassCount("FZZOFDFilesContainer");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFilesContainer::~FZZOFDFilesContainer()
{
    //DLOG("~FZZOFDFilesContainer()");
    //FZZConst::delClassCount("FZZOFDFilesContainer");
    removeAll();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFilesContainer::addFile(string root,string name,unsigned char * data,size_t len)
{
    if ( data == NULL || len <= 0 ) {
        return;
    }
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    name = FZZConst::replace_all(name,"\\","/");
//    if ( name[0] != '/' ) {
//        name = "/" + name;
//    }
    
//    map<string,FZZBytes*>* files = m_ofdFilesContainer[root];
//    if ( files == NULL ) {
//        files = new map<string,FZZBytes*>();
//        m_ofdFilesContainer[root] = files;
//    }
//    if ( (*files)[name] == NULL ) {
//        (*files)[name] = new FZZBytes(data,len);
//    } else {
//        (*files)[name]->setData(data,len);
//    }
    
    string key = name+"||"+root;
    FZZBytes * filedata = NULL;
    map<string,FZZBytes*>::const_iterator it = m_ofdFilesContainer.find(key);
    if (it != m_ofdFilesContainer.end()) {
        filedata = it->second;
        if ( filedata != NULL) {
            filedata->setData(data,len);
        } else {
            filedata = new FZZBytes(data,len);
            if ( filedata != NULL ) {
                auto isExitPari = m_ofdFilesContainer.insert(pair<string,FZZBytes*>(key,filedata));
                if ( !isExitPari.second ) {
                    delete filedata;
                }
            }
        }
    } else {
        filedata = new FZZBytes(data,len);
        if ( filedata != NULL ) {
            auto isExitPari = m_ofdFilesContainer.insert(pair<string,FZZBytes*>(key,filedata));
            
            if ( !isExitPari.second ) {
                delete filedata;
            }
        }
    }
    
    //DLOG("add file root=%s,name=%s",root.c_str(),name.c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFilesContainer::removeAll()
{
//    vector<string>  RootNames;
//    map<string, map<string,FZZBytes*>*>::iterator it;
//    for (it = m_ofdFilesContainer.begin(); it != m_ofdFilesContainer.end(); it++) {
//        RootNames.push_back(it->first);
//    }
//    for( int i = 0; i < RootNames.size(); i++ ) {
//        removeFils(RootNames[i]);
//    }
//    m_ofdFilesContainer.clear();
//    DLOG("removeAll");
    map<string,FZZBytes*>::const_iterator it;
    for (it = m_ofdFilesContainer.begin(); it != m_ofdFilesContainer.end(); it++ ) {
        if ( it->second != NULL ) {
            delete it->second;
        }
    }
    m_ofdFilesContainer.clear();
    //DLOG("removeAll");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFilesContainer::removeFils(string root)
{
//    removeFils_pri(root);
//
//    time_t now;
//    time(&now);
//    vector<string> RootNames;
//    getRootsName(RootNames);
//    for ( int i = 0; i < RootNames.size();i++ ) {
//        string temproot = RootNames[i];
//        string temptime = temproot.substr(temproot.find("-")+1);
//        if ( now - atol(temptime.c_str()) >= DIFFTIME ) {
//            removeFils_pri(temproot);
//        }
//    }
    time_t now;
    time(&now);
    vector<string> RootNames;
    string key = "",temproot = "",temptime = "";
    map<string,FZZBytes*>::const_iterator it;
    for (it = m_ofdFilesContainer.begin(); it != m_ofdFilesContainer.end(); it++ ) {
        key = it->first;
        size_t pos = key.find(root);
        if ( pos != string::npos ) {
            if ( it->second != NULL ) {
                delete it->second;
            }
            RootNames.push_back(key);
        }
//        temproot = key;
//        temptime = temproot.substr(temproot.find("-")+1);
//        if ( now - atol(temptime.c_str()) >= DIFFTIME ) {
//            if ( it->second != NULL ) {
//                delete it->second;
//            }
//            RootNames.push_back(key);
//        }
        
    }
    
    vector<string>::const_iterator it_rootname;
    for( it_rootname = RootNames.begin(); it_rootname != RootNames.end(); it_rootname++ ) {
        m_ofdFilesContainer.erase(*it_rootname);
    }
    
    DLOG("remove root file root=%s",root.c_str());
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZOFDFilesContainer::removeFils_pri(string root)
//{
//    map<string,FZZBytes*>* files = m_ofdFilesContainer[root];
//    if ( files != NULL ) {
//        map<string, FZZBytes*>::iterator it;
//        for (it = files->begin(); it != files->end(); ++it) {
//            if (it->second != NULL) {
//                delete (it->second);
//            }
//        }
//        files->clear();
//        delete files;
//        m_ofdFilesContainer.erase(root);
//        DLOG("remove root root=%s",root.c_str());
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDFilesContainer::exists(string root,string name)
{
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    name = FZZConst::replace_all(name,"\\","/");
//    if ( name[0] != '/' ) {
//        name = "/" + name;
//    }
//    map<string,FZZBytes*>* files = m_ofdFilesContainer[root];
//    if ( files == NULL ) {
//        return false;
//    } else {
//        return files->count(name) == 0 ? false:true;
//    }
    string key = name+"||"+root;
    //FZZBytes * filedata = NULL;
    map<string,FZZBytes*>::const_iterator it = m_ofdFilesContainer.find(key);
    if (it != m_ofdFilesContainer.end()) {
        return true;
    } else {
        return false;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//void FZZOFDFilesContainer::getRootsName(vector<string> & RootNames)
//{
//    map<string, map<string,FZZBytes*>*>::iterator it;
//    for (it = m_ofdFilesContainer.begin(); it != m_ofdFilesContainer.end(); ++it) {
//        RootNames.push_back(it->first);
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFilesContainer::getFilesName(string root,vector<string> & fileNames)
{
//    map<string,FZZBytes*>* files = m_ofdFilesContainer[root];
//    if ( files == NULL ) {
//        fileNames.clear();
//        return;
//    }
//    map<string,FZZBytes*>::iterator it;
//    for (it = files->begin(); it != files->end(); ++it) {
//        fileNames.push_back(it->first);
//    }
    fileNames.clear();
    string key = "";
    map<string,FZZBytes*>::const_iterator it;
    for (it = m_ofdFilesContainer.begin(); it != m_ofdFilesContainer.end(); it++ ) {
        key = it->first;
        size_t pos = key.find(root);
        if ( pos != string::npos ) {
            pos = key.find("||");
            if ( pos != string::npos ) {
                fileNames.push_back(key.substr(0,pos));
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes* FZZOFDFilesContainer::getFileData(string root,string name)
{
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    name = FZZConst::replace_all(name,"\\","/");
//    if ( name[0] != '/' ) {
//        name = "/" + name;
//    }
//    map<string,FZZBytes*>* files = m_ofdFilesContainer[root];
//    if ( files == NULL ) {
//        DLOG("get file root=%s,name=%s",root.c_str(),name.c_str());
//        return NULL;
//    }
//    FZZBytes * temp = (*files)[name];
//    if ( temp == NULL ) {
//        DLOG("get file root=%s,name=%s",root.c_str(),name.c_str());
//        return NULL;
//    }
    string key = name+"||"+root;
    FZZBytes * temp = NULL;
    map<string,FZZBytes*>::const_iterator it = m_ofdFilesContainer.find(key);
    if (it != m_ofdFilesContainer.end()) {
        temp = it->second;
    }
    if ( temp == NULL ) {
        //DLOG("get file root=%s,name=%s",root.c_str(),name.c_str());
    }
    return temp;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFilesContainer::removeFile(string root,string name)
{
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    name = FZZConst::replace_all(name,"\\","/");
//    if ( name[0] != '/' ) {
//        name = "/" + name;
//    }
//    map<string,FZZBytes*>* files = m_ofdFilesContainer[root];
//    if ( files == NULL ) {
//        return;
//    }
//    if ( (*files)[name] != NULL ) {
//        delete (*files)[name];
//        files->erase(name);
//    }
    string key = name+"||"+root;
    map<string,FZZBytes*>::const_iterator it = m_ofdFilesContainer.find(key);
    if (it != m_ofdFilesContainer.end()) {
        if ( it->second != NULL ) {
            delete it->second;
        }
        m_ofdFilesContainer.erase(it);
    }
    //DLOG("remove file root=%s,name=%s",root.c_str(),name.c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFilesContainer::removeDirFile(string root,string name)
{
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    name = FZZConst::replace_all(name,"\\","/");
//    if ( name[0] != '/' ) {
//        name = "/" + name;
//    }
    
    vector<string> filesname;
    getFilesName(root,filesname);
    
    vector<string>::const_iterator iter;
    for (iter = filesname.begin(); iter != filesname.end(); iter++) {
        string filename = *iter;
        size_t pos = filename.find(name);
        if ( pos != string::npos ) {
            removeFile(root,filename);
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------

