//
//  FZZString.h
//  ofdcreate
//
//  Created by zizheng fan on 2022/1/18.
//

#ifndef FZZSTRING_H
#define FZZSTRING_H

#include "basic/FZZStringItem.h"

class FZZString
{
public:
    FZZString();
    FZZString(const FZZString& obj);
    FZZString(const string& data);
    FZZString(const char * data);
    const FZZString& operator=(const FZZString& data);
    const FZZString& operator=(const string& data);
    const FZZString& operator=(const char * data);
    FZZString& operator+=(const FZZString& data);
    FZZString& operator+=(const string& data);
    FZZString& operator+=(const char * data);
    FZZString operator+ (FZZString & right);
    FZZString operator+(const string& right);
    FZZString operator+(const char * right);
    bool operator==(const FZZString &right);
    bool operator!=(const FZZString &right);
    bool operator==(const string &right);
    bool operator!=(const string &right);
    bool operator==(const char * right);
    bool operator!=(const char * right);
    //vector index
    string operator[] (int pos);
    ~FZZString();
public:
    const char * c_str() { return m_data.c_str(); }
    string getString() const { return m_data; }
    int length() { return (int)m_items.size(); }
    int length_data() { return (int)m_data.length(); }
    void clear();
    //Convert from string index to vector index
    int convertIndexToItems(int index);
    //Convert vector index to string index
    int convertIndexToString(int index);
    
    //return vector index
    int find(const FZZString &data);
    int find(const string &data);
    int find(const char * data);
    int find(const FZZString &data,int begin);
    int find(const string &data,int begin);
    int find(const char * data,int begin);
    int find_last_of(const FZZString &data);
    int find_last_of(const string &data);
    int find_last_of(const char * data);
    //return string index
    int findString(const FZZString &data);
    int findString(const string &data);
    int findString(const char * data);
    int findString_last_of(const FZZString &data);
    int findString_last_of(const string &data);
    int findString_last_of(const char * data);
    //vector index
    FZZString substr(int begin);
    FZZString substr(int begin,int count);
    //string index
    FZZString substr_String(int begin);
    FZZString substr_String(int begin,int count);
    
    FZZString Trim();
    bool empty();
    
    void Remove(int index);
    void Remove(int index,int delcount);
    
private:
    void splitWord(const string & word, vector<FZZStringItem> & characters);
    
private:
    vector<FZZStringItem> m_items;
    string m_data;
};


#endif /* FZZSTRING_H */
