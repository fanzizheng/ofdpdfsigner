//
//  Created by zizheng fan on 2024/07/17.
//
#ifndef FZZTEMPFONTLIST_H
#define FZZTEMPFONTLIST_H

#include "fzfont/FZZFontCache.h"


class FZZTempFontList
{
public:
    FZZTempFontList();
    ~FZZTempFontList();
public:
    
    FZZFontCache*  addFontFile(string fontName,string familyName,string fontFileName,const FZZBytes* fontFileData);
    FZZFontCache*  addFontFile(fz_context *ctx,string fontName,string familyName,string fontFileName,const FZZBytes* fontFileData);
    FZZFontCache*  addFontFile(string fontName,string familyName,string fontFileName);
    
    void removeAll();
    bool isHave(string fontName,string familyName,string fontFileName);
    FZZFontCache*  getFont(string fontName,string familyName,string fontFileName);
    
private:
   
private:
    
    map<string,FZZFontCache*> m_TempCache;

};

#endif //FZZTEMPFONTLIST_H

