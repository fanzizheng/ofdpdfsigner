//
//  Created by zizheng fan on 2023/01/09.
//
#include "basic/FZZConst.h"
#include "ofd/sign/stamppos/FZZRidingStampPos.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZRidingStampPos*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZRidingStampPos::FZZRidingStampPos() : FZZStampAppearance(),m_side(FZZRidingStampPos::TYPE::TYPE_Right),m_clipNumber(0),m_offset(0.0),m_margin(0.0),m_Width(0.0),m_Height(0.0)
{
    //DLOG("FZZRidingStampPos()");
    FZZConst::addClassCount("FZZRidingStampPos");
}
//-----------------------------------------------------------------------------------------------------------------
FZZRidingStampPos::FZZRidingStampPos(double width, double height): FZZRidingStampPos()
{
    m_Width = width;
    m_Height = height;
}
//-----------------------------------------------------------------------------------------------------------------
FZZRidingStampPos::FZZRidingStampPos(FZZRidingStampPos::TYPE side, double width, double height): FZZRidingStampPos()
{
    m_side = side;
    m_Width = width;
    m_Height = height;
}
//-----------------------------------------------------------------------------------------------------------------
FZZRidingStampPos::FZZRidingStampPos(FZZRidingStampPos::TYPE side, double offset, double width, double height): FZZRidingStampPos()
{
    m_side = side;
    m_offset = offset;
    m_Width = width;
    m_Height = height;
}
//-----------------------------------------------------------------------------------------------------------------
FZZRidingStampPos::FZZRidingStampPos(FZZRidingStampPos::TYPE side, double offset, double width, double height, double margin): FZZRidingStampPos()
{
    m_side = side;
    m_offset = offset;
    m_Width = width;
    m_Height = height;
    m_margin = margin;
}
//-----------------------------------------------------------------------------------------------------------------
FZZRidingStampPos::FZZRidingStampPos(FZZRidingStampPos::TYPE side, double offset, int clipNumber, double width, double height, double margin): FZZRidingStampPos()
{
    m_side = side;
    m_offset = offset;
    m_Width = width;
    m_Height = height;
    m_margin = margin;
    m_clipNumber = clipNumber;
}
//-----------------------------------------------------------------------------------------------------------------
FZZRidingStampPos::~FZZRidingStampPos()
{
    //DLOG("~FZZRidingStampPos()");
    FZZConst::delClassCount("FZZRidingStampPos");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZRidingStampPos::getAppearance(FZZOFD* ctx, FZZSignIDProvider* idProvider,FZZOFDSignedInfo * signedInfo)
{
    int numPage = 0;
    bool isClipNumber = false;
    int leftClipNumber = 0;
    double itemWith = 0;
    double itemHeight = 0;
    int i = 0;
    int index = 0;
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
 
    FZZOFDStampAnnot * annot = NULL;
 
    if ( ctx == NULL || idProvider == NULL || signedInfo == NULL) {
        return;
    }
    
    numPage = ctx->getPageCount();
    isClipNumber = m_clipNumber > 0 && m_clipNumber < numPage;
    if (m_side == FZZRidingStampPos::TYPE::TYPE_Right || m_side == FZZRidingStampPos::TYPE::TYPE_Left) {
        itemWith = m_Width / numPage;
        if (isClipNumber) {
            itemWith = m_Width / m_clipNumber;
            leftClipNumber = numPage % m_clipNumber;
            if (leftClipNumber == 1) {
                leftClipNumber = m_clipNumber + 1;
            }
        }
        
        for (i = 0; i < numPage; i++) {
            index = leftClipNumber == 0 ? i : (leftClipNumber + i - numPage);
            if (numPage - i <= leftClipNumber) {
                m_clipNumber = leftClipNumber;
                itemWith = m_Width / m_clipNumber;
            }
            page = ctx->getPage(i + 1);
            ctx->getPageSize(page,pageSize_x,pageSize_y,pageSize_width,pageSize_height);
            
            if (m_side == FZZRidingStampPos::TYPE::TYPE_Right) {
                x = pageSize_width - itemWith * (i + 1) - m_margin;
                clip_x = i * itemWith;
                clip_y = 0;
                clip_width = itemWith;
                clip_height = m_Height;
                
              
                if (isClipNumber) {
                    x = pageSize_width - (floorMod(index, m_clipNumber) + 1) * itemWith - m_margin;
                    
                    clip_x = floorMod(index, m_clipNumber) * itemWith;
                    clip_y = 0;
                    clip_width = itemWith;
                    clip_height = m_Height;
                }
            } else {
                x = 0 - itemWith * (numPage - 1 - i) + m_margin;
               
                clip_x = (numPage - 1 - i) * itemWith;
                clip_y = 0;
                clip_width = itemWith;
                clip_height = m_Height;
                if (isClipNumber) {
                    x = 0 - itemWith * (floorMod(index, m_clipNumber)) + m_margin;
                    
                    clip_x = floorMod(index, m_clipNumber) * itemWith;
                    clip_y = 0;
                    clip_width = itemWith;
                    clip_height = m_Height;
                }
            }
            
            if (m_offset == 0) {
                // 居中
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
            
        } //for
        
    } else {
        itemHeight = m_Height / numPage;
        if (isClipNumber) {
            itemHeight = m_Height / m_clipNumber;
            leftClipNumber = numPage % m_clipNumber;
            if (leftClipNumber == 1) {
                leftClipNumber = m_clipNumber + 1;
            }
        }
        for (int i = 0; i < numPage; i++) {
            index = leftClipNumber == 0 ? i : (leftClipNumber + i - numPage);
            if (numPage - i <= leftClipNumber) {
                m_clipNumber = leftClipNumber;
                itemHeight = m_Width / m_clipNumber;
            }
            page = ctx->getPage(i + 1);
            ctx->getPageSize(page,pageSize_x,pageSize_y,pageSize_width,pageSize_height);

            if (m_offset == 0) {
                // 居中
                x = pageSize_width / 2 - m_Width / 2;
            } else {
                x = m_offset;
            }

            if (m_side == FZZRidingStampPos::TYPE::TYPE_Bottom) {
                y = pageSize_height - itemHeight * (i + 1) - m_margin;
                
                clip_x = 0;
                clip_y = itemHeight * i;
                clip_width = m_Width;
                clip_height = itemHeight;
                
                if (isClipNumber) {
                    y = pageSize_height - (floorMod(index, m_clipNumber) + 1) * itemHeight - m_margin;
                    
                    clip_x = 0;
                    clip_y = itemHeight * floorMod(index, m_clipNumber);
                    clip_width = m_Width;
                    clip_height = itemHeight;
                }

            } else {
                y = 0 - itemHeight * (numPage - 1 - i) + m_margin;
                
                clip_x = 0;
                clip_y = (numPage - 1 - i) * itemHeight;
                clip_width = m_Width;
                clip_height = itemHeight;
                if (isClipNumber) {
                    y = 0 - itemHeight * floorMod(index, m_clipNumber) + m_margin;
                    
                    clip_x = 0;
                    clip_y = floorMod(index, m_clipNumber) * itemHeight;
                    clip_width = m_Width;
                    clip_height = itemHeight;
                }
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
            
            

            
        } //for
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
int FZZRidingStampPos::floor_div(int a, int b)
{
    int d = a / b;
    return d * b == a ? d : d - ((a < 0) ^ (b < 0));
}
//-----------------------------------------------------------------------------------------------------------------
int FZZRidingStampPos::floorMod(int a, int b)
{
    return (a - (floor_div(a,b)* b));
}
//-----------------------------------------------------------------------------------------------------------------

