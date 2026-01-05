//
//  Created by zizheng fan on 2022/10/16.
//
#ifndef FZZBYTES_H
#define FZZBYTES_H


class FZZBytes
{
public:
    FZZBytes();
    FZZBytes(const unsigned char * const data,size_t len);
    FZZBytes(const FZZBytes& obj);
    virtual ~FZZBytes();
    const FZZBytes& operator=(const FZZBytes& data);
public:
    bool setData(const unsigned char * const data,size_t len);
    unsigned char * getData() const { return m_Data; }
    size_t getLen() const { return m_Len; }
    bool addData(const unsigned char * const data,size_t len);
    bool addData(const FZZBytes & data);
    void clear();
    
    bool setMaxLen(size_t bufferlen);
    bool setData_NotMalloc(const unsigned char * const data,size_t len);
    void setLen(size_t bufferlen) { m_Len = bufferlen; }
    unsigned char ** getDataRef() { return &m_Data; }
    
    void updataData(size_t index,unsigned char value);
protected:
    
private:

private:
    unsigned char * m_Data;
    size_t m_Len;
};

#endif //FZZBYTES_H

