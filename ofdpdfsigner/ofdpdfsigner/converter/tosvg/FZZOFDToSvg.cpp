//
//  Created by zizheng fan on 2024/07/23.
//
#include "ofd/FZZOFDConst.h"
#include "converter/tosvg/FZZOFDToSvg.h"
#include "converter/utils/FZZCommonUtil.h"
#include "basic/FZZString.h"
#include "converter/image/FZZOFDToImage.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDToSvg**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDToSvg::FZZOFDToSvg() : m_reader(NULL),m_NoText(false),m_NoStamp(false),m_isAnnotation(false)
{
    //DLOG("FZZOFDToSvg()");
    FZZConst::addClassCount("FZZOFDToSvg");
    m_ppm = FZZCommonUtil::dpiToPpm(72);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDToSvg::FZZOFDToSvg(FZZOFD * reader,double ppm) : FZZOFDToSvg()
{
    m_ppm = ppm;
    
    if ( reader != NULL ) {
        m_reader = reader;
        m_pages = reader->getPageInfoList();
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDToSvg::~FZZOFDToSvg()
{
    //DLOG("~FZZOFDToSvg()");
    FZZConst::delClassCount("FZZOFDToSvg");
    
    m_pages = NULL;
    m_reader = NULL;
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDToSvg::pageSize()
{
    return m_pages == NULL ? 0 : (int)m_pages->size();
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZOFDToSvg::makePage(int pageIndex,bool isNoText,bool isNoStamp)
{
    FZZBytes retBytes;
    
    if ( m_pages == NULL || m_pages->size() <= 0) return retBytes;
    
    if (pageIndex < 0 || pageIndex >= m_pages->size() ) {
        return retBytes;
    }
    
    TPageInfo* pageInfo = *(m_pages->begin() + pageIndex);
    if ( pageInfo == NULL ) {
        DLOG("pageInfo == NULL,pageIndex = %d",pageIndex);
        return retBytes;
    }
    
    int pageWidthPixel = (int) lround(m_ppm * pageInfo->pageSize_width);
    int pageHeightPixel = (int) lround(m_ppm * pageInfo->pageSize_height);

    //std::chrono::system_clock::time_point time_start_ =  std::chrono::system_clock::now();
    FZZSVGUtil imageUtil;
    fz_context * ctx = imageUtil.getContext();
    fz_try(ctx) {
        imageUtil.CreateSVG(pageWidthPixel, pageHeightPixel, /*FZ_SVG_TEXT_AS_TEXT*/FZ_SVG_TEXT_AS_PATH, 1);
        FZZMatrix matrix;
        matrix.reset(); // reset() == matrix.setAll(1.0, 0, 0, 0, 1.0, 0, 0, 0, 1.0);
        //matrix.setAll(1.0, 0, 0, 0, 1.0, 0, 0, 0, 1.0);
        writePage(imageUtil, pageInfo,matrix,isNoText,isNoStamp);
        //int lastrunsec = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - time_start_).count();
        //DLOG("ofd to image run %d ",lastrunsec);
        //time_start_ =  std::chrono::system_clock::now();
        retBytes = imageUtil.SVGEncode();
    } fz_catch(ctx) {
        DLOG("gen svg error : %s",ctx->error.message);
    }
    //lastrunsec = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - time_start_).count();
    //DLOG("image to jpg run %d ",lastrunsec);
     
    return retBytes;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::writePage(FZZSVGUtil& graphics, TPageInfo* pageInfo,FZZMatrix & matrix,bool isNoText,bool isNoStamp)
{
    if ( m_reader == NULL || pageInfo == NULL) {
        return;
    }
    
    m_NoText = isNoText;
    m_NoStamp = isNoStamp;
    
    vector<FZZOFDLayer *>* layerList = &(pageInfo->layerList);
    if ( layerList != NULL ) {
        vector<FZZOFDLayer*>::const_iterator CT_Layer_iter;
        for (CT_Layer_iter = layerList->begin(); CT_Layer_iter != layerList->end(); CT_Layer_iter++) {
            writeContent(graphics, *CT_Layer_iter, NULL,matrix,false,0xff,m_NoText);
        }
    }
    
    if ( !m_NoStamp ) {
        vector<FZZStampAnnotEntity*> * stampAnnotEntityList = m_reader->getStampAnnots();
        
        
        vector<FZZStampAnnotEntity*>::const_iterator StampAnnotEntity_iter;
        for (StampAnnotEntity_iter = stampAnnotEntityList->begin(); StampAnnotEntity_iter != stampAnnotEntityList->end(); StampAnnotEntity_iter++) {
            if ( *StampAnnotEntity_iter != NULL ) {
                vector<FZZOFDStampAnnot*>* stampAnnots = (*StampAnnotEntity_iter)->getStampAnnots_OFD();
                if ( stampAnnots != NULL ) {
                    for ( int i = 0; i < stampAnnots->size(); i++ ) {
                        FZZOFDStampAnnot * stampAnnot = (*stampAnnots)[i];
                        if ( stampAnnot != NULL ) {
                            string temprefid = stampAnnot->getPageRef();
                            if ( !temprefid.empty() ) {
                                if ( temprefid == pageInfo->id ) {
                                    writeStampAnnot(graphics, *StampAnnotEntity_iter, stampAnnot);
                                }
                            }
                        }
                    }
                }
                
            }
        }
        
    
            
    }
    
    vector<FZZOFDPageDir *> * annotationDirList = m_reader->getAnnotationList();
    if ( annotationDirList != NULL ) {
        vector<FZZOFDPageDir*>::const_iterator AnnotionEntity_iter;
        for (AnnotionEntity_iter = annotationDirList->begin(); AnnotionEntity_iter != annotationDirList->end(); AnnotionEntity_iter++) {
            FZZOFDPageDir* annotionEntity = *AnnotionEntity_iter;
            if ( annotionEntity == NULL ) {
                continue;
            }
            FZZOFDPageAnnotXML* pageAnnotXml = annotionEntity->getAnnotationXML();
            if ( annotionEntity->getPageId() == pageInfo->id && pageAnnotXml != NULL ) {
                vector<FZZOFDAnnot_Annotation*>* Annots = pageAnnotXml->getAnnotList();
                if ( Annots != NULL ) {
                    vector<FZZOFDAnnot_Annotation*>::const_iterator Annot_iter;
                    for (Annot_iter = Annots->begin(); Annot_iter != Annots->end(); Annot_iter++) {
                        FZZOFDAnnot_Annotation* tempAnnot = *Annot_iter;
                        if ( tempAnnot != NULL ) {
                            
                            if ( tempAnnot->getSubtype() != "PDFWidgetSign" ) {
                                //fz_rect pbox = { 0,0,(float)graphics.getWidth(),(float)graphics.getHeight() };
                                
                                //graphics.BeginGroup(pbox, NULL, 1, 0, FZ_BLEND_MULTIPLY, 1);
                                
                                FZZMatrix tempmatrix;
                             
                                writeContent(graphics, tempAnnot->getAppearance(), NULL,tempmatrix,false,0xff,false);
                                
                                //graphics.EndGroup();
                            } else {
                                fz_rect pbox = { 0,0,(float)graphics.getWidth(),(float)graphics.getHeight() };
                                
                                graphics.BeginGroup(pbox, NULL, 1, 0, FZ_BLEND_MULTIPLY, 1);
                                
                                FZZMatrix tempmatrix;
                             
                                writeContent(graphics, tempAnnot->getAppearance(), NULL,tempmatrix,false,0xff,false);
                                
                                graphics.EndGroup();
                            }
                            
                        }
                    }
                } //if ( Annots != NULL )
            }
        }//for (AnnotionEntity_iter = annotationDirList->begin(); AnnotionEntity_iter != annotationDirList->end(); AnnotionEntity_iter++)
    }//if ( annotationDirList != NULL )
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::writeStampAnnot( FZZSVGUtil& graphics, FZZStampAnnotEntity* stampAnnotVo, FZZOFDStampAnnot* stampAnnot)
{
    if ( stampAnnotVo == NULL || stampAnnot == NULL) {
        return ;
    }
    FZZBytes imageData = stampAnnotVo->getImageByte();
    if ( imageData.getLen() < 10 ) {
        return;
    }
    
    if ( stampAnnotVo->getImgType() == "ofd" ) {
        //----------test ------------
        //FZZConst::writefile("/Users/fzz/work/cpp/ofd/tmp/sel.zip", imageData.getData(),imageData.getLen());
        //---------------------------
        FZZOFD reader;
        if ( reader.Read(imageData) ) {
            FZZOFDToImage imagemaker(&reader,m_ppm);
            if ( imagemaker.pageSize() > 0 ) {
                imageData = imagemaker.makePage(0, "PNG");
            }
        }
    }
    
    fz_context * ctx = graphics.getContext();
    FZZImageUtil stampImage(ctx);
    if ( !stampImage.LoadImage(imageData) ) {
        return;
    }
    
    stampImage.renderMask(imageData, 255);
    imageData = stampImage.PngEncode();
    
    if ( !stampImage.LoadImage(imageData) ) {
        return;
    }
    
    fz_image * fzimage = stampImage.getImage();
    if ( fzimage == NULL ) {
        return;
    }
    
    double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
    string strBoundaryBox = stampAnnot->getBoundary();
    if ( !strBoundaryBox.empty() ) {
        ST_Box_ToDouble(strBoundaryBox, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
    }
    
 
    double clip_x = 0; double clip_y = 0; double clip_width = 0; double clip_height = 0;
    string strclipBox = stampAnnot->getClip();
    if ( !strclipBox.empty() ) {
        ST_Box_ToDouble(strclipBox, clip_x, clip_y, clip_width, clip_height);
    }
    
    FZZMatrix matrix;
    if ( !strBoundaryBox.empty() ) {
        //matrix.postScale(BoundaryBox_width/stampImage.getWidth(), BoundaryBox_height/stampImage.getHeight());
        matrix.postScale(BoundaryBox_width, BoundaryBox_height);
        //平移
        matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
        
    }
    matrix.postScale(m_ppm,m_ppm);
    //matrix.postScale(stampImage.getWidth(),stampImage.getHeight());
    fz_rect pbox = {0,0,0,0};
    if ( !strBoundaryBox.empty() ) {
        pbox = {(float)BoundaryBox_x, (float)BoundaryBox_y, (float)BoundaryBox_x+(float)BoundaryBox_width, (float)BoundaryBox_y+(float)BoundaryBox_height};
    } else {
        pbox = {0,0,(float)stampImage.getWidth(),(float)stampImage.getHeight()};
    }
    
    FZZMatrix boxmatrix;
    boxmatrix.postScale(m_ppm,m_ppm);
    pbox = fz_transform_rect(pbox, boxmatrix.getMatrix());
    //下面四种目前都对，感觉第三种是最佳方法
    //graphics.BeginGroup(pbox, NULL, 1, 1, FZ_BLEND_MULTIPLY, 1);
    //graphics.BeginGroup(pbox, NULL, 0, 1, FZ_BLEND_MULTIPLY, 1);
    graphics.BeginGroup(pbox, NULL, 1, 0, FZ_BLEND_MULTIPLY, 1);
    //graphics.BeginGroup(pbox, NULL, 0, 0, FZ_BLEND_MULTIPLY, 1);
    
    if ( !strclipBox.empty() ) {
        
        FZZMatrix clipmatrix;
        
        clipmatrix.reset();
        if ( !strBoundaryBox.empty() ) {
            clipmatrix.postScale(BoundaryBox_width/stampImage.getWidth(), BoundaryBox_height/stampImage.getHeight());
            clipmatrix.postTranslate(BoundaryBox_x+clip_x, BoundaryBox_y+clip_y);
        } else {
            clipmatrix.postTranslate(clip_x, clip_y);
        }
        clipmatrix.postScale(m_ppm,m_ppm);
        
        fz_rect cliprect;
        if ( !strBoundaryBox.empty() ) {
            cliprect = { (float) clipmatrix.getTranslateX(), (float) clipmatrix.getTranslateY(),(float) clipmatrix.getTranslateX()+ (float) (stampImage.getWidth() * clipmatrix.getScaleX() * (clip_width / BoundaryBox_width)),
                (float) clipmatrix.getTranslateY() + (float) (stampImage.getHeight() * clipmatrix.getScaleY() * (clip_height / BoundaryBox_height))};
            
            
        } else {
            cliprect = {(float) clipmatrix.getTranslateX(), (float) clipmatrix.getTranslateY(),
                (float) clipmatrix.getTranslateX()+(float) (stampImage.getWidth() * clipmatrix.getScaleX() * (clip_width )),
                (float) clipmatrix.getTranslateY()+(float) (stampImage.getHeight() * clipmatrix.getScaleY() * (clip_height ))};
            
            
        }
        
        FZZPath clippath(ctx);
        clippath.rectTo(cliprect.x0, cliprect.y0,cliprect.x1,cliprect.y1);
        
        graphics.ClipPath(clippath.getPath(),0,MUPDF_fz_identity,cliprect);
    }
    
    graphics.DrawFillImage(fzimage, matrix.getMatrix(), 1);
  
   
    if ( !strclipBox.empty() ) {
        graphics.POPClip();
        
    }
    graphics.EndGroup();
   
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::writeContent( FZZSVGUtil& graphics, FZZOFDPageBlock* pageBlock, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha,int preAlpha,bool isNoText)
{
    vector<FZZOFDDrawParam*> tempdrawParams;
    
    if ( pageBlock == NULL ) return;
    
    if (drawParams != NULL) {
        tempdrawParams.assign(drawParams->begin(), drawParams->end());
    }
    
    if (dynamic_cast<FZZOFDLayer*>(pageBlock) != NULL) {
        string drawParamRef = ((FZZOFDLayer*)pageBlock)->getDrawParam_String();
        addDrawParams(tempdrawParams, drawParamRef);
    }
    
    string strBoundaryBox = pageBlock->getBoundary();
    if ( !strBoundaryBox.empty() ) {
        double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
        ST_Box_ToDouble(strBoundaryBox, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
        //parentMatrix.postTranslate(m_ppm *BoundaryBox->getTopLeftX(), m_ppm *BoundaryBox->getTopLeftY());
        parentMatrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
    }
    
    vector<FZZOFDPageBlockType*>* pageBlockTypes = pageBlock->getPageBlockList();
    vector<FZZOFDPageBlockType*>::const_iterator PageBlockType_iter;
    FZZOFDTextObject * textObj = NULL;
    FZZOFDImageObject * imageObj = NULL;
    FZZOFDPathObject * pathObj = NULL;
    FZZOFDCompositeObject * compositeObj = NULL;
    FZZOFDLayer * layerObj = NULL;
    FZZOFDPageBlock * pageBlockObj = NULL;
    
    for (PageBlockType_iter = pageBlockTypes->begin(); PageBlockType_iter != pageBlockTypes->end(); PageBlockType_iter++) {

        
        if ((textObj = dynamic_cast<FZZOFDTextObject*>(*PageBlockType_iter)) != NULL) {
            addDrawParams(tempdrawParams, textObj->getDrawParam_String()) ;
            if ( !isNoText ) {
                writeText(graphics, textObj, &tempdrawParams,parentMatrix);
            }
            continue;
        } else if ((imageObj = dynamic_cast<FZZOFDImageObject*>(*PageBlockType_iter)) != NULL) {
            addDrawParams(tempdrawParams, imageObj->getDrawParam_String()) ;
            writeImage(graphics, imageObj, &tempdrawParams,parentMatrix);
            continue;
        } else if ((pathObj = dynamic_cast<FZZOFDPathObject*>(*PageBlockType_iter)) != NULL) {
            addDrawParams(tempdrawParams, pathObj->getDrawParam_String()) ;
            writePath(graphics, pathObj, &tempdrawParams,parentMatrix,isUsePreAlpha,preAlpha);
            continue;
//            cc++;
//            if ( cc == 5) {
//                break;
//            }
        } else if ((compositeObj = dynamic_cast<FZZOFDCompositeObject*>(*PageBlockType_iter)) != NULL) {
            addDrawParams(tempdrawParams, compositeObj->getDrawParam_String()) ;
            writeComposite(graphics, compositeObj, &tempdrawParams,parentMatrix,isNoText);
            continue;
        } else if ((layerObj = dynamic_cast<FZZOFDLayer*>(*PageBlockType_iter)) != NULL) {
            
            addDrawParams(tempdrawParams, layerObj->getDrawParam_String()) ;
            writeContent(graphics, layerObj, &tempdrawParams,parentMatrix,isUsePreAlpha, preAlpha, isNoText);
            continue;
        } else if ((pageBlockObj = dynamic_cast<FZZOFDPageBlock*>(*PageBlockType_iter)) != NULL) {
            
            
            writeContent(graphics, pageBlockObj, &tempdrawParams,parentMatrix,isUsePreAlpha, preAlpha, isNoText);
            continue;
        }
        
    }
    //fzz add begin
    //裁剪可能是一组，要先save，中间可能是路径，图片，文字的裁剪，最后restore
    //但目前没有搞明白具体的操作，所以先维持现状,只对Annotation处理，等碰到相关问题文档时再解决
//    if ( m_isAnnotation ) {
//        if ( graphics.isSave() ) {
//            graphics.restore();
//        }
//    }
    //fzz add end
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::writeText( FZZSVGUtil& graphics, FZZOFDTextObject* textObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix)
{
    
    if ( textObject == NULL ) {
        return;
    }
    
    vector<FZZOFDTextCode*> * textCodes = textObject->getTextCodeList();
    if ( textCodes == NULL ) {
        return;
    }
    
    fz_context * ctx = graphics.getContext();
    if ( ctx == NULL ) {
        return;
    }
    //--------test----------
//    if ( textObject->getID_long() == 94 ) {
//        int aa = textObject->getID_long();
//
//    }

    //----------------------
    
    
#ifdef OFDTESTLOG
    DLOG("writeText.......................1");
#endif
    
    
    string strboundary = textObject->getBoundary();
    double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
    if (!strboundary.empty()) {
        ST_Box_ToDouble(strboundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
    }
    
    FZZFontCache* defaultFont = FZZConst::g_FZSystemFontList.addDefaultFont();
    
    
    FZZFontCache* tempFont = getFont(textObject);
   
    FZZOFDWeight::TYPE weight = textObject->getWeight();
    bool isBlob = false;
    if ( weight >= FZZOFDWeight::TYPE::W_600 ) {
        isBlob = true;
    }
    
#ifdef OFDTESTLOG
    DLOG("writeText.......................2");
#endif
    
    double tempfontsize = textObject->getSize();
    vector<double> ctm;
    textObject->getCTM(ctm);
    double hscale = textObject->getHScale();
    
    FZZMatrix matrix;
    
#ifdef OFDTESTLOG
    DLOG("writeText.......................3");
#endif
    
    FZZMatrix ctmMatrix;
    if ( ctm.size() >= 6 ) {
        ctmMatrix.setAll(ctm[0], ctm[2], ctm[4], ctm[1], ctm[3], ctm[5]);
    }
    
    
    FZZMatrix baseMatrix;
    //double fontSize = textObject->getSize();
    TOFDColor * strokeColor = getStrokeColor(textObject->getStrokeColor(), NULL, drawParams);
    
#ifdef OFDTESTLOG
    DLOG("writeText.......................4");
#endif
    
    bool isShader = false;
//----------
    
    TOFDColor * fillColor = NULL;
    FZZOFDFillColor * ofdfillColor = textObject->getFillColor();
    if ( ofdfillColor != NULL ) {
        FZZOFDAxialShd * ofdAxialShd = ofdfillColor->getAxialShd();
        if ( ofdAxialShd != NULL ) {
            FZZMatrix matrix_shade;
//            if (hscale != 0) {
//                matrix_shade.postScale(hscale, 1);
//            }
//            matrix_shade.postScale(tempfontsize, tempfontsize);
//            if (!ctm.empty()) {
//                matrix_shade.postConcat(ctmMatrix);
//            }
//            if (!strboundary.empty()) {
//                matrix_shade.postTranslate(BoundaryBox_x, BoundaryBox_y);
//            }
            //matrix_shade.postConcat(parentMatrix);
            matrix_shade.postScale(m_ppm, m_ppm);
            
            fz_rect bbox = fz_make_rect(BoundaryBox_x, BoundaryBox_y, BoundaryBox_x+BoundaryBox_width, BoundaryBox_y+BoundaryBox_height);
            bbox = fz_transform_rect(bbox, matrix_shade.getMatrix());
            graphics.BeginGroup(bbox, NULL, 1, 1, FZ_BLEND_NORMAL, 1);
            isShader = true;
            //ShaderObject(graphics,ofdAxialShd,strboundary,BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
        } else {
            fillColor = getFillColor(ofdfillColor, NULL, drawParams);
        }
    } else {
        fillColor = getFillColor(ofdfillColor, NULL, drawParams);
    }
    
//    if ( ofdfillColor != NULL ) {
//        FZZOFDAxialShd * ofdAxialShd = ofdfillColor->getAxialShd();
//        if ( ofdAxialShd != NULL ) {
//            ShaderObject(graphics,ofdAxialShd,strboundary,BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
//        }
//    }
#ifdef OFDTESTLOG
    DLOG("writeText.......................5");
#endif
    if (fillColor == NULL) {
        
        fillColor = new TOFDColor();
        fillColor->r = 0;
        fillColor->g = 0;
        fillColor->b = 0;
    }
    
    int alpha = textObject->getAlpha();
  
    vector<FZZOFDCGTransform*> * tsfMap = textObject->getCGTransformList();
    
    double previousX = 0;
    double previousY = 0;
    vector<double> deltaX;
    vector<double> deltaY;
    vector<double> moveX;
    vector<double> moveY;
    string allText = "";
    
    
    
    vector<FZZOFDTextCode*>::const_iterator textCode_iter;
    for (textCode_iter = textCodes->begin(); textCode_iter != textCodes->end(); textCode_iter++) {
        FZZOFDTextCode* textCode = *textCode_iter;
        if ( textCode == NULL ) continue;
#ifdef OFDTESTLOG
    DLOG("writeText.......................51");
#endif
        string content = textCode->getContent();
        if ( content.empty() ) {
            continue;
        }

        content = FZZConst::replace_all(content, "\n", "");
        allText = allText + content;
        FZZString tempstcontent = content;
        int tempcontentlen = tempstcontent.length();
        
//        if ( allText.find(".....") == string::npos ) {
//            int bb ;
//            bb++;
//            return;
//        }
                              
#ifdef OFDTESTLOG
    DLOG("writeText.......................52");
#endif
        deltaX.clear();
        deltaY.clear();
        vector<string> array_X;
        textCode->getDeltaX(array_X);
        vector<string> array_Y;
        textCode->getDeltaY(array_Y);
        
        parseDelta(array_X,deltaX);
        parseDelta(array_Y,deltaY);
        
        double x = textCode->getX();
        double y = textCode->getY();
        if ( x == 0 && previousX != 0 ) {
            x = previousX;
        }
        if ( y == 0 && previousY != 0 ) {
            y = previousY;
        }
        
        int maxlen = deltaX.size() > deltaY.size() ? (int)deltaX.size() : (int)deltaY.size();
        if ( maxlen < tempcontentlen-1 ) {
            maxlen = tempcontentlen-1;
        }
        vector<double>::iterator delX_itr = deltaX.begin();
        vector<double>::iterator delY_itr = deltaY.begin();
#ifdef OFDTESTLOG
    DLOG("writeText.......................53");
#endif
        for ( int drawOffset = 0; drawOffset < maxlen+1; drawOffset++ ) {
            
            if ( drawOffset != 0 ) {
                if ( deltaX.size() > 0 && (drawOffset-1) < deltaX.size() ) {
                    x += *(delX_itr+drawOffset-1);//deltaX[drawOffset-1];
                } else if ( deltaX.size() > 0 && (drawOffset-1) >= deltaX.size() ) {
                    x += *(delX_itr+deltaX.size()-1);
                }
                if ( deltaY.size() > 0 && (drawOffset-1) < deltaY.size() ) {
                    y += *(delY_itr+drawOffset-1);//deltaY[drawOffset-1];
                } else if ( deltaY.size() > 0 && (drawOffset-1) >= deltaY.size() ) {
                    y += *(delY_itr+deltaY.size()-1);
                }
            }
            

            moveX.push_back(x);
            moveY.push_back(y);
            
        }
#ifdef OFDTESTLOG
    DLOG("writeText.......................54");
#endif
        if ( textCode->getX() != 0 ) {
            previousX = textCode->getX();
        }
        if ( textCode->getY() != 0 ) {
            previousY = textCode->getY();
        }
    }
    
#ifdef OFDTESTLOG
    DLOG("writeText.......................6");
#endif
    //DLOG("Text = %s",allText.c_str());
    FZZString stcontent = allText;
    int len = stcontent.length();
    //------test -----------
//    if ( allText.find("学时") != string::npos ) {
//        int aa;
//        aa++;
//        //return;
//    }
    //---------------------
    
    FZZOFDCGTransform* ct_CGTransForm = NULL;
    
    int offset = 0;
    vector<const FZZPath*> tbDrawChars;
    //vector<const fz_text*> tbDrawChars;
    string itemchar = "";
    int delchar = 0;
   
    if ( tsfMap != NULL && tsfMap->size() > 0 && (*tsfMap)[0] != NULL && (*tsfMap)[0]->getGlyphs() != NULL && getGlyphsSize((*tsfMap)[0]->getGlyphs()) > 0   ) {
       
        vector<FzGlyphID> gylphids;
        for ( int xx = 0; xx < tsfMap->size(); xx++ ) {
            ct_CGTransForm = (*tsfMap)[xx];
            if ( ct_CGTransForm != NULL ) {
                int CodePosition = ct_CGTransForm->getCodePosition();
                
                int codeCount = ct_CGTransForm->getCodeCount();
                int glyphCount = ct_CGTransForm->getGlyphCount();
                FZZOFDGlyphs * ofdglyphs = ct_CGTransForm->getGlyphs();
                
                if ( ofdglyphs == NULL ) {
                    continue;
                }
                
                vector<string> glyphs;
                ofdglyphs->getValue(glyphs);
                if ( glyphs.size() <= 0 ) {
                    continue;
                }
                
                if ( glyphCount == 0 ) {
                    glyphCount = (int)glyphs.size();
                }
                
                int cc = (gylphids.size() == 0) ? 0 : (int)gylphids.size();
                for ( ;cc < CodePosition-delchar; cc++) {
                    gylphids.push_back(0);
                }
                for ( int cc1 = 0;  cc1 < glyphCount; cc1++) {
                    if (cc1 > glyphs.size()-1) {
                       gylphids.push_back((FzGlyphID)strtol(glyphs[glyphs.size()-1].c_str(),NULL,10));
                       continue;
                   }
                   gylphids.push_back((FzGlyphID)strtol(glyphs[cc1].c_str(),NULL,10));
                }
                if ( codeCount >= 2 ) {
                    stcontent.Remove(CodePosition-delchar, codeCount-1);
                    len = stcontent.length();
                    delchar += codeCount-1;
                }
                
            }
        }
        
        int gi = (int)gylphids.size();
        for (; gi < len;  gi++) {
            gylphids.push_back(0);
        }
#ifdef OFDTESTLOG
    DLOG("writeText.......................7");
#endif
        vector<FzGlyphID>::iterator gid_itr;
        for ( gid_itr = gylphids.begin(); gid_itr != gylphids.end(); gid_itr++ ) {
            if ( *gid_itr == 0 ) {
                itemchar = stcontent[(int)(gid_itr-gylphids.begin())];

                FzUnichar unichar = FZZConst::Utf8ToUtf32LE(itemchar);

                const FZZPath* fontPath = NULL;
                //const fz_text * fontText = NULL;
                if ( unichar != 32 && tempFont != NULL ) {
                    FzGlyphID charGlyphid = tempFont->unicharToGlyph(unichar);
//                    fontText = tempFont->getText(ctx,charGlyphid);
//                    if ( (fontText == NULL || charGlyphid == 0) && defaultFont != NULL ) {
//                        charGlyphid = defaultFont->unicharToGlyph(unichar);
//                        fontText = defaultFont->getText(ctx,charGlyphid);
//                    }
                    fontPath = tempFont->getPath(charGlyphid);
                    if ( (fontPath == NULL || charGlyphid == 0) && defaultFont != NULL ) {
                        charGlyphid = defaultFont->unicharToGlyph(unichar);
                        fontPath = defaultFont->getPath(charGlyphid);
                    }
                }

                tbDrawChars.push_back(fontPath);
                //tbDrawChars.push_back(fontText);
            } else {
//                const fz_text* fontPath = NULL;
//                if ( tempFont != NULL ) {
//                    fontPath = tempFont->getText(ctx,*gid_itr);
//
//                    if ( fontPath == NULL  && defaultFont != NULL ) {
//                        fontPath = defaultFont->getText(ctx,*gid_itr);
//                    }
//                }
                const FZZPath* fontPath = NULL;
                if ( tempFont != NULL ) {
                    fontPath = tempFont->getPath(*gid_itr);

                    if ( fontPath == NULL  && defaultFont != NULL ) {
                        fontPath = defaultFont->getPath(*gid_itr);
                    }
                }
                tbDrawChars.push_back(fontPath);

                
            }
        }
       
    } else {
   
        while (offset < len) {
          
            itemchar = stcontent[offset];
            FzUnichar unichar = FZZConst::Utf8ToUtf32LE(itemchar);
            
//            const fz_text* fontPath = NULL;
//            if ( tempFont != NULL ) {
//                FzGlyphID charGlyphid = tempFont->unicharToGlyph(unichar);
//                fontPath = tempFont->getText(ctx,charGlyphid);
//                if ( (fontPath == NULL || charGlyphid == 0) && defaultFont != NULL) {
//                    charGlyphid = defaultFont->unicharToGlyph(unichar);
//                    fontPath = defaultFont->getText(ctx,charGlyphid);
//                }
//            }
            const FZZPath* fontPath = NULL;
            if ( unichar != 32 && tempFont != NULL ) {
                FzGlyphID charGlyphid = tempFont->unicharToGlyph(unichar);
                fontPath = tempFont->getPath(charGlyphid);
                if ( (fontPath == NULL || charGlyphid == 0) && defaultFont != NULL) {
                    charGlyphid = defaultFont->unicharToGlyph(unichar);
                    fontPath = defaultFont->getPath(charGlyphid);
                }
            }
            tbDrawChars.push_back(fontPath);
            offset++;
           
        }
      
    }
    
    int popcount = 0;
    FZZOFDClips * clips = textObject->getClips();
    if ( clips != NULL ) {
        FZZMatrix clipsmatrix;
        clipsmatrix.reset();
        if ( !ctm.empty() ) {

        }
        
        if (!strboundary.empty()) {
            clipsmatrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
        }

        clipsmatrix.postConcat(parentMatrix);


        clipsAble(graphics,clips,clipsmatrix,BoundaryBox_x,BoundaryBox_y,popcount);

    }
   
    vector<const FZZPath*>::const_iterator skpath_itr;
    vector<const FZZPath*>::const_iterator skpath_itr_begin = tbDrawChars.begin();
//    vector<const fz_text*>::const_iterator skpath_itr;
//    vector<const fz_text*>::const_iterator skpath_itr_begin = tbDrawChars.begin();
    vector<double>::iterator movex_itr = moveX.begin();
    vector<double>::iterator movey_itr = moveY.begin();
   
    if ( tbDrawChars.size() > 0 && moveX.size() > 0 && moveY.size() > 0 ){

        for (skpath_itr = tbDrawChars.begin(); skpath_itr != tbDrawChars.end(); skpath_itr++) {
            matrix.reset();
            //if ( tempfontsize <= 1 ) {
            if (hscale != 0) {
                matrix.postScale(hscale, 1);

            }
            matrix.postScale(tempfontsize, tempfontsize);
            //}

            matrix.postTranslate(*(movex_itr + (skpath_itr - skpath_itr_begin)), *(movey_itr + (skpath_itr - skpath_itr_begin)));
            if (!ctm.empty()) {

                matrix.postConcat(ctmMatrix);
            }

            if (!strboundary.empty()) {
                //matrix.postTranslate(*(movex_itr+(skpath_itr-tbDrawChars.begin())), *(movey_itr+(skpath_itr-tbDrawChars.begin())));
                matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
            }


            matrix.postConcat(parentMatrix);
            matrix.postScale(m_ppm, m_ppm);

            const FZZPath* path = (*skpath_itr);
            if (path != NULL) {

                FZZPath temppath(ctx,((FZZPath*)path)->getPath());
                temppath.transform(matrix.getMatrix());

                if (textObject->getStroke() || isBlob) {

                    fz_stroke_state* fillstroke = fz_new_stroke_state(ctx);
                    if ( fillstroke != NULL ) {
                        if (strokeColor == NULL) {
                            
                            strokeColor = new TOFDColor();
                            if ( fillColor != NULL ) {
                                strokeColor->r = fillColor->r;
                                strokeColor->g = fillColor->g;
                                strokeColor->b = fillColor->b;
                            } else {
                                strokeColor->r = 0;
                                strokeColor->g = 0;
                                strokeColor->b = 0;
                            }
                        }
                        float color[] = { strokeColor->r/255.0f, strokeColor->g/255.0f, strokeColor->b/255.0f };
                        double templinewidth = getLineWidth(textObject, drawParams);
//                        if (templinewidth < tempfontsize * 0.2 ) {
//                            templinewidth = tempfontsize * 0.2;
//                        }
                        fillstroke->linewidth = isBlob ? tempfontsize * 1.2 - tempfontsize : templinewidth;
                        fillstroke->miterlimit = fillstroke->linewidth*30;

                        if ( isShader ) {
                            if ( ofdfillColor != NULL ) {
                                FZZOFDAxialShd * ofdAxialShd = ofdfillColor->getAxialShd();
                                if ( ofdAxialShd != NULL ) {
                                    fz_rect clipbox = temppath.getBounds(fillstroke, MUPDF_fz_identity);
                                    graphics.ClipStrokePath(temppath.getPath(),fillstroke,MUPDF_fz_identity,clipbox);
                                    //popcount++;
                                    ShaderObject(graphics,ofdAxialShd,strboundary,BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
                                    graphics.POPClip();
                                }
                            }
                        }
                        else {
                            graphics.DrawStrokePath(temppath.getPath(), fillstroke, MUPDF_fz_identity, color, alpha/255.0f);
                        }




                        fz_drop_stroke_state(ctx,fillstroke);
                    }
                }

                if (textObject->getFill()) {
                    float color[] = { fillColor->r/255.0f, fillColor->g/255.0f, fillColor->b/255.0f };

                    if ( isShader ) {
                        if ( ofdfillColor != NULL ) {
                            FZZOFDAxialShd * ofdAxialShd = ofdfillColor->getAxialShd();
                            if ( ofdAxialShd != NULL ) {
                                fz_rect clipbox = temppath.getBounds();
                                graphics.ClipPath(temppath.getPath(),0,MUPDF_fz_identity,clipbox);
                                //popcount++;
                                ShaderObject(graphics,ofdAxialShd,strboundary,BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
                                graphics.POPClip();
                            }
                        }
                    }
                    else {
                        graphics.DrawFillPath(temppath.getPath(), 0, MUPDF_fz_identity, color, alpha/255.0f);
                    }




                }




            }
            else {
                //DLOG("writeText => path == NULL, words => %s",allText.c_str());
            }
            //DLOG("words => %s,%lf,%lf",allText.c_str(),matrix.getTranslateX(),matrix.getTranslateY());
        }

        tbDrawChars.clear();
    } //if (tbDrawChars.size() > 0)
#ifdef OFDTESTLOG
    DLOG("writeText.......................9");
#endif
    //fzz edit begin 2024-04-03
//    if ( !m_isAnnotation ) {
//        if ( clips != NULL ) {
//            graphics.restore();
//        }
//    }
    //fzz edit end 2024-04-03

    if ( clips != NULL && popcount > 0 ) {
    
        for ( int pop_i = 0; pop_i < popcount; pop_i++ ) {
            graphics.POPClip();
        }
        
    }
    
    if ( isShader ) {
       graphics.EndGroup();
    }

    if ( strokeColor != NULL ) {
        delete strokeColor;
        strokeColor = NULL;
    }
    if ( fillColor != NULL ) {
        delete fillColor;
        fillColor = NULL;
    }
    
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::writeImage( FZZSVGUtil& graphics, FZZOFDImageObject* imageObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix)
{
    if ( imageObject == NULL ) {
        return;
    }
    
    //-------------test ---------------
//    int aa = imageObject->getID()->getId();
//    if ( aa == 49) {
//        aa = imageObject->getID()->getId();
//        //FZZConst::writefile("/Users/fzz/work/cpp/ofd/tmp/output.png",image.getData(), image.getLen());
//    }
    //---------------------------------
    FZZBytes image = m_reader->getImage(imageObject);
    
    FZZImageUtil tempimage;
    if ( !tempimage.LoadImage(image) ) {
        return;
    }
    
    double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
    string strboundary = imageObject->getBoundary();
    if ( !strboundary.empty() ) {
        ST_Box_ToDouble(strboundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
    }
    
    FZZMatrix matrix;
    
    
    
//     ctm = a b c d e f
//     | a c e |
//     | b d f |
//     | 0 0 1 |
     
    vector<double> ctm;
    imageObject->getCTM(ctm);
    
    if ( ctm.size() >= 6 ) {
        FZZMatrix ctmMatrix;
        ctmMatrix.setAll(ctm[0], ctm[2], ctm[4], ctm[1], ctm[3], ctm[5]);
        matrix.postConcat(ctmMatrix);
    } else {
    }
  
    if (!strboundary.empty()) {
        matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
    }
    matrix.postConcat(parentMatrix);
    matrix.postScale(m_ppm,m_ppm);
    
    //bool ispopclips = false;
    int popcount = 0;
    FZZOFDClips * clips = imageObject->getClips();
    if ( clips != NULL ) {
        FZZMatrix clipsmatrix;
        clipsmatrix.reset();
        if ( ctm.size() >= 6  ) {
        }

        if (!strboundary.empty()) {
            clipsmatrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
        }
        clipsmatrix.postConcat(parentMatrix);
        clipsAble(graphics,clips,clipsmatrix,BoundaryBox_x, BoundaryBox_y,popcount);
    }
    
    

    graphics.DrawFillImage(tempimage.getImage(), matrix.getMatrix(), imageObject->getAlpha()/255.0f);
    
    if ( clips != NULL && popcount > 0 ) {
        for ( int pop_i = 0; pop_i < popcount; pop_i++ ) {
            graphics.POPClip();
        }
        
    }
    //fzz edit begin 2024-04-03
//    if ( !m_isAnnotation ) {
//        if ( clips != NULL ) {
//            graphics.restore();
//        }
//    }
    //fzz edit end 2024-04-03
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::writePath( FZZSVGUtil& graphics, FZZOFDPathObject* pathObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha,int preAlpha)
{
    if ( pathObject == NULL ) {
        return;
    }
    
    if ( !pathObject->getVisible() ) {
        return;
    }
    
    fz_context * ctx = graphics.getContext();
    if ( ctx == NULL ) {
        return;
    }
    
    //-------------test ---------------
//    string aa = pathObject->getID();
//    if ( aa == "325"    ) {
//        //aa = pathObject->getID()->getId();
//        //FZZConst::writefile("/Users/fzz/work/cpp/ofd/tmp/output.png",image.getData(), image.getLen());
//        int i = 0;
//        i++;
//    }
    //---------------------------------
    
    
    FZZOFDAbbreviatedData * abbreviatedData = pathObject->getAbbreviatedData();
    if ( abbreviatedData == NULL ) {
        return;
    }
    
    
    double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
    string strboundary = pathObject->getBoundary();
    if ( !strboundary.empty() ) {
        ST_Box_ToDouble(strboundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
    }
    
    vector<double> ctm;
    pathObject->getCTM(ctm);
    
    FZZMatrix matrix;
    if ( !ctm.empty() ) {
        FZZMatrix ctmMatrix;
        ctmMatrix.setAll(ctm[0], ctm[2], ctm[4], ctm[1], ctm[3], ctm[5]);
//        ctmMatrix.setAll(ctm->getDouble(0), ctm->getDouble(2), 0, ctm->getDouble(1), ctm->getDouble(3), 0, 0, 0, 1);
        matrix.postConcat(ctmMatrix);
    } else {

    }
  
    if (!strboundary.empty()) {
        matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
    }
    
    matrix.postConcat(parentMatrix);
    matrix.postScale(m_ppm,m_ppm);
    
    
    FZZPath path(ctx);
    //path.moveTo(0, 0);
    
    //DLOG("draw path begin");
    string strAdata = abbreviatedData->getValue();
    vector<string> aData;
    ST_Array_ToArray(strAdata,aData);
    
    string tempStr = "";
    string tempKey = "";
    for(int i = 0; i < aData.size(); i++) {
        tempStr = aData[i];
        if ( tempStr.empty() ) {
            continue;
        }
        if ( tempStr == "S" || tempStr == "M" || tempStr == "L" ||tempStr == "Q" || tempStr == "B" || tempStr == "A" || tempStr == "C" || tempStr == "a" ) {
            tempKey = tempStr;
            if ( tempKey == "C" ) {
                path.close();
                continue;
            }
        } else {
            if ( tempKey == "S" || tempKey == "M" ) {
                path.moveTo(strtod(aData[i].c_str(),NULL), strtod(aData[i+1].c_str(),NULL));
                //DLOG("M %lf,%lf",atof(aData.getString(i).c_str()), atof(aData.getString(i+1).c_str()));
                i+=1;
                continue;
            }
            if ( tempKey == "L" ) {
                path.lineTo(strtod(aData[i].c_str(),NULL), strtod(aData[i+1].c_str(),NULL));
                //DLOG("L %lf,%lf",atof(aData.getString(i).c_str()), atof(aData.getString(i+1).c_str()));
                i+=1;
                continue;
            }
            if ( tempKey == "Q" ) {
                path.quadTo(strtod(aData[i].c_str(),NULL), strtod(aData[i+1].c_str(),NULL),strtod(aData[i+2].c_str(),NULL), strtod(aData[i+3].c_str(),NULL));
                i+=3;
                continue;
            }
            if ( tempKey == "B" ) {
               
                path.cubicTo(strtod(aData[i].c_str(),NULL),strtod(aData[i+1].c_str(),NULL),strtod(aData[i+2].c_str(),NULL),strtod(aData[i+3].c_str(),NULL),strtod(aData[i+4].c_str(),NULL),strtod(aData[i+5].c_str(),NULL));
                i+=5;
                continue;
            }
            if ( tempKey == "A" ) {
                
                int tempi = 0;
                for (tempi = 0; tempi < 8; tempi++) {
                    string tempCommnd = aData[tempi+i];
                    if ( tempCommnd.empty() ) {
                        continue;
                    }
                    if ( tempCommnd == "S" || tempCommnd == "M" || tempCommnd == "L" ||tempCommnd == "Q" || tempCommnd == "B" || tempCommnd == "A" || tempCommnd == "C" || tempStr == "a" ) {
                        
                            break;
                        
                    }
                }
                
                if ( tempi == 7 ) {
                    path.arcTo(strtod(aData[i].c_str(),NULL), strtod(aData[i+1].c_str(),NULL),strtod(aData[i+2].c_str(),NULL),
                                   (int)strtol(aData[i+3].c_str(),NULL,10),(int)strtol(aData[i+4].c_str(),NULL,10),strtod(aData[i+5].c_str(),NULL),strtod(aData[i+6].c_str(),NULL));
                    i+=6;
                } else {
                   
                }
                continue;
            }
            if ( tempKey == "a" ) {
                int tempi = 0;
                for (tempi = 0; tempi < 8; tempi++) {
                    string tempCommnd = aData[tempi+i];
                    if ( tempCommnd.empty() ) {
                        continue;
                    }
                    if ( tempCommnd == "S" || tempCommnd == "M" || tempCommnd == "L" ||tempCommnd == "Q" || tempCommnd == "B" || tempCommnd == "A" || tempCommnd == "C" || tempStr == "a") {
                        
                            break;
                        
                    }
                }
                
                if ( tempi == 7 ) {
                    //画椭圆曲线，小写a 要加最后一个点
                    fz_point p = path.getCurrentPoint();
                    path.arcTo(strtod(aData[i].c_str(),NULL), strtod(aData[i+1].c_str(),NULL),strtod(aData[i+2].c_str(),NULL),
                                   (int)strtol(aData[i+3].c_str(),NULL,10),(int)strtol(aData[i+4].c_str(),NULL,10),strtod(aData[i+5].c_str(),NULL)+ p.x,strtod(aData[i+6].c_str(),NULL) + p.y);

                    i+=6;
                } else {
                   
                }
                continue;
            }

        }
    }
    //DLOG("draw path end..--------------------");
    
    FZZMatrix basematrix;
    path.transform(matrix.getMatrix());
    
    double linewidth = getLineWidth(pathObject, drawParams);
    if ( linewidth < 0.1 ) {
        linewidth = 0.1;
    }
    linewidth = linewidth * matrix.getScaleX();
    
    bool isShader = false;
    bool isPattern = false;
    FZZOFDStrokeColor * ofdStrokeColor = pathObject->getStrokeColor();
    if ( ofdStrokeColor != NULL ) {
        FZZOFDAxialShd * ofdAxialShd = ofdStrokeColor->getAxialShd();
        if (ofdAxialShd != NULL) {
            fz_rect bbox = path.getBounds();
            graphics.BeginGroup(bbox, NULL, 1, 1, FZ_BLEND_NORMAL, 1);
            isShader = true;
        }
    }

    FZZOFDFillColor * ofdfillColor = pathObject->getFillColor();
    if ( ofdfillColor != NULL ) {
        FZZOFDAxialShd * ofdAxialShd = ofdfillColor->getAxialShd();
        FZZOFDPattern * ofdPattern = ofdfillColor->getPattern();
        if (ofdAxialShd != NULL ) {
            if ( !isShader ) {
                fz_rect bbox = path.getBounds();
                graphics.BeginGroup(bbox, NULL, 1, 1, FZ_BLEND_NORMAL, 1);
                isShader = true;
            }
        }
        if ( ofdPattern != NULL ) {
            isPattern = true;
        }
    }
    
    int popcount = 0;
    FZZOFDClips * clips = pathObject->getClips();
    if ( clips != NULL ) {
        

        FZZMatrix clipsmatrix;
        clipsmatrix.reset();

        if ( !ctm.empty() ) {

        }
        
        if (!strboundary.empty()) {
            clipsmatrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
        }

        clipsmatrix.postConcat(parentMatrix);
        

        clipsAble(graphics,clips,clipsmatrix,BoundaryBox_x, BoundaryBox_y,popcount);
    }
    
    
    
    vector<double> DashArray;
    pathObject->getDashPattern(DashArray);
    double DashOffset = pathObject->getDashOffset();
    //FZ_LINECAP_BUTT
    fz_stroke_state* stroke = NULL;

    if ( DashArray.size() > 0 ) {
         stroke = fz_new_stroke_state_with_dash_len(ctx,(int)DashArray.size());
         FZZOFDLineCapType::TYPE captype = pathObject->getCap();
         switch(pathObject->getJoin()) {
             case FZZOFDLineJoinType::TYPE::TYPE_NONE:
             case FZZOFDLineJoinType::TYPE::TYPE_Miter:
                 stroke->linejoin = FZ_LINEJOIN_MITER;
                 break;
             case FZZOFDLineJoinType::TYPE::TYPE_Bevel:
                 stroke->linejoin = FZ_LINEJOIN_BEVEL;
                 break;
             case FZZOFDLineJoinType::TYPE::TYPE_Round:
                 stroke->linejoin = FZ_LINEJOIN_ROUND;
                 break;
             
         }
         switch(captype) {
             case FZZOFDLineCapType::TYPE::TYPE_Round:
                 //graphics.SetPaintStrokeCap(SkPaint::Cap::kRound_Cap);
                 stroke->start_cap = FZ_LINECAP_ROUND;
                 stroke->dash_cap = FZ_LINECAP_ROUND;
                 stroke->end_cap = FZ_LINECAP_ROUND;
                 
                 break;
             case FZZOFDLineCapType::TYPE::TYPE_Butt:
                 
                 break;
             case FZZOFDLineCapType::TYPE::TYPE_Square:
                 //graphics.SetPaintStrokeCap(SkPaint::Cap::kSquare_Cap);
                 stroke->start_cap = FZ_LINECAP_SQUARE;
                 stroke->dash_cap = FZ_LINECAP_SQUARE;
                 stroke->end_cap = FZ_LINECAP_SQUARE;
                 
                 break;
             default:
                 
                 break;
         }
         
         
         
         stroke->linewidth = linewidth;
         double miterlimit = pathObject->getMiterLimit();
         stroke->miterlimit = miterlimit == 0 ? stroke->linewidth*30 : miterlimit ;
         stroke->dash_phase = DashOffset;
         for (int i = 0; i < stroke->dash_len; i++) {
             //stroke->dash_list[i] = FZZCommonUtil::millimetersToPixel(DashArray->getDouble(i),72)* matrix.getScaleX();
             stroke->dash_list[i] = DashArray[i]* matrix.getScaleX();
         }
     
    } else {
         stroke = fz_new_stroke_state(ctx);
         if ( stroke != NULL ) {
             stroke->linewidth = linewidth;
             stroke->miterlimit = stroke->linewidth*30;
         }
    }
 
    float color[] = { 0.0, 0.0, 0.0 };
    //bool isShader = false;
    
    if ( pathObject->getFill() ) {
  
        //FZZOFDFillColor * ofdfillColor = pathObject->getFillColor();
    
        TOFDColor * fillColor = getFillColor(ofdfillColor, NULL, drawParams);
        if ( fillColor != NULL ) {

            color[0] = (float)(fillColor->r)/255.0;
            color[1] = (float)(fillColor->g)/255.0;
            color[2] = (float)(fillColor->b)/255.0;

        }
        
        float fzAlpha = 1.0f;
        //if ( !isShader ) {
        fzAlpha = (isUsePreAlpha ? preAlpha : 255)/255.0;
        
        if ( isPattern ) {
            //PatternObject 时
            color[0] = 1.0f;
            color[1] = 1.0f;
            color[2] = 1.0f;
            fzAlpha = 0.0f;
        }
        
        //float fzAlpha = 1.0f;
        if ( !isShader ) {
            //fzAlpha = (isUsePreAlpha ? preAlpha : 255)/255.0;
            graphics.DrawFillPath(path.getPath(), 0, MUPDF_fz_identity, color, fzAlpha);
            
            fz_stroke_state* fillstroke = fz_new_stroke_state(ctx);
            if ( fillstroke != NULL ) {
                fillstroke->linewidth = linewidth;
                fillstroke->miterlimit = fillstroke->linewidth*30;
                graphics.DrawStrokePath(path.getPath(), fillstroke, MUPDF_fz_identity, color, fzAlpha);
                fz_drop_stroke_state(ctx,fillstroke);
            }
        }
        if ( fillColor != NULL ) {
            delete fillColor;
        }
  
        
        if ( ofdfillColor != NULL ) {
            FZZOFDAxialShd * ofdAxialShd = ofdfillColor->getAxialShd();
            FZZOFDPattern * ofdPattern = ofdfillColor->getPattern();
            
            if (ofdAxialShd != NULL) {
                ShaderObject(graphics,ofdAxialShd,strboundary,BoundaryBox_x, BoundaryBox_y,BoundaryBox_width,BoundaryBox_height);
            } else if (ofdPattern != NULL) {
                PatternObject(graphics,ofdPattern,strboundary,BoundaryBox_x, BoundaryBox_y,BoundaryBox_width,BoundaryBox_height);
            }
            
        }
        
    } else {
        if ( pathObject->getStroke() ) {

            TOFDColor * strokeColor = getStrokeColor(ofdStrokeColor, NULL, drawParams);
            if ( strokeColor != NULL ) {
                color[0] = (float)(strokeColor->r)/255.0;
                color[1] = (float)(strokeColor->g)/255.0;
                color[2] = (float)(strokeColor->b)/255.0;
                
            }
            
            
            float fzAlpha = (isUsePreAlpha ? preAlpha : 255)/255.0;
            if ( !isShader ) {
                if ( stroke != NULL ) {
                    stroke->linewidth = linewidth;
                    stroke->miterlimit = stroke->linewidth*30;
                    graphics.DrawStrokePath(path.getPath(), stroke, MUPDF_fz_identity, color, fzAlpha);
                    
                }
            }
            
            if ( ofdStrokeColor != NULL ) {
                FZZOFDAxialShd * ofdAxialShd = ofdStrokeColor->getAxialShd();
                
                if (ofdAxialShd != NULL) {
                    ShaderObject(graphics,ofdAxialShd,strboundary,BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
                }
                
            }
            
            if ( strokeColor != NULL ) {
                delete strokeColor;
            }
            
            
            
        }
        
    }
    
    if ( clips != NULL && popcount > 0 ) {
        for ( int pop_i = 0; pop_i < popcount; pop_i++ ) {
            graphics.POPClip();
        }
        
    }
    
    if ( isShader ) {
        graphics.EndGroup();
    }
    
    if ( stroke != NULL ) {
        fz_drop_stroke_state(ctx,stroke);
        stroke = NULL;
    }
    //fzz edit begin 2024-04-03
//    if ( !m_isAnnotation ) {
//        if ( clips != NULL ) {
//            graphics.restore();
//        }
//    }
    //fzz edit begin 2024-04-03
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::writeComposite( FZZSVGUtil& graphics, FZZOFDCompositeObject* compositeObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isNoText)
{
    if ( compositeObject == NULL ) {
        return;
    }
    string strRefID = compositeObject->getResourceID();
    if (strRefID.empty()) return;
    
    int alpha = compositeObject->getAlpha();
    
    FZZOFDVectorG* vectorG = m_reader->getCompositeGraphicUnit(strRefID);
    if (vectorG == NULL) return;
    
    string strboundary = compositeObject->getBoundary();

    vector<double> ctm;
    compositeObject->getCTM(ctm);
    
    FZZMatrix matrix;
    if ( ctm.size() >= 6 ) {
        FZZMatrix ctmMatrix;
        ctmMatrix.setAll(ctm[0], ctm[2], ctm[4], ctm[1], ctm[3], ctm[5]);
        matrix.postConcat(ctmMatrix);
    } else {
//        if (boundary != NULL) {
//            matrix.postScale((m_ppm *boundary->getWidth()),(m_ppm *boundary->getHeight()));
//        }
    }
    
    if (!strboundary.empty()) {
        double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
        ST_Box_ToDouble(strboundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
        matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
        
    }
    
    matrix.postConcat(parentMatrix);

    writeContent(graphics, vectorG->getContent(), drawParams, matrix,alpha != 255,alpha,isNoText);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::addDrawParams(vector<FZZOFDDrawParam*>& drawParams, const string& refID)
{
    if ( !refID.empty() ) {
        FZZOFDDrawParam* ctDrawParam = m_reader->getDrawParam(refID);
        if (ctDrawParam != NULL) {
            drawParams.push_back(ctDrawParam);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::clipsAble(FZZSVGUtil& graphics,FZZOFDClips * clips,FZZMatrix& clipsmatrix,double preboundary_x, double preboundary_y,int & clipscount)
{
    //ispop = false;
    if ( clips == NULL ) {
        return;
    }
    bool TransFlag = clips->getTransFlag();
    
    if ( TransFlag ) {
        return;
    }
    //DLOG("TransFlag = %s",TransFlag ? "true" : "false");
    vector<FZZOFDClip*> * ctClips = clips->getClipList();
    if ( ctClips == NULL ) {
        return;
    }
    
    fz_context * ctx = graphics.getContext();
    if ( ctx == NULL ) {
        return;
    }
    
    FZZPath clippath(ctx);
    FZZPath clipStrokepath(ctx);
    
    //ispop = true;
    bool isclipStrokepath = false;
    double lineWidth = 0;
    bool isclippath = false;
    
    vector<FZZOFDClip*>::const_iterator CT_Clip_iter;
    for (CT_Clip_iter = ctClips->begin(); CT_Clip_iter != ctClips->end(); CT_Clip_iter++) {
        FZZOFDClip* ct_Clip = *CT_Clip_iter;
        if ( ct_Clip == NULL ) {
            continue;
        }
        vector<FZZOFDClipArea*>* areas = ct_Clip->getAreaList();
        if ( areas == NULL ) {
            continue;
        }
        vector<FZZOFDClipArea*>::const_iterator Area_iter;
        for (Area_iter = areas->begin(); Area_iter != areas->end(); Area_iter++) {
            FZZOFDClipArea* area = *Area_iter;
            if ( area == NULL ) {
                continue;
            }
            
            
            vector<double> areaCTM;
            area->getCTM(areaCTM);
            
            FZZOFDPath * ct_path = area->getPath();
            FZZOFDText * ct_text = area->getText();
            
            if (ct_path != NULL) {
                if ( ct_path->getStroke() ) {
                    clipStrokepath.reset();
                    
                    isclipStrokepath = true;
                    lineWidth = ct_path->getLineWidth();
                    if (lineWidth == 0) {
                        lineWidth = 0.3;
                    }
                    clipsPath(graphics,areaCTM,ct_path,clipsmatrix,preboundary_x, preboundary_y,TransFlag,clipStrokepath);
                    
                    fz_stroke_state* stroke = fz_new_stroke_state(ctx);
                    if ( stroke != NULL ) {
                        stroke->linewidth = lineWidth;
                        stroke->miterlimit = stroke->linewidth*30;
                        fz_rect clipbox = clipStrokepath.getBounds(stroke, MUPDF_fz_identity);
                        
                        if ( clipbox.x1-clipbox.x0 >= graphics.getWidth() && clipbox.y1 - clipbox.y0 >= graphics.getHeight() ) {
                            //ispop = false;
                        } else {
                            //ispop = true;
                            graphics.ClipStrokePath(clipStrokepath.getPath(),stroke,MUPDF_fz_identity,clipbox);
                            clipscount++;
                        }
                        
                        fz_drop_stroke_state(ctx,stroke);
                        
                    }
                }
                
                if ( ct_path->getFill() ) {
                    clippath.reset();
                    
                    isclippath = true;
                    clipsPath(graphics,areaCTM,ct_path,clipsmatrix,preboundary_x, preboundary_y,TransFlag,clippath);
                    
                    
                    fz_rect clipbox = clippath.getBounds();
                    if ( clipbox.x1-clipbox.x0 >= graphics.getWidth() && clipbox.y1 - clipbox.y0 >= graphics.getHeight() ) {
                        //ispop = false;
                    } else {
                        //ispop = true;
                        graphics.ClipPath(clippath.getPath(),0,MUPDF_fz_identity,clipbox);
                        clipscount++;
                    }
                }
                
                
            } else if (ct_text != NULL) {
                clipsText(graphics,areaCTM,ct_text,clipsmatrix,TransFlag);
                //clipscount++;
            }
            
        }
    }
    
//    if ( isclipStrokepath ) {
//        fz_stroke_state* stroke = fz_new_stroke_state(ctx);
//        if ( stroke != NULL ) {
//            stroke->linewidth = lineWidth;
//            stroke->miterlimit = stroke->linewidth*30;
//            fz_rect clipbox = clipStrokepath.getBounds(stroke, MUPDF_fz_identity);
//            
//            if ( clipbox.x1-clipbox.x0 >= graphics.getWidth() && clipbox.y1 - clipbox.y0 >= graphics.getHeight() ) {
//                ispop = false;
//            } else {
//                ispop = true;
//                graphics.ClipStrokePath(clipStrokepath.getPath(),stroke,MUPDF_fz_identity,clipbox);
//                
//            }
//            
//            fz_drop_stroke_state(ctx,stroke);
//            
//        }
//    }
//
//    if ( isclippath ) {
//        fz_rect clipbox = clippath.getBounds();
//        if ( clipbox.x1-clipbox.x0 >= graphics.getWidth() && clipbox.y1 - clipbox.y0 >= graphics.getHeight() ) {
//            ispop = false;
//        } else {
//            ispop = true;
//            graphics.ClipPath(clippath.getPath(),0,MUPDF_fz_identity,clipbox);
//            
//        }
//    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::clipsText(FZZSVGUtil& graphics,vector<double> & ctm,FZZOFDText * ct_text,FZZMatrix& clipsmatrix,bool TransFlag)
{
    if ( ct_text == NULL ) {
        return;
    }
 
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::clipsPath(FZZSVGUtil& graphics,vector<double> & ctm,FZZOFDPath * ct_path,FZZMatrix& matrix,double preboundary_x, double preboundary_y,bool TransFlag,/*out*/FZZPath& destpath)
{
    if ( ct_path == NULL ) {
        return;
    }
    
    FZZOFDAbbreviatedData * abbreviatedData = ct_path->getAbbreviatedData();
    if ( abbreviatedData == NULL ) {
        return;
    }
    double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
    string strboundary = ct_path->getBoundary();
    if ( !strboundary.empty() ) {
        ST_Box_ToDouble(strboundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
    }
    FZZMatrix clipmatrix;
    clipmatrix.reset();
    
    if ( !ctm.empty() ) {
        FZZMatrix ctmMatrix;
        ctmMatrix.setAll(ctm[0], ctm[2], ctm[4], ctm[1], ctm[3], ctm[5]);
        clipmatrix.postConcat(ctmMatrix);
    } else {

    }
  
    if (!strboundary.empty()) {
        clipmatrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
    }
    clipmatrix.postConcat(matrix);
    clipmatrix.postScale(m_ppm,m_ppm);

   
    //DLOG("draw path begin");
    string strAdata = abbreviatedData->getValue();
    vector<string> aData;
    ST_Array_ToArray(strAdata,aData);
    
    string tempStr = "";
    string tempKey = "";
    for(int i = 0; i < aData.size(); i++) {
        tempStr = aData[i];
        if ( tempStr.empty() ) {
            continue;
        }
        if ( tempStr == "S" || tempStr == "M" || tempStr == "L" ||tempStr == "Q" || tempStr == "B" || tempStr == "A" || tempStr == "C" || tempStr == "a") {
            tempKey = tempStr;
            if ( tempKey == "C" ) {
                destpath.close();
                continue;
            }
        } else {

            
            if ( tempKey == "S" || tempKey == "M" ) {
                destpath.moveTo((strtod(aData[i].c_str(),NULL)), (strtod(aData[i+1].c_str(),NULL)));
                i+=1;
                continue;
            }
            if ( tempKey == "L" ) {
                destpath.lineTo((strtod(aData[i].c_str(),NULL)), (strtod(aData[i+1].c_str(),NULL)));
                i+=1;
                continue;
            }
            if ( tempKey == "Q" ) {
                destpath.quadTo(strtod(aData[i].c_str(),NULL), strtod(aData[i+1].c_str(),NULL),strtod(aData[i+2].c_str(),NULL), strtod(aData[i+3].c_str(),NULL));
                i+=3;
                continue;
            }
            if ( tempKey == "B" ) {
              
                //path.moveTo(it->second[0], it->second[1]);
                //path.quadTo(it->second[2], it->second[3],it->second[4], it->second[5]);
                destpath.cubicTo(strtod(aData[i].c_str(),NULL),strtod(aData[i+1].c_str(),NULL),strtod(aData[i+2].c_str(),NULL),strtod(aData[i+3].c_str(),NULL),strtod(aData[i+4].c_str(),NULL),strtod(aData[i+5].c_str(),NULL));
                i+=5;
                continue;
            }
            if ( tempKey == "A" ) {
                int tempi = 0;
                for (tempi = 0; tempi < 8; tempi++) {
                    string tempCommnd = aData[tempi+i];
                    if ( tempCommnd.empty() ) {
                        continue;
                    }
                    if ( tempCommnd == "S" || tempCommnd == "M" || tempCommnd == "L" ||tempCommnd == "Q" || tempCommnd == "B" || tempCommnd == "A" || tempCommnd == "C" || tempStr == "a") {
                        
                            break;
                        
                    }
                }
                
                if ( tempi == 7 ) {
                    //画椭圆曲线
                    destpath.arcTo(strtod(aData[i].c_str(),NULL), strtod(aData[i+1].c_str(),NULL),strtod(aData[i+2].c_str(),NULL),
                                   (int)strtol(aData[i+3].c_str(),NULL,10),(int)strtol(aData[i+4].c_str(),NULL,10),strtod(aData[i+5].c_str(),NULL),strtod(aData[i+6].c_str(),NULL));

                    i+=6;
                } else {
                   
                }
                continue;
            }
            
            if ( tempKey == "a" ) {
                int tempi = 0;
                for (tempi = 0; tempi < 8; tempi++) {
                    string tempCommnd = aData[tempi+i];
                    if ( tempCommnd.empty() ) {
                        continue;
                    }
                    if ( tempCommnd == "S" || tempCommnd == "M" || tempCommnd == "L" ||tempCommnd == "Q" || tempCommnd == "B" || tempCommnd == "A" || tempCommnd == "C" || tempStr == "a") {
                        
                            break;
                        
                    }
                }
                
                if ( tempi == 7 ) {
                    //画椭圆曲线，小写a 要加最后一个点
                    fz_point p = destpath.getCurrentPoint();
                    destpath.arcTo(strtod(aData[i].c_str(),NULL), strtod(aData[i+1].c_str(),NULL),strtod(aData[i+2].c_str(),NULL),
                                   (int)strtol(aData[i+3].c_str(),NULL,10),(int)strtol(aData[i+4].c_str(),NULL,10),strtod(aData[i+5].c_str(),NULL)+ p.x,strtod(aData[i+6].c_str(),NULL) + p.y);

                    i+=6;
                } else {
                   
                }
                continue;
            }
            
        }
    }
    //DLOG("draw path end..--------------------");
    destpath.transform(clipmatrix.getMatrix());
    
}
//-----------------------------------------------------------------------------------------------------------------
double FZZOFDToSvg::getLineWidth(FZZOFDBaseGraphic* graphicUnit, vector<FZZOFDDrawParam*>* drawParams)
{
    if ( graphicUnit == NULL ) {
        return 0.1;
    }
    double lineWidth = graphicUnit->getLineWidth();
    if (lineWidth != 0) {
//        if ( lineWidth < 0.1 ) {
//            lineWidth = 0.1;
//        }
        return lineWidth;
    }
    if ( drawParams != NULL && drawParams->size() > 0 ) {
        lineWidth = (*drawParams)[drawParams->size()-1]->getLineWidth();
        if (lineWidth != 0) return lineWidth;
        return 0.1;
    }

    return 0.1;
   
}
//-----------------------------------------------------------------------------------------------------------------
TOFDColor* FZZOFDToSvg::getStrokeColor(FZZOFDColor* color, FZZOFDColor* defaultColor, vector<FZZOFDDrawParam*>* drawParams)
{
    FZZOFDColor * c = color;
    if ( c == NULL && drawParams != NULL) {
        vector<FZZOFDDrawParam*>::const_iterator itr;
        for (itr = drawParams->begin(); itr != drawParams->end(); itr++ ) {
            if ( *itr == NULL ) {
                continue;
            }
            c = (*itr)->getStrokeColor();
            if (c != NULL) {
                break;
            }
        }
    }
    if ( c == NULL )  {
        c = defaultColor;
    }
    return getColor(c);
}
//-----------------------------------------------------------------------------------------------------------------
TOFDColor* FZZOFDToSvg::getFillColor(FZZOFDColor* color, FZZOFDColor* defaultColor, vector<FZZOFDDrawParam*>* drawParams)
{
    FZZOFDColor * c = color;
    if ( c == NULL && drawParams != NULL ) {
        vector<FZZOFDDrawParam*>::const_iterator itr;
        for (itr = drawParams->begin(); itr != drawParams->end(); itr++ ) {
            if ( *itr == NULL ) {
                continue;
            }
            c = (*itr)->getFillColor();
            if (c != NULL) {
                break;
            }
        }
    }
    if ( c == NULL )  {
        c = defaultColor;
    }
    return getColor(c);
}
//-----------------------------------------------------------------------------------------------------------------
TOFDColor* FZZOFDToSvg::getColor(FZZOFDColor* ctColor)
{
    
    if ( ctColor == NULL ) {
        return NULL;
    }
   
    vector<string> array;
    ctColor->getValue(array);
    FZZOFDColorSpace::TYPE type = FZZOFDColorSpace::TYPE::TYPE_RGB;
    string refID = ctColor->getColorSpace();
    
    FZZOFDColorSpace* ctColorSpace = m_reader->getColorSpace(refID);
    if (ctColorSpace != NULL) {
        type = ctColorSpace->getType();
        string strIndex = ctColor->getIndex();
        if (array.size() == 0 && !strIndex.empty()) {
            FZZOFDPalette * ofdPalette = ctColorSpace->getPalette();
            if ( ofdPalette != NULL ) {
                ofdPalette->getColorByIndex(strIndex,array);
            }
        }
    }
    
    if (array.size() == 0) return NULL;
    int *color = new int[array.size()];
    if ( color == NULL ) {
        return NULL;
    }
    vector<string>::const_iterator itr;
    for (itr = array.begin(); itr != array.end(); itr++) {
        string s = *itr;
        int i = (int)(itr - array.begin());
        if (s[0] == '#') {
            s = FZZConst::replace_all(s, "#", "0x");
            color[i] = (int)strtol(s.c_str(),NULL,16);
        } else {
            if (s == "0.0")
                color[i] = 0;
            else
                color[i] = (int)strtol(s.c_str(),NULL,10);
        }
    }
    TOFDColor * tColor =  new TOFDColor();
    switch (type) {
        case FZZOFDColorSpace::TYPE::TYPE_GRAY:
            tColor->r = color[0];
            tColor->g = color[0];
            tColor->b = color[0];
            break;
        case FZZOFDColorSpace::TYPE::TYPE_CMYK:
            tColor->r = 255 * (100 - color[0]) * (100 - color[3]) / 10000;
            tColor->g = 255 * (100 - color[1]) * (100 - color[3]) / 10000;
            tColor->b = 255 * (100 - color[2]) * (100 - color[3]) / 10000;
            break;
        case FZZOFDColorSpace::TYPE::TYPE_RGB:
        default:
            tColor->r = color[0];
            tColor->g = color[1];
            tColor->b = color[2];
            break;
            
    }
    
    
    delete[] color;
    return tColor;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDToSvg::ShaderObject(FZZSVGUtil& graphics,FZZOFDAxialShd * ct_AxialShd,string & strBoundary,double BoundaryBox_x, double BoundaryBox_y, double BoundaryBox_width, double BoundaryBox_height)
{
    bool isTF = false;
    if ( ct_AxialShd == NULL ) {
        return isTF;
    }
    struct shade_stop stop_list[256];
    int stop_count = 0;
    
    FZZOFDExtend::TYPE extendType =  ct_AxialShd->getExtend();
    if ( extendType == FZZOFDExtend::TYPE::TYPE_3 ) {
        
        vector<FZZOFDSegment*> * segments = ct_AxialShd->getSegmentList();
        if ( segments->size() > 0 ) {
            double startpos_x = 0;
            double startpos_y = 0;
            double endpos_x = 0;
            double endpos_y = 0;
            ct_AxialShd->getStartPoint(startpos_x,startpos_y);
            ct_AxialShd->getEndPoint(endpos_x,endpos_y);
            
            FZZMatrix ShaderMatrix0;
            if (!strBoundary.empty()) {
                ShaderMatrix0.postTranslate(BoundaryBox_x, BoundaryBox_y);
            }
            ShaderMatrix0.postTranslate(startpos_x, startpos_y);
            ShaderMatrix0.postScale(m_ppm,m_ppm);

            FZZMatrix ShaderMatrix1;
            if (!strBoundary.empty()) {
                ShaderMatrix1.postTranslate(BoundaryBox_x, BoundaryBox_y);
            }
            ShaderMatrix1.postTranslate(endpos_x, endpos_y);
            ShaderMatrix1.postScale(m_ppm,m_ppm);
            
            stop_count = (int)segments->size();
            
            int pos_index = 0;
            vector<FZZOFDSegment*>::const_iterator segment_itr;
            for( segment_itr = segments->begin(); segment_itr != segments->end(); segment_itr++ ) {
                FZZOFDSegment * temp = *segment_itr;
                FZZOFDColor * tempOFDColor = temp->getColor();
                if ( temp != NULL && tempOFDColor != NULL ) {
                    stop_list[pos_index].offset = temp->getPosition(); //?
                    stop_list[pos_index].index = pos_index; //?
                    TOFDColor * tempColor = getColor(tempOFDColor);
                    if ( tempColor != NULL ) {
                        stop_list[pos_index].r = tempColor->r/255.0f;
                        stop_list[pos_index].g = tempColor->g/255.0f;
                        stop_list[pos_index].b = tempColor->b/255.0f;
                        stop_list[pos_index].a = 1.0f;
                        
                        pos_index++;

                        if ( tempColor != NULL ) {
                            delete tempColor;
                            tempColor = NULL;
                        }
                        isTF = true;
                    }
                }
            }//for
            
            if ( isTF ) {
                FZZImageUtil fziu(graphics.getContext());
                fz_shade * shade = fziu.newShade(FZ_LINEAR, 3, 3, ShaderMatrix0.getTranslateX(),ShaderMatrix0.getTranslateY(),0, ShaderMatrix1.getTranslateX(),ShaderMatrix1.getTranslateY(),0, stop_list, stop_count);
                
                if ( shade != NULL ) {
                    graphics.DrawFillShade(shade, MUPDF_fz_identity, 1, fz_default_color_params);
                    fziu.deleteShade(shade);
                }
            }
            
        }//if ( segments->size() > 0 )
    }//if ( extendType == FZZOFDExtend::TYPE::TYPE_3 )
    
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDToSvg::PatternObject(FZZSVGUtil& graphics,FZZOFDPattern * ct_Pattern,string & strboundary,double BoundaryBox_x, double BoundaryBox_y, double BoundaryBox_width, double BoundaryBox_height)
{
    bool isTF = false;
    if ( ct_Pattern == NULL ) {
        return isTF;
    }
    
    double patternWidth = ct_Pattern->getWidth();
    double patternHeight = ct_Pattern->getHeight();
    //ReflectMethod reflectMethod = ct_Pattern->getReflectMethod();
    fz_point pXY = {(float)(ct_Pattern->getXStep()),(float)(ct_Pattern->getYStep())};

    fz_rect view = {0,0,(float)patternWidth,(float)patternHeight};
    
    FZZOFDCellContent* cellConTent = ct_Pattern->getCellContent();
    if ( cellConTent != NULL ) {
        vector<FZZOFDPageBlockType* >* PageBlockTypeList = cellConTent->getPageBlockList();
        vector<FZZOFDPageBlockType*>::const_iterator itr;
        for( itr = PageBlockTypeList->begin(); itr != PageBlockTypeList->end(); itr++ ) {
            FZZOFDPageBlockType* pageBlockType_item = *itr;
            if (dynamic_cast<FZZOFDImageObject*>(pageBlockType_item) != NULL) {
                //目前不考虑多次循环情况，如存在，需要把裁剪和平铺提到循环外面，循环内只画图
                isTF = PatternImageObject(graphics,(FZZOFDImageObject *)pageBlockType_item,strboundary,BoundaryBox_x,BoundaryBox_y,BoundaryBox_width,BoundaryBox_height,view,pXY);
            } else if (dynamic_cast<FZZOFDTextObject*>(pageBlockType_item) != NULL) {
                isTF = PatternTextObject(graphics,(FZZOFDTextObject *)pageBlockType_item,strboundary,BoundaryBox_width,BoundaryBox_height,pXY.x ,pXY.y);
            }
        } //for( itr = PageBlockTypeList->begin(); itr != PageBlockTypeList->end(); itr++ )
                                                                                    
        
    }//if ( cellConTent != NULL )
    
    
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDToSvg::PatternImageObject(FZZSVGUtil& graphics,FZZOFDImageObject* imageObject,string & preboundary,double preboundary_x, double preboundary_y,double BoundaryBox_width, double BoundaryBox_height,fz_rect view,fz_point pXY)
{
    bool isTF = false;
    if ( imageObject == NULL || m_reader == NULL ) {
        return isTF;
    }
    
    fz_context * ctx = graphics.getContext();
    
    FZZBytes imageData = m_reader->getImage(imageObject);
    
    FZZImageUtil fzImageUtil_src(ctx);
    if ( !fzImageUtil_src.LoadImage(imageData.getData(), imageData.getLen()) ) {
        return isTF;
    }

    float widht = fzImageUtil_src.getWidth();
    float height = fzImageUtil_src.getHeight();
    fz_image * image = fzImageUtil_src.getImage();
    
    string boundary = imageObject->getBoundary();
    //int alpha = imageObject->getAlpha();
    fz_rect area = {(float)preboundary_x, (float)preboundary_y, (float)(preboundary_x+BoundaryBox_width), (float)(preboundary_y+BoundaryBox_height)};
    
    fz_rect pagebox = area;
    FZZMatrix pageMatrix;
    pageMatrix.postScale(m_ppm,m_ppm);
    pagebox = fz_transform_rect(pagebox, pageMatrix.getMatrix());
    
    FZZPath clippath(ctx);
    clippath.rectTo(pagebox.x0, pagebox.y0,pagebox.x1,pagebox.y1);
    graphics.ClipPath(clippath.getPath(),0,MUPDF_fz_identity,pagebox);
    
    
    
    FZZMatrix matrix;
    
    
    vector<double> ctm;
    imageObject->getCTM(ctm);
    if ( ctm.size() >= 6 ) {
        FZZMatrix ctmMatrix;
        ctmMatrix.setAll(ctm[0], ctm[2], ctm[4], ctm[1], ctm[3], ctm[5]);
        matrix.postConcat(ctmMatrix);
    }
    if (!boundary.empty()) {
        double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
        ST_Box_ToDouble(boundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
        matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
    }

  
    matrix.postScale(m_ppm,m_ppm);
    //不旋转，平铺
    //image 实际宽高
    fz_rect fzbounds = fz_make_rect(0, 0, widht/widht, height/widht);
    
    if ( pXY.x == 0 ) {
        pXY.x = (fzbounds.x1 - fzbounds.x0) * (view.x1 - view.x0);
    }
    if ( pXY.y == 0 ) {
        pXY.y = (fzbounds.y1 - fzbounds.y0) * (view.x1 - view.x0);;
    }
    graphics.BeginTile(area, view, pXY.x ,pXY.y, pageMatrix.getMatrix(), 0);
    
    fzbounds = fz_transform_rect(fzbounds, matrix.getMatrix());
    widht = fzbounds.x1 - fzbounds.x0;
    height = fzbounds.y1 - fzbounds.y0;
    matrix.setScale(widht, height);

    FZZMatrix drawctm;

    drawctm.postConcat(matrix);
    drawctm.setTranslate(0,0);
    graphics.DrawFillImage(image, drawctm.getMatrix(),
                                   1 //alpha/255.0f
                                   );
    
    graphics.EndTile();
    
    graphics.POPClip();

    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDToSvg::PatternTextObject(FZZSVGUtil& graphics,FZZOFDTextObject* textObject,string& boundary, double BoundaryBox_width, double BoundaryBox_height,double xStep,double yStep)
{
    FZZMatrix matrix;
    double moveX = 0;
    double moveY = 0;
    
    double textWidth = 0;
    double textHeight = 0;
    
    if ( textObject == NULL || boundary.empty() ) {
        return false;
    }
    
    string textbox = textObject->getBoundary();
    if ( !textbox.empty() ) {
        double textbox_x = 0; double textbox_y = 0; double textbox_width = 0; double textbox_height = 0;
        ST_Box_ToDouble(textbox, textbox_x, textbox_y, textbox_width, textbox_height);
        textWidth = textbox_width;
        textHeight = textbox_height;
    }
    
    while(true) {
        matrix.reset();
        matrix.postTranslate(moveX, moveY);
        writeText(graphics, textObject, NULL, matrix);
        
        moveX += xStep;
        if ( moveX > BoundaryBox_width ) {
            moveY += yStep;
            moveX = 0;
            if ( moveY > BoundaryBox_height ) {
                break;
            }
        }
    }
    
   
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
/*
bool FZZOFDToSvg::PatternImageObject(FZZImageUtil& graphics,FZZOFDImageObject* imageObject,string & preboundary,double preboundary_x, double preboundary_y,double BoundaryBox_width, double BoundaryBox_height)
{
    bool isTF = false;
    if ( imageObject == NULL || m_reader == NULL ) {
        return isTF;
    }
    
    fz_context * ctx = graphics.getContext();
    
    FZZBytes imageData = m_reader->getImage(imageObject);
    
    FZZImageUtil fzImageUtil_src(ctx);
    if ( !fzImageUtil_src.LoadImage(imageData.getData(), imageData.getLen()) ) {
        return isTF;
    }

    float widht = fzImageUtil_src.getWidth();
    float height = fzImageUtil_src.getHeight();
    fz_image * image = fzImageUtil_src.getImage();
    
    string boundary = imageObject->getBoundary();
    //int alpha = imageObject->getAlpha();
    
    fz_rect pagebox = fz_make_rect(preboundary_x, preboundary_y, preboundary_x+BoundaryBox_width, preboundary_y+BoundaryBox_height);
    FZZMatrix pageMatrix;
    pageMatrix.postScale(m_ppm,m_ppm);
    pagebox = fz_transform_rect(pagebox, pageMatrix.getMatrix());
    
    //graphics.BeginGroup(pagebox, NULL, 1, 0, FZ_BLEND_NORMAL, 1);
    
    FZZPath clippath(ctx);
    clippath.rectTo(pagebox.x0, pagebox.y0,pagebox.x1,pagebox.y1);
    graphics.ClipPath(clippath.getPath(),0,MUPDF_fz_identity,pagebox);
    
    FZZMatrix matrix;
    
    
    vector<double> ctm;
    imageObject->getCTM(ctm);
    if ( ctm.size() >= 6 ) {
        FZZMatrix ctmMatrix;
        ctmMatrix.setAll(ctm[0], ctm[2], ctm[4], ctm[1], ctm[3], ctm[5]);
        matrix.postConcat(ctmMatrix);
    }
    if (!boundary.empty()) {
        double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
        ST_Box_ToDouble(boundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
        matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
    }
//    if (!preboundary.empty()) {
//        matrix.postTranslate(preboundary_x, preboundary_y);
//    }
  
    matrix.postScale(m_ppm,m_ppm);
    //不旋转，平铺
    //image 实际宽高
    fz_rect fzbounds = fz_make_rect(0, 0, widht/widht, height/widht);
    fzbounds = fz_transform_rect(fzbounds, matrix.getMatrix());
    widht = fzbounds.x1 - fzbounds.x0;
    height = fzbounds.y1 - fzbounds.y0;
    matrix.setScale(widht, height);

    
    float endpos_x = pagebox.x1 + widht;
    float endpos_y = pagebox.y1 + height;
    
    FZZMatrix drawctm;
    for (int y = pagebox.y0; y < endpos_y; y += height) {
        for (int x = pagebox.x0; x < endpos_x; x += widht) {
            drawctm.reset();
            drawctm.postConcat(matrix);
            drawctm.setTranslate(x, y);
            graphics.DrawFillImage(image, drawctm.getMatrix(),
                                   1 //alpha/255.0f
                                   );
        }
    }
    
    graphics.POPClip();
    
    //graphics.EndGroup();
    
    return isTF;
}
 */
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache* FZZOFDToSvg::getFont(FZZOFDTextObject* textObject)
{
    FZZFontCache* retSKFont = NULL;

    string stRefID = textObject->getFont();
    if (stRefID.empty()) return retSKFont;
    
    FZZOFDFont* ctFont = m_reader->getFont(stRefID);
    if (ctFont == NULL) {
        retSKFont = FZZConst::g_FZSystemFontList.addDefaultFont();
        return retSKFont;
    }
    //fontFileLoc
    FZZOFDFontFile * ofdFontFile = ctFont->getFontFile();
    string fontFileLoc = "";
    if (ofdFontFile != NULL) {
        fontFileLoc = ofdFontFile->getValue();
    }
    string fontName = ctFont->getFontName();
    string familyName = ctFont->getFamilyName();
    if (!fontFileLoc.empty()) {
        
        if ( (retSKFont = m_FZTempFontList.getFont(fontName,familyName,fontFileLoc)) == NULL ) {
            FZZOFDResDir * resDir = m_reader->getResDir_default();
            if ( resDir != NULL ) {
                FZZBytes* fontData = resDir->getResFile(fontFileLoc);
    
                if ( fontData != NULL && fontData->getLen() > 10 ) {
                    retSKFont = m_FZTempFontList.addFontFile(fontName,familyName,fontFileLoc, fontData);
                    if ( retSKFont == NULL ) {
                        retSKFont = FZZConst::g_FZSystemFontList.addDefaultFont();
                    }
                } else {
                    retSKFont = FZZConst::g_FZSystemFontList.addDefaultFont();
                }
            }
        }
    } else {
        
        if ( !fontName.empty() ) {
            retSKFont = FZZConst::g_FZSystemFontList.findFont(fontName);
            if ( retSKFont == FZZConst::g_FZSystemFontList.addDefaultFont() ) {
                if ( !familyName.empty() ) {
                    retSKFont = FZZConst::g_FZSystemFontList.findFont(familyName);
                }
            }
        }
    }
    
    
    return retSKFont;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::parseDelta(vector<string> & array,vector<double> & arr)
{
    if ( array.size() <= 0 ) {
        return;
    }
    vector<string>::iterator arr_itr;
    for ( arr_itr = array.begin(); arr_itr != array.end(); arr_itr++ ) {
        double delta = strtod((*arr_itr).c_str(),NULL);
        arr.push_back(delta);
    }
}
//-----------------------------------------------------------------------------------------------------------------
size_t FZZOFDToSvg::getGlyphsSize(FZZOFDGlyphs * ofdglyphs)
{
    if ( ofdglyphs == NULL ) return 0;
    vector<string> glyphs;
    ofdglyphs->getValue(glyphs);
    return glyphs.size();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToSvg::test()
{
   
}
//-----------------------------------------------------------------------------------------------------------------
