//
//  Created by zizheng fan on 2024/07/30.
//
#include "ofd/FZZOFDConst.h"
#include "converter/topdf/FZZOFDToPDF.h"
#include "converter/image/FZZOFDToImage.h"
#include "converter/utils/FZZCommonUtil.h"
#include "basic/FZZString.h"
#include "font/FZZGenFont.h"

#define OFD_CLIPSCALE 2
#define SHADERSCALE 4
//Millimeter to pixel
//72/25.4 = 2.83464667
#define OFD_MILLIMETERSTOPIXEL 2.835

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDToPDF**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDToPDF::FZZOFDToPDF() : m_reader(NULL),m_isNoStamp(false),m_isGenFont(false),m_FZTempFontList(NULL),m_CurrPage_WidthPixel(0),m_CurrPage_HeightPixel(0),m_PDFPageMaxIndex(0),m_CTX(NULL),m_Doc(NULL),m_IsEncrypt(false),m_Password("")
{
    //DLOG("FZZOFDToPDF()");
    FZZConst::addClassCount("FZZOFDToPDF");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDToPDF::FZZOFDToPDF(FZZOFD * reader) : FZZOFDToPDF()
{
    if ( reader != NULL ) {
        m_reader = reader;
        m_pages = reader->getPageInfoList();
        m_CTX = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
        if ( m_CTX == NULL ) return;
        m_Doc = pdf_create_document(m_CTX);
        
        m_FZTempFontList = new FZZTempFontList();
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDToPDF::~FZZOFDToPDF()
{
    //DLOG("~FZZOFDToPDF()");
    FZZConst::delClassCount("FZZOFDToPDF");
    
    m_pages = NULL;
    m_reader = NULL;
    
    
    map<string,FZZGenFont*>::iterator it;
    for (it = m_genFont.begin(); it != m_genFont.end(); it++) {
        if ( it->second != NULL ) {
            delete (it->second);
        }
    }
    m_genFont.clear();
    
    
//    map<string,FZZBytes*>::iterator pdffontit;
//    for (pdffontit = m_PDFFontData.begin(); pdffontit != m_PDFFontData.end(); pdffontit++) {
//        if ( pdffontit->second != NULL ) {
//            delete (pdffontit->second);
//        }
//    }
//    m_PDFFontData.clear();
    
    if ( m_Doc != NULL ) {
        pdf_drop_document(m_CTX,m_Doc);
        m_Doc = NULL;
    }
    
    if ( m_FZTempFontList != NULL ) {
        delete m_FZTempFontList;
        m_FZTempFontList = NULL;
    }
    
    if ( m_CTX != NULL ) {
        fz_flush_warnings(m_CTX);
        fz_drop_context(m_CTX);
        m_CTX = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFDToPDF::getOFDPageCount()
{
    return m_pages == NULL ? 0 : (int)m_pages->size();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::generatePDFFont()
{
    map<string,FZZGenFont*>::iterator it;
    for (it = m_genFont.begin(); it != m_genFont.end(); it++) {
        if ( it->second != NULL ) {
            FZZGenFont* genFont = it->second;
            FZZBytes newFontData;
            if ( genFont->genNewFont(newFontData) ) {
                m_FZTempFontList->addFontFile(m_CTX,it->first, "", "", &newFontData);
//                    string aa = "/Users/fzz/work/cpp/ofd/tmp/imageconverter/";
//                    static int bb = 0;
//                    bb++;
//                    aa = aa + FZZConst::fmt(bb);
//                    aa += ".ttf";
//                    FZZConst::writefile(aa, newFontData->getData(), newFontData->getLen());
            }
            
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZOFDToPDF::generatePDF()
{
    FZZBytes ret;
    
    if ( m_CTX == NULL || m_Doc == NULL ) {
        return ret;
    }
    
    pdf_write_options opts = {
    0, /* do_incremental */
    0, /* do_pretty */
    0, /* do_ascii */
    0, /* do_compress */
    0, /* do_compress_images */
    0, /* do_compress_fonts */
    0, /* do_decompress */
    0, /* do_garbage */
    0, /* do_linear */
    0, /* do_clean */
    0, /* do_sanitize */
    0, /* do_appearance */
    0, /* do_encrypt  是否加密pdf文件*/
    0, /* dont_regenerate_id */
    ~0, /* permissions */
    "", /* opwd_utf8[128] 文档密码*/
    "", /* upwd_utf8[128] 文档密码*/
    0 /* do_snapshot */
    };
    
    opts.do_compress = 1;
    opts.do_compress_images = 1;
    opts.do_compress_fonts = 1;
    
    //fzz crypt begin
    if ( !m_Password.empty() ) {
        opts.do_encrypt = PDF_ENCRYPT_AES_128;//PDF_ENCRYPT_RC4_40 PDF_ENCRYPT_RC4_128 PDF_ENCRYPT_AES_128 PDF_ENCRYPT_AES_256
        fz_strlcpy(opts.upwd_utf8, m_Password.c_str(), nelen(opts.upwd_utf8));
        fz_strlcpy(opts.opwd_utf8, m_Password.c_str(), nelen(opts.opwd_utf8));
    } else {
        if ( m_IsEncrypt ) {
            opts.do_encrypt = PDF_ENCRYPT_AES_128;//PDF_ENCRYPT_RC4_40 PDF_ENCRYPT_RC4_128 PDF_ENCRYPT_AES_128 PDF_ENCRYPT_AES_256
        }
    }
    //fzz crypt end
    
    fz_buffer * buf = fz_new_buffer(m_CTX, 0);
    
    if ( buf != NULL ) {
        fz_output * output = fz_new_output_with_buffer(m_CTX, buf);
        if ( output != NULL ) {
            pdf_write_document(m_CTX, m_Doc, output, &opts);
            
            ret.setData(buf->data, buf->len);
            
            fz_close_output(m_CTX, output);
            fz_drop_output(m_CTX, output);
        }
        fz_drop_buffer(m_CTX, buf);
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDToPDF::makePage(int pageIndex)
{
    if ( m_pages == NULL || m_CTX == NULL || m_FZTempFontList == NULL ) return false;
    if (pageIndex < 0 || (m_pages != NULL && pageIndex >= m_pages->size())) {
        return false;
    }
    
    TPageInfo* pageInfo = *(m_pages->begin() + pageIndex);
    if ( pageInfo == NULL ) {
        DLOG("pageInfo == NULL, pageIndex = %d",pageIndex);
        return false;
    }
    
    m_CurrPage_WidthPixel = FZZCommonUtil::millimetersToPixel(pageInfo->pageSize_width, 72);
    m_CurrPage_HeightPixel = FZZCommonUtil::millimetersToPixel(pageInfo->pageSize_height,72);
    
    FZZMatrix matrix;
    fz_try(m_CTX) {
    if ( !m_isGenFont ) {
        fz_buffer *contents = NULL;
        pdf_obj * resources = NULL;
        fz_device * dev = NULL;
        pdf_obj * page = NULL;
        do {
        
            fz_rect mediabox = { (float)FZZCommonUtil::millimetersToPixel(pageInfo->pageSize_x, 72),
                (float)FZZCommonUtil::millimetersToPixel(pageInfo->pageSize_y, 72), (float)m_CurrPage_WidthPixel, (float)m_CurrPage_HeightPixel };
            int rotate = 0;
            
            dev = pdf_page_write(m_CTX, m_Doc,mediabox, &resources, &contents);
            if ( dev == NULL ) {
                break;
            }
            page = pdf_add_page(m_CTX, m_Doc, mediabox, rotate, resources, contents);
            if ( page == NULL ) {
                break;
            }
            pdf_insert_page(m_CTX, m_Doc, -1, page);
            
            //wtitePageBackground(dev,m_reader,OFDPageIndex);
            writePage(dev,pageInfo,matrix);
            
            m_PDFPageMaxIndex++;
        
        }while(false);
        
        

        if ( page != NULL ) {
            pdf_drop_obj(m_CTX, page);
            page = NULL;
        }
        if ( dev != NULL ) {
            fz_close_device(m_CTX, dev);
            fz_drop_device(m_CTX, dev);
            dev = NULL;
        }
        if ( contents != NULL ) {
            fz_drop_buffer(m_CTX, contents);
            contents = NULL;
        }
        if ( resources != NULL ) {
            pdf_drop_obj(m_CTX, resources);
            resources = NULL;
        }
        
    } else {
        writePage(NULL,pageInfo,matrix);
    }
    } fz_catch(m_CTX) {
        DLOG("gen svg error : %s",m_CTX->error.message);
    }
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::writePage(fz_device * dev, TPageInfo* pageInfo,FZZMatrix & matrix)
{
    if ( m_reader == NULL || pageInfo == NULL) {
        return;
    }
    
    
    vector<FZZOFDLayer *>* layerList = &(pageInfo->layerList);
    if ( layerList != NULL ) {
        vector<FZZOFDLayer*>::const_iterator CT_Layer_iter;
        for (CT_Layer_iter = layerList->begin(); CT_Layer_iter != layerList->end(); CT_Layer_iter++) {
            writeContent(dev, *CT_Layer_iter, NULL,matrix,false,0xff,false);
        }
    }

    if ( !m_isNoStamp && !m_isGenFont ) {
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
                                    if ( !m_isGenFont ) {
                                        writeStampAnnot(dev, *StampAnnotEntity_iter, stampAnnot);
                                    }
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
                            
                           
                            //fz_rect pbox = { 0,0,(float)graphics.getWidth(),(float)graphics.getHeight() };
                            
                            //graphics.BeginGroup(pbox, NULL, 1, 0, FZ_BLEND_MULTIPLY, 1);
                            
                            FZZMatrix tempmatrix;
                         
                            writeContent(dev, tempAnnot->getAppearance(), NULL,tempmatrix,false,0xff,false);
                            
                            //graphics.EndGroup();
                            
                        }
                    }
                } //if ( Annots != NULL )
            }
        }//for (AnnotionEntity_iter = annotationDirList->begin(); AnnotionEntity_iter != annotationDirList->end(); AnnotionEntity_iter++)
    }//if ( annotationDirList != NULL )
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::writeStampAnnot( fz_device * dev, FZZStampAnnotEntity* stampAnnotVo, FZZOFDStampAnnot* stampAnnot)
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
            FZZOFDToImage imagemaker(&reader,OFD_MILLIMETERSTOPIXEL*2);
            if ( imagemaker.pageSize() > 0 ) {
                imageData = imagemaker.makePage(0, "PNG");
            }
        }
    }
    
    fz_context * ctx = m_CTX;
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
    matrix.postScale(OFD_MILLIMETERSTOPIXEL,OFD_MILLIMETERSTOPIXEL);
    //matrix.postScale(stampImage.getWidth(),stampImage.getHeight());
    fz_rect pbox = {0,0,0,0};
    if ( !strBoundaryBox.empty() ) {
        pbox = {(float)BoundaryBox_x, (float)BoundaryBox_y, (float)BoundaryBox_x+(float)BoundaryBox_width, (float)BoundaryBox_y+(float)BoundaryBox_height};
    } else {
        pbox = {0,0,(float)stampImage.getWidth(),(float)stampImage.getHeight()};
    }
    
    FZZMatrix boxmatrix;
    boxmatrix.postScale(OFD_MILLIMETERSTOPIXEL,OFD_MILLIMETERSTOPIXEL);
    pbox = fz_transform_rect(pbox, boxmatrix.getMatrix());
    //下面四种目前都对，感觉第三种是最佳方法
    //graphics.BeginGroup(pbox, NULL, 1, 1, FZ_BLEND_MULTIPLY, 1);
    //graphics.BeginGroup(pbox, NULL, 0, 1, FZ_BLEND_MULTIPLY, 1);
    //graphics.BeginGroup(pbox, NULL, 1, 0, FZ_BLEND_MULTIPLY, 1);
    //graphics.BeginGroup(pbox, NULL, 0, 0, FZ_BLEND_MULTIPLY, 1);
    
    //fz_save_state(dev);
    //fz_begin_group( m_CTX, dev, pbox, NULL, 1, 1, FZ_BLEND_NORMAL, 1);
    //fz_begin_group( m_CTX, dev, pbox, NULL, 1, 0, FZ_BLEND_MULTIPLY, 1);
    
    if ( !strclipBox.empty() ) {
        
        FZZMatrix clipmatrix;
        
        clipmatrix.reset();
        if ( !strBoundaryBox.empty() ) {
            clipmatrix.postScale(BoundaryBox_width/stampImage.getWidth(), BoundaryBox_height/stampImage.getHeight());
            clipmatrix.postTranslate(BoundaryBox_x+clip_x, BoundaryBox_y+clip_y);
        } else {
            clipmatrix.postTranslate(clip_x, clip_y);
        }
        clipmatrix.postScale(OFD_MILLIMETERSTOPIXEL,OFD_MILLIMETERSTOPIXEL);
        
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
        
        
        fz_clip_path( m_CTX, dev, clippath.getPath(),0,MUPDF_fz_identity,cliprect);
    }

    fz_fill_image( m_CTX, dev, fzimage, matrix.getMatrix(), 0.75,fz_default_color_params);
    
  
   
    if ( !strclipBox.empty() ) {
        fz_pop_clip( m_CTX, dev);
    }
    //fz_end_group( m_CTX, dev);
    //fz_restore_state(dev);
   
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::writeContent( fz_device * dev, FZZOFDPageBlock* pageBlock, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha,int preAlpha,bool isNoText)
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
        //parentMatrix.postTranslate(OFD_MILLIMETERSTOPIXEL *BoundaryBox->getTopLeftX(), OFD_MILLIMETERSTOPIXEL *BoundaryBox->getTopLeftY());
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
            
            if ( m_isGenFont ) {
                writeText_genFontFile(dev, textObj, &tempdrawParams,parentMatrix);
            } else {
                writeText(dev, textObj, &tempdrawParams,parentMatrix);
            }
            
            
            
            continue;
        } else if ((imageObj = dynamic_cast<FZZOFDImageObject*>(*PageBlockType_iter)) != NULL) {
            addDrawParams(tempdrawParams, imageObj->getDrawParam_String()) ;
            if ( !m_isGenFont ) {
                writeImage(dev, imageObj, &tempdrawParams,parentMatrix);
            }
            continue;
        } else if ((pathObj = dynamic_cast<FZZOFDPathObject*>(*PageBlockType_iter)) != NULL) {
            addDrawParams(tempdrawParams, pathObj->getDrawParam_String()) ;
            if ( m_isGenFont ) {
                writePath_genFontFile(dev, pathObj, &tempdrawParams,parentMatrix,isUsePreAlpha,preAlpha);
            } else {
                writePath(dev, pathObj, &tempdrawParams,parentMatrix,isUsePreAlpha,preAlpha);
            }
            continue;
//            cc++;
//            if ( cc == 5) {
//                break;
//            }
        } else if ((compositeObj = dynamic_cast<FZZOFDCompositeObject*>(*PageBlockType_iter)) != NULL) {
            addDrawParams(tempdrawParams, compositeObj->getDrawParam_String()) ;
            writeComposite(dev, compositeObj, &tempdrawParams,parentMatrix,isNoText);
            continue;
        } else if ((layerObj = dynamic_cast<FZZOFDLayer*>(*PageBlockType_iter)) != NULL) {
            
            addDrawParams(tempdrawParams, layerObj->getDrawParam_String()) ;
            writeContent(dev, layerObj, &tempdrawParams,parentMatrix,isUsePreAlpha, preAlpha, isNoText);
            continue;
        } else if ((pageBlockObj = dynamic_cast<FZZOFDPageBlock*>(*PageBlockType_iter)) != NULL) {
            
            
            writeContent(dev, pageBlockObj, &tempdrawParams,parentMatrix,isUsePreAlpha, preAlpha, isNoText);
            continue;
        }
        
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::writeText_genFontFile( fz_device * dev, FZZOFDTextObject* textObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix)
{
    if ( textObject == NULL ) {
        return;
    }
    
    vector<FZZOFDTextCode*> * textCodes = textObject->getTextCodeList();
    if ( textCodes == NULL ) {
        return;
    }
    
    string strfontkey;
    bool isGen = false;
    FZZFontCache* tempFont = getFont(textObject,isGen,strfontkey);
    if ( !isGen ) {
        return;
    }
    
    FZZGenFont * genFont = NULL;
    if ( tempFont != NULL ) {
        const FZZBytes* fontdata = tempFont->getFontData();
        
        map<string,FZZGenFont*>::iterator it = m_genFont.find(strfontkey);
        
        if (it != m_genFont.end()) {
            genFont =  it->second;
            if ( genFont == NULL ) {
                genFont = new FZZGenFont();
                m_genFont[strfontkey] = genFont;
                genFont->setOldFont(*((FZZBytes*)fontdata));
            }
        } else {
            genFont = new FZZGenFont();
            if ( genFont != NULL ) {
                auto isExitPari = m_genFont.insert(pair<string,FZZGenFont*>(strfontkey ,genFont));
                if ( !isExitPari.second ) {
                    delete genFont;
                    genFont = isExitPari.first->second;
                    
                }
                if ( genFont != NULL ) {
                    genFont->setOldFont(*((FZZBytes*)fontdata));
                }
            }
        }
        

    }
    
    FZZGenFont * default_genFont = NULL;
    FZZFontCache* defaultFont = FZZConst::g_FZSystemFontList.addDefaultFont();
    if ( defaultFont != NULL ) {
        const FZZBytes* defaultfontdata = defaultFont->getFontData();
    
        map<string,FZZGenFont*>::iterator it = m_genFont.find(FZZConst::g_FZFontConfig.getDefaultFontName());
        if (it != m_genFont.end()) {
            default_genFont =  it->second;
            if ( default_genFont == NULL ) {
                default_genFont = new FZZGenFont();
                m_genFont[FZZConst::g_FZFontConfig.getDefaultFontName()] = default_genFont;
                default_genFont->setOldFont(*((FZZBytes*)defaultfontdata));
            }
        } else {
            default_genFont = new FZZGenFont();
            if ( default_genFont != NULL ) {
                auto isExitPari = m_genFont.insert(pair<string,FZZGenFont*>(FZZConst::g_FZFontConfig.getDefaultFontName() ,default_genFont));
                if ( !isExitPari.second ) {
                    delete default_genFont;
                    default_genFont = isExitPari.first->second;
                    
                }
                if ( default_genFont != NULL ) {
                    default_genFont->setOldFont(*((FZZBytes*)defaultfontdata));
                }
            }
        }
    }
    
    vector<FZZOFDCGTransform*> * tsfMap = textObject->getCGTransformList();
        
    string allText = "";
        
    vector<FZZOFDTextCode*>::const_iterator textCode_iter;
    for (textCode_iter = textCodes->begin(); textCode_iter != textCodes->end(); textCode_iter++) {
        FZZOFDTextCode* textCode = *textCode_iter;
            if ( textCode == NULL ) continue;
            string content = textCode->getContent();
            if ( content.empty() ) {
                continue;
            }

            content = FZZConst::replace_all(content, "\n", "");
            allText = allText + content;
    }
        
        //DLOG("Text = %s",allText.c_str());
    FZZString stcontent = allText;
    int len = stcontent.length();
        
//        if ( allText == "aa" ) {
//            int aa;
//            aa++;
//        }
        
    FZZOFDCGTransform* ct_CGTransForm = NULL;
        // The offset of the character encoding currently being processed in this character encoding
    int offset = 0;
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
                
                size_t cc = (gylphids.size() == 0) ? 0 : gylphids.size();
                for ( ;cc < CodePosition-delchar; cc++) {
                    gylphids.push_back(0);
                }
                for ( int cc1 = 0;  cc1 < glyphCount; cc1++) {
                    if (cc1 > glyphs.size()-1) {
                       gylphids.push_back((int)strtol(glyphs[glyphs.size()-1].c_str(),NULL,10));
                       continue;
                   }
                   gylphids.push_back((int)strtol(glyphs[cc1].c_str(),NULL,10));
                }
                if ( codeCount >= 2 ) {
                    stcontent.Remove(CodePosition-delchar, codeCount-1);
                    len = stcontent.length();
                    delchar += codeCount-1;
                }
                
            }
        }
        
        size_t gi = gylphids.size();
        for (; gi < len;  gi++) {
            gylphids.push_back(0);
        }
       
        vector<FzGlyphID>::iterator gid_itr;
        for ( gid_itr = gylphids.begin(); gid_itr != gylphids.end(); gid_itr++ ) {
            if ( *gid_itr == 0 ) {
//                itemchar = stcontent[(int)(gid_itr-gylphids.begin())];
//                if ( genFont != NULL ) {
//                    genFont->addData(itemchar);
//                } else {
//                    default_genFont->addData(itemchar);
//                }
                itemchar = stcontent[(int)(gid_itr-gylphids.begin())];
                FzUnichar unichar = FZZConst::Utf8ToUtf32LE(itemchar);
                
                if ( unichar !=32 && tempFont != NULL ) {
                    FzGlyphID charGlyphid = tempFont->unicharToGlyph(unichar);
                   
                    if ( charGlyphid == 0 && defaultFont != NULL) {
                        charGlyphid = defaultFont->unicharToGlyph(unichar);
                        default_genFont->addData(itemchar);
                    } else {
                        if ( genFont != NULL ) {
                            genFont->addData(itemchar);
                        } else {
                            default_genFont->addData(itemchar);
                        }
                    }
                }
            } else {
          
               
                if ( tempFont != NULL ) {
                    FzUnichar charforGlyph = tempFont->GlyphToUnichar(*gid_itr);
                    

                    
                    if ( genFont != NULL ) {
                        genFont->addData(charforGlyph);
                    } else {
                        default_genFont->addData(charforGlyph);
                    }
                    
                }
                
             
                
            }
        }
       
    } else {
   
        while (offset < len) {
    
            itemchar = stcontent[offset];
            FzUnichar unichar = FZZConst::Utf8ToUtf32LE(itemchar);
            
            if ( unichar !=32 && tempFont != NULL ) {
                FzGlyphID charGlyphid = tempFont->unicharToGlyph(unichar);
               
                if ( charGlyphid == 0 && defaultFont != NULL) {
                    charGlyphid = defaultFont->unicharToGlyph(unichar);
                    default_genFont->addData(itemchar);
                } else {
                    if ( genFont != NULL ) {
                        genFont->addData(itemchar);
                    } else {
                        default_genFont->addData(itemchar);
                    }
                }
            }
            
            offset++;
           
        }
      
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::writeText( fz_device * dev, FZZOFDTextObject* textObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix)
{
    
    if ( textObject == NULL ) {
        return;
    }
    
    vector<FZZOFDTextCode*> * textCodes = textObject->getTextCodeList();
    if ( textCodes == NULL ) {
        return;
    }
    
    fz_context * ctx = m_CTX;
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
    
    FZZFontCache* defaultFont = m_FZTempFontList->getFont(FZZConst::g_FZFontConfig.getDefaultFontName(), "", "");
    
    
    FZZFontCache* tempFont = getFont_PDF(textObject);
   
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
    FZZImageUtil fzImageUtil_Shader(m_CTX);
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
            matrix_shade.postScale(OFD_MILLIMETERSTOPIXEL, OFD_MILLIMETERSTOPIXEL);
            
            fz_rect bbox = fz_make_rect(BoundaryBox_x, BoundaryBox_y, BoundaryBox_x+BoundaryBox_width, BoundaryBox_y+BoundaryBox_height);
            bbox = fz_transform_rect(bbox, matrix_shade.getMatrix());
           
            //fz_begin_group( m_CTX, dev, bbox, NULL, 1, 1, FZ_BLEND_NORMAL, 1);
            isShader = true;
            
            fzImageUtil_Shader.CreateImage(BoundaryBox_width*OFD_MILLIMETERSTOPIXEL*SHADERSCALE, BoundaryBox_height*OFD_MILLIMETERSTOPIXEL*SHADERSCALE, 255, 255, 255, 0);
            
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
//    if ( allText == "总" ) {
//        int aa;
//        aa++;
//    }
    
    
    FZZOFDCGTransform* ct_CGTransForm = NULL;
    
    int offset = 0;
    //vector<const FZZPath*> tbDrawChars;
    vector<const fz_text*> tbDrawChars;
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

                const fz_text * fontPath = NULL;
                if ( unichar != 32 && tempFont != NULL ) {
                    FzGlyphID charGlyphid = tempFont->unicharToGlyph(unichar);
                    fontPath = tempFont->getText(charGlyphid);
                    if ( (fontPath == NULL || charGlyphid == 0) && defaultFont != NULL ) {
                        charGlyphid = defaultFont->unicharToGlyph(unichar);
                        fontPath = defaultFont->getText(charGlyphid);
                    }
                    
                }
//                const FZZPath* fontPath = NULL;
//                if ( tempFont != NULL ) {
//                    FzGlyphID charGlyphid = tempFont->unicharToGlyph(unichar);
//                    fontPath = tempFont->getPath(charGlyphid);
//                    if ( (fontPath == NULL || charGlyphid == 0) && defaultFont != NULL ) {
//                        charGlyphid = defaultFont->unicharToGlyph(unichar);
//                        fontPath = defaultFont->getPath(charGlyphid);
//                    }
//                }

                tbDrawChars.push_back(fontPath);
                
            } else {
                const fz_text* fontPath = NULL;
                if ( tempFont != NULL ) {
                    fontPath = tempFont->getText(*gid_itr);

                    if ( fontPath == NULL  && defaultFont != NULL ) {
                        fontPath = defaultFont->getText(*gid_itr);
                    }
                }
//                const FZZPath* fontPath = NULL;
//                if ( tempFont != NULL ) {
//                    fontPath = tempFont->getPath(*gid_itr);
//
//                    if ( fontPath == NULL  && defaultFont != NULL ) {
//                        fontPath = defaultFont->getPath(*gid_itr);
//                    }
//                }
                tbDrawChars.push_back(fontPath);

                
            }
        }
       
    } else {
   
        while (offset < len) {
          
            itemchar = stcontent[offset];
            FzUnichar unichar = FZZConst::Utf8ToUtf32LE(itemchar);
            
            const fz_text* fontPath = NULL;
            if ( unichar !=32 && tempFont != NULL ) {
                FzGlyphID charGlyphid = tempFont->unicharToGlyph(unichar);
                fontPath = tempFont->getText(charGlyphid);
                if ( (fontPath == NULL || charGlyphid == 0) && defaultFont != NULL) {
                    charGlyphid = defaultFont->unicharToGlyph(unichar);
                    fontPath = defaultFont->getText(charGlyphid);
                }
            }
//            const FZZPath* fontPath = NULL;
//            if ( tempFont != NULL ) {
//                FzGlyphID charGlyphid = tempFont->unicharToGlyph(unichar);
//                fontPath = tempFont->getPath(charGlyphid);
//                if ( (fontPath == NULL || charGlyphid == 0) && defaultFont != NULL) {
//                    charGlyphid = defaultFont->unicharToGlyph(unichar);
//                    fontPath = defaultFont->getPath(charGlyphid);
//                }
//            }
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


        clipsAble(dev,clips,clipsmatrix,BoundaryBox_x,BoundaryBox_y,popcount);

    }
   
//    vector<const FZZPath*>::const_iterator skpath_itr;
//    vector<const FZZPath*>::const_iterator skpath_itr_begin = tbDrawChars.begin();
    vector<const fz_text*>::const_iterator skpath_itr;
    vector<const fz_text*>::const_iterator skpath_itr_begin = tbDrawChars.begin();
    vector<double>::iterator movex_itr = moveX.begin();
    vector<double>::iterator movey_itr = moveY.begin();
   
    if ( tbDrawChars.size() > 0 && moveX.size() > 0 && moveY.size() > 0 ){
        FZZMatrix shadeMatrix;
        for (skpath_itr = tbDrawChars.begin(); skpath_itr != tbDrawChars.end(); skpath_itr++) {
            shadeMatrix.reset();
            matrix.reset();
            //if ( tempfontsize <= 1 ) {
            if (hscale != 0) {
                matrix.postScale(hscale, 1);
                shadeMatrix.postScale(hscale, 1);
            }
            matrix.postScale(tempfontsize, -tempfontsize);
            shadeMatrix.postScale(tempfontsize, -tempfontsize);
            //}

            matrix.postTranslate(*(movex_itr + (skpath_itr - skpath_itr_begin)), *(movey_itr + (skpath_itr - skpath_itr_begin)));
            shadeMatrix.postTranslate(*(movex_itr + (skpath_itr - skpath_itr_begin)), *(movey_itr + (skpath_itr - skpath_itr_begin)));
            if (!ctm.empty()) {

                matrix.postConcat(ctmMatrix);
                shadeMatrix.postConcat(ctmMatrix);
            }

            if (!strboundary.empty()) {
                //matrix.postTranslate(*(movex_itr+(skpath_itr-tbDrawChars.begin())), *(movey_itr+(skpath_itr-tbDrawChars.begin())));
                matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
            }


            matrix.postConcat(parentMatrix);
            matrix.postScale(OFD_MILLIMETERSTOPIXEL, OFD_MILLIMETERSTOPIXEL);
            
            shadeMatrix.postConcat(parentMatrix);
            shadeMatrix.postScale(OFD_MILLIMETERSTOPIXEL, OFD_MILLIMETERSTOPIXEL);



            //const fz_text* fzText = fz_keep_text(ctx,(*skpath_itr));
            const fz_text* fzText = (*skpath_itr);

            if (fzText != NULL) {

                if (textObject->getStroke() || isBlob) {
                    textObject->getStrokeColor();
                    fz_stroke_state* fillstroke = fz_new_stroke_state(ctx);
                    if ( fillstroke != NULL ) {
                        //文字画外框的颜色一定是和填充的颜色一致，目前还没有碰到不一样的。
                        float color[] = { fillColor->r/255.0f, fillColor->g/255.0f, fillColor->b/255.0f };
                        
                        fillstroke->linewidth = 0.046;//(isBlob ? 0.13 : getLineWidth(textObject, drawParams))/OFD_MILLIMETERSTOPIXEL;
                        fillstroke->miterlimit = fillstroke->linewidth*30;

                        const FZZPath* fontPath = NULL;
                        if ( tempFont != NULL ) {
                            fontPath = tempFont->getPath(fzText->head->items[0].gid);

                            if ( fontPath == NULL  && defaultFont != NULL ) {
                                fontPath = defaultFont->getPath(fzText->head->items[0].gid);
                            }
                        }
                        
                        if ( isShader ) {
                            if ( ofdfillColor != NULL ) {
                                FZZOFDAxialShd * ofdAxialShd = ofdfillColor->getAxialShd();
                                if ( ofdAxialShd != NULL ) {
                                    
                                    
                                    
                                    
                                    //fz_rect clipbox = fz_bound_text(ctx, fzText, fillstroke, shadeMatrix.getMatrix());
                                    //fz_clip_stroke_text( m_CTX, dev, (fz_text*)fzText, fillstroke, shadeMatrix.getMatrix(), clipbox);
                                    
                                    shadeMatrix.postScale(SHADERSCALE, SHADERSCALE);
                                    FZZMatrix pathMatrix(shadeMatrix);
                                    pathMatrix.setScale(pathMatrix.getScaleX(), -pathMatrix.getScaleY());
                                    fz_rect clipbox = ((FZZPath*)fontPath)->getBounds(fillstroke, pathMatrix.getMatrix());
                                    fzImageUtil_Shader.ClipStrokePath(((FZZPath*)fontPath)->getPath(), fillstroke, pathMatrix.getMatrix(), clipbox);
                                    
                                    //popcount++;
                                    ShaderObject(fzImageUtil_Shader,ofdAxialShd,strboundary,BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
                                    fzImageUtil_Shader.POPClip();
                                    
                                    
                                }
                            }
                        }
                        else {
                            
                            if ( fontPath != NULL ) {
                                FZZMatrix pathMatrix(matrix);
                                pathMatrix.setScale(pathMatrix.getScaleX(), -pathMatrix.getScaleY());
                                fz_stroke_path(m_CTX, dev, ((FZZPath*)fontPath)->getPath(), fillstroke, pathMatrix.getMatrix(), fz_device_rgb(m_CTX), color, alpha/255.0f, fz_default_color_params);

                            }
                            
                            //fz_stroke_text( m_CTX, dev, (fz_text*)fzText, fillstroke, matrix.getMatrix(), fz_device_rgb(m_CTX), color, alpha/255.0f, fz_default_color_params);
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
                                
                                
                                shadeMatrix.postScale(SHADERSCALE, SHADERSCALE);
                                fz_rect clipbox = fz_bound_text(ctx, fzText, NULL, shadeMatrix.getMatrix());
                                fzImageUtil_Shader.ClipText((fz_text*)fzText, shadeMatrix.getMatrix(), clipbox);
                                ShaderObject(fzImageUtil_Shader,ofdAxialShd,strboundary,BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
                                fzImageUtil_Shader.POPClip();
                                
                                
                                
                            }
                        }
                    }
                    else {
                        
                        
                        fz_fill_text( m_CTX, dev, (fz_text*)fzText, matrix.getMatrix(), fz_device_rgb(m_CTX), color, alpha/255.0f, fz_default_color_params);
                        
//                        const FZZPath* fontPath = NULL;
//                        if ( tempFont != NULL ) {
//                            fontPath = tempFont->getPath(fzText->head->items[0].gid);
//
//                            if ( fontPath == NULL  && defaultFont != NULL ) {
//                                fontPath = defaultFont->getPath(fzText->head->items[0].gid);
//                            }
//                        }
//
//                        FZZMatrix pathMatrix(matrix);
//                        pathMatrix.setScale(pathMatrix.getScaleX(), -pathMatrix.getScaleY());
//                        fz_fill_path(m_CTX, dev, ((FZZPath*)fontPath)->getPath(), 0, pathMatrix.getMatrix(), fz_device_rgb(m_CTX), color, alpha/255.0f, fz_default_color_params);

                    }




                }


                //fz_drop_text(ctx, fzText);

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
    
    if ( isShader ) {
        //fz_end_group( m_CTX, dev);
//        FZZBytes B_shaderImage = fzImageUtil_Shader.PngEncode();
//        FZZConst::writefile("/Volumes/WorkExt/work/cpp/ofdcreator_test/imageconverter/shadertext.png", B_shaderImage.getData(), B_shaderImage.getLen());
        FZZMatrix imageShaderMatrix;
        imageShaderMatrix.postScale(BoundaryBox_width, BoundaryBox_height);
        imageShaderMatrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
        imageShaderMatrix.postConcat(parentMatrix);
        imageShaderMatrix.postScale(OFD_MILLIMETERSTOPIXEL, OFD_MILLIMETERSTOPIXEL);
        fz_fill_image( m_CTX, dev, fzImageUtil_Shader.getImage(), imageShaderMatrix.getMatrix(), 1.0f,fz_default_color_params);
    }

    if ( clips != NULL && popcount > 0 ) {
    
        for ( int pop_i = 0; pop_i < popcount; pop_i++ ) {
            fz_pop_clip( m_CTX, dev);
        }
        
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
void FZZOFDToPDF::writeImage( fz_device * dev, FZZOFDImageObject* imageObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix)
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
    
    FZZImageUtil tempimage(m_CTX);
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
    matrix.postScale(OFD_MILLIMETERSTOPIXEL,OFD_MILLIMETERSTOPIXEL);
    
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
        clipsAble(dev,clips,clipsmatrix,BoundaryBox_x, BoundaryBox_y,popcount);
    }
    
    
    fz_fill_image( m_CTX, dev, tempimage.getImage(), matrix.getMatrix(), imageObject->getAlpha()/255.0f,fz_default_color_params);
    
    if ( clips != NULL && popcount > 0 ) {
        for ( int pop_i = 0; pop_i < popcount; pop_i++ ) {
            fz_pop_clip( m_CTX, dev);
        }
        
    }
    
     
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::writePath_genFontFile( fz_device * dev, FZZOFDPathObject* pathObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha,int preAlpha)
{
    if ( pathObject == NULL ) {
        return;
    }
    
    if ( !pathObject->getVisible() ) {
        return;
    }
    
    fz_context * ctx = m_CTX;
    if ( ctx == NULL ) {
        return;
    }
    
    double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
    string strboundary = pathObject->getBoundary();
    if ( !strboundary.empty() ) {
        ST_Box_ToDouble(strboundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
    }
    
    if ( pathObject->getFill() ) {
        FZZOFDFillColor * ofdfillColor = pathObject->getFillColor();
        if ( ofdfillColor != NULL ) {
            FZZOFDPattern * ofdPattern = ofdfillColor->getPattern();
            if (ofdPattern != NULL) {
                PatternObject(dev,ofdPattern,strboundary,BoundaryBox_x, BoundaryBox_y,BoundaryBox_width,BoundaryBox_height);
            }
            
        }
        
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::writePath( fz_device * dev, FZZOFDPathObject* pathObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha,int preAlpha)
{
    
    if ( pathObject == NULL ) {
        return;
    }
    
    if ( !pathObject->getVisible() ) {
        return;
    }
    
    fz_context * ctx = m_CTX;
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
    matrix.postScale(OFD_MILLIMETERSTOPIXEL,OFD_MILLIMETERSTOPIXEL);
    
    
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
    
    FZZImageUtil fzImageUtil_Shader(m_CTX);
    float shader_x = 0;
    float shader_y = 0;
    float shader_width = 0;
    float shader_height = 0;
    
    bool isShader = false;
    bool isPattern = false;
    FZZOFDStrokeColor * ofdStrokeColor = pathObject->getStrokeColor();
    if ( ofdStrokeColor != NULL ) {
        FZZOFDAxialShd * ofdAxialShd = ofdStrokeColor->getAxialShd();
        if (ofdAxialShd != NULL) {
            fz_rect bbox = path.getBounds();
            //fz_begin_group( m_CTX, dev, bbox, NULL, 1, 1, FZ_BLEND_NORMAL, 1);
            shader_x = bbox.x0 ;
            shader_y = bbox.y0;
            shader_width = bbox.x1 - bbox.x0;
            shader_height = bbox.y1 - bbox.y0;
            if ( shader_height <= 0 ) {
                shader_height = linewidth;
                shader_y -= shader_height / 2;
            }
            if ( shader_width != 0 && shader_height != 0 ) {
            
                fzImageUtil_Shader.CreateImage(shader_width*SHADERSCALE, shader_height*SHADERSCALE, 255, 255, 255, 0);
                isShader = true;
            }
        }
    }

    FZZOFDFillColor * ofdfillColor = pathObject->getFillColor();
    if ( ofdfillColor != NULL ) {
        FZZOFDAxialShd * ofdAxialShd = ofdfillColor->getAxialShd();
        FZZOFDPattern * ofdPattern = ofdfillColor->getPattern();
        if (ofdAxialShd != NULL ) {
            if ( !isShader ) {
                fz_rect bbox = path.getBounds();
                shader_x = bbox.x0 ;
                shader_y = bbox.y0;
                shader_width = bbox.x1 - bbox.x0;
                shader_height = bbox.y1 - bbox.y0;
                if ( shader_height <= 0 ) {
                    shader_height = linewidth;
                    shader_y -= shader_height / 2;
                }
                //fz_begin_group( m_CTX, dev, bbox, NULL, 1, 1, FZ_BLEND_NORMAL, 1);
                if ( shader_width != 0 && shader_height != 0 ) {
                    fzImageUtil_Shader.CreateImage(shader_width*SHADERSCALE, shader_height*SHADERSCALE, 255, 255, 255, 0);
                    isShader = true;
                }
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
        

        clipsAble(dev,clips,clipsmatrix,BoundaryBox_x, BoundaryBox_y,popcount);
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
          
            fz_fill_path(m_CTX, dev, path.getPath(), 0, MUPDF_fz_identity, fz_device_rgb(m_CTX), color, fzAlpha, fz_default_color_params);
            fz_stroke_state* fillstroke = fz_new_stroke_state(ctx);
            if ( fillstroke != NULL ) {
                fillstroke->linewidth = linewidth;
                fillstroke->miterlimit = fillstroke->linewidth*30;
                
                fz_stroke_path(m_CTX, dev, path.getPath(), fillstroke, MUPDF_fz_identity, fz_device_rgb(m_CTX), color, fzAlpha, fz_default_color_params);
                fz_drop_stroke_state(ctx,fillstroke);
            }
        }
        if ( fillColor != NULL ) {
            delete fillColor;
        }
  
        
        if ( ofdfillColor != NULL ) {
            FZZOFDAxialShd * ofdAxialShd = ofdfillColor->getAxialShd();
            FZZOFDPattern * ofdPattern = ofdfillColor->getPattern();

            if (ofdAxialShd != NULL  ) {
                if ( isShader ) {
                    ShaderObject(fzImageUtil_Shader,ofdAxialShd,strboundary,BoundaryBox_x, BoundaryBox_y,BoundaryBox_width,BoundaryBox_height);
                }
                
            } else if (ofdPattern != NULL) {
                PatternObject(dev,ofdPattern,strboundary,BoundaryBox_x, BoundaryBox_y,BoundaryBox_width,BoundaryBox_height);
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
                   
                    fz_stroke_path(m_CTX, dev, path.getPath(), stroke, MUPDF_fz_identity, fz_device_rgb(m_CTX), color, fzAlpha, fz_default_color_params);
                    
                }
            }
            
            if ( ofdStrokeColor != NULL ) {
                FZZOFDAxialShd * ofdAxialShd = ofdStrokeColor->getAxialShd();
                
                if (ofdAxialShd != NULL ) {
                    if ( isShader ) {
                        ShaderObject(fzImageUtil_Shader,ofdAxialShd,strboundary,BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
                    }
                    
                }
                
            }
            
            if ( strokeColor != NULL ) {
                delete strokeColor;
            }
            
            
            
        }
        
    }
    
    if ( isShader ) {
        //fz_end_group( m_CTX, dev);
        //FZZBytes B_shaderImage = fzImageUtil_Shader.PngEncode();
        //FZZConst::writefile("/Volumes/WorkExt/work/cpp/ofdcreator_test/imageconverter/shaderImage.png", B_shaderImage.getData(), B_shaderImage.getLen());
        
        FZZMatrix imageShaderMatrix;
        imageShaderMatrix.postScale(shader_width, shader_height);
        imageShaderMatrix.postTranslate(shader_x, shader_y);
        imageShaderMatrix.postConcat(parentMatrix);
 
    
        fz_fill_image( m_CTX, dev, fzImageUtil_Shader.getImage(), imageShaderMatrix.getMatrix(), 1.0f,fz_default_color_params);
        
                
    }
    
    if ( clips != NULL && popcount > 0 ) {
        for ( int pop_i = 0; pop_i < popcount; pop_i++ ) {
            fz_pop_clip( m_CTX, dev);
        }
        
    }
    
    
    
    if ( stroke != NULL ) {
        fz_drop_stroke_state(ctx,stroke);
        stroke = NULL;
    }
   
     
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::writeComposite( fz_device * dev, FZZOFDCompositeObject* compositeObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isNoText)
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
//            matrix.postScale((OFD_MILLIMETERSTOPIXEL *boundary->getWidth()),(OFD_MILLIMETERSTOPIXEL *boundary->getHeight()));
//        }
    }
    
    if (!strboundary.empty()) {
        double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
        ST_Box_ToDouble(strboundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
        matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
        
    }
    
    matrix.postConcat(parentMatrix);

    writeContent(dev, vectorG->getContent(), drawParams, matrix,alpha != 255,alpha,isNoText);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::addDrawParams(vector<FZZOFDDrawParam*>& drawParams, const string& refID)
{
    if ( !refID.empty() ) {
        FZZOFDDrawParam* ctDrawParam = m_reader->getDrawParam(refID);
        if (ctDrawParam != NULL) {
            drawParams.push_back(ctDrawParam);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::clipsAble(fz_device * dev,FZZOFDClips * clips,FZZMatrix& clipsmatrix,double preboundary_x, double preboundary_y,int & clipscount)
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
    
    fz_context * ctx = m_CTX;
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
                    clipsPath(dev,areaCTM,ct_path,clipsmatrix,preboundary_x, preboundary_y,TransFlag,clipStrokepath);
                    
                    fz_stroke_state* stroke = fz_new_stroke_state(ctx);
                    if ( stroke != NULL ) {
                        stroke->linewidth = lineWidth;
                        stroke->miterlimit = stroke->linewidth*30;
                        fz_rect clipbox = clipStrokepath.getBounds(stroke, MUPDF_fz_identity);
                        
                        if ( clipbox.x1-clipbox.x0 >= m_CurrPage_WidthPixel && clipbox.y1 - clipbox.y0 >= m_CurrPage_HeightPixel ) {
                            //ispop = false;
                        } else {
                            //ispop = true;
                            
                            fz_clip_stroke_path( m_CTX, dev, clipStrokepath.getPath(),stroke,MUPDF_fz_identity,clipbox);
                            clipscount++;
                        }
                        
                        fz_drop_stroke_state(ctx,stroke);
                        
                    }
                }
                
                if ( ct_path->getFill() ) {
                    clippath.reset();
                    
                    isclippath = true;
                    clipsPath(dev,areaCTM,ct_path,clipsmatrix,preboundary_x, preboundary_y,TransFlag,clippath);
                    
                    
                    fz_rect clipbox = clippath.getBounds();
                    if ( clipbox.x1-clipbox.x0 >= m_CurrPage_WidthPixel && clipbox.y1 - clipbox.y0 >= m_CurrPage_HeightPixel ) {
                        //ispop = false;
                    } else {
                        //ispop = true;
                     
                        fz_clip_path( m_CTX, dev, clippath.getPath(),0,MUPDF_fz_identity,clipbox);
                        clipscount++;
                    }
                }
                
                
            } else if (ct_text != NULL) {
                clipsText(dev,areaCTM,ct_text,clipsmatrix,TransFlag);
                //clipscount++;
            }
            
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::clipsText(fz_device * dev,vector<double> & ctm,FZZOFDText * ct_text,FZZMatrix& clipsmatrix,bool TransFlag)
{
    if ( ct_text == NULL ) {
        return;
    }
    DLOG("clipsText");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::clipsPath(fz_device * dev,vector<double> & ctm,FZZOFDPath * ct_path,FZZMatrix& matrix,double preboundary_x, double preboundary_y,bool TransFlag,/*out*/FZZPath& destpath)
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
    clipmatrix.postScale(OFD_MILLIMETERSTOPIXEL,OFD_MILLIMETERSTOPIXEL);

   
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
double FZZOFDToPDF::getLineWidth(FZZOFDBaseGraphic* graphicUnit, vector<FZZOFDDrawParam*>* drawParams)
{
    if ( graphicUnit == NULL ) {
        return 0.1;
    }
    double lineWidth = graphicUnit->getLineWidth();
    if (lineWidth != 0) return lineWidth;
    if ( drawParams != NULL && drawParams->size() > 0 ) {
        lineWidth = (*drawParams)[drawParams->size()-1]->getLineWidth();
        if (lineWidth != 0) return lineWidth;
        return 0.1;
    }

    return 0.1;
   
}
//-----------------------------------------------------------------------------------------------------------------
TOFDColor* FZZOFDToPDF::getStrokeColor(FZZOFDColor* color, FZZOFDColor* defaultColor, vector<FZZOFDDrawParam*>* drawParams)
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
TOFDColor* FZZOFDToPDF::getFillColor(FZZOFDColor* color, FZZOFDColor* defaultColor, vector<FZZOFDDrawParam*>* drawParams)
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
TOFDColor* FZZOFDToPDF::getColor(FZZOFDColor* ctColor)
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
bool FZZOFDToPDF::ShaderObject(FZZImageUtil & graphics,FZZOFDAxialShd * ct_AxialShd,string & strBoundary,double BoundaryBox_x, double BoundaryBox_y, double BoundaryBox_width, double BoundaryBox_height)
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
//            if (!strBoundary.empty()) {
//                ShaderMatrix0.postTranslate(BoundaryBox_x, BoundaryBox_y);
//            }
            ShaderMatrix0.postTranslate(startpos_x, startpos_y);
            ShaderMatrix0.postScale(OFD_MILLIMETERSTOPIXEL*SHADERSCALE,OFD_MILLIMETERSTOPIXEL*SHADERSCALE);

            FZZMatrix ShaderMatrix1;
//            if (!strBoundary.empty()) {
//                ShaderMatrix1.postTranslate(BoundaryBox_x, BoundaryBox_y);
//            }
            ShaderMatrix1.postTranslate(endpos_x, endpos_y);
            ShaderMatrix1.postScale(OFD_MILLIMETERSTOPIXEL*SHADERSCALE,OFD_MILLIMETERSTOPIXEL*SHADERSCALE);

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
                
                fz_shade * shade = graphics.newShade(FZ_LINEAR, 3, 3, ShaderMatrix0.getTranslateX(),ShaderMatrix0.getTranslateY(),0, ShaderMatrix1.getTranslateX(),ShaderMatrix1.getTranslateY(),0, stop_list, stop_count);

                if ( shade != NULL ) {
                    graphics.DrawFillShade(shade, MUPDF_fz_identity, 1, fz_default_color_params);
                    graphics.deleteShade(shade);
                }
            }

        }//if ( segments->size() > 0 )
    }//if ( extendType == FZZOFDExtend::TYPE::TYPE_3 )


    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDToPDF::PatternObject(fz_device * dev,FZZOFDPattern * ct_Pattern,string & strboundary,double BoundaryBox_x, double BoundaryBox_y, double BoundaryBox_width, double BoundaryBox_height)
{
    bool isTF = false;
    if ( ct_Pattern == NULL ) {
        return isTF;
    }
    
    int patternWidth = ct_Pattern->getWidth();
    int patternHeight = ct_Pattern->getHeight();
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
                isTF = PatternImageObject(dev,(FZZOFDImageObject *)pageBlockType_item,strboundary,BoundaryBox_x,BoundaryBox_y,BoundaryBox_width,BoundaryBox_height,view,pXY);
            } else if (dynamic_cast<FZZOFDTextObject*>(pageBlockType_item) != NULL) {
                isTF = PatternTextObject(dev,(FZZOFDTextObject *)pageBlockType_item,strboundary,BoundaryBox_width,BoundaryBox_height,pXY.x ,pXY.y);
            }
        } //for( itr = PageBlockTypeList->begin(); itr != PageBlockTypeList->end(); itr++ )
                                                                                    
        
    }//if ( cellConTent != NULL )
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
//pdf_dev_begin_tile 没有实现，如果下一个版本实现了 pdf_dev_begin_tile，可以使用平铺有效减少pdf的大小，具体参考ofd转图片实现，也因此ofd转图片中平铺文字，没有用研究平铺文字的实现，目前研究文字平铺没有意义
bool FZZOFDToPDF::PatternImageObject(fz_device * dev,FZZOFDImageObject* imageObject,string & preboundary,double preboundary_x, double preboundary_y,double BoundaryBox_width, double BoundaryBox_height,fz_rect view,fz_point pXY)
{
    bool isTF = false;
    if ( imageObject == NULL || m_reader == NULL || dev == NULL ) {
        return isTF;
    }
    
    fz_context * ctx = m_CTX;
    
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
    pageMatrix.postScale(OFD_MILLIMETERSTOPIXEL,OFD_MILLIMETERSTOPIXEL);
    pagebox = fz_transform_rect(pagebox, pageMatrix.getMatrix());
    
    //graphics.BeginGroup(pagebox, NULL, 1, 0, FZ_BLEND_NORMAL, 1);
    
    FZZPath clippath(ctx);
    clippath.rectTo(pagebox.x0, pagebox.y0,pagebox.x1,pagebox.y1);
    
    fz_clip_path( m_CTX, dev, clippath.getPath(), 0, MUPDF_fz_identity, pagebox);
    
    
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
  
    matrix.postScale(OFD_MILLIMETERSTOPIXEL,OFD_MILLIMETERSTOPIXEL);
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
            
            fz_fill_image( m_CTX, dev, image,   drawctm.getMatrix(),
                          1,//alpha/255.0f
                          fz_default_color_params);
            
        }
    }
    
    fz_pop_clip( m_CTX, dev);
    
    //graphics.EndGroup();
    
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFDToPDF::PatternTextObject(fz_device * dev,FZZOFDTextObject* textObject,string& boundary, double BoundaryBox_width, double BoundaryBox_height,double xStep,double yStep)
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
        if ( m_isGenFont ) {
            writeText_genFontFile(dev, textObject, NULL,matrix);
        } else {
            writeText(dev, textObject, NULL, matrix);
        }
        
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
FZZFontCache* FZZOFDToPDF::getFont_PDF(FZZOFDTextObject* textObject)
{
 
    FZZFontCache* retSKFont = NULL;

    string stRefID = textObject->getFont();
    if (stRefID.empty()) return retSKFont;
    
    FZZOFDFont* ctFont = m_reader->getFont(stRefID);
    if (ctFont == NULL) {
        retSKFont = m_FZTempFontList->getFont(FZZConst::g_FZFontConfig.getDefaultFontName(), "", "");
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
        if ( (retSKFont = m_FZTempFontList->getFont(fontName, familyName, fontFileLoc)) == NULL ) {
            FZZOFDResDir * resDir = m_reader->getResDir_default();
            if ( resDir != NULL ) {
                FZZBytes* fontData = resDir->getResFile(fontFileLoc);
    
                if ( fontData != NULL && fontData->getLen() > 10 ) {
                    retSKFont = m_FZTempFontList->addFontFile(m_CTX,fontName,familyName,fontFileLoc, fontData);
                    if ( retSKFont == NULL ) {
                        retSKFont = m_FZTempFontList->getFont(FZZConst::g_FZFontConfig.getDefaultFontName(), "", "");
                        
                    }
                } else {
                    retSKFont = m_FZTempFontList->getFont(FZZConst::g_FZFontConfig.getDefaultFontName(), "", "");
                }
            }
        }
    } else {
        
        if ( !fontName.empty() ) {
            retSKFont = m_FZTempFontList->getFont(fontName, "", "");
            if ( retSKFont == NULL ) {
                string findfontname = FZZConst::g_FZFontConfig.ConvertSysFontName(fontName);
                if ( findfontname.empty() ) {
                    findfontname = FZZConst::g_FZFontConfig.getDefaultFontName();
                }
                retSKFont = m_FZTempFontList->getFont(findfontname, "", "");
                if ( retSKFont == m_FZTempFontList->getFont(FZZConst::g_FZFontConfig.getDefaultFontName(), "", "") ) {
                    if ( !familyName.empty() ) {
                        FZZFontCache*  tempRetSKFont = m_FZTempFontList->getFont(familyName, "", "");
                        if ( tempRetSKFont == NULL ) {
                            findfontname = FZZConst::g_FZFontConfig.ConvertSysFontName(familyName);
                            if ( findfontname.empty() ) {
                                findfontname = FZZConst::g_FZFontConfig.getDefaultFontName();
                            }
                            tempRetSKFont = m_FZTempFontList->getFont(findfontname, "", "");
                            if ( tempRetSKFont != retSKFont ) {
                                retSKFont = tempRetSKFont;
                            }
                        }
                    }
                }
            }
            

            
            
        }
    }
    
    
    return retSKFont;
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache* FZZOFDToPDF::getFont(FZZOFDTextObject* textObject,bool & isGen,string & outfontname)
{
    FZZFontCache* retSKFont = NULL;

    string stRefID = textObject->getFont();
    if (stRefID.empty()) return retSKFont;
    
    FZZOFDFont* ctFont = m_reader->getFont(stRefID);
    if (ctFont == NULL) {
        retSKFont = FZZConst::g_FZSystemFontList.addDefaultFont();
        outfontname = FZZConst::g_FZFontConfig.getDefaultFontName();
        isGen = FZZConst::g_FZFontConfig.isClip(outfontname);
        if ( !isGen ) {
            retSKFont = m_FZTempFontList->addFontFile(m_CTX,outfontname,"","", retSKFont->getFontData());
            outfontname += "__";
        }
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
        isGen = false;
        outfontname = fontName + "_" + familyName + "_" + fontFileLoc;
        if ( (retSKFont = m_FZTempFontList->getFont(fontName,familyName,fontFileLoc)) == NULL ) {
            FZZOFDResDir * resDir = m_reader->getResDir_default();
            if ( resDir != NULL ) {
                FZZBytes* fontData = resDir->getResFile(fontFileLoc);
    
                if ( fontData != NULL && fontData->getLen() > 10 ) {
                    retSKFont = m_FZTempFontList->addFontFile(m_CTX,fontName,familyName,fontFileLoc, fontData);
                    if ( retSKFont == NULL ) {
                        retSKFont = FZZConst::g_FZSystemFontList.addDefaultFont();
                        outfontname = FZZConst::g_FZFontConfig.getDefaultFontName();
                        isGen = FZZConst::g_FZFontConfig.isClip(outfontname);
                        if ( !isGen ) {
                            retSKFont = m_FZTempFontList->addFontFile(m_CTX,outfontname,"","", retSKFont->getFontData());
                            outfontname += "__";
                        }
                    }
                } else {
                    retSKFont = FZZConst::g_FZSystemFontList.addDefaultFont();
                    outfontname = FZZConst::g_FZFontConfig.getDefaultFontName();
                    isGen = FZZConst::g_FZFontConfig.isClip(outfontname);
                    if ( !isGen ) {
                        retSKFont = m_FZTempFontList->addFontFile(m_CTX,outfontname,"","", retSKFont->getFontData());
                        outfontname += "__";
                    }
                }
            }
        }
    } else {
        
        if ( !fontName.empty() ) {
//            if ( fontName == "Helvetica" ) {
//                int i = 0;
//                i++;
//            }
            
            retSKFont = FZZConst::g_FZSystemFontList.findFont(fontName,outfontname);
            isGen = FZZConst::g_FZFontConfig.isClip(outfontname);
            if ( retSKFont == FZZConst::g_FZSystemFontList.addDefaultFont() ) {
                outfontname = FZZConst::g_FZFontConfig.getDefaultFontName();
                isGen = FZZConst::g_FZFontConfig.isClip(outfontname);
                if ( !familyName.empty() ) {
                    retSKFont = FZZConst::g_FZSystemFontList.findFont(familyName,outfontname);
                    if ( retSKFont == FZZConst::g_FZSystemFontList.addDefaultFont() ) {
                        outfontname = FZZConst::g_FZFontConfig.getDefaultFontName();
                        isGen = FZZConst::g_FZFontConfig.isClip(outfontname);
                        if ( !isGen ) {
                            retSKFont = m_FZTempFontList->addFontFile(m_CTX,outfontname,"","", retSKFont->getFontData());
                            outfontname += "__";
                        }
                    } else {
                        isGen = FZZConst::g_FZFontConfig.isClip(outfontname);
                        if ( !isGen ) {
                            retSKFont = m_FZTempFontList->addFontFile(m_CTX,outfontname,"","", retSKFont->getFontData());
                            outfontname += "__";
                        }
                    }
                }
            } else {
                if ( !isGen ) {
                    retSKFont = m_FZTempFontList->addFontFile(m_CTX,outfontname,"","", retSKFont->getFontData());
                    outfontname += "__";
                }
                
            }
        }
    }
    
    
    return retSKFont;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDToPDF::parseDelta(vector<string> & array,vector<double> & arr)
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
size_t FZZOFDToPDF::getGlyphsSize(FZZOFDGlyphs * ofdglyphs)
{
    if ( ofdglyphs == NULL ) return 0;
    vector<string> glyphs;
    ofdglyphs->getValue(glyphs);
    return glyphs.size();
}
//-----------------------------------------------------------------------------------------------------------------

void FZZOFDToPDF::test()
{
   
}
//-----------------------------------------------------------------------------------------------------------------
