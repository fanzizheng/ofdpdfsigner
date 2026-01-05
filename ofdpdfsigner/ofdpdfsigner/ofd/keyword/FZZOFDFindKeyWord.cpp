//
//  Created by zizheng fan on 2024/08/06.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/keyword/FZZOFDFindKeyWord.h"
#include "basic/FZZString.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZOFDFindKeyWord******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFindKeyWord::FZZOFDFindKeyWord() : m_reader(NULL),m_pages(NULL)
{
    //DLOG("FZZOFDFindKeyWord()");
    FZZConst::addClassCount("FZZOFDFindKeyWord");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFindKeyWord::FZZOFDFindKeyWord(FZZOFD* reader) : FZZOFDFindKeyWord()
{
    if ( reader != NULL ) {
        m_reader = reader;
        m_pages = reader->getPageInfoList();
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFindKeyWord::FZZOFDFindKeyWord(const FZZOFDFindKeyWord& obj): FZZOFDFindKeyWord()
{
    //DLOG("OFD2PDF(const OFD2PDF& obj)");
    if ( this == &obj ) {
        return;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFindKeyWord::~FZZOFDFindKeyWord()
{
    //DLOG("~FZZOFDFindKeyWord()");
    FZZConst::delClassCount("FZZOFDFindKeyWord");
    clearKeyWordList();
    
    m_pages = NULL;
    m_reader = NULL;
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFindKeyWord::clearKeyWordList()
{
    vector<FZZKeyWordInfo*>::const_iterator it;
    for( it = m_KeyWordList.begin(); it != m_KeyWordList.end(); it++ ) {
        FZZKeyWordInfo * temp = *it;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_KeyWordList.clear();
    
    
    for( it = m_GKeyWordList.begin(); it != m_GKeyWordList.end(); it++ ) {
        FZZKeyWordInfo * temp = *it;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_GKeyWordList.clear();
    
  
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZKeyWordInfo*> * FZZOFDFindKeyWord::find(int pageIndex,string keyWord)
{
    //DLOG("FZZOFDFindKeyWord::find begin");
    clearKeyWordList();
    
    //DLOG("FZZOFDFindKeyWord::find %d,%s",pageIndex,keyWord.c_str());
    //DLOG("FZZOFDFindKeyWord::find 1 begin");
    if ( m_pages == NULL ) return NULL;
    if (pageIndex < 0 || (m_pages != NULL && pageIndex >= m_pages->size())) {
        return NULL;
    }
    //DLOG("FZZOFDFindKeyWord::find 1 end");
    string tempKeyWord = keyWord;
    //DLOG("FZZOFDFindKeyWord::find word = %s", tempKeyWord.c_str());
#ifdef _MSC_VER 
    keyWord = FZZConst::Utf8toGB2312(keyWord);
#endif
    transform(keyWord.begin(), keyWord.end(), keyWord.begin(), ::tolower);
    
    FZZMatrix matrix;
    matrix.reset();
    
    TPageInfo* pageInfo = (*m_pages)[pageIndex];
    if ( pageInfo == NULL ) {
        //DLOG("pageInfo == NULL, pageIndex = %d",pageIndex);
        return NULL;
    }
    //DLOG("FZZOFDFindKeyWord::find 2 begin");
    writePage(pageIndex,pageInfo,matrix);
    //DLOG("FZZOFDFindKeyWord::find 2 end");
    
    FZZString stkeyWord = keyWord;
    int len = stkeyWord.length();
    //DLOG("FZZOFDFindKeyWord::find 3 begin");
    vector<FZZKeyWordInfo*>::const_iterator it;
    for( it = m_GKeyWordList.begin(); it != m_GKeyWordList.end(); it++ ) {
        FZZKeyWordInfo * temp = *it;
        if ( temp == NULL ) continue;
        if ( stkeyWord[0] == temp->getKeyWord() ) {
            //DLOG("FZZOFDFindKeyWord::find ....... 1");
            bool isfind = true;
            FZZKeyWordInfo * subtemp = NULL;
            float y = temp->getY();
            float h = temp->getH();
            for ( int i = 1; i < len; i++ ) {
                subtemp = *(it+i);
                if ( subtemp == NULL ) {
                    isfind = false;
                    //DLOG("FZZOFDFindKeyWord::find ....... 2 break");
                    break;
                }
                //DLOG("FZZOFDFindKeyWord::find ....... 4 %s == %s",stkeyWord[i].c_str(),subtemp->getKeyWord().c_str());
                if ( stkeyWord[i] != subtemp->getKeyWord() ) {
                    isfind = false;
                    //DLOG("FZZOFDFindKeyWord::find ....... 3 break");
                    break;
                }
              
                if ( h < subtemp->getH() ) {
                    h = subtemp->getH();
                }
                
                if ( y > subtemp->getY() ) {
                    y = subtemp->getY();
                }
            }
            
            if ( isfind ) {
                //DLOG("FZZOFDFindKeyWord::find ....... ok");
                if ( subtemp != NULL ) {
                    //DLOG("FZZOFDFindKeyWord::find add list word = %s", tempKeyWord.c_str());
                    m_KeyWordList.push_back(new FZZKeyWordInfo(pageIndex, tempKeyWord,temp->getX(),y,subtemp->getX()+subtemp->getW()-temp->getX(),h+0.3));
                    
                    
                } else {
                    //DLOG("FZZOFDFindKeyWord::find add list word = %s", tempKeyWord.c_str());
                    m_KeyWordList.push_back(new FZZKeyWordInfo(pageIndex, tempKeyWord,temp->getX(),y,temp->getW(),h+0.3));
                }
                it = it+ len - 1;
                
            }
        }
    }
    //DLOG("FZZOFDFindKeyWord::find 3 end");
    for( it = m_GKeyWordList.begin(); it != m_GKeyWordList.end(); it++ ) {
        FZZKeyWordInfo * temp = *it;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_GKeyWordList.clear();
    //DLOG("FZZOFDFindKeyWord::find end");
    return &m_KeyWordList;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFindKeyWord::writePage(int pageIndex, TPageInfo* pageInfo,FZZMatrix & matrix)
{
    //DLOG("FZZOFDFindKeyWord::writePage begin");
    string pageId = pageInfo->id;
    //DLOG("FZZOFDFindKeyWord::writePage 1 begin");
    vector<FZZOFDLayer *>* layerList = &(pageInfo->layerList);
    
    if ( layerList != NULL ) {
        vector<FZZOFDLayer*>::const_iterator CT_Layer_iter;
        //DLOG("FZZOFDFindKeyWord::writePage 1...1 begin");
        for (CT_Layer_iter = layerList->begin(); CT_Layer_iter != layerList->end(); CT_Layer_iter++) {
            //DLOG("FZZOFDFindKeyWord::writePage 1...1....1 begin");
            writeContent(pageIndex, *CT_Layer_iter, NULL,matrix,false,0xff);
            //DLOG("FZZOFDFindKeyWord::writePage 1...1....1 end");
        }
        //DLOG("FZZOFDFindKeyWord::writePage 1...1 end");
        
    }
    //DLOG("FZZOFDFindKeyWord::writePage 1 end");
    //DLOG("FZZOFDFindKeyWord::writePage 2 begin");
    vector<FZZOFDPageDir *> * annotationDirList = m_reader->getAnnotationList();
    if ( annotationDirList != NULL ) {
        vector<FZZOFDPageDir*>::const_iterator AnnotionEntity_iter;
        for (AnnotionEntity_iter = annotationDirList->begin(); AnnotionEntity_iter != annotationDirList->end(); AnnotionEntity_iter++) {
            FZZOFDPageDir* annotionEntity = *AnnotionEntity_iter;
            if ( annotionEntity == NULL ) {
                continue;
            }
            FZZOFDPageAnnotXML* pageAnnotXml = annotionEntity->getAnnotationXML();
            if ( annotionEntity->getPageId() == pageId && pageAnnotXml != NULL ) {
                vector<FZZOFDAnnot_Annotation*>* Annots = pageAnnotXml->getAnnotList();
                if ( Annots != NULL ) {
                    vector<FZZOFDAnnot_Annotation*>::const_iterator Annot_iter;
                    for (Annot_iter = Annots->begin(); Annot_iter != Annots->end(); Annot_iter++) {
                        FZZOFDAnnot_Annotation* tempAnnot = *Annot_iter;
                        if ( tempAnnot != NULL ) {
                            if ( tempAnnot->getSubtype() != "PDFWidgetSign" ) {
                                FZZMatrix tempmatrix;
                            
                                writeContent(pageIndex, tempAnnot->getAppearance(), NULL,tempmatrix,false,0xff);
                            }
                        }
                    }
                } //if ( Annots != NULL )
            }
        }//for (AnnotionEntity_iter = annotationDirList->begin(); AnnotionEntity_iter != annotationDirList->end(); AnnotionEntity_iter++)
    }//if ( annotationDirList != NULL )
    
    //DLOG("FZZOFDFindKeyWord::writePage 2 end");
    //DLOG("FZZOFDFindKeyWord::writePage end");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFindKeyWord::writeContent(int pageIndex,FZZOFDPageBlock* pageBlock, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha,int preAlpha)
{
    //DLOG("writeContent........begin");
    vector<FZZOFDDrawParam*> tempdrawParams;
    if ( pageBlock == NULL ) return;
    
    if (drawParams != NULL) {
        tempdrawParams.assign(drawParams->begin(), drawParams->end());
    }
   
    if (dynamic_cast<FZZOFDLayer*>(pageBlock) != NULL) {
        string drawParamRef = ((FZZOFDLayer*)pageBlock)->getDrawParam_String();
        addDrawParams(tempdrawParams, drawParamRef);
    }
    
    
    //if (parentMatrix == null) parentMatrix = MatrixUtils.base();
    string strBoundaryBox = pageBlock->getBoundary();
    
    if ( !strBoundaryBox.empty() ) {
        double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
        ST_Box_ToDouble(strBoundaryBox, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
        //parentMatrix.postTranslate(m_ppm *BoundaryBox->getTopLeftX(), m_ppm *BoundaryBox->getTopLeftY());
        parentMatrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
    }
    
    //int cc = 0;
    
    vector<FZZOFDPageBlockType*>* pageBlockTypes = pageBlock->getPageBlockList();
    vector<FZZOFDPageBlockType*>::const_iterator PageBlockType_iter;
    //DLOG("writeContent....for....begin");
    FZZOFDTextObject * textObj = NULL;
    FZZOFDImageObject * imageObj = NULL;
    FZZOFDPathObject * pathObj = NULL;
    FZZOFDCompositeObject * compositeObj = NULL;
    FZZOFDLayer * layerObj = NULL;
    FZZOFDPageBlock * pageBlockObj = NULL;
    
    for (PageBlockType_iter = pageBlockTypes->begin(); PageBlockType_iter != pageBlockTypes->end(); PageBlockType_iter++) {
        
        textObj = NULL;
        imageObj = NULL;
        pathObj = NULL;
        compositeObj = NULL;
        layerObj = NULL;
        pageBlockObj = NULL;
        
        if ((textObj = dynamic_cast<FZZOFDTextObject*>(*PageBlockType_iter)) != NULL) {
            
            addDrawParams(tempdrawParams, textObj->getDrawParam_String()) ;
            
            writeText(pageIndex,textObj, &tempdrawParams,parentMatrix);
            
            continue;
        } else if ( (imageObj = dynamic_cast<FZZOFDImageObject*>(*PageBlockType_iter)) != NULL) {
            
            addDrawParams(tempdrawParams, imageObj->getDrawParam_String()) ;
            
            continue;
        } else if ( (pathObj = dynamic_cast<FZZOFDPathObject*>(*PageBlockType_iter)) != NULL) {
            
            addDrawParams(tempdrawParams, pathObj->getDrawParam_String()) ;
            //writePath(page, tempObject, &tempdrawParams,parentMatrix,isUsePreAlpha,preAlpha);
            continue;
        } else if ( (compositeObj = dynamic_cast<FZZOFDCompositeObject*>(*PageBlockType_iter)) != NULL) {
          
            addDrawParams(tempdrawParams, compositeObj->getDrawParam_String()) ;
            writeComposite( pageIndex,compositeObj, &tempdrawParams,parentMatrix);
            continue;
        } else if ( (layerObj = dynamic_cast<FZZOFDLayer*>(*PageBlockType_iter)) != NULL) {
            
            addDrawParams(tempdrawParams, layerObj->getDrawParam_String()) ;
            writeContent( pageIndex,layerObj, &tempdrawParams,parentMatrix,false,0xFF);
            continue;
        } else if ( ( pageBlockObj = dynamic_cast<FZZOFDPageBlock*>(*PageBlockType_iter) )  != NULL) {
            
            writeContent( pageIndex,pageBlockObj, &tempdrawParams,parentMatrix,false,0xFF);
            continue;
        }
        
    }
    //DLOG("writeContent....for....end");
    //DLOG("writeContent........end");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFindKeyWord::addDrawParams(vector<FZZOFDDrawParam*>& drawParams, const string& refID)
{

    if ( !refID.empty() ) {
        FZZOFDDrawParam* ctDrawParam = m_reader->getDrawParam(refID);
        if (ctDrawParam != NULL) {
            drawParams.push_back(ctDrawParam);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFindKeyWord::writeComposite(int pageIndex,FZZOFDCompositeObject* compositeObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix)
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
    //平移
    if (!strboundary.empty()) {
        double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
        ST_Box_ToDouble(strboundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
        matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
        
    }
    
    matrix.postConcat(parentMatrix);
    writeContent(pageIndex,vectorG->getContent(), drawParams, matrix,alpha != 255,alpha);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDFindKeyWord::writeText(int pageIndex,FZZOFDTextObject* textObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix)
{
    //DLOG("writeText........begin");
    if ( textObject == NULL ) {
        return;
    }
    
    vector<FZZOFDTextCode*> * textCodes = textObject->getTextCodeList();
    if ( textCodes == NULL ) {
        return;
    }
    
    vector<string> m_KeyWords;
    
    string strboundary = textObject->getBoundary();


    double tempfontsize = textObject->getSize();
    
    vector<double> ctm;
    textObject->getCTM(ctm);
    
    
    double hscale = textObject->getHScale();
    FZZMatrix matrix;
    FZZMatrix ctmMatrix;
    if ( ctm.size() >= 6 ) {
        ctmMatrix.setAll(ctm[0], ctm[2], ctm[4], ctm[1], ctm[3], ctm[5]);
    }
    
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
        string content = textCode->getContent();
        if ( content.empty() ) {
            continue;
        }
#ifdef _MSC_VER 
        content = FZZConst::Utf8toGB2312(content);
#endif
        content = FZZConst::replace_all(content, "\n", "");
        allText = allText + content;

        FZZString tempstcontent = content;
        int tempcontentlen = tempstcontent.length();
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
        
        int maxlen = (int)(deltaX.size() > deltaY.size() ? deltaX.size() : deltaY.size());
        if ( maxlen < tempcontentlen-1 ) {
            maxlen = tempcontentlen-1;
        }
        vector<double>::iterator delX_itr = deltaX.begin();
        vector<double>::iterator delY_itr = deltaY.begin();
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
        if ( textCode->getX() != 0 ) {
            previousX = textCode->getX();
        }
        if ( textCode->getY() != 0 ) {
            previousY = textCode->getY();
        }
        
    }//for (textCode_iter = textCodes->begin(); textCode_iter != textCodes->end(); textCode_iter++)
    
    FZZString stcontent = allText;
    int len = stcontent.length();
    FZZOFDCGTransform* ct_CGTransForm = NULL;
    int offset = 0;
    string itemchar = "";
    int delchar = 0;
    if ( len > 0 ) {
        while (offset < len) {
            itemchar = stcontent[offset];
            m_KeyWords.push_back(itemchar);
            offset++;
        }//while (offset < len)
    } else if ( tsfMap != NULL && tsfMap->size() > 0 && (*tsfMap)[0] != NULL && (*tsfMap)[0]->getGlyphs() != NULL && getGlyphsSize((*tsfMap)[0]->getGlyphs()) > 0  ) {
           

        FZZFontCache * tempFont = getFont(textObject);
        bool isBlob = false;
        if ( textObject != NULL ) {
            FZZOFDWeight::TYPE weight = textObject->getWeight();
            
            if ( weight >= FZZOFDWeight::TYPE::W_600 ) {
                isBlob = true;
            }
            
        }
    #ifdef OFDTESTLOG
        DLOG("writeText.......................2");
    #endif

        FZZFontCache* defaultFont = FZZConst::g_FZSystemFontList.addDefaultFont();

        
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
                itemchar = stcontent[(int)(gid_itr-gylphids.begin())];
                m_KeyWords.push_back(itemchar);
            } else { //if ( *gid_itr == 0 )
                FzUnichar charforGlyph = -1;
                #ifndef FONTCACHE
                    charforGlyph = tempFont->GlyphToUnichar(*gid_itr);
                #else
                    if ( tempFont != NULL ) {
                        charforGlyph = tempFont->GlyphToUnichar(*gid_itr);
                        if ( charforGlyph == -1 && defaultFont != NULL ) {
                            charforGlyph = defaultFont->GlyphToUnichar(*gid_itr);
                        }
                    }
                #endif
                
                uint32_t tempuint32 = 0;
                unsigned char * bytes = (unsigned char *)(&tempuint32);

                bytes[0] = (unsigned char)(0xff&charforGlyph);
                bytes[1] = (unsigned char)((0xff00&charforGlyph)>>8);
                bytes[2] = (unsigned char)((0xff0000&charforGlyph)>>16);
                bytes[3] = (unsigned char)((0xff000000&charforGlyph)>>24);

                  
                string utf8str = FZZConst::Utf32LEToUtf8(tempuint32);
#ifdef _MSC_VER 
                utf8str = FZZConst::Utf8toGB2312(utf8str);
#endif
                //FZZGenFont genfont;
                //string utf8str = genfont.WstringToString(tempwstr);
                
                m_KeyWords.push_back(utf8str);
            }//if ( *gid_itr == 0 )
        }//for ( gid_itr = gylphids.begin(); gid_itr != gylphids.end(); gid_itr++ )
    }
//    } else { //if ( tsfMap != NULL && tsfMap->size() > 0 && (*tsfMap)[0] != NULL && (*tsfMap)[0]->getGlyphs() != NULL && (*tsfMap)[0]->getGlyphs()->size() > 0  )
//        while (offset < len) {
//            itemchar = stcontent[offset];
//            m_KeyWords.push_back(itemchar);
//            offset++;
//        }//while (offset < len)
//    }//if ( tsfMap != NULL && tsfMap->size() > 0 && (*tsfMap)[0] != NULL && (*tsfMap)[0]->getGlyphs() != NULL && (*tsfMap)[0]->getGlyphs()->size() > 0  )
    
    
    vector<string>::const_iterator keyword_itr;
    vector<string>::const_iterator keyword_itr_begin = m_KeyWords.begin();
    vector<double>::iterator movex_itr = moveX.begin();
    vector<double>::iterator movey_itr = moveY.begin();
    if (m_KeyWords.size() > 0 && moveX.size() > 0 && moveY.size() > 0) {
        for (keyword_itr = m_KeyWords.begin(); keyword_itr != m_KeyWords.end(); keyword_itr++) {
            matrix.reset();
            //if ( tempfontsize <= 1 ) {
            if (hscale != 0) {
                matrix.postScale(hscale, 1);

            }
            matrix.postScale(tempfontsize, tempfontsize);
            //}

            matrix.postTranslate(*(movex_itr + (keyword_itr - keyword_itr_begin)), *(movey_itr + (keyword_itr - keyword_itr_begin)));
            if (ctm.size() >= 6) {

                matrix.postConcat(ctmMatrix);
            }

            if (!strboundary.empty()) {
                double BoundaryBox_x = 0; double BoundaryBox_y = 0; double BoundaryBox_width = 0; double BoundaryBox_height = 0;
                ST_Box_ToDouble(strboundary, BoundaryBox_x, BoundaryBox_y, BoundaryBox_width, BoundaryBox_height);
                
                //matrix.postTranslate(*(movex_itr+(skpath_itr-tbDrawChars.begin())), *(movey_itr+(skpath_itr-tbDrawChars.begin())));
                matrix.postTranslate(BoundaryBox_x, BoundaryBox_y);
            }


            matrix.postConcat(parentMatrix);
            string strtemp = *keyword_itr;//(*(keyword_itr_begin + (keyword_itr - keyword_itr_begin)));
            if ( !strtemp.empty() ) {
                transform(strtemp.begin(), strtemp.end(), strtemp.begin(), ::tolower);

                m_GKeyWordList.push_back(new FZZKeyWordInfo(pageIndex, strtemp,matrix.getTranslateX(),matrix.getTranslateY()- matrix.getScaleY(), matrix.getScaleX(), matrix.getScaleY()));
            }

            


        }

    }

    
    
    
    //DLOG("writeText........end");
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontCache* FZZOFDFindKeyWord::getFont(FZZOFDTextObject* textObject)
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
void FZZOFDFindKeyWord::parseDelta(vector<string> & array,vector<double> & arr)
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
size_t FZZOFDFindKeyWord::getGlyphsSize(FZZOFDGlyphs * ofdglyphs)
{
    if ( ofdglyphs == NULL ) return 0;
    vector<string> glyphs;
    ofdglyphs->getValue(glyphs);
    return glyphs.size();
}
//-----------------------------------------------------------------------------------------------------------------
