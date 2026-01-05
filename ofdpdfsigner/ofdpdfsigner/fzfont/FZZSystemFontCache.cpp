//
//  Created by zizheng fan on 2024/07/16.
//
#include "basic/FZZConst.h"
#include "fzfont/FZZSystemFontCache.h"
#include <freetype/freetype.h>
#include <freetype/ftoutln.h>
#include <freetype/ftadvanc.h>



//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZSystemFontCache**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZSystemFontCache::FZZSystemFontCache() : FZZTempFontCache()
{
    //DLOG("FZZSystemFontCache()");
    FZZConst::addClassCount("FZZSystemFontCache");
    //time(&m_CreateTime);

    

}
//-----------------------------------------------------------------------------------------------------------------
FZZSystemFontCache::FZZSystemFontCache(fz_context * ctx) : FZZTempFontCache(ctx)
{
    //DLOG("FZZSystemFontCache()");
    FZZConst::addClassCount("FZZSystemFontCache");
    //time(&m_CreateTime);
}
//-----------------------------------------------------------------------------------------------------------------
FZZSystemFontCache::~FZZSystemFontCache()
{
    //DLOG("~FZZSystemFontCache()");
    FZZConst::delClassCount("FZZSystemFontCache");
    

}
//-----------------------------------------------------------------------------------------------------------------
bool FZZSystemFontCache::load(const FZZBytes & fontdata)
{
    bool isRet = false;
    DLOG("FZZSystemFontCache load begin");
    if ( m_CTX == NULL ) {
        return isRet;
    }
    if ( m_Font != NULL ) {
        return true;
    }
    m_FontData.setData(fontdata.getData(), fontdata.getLen());
    
    fz_try(m_CTX) {
        m_Font = fz_new_font_from_memory(m_CTX, NULL, m_FontData.getData(), (int)m_FontData.getLen(), 0, 0);
        if ( m_Font == NULL ) {
            return false;
        }
        m_familyName = m_Font->name;
        
    } fz_catch(m_CTX) {

    }
    
   
    
    InitUnicharGlyphIDAndPath();
    
    
    isRet = true;
    DLOG("FZZSystemFontCache load end");
    return isRet;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZSystemFontCache::InitUnicharGlyphIDAndPath()
{
    if ( m_CTX == NULL || m_Font == NULL ) {
        return;
    }
    
    if  ( m_UnicharToGlyphIDList.size() == 0 && m_GlyphIDToUnicharList == NULL ) {
        fz_try(m_CTX) {
            FT_Face face = (FT_Face)m_Font->ft_face;
            if ( face == NULL || face->num_glyphs <= 0 ) {
                return ;
            }
            m_GlyphIDToUnicharList = (int *)fz_calloc(m_CTX, face->num_glyphs, sizeof *m_GlyphIDToUnicharList);
            if ( m_GlyphIDToUnicharList == NULL ) {
                return ;
            }
            FT_UInt gid = 0;
            fz_ft_lock(m_CTX);
            FT_ULong ucs = FT_Get_First_Char(face, &gid);
            while (gid > 0)
            {
                if ( gid < (FT_ULong)face->num_glyphs ) {
                    m_GlyphIDToUnicharList[gid] = (int)ucs;
                    m_UnicharToGlyphIDList.emplace(ucs,gid);
                    
                    
//                    fz_path* fontPath = fz_outline_glyph(m_CTX,m_Font,gid,MUPDF_fz_identity);
//                    if ( fontPath != NULL ) {
//
//                        m_Paths.insert(pair<FzGlyphID,fz_path*>(gid,fontPath));
//                    }
                    fz_matrix font_matrix = { 1, 0, 0, -1, 0, 0 };
                    fz_path * tempfontPath = fz_outline_glyph(m_CTX,m_Font,gid,font_matrix);
                    //fontPath = fz_outline_ft_glyph_my(m_CTX,m_Font,value,MUPDF_fz_identity);
                    if ( tempfontPath != NULL ) {
                        FZZPath * fontPath = new FZZPath(m_CTX,tempfontPath);
                        if ( fontPath != NULL ) {
                            auto isExitPari = m_Paths.insert(pair<FzGlyphID,FZZPath*>(gid,fontPath));
                            if ( !isExitPari.second ) {
                                delete fontPath;
                            }
                        }
                        fz_drop_path(m_CTX, tempfontPath);
                    }
                    
                    fz_text * fontText = fz_new_text(m_CTX);
                    if ( fontText != NULL ) {
                        fz_show_glyph(m_CTX, fontText, m_Font,MUPDF_fz_identity,gid,0,false, 0, FZ_BIDI_NEUTRAL, FZ_LANG_UNSET);
                        auto isExitPari = m_Texts.insert(pair<FzGlyphID,fz_text*>(gid,fontText));
                        if ( !isExitPari.second ) {
                            fz_drop_text(m_CTX, fontText);
                        }
                    }
                
                }
                ucs = FT_Get_Next_Char(face, ucs, &gid);
            }
            fz_ft_unlock(m_CTX);
            
        } fz_catch(m_CTX) {
            
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
