//
//  Created by zizheng fan on 2023/01/08.
//
#include "basic/FZZConst.h"
#include "ofd/sign/stamppos/FZZNormalStampPos.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZNormalStampPos*********************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZNormalStampPos::FZZNormalStampPos() : FZZStampAppearance(),m_PageIndex(0),m_X(0.0),m_Y(0.0),m_Width(0.0),m_Height(0.0)
{
    //DLOG("FZZNormalStampPos()");
    FZZConst::addClassCount("FZZNormalStampPos");
}
//-----------------------------------------------------------------------------------------------------------------
FZZNormalStampPos::FZZNormalStampPos(int pageIndex,double x,double y, double width, double height) : FZZNormalStampPos()
{
    m_PageIndex = pageIndex;
    m_X = x;
    m_Y = y;
    m_Width = width;
    m_Height = height;
}
//-----------------------------------------------------------------------------------------------------------------
FZZNormalStampPos::~FZZNormalStampPos()
{
    //DLOG("~FZZNormalStampPos()");
    FZZConst::delClassCount("FZZNormalStampPos");
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZNormalStampPos::getAppearance(FZZOFD* ctx, FZZSignIDProvider* idProvider,FZZOFDSignedInfo * signedInfo)
{
    if ( ctx == NULL || idProvider == NULL || signedInfo == NULL) {
        return;
    }
    FZZOFDStampAnnot* annot = signedInfo->addStampAnnot();
    if ( annot == NULL ) {
        return;
    }
    annot->setID(idProvider->incrementAndGet().c_str());
    annot->setBoundary(m_X,m_Y,m_Width,m_Height);
    annot->setPageRef(ctx->getPageObjectId(m_PageIndex));
}
//-----------------------------------------------------------------------------------------------------------------




