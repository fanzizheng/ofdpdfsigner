//
//  Created by zizheng fan on 2024/07/17.
//
#include "basic/FZZConst.h"
#include "fzfont/FZZTempFontList.h"
#include "fzfont/FZZTempFontCache.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZTempFontList**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZTempFontList::FZZTempFontList()
{
    //DLOG("FZZTempFontList()");
    FZZConst::addClassCount("FZZTempFontList");
}
//-----------------------------------------------------------------------------------------------------------------
FZZTempFontList::~FZZTempFontList()
{
    //DLOG("~FZZTempFontList()");
    FZZConst::delClassCount("FZZTempFontList");
    removeAll();
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache*  FZZTempFontList::addFontFile(fz_context *ctx,string fontName,string familyName,string fontFileName,const FZZBytes* fontFileData)
{
    FZZFontCache* fontCache = getFont(fontName,familyName,fontFileName);
    if ( fontCache != NULL ) {
        return fontCache;
    } else {
        if ( ctx == NULL ) {
            fontCache = new FZZTempFontCache();
        }else {
            fontCache = new FZZTempFontCache(ctx);
        }

        if ( fontCache == NULL ) return NULL;
        if ( !fontCache->load(*fontFileData) ) {
            delete fontCache;
            return NULL;
        }
        
        string key = fontName + "_" + familyName + "_" + fontFileName;
        auto isExitPari = m_TempCache.insert(pair<string,FZZFontCache*>(key ,fontCache));
        if ( !isExitPari.second ) {
            delete fontCache;
            return isExitPari.first->second;
        }
        return fontCache;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache*  FZZTempFontList::addFontFile(string fontName,string familyName,string fontFileName,const FZZBytes* fontFileData)
{
    return addFontFile(NULL,fontName,familyName,fontFileName,fontFileData);
//    FZZFontCache* fontCache = getFont(fontName,familyName,fontFileName);
//    if ( fontCache != NULL ) {
//        return fontCache;
//    } else {
//        fontCache = new FZZTempFontCache();
//
//        if ( fontCache == NULL ) return NULL;
//        if ( !fontCache->load(*fontFileData) ) {
//            delete fontCache;
//            return NULL;
//        }
//
//        string key = fontName + "_" + familyName + "_" + fontFileName;
//        m_TempCache.insert(pair<string,FZZFontCache*>(key ,fontCache));
//        return fontCache;
//    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache*  FZZTempFontList::addFontFile(string fontName,string familyName,string fontFileName)
{
    
    FZZFontCache* fontCache = getFont(fontName,familyName,fontFileName);
    if ( fontCache != NULL ) {
        
        return fontCache;
    } else {
       
        FZZBytes fontFileData;
        if ( !FZZConst::readfile(fontFileName,fontFileData) ) {
            DLOG("read font file error, filename = %s",fontFileName.c_str());
            return NULL;
        }
        
        
        fontCache = new FZZTempFontCache();
        if ( fontCache == NULL ) return NULL;
        if ( !fontCache->load(fontFileData)) {
            delete fontCache;
            return NULL;
        }
      
          
        string key = fontName + "_" + familyName + "_" + fontFileName;
        auto isExitPari = m_TempCache.insert(pair<string,FZZFontCache*>(key ,fontCache));
        if ( !isExitPari.second ) {
            delete fontCache;
            return isExitPari.first->second;
        }
        return fontCache;
    }
}

//-----------------------------------------------------------------------------------------------------------------
void FZZTempFontList::removeAll()
{
    map<string,FZZFontCache*>::const_iterator it_temp;
    for(it_temp = m_TempCache.begin(); it_temp != m_TempCache.end(); it_temp++) {
        if ( it_temp->second != NULL ) {
            delete it_temp->second;
        }
    }
    m_TempCache.clear();
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZTempFontList::isHave(string fontName,string familyName,string fontFileName)
{
    return getFont(fontName,familyName,fontFileName) == NULL ? false : true;
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache*  FZZTempFontList::getFont(string fontName,string familyName,string fontFileName)
{
    FZZFontCache * retFontCache = NULL;
    
    string key = fontName + "_" + familyName + "_" + fontFileName;
    map<string,FZZFontCache*>::iterator it = m_TempCache.find(key);
    if (it != m_TempCache.end()) {
        retFontCache =  it->second;
    } else {
        retFontCache = NULL;
    }

    return retFontCache;
}
//-----------------------------------------------------------------------------------------------------------------

