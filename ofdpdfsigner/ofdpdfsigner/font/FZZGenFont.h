//
//  Created by zizheng fan on 2022/08/25.
//
#ifndef FZZGENFONT_H
#define FZZGENFONT_H


#include <set>
//Shrink the font according to the current font and generate a new font
//Currently, the kComposite type, that is, combined fonts, is not supported (for example, a new path is formed by combining the paths of two fonts). In this case, its path is NULL. For example, 1126 in Tahoma font
//If you want to solve this problem, you can use the unmodified sfntry, but it retains the Glyph table, causing the font to be too large.

class FZZGenFont
{
public:
    FZZGenFont();
    ~FZZGenFont();
public:
    //A Chinese character or an English character can not be added with a string
    void addData(string data);
    void addData(int32_t data);
    void setOldFont(FZZBytes & OldFontData) {
        if ( OldFontData.getLen() > 0 ) {
            m_OldFontData.setData(OldFontData.getData(),OldFontData.getLen());
        }
    }
    
    void setOldFont(const unsigned char * const data,size_t len) {
        if ( data != NULL && len > 0 ) {
            m_OldFontData.setData(data,len);
        }
    }
    
    bool genNewFont(FZZBytes & newFontData);
    bool genNewFont() {
        if ( !m_isGenNewFontOK ) {
            m_NewFontData.clear();
            m_isGenNewFontOK = genNewFont(m_NewFontData);
        }
        return m_isGenNewFontOK;
    }
    
    FZZBytes * getNewFontData() {return &m_NewFontData;}
    
    void setIsGenFont(bool isGenFont) { m_isGenFont = isGenFont; }
    bool isGenFont() { return m_isGenFont; }
    
    //string WstringToString(wstring & wstr);
private:
    
    uint32_t StringToWstring(const char* utf8Bytes);
private:
    //string m_NewFontCharData;
    //unordered_set<int32_t> m_NewFontCharData;
    set<int32_t> m_NewFontCharData;
    FZZBytes m_OldFontData;
    FZZBytes m_NewFontData;
    bool m_isGenNewFontOK;
    bool m_isGenFont;
};

#endif //FZZGENFONT_H

