//
//  FZZString.cpp
//  ofdcreate
//
//  Created by zizheng fan on 2022/1/18.
//

#include "basic/FZZConst.h"
#include "basic/FZZString.h"

//--------------------------------------------------------------------------------------------------------
/*****************************************************FZZString****************************************************/
//--------------------------------------------------------------------------------------------------------
FZZString::FZZString() : m_data("")
{
    //FZZConst::addClassCount("FZZString");
}
//--------------------------------------------------------------------------------------------------------
FZZString::FZZString(const FZZString& obj) :FZZString()
{
    if ( this == &obj ) {
        return;
    }
    clear();
    this->m_data = obj.m_data;
    splitWord(m_data,m_items);
}
//--------------------------------------------------------------------------------------------------------
FZZString::FZZString(const string& data) :FZZString()
{
    clear();
    m_data = data;
    splitWord(m_data,m_items);
}
//--------------------------------------------------------------------------------------------------------
FZZString::FZZString(const char * data) :FZZString()
{
    clear();
    m_data = data;
    splitWord(m_data,m_items);
}
//--------------------------------------------------------------------------------------------------------
const FZZString& FZZString::operator=(const FZZString& data)
{
    if ( this == &data ) {
        return *this;
    }
    clear();
    this->m_data = data.m_data;
    splitWord(m_data,m_items);
    return *this;
}
//--------------------------------------------------------------------------------------------------------
const FZZString& FZZString::operator=(const string& data)
{
    
    clear();
    m_data = data;
    splitWord(m_data,m_items);
    return *this;
}
//--------------------------------------------------------------------------------------------------------
const FZZString& FZZString::operator=(const char * data)
{
    
    clear();
    m_data = data;
    splitWord(m_data,m_items);
    return *this;
}
//--------------------------------------------------------------------------------------------------------
FZZString& FZZString::operator+=(const FZZString& data)
{
    this->m_data = this->m_data + data.m_data;
    m_items.clear();
    splitWord(this->m_data,m_items);
    return *this;
}
//--------------------------------------------------------------------------------------------------------
FZZString& FZZString::operator+=(const string& data)
{
    this->m_data = this->m_data + data;
    m_items.clear();
    splitWord(this->m_data,m_items);
    return *this;
}
//--------------------------------------------------------------------------------------------------------
FZZString& FZZString::operator+=(const char * data)
{
    this->m_data = this->m_data + data;
    m_items.clear();
    splitWord(this->m_data,m_items);
    return *this;
}
//--------------------------------------------------------------------------------------------------------
FZZString FZZString::operator+ (FZZString & right)
{
    FZZString temp = *this;
    temp += right;
    return temp;
}
//--------------------------------------------------------------------------------------------------------
FZZString FZZString::operator+(const string& right)
{
    FZZString temp = *this;
    temp += right;
    return temp;
}
//--------------------------------------------------------------------------------------------------------
FZZString FZZString::operator+(const char * right)
{
    FZZString temp = *this;
    temp += right;
    return temp;
}
//--------------------------------------------------------------------------------------------------------
bool FZZString::operator==(const FZZString &right)
{
    if ( this == &right ) {
        return true;
    }
    
    return this->m_data == right.m_data;
}
//--------------------------------------------------------------------------------------------------------
bool FZZString::operator!=( const FZZString &right)
{
    if ( this == &right ) {
        return false;
    }
    return !(*this == right);
}
//--------------------------------------------------------------------------------------------------------
bool FZZString::operator==(const string &right)
{
    return this->m_data == right;
}
//--------------------------------------------------------------------------------------------------------
bool FZZString::operator!=(const string &right)
{
    return this->m_data != right;
}
//--------------------------------------------------------------------------------------------------------
bool FZZString::operator==(const char * right)
{
    return this->m_data == right;
}
//--------------------------------------------------------------------------------------------------------
bool FZZString::operator!=(const char * right)
{
    return this->m_data == right;
}
//--------------------------------------------------------------------------------------------------------
string FZZString::operator[] (int pos)
{
    string ret;
    if ( pos < m_items.size() ) {
        //FZZStringItem temp = *(m_items.begin()+pos);
        ret = (*(m_items.begin()+pos)).getData();
        //ret = m_items[pos].getData();
    }
    return ret;
}
//--------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------
FZZString::~FZZString()
{
    //FZZConst::delClassCount("FZZString");
    clear();
}
//--------------------------------------------------------------------------------------------------------
void FZZString::clear()
{
    m_data = "";
    m_items.clear();
}
//--------------------------------------------------------------------------------------------------------
int FZZString::find(const FZZString &data)
{
    int pos = (int)m_data.find(data.getString());
    if ( pos == string::npos ) {
        return (int)(string::npos);
    } else {
        return convertIndexToItems(pos);
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::find(const string &data)
{
    int pos = (int)m_data.find(data);
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return convertIndexToItems(pos);
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::find(const char * data)
{
    int pos = (int)m_data.find(data);
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return convertIndexToItems(pos);
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::find(const FZZString &data,int begin)
{
    FZZString content = substr(begin);
    int pos = content.find(data);
    if ( pos != string::npos ) {
        pos = pos+begin;
    }
    return pos;
}
//--------------------------------------------------------------------------------------------------------
int FZZString::find(const string &data,int begin)
{
    FZZString content = substr(begin);
    int pos = content.find(data);
    if ( pos != string::npos ) {
        pos = pos+begin;
    }
    return pos;
}
//--------------------------------------------------------------------------------------------------------
int FZZString::find(const char * data,int begin)
{
    FZZString content = substr(begin);
    int pos = content.find(data);
    if ( pos != string::npos ) {
        pos = pos+begin;
    }
    return pos;
}
//--------------------------------------------------------------------------------------------------------
int FZZString::findString(const FZZString &data)
{
    int pos = (int)m_data.find(data.getString());
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return pos;
    }
   
}
//--------------------------------------------------------------------------------------------------------
int FZZString::findString(const string &data)
{
    int pos = (int)m_data.find(data);
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return pos;
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::findString(const char * data)
{
    int pos = (int)m_data.find(data);
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return pos;
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::find_last_of(const FZZString &data)
{
    int pos = (int)m_data.rfind(data.getString());
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return convertIndexToItems(pos);
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::find_last_of(const string &data)
{
    int pos = (int)m_data.rfind(data);
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return convertIndexToItems(pos);
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::find_last_of(const char * data)
{
    int pos = (int)m_data.rfind(data);
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return convertIndexToItems(pos);
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::findString_last_of(const FZZString &data)
{
    int pos = (int)m_data.rfind(data.getString());
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return pos;
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::findString_last_of(const string &data)
{
    int pos = (int)m_data.rfind(data);
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return pos;
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::findString_last_of(const char * data)
{
    int pos = (int)m_data.rfind(data);
    if ( pos == string::npos ) {
        return (int)string::npos;
    } else {
        return pos;
    }
}
//--------------------------------------------------------------------------------------------------------
FZZString FZZString::substr(int begin)
{
    FZZString ret;
    if ( begin != string::npos ) {
        int index = convertIndexToString(begin);
        if ( index < m_data.length() ) {
            ret = m_data.substr(index);
        }
    }
    return ret;
}
//--------------------------------------------------------------------------------------------------------
FZZString FZZString::substr(int begin,int count)
{
    FZZString ret;
    if ( begin != string::npos ) {
        if ( begin < m_items.size() && begin+count <= m_items.size() ) {
            int index = convertIndexToString(begin);
            int endindex = convertIndexToString(begin+count-1);
            
            ret = m_data.substr(index,endindex-index+m_items[begin+count-1].getData().length());
        }
    }
    return ret;
}
//--------------------------------------------------------------------------------------------------------
FZZString FZZString::substr_String(int begin)
{
    FZZString ret;
    if ( begin != string::npos && begin < m_data.length() ) {
        ret = m_data.substr(begin);
    }
    return ret;
}
//--------------------------------------------------------------------------------------------------------
FZZString FZZString::substr_String(int begin,int count)
{
    FZZString ret;
    if ( begin != string::npos && begin < m_data.length() && begin+count <= m_data.length() ) {
        ret = m_data.substr(begin,count);
    }
    return ret;
}
//--------------------------------------------------------------------------------------------------------
FZZString FZZString::Trim()
{
    FZZString ret = FZZConst::Trim(m_data);
    return ret;
}
//--------------------------------------------------------------------------------------------------------
bool FZZString::empty()
{
    return m_data.empty();
}
//--------------------------------------------------------------------------------------------------------
void FZZString::splitWord(const string & word, vector<FZZStringItem> & characters)
{

    int num = (int)word.size();
    int i = 0;
    while(i < num)
    {
        int size;
#ifdef _MSC_VER
        unsigned char tempc = word[i];
        if (tempc > 127) {
            size = 2;
        }
        else {
            size = 1;
        }
#else
        if(word[i] & 0x80)
        {
            if(word[i] & 0x20)
            {
                if(word[i] & 0x10)
                {
                    if(word[i] & 0x08)
                    {
                        if(word[i] & 0x04)
                        {
                                size = 6;
                        }else{
                            size = 5;
                        }
                    }else{
                        size = 4;
                    }
                }else{
                    size = 3;
                }
            }else{
                size = 2;
            }
        }else{
            size = 1;
        }
#endif
        string subWord;
        subWord = word.substr(i, size);
        FZZStringItem stringItem(subWord,i,(int)characters.size());
        //DLOG("St_string = ...... %s,%d,%d",stringItem.getData().c_str(),stringItem.getIndex(),stringItem.getDataIndex());
        characters.push_back(stringItem);
        i += size;
    }
}
//--------------------------------------------------------------------------------------------------------
int FZZString::convertIndexToItems(int index)
{
    for ( int i = 0; i < m_items.size(); i++ ) {
        if ( m_items[i].getDataIndex() == index ) {
            return m_items[i].getIndex();
        }
    }
    return (int)string::npos;
}
//--------------------------------------------------------------------------------------------------------
int FZZString::convertIndexToString(int index)
{
    for ( int i = 0; i < m_items.size(); i++ ) {
        if ( m_items[i].getIndex() == index ) {
            return m_items[i].getDataIndex();
        }
    }
    return (int)string::npos;
}
//--------------------------------------------------------------------------------------------------------
void FZZString::Remove(int index)
{
    string::iterator itr = m_data.begin();
    itr += index;
    m_data.erase(itr);
    
    vector<FZZStringItem>::iterator  itr1 = m_items.begin();
    itr1 += index;
    m_items.erase(itr1);
}
//--------------------------------------------------------------------------------------------------------
void FZZString::Remove(int index,int delcount)
{
    string::iterator itr = m_data.begin();
    itr += index;
    string::iterator itr_end = itr+delcount;
    m_data.erase(itr,itr_end);
    
    vector<FZZStringItem>::iterator  itr1 = m_items.begin();
    itr1 += index;
    vector<FZZStringItem>::iterator  itr1_end = itr1+delcount;
    m_items.erase(itr1,itr1_end);
}
//--------------------------------------------------------------------------------------------------------
