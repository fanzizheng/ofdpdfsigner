//
//  Created by zizheng fan on 2024/07/16.
//
#ifndef FZZFONTCACHE_H
#define FZZFONTCACHE_H

#include "basic/FZZObject.h"
#include "basic/FZZPath.h"

class FZZFontCache : public FZZObject
{
public:
    struct FontPair {
        FZZFontCache* FZZFontCache;
        int index;
    };
public:
    FZZFontCache();
    FZZFontCache(fz_context * ctx);
    virtual ~FZZFontCache();
public:
    virtual bool load(const FZZBytes & fontdata) = 0;
    virtual FzGlyphID unicharToGlyph(FzUnichar value) = 0;
    
    virtual FzUnichar GlyphToUnichar(FzGlyphID value) = 0;

    virtual const FZZPath* getPath(FzGlyphID value) = 0;
    virtual const fz_text* getText(FzGlyphID value) = 0;
    
    virtual string getFamilyName() = 0;
    virtual string getPostscriptName() = 0;
    
    virtual bool isTempFont() = 0;
    
    virtual const FZZBytes * getFontData() = 0;
    
    virtual const fz_font * getFZFont() = 0;
    
public:
    
private:
    
protected:
    
};

#endif //FZZFONTCACHE_H

