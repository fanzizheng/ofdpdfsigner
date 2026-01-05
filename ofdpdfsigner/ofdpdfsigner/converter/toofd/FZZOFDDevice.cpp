//
//  Created by zizheng fan on 2024/08/05.
//
#include "ofd/FZZOFDConst.h"
#include "FZZOFDDevice.h"
#include "converter/utils/FZZCommonUtil.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTextObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDImageObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPathObject.h"
#include "font/FZZGenFont.h"
#include "converter/utils/FZZImageUtil.h"
#include "basic/FZZMatrix.h"

#define _USE_MATH_DEFINES
#include "math.h"

#define LINEWIDTH_SCALE 0.27
//test
static int clip_count = 0;
//-----------------------------------------------------------------------------------------------------------------
static void OFD_genAnnot(fz_context *ctx,fzofd_device * pdev,string strAuthor,string reMark,bool isReadOnly,bool isNoZoom,bool isNoRotate)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    if ( pdev == NULL ) return;
    
    if ( pdev->isNoStamp && pdev->annotType == PDF_ANNOT_WIDGET ) {
        return;
    }
    
    
    if ( pdev->pageAnnot == NULL ) {
   
        pdev->pageAnnot = pdev->ofdDoc->addAnnotation(pdev->currPageIndex);
        if ( pdev->pageAnnot == NULL ) {
            return;
        }
    }
    
    if ( pdev->annotation_Annot == NULL && pdev->annotation_Appearance == NULL &&
        pdev->annotation_CompositeObject == NULL && pdev->documentRes_CompositeGraphicUnit == NULL ) {
        pdev->annotation_Annot = pdev->pageAnnot->addAnnot();
        if ( pdev->annotation_Annot != NULL ) {
            pdev->annotation_Annot->setID(pdev->ofdDoc->getNewID());
            //Text of the Help sticky note annotation;Text of the Sticky note annotation; Text of the FZZKey sticky note annotation -> PDF_ANNOT_TEXT -> stamp
            // -> PDF_ANNOT_TEXT -> stamp
            switch (pdev->annotType) {
                
                case PDF_ANNOT_SQUIGGLY:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Highlight);
                    pdev->annotation_Annot->setSubtype("Squiggly");
                    break;
                case PDF_ANNOT_STRIKE_OUT:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Highlight);
                    pdev->annotation_Annot->setSubtype("StrikeOut");
                    break;
                case PDF_ANNOT_UNDERLINE:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Highlight);
                    pdev->annotation_Annot->setSubtype("Underline");
                    break;
                case PDF_ANNOT_HIGHLIGHT:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Highlight);
                    pdev->annotation_Annot->setSubtype("Highlight");
                    break;
                case PDF_ANNOT_TEXT:
                case PDF_ANNOT_FREE_TEXT:
                case PDF_ANNOT_STAMP:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Stamp);
                    pdev->annotation_Annot->setSubtype("None");
                    break;
                case PDF_ANNOT_WIDGET:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Stamp);
                    pdev->annotation_Annot->setSubtype("PDFWidgetSign");
                    break;
                case PDF_ANNOT_INK:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Path);
                    pdev->annotation_Annot->setSubtype("Ink");
                    break;
                case PDF_ANNOT_SQUARE:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Path);
                    pdev->annotation_Annot->setSubtype("Square");
                    break;
                case PDF_ANNOT_CIRCLE:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Path);
                    pdev->annotation_Annot->setSubtype("Circle");
                    break;
                case PDF_ANNOT_LINE:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Path);
                    pdev->annotation_Annot->setSubtype("Line");
                    break;
                case PDF_ANNOT_FILE_ATTACHMENT:
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Link);
                    pdev->annotation_Annot->setSubtype("attachlink");
                    break;
    //            case PDF_ANNOT_LINK:
    //
    //                break;
                default:
                    DLOG("annto type : %s untreated ",pdf_string_from_annot_type(ctx,pdev->annotType));
                    pdev->annotation_Annot->setType(FZZOFDAnnotType::TYPE::TYPE_Path);
                    pdev->annotation_Annot->setSubtype("None");
                    break;
            }
            
            //DLOG("annto type : %s look ",pdf_string_from_annot_type(ctx,pdev->annotType));
            
            pdev->annotation_Annot->setCreator(strAuthor.c_str());
            FZZOFDRemark * ofdRemark = pdev->annotation_Annot->setRemark();
            if ( ofdRemark != NULL ) {
                ofdRemark->setValue(reMark.c_str());
            }
            time_t now;
            time(&now);
            pdev->annotation_Annot->setLastModDate(FZZConst::format_time_YYYY_MM_DD_hh_mm_ss(now));
            pdev->annotation_Annot->setReadOnly(isReadOnly);
            pdev->annotation_Annot->setNoZoom(isNoZoom);
            pdev->annotation_Annot->setNoRotate(isNoRotate);
            
        
            pdev->annotation_Appearance = pdev->annotation_Annot->setAppearance();
            if ( pdev->annotation_Appearance == NULL ) return;
            pdev->annotation_CompositeObject = (FZZOFDCompositeObject *)pdev->annotation_Appearance->addPageBlock(FZZOFDPageBlockType::TYPE::TYPT_CompositeObject);
            if ( pdev->annotation_CompositeObject == NULL ) return;
            //-----------------------
            
            FZZOFDDocumentResXML * docmentRes = pdev->ofdDoc->getDocumentResXML();
            if ( docmentRes == NULL ) return;
            FZZOFDCompositeGraphicUnits* tempCompositeGraphicUnits = docmentRes->addCompositeGraphicUnits();
            if ( tempCompositeGraphicUnits == NULL ) return;
            pdev->documentRes_CompositeGraphicUnit = tempCompositeGraphicUnits->addVectorG();
            if ( pdev->documentRes_CompositeGraphicUnit == NULL ) return;
            long CGU_ID = pdev->ofdDoc->getNewID();
            pdev->documentRes_CompositeGraphicUnit->setID(CGU_ID);
            
            FZZOFDPageBlock* DocumentRes_PageBlock = pdev->documentRes_CompositeGraphicUnit->setContent();
            if ( DocumentRes_PageBlock == NULL ) return;
            DocumentRes_PageBlock->setID(pdev->ofdDoc->getNewID());
            //------------------------
            pdev->annotation_CompositeObject->setID(pdev->ofdDoc->getNewID());
            pdev->annotation_CompositeObject->setResourceID(CGU_ID);
        }
        
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
static fz_rect OFD_getMaxRect(fz_rect * rect1,fz_rect * rect2)
{
    fz_rect ret;
    ret.x0 = rect1->x0 <= rect2->x0 ? rect1->x0 : rect2->x0;
    ret.y0 = rect1->y0 <= rect2->y0 ? rect1->y0 : rect2->y0;
    ret.x1 = rect1->x1 >= rect2->x1 ? rect1->x1 : rect2->x1;
    ret.y1 = rect1->y1 >= rect2->y1 ? rect1->y1 : rect2->y1;
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------

static void OFD_annotationrender(fzofd_device * pdev)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    if ( pdev == NULL ) return;
    if ( pdev->annotation_Annot != NULL && pdev->annotation_Appearance != NULL &&
        pdev->annotation_CompositeObject != NULL && pdev->documentRes_CompositeGraphicUnit != NULL ) {
        
        fz_rect dest = {0,0,0,0};
        FZZOFDPageBlock* pageBlock = pdev->documentRes_CompositeGraphicUnit->getContent();
        if ( pageBlock == NULL ) return;
        vector<FZZOFDPageBlockType* >* pageBlockTypes = pageBlock->getPageBlockList();
        if ( pageBlockTypes == NULL ) return;
        
        int count = 0;
        vector<FZZOFDPageBlockType*>::iterator iter;
        for (iter = pageBlockTypes->begin(); iter != pageBlockTypes->end(); iter++) {
            FZZOFDPageBlockType* temp = *iter;
            if ( temp != NULL ) {
                
                string tempbox = "";
                if (dynamic_cast<FZZOFDTextObject*>(temp) != NULL) {
                    tempbox = ((FZZOFDTextObject*)temp)->getBoundary();
                }
                else if (dynamic_cast<FZZOFDPathObject*>(temp) != NULL) {
                    tempbox = ((FZZOFDPathObject*)temp)->getBoundary();
                }
                else if (dynamic_cast<FZZOFDImageObject*>(temp) != NULL) {
                    tempbox = ((FZZOFDImageObject*)temp)->getBoundary();
                }
                if ( tempbox.empty() ) continue;
                
                double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
                ST_Box_ToDouble(tempbox, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
                
                if ( count == 0 ) {
                    dest.x0 = BoundaryBox_x;
                    dest.y0 = BoundaryBox_y;
                    dest.x1 = BoundaryBox_x + BoundaryBox_width;
                    dest.y1 = BoundaryBox_y + BoundaryBox_height;
                    count++;
                } else {
                    count++;
                    fz_rect rect2;
                    rect2.x0 = BoundaryBox_x;
                    rect2.y0 = BoundaryBox_y;
                    rect2.x1 = BoundaryBox_x + BoundaryBox_width;
                    rect2.y1 = BoundaryBox_y + BoundaryBox_height;
                    dest = OFD_getMaxRect(&dest,&rect2);
                }
                
                
            }
            
            
            
        }
        
        pdev->documentRes_CompositeGraphicUnit->setWidth(dest.x1-dest.x0);
        pdev->documentRes_CompositeGraphicUnit->setHeight(dest.y1-dest.y0);
        
        string strBox;
        ST_Box_ToString(dest.x0,dest.y0,dest.x1-dest.x0,dest.y1-dest.y0,strBox);
        pdev->annotation_Appearance->setBoundary(strBox);
        
        ST_Box_ToString(0,0,dest.x1-dest.x0,dest.y1-dest.y0,strBox);
        pdev->annotation_CompositeObject->setBoundary(strBox);
        
        
        pdev->annotation_CompositeObject->setCTM("1 0 0 1 0 0");
        
  
        for (iter = pageBlockTypes->begin(); iter != pageBlockTypes->end(); iter++) {
            FZZOFDPageBlockType* temp = *iter;
            
            if ( temp != NULL ) {
                double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
                //Clips* clips = NULL;
                if (dynamic_cast<FZZOFDTextObject*>(temp) != NULL) {
                    BoundaryBox_x = 0; BoundaryBox_y = 0; BoundaryBox_width = 0; BoundaryBox_height = 0;
                    ((FZZOFDTextObject*)temp)->getBoundary(BoundaryBox_x,BoundaryBox_y,BoundaryBox_width,BoundaryBox_height);
                    ((FZZOFDTextObject*)temp)->setBoundary(BoundaryBox_x-dest.x0,BoundaryBox_y-dest.y0,BoundaryBox_width,BoundaryBox_height);
                    //clips = ((TextObject*)temp)->getClips();
                    
                }
                else if (dynamic_cast<FZZOFDPathObject*>(temp) != NULL) {
                    BoundaryBox_x = 0; BoundaryBox_y = 0; BoundaryBox_width = 0; BoundaryBox_height = 0;
                    ((FZZOFDPathObject*)temp)->getBoundary(BoundaryBox_x,BoundaryBox_y,BoundaryBox_width,BoundaryBox_height);
                    ((FZZOFDPathObject*)temp)->setBoundary(BoundaryBox_x-dest.x0,BoundaryBox_y-dest.y0,BoundaryBox_width,BoundaryBox_height);
                    //clips = ((PathObject*)temp)->getClips();
                }
                else if (dynamic_cast<FZZOFDImageObject*>(temp) != NULL) {
                    BoundaryBox_x = 0; BoundaryBox_y = 0; BoundaryBox_width = 0; BoundaryBox_height = 0;
                    ((FZZOFDImageObject*)temp)->getBoundary(BoundaryBox_x,BoundaryBox_y,BoundaryBox_width,BoundaryBox_height);
                    ((FZZOFDImageObject*)temp)->setBoundary(BoundaryBox_x-dest.x0,BoundaryBox_y-dest.y0,BoundaryBox_width,BoundaryBox_height);
                    //clips = ((ImageObject*)temp)->getClips();
                }
                
                //At present, clips do not need to recalculate x and y
//                if ( clips != NULL ) {
//                    vector<CT_Clip*>* ct_Clips = clips->getClips();
//                    if ( ct_Clips != NULL ) {
//                        vector<CT_Clip*>::iterator clip_iter;
//                        for (clip_iter = ct_Clips->begin(); clip_iter != ct_Clips->end(); clip_iter++) {
//                            CT_Clip* temp_clip = *clip_iter;
//                            if ( temp_clip != NULL ) {
//                                vector<Area*>* areas = temp_clip->getAreas();
//                                if ( areas != NULL ) {
//                                    vector<Area*>::iterator Area_iter;
//                                    for (Area_iter = areas->begin(); Area_iter != areas->end(); Area_iter++) {
//                                        Area* temp_Area = *Area_iter;
//                                        if ( temp_Area != NULL ) {
//                                            ClipAble* clipobj = temp_Area->getClipObj();
//                                            ST_Box* clip_box = NULL;
//                                            if (dynamic_cast<CT_Path*>(clipobj) != NULL) {
//
//                                                clip_box = ((CT_Path*)clipobj)->getBoundary();
//                                                clip_box->setTopLeftX(clip_box->getTopLeftX()-dest.x0);
//                                                clip_box->setTopLeftY(clip_box->getTopLeftY()-dest.y0);
//                                                ((CT_Path*)clipobj)->setBoundary(clip_box);
//                                            } else if (dynamic_cast<CT_Text*>(clipobj) != NULL) {
//                                                clip_box = ((CT_Text*)clipobj)->getBoundary();
//                                                clip_box->setTopLeftX(clip_box->getTopLeftX()-dest.x0);
//                                                clip_box->setTopLeftY(clip_box->getTopLeftY()-dest.y0);
//                                                ((CT_Text*)clipobj)->setBoundary(clip_box);
//                                            }
//
//                                            if ( clip_box != NULL ) {
//                                                delete clip_box;
//                                            }
//
//                                        } // if ( temp_Area != NULL )
//                                    }//for
//                                }//if ( areas != NULL )
//                            }//if ( temp_clip != NULL )
//                        }//for
//                    }//if ( ct_Clips != NULL )
//
//                }//if ( clips != NULL )
                
            }
            
            
            
        }
        
        pdev->annotation_Annot = NULL;
        pdev->annotation_Appearance = NULL;
        pdev->annotation_CompositeObject = NULL;
        pdev->documentRes_CompositeGraphicUnit = NULL;
        if ( pdev->Annot_Event_cmd != NULL ) {
            *(pdev->Annot_Event_cmd) = "";
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
static fz_point OFD_point_fan_ctm(fz_point dd,fz_matrix cc)
{
    // 1,0,0,1,0,0 to 1,xx0,xx1,1,0,0 . The algorithm is fz_transform_point_xy() Inverse operation of.When xx0 and xx1 are 0, the calculation result remains unchanged.
    fz_point p;
    p.y = (dd.y*cc.a - cc.f*cc.a  - dd.x*cc.b + cc.e*cc.b) / (cc.d*cc.a - cc.c*cc.b);
    p.x = (dd.x - cc.e - p.y * cc.c)/cc.a;
    
    if ( isnan(p.y) ) p.y = 0;
    if ( isnan(p.x) ) p.x = 0;
    return p;
}
//-----------------------------------------------------------------------------------------------------------------
static fz_point OFD_point_fan_ctm_xy(float x,float y,fz_matrix cc)
{
    // 1,0,0,1,0,0 to 1,xx0,xx1,1,0,0 . The algorithm is fz_transform_point_xy() Inverse operation of.When xx0 and xx1 are 0, the calculation result remains unchanged.
    fz_point p;
    p.y = (y*cc.a - cc.f*cc.a  - x*cc.b + cc.e*cc.b) / (cc.d*cc.a - cc.c*cc.b);
    p.x = (x - cc.e - p.y * cc.c)/cc.a;
    
    if ( isnan(p.y) ) p.y = 0;
    if ( isnan(p.x) ) p.x = 0;
    return p;
}
//-----------------------------------------------------------------------------------------------------------------
static fz_point OFD_point_fan_ctm2(fz_point p,fz_matrix m)
{
    fz_point cc = {0,0};
//    cc.y = (p.x/m.a-m.e/m.a-p.y/m.b+m.f/m.a)/(m.c/m.a+m.d/m.b);
//    cc.x = (p.x-cc.y*m.c+m.e)/m.a;
//    if ( isnan(cc.y) ) cc.y = 0;
//    if ( isnan(cc.x) ) cc.x = 0;
    float det = m.a * m.d - m.b * m.c;
    if (det == 0) {
        return cc;
    }

    float inv_a = m.d / det;
    float inv_b = -m.b / det;
    float inv_c = -m.c / det;
    float inv_d = m.a / det;

    cc.x = inv_a * (p.x - m.e) + inv_c * (p.y - m.f);
    cc.y = inv_b * (p.x - m.e) + inv_d * (p.y - m.f);
    
    return cc;
}
//-----------------------------------------------------------------------------------------------------------------
static fz_point OFD_point_fan_ctm_xy2(float x,float y,fz_matrix m)
{
    fz_point cc = {0,0};
//    cc.y = (p.x/m.a-m.e/m.a-p.y/m.b+m.f/m.a)/(m.c/m.a+m.d/m.b);
//    cc.x = (p.x-cc.y*m.c+m.e)/m.a;
//    if ( isnan(cc.y) ) cc.y = 0;
//    if ( isnan(cc.x) ) cc.x = 0;
    float det = m.a * m.d - m.b * m.c;
    if (det == 0) {
        return cc;
    }

    float inv_a = m.d / det;
    float inv_b = -m.b / det;
    float inv_c = -m.c / det;
    float inv_d = m.a / det;

    cc.x = inv_a * (x - m.e) + inv_c * (y - m.f);
    cc.y = inv_b * (x - m.e) + inv_d * (y - m.f);
    
    return cc;
}
//-----------------------------------------------------------------------------------------------------------------
typedef enum
{
    FZ_MOVETO = 'M',
    FZ_LINETO = 'L',
    FZ_DEGENLINETO = 'D',
    FZ_CURVETO = 'C',
    FZ_CURVETOV = 'V',
    FZ_CURVETOY = 'Y',
    FZ_HORIZTO = 'H',
    FZ_VERTTO = 'I',
    FZ_QUADTO = 'Q',
    FZ_RECTTO = 'R',
    FZ_MOVETOCLOSE = 'm',
    FZ_LINETOCLOSE = 'l',
    FZ_DEGENLINETOCLOSE = 'd',
    FZ_CURVETOCLOSE = 'c',
    FZ_CURVETOVCLOSE = 'v',
    FZ_CURVETOYCLOSE = 'y',
    FZ_HORIZTOCLOSE = 'h',
    FZ_VERTTOCLOSE = 'i',
    FZ_QUADTOCLOSE = 'q',
} fz_path_item_kind;

struct fz_path
{
    int8_t refs;
    uint8_t packed;
    int cmd_len, cmd_cap;
    unsigned char *cmds;
    int coord_len, coord_cap;
    float *coords;
    fz_point current;
    fz_point begin;
};

//fz_transform_path() in mupdf There is something wrong with the function. Let's fix this function
//old fz_transform_path()：
//if (path->cmd_len + extra_cmd < path->cmd_cap)
//{
//    path->cmds = fz_realloc_array(ctx, path->cmds, path->cmd_len + extra_cmd, unsigned char);
//    path->cmd_cap = path->cmd_len + extra_cmd;
//}
//if (path->coord_len + extra_coord < path->coord_cap)
//{
//    path->coords = fz_realloc_array(ctx, path->coords, path->coord_len + extra_coord, float);
//    path->coord_cap = path->coord_len + extra_coord;
//}
// The<sign should be changed to the>sign when the if statement is judged incorrectly. This causes other memory contents to be overwritten without expanding memory. Resulting in a crash.
void
OFD_fz_transform_path3(fz_context *ctx, fz_path *path, fz_matrix ctm)
{
    int i, k, n;
    fz_point p, p1, p2, p3, q, s;

    if (path->packed)
        fz_throw(ctx, FZ_ERROR_GENERIC, "Cannot transform a packed path");

    if (ctm.b == 0 && ctm.c == 0)
    {
        /* Simple, in place transform */
        i = 0;
        k = 0;
        while (i < path->cmd_len)
        {
            uint8_t cmd = path->cmds[i];

            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_LINETO:
            case FZ_MOVETOCLOSE:
            case FZ_LINETOCLOSE:
                n = 1;
                break;
            case FZ_DEGENLINETO:
            case FZ_DEGENLINETOCLOSE:
                n = 0;
                break;
            case FZ_CURVETO:
            case FZ_CURVETOCLOSE:
                n = 3;
                break;
            case FZ_RECTTO:
                s.x = path->coords[k];
                s.y = path->coords[k+1];
                n = 2;
                break;
            case FZ_CURVETOV:
            case FZ_CURVETOY:
            case FZ_QUADTO:
            case FZ_CURVETOVCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_QUADTOCLOSE:
                n = 2;
                break;
            case FZ_HORIZTO:
            case FZ_HORIZTOCLOSE:
                q.x = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.x;
                n = 0;
                break;
            case FZ_VERTTO:
            case FZ_VERTTOCLOSE:
                q.y = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.y;
                n = 0;
                break;
            default:
                assert("Unknown path cmd" == NULL);
            }
            while (n > 0)
            {
                q.x = path->coords[k];
                q.y = path->coords[k+1];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.x;
                path->coords[k++] = p.y;
                n--;
            }
            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_MOVETOCLOSE:
                s = q;
                break;
            case FZ_LINETOCLOSE:
            case FZ_DEGENLINETOCLOSE:
            case FZ_CURVETOCLOSE:
            case FZ_CURVETOVCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_QUADTOCLOSE:
            case FZ_HORIZTOCLOSE:
            case FZ_VERTTOCLOSE:
            case FZ_RECTTO:
                q = s;
                break;
            }
            i++;
        }
    }
    else if (ctm.a == 0 && ctm.d == 0)
    {
      
        /* In place transform with command rewriting */
        i = 0;
        k = 0;
        while (i < path->cmd_len)
        {
            uint8_t cmd = path->cmds[i];

            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_LINETO:
            case FZ_MOVETOCLOSE:
            case FZ_LINETOCLOSE:
                n = 1;
                break;
            case FZ_DEGENLINETO:
            case FZ_DEGENLINETOCLOSE:
                n = 0;
                break;
            case FZ_CURVETO:
            case FZ_CURVETOCLOSE:
                n = 3;
                break;
            case FZ_RECTTO:
                s.x = path->coords[k];
                s.y = path->coords[k+1];
                n = 2;
                break;
            case FZ_CURVETOV:
            case FZ_CURVETOY:
            case FZ_QUADTO:
            case FZ_CURVETOVCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_QUADTOCLOSE:
                n = 2;
                break;
            case FZ_HORIZTO:
                q.x = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.y;
                path->cmds[i] = FZ_VERTTO;
                n = 0;
                break;
            case FZ_HORIZTOCLOSE:
                q.x = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.y;
                path->cmds[i] = FZ_VERTTOCLOSE;
                n = 0;
                break;
            case FZ_VERTTO:
                q.y = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.x;
                path->cmds[i] = FZ_HORIZTO;
                n = 0;
                break;
            case FZ_VERTTOCLOSE:
                q.y = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.x;
                path->cmds[i] = FZ_HORIZTOCLOSE;
                n = 0;
                break;
            default:
                assert("Unknown path cmd" == NULL);
            }
            while (n > 0)
            {
                q.x = path->coords[k];
                q.y = path->coords[k+1];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.x;
                path->coords[k++] = p.y;
                n--;
            }
            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_MOVETOCLOSE:
                s = q;
                break;
            case FZ_LINETOCLOSE:
            case FZ_DEGENLINETOCLOSE:
            case FZ_CURVETOCLOSE:
            case FZ_CURVETOVCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_QUADTOCLOSE:
            case FZ_HORIZTOCLOSE:
            case FZ_VERTTOCLOSE:
            case FZ_RECTTO:
                q = s;
                break;
            }
            i++;
        }
    }
    else
    {
        
       

        int extra_coord = 0;
        int extra_cmd = 0;
        int coord_read, coord_write, cmd_read, cmd_write;

        /* General case. Have to allow for rects/horiz/verts
         * becoming non-rects/horiz/verts. */
        for (i = 0; i < path->cmd_len; i++)
        {
            uint8_t cmd = path->cmds[i];
            switch (cmd)
            {
            case FZ_HORIZTO:
            case FZ_VERTTO:
            case FZ_HORIZTOCLOSE:
            case FZ_VERTTOCLOSE:
                extra_coord += 1;
                break;
            case FZ_RECTTO:
                extra_coord += 2;
                extra_cmd += 3;
                break;
            default:
                /* Do nothing */
                break;
            }
        }
        if (path->cmd_len + extra_cmd > path->cmd_cap)
        {
            path->cmds = fz_realloc_array(ctx, path->cmds, path->cmd_len + extra_cmd, unsigned char);
            path->cmd_cap = path->cmd_len + extra_cmd;
        }
        if (path->coord_len + extra_coord > path->coord_cap)
        {
            path->coords = fz_realloc_array(ctx, path->coords, path->coord_len + extra_coord, float);
            path->coord_cap = path->coord_len + extra_coord;
        }
        memmove(path->cmds + extra_cmd, path->cmds, path->cmd_len * sizeof(unsigned char));
        path->cmd_len += extra_cmd;
        memmove(path->coords + extra_coord, path->coords, path->coord_len * sizeof(float));
        path->coord_len += extra_coord;

        for (cmd_write = 0, cmd_read = extra_cmd, coord_write = 0, coord_read = extra_coord; cmd_read < path->cmd_len; i += 2)
        {
            uint8_t cmd = path->cmds[cmd_write++] = path->cmds[cmd_read++];

            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_LINETO:
            case FZ_MOVETOCLOSE:
            case FZ_LINETOCLOSE:
                n = 1;
                break;
            case FZ_DEGENLINETO:
            case FZ_DEGENLINETOCLOSE:
                n = 0;
                break;
            case FZ_CURVETO:
            case FZ_CURVETOCLOSE:
                n = 3;
                break;
            case FZ_CURVETOV:
            case FZ_CURVETOY:
            case FZ_QUADTO:
            case FZ_CURVETOVCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_QUADTOCLOSE:
                n = 2;
                break;
            case FZ_RECTTO:
                p.x = path->coords[coord_read++];
                p.y = path->coords[coord_read++];
                p2.x = path->coords[coord_read++];
                p2.y = path->coords[coord_read++];
                p1.x = p2.x;
                p1.y = p.y;
                p3.x = p.x;
                p3.y = p2.y;
                s = p;
                p = fz_transform_point(p, ctm);
                p1 = fz_transform_point(p1, ctm);
                p2 = fz_transform_point(p2, ctm);
                p3 = fz_transform_point(p3, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                path->coords[coord_write++] = p1.x;
                path->coords[coord_write++] = p1.y;
                path->coords[coord_write++] = p2.x;
                path->coords[coord_write++] = p2.y;
                path->coords[coord_write++] = p3.x;
                path->coords[coord_write++] = p3.y;
                path->cmds[cmd_write-1] = FZ_MOVETO;
                path->cmds[cmd_write++] = FZ_LINETO;
                path->cmds[cmd_write++] = FZ_LINETO;
                path->cmds[cmd_write++] = FZ_LINETOCLOSE;
                n = 0;
                break;
            case FZ_HORIZTO:
                q.x = path->coords[coord_read++];
                p = fz_transform_point(q, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                path->cmds[cmd_write-1] = FZ_LINETO;
                n = 0;
                break;
            case FZ_HORIZTOCLOSE:
                p.x = path->coords[coord_read++];
                p.y = q.y;
                p = fz_transform_point(p, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                path->cmds[cmd_write-1] = FZ_LINETOCLOSE;
                q = s;
                n = 0;
                break;
            case FZ_VERTTO:
                q.y = path->coords[coord_read++];
                p = fz_transform_point(q, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                path->cmds[cmd_write-1] = FZ_LINETO;
                n = 0;
                break;
            case FZ_VERTTOCLOSE:
                p.x = q.x;
                p.y = path->coords[coord_read++];
                p = fz_transform_point(p, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                path->cmds[cmd_write-1] = FZ_LINETOCLOSE;
                q = s;
                n = 0;
                break;
            default:
                assert("Unknown path cmd" == NULL);
            }
            while (n > 0)
            {
                q.x = path->coords[coord_read++];
                q.y = path->coords[coord_read++];
                p = fz_transform_point(q, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                n--;
            }
            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_MOVETOCLOSE:
                s = q;
                break;
            case FZ_LINETOCLOSE:
            case FZ_DEGENLINETOCLOSE:
            case FZ_CURVETOCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_CURVETOVCLOSE:
            case FZ_QUADTOCLOSE:
            case FZ_HORIZTOCLOSE:
            case FZ_VERTTOCLOSE:
            case FZ_RECTTO:
                q = s;
                break;
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
//static void shade_process(fz_context *ctx, void *arg, fz_vertex *av, fz_vertex *bv, fz_vertex *cv)
//{
//    s_FZOFD_SHADE* sShade = (s_FZOFD_SHADE*)arg;
//
//    if ( sShade == NULL || sShade->shade == NULL || sShade->dev == NULL) {
//        return;
//    }
//
//    float *vertices[3];
//    vertices[0] = (float *)av;
//    vertices[1] = (float *)bv;
//    vertices[2] = (float *)cv;
//
//    if ( sShade->shade->type == FZ_LINEAR  ) {
//        DLOG("shade_process type:FZ_LINEAR , av : %f %f,bv : %f %f,cv : %f %f, ",FZZCommonUtil::pixelToMillimeters(av->p.x,72),FZZCommonUtil::pixelToMillimeters(av->p.y,72),FZZCommonUtil::pixelToMillimeters(bv->p.x,72),FZZCommonUtil::pixelToMillimeters(bv->p.y,72),FZZCommonUtil::pixelToMillimeters(cv->p.x,72),FZZCommonUtil::pixelToMillimeters(cv->p.y,72));
//        float rgb[FZ_MAX_COLORS];
//        if ( fz_device_rgb(ctx) == sShade->shade->colorspace ) {
//            rgb[0] = av->c[0];
//            rgb[1] = av->c[1];
//            rgb[2] = av->c[2];
//        } else {
//            fz_convert_color(ctx, sShade->shade->colorspace, av->c, fz_device_rgb(ctx), rgb, NULL, sShade->color_params);
//        }
//
//        DLOG("shade_process type:FZ_LINEAR , av->RGB : %d %d %d",(int)(rgb[0]*255),(int)(rgb[1]*255),(int)(rgb[2]*255));
//
//        if ( fz_device_rgb(ctx) == sShade->shade->colorspace ) {
//            rgb[0] = bv->c[0];
//            rgb[1] = bv->c[1];
//            rgb[2] = bv->c[2];
//        } else {
//            fz_convert_color(ctx, sShade->shade->colorspace, bv->c, fz_device_rgb(ctx), rgb, NULL, sShade->color_params);
//        }
//
//        DLOG("shade_process type:FZ_LINEAR , bv->RGB : %d %d %d",(int)(rgb[0]*255),(int)(rgb[1]*255),(int)(rgb[2]*255));
//
//        if ( fz_device_rgb(ctx) == sShade->shade->colorspace ) {
//            rgb[0] = cv->c[0];
//            rgb[1] = cv->c[1];
//            rgb[2] = cv->c[2];
//        } else {
//            fz_convert_color(ctx, sShade->shade->colorspace, cv->c, fz_device_rgb(ctx), rgb, NULL, sShade->color_params);
//        }
//
//        DLOG("shade_process type:FZ_LINEAR , cv->RGB : %d %d %d",(int)(rgb[0]*255),(int)(rgb[1]*255),(int)(rgb[2]*255));
//    }
//}
////-----------------------------------------------------------------------------------------------------------------
//static void shade_prepare(fz_context *ctx, void *arg, fz_vertex *v, const float *color)
//{
//    s_FZOFD_SHADE* sShade = (s_FZOFD_SHADE*)arg;
//    if ( sShade == NULL || sShade->shade == NULL || sShade->dev == NULL) {
//        return;
//    }
//    if ( sShade->shade->type == FZ_LINEAR  ) {
//        float rgb[FZ_MAX_COLORS];
//        if ( fz_device_rgb(ctx) == sShade->shade->colorspace ) {
//            rgb[0] = v->c[0];
//            rgb[1] = v->c[1];
//            rgb[2] = v->c[2];
//        } else {
//            fz_convert_color(ctx, sShade->shade->colorspace, color, fz_device_rgb(ctx), rgb, NULL, sShade->color_params);
//        }
//
//        DLOG("shade_prepare type:FZ_LINEAR ,v-p: %f %f ,v->RGB : %d %d %d",FZZCommonUtil::pixelToMillimeters(v->p.x,72),FZZCommonUtil::pixelToMillimeters(v->p.y,72),(int)(rgb[0]*255),(int)(rgb[1]*255),(int)(rgb[2]*255));
//    } else {
//
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
//static void OFD_copy_dev_path_moveto(fz_context *ctx, void *arg, float x, float y)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_moveto(ctx, temp, x, y);
//    }
//
//}
////-----------------------------------------------------------------------------------------------------------------
//static void OFD_copy_dev_path_lineto(fz_context *ctx, void *arg, float x, float y)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_lineto(ctx, temp, x, y);
//    }
//}
////-----------------------------------------------------------------------------------------------------------------
//static void OFD_copy_dev_path_curveto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2, float x3, float y3)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_curveto(ctx, temp, x1, y1, x2, y2,x3,y3);
//    }
//}
////-----------------------------------------------------------------------------------------------------------------
//static void OFD_copy_dev_path_close(fz_context *ctx, void *arg)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_closepath(ctx, temp);
//    }
//}
////-----------------------------------------------------------------------------------------------------------------
//static void OFD_copy_dev_path_quadto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_quadto(ctx, temp, x1, y1, x2, y2);
//    }
//}
////-----------------------------------------------------------------------------------------------------------------
//static void OFD_copy_dev_path_curvetov(fz_context *ctx, void *arg, float x2, float y2, float x3, float y3)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_curvetov(ctx, temp, x2, y2, x3, y3);
//    }
//}
////-----------------------------------------------------------------------------------------------------------------
//static void OFD_copy_dev_path_curvetoy(fz_context *ctx, void *arg, float x1, float y1, float x3, float y3)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_curvetoy(ctx, temp, x1, y1, x3, y3);
//    }
//}
////-----------------------------------------------------------------------------------------------------------------
//static void OFD_copy_dev_path_rectto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_rectto(ctx, temp, x1, y1, x2, y2);
//    }
//}
////-----------------------------------------------------------------------------------------------------------------
//static const fz_path_walker copy_dev_path_proc =
//{
//    OFD_copy_dev_path_moveto,
//    OFD_copy_dev_path_lineto,
//    OFD_copy_dev_path_curveto,
//    OFD_copy_dev_path_close,
//    OFD_copy_dev_path_quadto,
//    NULL,//OFD_copy_dev_path_curvetov,
//    NULL,//OFD_copy_dev_path_curvetoy,
//    OFD_copy_dev_path_rectto
//};

//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_path_moveto(fz_context *ctx, void *arg, float x, float y)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    //
    s_FZOFD_PATHTYPE * temp = (s_FZOFD_PATHTYPE*)arg;
    if ( temp != NULL ) {
        if ( temp->isLog ) {
            DLOG("OFD_ofd_dev_path_moveto is call");
        }
        if ( temp->type == 0 ) {
            FZZOFDDrawContext * drawContext = (FZZOFDDrawContext *)temp->obj;
            if ( drawContext != NULL ) {
                drawContext->moveTo(FZZCommonUtil::pixelToMillimeters(x,72)-drawContext->getBoundary_X(), FZZCommonUtil::pixelToMillimeters(y,72)-drawContext->getBoundary_Y());
                
            }
        } else if (temp->type == 1) {
            FZZOFDAbbreviatedData * adata = (FZZOFDAbbreviatedData *)temp->obj;
            if ( adata != NULL && !temp->box.strBox.empty() ) {
                adata->moveTo(FZZCommonUtil::pixelToMillimeters(x,72)-temp->box.box_x, FZZCommonUtil::pixelToMillimeters(y,72)-temp->box.box_y);
                
            }
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_path_lineto(fz_context *ctx, void *arg, float x, float y)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    //
    s_FZOFD_PATHTYPE * temp = (s_FZOFD_PATHTYPE*)arg;
    if ( temp != NULL ) {
        if ( temp->isLog ) {
            DLOG("OFD_ofd_dev_path_lineto is call");
        }
        if ( temp->type == 0 ) {
            FZZOFDDrawContext * drawContext = (FZZOFDDrawContext *)temp->obj;
            if ( drawContext != NULL ) {
                //drawContext->lineTo(FZZCommonUtil::pixelToMillimeters(x,72), FZZCommonUtil::pixelToMillimeters(y,72));
                drawContext->lineTo(FZZCommonUtil::pixelToMillimeters(x,72)-drawContext->getBoundary_X(), FZZCommonUtil::pixelToMillimeters(y,72)-drawContext->getBoundary_Y());
            }
        } else if (temp->type == 1) {
            FZZOFDAbbreviatedData * adata = (FZZOFDAbbreviatedData *)temp->obj;
            if ( adata != NULL && !temp->box.strBox.empty() ) {
                adata->lineTo(FZZCommonUtil::pixelToMillimeters(x,72)-temp->box.box_x, FZZCommonUtil::pixelToMillimeters(y,72)-temp->box.box_y);
                
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_path_curveto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2, float x3, float y3)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    //
    s_FZOFD_PATHTYPE * temp = (s_FZOFD_PATHTYPE*)arg;
    if ( temp != NULL ) {
        if ( temp->isLog ) {
            DLOG("OFD_ofd_dev_path_curveto is call");
        }
        if ( temp->type == 0 ) {
            FZZOFDDrawContext * drawContext = (FZZOFDDrawContext *)temp->obj;
            if ( drawContext != NULL ) {
                drawContext->bezierCurveTo(FZZCommonUtil::pixelToMillimeters(x1,72)-drawContext->getBoundary_X(), FZZCommonUtil::pixelToMillimeters(y1,72)-drawContext->getBoundary_Y(), FZZCommonUtil::pixelToMillimeters(x2,72)-drawContext->getBoundary_X(), FZZCommonUtil::pixelToMillimeters(y2,72)-drawContext->getBoundary_Y(), FZZCommonUtil::pixelToMillimeters(x3,72)-drawContext->getBoundary_X(), FZZCommonUtil::pixelToMillimeters(y3,72)-drawContext->getBoundary_Y());
            }
        } else if (temp->type == 1) {
            FZZOFDAbbreviatedData * adata = (FZZOFDAbbreviatedData *)temp->obj;
            if ( adata != NULL && !temp->box.strBox.empty() ) {
                adata->cubicBezier(FZZCommonUtil::pixelToMillimeters(x1,72)-temp->box.box_x, FZZCommonUtil::pixelToMillimeters(y1,72)-temp->box.box_y, FZZCommonUtil::pixelToMillimeters(x2,72)-temp->box.box_x, FZZCommonUtil::pixelToMillimeters(y2,72)-temp->box.box_y, FZZCommonUtil::pixelToMillimeters(x3,72)-temp->box.box_x, FZZCommonUtil::pixelToMillimeters(y3,72)-temp->box.box_y);
                
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_path_close(fz_context *ctx, void *arg)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    //
    s_FZOFD_PATHTYPE * temp = (s_FZOFD_PATHTYPE*)arg;
    if ( temp != NULL ) {
        if ( temp->isLog ) {
            DLOG("OFD_ofd_dev_path_close is call");
        }
        if ( temp->type == 0 ) {
            FZZOFDDrawContext * drawContext = (FZZOFDDrawContext *)temp->obj;
            if ( drawContext != NULL ) {
                drawContext->closePath();
            }
        } else if (temp->type == 1) {
            FZZOFDAbbreviatedData * adata = (FZZOFDAbbreviatedData *)temp->obj;
            if ( adata != NULL ) {
                adata->close();
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_path_quadto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    //
    s_FZOFD_PATHTYPE * temp = (s_FZOFD_PATHTYPE*)arg;
    if ( temp != NULL ) {
        if ( temp->isLog ) {
            DLOG("OFD_ofd_dev_path_quadto is call");
        }
        if ( temp->type == 0 ) {
            FZZOFDDrawContext * drawContext = (FZZOFDDrawContext *)temp->obj;
            if ( drawContext != NULL ) {
                drawContext->quadraticCurveTo(FZZCommonUtil::pixelToMillimeters(x1,72)-drawContext->getBoundary_X(), FZZCommonUtil::pixelToMillimeters(y1,72)-drawContext->getBoundary_Y(), FZZCommonUtil::pixelToMillimeters(x2,72)-drawContext->getBoundary_X(), FZZCommonUtil::pixelToMillimeters(y2,72)-drawContext->getBoundary_Y());
            }
        } else if (temp->type == 1) {
            FZZOFDAbbreviatedData * adata = (FZZOFDAbbreviatedData *)temp->obj;
            if ( adata != NULL ) {
                adata->quadraticBezier(FZZCommonUtil::pixelToMillimeters(x1,72)-temp->box.box_x, FZZCommonUtil::pixelToMillimeters(y1,72)-temp->box.box_y, FZZCommonUtil::pixelToMillimeters(x2,72)-temp->box.box_x, FZZCommonUtil::pixelToMillimeters(y2,72)-temp->box.box_y);
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_path_curvetov(fz_context *ctx, void *arg, float x2, float y2, float x3, float y3)
{
    //For details, refer to fz in path.c file, fz_curvetov() and fz_quadto(). But ofd does not support this
    DLOG("OFD_ofd_dev_path_curvetov is call");
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_path_curvetoy(fz_context *ctx, void *arg, float x1, float y1, float x3, float y3)
{
    DLOG("OFD_ofd_dev_path_curvetoy is call");
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_path_rectto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif

    s_FZOFD_PATHTYPE * temp = (s_FZOFD_PATHTYPE*)arg;
    if ( temp != NULL ) {
        if ( temp->isLog ) {
            DLOG("OFD_ofd_dev_path_rectto is call");
        }
        if ( temp->type == 0 ) {
            FZZOFDDrawContext * drawContext = (FZZOFDDrawContext *)temp->obj;
            if ( drawContext != NULL ) {
                drawContext->rect(FZZCommonUtil::pixelToMillimeters(x1,72)-drawContext->getBoundary_X(), FZZCommonUtil::pixelToMillimeters(y1,72)-drawContext->getBoundary_Y(), FZZCommonUtil::pixelToMillimeters(x2-x1,72), FZZCommonUtil::pixelToMillimeters(y2-y1,72));
            }
        } else if (temp->type == 1) {
            FZZOFDAbbreviatedData * adata = (FZZOFDAbbreviatedData *)temp->obj;
            if ( adata != NULL  ) {
                
                double width = FZZCommonUtil::pixelToMillimeters(x2-x1,72);
                double height = FZZCommonUtil::pixelToMillimeters(y2-y1,72);
                double x = FZZCommonUtil::pixelToMillimeters(x1,72)-temp->box.box_x;
                double y = FZZCommonUtil::pixelToMillimeters(y1,72)-temp->box.box_y;
                adata->moveTo(x, y);
                adata->lineTo(x + width, y);
                adata->lineTo(x + width, y + height);
                adata->lineTo(x, y + height);
                adata->close();
                
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
static const fz_path_walker ofd_dev_path_proc =
{
    
    OFD_ofd_dev_path_moveto,
    OFD_ofd_dev_path_lineto,
    OFD_ofd_dev_path_curveto,
    OFD_ofd_dev_path_close,
    OFD_ofd_dev_path_quadto,
    NULL,//Internal conversion to curveto(), OFD_ofd_dev_path_curvetov() is therefore not used
    NULL,//Internal conversion to curveto(), OFD_ofd_dev_path_curvetov() is therefore not used
    OFD_ofd_dev_path_rectto
};
//-----------------------------------------------------------------------------------------------------------------
//main func
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_close_device(fz_context *ctx, fz_device *dev)
{
    //last close
    fzofd_device *pdev = (fzofd_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    //DLOG("OFD_ofd_dev_close_device is call");
    //OFD_annotationrender(pdev);
    
    //DLOG("OFD_ofd_dev_close_device is call,pdev->clip_PathDatas : %d %d",pdev->clip_PathDatas.size(),clip_count);
    
//    vector<FZZOFDAbbreviatedData*>::const_iterator iter;
//    for (iter = pdev->clip_PathDatas.begin(); iter != pdev->clip_PathDatas.end(); iter++) {
//        FZZOFDAbbreviatedData* temp = *iter;
//        if ( temp != NULL ) {
//            delete temp;
//            temp = NULL;
//        }
//    }
//    pdev->clip_PathDatas.clear();
//
//
//    pdev->clip_Boxs.clear();
//    pdev->clip_ctms.clear();
//
//    pdev->clip_isFill.clear();
//    pdev->clip_isStroke.clear();
//    pdev->clip_StrokeLineWidth.clear();
    if ( pdev->clipItemList != NULL ) {
        vector<clipItem*>::const_iterator itr;
        for( itr = pdev->clipItemList->begin(); itr != pdev->clipItemList->end(); itr++ ) {
            clipItem * item = *itr;
            if ( item != NULL ) {
                if ( item->clip_Box != NULL ) {
                    delete item->clip_Box;
                }
                if ( item->clip_PathData != NULL ) {
                    delete item->clip_PathData;
                }
                if ( item->clip_ctms != NULL ) {
                    delete item->clip_ctms;
                }
                delete item;
            }
        }
        pdev->clipItemList->clear();
        delete pdev->clipItemList;
        pdev->clipItemList = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_drop_device(fz_context *ctx, fz_device *dev)
{
    //free
    fzofd_device *pdev = (fzofd_device*)dev;
    if ( pdev == NULL ) {
        return;
    }
    if ( pdev->Annot_Event_cmd != NULL ) {
        delete pdev->Annot_Event_cmd;
        pdev->Annot_Event_cmd = NULL;
    }
    //DLOG("OFD_ofd_dev_drop_device is call");
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_fill_path(fz_context *ctx, fz_device *dev, const fz_path *path, int even_odd, fz_matrix ctm,
    fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    //DLOG("OFD_ofd_dev_fill_path is call : even_odd : %d",even_odd);
    fzofd_device *pdev = (fzofd_device*)dev;
    if ( pdev != NULL && pdev->ofdDoc != NULL && pdev->layer != NULL ) {
        fz_path * pathc = fz_clone_path(ctx,(fz_path *)path);
        if ( pathc == NULL ) {
            return;
        }
        
        fz_rect rect = fz_bound_path(ctx, pathc, NULL, ctm);

        OFD_fz_transform_path3(ctx,pathc,ctm);
        
        FZZOFDDrawContext * drawContext = NULL;
        switch ( pdev->pagetype ) {
            case 0:
                drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                break;
            case 1:
                //DLOG("OFD_ofd_dev_fill_path pagetype 1");
//                if ( pdev->documentRes_CompositeGraphicUnit == NULL ) {
//                    OFD_genAnnot(pdev);
//                }
                if ( pdev->documentRes_CompositeGraphicUnit != NULL ) {
                    drawContext = pdev->ofdDoc->newDrawContext(pdev->documentRes_CompositeGraphicUnit->getContent());
                }
                break;
            case 2:
                DLOG("OFD_ofd_dev_fill_path pagetype 2");
                break;
            default:
                drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                break;
        }
        if ( drawContext != NULL  ) {
            //ST_Box boundary(rect.x0, rect.y0, rect.x1-rect.x0, rect.y1-rect.y0);
            string boundary = "";
            double x = FZZCommonUtil::pixelToMillimeters(rect.x0,72);
            double y = FZZCommonUtil::pixelToMillimeters(rect.y0,72);
            double width = FZZCommonUtil::pixelToMillimeters(rect.x1-rect.x0,72);
            double height = FZZCommonUtil::pixelToMillimeters(rect.y1-rect.y0,72);
            ST_Box_ToString(x,y ,width , height,boundary);
             
            drawContext->setBoundary(boundary);
            drawContext->setCTM("1 0 0 1 0 0");
            drawContext->setGlobalAlpha(alpha);
            
            drawContext->beginPath();
           
            float rgb[FZ_MAX_COLORS];
            if ( fz_device_rgb(ctx) == colorspace ) {
                rgb[0] = color[0];
                rgb[1] = color[1];
                rgb[2] = color[2];
            } else {
                fz_convert_color(ctx, colorspace, color, fz_device_rgb(ctx), rgb, NULL, color_params);
            }
            
            drawContext->setFillColor(rgb[0]*255, rgb[1]*255, rgb[2]*255);
            drawContext->fill();
            
            s_FZOFD_PATHTYPE pathtype;
            pathtype.type = 0;
            pathtype.obj = drawContext;
            pathtype.box.strBox = "";
            pathtype.box.box_x = 0;
            pathtype.box.box_y = 0;
            pathtype.box.box_width = 0;
            pathtype.box.box_height = 0;
            
            fz_walk_path(ctx, pathc, &ofd_dev_path_proc, &pathtype);
            
            vector<s_OFD_Box*> clip_Boxs;
                        
            vector<clipItem*>::const_iterator clipItem_iter;
            for (clipItem_iter = pdev->clipItemList->begin(); clipItem_iter != pdev->clipItemList->end(); clipItem_iter++) {
                clipItem *temp = *clipItem_iter;
                if ( temp->clip_Box != NULL && !(temp->clip_Box->strBox.empty()) ) {
                    s_OFD_Box * ofdBox = new s_OFD_Box();
                    if ( ofdBox != NULL ) {
                        ofdBox->box_x = temp->clip_Box->box_x-x;
                        ofdBox->box_y = temp->clip_Box->box_y-y;
                        ofdBox->box_width = temp->clip_Box->box_width;
                        ofdBox->box_height = temp->clip_Box->box_height;
                        ST_Box_ToString(ofdBox->box_x,ofdBox->box_y ,ofdBox->box_width , ofdBox->box_height,ofdBox->strBox);
                        clip_Boxs.push_back(ofdBox);
                    }
                } else {
                    s_OFD_Box * ofdBox = new s_OFD_Box();
                    if ( ofdBox != NULL ) {
                        ofdBox->box_x = 0;
                        ofdBox->box_y = 0;
                        ofdBox->box_width = 0;
                        ofdBox->box_height = 0;
                        ofdBox->strBox = "";
                        clip_Boxs.push_back(ofdBox);
                    }
                }
            }
            
            if ( pdev->pagetype == 1 && pdev->Annot_Event_cmd != NULL && !pdev->Annot_Event_cmd->empty() ) {
                drawContext->setPathObject_Actiton(*(pdev->Annot_Event_cmd));
            }
            drawContext->close(pdev->clipItemList,&clip_Boxs);
                        
            vector<s_OFD_Box*>::const_iterator box_iter;
            for (box_iter = clip_Boxs.begin(); box_iter != clip_Boxs.end(); box_iter++) {
                s_OFD_Box *temp = *box_iter;
                if ( temp != NULL ) {
                    delete temp;
                    temp = NULL;
                }
            }
            clip_Boxs.clear();
            
            delete drawContext;
        }
        
        fz_drop_path(ctx,pathc);
            
    }
    
}
//-----------------------------------------------------------------------------------------------------------------


static void OFD_ofd_dev_stroke_path(fz_context *ctx, fz_device *dev, const fz_path *path, const fz_stroke_state *stroke, fz_matrix ctm,
    fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    //DLOG("OFD_ofd_dev_stroke_path is call");
    fzofd_device *pdev = (fzofd_device*)dev;
    if ( pdev != NULL && pdev->ofdDoc != NULL && pdev->layer != NULL ) {
   
        fz_path * pathc = fz_clone_path(ctx,(fz_path *)path);
        if ( pathc == NULL ) {
            return;
        }
        fz_rect rect = fz_bound_path(ctx, pathc, stroke, ctm);
        OFD_fz_transform_path3(ctx,pathc,ctm);
        FZZOFDDrawContext * drawContext = NULL;
        switch ( pdev->pagetype ) {
            case 0:
                drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                break;
            case 1:
                //DLOG("OFD_ofd_dev_stroke_path pagetype 1");
//                if ( pdev->documentRes_CompositeGraphicUnit == NULL ) {
//                    OFD_genAnnot(pdev);
//                }
                if ( pdev->documentRes_CompositeGraphicUnit != NULL ) {
                    drawContext = pdev->ofdDoc->newDrawContext(pdev->documentRes_CompositeGraphicUnit->getContent());
                }
                break;
            case 2:
                DLOG("OFD_ofd_dev_stroke_path pagetype 2");
                break;
            default:
                drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                break;
        }
        if ( drawContext != NULL  ) {
        
           
            string boundary = "";
            double x = FZZCommonUtil::pixelToMillimeters(rect.x0,72);
            double y = FZZCommonUtil::pixelToMillimeters(rect.y0,72);
            double width = FZZCommonUtil::pixelToMillimeters(rect.x1-rect.x0,72);
            double height = FZZCommonUtil::pixelToMillimeters(rect.y1-rect.y0,72);
            ST_Box_ToString(x,y ,width , height,boundary);
            
            drawContext->setBoundary(boundary);
            
            
          
            drawContext->setCTM("1 0 0 1 0 0");
            drawContext->setGlobalAlpha(alpha);
            drawContext->beginPath();
            
          
            float rgb[FZ_MAX_COLORS];
            if ( fz_device_rgb(ctx) == colorspace ) {
                rgb[0] = color[0];
                rgb[1] = color[1];
                rgb[2] = color[2];
            } else {
                fz_convert_color(ctx, colorspace, color, fz_device_rgb(ctx), rgb, NULL, color_params);
            }
            drawContext->setStrokeColor(rgb[0]*255, rgb[1]*255, rgb[2]*255);
            drawContext->setLineWidth(FZZCommonUtil::pixelToMillimeters(stroke->linewidth,72)*LINEWIDTH_SCALE);
            drawContext->setMiterLimit(FZZCommonUtil::pixelToMillimeters(stroke->miterlimit,72)*LINEWIDTH_SCALE);
            
            if (stroke->dash_len != 0)
            {
                vector<string> dashPattern;
                for (int i = 0; i < stroke->dash_len; i++) {
                    double dash_temp = stroke->dash_list[i];
                    dashPattern.push_back(FZZConst::fmt(dash_temp == 0 ? 0.0001 : FZZCommonUtil::pixelToMillimeters(dash_temp,72)));
                }
                string strDashPattern = "";
                ST_Array_ToString(dashPattern,strDashPattern);
                drawContext->setDashPattern(strDashPattern);
                if (stroke->dash_phase != 0) {
                    drawContext->setDashOffset(FZZCommonUtil::pixelToMillimeters(stroke->dash_phase,72));
                }
            }
            
            switch( stroke->start_cap ) {
                case FZ_LINECAP_BUTT:
                    drawContext->setCap(FZZOFDLineCapType::TYPE::TYPE_Butt);
                    break;
                case FZ_LINECAP_ROUND:
                    drawContext->setCap(FZZOFDLineCapType::TYPE::TYPE_Round);
                    break;
                case FZ_LINECAP_SQUARE:
                    drawContext->setCap(FZZOFDLineCapType::TYPE::TYPE_Square);
                    break;
                case FZ_LINECAP_TRIANGLE:
                    drawContext->setCap(FZZOFDLineCapType::TYPE::TYPE_Butt);
                    break;
                default:
                    drawContext->setCap(FZZOFDLineCapType::TYPE::TYPE_Butt);
                    break;
            }
            
            switch (stroke->linejoin) {
                case FZ_LINEJOIN_MITER:
                    //DLOG(" stroke->linejoin : FZ_LINEJOIN_MITER");
                    drawContext->setLineJoin(FZZOFDLineJoinType::TYPE::TYPE_Miter);
                    break;
                case FZ_LINEJOIN_BEVEL:
                    //DLOG(" stroke->linejoin : FZ_LINEJOIN_BEVEL");
                    drawContext->setLineJoin(FZZOFDLineJoinType::TYPE::TYPE_Bevel);
                    break;
                case FZ_LINEJOIN_ROUND:
                    //DLOG(" stroke->linejoin : FZ_LINEJOIN_ROUND");
                    drawContext->setLineJoin(FZZOFDLineJoinType::TYPE::TYPE_Round);
                    break;
                case FZ_LINEJOIN_MITER_XPS:
                    //DLOG(" stroke->linejoin : FZ_LINEJOIN_MITER_XPS");
                    drawContext->setLineJoin(FZZOFDLineJoinType::TYPE::TYPE_Miter);
                    break;
                default:
                    //DLOG(" stroke->linejoin : default");
                    drawContext->setLineJoin(FZZOFDLineJoinType::TYPE::TYPE_Miter);
                    break;
            }
            
            drawContext->stroke();
            
            
            s_FZOFD_PATHTYPE pathtype;
            pathtype.type = 0;
            pathtype.obj = drawContext;
            pathtype.box.strBox = "";
            pathtype.box.box_x = 0;
            pathtype.box.box_y = 0;
            pathtype.box.box_width = 0;
            pathtype.box.box_height = 0;
            pathtype.isLog = false;
            
            fz_walk_path(ctx, pathc, &ofd_dev_path_proc, &pathtype);
            
            
        
            
            vector<s_OFD_Box*> clip_Boxs;
            
            vector<clipItem*>::const_iterator clipItem_iter;
            for (clipItem_iter = pdev->clipItemList->begin(); clipItem_iter != pdev->clipItemList->end(); clipItem_iter++) {
                clipItem *temp = *clipItem_iter;
                if ( temp->clip_Box != NULL && !(temp->clip_Box->strBox.empty()) ) {
                    s_OFD_Box * ofdBox = new s_OFD_Box();
                    if ( ofdBox != NULL ) {
                        ofdBox->box_x = temp->clip_Box->box_x-x;
                        ofdBox->box_y = temp->clip_Box->box_y-y;
                        ofdBox->box_width = temp->clip_Box->box_width;
                        ofdBox->box_height = temp->clip_Box->box_height;
                        ST_Box_ToString(ofdBox->box_x,ofdBox->box_y ,ofdBox->box_width , ofdBox->box_height,ofdBox->strBox);
                        clip_Boxs.push_back(ofdBox);
                    }
                } else {
                    s_OFD_Box * ofdBox = new s_OFD_Box();
                    if ( ofdBox != NULL ) {
                        ofdBox->box_x = 0;
                        ofdBox->box_y = 0;
                        ofdBox->box_width = 0;
                        ofdBox->box_height = 0;
                        ofdBox->strBox = "";
                        clip_Boxs.push_back(ofdBox);
                    }
                }
            }
            
            if ( pdev->pagetype == 1 && pdev->Annot_Event_cmd != NULL  && !pdev->Annot_Event_cmd->empty() ) {
                drawContext->setPathObject_Actiton(*(pdev->Annot_Event_cmd));
            }
            
            //drawContext->close(&(pdev->clip_PathDatas),&clip_Boxs,&(pdev->clip_ctms),&(pdev->clip_isFill),&(pdev->clip_isStroke),&(pdev->clip_StrokeLineWidth));
            drawContext->close(pdev->clipItemList,&clip_Boxs);
            
            vector<s_OFD_Box*>::const_iterator box_iter;
            for (box_iter = clip_Boxs.begin(); box_iter != clip_Boxs.end(); box_iter++) {
                s_OFD_Box *temp = *box_iter;
                if ( temp != NULL ) {
                    delete temp;
                    temp = NULL;
                }
            }
            clip_Boxs.clear();
            
            delete drawContext;
        }
        if ( pathc != NULL ) {
            fz_drop_path(ctx,pathc);
        }
    }
     
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_clip_path(fz_context *ctx, fz_device *dev, const fz_path *path, int even_odd, fz_matrix ctm, fz_rect scissor)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    //DLOG("OFD_ofd_dev_clip_path is call : even_odd : %d",even_odd);
   
    
    fzofd_device *pdev = (fzofd_device*)dev;
    if ( pdev != NULL && pdev->ofdDoc != NULL && pdev->layer != NULL && pdev->clipItemList != NULL ) {
      
        fz_path * pathc = fz_clone_path(ctx,(fz_path *)path);
        if ( pathc == NULL ) {
            return;
        }
    
        fz_rect rect = fz_bound_path(ctx, pathc, NULL, ctm);
        
        OFD_fz_transform_path3(ctx,pathc,ctm);
        
        s_OFD_Box * boundary = new s_OFD_Box();
        if ( boundary == NULL ) {
            fz_drop_path(ctx,pathc);
            return;
        }
        boundary->box_x = FZZCommonUtil::pixelToMillimeters(rect.x0,72);
        boundary->box_y = FZZCommonUtil::pixelToMillimeters(rect.y0,72);
        boundary->box_width = FZZCommonUtil::pixelToMillimeters(rect.x1-rect.x0,72);
        boundary->box_height = FZZCommonUtil::pixelToMillimeters(rect.y1-rect.y0,72);
        ST_Box_ToString(boundary->box_x, boundary->box_y, boundary->box_width, boundary->box_height,boundary->strBox);
        
        string *ofdctm = new string("1 0 0 1 0 0");
        if ( ofdctm == NULL ) {
            delete boundary;
            fz_drop_path(ctx,pathc);
            return;
        }
        
        FZZOFDAbbreviatedData* pathdata = new FZZOFDAbbreviatedData(NULL);
        if ( pathdata == NULL) {
            delete boundary;
            delete ofdctm;
            fz_drop_path(ctx,pathc);
            return;
        }
        
        s_FZOFD_PATHTYPE pathtype;
        pathtype.type = 1;
        pathtype.obj = pathdata;
        //pathtype.box = boundary;
        pathtype.box.box_x = boundary->box_x;
        pathtype.box.box_y = boundary->box_y;
        pathtype.box.box_height = boundary->box_height;
        pathtype.box.box_width = boundary->box_width;
        pathtype.box.strBox = boundary->strBox;
        
        fz_walk_path(ctx, pathc, &ofd_dev_path_proc, &pathtype);
        
        clipItem * item = new clipItem();
        item->clip_PathData = pathdata;
        item->clip_Box = boundary;
        item->clip_ctms = ofdctm;
        item->clip_isFill = true;
        item->clip_isStroke = false;
        item->clip_StrokeLineWidth = 0;
        pdev->clipItemList->push_back(item);
        
        
//        pdev->clip_PathDatas.push_back(pathdata);
//        pdev->clip_Boxs.push_back(boundary);
//        pdev->clip_ctms.push_back(ofdctm);
//        pdev->clip_isFill.push_back(true);
//        pdev->clip_isStroke.push_back(false);
//        pdev->clip_StrokeLineWidth.push_back(0);
        fz_drop_path(ctx,pathc);
        
        clip_count++;
        
        
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_clip_stroke_path(fz_context *ctx, fz_device *dev, const fz_path *path, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    DLOG("OFD_ofd_dev_clip_stroke_path is call");
    fzofd_device *pdev = (fzofd_device*)dev;
    if ( pdev != NULL && pdev->ofdDoc != NULL && pdev->layer != NULL ) {
        fz_path * pathc = fz_clone_path(ctx,(fz_path *)path);
        if ( pathc == NULL ) {
            return;
        }
       
        
        fz_rect rect = fz_bound_path(ctx, pathc, stroke, ctm);
        
        OFD_fz_transform_path3(ctx,pathc,ctm);
        
        
        s_OFD_Box *boundary = new s_OFD_Box();
        if (  boundary == NULL ) {
            fz_drop_path(ctx,pathc);
            return;
        }
        boundary->box_x = FZZCommonUtil::pixelToMillimeters(rect.x0,72);
        boundary->box_y = FZZCommonUtil::pixelToMillimeters(rect.y0,72);
        boundary->box_width = FZZCommonUtil::pixelToMillimeters(rect.x1-rect.x0,72);
        boundary->box_height = FZZCommonUtil::pixelToMillimeters(rect.y1-rect.y0,72);
        ST_Box_ToString(boundary->box_x, boundary->box_y, boundary->box_width, boundary->box_height,boundary->strBox);
        
        
        string *ofdctm = new string("1 0 0 1 0 0");
        if ( ofdctm == NULL ) {
            delete boundary;
            fz_drop_path(ctx,pathc);
            return;
        }
        
        FZZOFDAbbreviatedData* pathdata = new FZZOFDAbbreviatedData(NULL);
        if ( pathdata == NULL) {
            delete ofdctm;
            delete boundary;
            fz_drop_path(ctx,pathc);
            return;
        }
        
        s_FZOFD_PATHTYPE pathtype;
        pathtype.type = 1;
        pathtype.obj = pathdata;
        //pathtype.box = boundary;
        pathtype.box.box_x = boundary->box_x;
        pathtype.box.box_y = boundary->box_y;
        pathtype.box.box_height = boundary->box_height;
        pathtype.box.box_width = boundary->box_width;
        pathtype.box.strBox = boundary->strBox;
        
        fz_walk_path(ctx, pathc, &ofd_dev_path_proc, &pathtype);
        
        clipItem * item = new clipItem();
        item->clip_PathData = pathdata;
        item->clip_Box = boundary;
        item->clip_ctms = ofdctm;
        item->clip_isFill = false;
        item->clip_isStroke = true;
        item->clip_StrokeLineWidth = FZZCommonUtil::pixelToMillimeters(stroke->linewidth,72);
        pdev->clipItemList->push_back(item);
        
//        pdev->clip_PathDatas.push_back(pathdata);
//        pdev->clip_Boxs.push_back(boundary);
//        pdev->clip_ctms.push_back(ofdctm);
//        pdev->clip_isFill.push_back(false);
//        pdev->clip_isStroke.push_back(true);
//        //pdev->clip_StrokeLineWidth.push_back(stroke->linewidth);
//        pdev->clip_StrokeLineWidth.push_back(FZZCommonUtil::pixelToMillimeters(stroke->linewidth,72));
        fz_drop_path(ctx,pathc);
            
        clip_count++;
    }
     
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_write_text_genfont(fz_context *ctx, fz_device *dev, const fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    fzofd_device *pdev = (fzofd_device*)dev;
    if ( pdev != NULL ) {
        string key = "";
        long clipMaxLen = FZZConst::g_FZFontConfig.getClipMaxLen();
        FZZGenFont* genFont = NULL;
        for (fz_text_span * span = text->head; span; span = span->next) {

            int gid;
            if ( span->len <= 0 ) continue;
            const char * fontName = fz_font_name(ctx, span->font);
                
            if ( span->font->buffer == NULL ) {
                DLOG("OFD_ofd_dev_write_text_genfont no have font file : %s",fontName);
                continue;
            }
            if ( key != fontName ) {
                key = fontName;
                //DLOG("%s => isGenFont = %s",key.c_str(),span->font->buffer->len > clipMaxLen ? "true":"false");
                //The system font is not used and needs to be regenerated.
                if ( pdev->g_GenFont != NULL ) {
                    //string key = fontName;

                    map<string,FZZGenFont*>::iterator it = pdev->g_GenFont->find(key);

                    if (it != pdev->g_GenFont->end()) {
                        genFont =  it->second;
                        if ( genFont == NULL ) {
                            //DLOG("OFD_ofd_dev_write_text_genfont new: %s",key.c_str());
                            genFont = new FZZGenFont();
                            if ( genFont != NULL ) {
                                (*(pdev->g_GenFont))[key] = genFont;

                                
                                transform(key.begin(), key.end(), key.begin(), ::tolower);
                                if ( key == FZZConst::g_FZFontConfig.getDefaultFontName() || key.find(FZZConst::g_FZFontConfig.getDefaultFontName()) != string::npos ) {
                                    FZZFontCache * fontCache = FZZConst::g_FZSystemFontList.addDefaultFont();
                                    
                                    if (fontCache != NULL ) {
                                        const FZZBytes * tempdefaultfont = fontCache->getFontData();
                                        genFont->setOldFont(tempdefaultfont->getData(), tempdefaultfont->getLen());
                                    } else {
                                        genFont->setIsGenFont(span->font->buffer->len > clipMaxLen);
                                        genFont->setOldFont(span->font->buffer->data,span->font->buffer->len);
                                    }
                                } else {
                                    genFont->setIsGenFont(span->font->buffer->len > clipMaxLen);
                                    genFont->setOldFont(span->font->buffer->data,span->font->buffer->len);
                                }
                            }
                        }
                    } else {
                        genFont = new FZZGenFont();
                        if ( genFont != NULL ) {
                            //DLOG("OFD_ofd_dev_write_text_genfont new: %s",key.c_str());
                            auto isExitPari = pdev->g_GenFont->insert(pair<string,FZZGenFont*>(key ,genFont));
                            if ( !isExitPari.second ) {
                                delete genFont;
                                genFont = isExitPari.first->second;
                                
                            }
                            if ( genFont != NULL ) {
                                //transform(key.begin(), key.end(), key.begin(), ::tolower);
                                transform(key.begin(), key.end(), key.begin(), ::tolower);
                                if ( key == FZZConst::g_FZFontConfig.getDefaultFontName() || key.find(FZZConst::g_FZFontConfig.getDefaultFontName()) != string::npos ) {
                                    FZZFontCache * fontCache = FZZConst::g_FZSystemFontList.addDefaultFont();
                                    if (fontCache != NULL ) {
                                        const FZZBytes * tempdefaultfont = fontCache->getFontData();
                                        genFont->setOldFont(tempdefaultfont->getData(), tempdefaultfont->getLen());
                                    } else {
                                        genFont->setIsGenFont(span->font->buffer->len > clipMaxLen);
                                        genFont->setOldFont(span->font->buffer->data,span->font->buffer->len);
                                    }
                                } else {
                                    genFont->setIsGenFont(span->font->buffer->len > clipMaxLen);
                                    genFont->setOldFont(span->font->buffer->data,span->font->buffer->len);
                                }
                            }//if ( genFont != NULL )
                        }
                    }
                } //if ( pdev->g_GenFont != NULL ) {
            }//if (  key != fontName )
            if ( genFont != NULL ) {
                for (int i = 0; i < span->len; i++) {
                    gid = span->items[i].gid;
                    if (gid < 0)
                        continue;
                    //if ( genFont != NULL ) {
                        genFont->addData(span->items[i].ucs);
                    //}
                }
            }
             
        }//for
            
    }
}
//-----------------------------------------------------------------------------------------------------------------
//裁剪情况不能单独处理每个字，因此要大融合后一起做处理
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_write_text(fz_context *ctx, fz_device *dev, const fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    
    fzofd_device *pdev = (fzofd_device*)dev;
    if ( pdev != NULL && pdev->ofdDoc != NULL && pdev->layer != NULL ) {
        FZZOFDDrawContext * drawContext = NULL;
        
        switch ( pdev->pagetype ) {
            case 0:
                drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                break;
            case 1:
                //DLOG("OFD_ofd_dev_fill_text pagetype 1");
                if ( pdev->tile_CellContent != NULL ) {
                    drawContext = pdev->ofdDoc->newDrawContext(pdev->tile_CellContent);
                } else if ( pdev->documentRes_CompositeGraphicUnit != NULL ) {
                    drawContext = pdev->ofdDoc->newDrawContext(pdev->documentRes_CompositeGraphicUnit->getContent());
                }
                break;
            case 2:
                DLOG("OFD_ofd_dev_fill_text pagetype 2");
                break;
            default:
                drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                break;
        }
        
        
        if ( drawContext != NULL  ) {
            
          
            
            drawContext->setGlobalAlpha(alpha);
            float rgb[FZ_MAX_COLORS] = {0};
            if ( fz_device_rgb(ctx) == colorspace ) {
                rgb[0] = color[0];
                rgb[1] = color[1];
                rgb[2] = color[2];
            } else {
                fz_convert_color(ctx, colorspace, color, fz_device_rgb(ctx), rgb, NULL, color_params);
            }
            fz_rect rect;
            if ( stroke == NULL ) {
                drawContext->setFillColor(rgb[0]*255, rgb[1]*255, rgb[2]*255);
                rect = fz_bound_text(ctx,text,NULL,ctm);
            } else {
                drawContext->setStrokeColor(rgb[0]*255, rgb[1]*255, rgb[2]*255);
                rect = fz_bound_text(ctx,text,stroke,ctm);
            }
             
//            //rect = fz_transform_rect(rect, ctm);
//
            string boundary = "";
            double x = FZZCommonUtil::pixelToMillimeters(rect.x0,72);
            double y = FZZCommonUtil::pixelToMillimeters(rect.y0,72);
            double width = FZZCommonUtil::pixelToMillimeters(rect.x1-rect.x0,72);
            double height = FZZCommonUtil::pixelToMillimeters(rect.y1-rect.y0,72);
            ST_Box_ToString(x,y ,width , height,boundary);

            drawContext->setBoundary(boundary);
            
            for (fz_text_span * span = text->head; span; span = span->next) {
                fz_matrix tm, trm,trmp,spantrm;
                //fzz add begin 2024-05-08
//                fz_matrix trmp_R;
//                int tempLine_Y = 0;
//                double tempLineHeight = 0;
//                double tempLineFontWidth = 0;
//                double tempLineBeginPos = 0;
                //fzz add end 2024-05-08
                int gid;

                if ( span->len <= 0 ) continue;
                
                spantrm = span->trm;
                tm = spantrm;
                
                trm = fz_concat(tm, ctm);
                
                const char * fontName = fz_font_name(ctx, span->font);
          

                //double dfontSize = abs(trm.a==0?tm.a:trm.a);
                
                if ( span->font->buffer == NULL ) {
                    DLOG("OFD_ofd_dev_write_text no have font file : %s",fontName);
                    continue;
                }

                fz_font_flags_t * fontFlags = fz_font_flags(span->font);
                if ( fontFlags == NULL ) {
                    DLOG("OFD_ofd_dev_write_text no have font file : %s",fontName);
                    continue;
                }
                
                //First insert the font resource, and then update the generated font file to the resource.
                //drawContext->setFontParam(fontName, FZZCommonUtil::pixelToMillimeters(dfontSize,72), fontFlags->is_bold, fontFlags->is_italic);
                drawContext->setFontParam(fontName, 1, fontFlags->is_bold, fontFlags->is_italic);
                //DLOG("text => begin.....");
                char * tempstr = new char[(span->len+1)*3];
                if ( tempstr == NULL ) continue;
                
                memset(tempstr,0x00,(span->len+1)*3);
                char * ptempstr = tempstr;
                
                
                
                vector<string> DeltaX;
                vector<string> DeltaY;
                vector<string> glyphs;
             
                fz_point xy;
                fz_point char_xy_p;
                
                for (int i = 0; i < span->len; i++) {
                    gid = span->items[i].gid;
                    
                    if ( gid < 0 || span->items[i].ucs == 32 ) {
                        if ( i == 0 ) {
                            glyphs.push_back("0");
                            ptempstr += fz_runetochar(ptempstr, 32);
                            tm.e = span->items[i].x;
                            tm.f = span->items[i].y;
                            trm = fz_concat(tm, ctm);
                            fz_matrix trmChar2 = trm;
                            trmChar2.e = 0;
                            trmChar2.f = 0;
                            char_xy_p = OFD_point_fan_ctm_xy2(trm.e,trm.f,trmChar2);
                        }
                        continue;
                    }
                    
                    
                    if ( pdev->g_ucs_gid_map != NULL ) {
                        string tempfontName = fontName;
                        //transform(tempfontName.begin(), tempfontName.end(), tempfontName.begin(), ::tolower);
                        map<string,unordered_map<FzUnichar,FzGlyphID>>::iterator it =pdev->g_ucs_gid_map->find(tempfontName);
                        if (it != pdev->g_ucs_gid_map->end()) {
                            unordered_map<FzUnichar,FzGlyphID>::iterator subit = it->second.find(span->items[i].ucs);
                            if (subit != it->second.end()) {
                                glyphs.push_back(FZZConst::fmt(subit->second));
                            } else {
                                glyphs.push_back(FZZConst::fmt(gid));
                            }
                        } else {
                            glyphs.push_back(FZZConst::fmt(gid));
                        }
                    
                    } else {
                        glyphs.push_back(FZZConst::fmt(gid));
                    }

                    tm.e = span->items[i].x;
                    tm.f = span->items[i].y;
                    trm = fz_concat(tm, ctm);

                    fz_matrix trmChar = trm;
                    trmChar.e = 0;
                    trmChar.f = 0;
                  
                    
                    
                    ptempstr += fz_runetochar(ptempstr, span->items[i].ucs);
                    //----test---------
//                    string aa = tempstr;
//                    if ( aa .find("学") != string::npos ) {
//
////                        fz_matrix cc = tm;
////                        cc.e = span->items[0].x;
////                        cc.f = span->items[0].y;
////                        cc = fz_concat(cc, ctm);
////
////                        fz_matrix cc1 = tm;
////                        cc1.e = span->items[1].x;
////                        cc1.f = span->items[1].y;
////                        cc1 = fz_concat(cc1, ctm);
////
////                        fz_point char_xy1 = OFD_point_fan_ctm_xy2(cc.e,cc.f,trmChar);
////                        fz_point char_xy2 = OFD_point_fan_ctm_xy2(cc1.e,cc1.f,trmChar);
//                        int xxxxx = 0;
//                        xxxxx++;
//
//                    }
                    //----------------
                    if ( i != 0 ) {
                        fz_point char_xy = OFD_point_fan_ctm_xy2(trm.e,trm.f,trmChar);
                        //DLOG("text 2=> i=%d,%s,x:%f,y:%f,trmp.a:%f,trmp.b:%f,trmp.c:%f,trmp.d:%f,trmp.e:%f,trmp.f:%f",
                         //    i,tempstr,char_xy.x,char_xy.y,trmChar.a,trmChar.b,trmChar.c,trmChar.d,trmChar.e,trmChar.f);
                        DeltaX.push_back(FZZConst::fmt(char_xy.x - char_xy_p.x));
                        //if ( spantrm.b == 0 && spantrm.c == 0 ) {
                            DeltaY.push_back(FZZConst::fmt(-(char_xy.y - char_xy_p.y)));
                        //} else {
                        ////原始 但文字倒的
                        //    DeltaY.push_back(FZZConst::fmt(char_xy.y - char_xy_p.y));
                        //}
                    
                    } else {
                       
                        //if ( spantrm.b == 0 && spantrm.c == 0 ) {
//                            fz_matrix cc = spantrm;
//                            cc.e = 0;
//                            cc.f = 0;
//
//                            xy = OFD_point_fan_ctm_xy2(trm.e - rect.x0,trm.f - rect.y0,cc);
                    
                        //xy = OFD_point_fan_ctm_xy(trm.e - rect.x0,trm.f - rect.y0,trmChar);
                        
                        //} else {
                        //原始 但文字倒的
                        //    xy = OFD_point_fan_ctm_xy2(trm.e - rect.x0,trm.f - rect.y0,trmChar);
                       // }
                    }
                    trmp = trm;
                    char_xy_p = OFD_point_fan_ctm_xy2(trm.e,trm.f,trmChar);
                    //DLOG("text => %s,x:%f,y:%f,trmp.a:%f,trmp.b:%f,trmp.c:%f,trmp.d:%f,trmp.e:%f,trmp.f:%f",
                    //     tempstr,char_xy_p.x,char_xy_p.y,trmChar.a,trmChar.b,trmChar.c,trmChar.d,trmChar.e,trmChar.f);
                }//for (int i = 0; i < span->len; i++)
                
                //DLOG("text => %s",tempstr);
                
                fz_point dd =  fz_transform_point_xy(span->items[0].x,span->items[0].y, ctm);
                dd.x = dd.x - rect.x0;
                dd.y = dd.y - rect.y0;
                
                //原始 但文字倒的
//                fz_matrix trmText = fz_concat(tm, ctm);
//                trmText.e = 0;
//                trmText.f = 0;

                
                //fz_matrix trmText = spantrm;
                fz_matrix trmText = fz_concat(spantrm, ctm);
                if ( trmText.b == 0 && trmText.c == 0 ) {
                    if ( trmText.d < 0 ) {
                        trmText.d = -trmText.d;
                    }
                    trmText.e = 0;
                    trmText.f = 0;
                    //trmText.f -= dfontSize*1.6;
                    
                    
                    xy = OFD_point_fan_ctm_xy2(dd.x,dd.y,trmText);
                    
                } else {
                    //适用于 ctm = {1,0,0,-1,0,595}
                    trmText = spantrm;
                    trmText.e = 0;
                    trmText.f = 0;
                    
                    
                    xy = OFD_point_fan_ctm_xy2(dd.x,dd.y,trmText);
                    
                    
                    fz_point ef1 = fz_transform_point_xy(xy.x,xy.y,trmText);

                    trmText = fz_concat(spantrm, ctm);
                    if ( trmText.a > 0 && trmText.b < 0 && trmText.c < 0 && trmText.d < 0 ) {
                        //负度数旋转 就是左低右高
                        trmText.c = -trmText.c;
                        trmText.d = -trmText.d;
                    } else if ( trmText.a > 0 && trmText.b > 0 && trmText.c > 0 && trmText.d < 0 ) {
                        //负度数旋转 就是左高右低
                        trmText.d = -trmText.d;
                        trmText.c = -trmText.c;
                    } else if ( trmText.a == 0 && trmText.b < 0 && trmText.c < 0 && trmText.d == -0.0f ) {
                        //负度数旋转 就是左低右高
                        trmText.c = -trmText.c;
                        trmText.d = -trmText.d;
                    } else if ( trmText.a == 0 && trmText.b > 0 && trmText.c > 0 && trmText.d == 0 && trmText.b == trmText.c ) {
                        //垂直90度，字体方向 向右侧
                        trmText.c = -trmText.c;
                    } else {
                        //其他未知
                    }
                    trmText.e = 0;
                    trmText.f = 0;
                    
                    fz_point ef2 = fz_transform_point_xy(xy.x,xy.y,trmText);

                    trmText.e = ef1.x - ef2.x;
                    trmText.f = ef1.y - ef2.y;
                    
                }
                        
                
                
                string ofdctm;
                vector<string> cmtarray;

//                DLOG("toofd : text => ctm,%f,%f , %f,%f , %f,%f; %f,%f",FZZCommonUtil::pixelToMillimeters(trmText.a,72),
//                     FZZCommonUtil::pixelToMillimeters(trmText.b,72),
//                     FZZCommonUtil::pixelToMillimeters(trmText.c,72),
//                     FZZCommonUtil::pixelToMillimeters(trmText.d,72),
//                     FZZCommonUtil::pixelToMillimeters(trmText.e,72),
//                     FZZCommonUtil::pixelToMillimeters(trmText.f,72),xy.x,xy.y);
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.a,72)));
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.b,72)));
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.c,72)));
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.d,72)));
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.e,72)));
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.f,72)));

                ST_Array_ToString(cmtarray,ofdctm);
                    
                drawContext->setCTM(ofdctm);
                
                vector<s_OFD_Box*> clip_Boxs;
                            
                vector<clipItem*>::const_iterator clipItem_iter;
                
                for (clipItem_iter = pdev->clipItemList->begin(); clipItem_iter != pdev->clipItemList->end(); clipItem_iter++) {
                    clipItem *temp = *clipItem_iter;
                    if ( temp->clip_Box != NULL && !(temp->clip_Box->strBox.empty()) ) {
                        s_OFD_Box * ofdBox = new s_OFD_Box();
                        if ( ofdBox != NULL ) {
                            ofdBox->box_x = temp->clip_Box->box_x-x;
                            ofdBox->box_y = temp->clip_Box->box_y-y;
                            ofdBox->box_width = temp->clip_Box->box_width;
                            ofdBox->box_height = temp->clip_Box->box_height;
                            ST_Box_ToString(ofdBox->box_x,ofdBox->box_y ,ofdBox->box_width , ofdBox->box_height,ofdBox->strBox);
                            clip_Boxs.push_back(ofdBox);
                        }
                    } else {
                        s_OFD_Box * ofdBox = new s_OFD_Box();
                        if ( ofdBox != NULL ) {
                            ofdBox->box_x = 0;
                            ofdBox->box_y = 0;
                            ofdBox->box_width = 0;
                            ofdBox->box_height = 0;
                            ofdBox->strBox = "";
                            clip_Boxs.push_back(ofdBox);
                        }
                    }
                }
                
                if ( stroke == NULL  ) {

                    drawContext->drawText(tempstr,xy.x,xy.y,true,false,0,0,DeltaX,DeltaY,glyphs,pdev->clipItemList,&clip_Boxs);
                } else {

                    
//                    drawContext->drawText(tempstr,xy.x,xy.y,false,true,FZZCommonUtil::pixelToMillimeters(stroke->linewidth,72),FZZCommonUtil::pixelToMillimeters(stroke->miterlimit,72),DeltaX,DeltaY,glyphs,pdev->clipItemList,&clip_Boxs);
                    drawContext->drawText(tempstr,xy.x,xy.y,false,true,stroke->linewidth,stroke->miterlimit,DeltaX,DeltaY,glyphs,pdev->clipItemList,&clip_Boxs);
                }
                        
                vector<s_OFD_Box*>::const_iterator box_iter;
                for (box_iter = clip_Boxs.begin(); box_iter != clip_Boxs.end(); box_iter++) {
                    s_OFD_Box *temp = *box_iter;
                    if ( temp != NULL ) {
                        delete temp;
                        temp = NULL;
                    }
                }
                clip_Boxs.clear();
                
                delete [] tempstr;
                
                //DLOG("text => end.....");
                
            }
            
            delete drawContext;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_write_text_new100(fz_context *ctx, fz_device *dev, const fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    
    fzofd_device *pdev = (fzofd_device*)dev;
    if ( pdev != NULL && pdev->ofdDoc != NULL && pdev->layer != NULL ) {
        FZZOFDDrawContext * drawContext = NULL;
        
        switch ( pdev->pagetype ) {
            case 0:
                drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                break;
            case 1:
                //DLOG("OFD_ofd_dev_fill_text pagetype 1");
                if ( pdev->documentRes_CompositeGraphicUnit != NULL ) {
                    drawContext = pdev->ofdDoc->newDrawContext(pdev->documentRes_CompositeGraphicUnit->getContent());
                }
                break;
            case 2:
                DLOG("OFD_ofd_dev_fill_text pagetype 2");
                break;
            default:
                drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                break;
        }
        
        
        if ( drawContext != NULL  ) {
            
          
            
            drawContext->setGlobalAlpha(alpha);
            float rgb[FZ_MAX_COLORS];
            if ( fz_device_rgb(ctx) == colorspace ) {
                rgb[0] = color[0];
                rgb[1] = color[1];
                rgb[2] = color[2];
            } else {
                fz_convert_color(ctx, colorspace, color, fz_device_rgb(ctx), rgb, NULL, color_params);
            }
            fz_rect rect;
            if ( stroke == NULL ) {
                drawContext->setFillColor(rgb[0]*255, rgb[1]*255, rgb[2]*255);
                rect = fz_bound_text(ctx,text,NULL,ctm);
            } else {
                drawContext->setStrokeColor(rgb[0]*255, rgb[1]*255, rgb[2]*255);
                rect = fz_bound_text(ctx,text,stroke,ctm);
            }
             
//            //rect = fz_transform_rect(rect, ctm);
//
            string boundary = "";
            double x = FZZCommonUtil::pixelToMillimeters(rect.x0,72);
            double y = FZZCommonUtil::pixelToMillimeters(rect.y0,72);
            double width = FZZCommonUtil::pixelToMillimeters(rect.x1-rect.x0,72);
            double height = FZZCommonUtil::pixelToMillimeters(rect.y1-rect.y0,72);
            ST_Box_ToString(x,y ,width , height,boundary);

            drawContext->setBoundary(boundary);
            
            for (fz_text_span * span = text->head; span; span = span->next) {
                fz_matrix tm, trm,trmp,spantrm;
                //fzz add begin 2024-05-08
//                fz_matrix trmp_R;
//                int tempLine_Y = 0;
//                double tempLineHeight = 0;
//                double tempLineFontWidth = 0;
//                double tempLineBeginPos = 0;
                //fzz add end 2024-05-08
                int gid;

                if ( span->len <= 0 ) continue;
                
                spantrm = span->trm;
                tm = spantrm;
                
                trm = fz_concat(tm, ctm);
                
                const char * fontName = fz_font_name(ctx, span->font);
          

                //double dfontSize = abs(trm.a==0?tm.a:trm.a);
                
                if ( span->font->buffer == NULL ) {
                    DLOG("OFD_ofd_dev_write_text no have font file : %s",fontName);
                    continue;
                }

                fz_font_flags_t * fontFlags = fz_font_flags(span->font);
                if ( fontFlags == NULL ) {
                    DLOG("OFD_ofd_dev_write_text no have font file : %s",fontName);
                    continue;
                }
                
                //First insert the font resource, and then update the generated font file to the resource.
                //drawContext->setFontParam(fontName, FZZCommonUtil::pixelToMillimeters(dfontSize,72), fontFlags->is_bold, fontFlags->is_italic);
                drawContext->setFontParam(fontName, 1, fontFlags->is_bold, fontFlags->is_italic);
                
                char * tempstr = new char[(span->len+1)*3];
                if ( tempstr == NULL ) continue;
                
                memset(tempstr,0x00,(span->len+1)*3);
                char * ptempstr = tempstr;
                
                
                
                vector<string> DeltaX;
                vector<string> DeltaY;
                vector<string> glyphs;
             
                fz_point xy;
                fz_point char_xy_p;
                
                for (int i = 0; i < span->len; i++) {
                    gid = span->items[i].gid;
                    if (gid < 0)
                        continue;
                    
                    if ( pdev->g_ucs_gid_map != NULL ) {
                        string tempfontName = fontName;
                        
                        map<string,unordered_map<FzUnichar,FzGlyphID>>::iterator it =pdev->g_ucs_gid_map->find(tempfontName);
                        if (it != pdev->g_ucs_gid_map->end()) {
                            unordered_map<FzUnichar,FzGlyphID>::iterator subit = it->second.find(span->items[i].ucs);
                            if (subit != it->second.end()) {
                                glyphs.push_back(FZZConst::fmt(subit->second));
                            } else {
                                glyphs.push_back(FZZConst::fmt(gid));
                            }
                        } else {
                            glyphs.push_back(FZZConst::fmt(gid));
                        }
                    
                    } else {
                        glyphs.push_back(FZZConst::fmt(gid));
                    }

                    tm.e = span->items[i].x;
                    tm.f = span->items[i].y;
                    trm = fz_concat(tm, ctm);

                    fz_matrix trmChar = trm;
                    trmChar.e = 0;
                    trmChar.f = 0;
                  
                    ptempstr += fz_runetochar(ptempstr, span->items[i].ucs);
                    //----test---------
                    string aa = tempstr;
                    if ( aa .find("吉") != string::npos ) {
                        int i = 0;
                        i++;
                    }
                    //----------------
                    if ( i != 0 ) {
                        fz_point char_xy = OFD_point_fan_ctm_xy2(trm.e,trm.f,trmChar);
                        
                        DeltaX.push_back(FZZConst::fmt(char_xy.x - char_xy_p.x));
                        //if ( spantrm.b == 0 && spantrm.c == 0 ) {
                            DeltaY.push_back(FZZConst::fmt(-(char_xy.y - char_xy_p.y)));
                        //} else {
                        ////原始 但文字倒的
                        //    DeltaY.push_back(FZZConst::fmt(char_xy.y - char_xy_p.y));
                        //}
                    
                    } else {
                       
                        //if ( spantrm.b == 0 && spantrm.c == 0 ) {
                            fz_matrix cc = spantrm;
                            cc.e = 0;
                            cc.f = 0;
                            xy = OFD_point_fan_ctm_xy2(trm.e - rect.x0,trm.f - rect.y0,cc);
                        //xy = OFD_point_fan_ctm_xy(trm.e - rect.x0,trm.f - rect.y0,trmChar);
                        
                        //} else {
                        //原始 但文字倒的
                        //    xy = OFD_point_fan_ctm_xy2(trm.e - rect.x0,trm.f - rect.y0,trmChar);
                       // }
                    }
                    trmp = trm;
                    char_xy_p = OFD_point_fan_ctm_xy2(trm.e,trm.f,trmChar);
                }//for (int i = 0; i < span->len; i++)
                //原始 但文字倒的
//                fz_matrix trmText = fz_concat(tm, ctm);
//                trmText.e = 0;
//                trmText.f = 0;

                //fz_matrix trmText = spantrm;
                fz_matrix trmText = fz_concat(spantrm, ctm);
                if ( trmText.b == 0 && trmText.c == 0 ) {
                    if ( trmText.d < 0 ) {
                        trmText.d = -trmText.d;
                    }
                    trmText.e = 0;
                    trmText.f = 0;

                } else {
                    //适用于 ctm = {1,0,0,-1,0,595}
                    trmText = spantrm;
                    trmText.e = 0;
                    trmText.f = 0;
                    fz_point ef1 = fz_transform_point_xy(xy.x,xy.y,trmText);

                    trmText = fz_concat(spantrm, ctm);
                    if ( trmText.a > 0 && trmText.b < 0 && trmText.c < 0 && trmText.d < 0 ) {
                        //负度数旋转 就是左低右高
                        trmText.c = -trmText.c;
                        trmText.d = -trmText.d;
                    } else {
                        //其他未知
                    }
                    trmText.e = 0;
                    trmText.f = 0;
                    fz_point ef2 = fz_transform_point_xy(xy.x,xy.y,trmText);

                    trmText.e = ef1.x - ef2.x;
                    trmText.f = ef1.y - ef2.y;
                    
                }
                        
                string ofdctm;
                vector<string> cmtarray;

//                DLOG("toofd : text => ctm,%f,%f , %f,%f , %f,%f; %f,%f",FZZCommonUtil::pixelToMillimeters(trmText.a,72),
//                     FZZCommonUtil::pixelToMillimeters(trmText.b,72),
//                     FZZCommonUtil::pixelToMillimeters(trmText.c,72),
//                     FZZCommonUtil::pixelToMillimeters(trmText.d,72),
//                     FZZCommonUtil::pixelToMillimeters(trmText.e,72),
//                     FZZCommonUtil::pixelToMillimeters(trmText.f,72),xy.x,xy.y);
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.a,72)));
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.b,72)));
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.c,72)));
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.d,72)));
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.e,72)));
                cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(trmText.f,72)));

                ST_Array_ToString(cmtarray,ofdctm);
                    
                drawContext->setCTM(ofdctm);
                
                vector<s_OFD_Box*> clip_Boxs;
                            
                vector<clipItem*>::const_iterator clipItem_iter;
                for (clipItem_iter = pdev->clipItemList->begin(); clipItem_iter != pdev->clipItemList->end(); clipItem_iter++) {
                    clipItem *temp = *clipItem_iter;
                    if ( temp->clip_Box != NULL && !(temp->clip_Box->strBox.empty()) ) {
                        s_OFD_Box * ofdBox = new s_OFD_Box();
                        if ( ofdBox != NULL ) {
                            ofdBox->box_x = temp->clip_Box->box_x-x;
                            ofdBox->box_y = temp->clip_Box->box_y-y;
                            ofdBox->box_width = temp->clip_Box->box_width;
                            ofdBox->box_height = temp->clip_Box->box_height;
                            ST_Box_ToString(ofdBox->box_x,ofdBox->box_y ,ofdBox->box_width , ofdBox->box_height,ofdBox->strBox);
                            clip_Boxs.push_back(ofdBox);
                        }
                    } else {
                        s_OFD_Box * ofdBox = new s_OFD_Box();
                        if ( ofdBox != NULL ) {
                            ofdBox->box_x = 0;
                            ofdBox->box_y = 0;
                            ofdBox->box_width = 0;
                            ofdBox->box_height = 0;
                            ofdBox->strBox = "";
                            clip_Boxs.push_back(ofdBox);
                        }
                    }
                }
                
                if ( stroke == NULL  ) {

                    drawContext->drawText(tempstr,xy.x,xy.y,true,false,0,0,DeltaX,DeltaY,glyphs,pdev->clipItemList,&clip_Boxs);
                } else {

                    
                    drawContext->drawText(tempstr,xy.x,xy.y,false,true,FZZCommonUtil::pixelToMillimeters(stroke->linewidth,72),FZZCommonUtil::pixelToMillimeters(stroke->miterlimit,72),DeltaX,DeltaY,glyphs,pdev->clipItemList,&clip_Boxs);
                }
                        
                vector<s_OFD_Box*>::const_iterator box_iter;
                for (box_iter = clip_Boxs.begin(); box_iter != clip_Boxs.end(); box_iter++) {
                    s_OFD_Box *temp = *box_iter;
                    if ( temp != NULL ) {
                        delete temp;
                        temp = NULL;
                    }
                }
                clip_Boxs.clear();
                
                delete [] tempstr;
                
            }
            
            delete drawContext;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_fill_text(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    //DLOG("OFD_ofd_dev_fill_text is call");
    OFD_ofd_dev_write_text(ctx,  dev, text, NULL, ctm,colorspace, color, alpha,color_params);
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_stroke_text(fz_context *ctx, fz_device *dev, const fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    //DLOG("OFD_ofd_dev_stroke_text is call");
    OFD_ofd_dev_write_text(ctx,  dev, text, stroke, ctm,colorspace, color, alpha,color_params);
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_fill_text_genfont(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    //DLOG("OFD_ofd_dev_fill_text is call");
    OFD_ofd_dev_write_text_genfont(ctx,  dev, text, NULL, ctm,colorspace, color, alpha,color_params);
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_stroke_text_genfont(fz_context *ctx, fz_device *dev, const fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    //DLOG("OFD_ofd_dev_stroke_text is call");
    OFD_ofd_dev_write_text_genfont(ctx,  dev, text, stroke, ctm,colorspace, color, alpha,color_params);
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_clip_text(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm, fz_rect scissor)
{
    //fzofd_device *pdev = (fzofd_device*)dev;
    DLOG("OFD_ofd_dev_clip_text is call");
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_clip_stroke_text(fz_context *ctx, fz_device *dev, const fz_text *text, const fz_stroke_state *stroke, fz_matrix ctm, fz_rect scissor)
{
    //fzofd_device *pdev = (fzofd_device*)dev;
    DLOG("OFD_ofd_dev_clip_stroke_text is call");
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_ignore_text(fz_context *ctx, fz_device *dev, const fz_text *text, fz_matrix ctm)
{
    //No implementation

    fzofd_device *pdev = (fzofd_device*)dev;
    DLOG("OFD_ofd_dev_ignore_text is call , page : %d",pdev->currPageIndex);
//
//
//    if ( pdev != NULL && pdev->ofdDoc != NULL && pdev->layer != NULL ) {
//        DrawContext * drawContext = pdev->ofdDoc->getDrawContext(pdev->curr_PageBlock);
//        if ( drawContext != NULL  ) {
//
//            drawContext->setGlobalAlpha(1);
//            float rgb[FZ_MAX_COLORS];
//
//                rgb[0] = 1;
//                rgb[1] = 0;
//                rgb[2] = 0;
//
//
//            drawContext->setFillColor(rgb[0]*255, rgb[1]*255, rgb[2]*255);
//
//            fz_rect rect = fz_bound_text(ctx,text,NULL,ctm);
//            ST_Box boundary(FZZCommonUtil::pixelToMillimeters(rect.x0,72), FZZCommonUtil::pixelToMillimeters(rect.y0,72), FZZCommonUtil::pixelToMillimeters(rect.x1-rect.x0,72), FZZCommonUtil::pixelToMillimeters(rect.y1-rect.y0,72));
//            drawContext->setBoundary(&boundary);
//
//            for (fz_text_span * span = text->head; span; span = span->next) {
//                fz_matrix tm, trm,trmp;
//                int gid;
//
//                if ( span->len <= 0 ) continue;
//
//                tm = span->trm;
//
//                trm = fz_concat(tm, ctm);
//
//                const char * fontName = fz_font_name(ctx, span->font);
//                if ( !drawContext->isHaveFont(fontName) && SysFont::isAddFontFile(fontName) ) {
//                    FZZBytes fileData(span->font->buffer->data,span->font->buffer->len);
//                    Font * font = Font::getFont(fontName, "", fileData);
//                    FontSetting * fontSetting = new FontSetting(FZZCommonUtil::pixelToMillimeters(trm.a,72),font);
//                    delete font;
//
//                    fz_font_flags_t * fontFlags = fz_font_flags(span->font);
//                    fontSetting->setBold(fontFlags->is_bold);
//                    fontSetting->setItalic(fontFlags->is_italic);
//                    //drawContext free -> fontSetting
//                    drawContext->setFont(fontSetting);
//                        delete fontSetting;
//                } else {
//                    Font * font = Font::getFont(fontName, "");
//                    FontSetting * fontSetting = new FontSetting(FZZCommonUtil::pixelToMillimeters(trm.a,72),font);
//                    delete font;
//                    fz_font_flags_t * fontFlags = fz_font_flags(span->font);
//                    fontSetting->setBold(fontFlags->is_bold);
//                    fontSetting->setItalic(fontFlags->is_italic);
//                    drawContext->setFont(fontSetting);
//                      delete fontSetting;
//                }
//
//                char * tempstr = new char[(span->len+1)*3];
//                if ( tempstr == NULL ) continue;
//
//                memset(tempstr,0x00,(span->len+1)*3);
//                char * ptempstr = tempstr;
//
//                ST_Array DeltaX;
//                ST_Array DeltaY;
//                ST_Array glyphs;
//
//                for (int i = 0; i < span->len; i++) {
//                    gid = span->items[i].gid;
//                    if (gid < 0)
//                        continue;
//                    if ( SysFont::isAddFontFile(fontName) ) {
//                        glyphs.add(gid);
//                    }
//                    tm.e = span->items[i].x;
//                    tm.f = span->items[i].y;
//                    trm = fz_concat(tm, ctm);
//
//
//
//                    ptempstr += fz_runetochar(ptempstr, span->items[i].ucs);
//
//                    if ( i != 0 ) {
//                        DeltaX.add(FZZCommonUtil::pixelToMillimeters(trm.e - trmp.e,72));
//                        DeltaY.add(FZZCommonUtil::pixelToMillimeters(trm.f - trmp.f,72));
//                    }
//                    trmp = trm;
//                }
//
//
//                fz_point dd =  fz_transform_point_xy(span->items[0].x,span->items[0].y, ctm);
//                dd.x = dd.x - rect.x0;
//                dd.y = dd.y - rect.y0;
//
//                fz_matrix cc = {1,trm.b/trm.a,trm.c/trm.d,1,0,0};
//                double y = (dd.y*cc.a - cc.f*cc.a  - dd.x*cc.b + cc.e*cc.b) / (cc.d*cc.a - cc.c*cc.b);
//                double x = (dd.x - cc.e - y * cc.c)/cc.a;
//
//
//                ST_Array ofdctm;
//                vector<string> cmtarray;
//                cmtarray.push_back("1");
//                cmtarray.push_back(FZZConst::fmt(cc.b));
//                cmtarray.push_back(FZZConst::fmt(cc.c));
//                cmtarray.push_back("1");
//                cmtarray.push_back("0");
//                cmtarray.push_back("0");
//                ofdctm.setArray(&cmtarray);
//                drawContext->setCTM(&ofdctm);
//
//
//
//                vector<ST_Box*> clip_Boxs;
//
//                vector<ST_Box*>::const_iterator box_iter;
//                for (box_iter = pdev->clip_Boxs.begin(); box_iter != pdev->clip_Boxs.end(); box_iter++) {
//                    ST_Box* temp = *box_iter;
//                    if ( temp != NULL) {
//                        clip_Boxs.push_back(new ST_Box(temp->getTopLeftX()-boundary.getTopLeftX(),temp->getTopLeftY()-boundary.getTopLeftY(),temp->getWidth(),temp->getHeight()));
//                    } else {
//                        clip_Boxs.push_back(NULL);
//                    }
//                }
//
////                string aa = tempstr;
////                if ( aa == "Film" ) {
////                    int bb;
////                    bb++;
////
////                }
//
//
//                drawContext->drawText("ffffaaaaa",FZZCommonUtil::pixelToMillimeters(x,72),FZZCommonUtil::pixelToMillimeters(y,72),true,false,0,0,&DeltaX,&DeltaY,&glyphs,&(pdev->clip_PathDatas),&clip_Boxs,&(pdev->clip_ctms),&(pdev->clip_isFill),&(pdev->clip_isStroke),&(pdev->clip_StrokeLineWidth));
//
//
//                for (box_iter = clip_Boxs.begin(); box_iter != clip_Boxs.end(); box_iter++) {
//                    ST_Box* temp = *box_iter;
//                    if ( temp != NULL) {
//                        delete temp;
//                        temp = NULL;
//                    }
//                }
//                clip_Boxs.clear();
//
//                delete [] tempstr;
//
//            }
//
//            delete drawContext;
//        }
//    }
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_fill_image(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm, float alpha, fz_color_params color_params)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    //DLOG("OFD_ofd_dev_fill_image is call");
    fzofd_device *pdev = (fzofd_device*)dev;
    if ( pdev != NULL && pdev->ofdDoc != NULL && pdev->layer != NULL ) {
        fz_pixmap * pix = fz_get_unscaled_pixmap_from_image(ctx,image);
        if ( pix == NULL ) {
            return;
        }
        
        fz_buffer *buf = fz_new_buffer(ctx, INCREMENT_BUFLEN_PNG);
        if ( buf != NULL ) {
            fz_output * out = fz_new_output_with_buffer(ctx, buf);
            if ( out != NULL ) {
                fz_write_pixmap_as_png(ctx, out, pix);
                
                FZZOFDDrawContext * drawContext = NULL;
                switch ( pdev->pagetype ) {
                    case 0:
                        drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                        break;
                    case 1:
                        //DLOG("OFD_ofd_dev_fill_image pagetype 1");
//                        if ( pdev->documentRes_CompositeGraphicUnit == NULL ) {
//                            OFD_genAnnot(pdev);
//                        }
                        if ( pdev->tile_CellContent != NULL ) {
                            drawContext = pdev->ofdDoc->newDrawContext(pdev->tile_CellContent);
                        } else if ( pdev->documentRes_CompositeGraphicUnit != NULL ) {
                            drawContext = pdev->ofdDoc->newDrawContext(pdev->documentRes_CompositeGraphicUnit->getContent());
                        }
                        break;
                    case 2:
                        DLOG("OFD_ofd_dev_fill_image pagetype 2");
                        break;
                    default:
                        drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                        break;
                }
                if ( drawContext != NULL  ) {
                    
                    string boundary = "";
                    double x = FZZCommonUtil::pixelToMillimeters(ctm.e,72)+FZZCommonUtil::pixelToMillimeters(ctm.c,72);
                    double y = FZZCommonUtil::pixelToMillimeters(ctm.f,72);
                    double width = FZZCommonUtil::pixelToMillimeters(ctm.a,72)-FZZCommonUtil::pixelToMillimeters(ctm.c,72);
                    double height = FZZCommonUtil::pixelToMillimeters(ctm.d,72)+FZZCommonUtil::pixelToMillimeters(ctm.b,72);
                    ST_Box_ToString(x,y ,width , height,boundary);
                    
                    drawContext->setBoundary(boundary);
                    
                    string ofdctm;
                    vector<string> cmtarray;
                    cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(ctm.a,72)));
                    cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(ctm.b,72)));
                    cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(ctm.c,72)));
                    cmtarray.push_back(FZZConst::fmt(FZZCommonUtil::pixelToMillimeters(ctm.d,72)));
                    cmtarray.push_back(FZZConst::fmt(width-FZZCommonUtil::pixelToMillimeters(ctm.a,72)));
                    cmtarray.push_back("0");
                    
                    
                    ST_Array_ToString(cmtarray,ofdctm);
                    
                    drawContext->setCTM(ofdctm);
                    drawContext->setGlobalAlpha(alpha);
                    
                                
                    vector<s_OFD_Box*> clip_Boxs;
                                
                    vector<clipItem*>::const_iterator clipItem_iter;
                    for (clipItem_iter = pdev->clipItemList->begin(); clipItem_iter != pdev->clipItemList->end(); clipItem_iter++) {
                        clipItem *temp = *clipItem_iter;
                        if ( temp->clip_Box != NULL && !(temp->clip_Box->strBox.empty()) ) {
                            s_OFD_Box * ofdBox = new s_OFD_Box();
                            if ( ofdBox != NULL ) {
                                ofdBox->box_x = temp->clip_Box->box_x-x;
                                ofdBox->box_y = temp->clip_Box->box_y-y;
                                ofdBox->box_width = temp->clip_Box->box_width;
                                ofdBox->box_height = temp->clip_Box->box_height;
                                ST_Box_ToString(ofdBox->box_x,ofdBox->box_y ,ofdBox->box_width , ofdBox->box_height,ofdBox->strBox);
                                clip_Boxs.push_back(ofdBox);
                            }
                        } else {
                            s_OFD_Box * ofdBox = new s_OFD_Box();
                            if ( ofdBox != NULL ) {
                                ofdBox->box_x = 0;
                                ofdBox->box_y = 0;
                                ofdBox->box_width = 0;
                                ofdBox->box_height = 0;
                                ofdBox->strBox = "";
                                clip_Boxs.push_back(ofdBox);
                            }
                        }
                    }
                    
                    
                    FZZBytes imageData(buf->data, buf->len);
                    //FZZConst::writefile("/Volumes/WorkExt/work/cpp/ofdcreator_test/imageconverter/pdftoofd/aa.png", buf->data, buf->len);
                    if ( image->mask != NULL ) {
                        if (image->mask->imagemask)  {
                            DLOG("OFD_ofd_dev_fill_image is call -> image->mask != NULL , type : mask");
                        } else {
                            //DLOG("OFD_ofd_dev_fill_image is call -> image->mask != NULL , type : smask");
                            FZZBytes maskImage;
                            fz_pixmap * pix_mask = fz_get_unscaled_pixmap_from_image(ctx,image->mask);
                            if ( pix_mask == NULL ) {
                                return;
                            }
                            fz_buffer *buf_mask = fz_new_buffer(ctx, INCREMENT_BUFLEN_PNG);
                            if ( buf_mask != NULL ) {
                                fz_output * out_mask = fz_new_output_with_buffer(ctx, buf_mask);
                                if ( out_mask != NULL ) {
                                    fz_write_pixmap_as_png(ctx, out_mask, pix_mask);
                                    maskImage.setData(buf_mask->data, buf_mask->len);
                                }
                                
                                fz_close_output(ctx, out_mask);
                                fz_drop_output(ctx, out_mask);
                            }
                            fz_drop_buffer(ctx, buf_mask);
                            fz_drop_pixmap(ctx, pix_mask);
                            
                            FZZImageUtil imageUtil;
                            imageUtil.renderMask(imageData, maskImage);
                            imageData = imageUtil.PngEncode();
                        }
                    }
                    
                    drawContext->drawImage(imageData.getData(), (int)imageData.getLen(),"PNG", 0, 0, image->w, image->h,pdev->clipItemList,&clip_Boxs);
                    
                    
                    vector<s_OFD_Box*>::const_iterator box_iter;
                    for (box_iter = clip_Boxs.begin(); box_iter != clip_Boxs.end(); box_iter++) {
                        s_OFD_Box *temp = *box_iter;
                        if ( temp != NULL ) {
                            delete temp;
                            temp = NULL;
                        }
                    }
                    clip_Boxs.clear();
                    
                    delete drawContext;
                }
                
                
                fz_close_output(ctx, out);
                fz_drop_output(ctx, out);
            }
            fz_drop_buffer(ctx, buf);
        }
        
        
        
        fz_drop_pixmap(ctx, pix);
    }
     
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_fill_shade(fz_context *ctx, fz_device *dev, fz_shade *shade, fz_matrix ctm, float alpha, fz_color_params color_params)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    fzofd_device *pdev = (fzofd_device*)dev;
    //DLOG("OFD_ofd_dev_fill_shade is call");
    fz_pixmap *pix = NULL;
    fz_image *img = NULL;
    fz_rect scissor = fz_device_current_scissor(ctx, dev);

    if (alpha == 0)
        return;

    if (fz_is_infinite_rect(scissor))
    {
        scissor.x0 = 0;
        scissor.x1 = pdev->page_width;
        scissor.y0 = 0;
        scissor.y1 = pdev->page_height;
    }

    fz_irect bbox = fz_round_rect(fz_intersect_rect(fz_bound_shade(ctx, shade, ctm), scissor));
    if (fz_is_empty_irect(bbox))
        return;
    
    pix = fz_new_pixmap_with_bbox(ctx, fz_device_rgb(ctx), bbox, NULL, 1);
    fz_clear_pixmap(ctx, pix);
    

  

    fz_try(ctx)
    {
        if (shade->use_background)
            fz_fill_pixmap_with_color(ctx, pix, shade->colorspace, shade->background, color_params);
        else
            fz_clear_pixmap(ctx, pix);
        
        fz_paint_shade(ctx, shade, NULL, ctm, pix, color_params, bbox, NULL, NULL);
       
//        DLOG("image x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\"", pix->x, pix->y, pix->w, pix->h);
//        fz_buffer *buf = fz_new_buffer(ctx, 1024);
//        if ( buf != NULL ) {
//            fz_output * out = fz_new_output_with_buffer(ctx, buf);
//            if ( out != NULL ) {
//                fz_write_pixmap_as_png(ctx, out, pix);
//
//                string aa = "/Users/fzz/work/cpp/ofd/tmp/imageconverter/ffbb";
//                static int aaa = 0;
//                aaa++;
//                FZZConst::writefile(aa+FZZConst::fmt(aaa)+".png", buf->data, (int)(buf->len));
//                fz_close_output(ctx, out);
//                fz_drop_output(ctx, out);
//            }
//            fz_drop_buffer(ctx, buf);
//        }
        fz_matrix in_out_ctm ;
        in_out_ctm.a = pix->w;
        in_out_ctm.b = 0;
        in_out_ctm.c = 0;
        in_out_ctm.d = pix->h;
        in_out_ctm.e = pix->x;
        in_out_ctm.f = pix->y;
    
        
        img = fz_new_image_from_pixmap(ctx, pix, NULL);
        OFD_ofd_dev_fill_image(ctx, dev, img, in_out_ctm,  alpha,  color_params);
        
    }
    fz_always(ctx)
    {
        if ( pix != NULL ) {
            fz_drop_pixmap(ctx, pix);
        }
        if ( img != NULL ) {
            fz_drop_image(ctx, img);
        }
    }
    fz_catch(ctx)
    {
        //fz_rethrow(ctx);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_fill_image_mask(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm,
        fz_colorspace *colorspace, const float *color, float alpha, fz_color_params color_params)
{
    //fzofd_device *pdev = (fzofd_device*)dev;
    DLOG("OFD_ofd_dev_fill_image_mask is call");
}
//-----------------------------------------------------------------------------------------------------------------
static void
OFD_ofd_dev_clip_image_mask(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix ctm, fz_rect scissor)
{
    //OFD_ofd_dev_fill_image=>smask Implemented, OFD_ofd_dev_clip_image_mask no Implemente
    
    
//    fzofd_device *pdev = (fzofd_device*)dev;
    DLOG("OFD_ofd_dev_clip_image_mask is call");
//    if ( pdev != NULL && pdev->ofdDoc != NULL && pdev->layer != NULL ) {
//        fz_pixmap * pix = fz_get_unscaled_pixmap_from_image(ctx,image);
//        if ( pix == NULL ) {
//            return;
//        }
//
//        fz_buffer *buf = fz_new_buffer(ctx, 1024);
//        if ( buf != NULL ) {
//            fz_output * out = fz_new_output_with_buffer(ctx, buf);
//            if ( out != NULL ) {
//                fz_write_pixmap_as_png(ctx, out, pix);
//
//                FZZBytes imageData(buf->data, (int)(buf->len));
//                if ( image->mask != NULL ) {
//                    if (image->mask->imagemask)  {
//                        DLOG("OFD_ofd_dev_fill_image is call -> image->mask != NULL , type : mask");
//                    } else {
//                        //DLOG("OFD_ofd_dev_fill_image is call -> image->mask != NULL , type : smask");
//                        FZZBytes maskImage;
//                        fz_pixmap * pix_mask = fz_get_unscaled_pixmap_from_image(ctx,image->mask);
//                        if ( pix_mask == NULL ) {
//                            return;
//                        }
//                        fz_buffer *buf_mask = fz_new_buffer(ctx, 1024);
//                        if ( buf_mask != NULL ) {
//                            fz_output * out_mask = fz_new_output_with_buffer(ctx, buf_mask);
//                            if ( out_mask != NULL ) {
//                                fz_write_pixmap_as_png(ctx, out_mask, pix_mask);
//                                maskImage.setData(buf_mask->data, (int)(buf_mask->len));
//                            }
//
//                            fz_close_output(ctx, out_mask);
//                            fz_drop_output(ctx, out_mask);
//                        }
//                        fz_drop_buffer(ctx, buf_mask);
//                        fz_drop_pixmap(ctx, pix_mask);
//
//                        ImageUtil imageUtil;
//                        imageUtil.renderMask(imageData, maskImage);
//                        imageData = imageUtil.EncodeImage(ImageUtil::TYPE::TYPE_PNG);
//
//                    }
//                }
//
//                static int gg = 0;
//                string imagefile = "/Users/fzz/work/cpp/ofd/tmp/imageconverter/";
//                FZZConst::writefile(imagefile+FZZConst::fmt(gg)+".png", imageData.getData(), imageData.getLen());
//                gg++;
//
//
//                fz_close_output(ctx, out);
//                fz_drop_output(ctx, out);
//            }
//            fz_drop_buffer(ctx, buf);
//        }
//
//
//
//        fz_drop_pixmap(ctx, pix);
//    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
static void
OFD_ofd_dev_pop_clip(fz_context *ctx, fz_device *dev)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    //DLOG("OFD_ofd_dev_pop_clip is call");
    fzofd_device *pdev = (fzofd_device*)dev;
    
    if ( pdev == NULL ) return;
    
//    if ( pdev->clip_PathDatas.size() > 0 ) {
//        AbbreviatedData* temp = *(pdev->clip_PathDatas.begin());
//        if ( temp != NULL ) {
//            delete temp;
//        }
//        pdev->clip_PathDatas.erase(pdev->clip_PathDatas.begin());
//    }
//
//    if ( pdev->clip_Boxs.size() > 0 ) {
//        ST_Box* temp1 = *(pdev->clip_Boxs.begin());
//        if ( temp1 != NULL ) {
//            delete temp1;
//        }
//        pdev->clip_Boxs.erase(pdev->clip_Boxs.begin());
//    }
//    if ( pdev->clip_ctms.size() > 0 ) {
//        ST_Array* temp2 = *(pdev->clip_ctms.begin());
//        if ( temp2 != NULL ) {
//            delete temp2;
//        }
//        pdev->clip_ctms.erase(pdev->clip_ctms.begin());
//    }
//
//    if ( pdev->clip_isFill.size() > 0 ) {
//        pdev->clip_isFill.erase(pdev->clip_isFill.begin());
//    }
//
//    if ( pdev->clip_isStroke.size() > 0 ) {
//        pdev->clip_isStroke.erase(pdev->clip_isStroke.begin());
//    }
//
//    if ( pdev->clip_StrokeLineWidth.size() > 0 ) {
//        pdev->clip_StrokeLineWidth.erase(pdev->clip_StrokeLineWidth.begin());
//    }
    
//    if ( pdev->clip_PathDatas.size() > 0 ) {
//        FZZOFDAbbreviatedData* temp = pdev->clip_PathDatas.back();
//        if ( temp != NULL ) {
//            delete temp;
//        }
//        pdev->clip_PathDatas.pop_back();
//    }
//
//    if ( pdev->clip_Boxs.size() > 0 ) {
//
//        pdev->clip_Boxs.pop_back();
//    }
//    if ( pdev->clip_ctms.size() > 0 ) {
//        pdev->clip_ctms.pop_back();
//    }
//
//    if ( pdev->clip_isFill.size() > 0 ) {
//
//        pdev->clip_isFill.pop_back();
//    }
//
//    if ( pdev->clip_isStroke.size() > 0 ) {
//
//        pdev->clip_isStroke.pop_back();
//    }
//
//    if ( pdev->clip_StrokeLineWidth.size() > 0 ) {
//        pdev->clip_StrokeLineWidth.pop_back();
//    }
    if ( pdev->clipItemList != NULL && pdev->clipItemList->size() > 0 ) {
        
        clipItem * item = pdev->clipItemList->back();
        if ( item != NULL ) {
            if ( item->clip_Box != NULL ) {
                delete item->clip_Box;
            }
            if ( item->clip_PathData != NULL ) {
                delete item->clip_PathData;
            }
            if ( item->clip_ctms != NULL ) {
                delete item->clip_ctms;
            }
            delete item;
        }
        pdev->clipItemList->pop_back();
    }
    
    clip_count--;
    
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_begin_mask(fz_context *ctx, fz_device *dev, fz_rect bbox, int luminosity, fz_colorspace *colorspace, const float *color, fz_color_params color_params)
{
    //Guess it is the occluded part of the document, and it will not be displayed
    //fzofd_device *pdev = (fzofd_device*)dev;
    DLOG("OFD_ofd_dev_begin_mask is call");
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_end_mask(fz_context *ctx, fz_device *dev,fz_function *tr)
{
    //fzofd_device *pdev = (fzofd_device*)dev;
    DLOG("OFD_ofd_dev_end_mask is call");
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_begin_group(fz_context *ctx, fz_device *dev, fz_rect bbox, fz_colorspace *cs, int isolated, int knockout, int blendmode, float alpha)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    fzofd_device *pdev = (fzofd_device*)dev;
    DLOG("OFD_ofd_dev_begin_group is call");
    if ( pdev != NULL && pdev->layer != NULL && pdev->ofdDoc != NULL ) {
        pdev->curr_PageBlock = pdev->ofdDoc->addPageBlock_Page(pdev->layer);
    }
     
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_end_group(fz_context *ctx, fz_device *dev)
{
#ifdef TEST_MEM_fzofd_device
    return;
#endif
    fzofd_device *pdev = (fzofd_device*)dev;
    
    DLOG("OFD_ofd_dev_end_group is call");
    if ( pdev != NULL ) {
        pdev->curr_PageBlock = pdev->layer;
    }
     
}
//-----------------------------------------------------------------------------------------------------------------
static int OFD_ofd_dev_begin_tile(fz_context *ctx, fz_device *dev, fz_rect area, fz_rect view, float xstep, float ystep, fz_matrix ctm, int id)
{
    //Tile: Tiles the contents of an area into an area.
    fzofd_device *pdev = (fzofd_device*)dev;
    DLOG("OFD_ofd_dev_begin_tile is call");
    if ( pdev != NULL && pdev->ofdDoc != NULL && pdev->layer != NULL ) {
        FZZOFDDrawContext * drawContext = NULL;
        
        switch ( pdev->pagetype ) {
            case 0:
                drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                break;
            case 1:
                //DLOG("OFD_ofd_dev_fill_text pagetype 1");
                if ( pdev->documentRes_CompositeGraphicUnit != NULL ) {
                    drawContext = pdev->ofdDoc->newDrawContext(pdev->documentRes_CompositeGraphicUnit->getContent());
                }
                break;
            case 2:
                DLOG("OFD_ofd_dev_fill_text pagetype 2");
                break;
            default:
                drawContext = pdev->ofdDoc->newDrawContext(pdev->curr_PageBlock);
                break;
        }
        
        
        if ( drawContext == NULL  ) {
            return 0;
        }
        
        fz_path * pathc = fz_new_path(ctx);
        if ( pathc == NULL ) {
            delete drawContext;
            return 0;
        }
        string boundary = "";
        
        
        fz_rect fzbounds = fz_transform_rect(area, ctm);

        double x = FZZCommonUtil::pixelToMillimeters(fzbounds.x0,72);
        double y = FZZCommonUtil::pixelToMillimeters(fzbounds.y0,72);
        double width = FZZCommonUtil::pixelToMillimeters(fzbounds.x1-fzbounds.x0,72);
        double height = FZZCommonUtil::pixelToMillimeters(fzbounds.y1-fzbounds.y0,72);
        ST_Box_ToString(x,y ,width , height,boundary);
         
        drawContext->setBoundary(boundary);
        drawContext->beginPath();
        
        drawContext->fill();
        
        pdev->tile_CellContent = drawContext->setPath_Pattern(view.x1-view.x0, view.y1-view.y0, xstep, ystep);
        
        s_FZOFD_PATHTYPE pathtype;
        pathtype.type = 0;
        pathtype.obj = drawContext;
        pathtype.box.strBox = "";
        pathtype.box.box_x = 0;
        pathtype.box.box_y = 0;
        pathtype.box.box_width = 0;
        pathtype.box.box_height = 0;
                    
        fz_rectto(ctx, pathc,fzbounds.x0,  fzbounds.y0,  fzbounds.x1,  fzbounds.y1);
        
        fz_walk_path(ctx, pathc, &ofd_dev_path_proc, &pathtype);
        
        
        
        drawContext->close(NULL,NULL);
        
        delete drawContext;
        
        fz_drop_path(ctx, pathc);
        
    }
    
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
static void OFD_ofd_dev_end_tile(fz_context *ctx, fz_device *dev)
{
    fzofd_device *pdev = (fzofd_device*)dev;
    DLOG("OFD_ofd_dev_end_tile is call");
    
    pdev->tile_CellContent = NULL;
}
//-----------------------------------------------------------------------------------------------------------------
fz_device * new_fzofd_device(fz_context *ctx,FZZOFD* ofdDoc,FZZOFDLayer*  layer,float page_width,float page_height,fz_matrix transform,bool isNoStamp,map<string,FZZGenFont*>* genFonts,map<string,unordered_map<FzUnichar,FzGlyphID>> * ucs_gid_map,bool m_isGenFont)
{
    fzofd_device *dev = fz_new_derived_device(ctx, fzofd_device);
    if ( dev == NULL ) {
        return NULL;
    }
    
    
    
    if ( m_isGenFont ) {
        dev->super.close_device = OFD_ofd_dev_close_device;
        dev->super.drop_device = OFD_ofd_dev_drop_device;

        dev->super.fill_path = NULL;
        dev->super.stroke_path = NULL;
        dev->super.clip_path = NULL;
        dev->super.clip_stroke_path = NULL;
        //fzz test begin
        dev->super.fill_text = OFD_ofd_dev_fill_text_genfont;
        dev->super.stroke_text = OFD_ofd_dev_stroke_text_genfont;
        //dev->super.fill_text = NULL;
        //dev->super.stroke_text = NULL;
        //fzz test end
        dev->super.clip_text = NULL;
        dev->super.clip_stroke_text = NULL;
        dev->super.ignore_text = NULL;

        dev->super.fill_shade = NULL;
        dev->super.fill_image = NULL;
        dev->super.fill_image_mask = NULL;
        dev->super.clip_image_mask = NULL;

        dev->super.pop_clip = NULL;

        dev->super.begin_mask = NULL;
        dev->super.end_mask = NULL;
        dev->super.begin_group = NULL;
        dev->super.end_group = NULL;

        dev->super.begin_tile = NULL;
        dev->super.end_tile = NULL;

        dev->OFD_genAnnot = NULL;
        dev->OFD_annotationrender = NULL;

    } else {
        dev->super.close_device = OFD_ofd_dev_close_device;
        dev->super.drop_device = OFD_ofd_dev_drop_device;

        dev->super.fill_path = OFD_ofd_dev_fill_path;
        dev->super.stroke_path = OFD_ofd_dev_stroke_path;
        dev->super.clip_path = OFD_ofd_dev_clip_path;
        dev->super.clip_stroke_path = OFD_ofd_dev_clip_stroke_path;

        dev->super.fill_text = OFD_ofd_dev_fill_text;
        dev->super.stroke_text = OFD_ofd_dev_stroke_text;
        dev->super.clip_text = OFD_ofd_dev_clip_text;
        dev->super.clip_stroke_text = OFD_ofd_dev_clip_stroke_text;
        dev->super.ignore_text = OFD_ofd_dev_ignore_text;

        dev->super.fill_shade = OFD_ofd_dev_fill_shade;
        dev->super.fill_image = OFD_ofd_dev_fill_image;
        dev->super.fill_image_mask = OFD_ofd_dev_fill_image_mask;
        dev->super.clip_image_mask = OFD_ofd_dev_clip_image_mask;

        dev->super.pop_clip = OFD_ofd_dev_pop_clip;

        dev->super.begin_mask = OFD_ofd_dev_begin_mask;
        dev->super.end_mask = OFD_ofd_dev_end_mask;
        dev->super.begin_group = OFD_ofd_dev_begin_group;
        dev->super.end_group = OFD_ofd_dev_end_group;

        dev->super.begin_tile = OFD_ofd_dev_begin_tile;
        dev->super.end_tile = OFD_ofd_dev_end_tile;

        dev->OFD_genAnnot = OFD_genAnnot;
        dev->OFD_annotationrender = OFD_annotationrender;
        //------test begin----------
        
//        dev->super.close_device = OFD_ofd_dev_close_device;
//        dev->super.drop_device = OFD_ofd_dev_drop_device;
//
//        dev->super.fill_path = NULL;
//        dev->super.stroke_path = NULL;
//        dev->super.clip_path = NULL;
//        dev->super.clip_stroke_path = NULL;
//
//        dev->super.fill_text = NULL;
//        dev->super.stroke_text = NULL;
//        dev->super.clip_text = NULL;
//        dev->super.clip_stroke_text = NULL;
//        dev->super.ignore_text = NULL;
//
//        dev->super.fill_shade = NULL;
//        dev->super.fill_image = NULL;
//        dev->super.fill_image_mask = NULL;
//        dev->super.clip_image_mask = NULL;
//
//        dev->super.pop_clip = NULL;
//
//        dev->super.begin_mask = NULL;
//        dev->super.end_mask = NULL;
//        dev->super.begin_group = NULL;
//        dev->super.end_group = NULL;
//
//        dev->super.begin_tile = NULL;
//        dev->super.end_tile = NULL;
//
//        dev->OFD_genAnnot = NULL;
//        dev->OFD_annotationrender = NULL;
        
        //------test end----------
    }
    
    dev->clipItemList = new vector<clipItem*>();
    
    dev->ofdDoc = ofdDoc;
    dev->layer = layer;
    dev->curr_PageBlock = layer;
    dev->page_width = page_width;
    dev->page_height = page_height;
    dev->transform = transform;
    dev->pagetype = 0;
    dev->currPageIndex = -1;
    dev->pageAnnot = NULL;
    dev->annotation_Annot = NULL;
    dev->annotation_Appearance = NULL;
    dev->annotation_CompositeObject = NULL;
    dev->documentRes_CompositeGraphicUnit = NULL;
    dev->Annot_Event_cmd = new string("");
    
    dev->g_GenFont = genFonts;
    dev->g_ucs_gid_map = ucs_gid_map;
    dev->isNoStamp = isNoStamp;
    dev->tile_CellContent = NULL;
    
    return (fz_device*)dev;
}
//-----------------------------------------------------------------------------------------------------------------
