//
//  Created by zizheng fan on 2024/03/25.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/draw/FZZOFDDrawContext.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDAction.h"
#include "ofd/ofdxmlelement/basicStructure/action/FZZOFDActions.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClips.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClip.h"
#include "ofd/FZZOFD.h"
#define _USE_MATH_DEFINES
#include "math.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDDrawContext**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawContext::FZZOFDDrawContext() : m_maxUnitID(NULL),m_container(NULL),m_boundary(""),m_BoundaryBox_x(0.0f), m_BoundaryBox_y(0.0f), m_BoundaryBox_width(0.0f), m_BoundaryBox_height(0.0f),m_ctm(""),m_alpha(0.0),m_workPathObj(NULL),m_pathData(NULL),m_FZZOFD(NULL),m_FontName(""),m_FontSize(0),m_FontBold(false),m_FontItalic(false)
{
    //DLOG("FZZOFDDrawContext()");
    FZZConst::addClassCount("FZZOFDDrawContext");
    m_fillColor[0] = 0;
    m_fillColor[1] = 0;
    m_fillColor[2] = 0;
    
    m_strokeColor[0] = 0;
    m_strokeColor[1] = 0;
    m_strokeColor[2] = 0;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawContext::FZZOFDDrawContext(FZZOFD * ofd,FZZOFDPageBlock * container,FZZAtomicInteger* maxUnitID) : FZZOFDDrawContext()
{
    m_maxUnitID = maxUnitID;
    m_container = container;
    m_FZZOFD = ofd;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawContext::~FZZOFDDrawContext()
{
    //DLOG("~FZZOFDDrawContext()");
    FZZConst::delClassCount("FZZOFDDrawContext");

}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::beginPath()
{
    flushPath();
    m_workPathObj = NULL;
    if (m_container == NULL) return;
    FZZOFDPathObject * path = (FZZOFDPathObject*)m_container->addPageBlock(FZZOFDPageBlockType::TYPE::TYPT_PathObject);
    if (path == NULL) return;
    if (!m_boundary.empty()) {
        path->setBoundary(m_boundary);
    }
    
    if (!m_ctm.empty()) {
        path->setCTM(m_ctm);
    }
    
    path->setAlpha((int)(255* m_alpha));
        
    m_workPathObj = path;
    m_pathData = m_workPathObj->setAbbreviatedData();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::flushPath()
{
    if (m_workPathObj == NULL || m_pathData == NULL)
        return;
    if (m_workPathObj->getStroke() || m_workPathObj->getFill()) {
        m_workPathObj->setID(m_maxUnitID->incrementAndGet());
        m_pathData->flush();
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setFillColor(int r, int g, int b)
{
    m_fillColor[0] = r;
    m_fillColor[1] = g;
    m_fillColor[2] = b;
    if (m_workPathObj != NULL) {
        FZZOFDFillColor * fillColor = m_workPathObj->setFillColor();
        if ( fillColor != NULL ) {
            string strColor = FZZConst::fmt(r) + " " + FZZConst::fmt(g) + " " + FZZConst::fmt(b);
            fillColor->setValue(strColor);
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCellContent * FZZOFDDrawContext::setPath_Pattern(double width,double height,double XStep,double YStep)
{
    FZZOFDCellContent * tempContent = NULL;
    if (m_workPathObj == NULL )
        return tempContent;
    FZZOFDFillColor * fillColor = m_workPathObj->setFillColor();
    if ( fillColor == NULL ) {
        return tempContent;
    }
    FZZOFDPattern * ofdPattern = fillColor->setPattern();
    if ( ofdPattern == NULL ) {
        return tempContent;
    }
    tempContent = ofdPattern->setCellContent();
    if ( tempContent == NULL ) {
        return tempContent;
    }
    tempContent->setID(m_maxUnitID->incrementAndGet());
    
    ofdPattern->setWidth(width);
    ofdPattern->setHeight(height);
    ofdPattern->setXStep(XStep);
    ofdPattern->setYStep(YStep);
    return tempContent;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::fill()
{
    if (m_workPathObj != NULL) {
        m_workPathObj->setFill(true);
        m_workPathObj->setStroke(false);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setStrokeColor(int r, int g, int b)
{
    m_strokeColor[0] = r;
    m_strokeColor[1] = g;
    m_strokeColor[2] = b;
    if (m_workPathObj != NULL) {
        FZZOFDStrokeColor * strokeColor = m_workPathObj->setStrokeColor();
        if ( strokeColor != NULL ) {
            string strColor = FZZConst::fmt(r) + " " + FZZConst::fmt(g) + " " + FZZConst::fmt(b);
            strokeColor->setValue(strColor);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::stroke()
{
    if (m_workPathObj != NULL) {
        m_workPathObj->setFill(false);
        m_workPathObj->setStroke(true);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setPathObject_Actiton(string cmd)
{
    if (m_workPathObj == NULL) {
        return;
    }
    if (!cmd.empty()) {
        string tempcmd = cmd;
        size_t pos = tempcmd.find(":");
        if (pos != string::npos) {
            string tempstr = tempcmd.substr(0,pos);
            tempcmd = tempcmd.substr(pos+1);
            FZZOFDAction* ctActiton = NULL;
            if ( tempstr == "DO" ) {
                FZZOFDActions * actions = m_workPathObj->setActions();
                if ( actions != NULL ) {
                    ctActiton = actions->addAction();
                    if ( ctActiton != NULL ) {
                        ctActiton->setEvent(EventType::DO);
                        
                    }
                }
                
            } else if (tempstr == "PO") {
                FZZOFDActions * actions = m_workPathObj->setActions();
                if ( actions != NULL ) {
                    ctActiton = actions->addAction();
                    if ( ctActiton != NULL ) {
                        ctActiton->setEvent(EventType::PO);
                    }
                }
                
            } else if (tempstr == "CLICK") {
                FZZOFDActions * actions = m_workPathObj->setActions();
                if ( actions != NULL ) {
                    ctActiton = actions->addAction();
                    if ( ctActiton != NULL ) {
                        ctActiton->setEvent(EventType::CLICK);
                    }
                }
            }
            
            if ( ctActiton != NULL ) {
                pos = tempcmd.find("->");
                if (pos != string::npos) {
                    tempstr = tempcmd.substr(0,pos);
                    tempcmd = tempcmd.substr(pos+2);
                    
                    if ( tempstr == "GotoA" ) {
                        FZZOFDGotoA*  gotoA = ctActiton->setGotoA();
                        if ( gotoA != NULL ) {
                            vector<string> itmes;
                            FZZConst::split(tempcmd.c_str(), ";", itmes);
                            vector<string>::const_iterator itr;
                            for( itr = itmes.begin(); itr != itmes.end(); itr++ ) {
                                tempstr = *itr;
                                pos = tempstr.find(":");
                                if (pos != string::npos) {
                                    if ( tempstr.substr(0,pos) == "NewWindow" ) {
                                        gotoA->setNewWindow(tempstr.substr(pos+1) == "true" ? true : false);
                                    } else if ( tempstr.substr(0,pos) == "AttachID" ) {
                                        gotoA->setAttachID(tempstr.substr(pos+1).c_str());
                                        
                                    }
                                }
                            }//for
                            
                        }//if ( gotoA != NULL ) {
                    }
                    
                    
                }
            }//ctActiton != NULL
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::close(vector<clipItem*>* clipItemList,vector<s_OFD_Box*> * clip_Boxs)
{
    if (m_workPathObj == NULL) {
        return;
    }
    flushPath();
    
    if ( clipItemList != NULL && clipItemList->size() > 0 && clip_Boxs != NULL && clipItemList->size() == clip_Boxs->size() ) {
        
        FZZOFDClips * clips = m_workPathObj->setClips();
        if ( clips == NULL ) return;
        clips->setTransFlag(false);
        
        vector<clipItem*>::const_iterator iter;
        for (iter = clipItemList->begin(); iter != clipItemList->end(); iter++) {
            clipItem * item = *iter;
            if ( item->clip_PathData != NULL ) {
                FZZOFDClip* clip = clips->addClip();
                if ( clip == NULL ) return;
                FZZOFDClipArea* area = clip->addArea();
                if ( area == NULL ) return;
                if ( item->clip_ctms != NULL )
                area->setCTM(*item->clip_ctms);
                
                FZZOFDPath * ct_path = area->setPath();
                if ( ct_path == NULL ) return;
//                ST_Box* tempBox = *(clip_Boxs->begin()+(iter-clip_PathDatas->begin()));
//
//                ct_path->setBoundary(tempBox->getTopLeftX()-m_boundary->getTopLeftX(),tempBox->getTopLeftY()-m_boundary->getTopLeftY(),tempBox->getWidth(),tempBox->getHeight());
                
                ct_path->setBoundary( (*(clip_Boxs->begin()+(iter-clipItemList->begin())))->strBox );
                ct_path->setFill(item->clip_isFill);
                ct_path->setStroke(item->clip_isStroke);
                if ( item->clip_isStroke ) {
                    ct_path->setLineWidth(item->clip_StrokeLineWidth);
                }
                FZZOFDAbbreviatedData* pathdata = ct_path->setAbbreviatedData();
                if ( pathdata == NULL ) return;
                pathdata->copy(item->clip_PathData);
                pathdata->flush();
                
            }
        }
        
        
       
    }
    m_workPathObj = NULL;
}

//void FZZOFDDrawContext::close(vector<FZZOFDAbbreviatedData*>* clip_PathDatas,vector<s_OFD_Box> * clip_Boxs,
//                        vector<string> * clip_ctms,vector<bool> * clip_isFill,vector<bool>* clip_isStroke,vector<float> * clip_StrokeLineWidth)
//{
//    if (m_workPathObj == NULL) {
//        return;
//    }
//    flushPath();
//
//    if ( clip_PathDatas != NULL && clip_Boxs != NULL && clip_ctms != NULL
//        && clip_PathDatas->size() > 0 && clip_PathDatas->size() == clip_Boxs->size()
//        && clip_PathDatas->size() == clip_ctms->size() && clip_PathDatas->size() == clip_isFill->size()
//        && clip_PathDatas->size() == clip_isStroke->size() && clip_PathDatas->size() == clip_StrokeLineWidth->size() ) {
//
//        FZZOFDClips * clips = m_workPathObj->setClips();
//        if ( clips == NULL ) return;
//        clips->setTransFlag(false);
//
//        vector<FZZOFDAbbreviatedData*>::const_iterator iter;
//        for (iter = clip_PathDatas->begin(); iter != clip_PathDatas->end(); iter++) {
//            FZZOFDAbbreviatedData* temp = *iter;
//            if ( temp != NULL ) {
//                FZZOFDClip* clip = clips->addClip();
//                if ( clip == NULL ) return;
//                FZZOFDClipArea* area = clip->addArea();
//                if ( area == NULL ) return;
//                area->setCTM(*(clip_ctms->begin()+(iter-clip_PathDatas->begin())));
//
//                FZZOFDPath * ct_path = area->setPath();
//                if ( ct_path == NULL ) return;
////                ST_Box* tempBox = *(clip_Boxs->begin()+(iter-clip_PathDatas->begin()));
////
////                ct_path->setBoundary(tempBox->getTopLeftX()-m_boundary->getTopLeftX(),tempBox->getTopLeftY()-m_boundary->getTopLeftY(),tempBox->getWidth(),tempBox->getHeight());
//                ct_path->setBoundary( (*(clip_Boxs->begin()+(iter-clip_PathDatas->begin()))).strBox );
//                ct_path->setFill(*(clip_isFill->begin()+(iter-clip_PathDatas->begin())));
//                ct_path->setStroke(*(clip_isStroke->begin()+(iter-clip_PathDatas->begin())));
//                if ( *(clip_isStroke->begin()+(iter-clip_PathDatas->begin())) ) {
//                    ct_path->setLineWidth(*(clip_StrokeLineWidth->begin()+(iter-clip_PathDatas->begin())));
//                }
//                FZZOFDAbbreviatedData* pathdata = ct_path->setAbbreviatedData();
//                if ( pathdata == NULL ) return;
//                pathdata->copy(temp);
//                pathdata->flush();
//
//            }
//        }
//
//
//
//    }
//    m_workPathObj = NULL;
//}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::moveTo(double x, double y)
{
    if (m_workPathObj == NULL) {
        beginPath();
    }
    m_pathData->moveTo(x, y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::lineTo(double x, double y)
{
    if (m_workPathObj == NULL) {
        beginPath();
    }
    m_pathData->lineTo(x, y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::quadraticCurveTo(double cpx, double cpy, double x, double y)
{
    if (m_workPathObj == NULL) {
        beginPath();
    }
    m_pathData->quadraticBezier(cpx, cpy, x, y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::bezierCurveTo(double cp1x, double cp1y, double cp2x, double cp2y, double x, double y)
{
    if (m_workPathObj == NULL) {
        beginPath();
    }
    m_pathData->cubicBezier(cp1x, cp1y, cp2x, cp2y, x, y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::arc(double a, double b, double angle, bool large, bool sweep, double x, double y)
{
    if (m_workPathObj == NULL) {
        beginPath();
    }
    m_pathData->arc(a, b, (int)angle % 360, large ? 1 : 0, sweep ? 1 : 0, x, y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::arc(double x, double y, double r, double sAngle, double eAngle, bool counterclockwise)
{
    if (m_workPathObj == NULL) {
        beginPath();
    }
    double x1 = x + r * cos(sAngle * M_PI / 180);
    double y1 = y + r * sin(sAngle * M_PI / 180);
    moveTo(x1, y1);


    double angle = eAngle - sAngle;
    if (angle == 360) {
     
        m_pathData->arc(r, r, angle, 1, counterclockwise ? 1 : 0, x - r, y);
        m_pathData->arc(r, r, angle, 1, counterclockwise ? 1 : 0, x1, y1);
    }
    else {
     
        double x2 = x + r * cos(eAngle * M_PI / 180);
        double y2 = y + r * sin(eAngle * M_PI / 180);
        m_pathData->arc(r, r, angle,
            angle > 180 ? 1 : 0,
            counterclockwise ? 1 : 0,
            x2, y2);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::arc(double x, double y, double r, double sAngle, double eAngle)
{
    return arc(x, y, r, sAngle, eAngle, true);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::rect(double x, double y, double width, double height)
{
    if (m_workPathObj == NULL) {
        beginPath();
    }
    m_pathData->moveTo(x, y);
    m_pathData->lineTo(x + width, y);
    m_pathData->lineTo(x + width, y + height);
    m_pathData->lineTo(x, y + height);
    m_pathData->close();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::closePath()
{
    if (m_workPathObj != NULL) {
        m_pathData->close();
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setBoundary(string boundary) {
    m_boundary = boundary;
    if ( !m_boundary.empty() ) {
        ST_Box_ToDouble(m_boundary, m_BoundaryBox_x, m_BoundaryBox_y, m_BoundaryBox_width, m_BoundaryBox_height);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setLineWidth(double lineWidth)
{
    if (m_workPathObj != NULL) {
        m_workPathObj->setLineWidth(lineWidth);
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setDashOffset(double dashOffset)
{
    if (m_workPathObj != NULL) {
        m_workPathObj->setDashOffset(dashOffset);
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setMiterLimit(double miterLimit)
{
    if (m_workPathObj != NULL) {
        m_workPathObj->setMiterLimit(miterLimit);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setDashPattern(string dashPattern)
{
    if (m_workPathObj != NULL) {
        m_workPathObj->setDashPattern(dashPattern);
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setCap(FZZOFDLineCapType::TYPE cap)
{
    if (m_workPathObj != NULL) {
        m_workPathObj->setCap(cap);
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setLineJoin(FZZOFDLineJoinType::TYPE join)
{
    if (m_workPathObj != NULL) {
        m_workPathObj->setJoin(join);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::drawImage(const unsigned char * imageBuffer,int imageSize,const char * const imageType,
    double x, double y,
    double width, double height,vector<clipItem*>* clipItemList,vector<s_OFD_Box*> * clip_Boxs)
{
    if (m_FZZOFD == NULL || imageBuffer == NULL || imageSize < 2  ) {
        return;
    }
    
    FZZOFDImageObject* imgObj = (FZZOFDImageObject*)m_container->addPageBlock(FZZOFDPageBlockType::TYPE::TYPT_ImageObject);
    
    string id = m_FZZOFD->addImageRes(imageBuffer,imageSize,imageType);
    imgObj->setID(m_maxUnitID->incrementAndGet());
    
    imgObj->setResourceID(id);
    
    imgObj->setBoundary(m_boundary);
    string ctm = "";
 
    if (m_ctm.empty()) {
        m_ctm = CTM_Mul(width,0,0,height,x,y,1, 0, 0, 1, 0, 0);
    }
    else {
        ctm = m_ctm;
    }
    imgObj->setCTM(ctm);
    
 
    imgObj->setAlpha((int)(255 * m_alpha));
    
    if ( clipItemList != NULL && clip_Boxs != NULL && clipItemList->size() > 0 && clipItemList->size() == clip_Boxs->size()) {
        
        FZZOFDClips* clips = imgObj->setClips();
        if ( clips == NULL ) return;
        clips->setTransFlag(false);
        
        vector<clipItem*>::const_iterator iter;
        for (iter = clipItemList->begin(); iter != clipItemList->end(); iter++) {
            clipItem* temp = *iter;
            if ( temp != NULL ) {
                FZZOFDClip * clip = clips->addClip();
                if ( clip == NULL ) return;
                FZZOFDClipArea * area = clip->addArea();
                if ( area == NULL ) return;
                if ( temp->clip_ctms != NULL ) {
                    area->setCTM(*temp->clip_ctms);
                }
   
                FZZOFDPath* ct_path = area->setPath();
                if ( ct_path == NULL ) return;
//                ST_Box* tempBox = *(clip_Boxs->begin()+(iter-clip_PathDatas->begin()));
//
//                ct_path->setBoundary(tempBox->getTopLeftX()-m_boundary->getTopLeftX(),tempBox->getTopLeftY()-m_boundary->getTopLeftY(),tempBox->getWidth(),tempBox->getHeight());
               
                ct_path->setBoundary((*(clip_Boxs->begin()+(iter-clipItemList->begin())))->strBox);
                ct_path->setFill(temp->clip_isFill);
                ct_path->setStroke(temp->clip_isStroke);
                if ( temp->clip_isStroke ) {
                    ct_path->setLineWidth(temp->clip_StrokeLineWidth);
                }
                FZZOFDAbbreviatedData* pathdata = ct_path->setAbbreviatedData();
                if ( pathdata == NULL ) return;
                pathdata->copy(temp->clip_PathData);
                pathdata->flush();
                
            }
        }
        
        
       
    }
}
//void FZZOFDDrawContext::drawImage(const unsigned char * imageBuffer,int imageSize,const char * const imageType,
//    double x, double y,
//    double width, double height,vector<FZZOFDAbbreviatedData*>* clip_PathDatas,
//                            vector<s_OFD_Box> * clip_Boxs,vector<string> * clip_ctms,vector<bool> * clip_isFill,vector<bool>* clip_isStroke,vector<float> * clip_StrokeLineWidth)
//{
//
//    if (m_FZZOFD == NULL || imageBuffer == NULL || imageSize < 2  ) {
//        return;
//    }
//
//    FZZOFDImageObject* imgObj = (FZZOFDImageObject*)m_container->addPageBlock(FZZOFDPageBlockType::TYPE::TYPT_ImageObject);
//
//    string id = m_FZZOFD->addImageRes(imageBuffer,imageSize,imageType);
//    imgObj->setID(m_maxUnitID->incrementAndGet());
//
//    imgObj->setResourceID(id);
//
//    imgObj->setBoundary(m_boundary);
//    string ctm = "";
//
//    if (m_ctm.empty()) {
//        m_ctm = CTM_Mul(width,0,0,height,x,y,1, 0, 0, 1, 0, 0);
//    }
//    else {
//        ctm = m_ctm;
//    }
//    imgObj->setCTM(ctm);
//
//
//    imgObj->setAlpha((int)(255 * m_alpha));
//
//    if ( clip_PathDatas != NULL && clip_Boxs != NULL && clip_ctms != NULL
//        && clip_PathDatas->size() > 0 && clip_PathDatas->size() == clip_Boxs->size()
//        && clip_PathDatas->size() == clip_ctms->size() && clip_PathDatas->size() == clip_isFill->size()
//        && clip_PathDatas->size() == clip_isStroke->size() && clip_PathDatas->size() == clip_StrokeLineWidth->size() ) {
//
//        FZZOFDClips* clips = imgObj->setClips();
//        if ( clips == NULL ) return;
//        clips->setTransFlag(false);
//
//        vector<FZZOFDAbbreviatedData*>::const_iterator iter;
//        for (iter = clip_PathDatas->begin(); iter != clip_PathDatas->end(); iter++) {
//            FZZOFDAbbreviatedData* temp = *iter;
//            if ( temp != NULL ) {
//                FZZOFDClip * clip = clips->addClip();
//                if ( clip == NULL ) return;
//                FZZOFDClipArea * area = clip->addArea();
//                if ( area == NULL ) return;
//                area->setCTM(*(clip_ctms->begin()+(iter-clip_PathDatas->begin())));
//
//                FZZOFDPath* ct_path = area->setPath();
//                if ( ct_path == NULL ) return;
////                ST_Box* tempBox = *(clip_Boxs->begin()+(iter-clip_PathDatas->begin()));
////
////                ct_path->setBoundary(tempBox->getTopLeftX()-m_boundary->getTopLeftX(),tempBox->getTopLeftY()-m_boundary->getTopLeftY(),tempBox->getWidth(),tempBox->getHeight());
//
//                ct_path->setBoundary((*(clip_Boxs->begin()+(iter-clip_PathDatas->begin()))).strBox);
//                ct_path->setFill(*(clip_isFill->begin()+(iter-clip_PathDatas->begin())));
//                ct_path->setStroke(*(clip_isStroke->begin()+(iter-clip_PathDatas->begin())));
//                if ( *(clip_isStroke->begin()+(iter-clip_PathDatas->begin())) ) {
//                    ct_path->setLineWidth(*(clip_StrokeLineWidth->begin()+(iter-clip_PathDatas->begin())));
//                }
//                FZZOFDAbbreviatedData* pathdata = ct_path->setAbbreviatedData();
//                if ( pathdata == NULL ) return;
//                pathdata->copy(temp);
//                pathdata->flush();
//
//            }
//        }
//
//
//
//    }
//
//}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::setFontParam(string fontName,double fontSize,bool isBold,bool isItalic)
{
    m_FontName = fontName;
    m_FontSize = fontSize;
    m_FontBold = isBold;
    m_FontItalic = isItalic;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDDrawContext::drawText(const char * const text, double x, double y,bool isFill,bool isStroke,double lineWidth,double miterLimit, vector<string> &DeltaX,vector<string> &DeltaY,vector<string> &glyphs,
              vector<clipItem*>* clipItemList,vector<s_OFD_Box*> * clip_Boxs)
{
    FZZOFDDirection::TYPE readDirection = FZZOFDDirection::TYPE::Angle_0;
    FZZOFDDirection::TYPE charDirection = FZZOFDDirection::TYPE::Angle_0;
    double fontSize = m_FontSize;

    
    string id = m_FZZOFD->addFontRes(m_FontName);
    if (id.empty()) return;
    
    FZZOFDTextObject* txtObj = (FZZOFDTextObject*)m_container->addPageBlock(FZZOFDPageBlockType::TYPE::TYPT_TextObject);
    if (txtObj == NULL) return;
    
    txtObj->setFill(isFill);
    if ( isStroke ) {
        txtObj->setStroke(isStroke);
        txtObj->setLineWidth(lineWidth);
        txtObj->setMiterLimit(miterLimit);
    }
    txtObj->setBoundary(m_boundary);
    txtObj->setFont(id);
    txtObj->setSize(fontSize);
    txtObj->setID(m_maxUnitID->incrementAndGet());
   
    if (m_FontBold) {
        txtObj->setWeight(FZZOFDWeight::TYPE::W_800);
    }
   
    if (m_FontItalic) {
        txtObj->setItalic(true);
    }
    
    if ( isFill ) {
        FZZOFDFillColor * fc = txtObj->setFillColor();
        if ( fc != NULL ) {
            fc->setValue(FZZConst::fmt(m_fillColor[0]) + " " + FZZConst::fmt(m_fillColor[1]) + " " + FZZConst::fmt(m_fillColor[2]));
        }
    }
    
    if ( isStroke ) {
        FZZOFDStrokeColor* fc = txtObj->setStrokeColor();
        if ( fc != NULL ) {
            fc->setValue(FZZConst::fmt(m_strokeColor[0]) + " " + FZZConst::fmt(m_strokeColor[1]) + " " + FZZConst::fmt(m_strokeColor[2]));
        }
    }
    
    if (!m_ctm.empty()) {
        txtObj->setCTM(m_ctm);
    }
    
    if (m_alpha != 1) {
        txtObj->setAlpha((int)(255 * m_alpha));
    }
  
    if (readDirection != FZZOFDDirection::TYPE::Angle_0) {
        txtObj->setReadDirection(readDirection);
    }
    
    if (charDirection != FZZOFDDirection::TYPE::Angle_0) {
        txtObj->setCharDirection(charDirection);
    }
    
    FZZOFDTextCode* tcSTTxt = txtObj->addTextCode();
    tcSTTxt->setContent(text);
    tcSTTxt->setX(x);
    tcSTTxt->setY(y);
    if ( DeltaX.size() > 0 ) {
        tcSTTxt->setDeltaX(DeltaX);
    }
    if ( DeltaY.size() > 0 ) {
        tcSTTxt->setDeltaY(DeltaY);
    }
    
    if ( glyphs.size() > 0 ) {
        FZZOFDCGTransform* gtransForm = txtObj->addCGTransform();
        if ( gtransForm != NULL ) {
            FZZOFDGlyphs * ofdGlyphs = gtransForm->setGlyphs();
            if ( ofdGlyphs != NULL ) {
                ofdGlyphs->setValue(glyphs);
            }
            gtransForm->setGlyphCount((int)glyphs.size());
            gtransForm->setCodePosition(0);
            //gtransForm->setCodeCount((int)glyphs.size());
            gtransForm->setCodeCount(0);
        }
    }
    
    if ( clipItemList != NULL && clip_Boxs != NULL && clipItemList->size() > 0 && clipItemList->size() == clip_Boxs->size()) {
        
        FZZOFDClips* clips = txtObj->setClips();
        if ( clips == NULL ) return;
        clips->setTransFlag(false);
        
        vector<clipItem*>::const_iterator iter;
        for (iter = clipItemList->begin(); iter != clipItemList->end(); iter++) {
            clipItem* temp = *iter;
            if ( temp != NULL ) {
                FZZOFDClip* clip = clips->addClip();
                if ( clip == NULL ) return;
                FZZOFDClipArea* area = clip->addArea();
                if ( area == NULL ) return;
                if ( temp->clip_ctms != NULL ) {
                    area->setCTM(*temp->clip_ctms);
                }
                
                FZZOFDPath* ct_path = area->setPath();
                if ( ct_path == NULL ) return;
//                ST_Box* tempBox = *(clip_Boxs->begin()+(iter-clip_PathDatas->begin()));
//
//                ct_path->setBoundary(tempBox->getTopLeftX()-m_boundary->getTopLeftX(),tempBox->getTopLeftY()-m_boundary->getTopLeftY(),tempBox->getWidth(),tempBox->getHeight());
                ct_path->setBoundary((*(clip_Boxs->begin()+(iter-clipItemList->begin())))->strBox);
                ct_path->setFill(temp->clip_isFill);
                ct_path->setStroke(temp->clip_isStroke);
                if ( temp->clip_isStroke ) {
                    ct_path->setLineWidth(temp->clip_StrokeLineWidth);
                }
                FZZOFDAbbreviatedData* pathdata = ct_path->setAbbreviatedData();
                if ( pathdata == NULL ) return;
                pathdata->copy(temp->clip_PathData);
                pathdata->flush();
                
            }
        }
        
        
       
    }
}
//void FZZOFDDrawContext::drawText(const char * const text, double x, double y,bool isFill,bool isStroke,double lineWidth,double miterLimit, vector<string> &DeltaX,vector<string> &DeltaY,vector<string> &glyphs,
//                           vector<FZZOFDAbbreviatedData*>* clip_PathDatas,vector<s_OFD_Box> * clip_Boxs,
//                           vector<string> * clip_ctms,vector<bool> * clip_isFill,vector<bool>* clip_isStroke,vector<float> * clip_StrokeLineWidth)
//{
//
//    FZZOFDDirection::TYPE readDirection = FZZOFDDirection::TYPE::Angle_0;
//    FZZOFDDirection::TYPE charDirection = FZZOFDDirection::TYPE::Angle_0;
//    double fontSize = m_FontSize;
//
//
//    string id = m_FZZOFD->addFontRes(m_FontName);
//    if (id.empty()) return;
//
//    FZZOFDTextObject* txtObj = (FZZOFDTextObject*)m_container->addPageBlock(FZZOFDPageBlockType::TYPE::TYPT_TextObject);
//    if (txtObj == NULL) return;
//
//    txtObj->setFill(isFill);
//    if ( isStroke ) {
//        txtObj->setStroke(isStroke);
//        txtObj->setLineWidth(lineWidth);
//        txtObj->setMiterLimit(miterLimit);
//    }
//    txtObj->setBoundary(m_boundary);
//    txtObj->setFont(id);
//    txtObj->setSize(fontSize);
//    txtObj->setID(m_maxUnitID->incrementAndGet());
//
//    if (m_FontBold) {
//        txtObj->setWeight(FZZOFDWeight::TYPE::W_800);
//    }
//
//    if (m_FontItalic) {
//        txtObj->setItalic(true);
//    }
//
//    if ( isFill ) {
//        FZZOFDFillColor * fc = txtObj->setFillColor();
//        if ( fc != NULL ) {
//            fc->setValue(FZZConst::fmt(m_fillColor[0]) + " " + FZZConst::fmt(m_fillColor[1]) + " " + FZZConst::fmt(m_fillColor[2]));
//        }
//    }
//
//    if ( isStroke ) {
//        FZZOFDStrokeColor* fc = txtObj->setStrokeColor();
//        if ( fc != NULL ) {
//            fc->setValue(FZZConst::fmt(m_strokeColor[0]) + " " + FZZConst::fmt(m_strokeColor[1]) + " " + FZZConst::fmt(m_strokeColor[2]));
//        }
//    }
//
//    if (!m_ctm.empty()) {
//        txtObj->setCTM(m_ctm);
//    }
//
//    if (m_alpha != 1) {
//        txtObj->setAlpha((int)(255 * m_alpha));
//    }
//
//    if (readDirection != FZZOFDDirection::TYPE::Angle_0) {
//        txtObj->setReadDirection(readDirection);
//    }
//
//    if (charDirection != FZZOFDDirection::TYPE::Angle_0) {
//        txtObj->setCharDirection(charDirection);
//    }
//
//    FZZOFDTextCode* tcSTTxt = txtObj->addTextCode();
//    tcSTTxt->setContent(text);
//    tcSTTxt->setX(x);
//    tcSTTxt->setY(y);
//    if ( DeltaX.size() > 0 ) {
//        tcSTTxt->setDeltaX(DeltaX);
//    }
//    if ( DeltaY.size() > 0 ) {
//        tcSTTxt->setDeltaY(DeltaY);
//    }
//
//    if ( glyphs.size() > 0 ) {
//        FZZOFDCGTransform* gtransForm = txtObj->addCGTransform();
//        if ( gtransForm != NULL ) {
//            FZZOFDGlyphs * ofdGlyphs = gtransForm->setGlyphs();
//            if ( ofdGlyphs != NULL ) {
//                ofdGlyphs->setValue(glyphs);
//            }
//            gtransForm->setGlyphCount((int)glyphs.size());
//            gtransForm->setCodePosition(0);
//            gtransForm->setCodeCount((int)glyphs.size());
//        }
//    }
//
//    if ( clip_PathDatas != NULL && clip_Boxs != NULL && clip_ctms != NULL
//        && clip_PathDatas->size() > 0 && clip_PathDatas->size() == clip_Boxs->size()
//        && clip_PathDatas->size() == clip_ctms->size() && clip_PathDatas->size() == clip_isFill->size()
//        && clip_PathDatas->size() == clip_isStroke->size() && clip_PathDatas->size() == clip_StrokeLineWidth->size() ) {
//
//        FZZOFDClips* clips = txtObj->setClips();
//        if ( clips == NULL ) return;
//        clips->setTransFlag(false);
//
//        vector<FZZOFDAbbreviatedData*>::const_iterator iter;
//        for (iter = clip_PathDatas->begin(); iter != clip_PathDatas->end(); iter++) {
//            FZZOFDAbbreviatedData* temp = *iter;
//            if ( temp != NULL ) {
//                FZZOFDClip* clip = clips->addClip();
//                if ( clip == NULL ) return;
//                FZZOFDClipArea* area = clip->addArea();
//                if ( area == NULL ) return;
//                area->setCTM(*(clip_ctms->begin()+(iter-clip_PathDatas->begin())));
//
//                FZZOFDPath* ct_path = area->setPath();
//                if ( ct_path == NULL ) return;
////                ST_Box* tempBox = *(clip_Boxs->begin()+(iter-clip_PathDatas->begin()));
////
////                ct_path->setBoundary(tempBox->getTopLeftX()-m_boundary->getTopLeftX(),tempBox->getTopLeftY()-m_boundary->getTopLeftY(),tempBox->getWidth(),tempBox->getHeight());
//                ct_path->setBoundary((*(clip_Boxs->begin()+(iter-clip_PathDatas->begin()))).strBox);
//                ct_path->setFill(*(clip_isFill->begin()+(iter-clip_PathDatas->begin())));
//                ct_path->setStroke(*(clip_isStroke->begin()+(iter-clip_PathDatas->begin())));
//                if ( *(clip_isStroke->begin()+(iter-clip_PathDatas->begin())) ) {
//                    ct_path->setLineWidth(*(clip_StrokeLineWidth->begin()+(iter-clip_PathDatas->begin())));
//                }
//                FZZOFDAbbreviatedData* pathdata = ct_path->setAbbreviatedData();
//                if ( pathdata == NULL ) return;
//                pathdata->copy(temp);
//                pathdata->flush();
//
//            }
//        }
//
//
//
//    }
//
//}
//-----------------------------------------------------------------------------------------------------------------
