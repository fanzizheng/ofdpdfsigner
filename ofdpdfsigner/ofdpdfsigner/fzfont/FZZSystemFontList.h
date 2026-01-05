//
//  Created by zizheng fan on 2024/07/17.
//
#ifndef FZZSYSTEMFONTLIST_H
#define FZZSYSTEMFONTLIST_H

#include "fzfont/FZZFontCache.h"

class FZZSystemFontList
{
public:
    FZZSystemFontList();
    ~FZZSystemFontList();
public:
    FZZFontCache* addDefaultFont();
    FZZFontCache*  addFontFile(string fontName,const FZZBytes* fontFileData);
    FZZFontCache*  addFontFile(string fontName,string fontFileName);
    
    void removeAll();
    bool isHave(string fontName);
    FZZFontCache*  getFont(string fontName);
    
    FZZFontCache* findFont(string inFontName);
    
    FZZFontCache* findFont(string inFontName,string &outFontName);
    
private:
    
    map<string,FZZFontCache*> m_TempCache;

};

#endif //FZZSYSTEMFONTLIST_H

