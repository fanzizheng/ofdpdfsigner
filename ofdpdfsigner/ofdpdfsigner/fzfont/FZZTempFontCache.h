//
//  Created by zizheng fan on 2024/07/16.
//
#ifndef FZZTEMPFONTCACHE_H
#define FZZTEMPFONTCACHE_H

#include "fzfont/FZZFontCache.h"

class FZZTempFontCache : public FZZFontCache
{
    
public:
    FZZTempFontCache();
    FZZTempFontCache(fz_context * ctx);
    virtual ~FZZTempFontCache();
public:
    //
    virtual bool load(const FZZBytes & fontdata);
    virtual FzGlyphID unicharToGlyph(FzUnichar value);
    
    virtual FzUnichar GlyphToUnichar(FzGlyphID value);

    virtual const FZZPath* getPath(FzGlyphID value);
    virtual const fz_text* getText(FzGlyphID value);
    
    virtual string getFamilyName() {return m_familyName;}
    virtual string getPostscriptName() { return m_postscriptName; }
    
    virtual bool isTempFont() {return true;}

    
    virtual const FZZBytes * getFontData() { return &m_FontData; }
    
    unordered_map<FzUnichar, FzGlyphID> * getWords() { return &m_UnicharToGlyphIDList; }
    
    virtual const fz_font * getFZFont() { return m_Font;}
    
private:
    void InitUnicharAndGlyphID();
    
protected:
    string m_familyName;
    string m_postscriptName;
    FZZBytes m_FontData;
    
    fz_font * m_Font;
    int * m_GlyphIDToUnicharList;
    map<FzGlyphID,FZZPath*> m_Paths;
    map<FzGlyphID,fz_text*> m_Texts;
    unordered_map<FzUnichar, FzGlyphID> m_UnicharToGlyphIDList;
};

#endif //FZZTEMPFONTCACHE_H

