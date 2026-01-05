//
//  Created by zizheng fan on 2024/08/05.
//

#ifndef FZZOFDDEVICE_H
#define FZZOFDDEVICE_H

#include <stdio.h>
#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"

#include "ofd/FZZOFD.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCompositeObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDAbbreviatedData.h"
#include "ofd/draw/FZZOFDDrawContext.h"



//#define TEST_MEM_fzofd_device

class FZZGenFont;

struct fzofd_device
{
    fz_device super;
    FZZOFD* ofdDoc;
    //--------------page----------
    FZZOFDLayer*  layer;
    FZZOFDPageBlock* curr_PageBlock; //CT_Layer or CT_PageBlock
    //--------------annots----------
    int pagetype; //0:contents 1:annots;2:widgets
    enum pdf_annot_type annotType;
    fz_matrix transform;    //not use
    float page_width;
    float page_height;
    //--------------annot----------
    int currPageIndex;
    FZZOFDPageAnnotXML * pageAnnot; //Annotation.xml
    FZZOFDAnnot_Annotation* annotation_Annot;
    FZZOFDAppearance* annotation_Appearance;             //Annotation.xml
    FZZOFDCompositeObject * annotation_CompositeObject;  //Annotation.xml
    FZZOFDVectorG* documentRes_CompositeGraphicUnit;   //DocumentRes.xml
    string *Annot_Event_cmd;
    //---------------------------
    map<string,FZZGenFont*>* g_GenFont;
    map<string,unordered_map<FzUnichar,FzGlyphID>> * g_ucs_gid_map;
    //---------------------------
    
//    vector<FZZOFDAbbreviatedData*> clip_PathDatas;
//    vector<s_OFD_Box> clip_Boxs;
//    vector<string> clip_ctms;
//    vector<bool> clip_isFill;
//    vector<bool> clip_isStroke;
//    vector<float> clip_StrokeLineWidth;
    vector<clipItem*>* clipItemList;
    
    bool isNoStamp;
    FZZOFDCellContent * tile_CellContent;
    
    
    void (*OFD_genAnnot)(fz_context *ctx,fzofd_device * pdev,string strAuthor,string reMark,bool isReadOnly,bool isNoZoom,bool isNoRotate);
    void (*OFD_annotationrender)(fzofd_device * pdev);
};

struct s_FZOFD_PATHTYPE
{
    int type; //0:DrawContext 1: AbbreviatedData
    void * obj;
    s_OFD_Box box;
    bool isLog = false;
};



struct s_FZOFD_SHADE
{
    fzofd_device * dev;
    fz_shade * shade;
    fz_color_params color_params;
};

fz_device * new_fzofd_device(fz_context *ctx,FZZOFD* ofdDoc,FZZOFDLayer*  layer,float page_width,float page_height,fz_matrix transform,bool isNoStamp,map<string,FZZGenFont*>* genFonts,map<string,unordered_map<FzUnichar,FzGlyphID>> * ucs_gid_map,bool m_isGenFont);

#endif //FZZOFDDEVICE_H
