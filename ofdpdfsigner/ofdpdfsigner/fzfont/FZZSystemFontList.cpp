//
//  Created by zizheng fan on 2024/07/17.
//
#include "basic/FZZConst.h"
#include "fzfont/FZZSystemFontList.h"
#include "fzfont/FZZSystemFontCache.h"



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZSystemFontList**************************************************************/
//-----------------------------------------------------------------------------------------------------------------

FZZSystemFontList::FZZSystemFontList()
{
    //DLOG("FZZSystemFontList()");
    FZZConst::addClassCount("FZZSystemFontList");
    addDefaultFont();
}
//-----------------------------------------------------------------------------------------------------------------
FZZSystemFontList::~FZZSystemFontList()
{
    //DLOG("~FZZSystemFontList()");
    FZZConst::delClassCount("FZZSystemFontList");
    removeAll();
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache* FZZSystemFontList::addDefaultFont()
{
    
    if ( !FZZConst::g_FZFontConfig.isLoad() ) {
        FZZBytes fontData;
        FZZConst::readfile(FZZConst::getDefaultFontPath()+"fonts.json", fontData);
        FZZBytes jsonData;
        jsonData.setMaxLen(fontData.getLen()+3);
        jsonData.setData_NotMalloc(fontData.getData(), fontData.getLen());
        FZZConst::g_FZFontConfig.load((char *)jsonData.getData());
    }
    return addFontFile(FZZConst::g_FZFontConfig.getDefaultFontName(),FZZConst::g_FZFontConfig.getDefaultFontFile());
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache* FZZSystemFontList::addFontFile(string fontName,const FZZBytes* fontFileData)
{
    
    FZZFontCache* fontCache = getFont(fontName);
    if ( fontCache != NULL ) {
        return fontCache;
    } else {
        
        fontCache = new FZZSystemFontCache();
        if ( fontCache == NULL ) return NULL;
        if ( !fontCache->load(*fontFileData) ) {
            delete fontCache;
            return NULL;
        }
        
        string key = fontName;
        auto isExitPari = m_TempCache.insert(pair<string,FZZFontCache*>(key ,fontCache));
        if ( !isExitPari.second ) {
            delete fontCache;
            return isExitPari.first->second;
        }
        return fontCache;
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache*  FZZSystemFontList::addFontFile(string fontName,string fontFileName)
{
    
    FZZFontCache* fontCache = getFont(fontName);
    if ( fontCache != NULL ) {
        
        return fontCache;
    } else {
       
        FZZBytes fontFileData;
        if ( !FZZConst::readfile(fontFileName,fontFileData) ) {
            DLOG("read font file error, filename = %s",fontFileName.c_str());
            return NULL;
        }
        
        
        
        fontCache = new FZZSystemFontCache();
        if ( fontCache == NULL ) return NULL;
        if ( !fontCache->load(fontFileData)) {
            delete fontCache;
            return NULL;
        }
      
          
        string key = fontName;
        auto isExitPari = m_TempCache.insert(pair<string,FZZFontCache*>(key ,fontCache));
        if ( !isExitPari.second ) {
            delete fontCache;
            return isExitPari.first->second;
        }
        return fontCache;
    }
}

//-----------------------------------------------------------------------------------------------------------------
void FZZSystemFontList::removeAll()
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
bool FZZSystemFontList::isHave(string fontName)
{
    return getFont(fontName) == NULL ? false : true;
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache*  FZZSystemFontList::getFont(string fontName)
{
    FZZFontCache * retFontCache = NULL;
    
    string key = fontName;
    map<string,FZZFontCache*>::iterator it = m_TempCache.find(key);
    if (it != m_TempCache.end()) {
        retFontCache =  it->second;
    } else {
        retFontCache = NULL;
    }

    return retFontCache;
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache* FZZSystemFontList::findFont(string inFontName)
{
    string outFontName = "";
    return findFont(inFontName,outFontName);
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache* FZZSystemFontList::findFont(string inFontName,string &outFontName)
{
    FZZFontCache* retSKFont = NULL;
    
    if ( inFontName.empty() ) {
        retSKFont = addDefaultFont();
        outFontName = FZZConst::g_FZFontConfig.getDefaultFontName();
        return retSKFont;
    }
    
    outFontName = inFontName;
    if ( (retSKFont = getFont(inFontName)) == NULL ) {
        string fontname = FZZConst::g_FZFontConfig.ConvertSysFontName(inFontName);
        if ( fontname.empty() ) {
            retSKFont = addDefaultFont();
            outFontName = FZZConst::g_FZFontConfig.getDefaultFontName();
        } else {
            outFontName = fontname;
            retSKFont = getFont(fontname);
            if ( retSKFont == NULL ) {
                
                vector<string> fullpaths;
                FZZConst::g_FZFontConfig.getSysFontFullPath(fontname,fullpaths);
                vector<string>::const_iterator ita;
                for( ita = fullpaths.begin(); ita != fullpaths.end(); ita++ ) {
                    string tempstrita = *ita;
                    if ( !tempstrita.empty() ) {
                        addFontFile(FZZConst::g_FZFontConfig.getFontName_FullPath(tempstrita),tempstrita);
                    }
                }
                outFontName = fontname;
                retSKFont = getFont(fontname);
                if ( retSKFont == NULL ) {
                    retSKFont = addDefaultFont();
                    outFontName = FZZConst::g_FZFontConfig.getDefaultFontName();
                }
            }

        }
    }
        
    return retSKFont;
}
//-----------------------------------------------------------------------------------------------------------------
