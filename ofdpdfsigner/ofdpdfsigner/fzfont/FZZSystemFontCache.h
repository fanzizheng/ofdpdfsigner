//
//  Created by zizheng fan on 2024/07/16.
//
#ifndef FZZSYSTEMFONTCACHE_H
#define FZZSYSTEMFONTCACHE_H

#include "fzfont/FZZTempFontCache.h"

class FZZSystemFontCache : public FZZTempFontCache
{
    
public:
    FZZSystemFontCache();
    FZZSystemFontCache(fz_context * ctx);
    virtual ~FZZSystemFontCache();
public:
    virtual bool load(const FZZBytes & fontdata);
    
    virtual bool isTempFont() {return false;}
    
   
private:
    void InitUnicharGlyphIDAndPath();
    
protected:
    
};

#endif //FZZSYSTEMFONTCACHE_H

