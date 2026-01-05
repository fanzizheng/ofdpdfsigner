//
//  Created by zizheng fan on 2023/01/10.
//
#include "basic/FZZConst.h"
#include "ofd/sign/stamppos/FZZCuttingRideStampPos.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZCuttingRideStampPos*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZCuttingRideStampPos::FZZCuttingRideStampPos() : FZZStampAppearance(),m_side(FZZRidingStampPos::TYPE::TYPE_Right),m_offset(0.0),m_margin(0.0),m_Width(0.0),m_Height(0.0)
{
    //DLOG("FZZCuttingRideStampPos()");
    FZZConst::addClassCount("FZZCuttingRideStampPos");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZCuttingRideStampPos::FZZCuttingRideStampPos(FZZRidingStampPos::TYPE side,double offset, double width, double height, double margin): FZZCuttingRideStampPos()
{
    m_side = side;
    m_offset = offset;
    m_Width = width;
    m_Height = height;
    m_margin = margin;
}
//-----------------------------------------------------------------------------------------------------------------
FZZCuttingRideStampPos::~FZZCuttingRideStampPos()
{
    //DLOG("~FZZCuttingRideStampPos()");
    FZZConst::delClassCount("FZZCuttingRideStampPos");
    m_cuttingRatios.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZCuttingRideStampPos::getAppearance(FZZOFD* ctx, FZZSignIDProvider* idProvider,FZZOFDSignedInfo * signedInfo)
{
    int numPage = 0;
    //bool isClipNumber = false;
    //int leftClipNumber = 0;
    double itemWith = 0;
    double itemHeight = 0;
    //int i = 0;
    //int index = 0;
    FZZOFDPageXML* page = NULL;

    double pageSize_x = 0;
    double pageSize_y = 0;
    double pageSize_width = 0;
    double pageSize_height = 0;
    double x = 0;
    double y = 0;

    double clip_x = 0;
    double clip_y = 0;
    double clip_width = 0;
    double clip_height = 0;
    long pageid = 0;
    FZZOFDStampAnnot* annot = NULL;
    //ST_Box tempBox(0,0,0,0);
    if ( ctx == NULL || idProvider == NULL || signedInfo == NULL) {
        return;
    }
    
    numPage = ctx->getPageCount();
    if (m_side == FZZRidingStampPos::TYPE::TYPE_Right ) {
        itemWith = m_Width * 0.5;
        for (int i = 0; i < numPage; i++) {
            page = ctx->getPage(i + 1);
            ctx->getPageSize(page,pageSize_x,pageSize_y,pageSize_width,pageSize_height);
            if (numPage - 1 != i) {
                if (m_cuttingRatios.size() > 0) {
                    itemWith = m_Width * m_cuttingRatios[i].left;
                }
                x = pageSize_width - itemWith - m_margin;
                
                clip_x = 0;
                clip_y = 0;
                clip_width = itemWith;
                clip_height = m_Height;
            } else {
                if (m_cuttingRatios.size() > 0) {
                    itemWith = m_Width * m_cuttingRatios[i-1].right;
                }
                x = 0 - (m_Width - itemWith) + m_margin;
                
                clip_x = (m_Width - itemWith);
                clip_y = 0;
                clip_width = itemWith;
                clip_height = m_Height;
            }
        
            if (m_offset == 0) {
                y = pageSize_height / 2 - m_Height / 2;
            } else {
                y = m_offset;
            }
            
            
            
            annot = signedInfo->addStampAnnot();
            if ( annot == NULL ) {
                continue;
            }
            annot->setID(idProvider->incrementAndGet().c_str());
          
            annot->setBoundary(x,y,m_Width,m_Height);
            annot->setClip(clip_x,clip_y,clip_width,clip_height);
            
            pageid = ctx->getPageObjectId(i + 1);
            
            
            annot->setPageRef(pageid);
            
            

            if (0 != i && numPage - 1 != i) {
                if (m_cuttingRatios.size() > 0) {
                    itemWith = m_Width * m_cuttingRatios[i-1].right;
                }
                x = 0 - (m_Width - itemWith) + m_margin;
                
                clip_x = (m_Width - itemWith);
                clip_y = 0;
                clip_width = itemWith;
                clip_height = m_Height;
                annot = signedInfo->addStampAnnot();
                if ( annot == NULL ) {
                    continue;
                }
                annot->setID(idProvider->incrementAndGet().c_str());
                
                annot->setBoundary(x,y,m_Width,m_Height);
                annot->setClip(clip_x,clip_y,clip_width,clip_height);
                annot->setPageRef(pageid);

            }
            
            
        }
    } else if (m_side == FZZRidingStampPos::TYPE::TYPE_Left) {
        itemWith = m_Width * 0.5;
        for (int i = 0; i < numPage; i++) {
            page = ctx->getPage(i + 1);
            ctx->getPageSize(page,pageSize_x,pageSize_y,pageSize_width,pageSize_height);
           

            if (numPage - 1 != i) {
                if (m_cuttingRatios.size() > 0) {
                    itemWith = m_Width * m_cuttingRatios[i].left;
                }
                x = 0 - (m_Width - itemWith) + m_margin;
                
                clip_x = (m_Width - itemWith);
                clip_y = 0;
                clip_width = itemWith;
                clip_height = m_Height;
            } else {
                if (m_cuttingRatios.size() > 0) {
                    itemWith = m_Width * m_cuttingRatios[i-1].right;
                }
                x = pageSize_width - itemWith - m_margin;
                
                clip_x = 0;
                clip_y = 0;
                clip_width = itemWith;
                clip_height = m_Height;
            }
       
            if (m_offset == 0) {
                y = pageSize_height / 2 - m_Height / 2;
            } else {
                y = m_offset;
            }
            
            
            
            double tempPagewidth = pageSize_width;
            
            annot = signedInfo->addStampAnnot();
            if ( annot == NULL ) {
                continue;
            }
            annot->setID(idProvider->incrementAndGet().c_str());
           
            annot->setBoundary(x,y,m_Width,m_Height);
            annot->setClip(clip_x,clip_y,clip_width,clip_height);
            
            pageid = ctx->getPageObjectId(i + 1);
            
            annot->setPageRef(pageid);

            if (0 != i && numPage - 1 != i) {
                if (m_cuttingRatios.size() > 0) {
                    itemWith = m_Width * m_cuttingRatios[i-1].right;
                }
                x = tempPagewidth - itemWith - m_margin;
                
                clip_x = 0;
                clip_y = 0;
                clip_width = itemWith;
                clip_height = m_Height;
                
                annot = signedInfo->addStampAnnot();
                if ( annot == NULL ) {
                    continue;
                }
                annot->setID(idProvider->incrementAndGet().c_str());
                
                annot->setBoundary(x,y,m_Width,m_Height);
                annot->setClip(clip_x,clip_y,clip_width,clip_height);
                annot->setPageRef(pageid);
                
            }
            
        }
    } else if (m_side == FZZRidingStampPos::TYPE::TYPE_Top) {
        itemHeight = m_Height * 0.5;
        for (int i = 0; i < numPage; i++) {
            page = ctx->getPage(i + 1);
            ctx->getPageSize(page,pageSize_x,pageSize_y,pageSize_width,pageSize_height);
            if (numPage - 1 != i) {
                if (m_cuttingRatios.size() > 0) {
                    itemHeight = m_Height * m_cuttingRatios[i].left;
                }
                y = pageSize_height - itemHeight - m_margin;
                
                clip_x = 0;
                clip_y = 0;
                clip_width = m_Width;
                clip_height = itemHeight;
            } else {
                if (m_cuttingRatios.size() > 0) {
                    itemHeight = m_Height * m_cuttingRatios[i-1].right;
                }
                y = 0 - (m_Height - itemHeight) + m_margin;
                
                clip_x = 0;
                clip_y = (m_Height - itemHeight);
                clip_width = m_Width;
                clip_height = itemHeight;
            }
        
            if (m_offset == 0) {
                x = pageSize_width / 2 - m_Width / 2;
            } else {
                x = m_offset;
            }
            
            annot = signedInfo->addStampAnnot();
            if ( annot == NULL ) {
                continue;
            }
            annot->setID(idProvider->incrementAndGet().c_str());
        
            annot->setBoundary(x,y,m_Width,m_Height);
            annot->setClip(clip_x,clip_y,clip_width,clip_height);
            
            pageid = ctx->getPageObjectId(i + 1);
            
            annot->setPageRef(pageid);
            
            

            if (0 != i && numPage - 1 != i) {
                if (m_cuttingRatios.size() > 0) {
                    itemHeight = m_Height * m_cuttingRatios[i-1].right;
                }
                y = 0 - (m_Height - itemHeight) + m_margin;
                
                
                clip_x = 0;
                clip_y = (m_Height - itemHeight);
                clip_width = m_Width;
                clip_height = itemHeight;
                annot = signedInfo->addStampAnnot();
                if ( annot == NULL ) {
                    continue;
                }
                annot->setID(idProvider->incrementAndGet().c_str());
                
                annot->setBoundary(x,y,m_Width,m_Height);
                annot->setClip(clip_x,clip_y,clip_width,clip_height);
                annot->setPageRef(pageid);

            }
            
            
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
int FZZCuttingRideStampPos::floor_div(int a, int b)
{
    int d = a / b;
    return d * b == a ? d : d - ((a < 0) ^ (b < 0));
}
//-----------------------------------------------------------------------------------------------------------------
int FZZCuttingRideStampPos::floorMod(int a, int b)
{
    return (a - (floor_div(a,b)* b));
}
//-----------------------------------------------------------------------------------------------------------------

