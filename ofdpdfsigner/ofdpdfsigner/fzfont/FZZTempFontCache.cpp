//
//  Created by zizheng fan on 2024/07/16.
//
#include "basic/FZZConst.h"
#include "fzfont/FZZTempFontCache.h"
#include <freetype/freetype.h>
#include <freetype/ftoutln.h>
#include <freetype/ftadvanc.h>

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZTempFontCache**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZTempFontCache::FZZTempFontCache() : FZZFontCache(), m_familyName(""),m_postscriptName(""),m_Font(NULL),m_GlyphIDToUnicharList(NULL)
{
    //DLOG("FZZTempFontCache()");
    FZZConst::addClassCount("FZZTempFontCache");
    //time(&m_CreateTime);
}
//-----------------------------------------------------------------------------------------------------------------
FZZTempFontCache::FZZTempFontCache(fz_context * ctx) : FZZFontCache(ctx), m_familyName(""),m_postscriptName(""),m_Font(NULL),m_GlyphIDToUnicharList(NULL)
{
    //DLOG("FZZTempFontCache()");
    FZZConst::addClassCount("FZZTempFontCache");
    //time(&m_CreateTime);
}
//-----------------------------------------------------------------------------------------------------------------
FZZTempFontCache::~FZZTempFontCache()
{
    //DLOG("~FZZTempFontCache()");
    FZZConst::delClassCount("FZZTempFontCache");
    
    if ( m_GlyphIDToUnicharList != NULL ) {
        fz_free(m_CTX, m_GlyphIDToUnicharList);
        m_GlyphIDToUnicharList = NULL;
    }
    
    m_UnicharToGlyphIDList.clear();
    
    map<FzGlyphID,FZZPath*>::const_iterator it;
 
    for (it = m_Paths.begin(); it != m_Paths.end(); it++) {
        FZZPath * temp = it->second;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_Paths.clear();
    
    map<FzGlyphID,fz_text*>::const_iterator it_text;
 
    for (it_text = m_Texts.begin(); it_text != m_Texts.end(); it_text++) {
        fz_text * temp = it_text->second;
        if ( temp != NULL ) {
            fz_drop_text(m_CTX, temp);
        }
    }
    m_Texts.clear();
    
    
    if ( m_Font != NULL ) {
        fz_drop_font(m_CTX, m_Font);
        m_Font = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZTempFontCache::load(const FZZBytes & fontdata)
{
    bool isRet = false;
    if ( m_CTX == NULL ) {
        return isRet;
    }
    if ( m_Font != NULL ) {
        return true;
    }
    m_FontData.setData(fontdata.getData(), fontdata.getLen());
    
    fz_try(m_CTX) {
        m_Font = fz_new_font_from_memory(m_CTX, NULL, m_FontData.getData(), (int)m_FontData.getLen(), 0, 0);
        //m_Font = fz_new_font_from_memory(m_CTX, NULL, m_FontData.getData(), (int)m_FontData.getLen(), 0, 1);
    if ( m_Font == NULL ) {
        return false;
    }
    m_familyName = m_Font->name;
        
    } fz_catch(m_CTX) {
        DLOG("FZZTempFontCache::load err.");
    }
    
    
    InitUnicharAndGlyphID();
    
    
    isRet = true;
    return isRet;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZTempFontCache::InitUnicharAndGlyphID()
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
                }
                ucs = FT_Get_Next_Char(face, ucs, &gid);
            }
            fz_ft_unlock(m_CTX);
            
        } fz_catch(m_CTX) {

        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FzGlyphID FZZTempFontCache::unicharToGlyph(FzUnichar ucs)
{
    FzGlyphID retGid = 0;
    if ( m_CTX == NULL || m_Font == NULL ) {
        return retGid;
    }
//    //FzGlyphID idx = FT_Get_Char_Index((FT_Face)(m_Font->ft_face), ucs);
////    return ft_char_index(m_Font->ft_face,ucs);

 //   return fz_encode_character(m_CTX, m_Font, ucs);
////    if (m_Font->ft_face)
////    {
////        int idx;
////        if (ucs >= 0 && ucs < 0x10000)
////        {
////            int pg = ucs >> 8;
////            int ix = ucs & 0xFF;
////            if (!m_Font->encoding_cache[pg])
////            {
////                int i;
////                m_Font->encoding_cache[pg] = fz_malloc_array(m_CTX, 256, uint16_t);
////                fz_ft_lock(m_CTX);
////                for (i = 0; i < 256; ++i)
////                    m_Font->encoding_cache[pg][i] = ft_char_index(m_Font->ft_face, (pg << 8) + i);
////                fz_ft_unlock(m_CTX);
////            }
////            return m_Font->encoding_cache[pg][ix];
////        }
////        fz_ft_lock(m_CTX);
////        idx = ft_char_index(m_Font->ft_face, ucs);
////        fz_ft_unlock(m_CTX);
////        return idx;
////    }
////    return ucs;
//
//    GlyphToUnichar(1);
//    for( int i = 0; i < m_Font->glyph_count; i++ ) {
//        if ( m_GlyphIDToUnicharList[i] == ucs ) {
//            return i;
//        }
//    }
    
    unordered_map<int, int>::const_iterator it = m_UnicharToGlyphIDList.find(ucs);
    if (it != m_UnicharToGlyphIDList.end()) {
        retGid = it->second;
    }
    return retGid;
}
//-----------------------------------------------------------------------------------------------------------------
FzUnichar FZZTempFontCache::GlyphToUnichar(FzGlyphID value)
{
    FzUnichar ucharValue = 0;
    if ( m_CTX == NULL || m_Font == NULL ) {
        return ucharValue;
    }
    if ( m_GlyphIDToUnicharList != NULL && value < m_Font->glyph_count ) {
        ucharValue = m_GlyphIDToUnicharList[value];
    }
//    else {
//        fz_try(m_CTX) {
//            FT_Face face = (FT_Face)m_Font->ft_face;
//            if ( face->num_glyphs <= 0 ) {
//                return ucharValue;
//            }
//            m_GlyphIDToUnicharList = (int *)fz_calloc(m_CTX, face->num_glyphs, sizeof *m_GlyphIDToUnicharList);
//            if ( m_GlyphIDToUnicharList == NULL ) {
//                return ucharValue;
//            }
//            FT_UInt gid;
//            fz_ft_lock(m_CTX);
//            FT_ULong ucs = FT_Get_First_Char(face, &gid);
//            while (gid > 0)
//            {
//                if ( gid < (FT_ULong)face->num_glyphs )
//                    m_GlyphIDToUnicharList[gid] = (int)ucs;
//                ucs = FT_Get_Next_Char(face, ucs, &gid);
//            }
//            fz_ft_unlock(m_CTX);
//            ucharValue = m_GlyphIDToUnicharList[value];
//        } fz_catch(m_CTX) {
//
//        }
//    }
    
    return ucharValue;
}
//-----------------------------------------------------------------------------------------------------------------
/* 20 degrees */
//#define SHEAR 0.36397f
//
//struct closure {
//    fz_context *ctx;
//    fz_path *path;
//    fz_matrix trm;
//};
//
//static int move_to(const FT_Vector *p, void *cc_)
//{
//    struct closure *cc = (struct closure *)cc_;
//    fz_context *ctx = cc->ctx;
//    fz_path *path = cc->path;
//    fz_point pt;
//
//    pt = fz_transform_point_xy(p->x, p->y, cc->trm);
//    fz_moveto(ctx, path, pt.x, pt.y);
//    return 0;
//}
//
//static int line_to(const FT_Vector *p, void *cc_)
//{
//    struct closure *cc = (struct closure *)cc_;
//    fz_context *ctx = cc->ctx;
//    fz_path *path = cc->path;
//    fz_point pt;
//
//    pt = fz_transform_point_xy(p->x, p->y, cc->trm);
//    fz_lineto(ctx, path, pt.x, pt.y);
//    return 0;
//}
//
//static int conic_to(const FT_Vector *c, const FT_Vector *p, void *cc_)
//{
//    struct closure *cc = (struct closure *)cc_;
//    fz_context *ctx = cc->ctx;
//    fz_path *path = cc->path;
//    fz_point ct, pt;
//
//    ct = fz_transform_point_xy(c->x, c->y, cc->trm);
//    pt = fz_transform_point_xy(p->x, p->y, cc->trm);
//
//    fz_quadto(ctx, path, ct.x, ct.y, pt.x, pt.y);
//    return 0;
//}
//
//static int cubic_to(const FT_Vector *c1, const FT_Vector *c2, const FT_Vector *p, void *cc_)
//{
//    struct closure *cc = (struct closure *)cc_;
//    fz_context *ctx = cc->ctx;
//    fz_path *path = cc->path;
//    fz_point c1t, c2t, pt;
//
//    c1t = fz_transform_point_xy(c1->x, c1->y, cc->trm);
//    c2t = fz_transform_point_xy(c2->x, c2->y, cc->trm);
//    pt = fz_transform_point_xy(p->x, p->y, cc->trm);
//
//    fz_curveto(ctx, path, c1t.x, c1t.y, c2t.x, c2t.y, pt.x, pt.y);
//    return 0;
//}
//
//static const FT_Outline_Funcs outline_funcs = {
//    move_to, line_to, conic_to, cubic_to, 0, 0
//};
//
//static fz_matrix *
//fz_adjust_ft_glyph_width(fz_context *ctx, fz_font *font, int gid, fz_matrix *trm)
//{
//    /* Fudge the font matrix to stretch the glyph if we've substituted the font. */
//    if (font->flags.ft_stretch && font->width_table /* && font->wmode == 0 */)
//    {
//        FT_Error fterr;
//        FT_Fixed adv = 0;
//        float subw;
//        float realw;
//
//        fz_ft_lock(ctx);
//        fterr = FT_Get_Advance((FT_Face)font->ft_face, gid, FT_LOAD_NO_SCALE | FT_LOAD_NO_HINTING | FT_LOAD_IGNORE_TRANSFORM, &adv);
//        fz_ft_unlock(ctx);
//        if (fterr && fterr != FT_Err_Invalid_Argument)
//            fz_warn(ctx, "FT_Get_Advance(%s,%d): %s", font->name, gid, ft_error_string(fterr));
//
//        realw = adv * 1000.0f / ((FT_Face)font->ft_face)->units_per_EM;
//        if (gid < font->width_count)
//            subw = font->width_table[gid];
//        else
//            subw = font->width_default;
//
//        /* Sanity check scaling in case of broken metrics. */
//        if (realw > 0 && subw > 0)
//            *trm = fz_pre_scale(*trm, subw / realw, 1);
//    }
//
//    return trm;
//}
//
//fz_path *
//fz_outline_ft_glyph_my(fz_context *ctx, fz_font *font, int gid, fz_matrix trm)
//{
//    struct closure cc;
//    FT_Face face = (FT_Face)font->ft_face;
//    int fterr;
//
//    const int scale = 65536;
//    const float recip = 1.0f / scale;
//    const float strength = 0.02f;
//
//    fz_adjust_ft_glyph_width(ctx, font, gid, &trm);
//
//    if (font->flags.fake_italic)
//        trm = fz_pre_shear(trm, SHEAR, 0);
//
//    fz_ft_lock(ctx);
//
//    fterr = FT_Set_Char_Size(face, scale, scale, 72, 72);
//    if (fterr)
//        fz_warn(ctx, "FT_Set_Char_Size(%s,%d,72): %s", font->name, scale, ft_error_string(fterr));
//
//    //FT_Int32 loadFlags = FT_LOAD_DEFAULT;
//    //loadFlags |= FT_LOAD_NO_BITMAP; // ignore embedded bitmaps so we're sure to get the outline
//    //loadFlags &= ~FT_LOAD_RENDER;   // don't scan convert (we just want the outline)
////    FT_Int32 loadFlags = FT_LOAD_DEFAULT|FT_LOAD_NO_BITMAP|FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH;
////    loadFlags &= ~FT_LOAD_RENDER;
////
////    fterr = FT_Load_Glyph(face, gid, loadFlags);
////    if (fterr) {
////        fz_warn(ctx, "FT_Load_Glyph(%s,%d): %s", font->name, gid, ft_error_string(fterr));
////        fz_ft_unlock(ctx);
////        return NULL;
////    }
//
//
//    fterr = FT_Load_Glyph(face, gid, FT_LOAD_IGNORE_TRANSFORM);
//    if (fterr)
//    {
//        //fz_warn(ctx, "FT_Load_Glyph(%s,%d,FT_LOAD_IGNORE_TRANSFORM): %s", font->name, gid, ft_error_string(fterr));
//        fterr = FT_Load_Glyph(face, gid, FT_LOAD_IGNORE_TRANSFORM | FT_LOAD_NO_HINTING);
//    }
//    if (fterr)
//    {
//        //fz_warn(ctx, "FT_Load_Glyph(%s,%d,FT_LOAD_IGNORE_TRANSFORM | FT_LOAD_NO_HINTING): %s", font->name, gid, ft_error_string(fterr));
//        FT_Int32 loadFlags = FT_LOAD_DEFAULT|FT_LOAD_NO_BITMAP|FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH;
//        loadFlags &= ~FT_LOAD_RENDER;
//        fterr = FT_Load_Glyph(face, gid, loadFlags);
//        if (fterr)
//        {
//            fz_warn(ctx, "FT_Load_Glyph(%s,%d): %s", font->name, gid, ft_error_string(fterr));
//            fz_ft_unlock(ctx);
//            return NULL;
//        }
//    }
//
//    if (font->flags.fake_bold)
//    {
//        FT_Outline_Embolden(&face->glyph->outline, strength * scale);
//        FT_Outline_Translate(&face->glyph->outline, -strength * 0.5f * scale, -strength * 0.5f * scale);
//    }
//
//    cc.path = NULL;
//    fz_try(ctx)
//    {
//        cc.ctx = ctx;
//        cc.path = fz_new_path(ctx);
//        cc.trm = fz_concat(fz_scale(recip, recip), trm);
//        fz_moveto(ctx, cc.path, cc.trm.e, cc.trm.f);
//        FT_Outline_Decompose(&face->glyph->outline, &outline_funcs, &cc);
//        fz_closepath(ctx, cc.path);
//    }
//    fz_always(ctx)
//    {
//        fz_ft_unlock(ctx);
//    }
//    fz_catch(ctx)
//    {
//        fz_warn(ctx, "freetype cannot decompose outline");
//        fz_drop_path(ctx, cc.path);
//        return NULL;
//    }
//
//    return cc.path;
//}
//-----------------------------------------------------------------------------------------------------------------
const FZZPath* FZZTempFontCache::getPath(FzGlyphID value)
{
    
    FZZPath* fontPath = NULL;
    if ( m_CTX == NULL || m_Font == NULL ) {
        return fontPath;
    }
    map<FzGlyphID,FZZPath*>::const_iterator it = m_Paths.find(value);
    if (it != m_Paths.end()) {
        fontPath = it->second;
    } else {
        fz_try(m_CTX) {
            fz_matrix font_matrix = { 1, 0, 0, -1, 0, 0 };
            fz_path * tempfontPath = fz_outline_glyph(m_CTX,m_Font,value,font_matrix);
            //fontPath = fz_outline_ft_glyph_my(m_CTX,m_Font,value,MUPDF_fz_identity);
            if ( tempfontPath != NULL ) {
                fontPath = new FZZPath(m_CTX,tempfontPath);
                if ( fontPath != NULL ) {
                    auto isExitPari = m_Paths.insert(pair<FzGlyphID,FZZPath*>(value,fontPath));
                    if ( !isExitPari.second ) {
                        delete fontPath;
                    }
                }
                fz_drop_path(m_CTX, tempfontPath);
            }
        } fz_catch(m_CTX) {

        }
    }
    return fontPath;
}
//-----------------------------------------------------------------------------------------------------------------
const fz_text* FZZTempFontCache::getText(FzGlyphID value)
{
    fz_text* fontText = NULL;
    if ( m_CTX == NULL || m_Font == NULL ) {
        return fontText;
    }
    map<FzGlyphID,fz_text*>::const_iterator it = m_Texts.find(value);
    if (it != m_Texts.end()) {
        fontText = it->second;
    } else {
        
        fontText = fz_new_text(m_CTX);
        if ( fontText == NULL ) {
            return fontText;
        }
        //fz_try(m_CTX) {
           
            fz_show_glyph(m_CTX, fontText, m_Font,MUPDF_fz_identity,value,0,false, 0, FZ_BIDI_NEUTRAL, FZ_LANG_UNSET);
        //} fz_catch(m_CTX) {

        //}
        auto isExitPari = m_Texts.insert(pair<FzGlyphID,fz_text*>(value,fontText));
        if ( !isExitPari.second ) {
            fz_drop_text(m_CTX, fontText);
        }
        
    }
    return fontText;
}
//-----------------------------------------------------------------------------------------------------------------

