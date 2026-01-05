//
//  FZZString.h
//  ofdcreate
//
//  Created by zizheng fan on 2022/1/18.
//

#ifndef FZZSTRINGITEM_H
#define FZZSTRINGITEM_H


class FZZStringItem
{
public:
    FZZStringItem();
    FZZStringItem(const string& data,int dataindex,int index);
    FZZStringItem(const FZZStringItem& obj);
    const FZZStringItem& operator=(const FZZStringItem& data);
    ~FZZStringItem();
public:
    void setData(const string& data) { m_data = data; }
    string getData() { return m_data; }
    //string index
    void setDataIndex(int dataindex) { m_dataindex = dataindex; }
    int getDataIndex() { return m_dataindex; }
    //seq index
    void setIndex(int index) { m_index = index; }
    int getIndex() { return m_index; }
private:
  
private:
    string m_data;
    int m_dataindex; //string index
    int m_index;//seq index
    
};


#endif /* FZZSTRINGITEM_H */
