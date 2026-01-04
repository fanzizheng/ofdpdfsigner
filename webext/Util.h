
#ifndef RESTFULSERVER_UNTIL_H
#define RESTFULSERVER_UNTIL_H

#include "mongoose.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <type_traits>


using namespace std;

#include <QString>
#ifdef _MSC_VER || _WIN32 || _WIN64

#include <QLabel>
#include <QDir>
#include <QSettings>
#include "qtservice.h"

#endif

class FZZBytes;

#define DIFFTIME 60*30

#ifdef  _MSC_VER || _WIN32 || _WIN64
     static const char * FILEPATH = "C:/fakepath/";
#else
     static const char * FILEPATH = "/Users/zizhengfan/work/cpp/ofd/tmp/signpdf/";
#endif



struct FILETEMPCACHE {
    int filetype;
    string* filebase64;
    FZZBytes* filedata;
    vector<FZZBytes*> * pages;
    void * docHandle;
};

extern map<string,FILETEMPCACHE*> g_FilesContainer;

FILETEMPCACHE * newFileTempCache();
void DeleteFileTempCache(FILETEMPCACHE * filecache);
void AddFiles(string fileid,FZZBytes* filedata,int filetype);
void AddFiles_Page(string fileid,FZZBytes* Page);

void AddFiles_base64(string fileid,string filedata);
void clearFiles_base64(string fileid);
string getFiles_base64(string fileid);

int getFiles_PageCount(string fileid);
FZZBytes * getFiles_Page(string fileid,int pageIndex);
FZZBytes * getFiles_FileData(string fileid);
int getFiles_FileType(string fileid);

void DeleteFiles(string fileid);
void RenovateFiles();
string genFileID();
void split(const char* s, const char* delim,std::vector<std::string> & rets);

char* random_uuid(char buf[37]);
string replace_all(string str,const string old_value,const string new_value);
string getGetParam(const struct mg_http_message *hm);
bool readfile(QString srcfile,FZZBytes& outData);
bool writefile(QString srcfile,const unsigned char * const data,int len);
string fmt(double d);
string fmt(int d);
string fmt(long d);
string fmt(long long d);

string Base64Encode(const unsigned char * const data,int len);
void Base64_decode(const char * base64str,int base64strlen,FZZBytes & out);

#endif //RESTFULSERVER_UNTIL_H

