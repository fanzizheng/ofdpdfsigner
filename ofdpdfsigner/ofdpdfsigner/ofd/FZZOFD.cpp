//
//  Created by zizheng fan on 2024/02/23.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/FZZOFD.h"
#include "basic/FZZZipTracks.h"
#include "gm/ses/parse/FZZSESVersionHolder.h"
#include "gm/ses/parse/FZZVersionParser.h"
#include "ofd/ofdxmlelement/basicStructure/res/FZZOFDFonts.h"
#include "converter/utils/FZZCommonUtil.h"
#include "basic/FZZString.h"

#include "converter/utils/FZZImageUtil.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFD**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFD::FZZOFD() : m_ColorSpace_default(NULL),m_maxUnitID(0)
{
    //DLOG("FZZOFD()");
    FZZConst::addClassCount("FZZOFD");
    m_workDir = FZZConst::createuuid();
    m_OFDDir = new FZZOFDDir(&m_OFDFilesContainer,m_workDir);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFD::~FZZOFD()
{
    //DLOG("~FZZOFD()");
    FZZConst::delClassCount("FZZOFD");
    clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::clear()
{
    if ( m_OFDDir != NULL ) {
        delete m_OFDDir;
        m_OFDDir = NULL;
    }
    
    vector<FZZStampAnnotEntity*>::const_iterator saeitr;
    for( saeitr = m_StampAnnotEntityList.begin(); saeitr != m_StampAnnotEntityList.end(); saeitr++ ) {
        FZZStampAnnotEntity * temp = *saeitr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_StampAnnotEntityList.clear();
    
    vector<TPageInfo*>::const_iterator tpi_itr;
    for( tpi_itr = m_PageInfoList.begin(); tpi_itr != m_PageInfoList.end(); tpi_itr++ ) {
        TPageInfo * temp = *tpi_itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_PageInfoList.clear();
    
    m_colorSpaceMap.clear();
    m_drawParamMap.clear();
    m_fontMap.clear();
    m_multiMediaMap.clear();
    m_compositeGraphicUnitMap.clear();
    m_cache.clear();
    
//    vector<TAnnotion*>::const_iterator annot_itr;
//    for( annot_itr = m_AnnotionList.begin(); annot_itr != m_AnnotionList.end(); annot_itr++ ) {
//        TAnnotion * temp = *annot_itr;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
//    m_AnnotionList.clear();
    
    m_ColorSpace_default = NULL;
    m_maxUnitID.set(0);
    m_FileData.clear();
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFD::Read(FZZBytes & indata)
{
    return Read(indata.getData(), indata.getLen());
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFD::Read(const unsigned char * const ofdData,size_t ofdDatalen)
{
    clear();
    
    m_FileData.setData(ofdData, ofdDatalen);
    
    m_workDir = FZZConst::createuuid();
    if ( m_workDir.empty() ) {
        return false;
    }
    FZZZipTracks zipTracks;
    if (!zipTracks.UnZip(m_workDir,ofdData, ofdDatalen,&m_OFDFilesContainer)) {
        return false;
    }

    if ( m_OFDDir != NULL ) {
        delete m_OFDDir;
        m_OFDDir = NULL;
    }
    m_OFDDir = new FZZOFDDir(&m_OFDFilesContainer,m_workDir);
    
    FZZOFDDocumentXML* documentXML = getDocumentXML_default();
    if ( documentXML != NULL ) {

        FZZOFDCommonData * commonData = documentXML->getCommonData();
        if ( commonData != NULL )  {
            FZZOFDMaxUnitID * maxUnitID = commonData->getMaxUnitID();
            if ( maxUnitID != NULL )  {
                m_maxUnitID.set(maxUnitID->getLongValue());
            }
        }
    }
    //--------test begin --------------------
    //FZZOFDXML* ofdxml = m_OFDDir->getOFDXML();
    //vector<FZZOFDDocBody*>*  aab = ofdxml->getDocBodys();

    //--------test end ----------------------
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes * FZZOFD::getFileData()
{
    return &m_FileData;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::FlushAll()
{
    if ( m_OFDDir == NULL ) {
        return;
    }
    m_OFDDir->FlushAll();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::Close(FZZBytes & outdata)
{
    zip_mem(outdata);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDXML* FZZOFD::getOFDXML()
{
    FZZOFDXML* ret = NULL;
    if ( m_OFDDir != NULL ) {
        ret = m_OFDDir->getOFDXML();
    }
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::zip_mem(FZZBytes & outData)
{
    FZZZipTracks zipTracks;
#ifdef MINIZIPNG
    zipTracks.CreateZip_mem();
    addZip(&zipTracks, m_workDir);
    outData = zipTracks.CloseZip_mem();
#else

#endif
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::addZip(FZZZipTracks* zipTracks,string rootpath)
{
    vector<string> fileNames;
    vector<string> dirNames;
    string tempdir;
    bool isfind = false;
    m_OFDFilesContainer.getFilesName(rootpath, fileNames);
    for ( int i = 0; i < fileNames.size();i++ ) {
        isfind = false;
        size_t indexOf = fileNames[i].find_last_of("/");
        if (indexOf != string::npos) {
            tempdir = fileNames[i].substr(0, indexOf + 1);
        } else {
            FZZBytes * tempdata = m_OFDFilesContainer.getFileData(rootpath, fileNames[i]);
            zipTracks->AddFileToZip(fileNames[i].c_str(), tempdata->getData(), tempdata->getLen());
            continue;
        }
        for (int z =0; z < dirNames.size(); z++) {
            if ( dirNames[z] == tempdir ) {
                isfind = true;
                break;
            }
        }
        if (!isfind) {
            dirNames.push_back(tempdir);
            zipTracks->AddFileToZip(tempdir.c_str(), NULL, 0);
        }
        
        FZZBytes * tempdata = m_OFDFilesContainer.getFileData(rootpath, fileNames[i]);
        zipTracks->AddFileToZip(fileNames[i].c_str(), tempdata->getData(), tempdata->getLen());
    }

}
//-----------------------------------------------------------------------------------------------------------------
long FZZOFD::getPageObjectId(int pageNum)
{
//    FZZOFDDocumentXML* documentXML = getDocumentXML_default();
//    if ( documentXML == NULL ) {
//        return 0;
//    }
//    FZZOFDPages * ofdPages = documentXML->getPages();
//    if ( ofdPages == NULL ) {
//        return 0;
//    }
//    int index = pageNum - 1;
//    if ( index < 0 ) {
//        return 0;
//    }
//    vector<FZZOFDPageElem*> * ofdPageElemList = ofdPages->getPageList();
//    if ( ofdPageElemList == NULL || ofdPageElemList-> size() <= 0 || index >= ofdPageElemList->size() ) {
//        return 0;
//    }
//    FZZOFDPageElem * ofdPageElem = *(ofdPageElemList->begin() + index);
//    if ( ofdPageElem == NULL ) {
//        return 0;
//    }
//    return ofdPageElem->getID_long();
    int index = pageNum - 1;
    if ( index < 0 ) {
        return 0;
    }
    
    getPageInfoList();
    
    if ( m_PageInfoList.size() <= 0 || index >= m_PageInfoList.size() ) {
        return 0;
    }
        
    TPageInfo * pageInfo = *(m_PageInfoList.begin() + index);
    if ( pageInfo == NULL ) {
        return 0;
    }
    return strtol(pageInfo->id.c_str(),NULL,10);
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentXML* FZZOFD::getDocumentXML_default()
{
    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return NULL;
    }
    return docDir->getDocumentXML();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocDir * FZZOFD::getDocDir_default()
{
    if ( m_OFDDir == NULL ) {
        return NULL;
    }
    return m_OFDDir->getDocDir_default();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDResDir * FZZOFD::getResDir_default()
{
    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return NULL;
    }
    return docDir->getResDir();
}
//-----------------------------------------------------------------------------------------------------------------
int FZZOFD::getPageCount()
{
    FZZOFDDocumentXML* documentXML = getDocumentXML_default();
    if ( documentXML == NULL ) {
        return 0;
    }
    FZZOFDPages * ofdPages = documentXML->getPages();
    if ( ofdPages == NULL ) {
        return 0;
    }
    vector<FZZOFDPageElem*> * ofdPageElemList = ofdPages->getPageList();
    if ( ofdPageElemList == NULL || ofdPageElemList->size() <= 0 ) {
        return 0;
    }
    return (int)(ofdPageElemList->size());
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageXML* FZZOFD::getPage(int pageNum)
{
    if ( m_OFDDir == NULL ) {
        return NULL;
    }
    FZZOFDDocDir * docDir = m_OFDDir->getDocDir_default();
    if ( docDir == NULL ) {
        return NULL;
    }
    int index = pageNum - 1;
    vector<FZZOFDPageDir *> *  pageDirList = docDir->getPageDirList();
    if ( pageDirList == NULL || pageDirList->size() <= 0 || index >= pageDirList->size()) {
        return NULL;
    }
    FZZOFDPageDir * pageDir = *(pageDirList->begin() + index);
    if ( pageDir == NULL ) {
        return NULL;
    }
    return pageDir->getPageXML();
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFD::getPageSize(FZZOFDPageXML* page,/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    string retBox = "";
    if (page == NULL) {
        return retBox;
    }
    
    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return retBox;
    }
    
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    FZZOFDPageArea * pageArea = page->getPageArea();
    if ( pageArea != NULL ) {
        retBox = pageArea->getBox();
        ST_Box_ToDouble(retBox, x,y,width,height);
    }
    if ( retBox.empty() ) {
        pageArea = NULL;
    
        vector<FZZOFDTemplate*>* itemList = page->getTemplateList();
        if ( itemList != NULL ) {
            for(int i = 0; i < itemList->size(); i++) {
                FZZOFDTemplate* item = (*itemList)[i];
                if ( item == NULL ) continue;
              
                
                FZZOFDTemplateDir * tplDir = docDir->getTemplateDir(item->getTemplateID());
                if ( tplDir == NULL ) continue;
                FZZOFDPageXML* tplPageXML = tplDir->getPageXML();
                if ( tplPageXML == NULL ) continue;
                
                
                FZZOFDPageArea* tplArea = tplPageXML->getPageArea();
                
                Type type = item->getZOrder();
                
                if (tplArea != NULL && type > Type::Background ) {
                    pageArea = tplArea;
                }
            }
        }
        
    
        if (pageArea == NULL) {
            FZZOFDDocumentXML* documentXML = getDocumentXML_default();
            if ( documentXML == NULL ) return retBox;
      
            FZZOFDCommonData * commonData = documentXML->getCommonData();
            if ( commonData == NULL ) return retBox;
            pageArea = commonData->getPageArea();
        }
        
        if ( pageArea != NULL ) {
            retBox = pageArea->getBox();
            ST_Box_ToDouble(retBox, x,y,width,height);
        }
    }
    return retBox;
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZStampAnnotEntity*> * FZZOFD::getStampAnnots()
{
    if ( m_StampAnnotEntityList.size() <= 0 && m_OFDDir != NULL ) {
        FZZOFDDocDir * docDir = m_OFDDir->getDocDir_default();
        if ( docDir == NULL ) return &m_StampAnnotEntityList;
        
        FZZOFDSignsDir * signsDir = docDir->getSignsDir();
        if ( signsDir == NULL ) return &m_StampAnnotEntityList;
        
        vector<FZZOFDSignDir *> * signDirList = signsDir->getSignDirList();
        if ( signDirList == NULL ) return &m_StampAnnotEntityList;
        
        vector<FZZOFDSignDir*>::const_iterator SignDir_it;
        for( SignDir_it = signDirList->begin(); SignDir_it != signDirList->end(); SignDir_it++ ) {
            FZZOFDSignDir* tempSignDir = *SignDir_it;
            if ( tempSignDir == NULL )  continue;
            FZZOFDSignatureXML* signatureXML = tempSignDir->getSignatureXML();
            if ( signatureXML == NULL ) continue;
            FZZOFDSignedValue * signedValue = signatureXML->getSignedValue();
            if ( signedValue == NULL ) {
                continue;
            }
            string signedValueFilePath = signedValue->getValue();
            signedValueFilePath = FZZConst::replace_all(signedValueFilePath,"\\","/");
            if ( signedValueFilePath[0] == '/' ) {
                signedValueFilePath = signedValueFilePath.substr(1);
            }
            
            FZZBytes * signedValueFile = m_OFDDir->getResFile(signedValueFilePath);
            if ( signedValueFile == NULL || signedValueFile->getLen() < 10 ) {
                continue;
            }
         
            m_StampAnnotEntityList.push_back(new FZZStampAnnotEntity(tempSignDir->getSignID(),signedValueFile, signatureXML->getSignedInfo()));
        }
    }
    return &m_StampAnnotEntityList;
}
//-----------------------------------------------------------------------------------------------------------------
vector<TPageInfo*> * FZZOFD::getPageInfoList()
{
    if ( m_PageInfoList.size() > 0 ) {
        return &m_PageInfoList;
    }
    
    
    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return &m_PageInfoList;
    }
    vector<FZZOFDPageDir *> * pageDirList = docDir->getPageDirList();
    if ( pageDirList == NULL || pageDirList-> size() <= 0  ) {
        return &m_PageInfoList;
    }
    
    vector<FZZOFDPageDir*>::const_iterator itr;
    for (itr = pageDirList->begin(); itr != pageDirList->end(); itr++) {
        FZZOFDPageDir* pageDir = *itr;
        if ( pageDir != NULL ) {
            
            TPageInfo * pageInfo = new TPageInfo();
            if ( pageInfo == NULL ) {
                continue;
            }
            pageInfo->pageNum = (int)(itr - pageDirList->begin() + 1);
            pageInfo->id = pageDir->getPageId();
            pageInfo->pageXML = pageDir->getPageXML();
            if ( pageInfo->pageXML == NULL ) {
                delete pageInfo;
                continue;
            }
            getPageSize(pageInfo->pageXML,pageInfo->pageSize_x,pageInfo->pageSize_y,pageInfo->pageSize_width,pageInfo->pageSize_height);
            pageInfo->pagePath = pageDir->getPath();
            pageInfo->pageDir = pageDir;
            
            vector<FZZOFDTemplate*>* templateList = pageInfo->pageXML->getTemplateList();
            if ( templateList != NULL && templateList->size() > 0 ) {
                vector<FZZOFDTemplate*>::const_iterator t_itr;
                for (t_itr = templateList->begin(); t_itr != templateList->end(); t_itr++) {
                    FZZOFDTemplate* ofdTemplate = *t_itr;
                    if ( ofdTemplate == NULL ) {
                        continue;
                    }
                    if ( ofdTemplate->getZOrder() != Type::Background ) {
                        continue;
                    }
                    
                    addLayer(docDir,ofdTemplate->getTemplateID(),pageInfo);
                }
              
                for (t_itr = templateList->begin(); t_itr != templateList->end(); t_itr++) {
                    FZZOFDTemplate* ofdTemplate = *t_itr;
                    if ( ofdTemplate == NULL ) {
                        continue;
                    }
                    if ( ofdTemplate->getZOrder() != Type::Body ) {
                        continue;
                    }
                    
                    addLayer(docDir,ofdTemplate->getTemplateID(),pageInfo);
                }
                
                addLayer(pageInfo->pageXML,pageInfo);
                
                for (t_itr = templateList->begin(); t_itr != templateList->end(); t_itr++) {
                    FZZOFDTemplate* ofdTemplate = *t_itr;
                    if ( ofdTemplate == NULL ) {
                        continue;
                    }
                    if ( ofdTemplate->getZOrder() != Type::Foreground ) {
                        continue;
                    }
                    
                    addLayer(docDir,ofdTemplate->getTemplateID(),pageInfo);
                }
                
                
            } else {
                addLayer(pageInfo->pageXML,pageInfo);
            }
        
            m_PageInfoList.push_back(pageInfo);
        }
    }
    
    return &m_PageInfoList;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::addLayer(FZZOFDDocDir * docDir,string TplID,TPageInfo * pageInfo)
{
    if ( docDir == NULL || pageInfo == NULL || TplID.empty() ) {
        return;
    }
    
    FZZOFDTemplateDir * templateDir = docDir->getTemplateDir(TplID);
    if ( templateDir == NULL ) {
        return;
    }
    FZZOFDPageXML * templatePageXML = templateDir->getPageXML();
    addLayer(templatePageXML,pageInfo);
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::addLayer(FZZOFDPageXML * pageXML,TPageInfo * pageInfo)
{
    
    if ( pageXML == NULL ) {
        return;
    }
    FZZOFDContent * ofdContent = pageXML->getContent();
    if ( ofdContent == NULL ) {
        return;
    }
    vector<FZZOFDLayer*>* layerList = ofdContent->getLayerList();
    if ( layerList == NULL ) {
        return;
    }
    vector<FZZOFDLayer*>::const_iterator iter_layer;
    for (iter_layer = layerList->begin(); iter_layer != layerList->end(); iter_layer++) {
        FZZOFDLayer* ofdLayer = *iter_layer;
        if ( ofdLayer == NULL ) {
            continue;
        }
        pageInfo->layerList.push_back(ofdLayer);
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawParam * FZZOFD::getDrawParam(string id)
{
    
    getAllResource();
    return m_drawParamMap[id];
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDColorSpace * FZZOFD::getColorSpace(string id)
{
    getAllResource();
    if ( id.empty() ) {
        FZZOFDDocumentXML*  documentXML = FZZOFD::getDocumentXML_default();
        if ( documentXML != NULL ) {
            FZZOFDCommonData * commonData = documentXML->getCommonData();
            if ( commonData != NULL ) {
                FZZOFDDefaultCS * defaultCS = commonData->getDefaultCS();
                if ( defaultCS != NULL ) {
                    id = defaultCS->getValue();
                }
            }
        }
    }
    if ( id.empty() ) {
        return NULL;
    }
    
    return m_colorSpaceMap[id];
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDFont * FZZOFD::getFont(string id)
{
    getAllResource();
    return m_fontMap[id];
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMultiMedia * FZZOFD::getMultiMedia(string id)
{
    getAllResource();
    return m_multiMediaMap[id];
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDVectorG * FZZOFD::getCompositeGraphicUnit(string id)
{
    getAllResource();
    return m_compositeGraphicUnitMap[id];
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::getAllResource()
{
    if ( m_drawParamMap.size() > 0 || m_colorSpaceMap.size() > 0 || m_fontMap.size() > 0 || m_multiMediaMap.size() > 0 || m_compositeGraphicUnitMap.size() > 0) {
        return;
    }
    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return;
    }
    loadRes(docDir->getPublicResXML());
    loadRes(docDir->getDocumentResXML());
    
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::loadRes(FZZOFDResXML * resXML)
{
    if ( resXML == NULL ) {
        return;
    }
    vector<FZZOFDBaseRes*>* ofdBaseResList =  resXML->getResourceList();
    
    FZZOFDFonts * ofdFonts = NULL;
    FZZOFDColorSpaces * ofdColorSpacs = NULL;
    FZZOFDDrawParams * ofdDrawParams = NULL;
    FZZOFDMultiMedias * ofdMultiMeedias = NULL;
    FZZOFDCompositeGraphicUnits * ofdCompositeGraphicUnits = NULL;
    
    vector<FZZOFDBaseRes*>::const_iterator itr;
    for( itr = ofdBaseResList->begin(); itr != ofdBaseResList->end(); itr++ ) {
        FZZOFDBaseRes * temp = *itr;
        if ( temp != NULL ) {
            ofdFonts = NULL;
            ofdColorSpacs = NULL;
            ofdDrawParams = NULL;
            ofdMultiMeedias = NULL;
            ofdCompositeGraphicUnits = NULL;
            
            if ( ( ofdFonts = dynamic_cast<FZZOFDFonts*>(temp) ) != NULL ) {
                vector<FZZOFDFont*>* FontList = ofdFonts->getFontList();
                if ( FontList == NULL ) {
                    continue;
                }
                vector<FZZOFDFont*>::const_iterator font_itr;
                for( font_itr = FontList->begin(); font_itr != FontList->end(); font_itr++ ) {
                    FZZOFDFont * font = *font_itr;
                    if ( font == NULL ) {
                        continue;
                    }
                    m_fontMap[font->getID()] = font;
                }
            } else if ( ( ofdColorSpacs = dynamic_cast<FZZOFDColorSpaces*>(temp) ) != NULL ) {
                vector<FZZOFDColorSpace*>* ColorSpaceList = ofdColorSpacs->getColorSpaceList();
                if ( ColorSpaceList == NULL ) {
                    continue;
                }
                vector<FZZOFDColorSpace*>::const_iterator colorspace_itr;
                for( colorspace_itr = ColorSpaceList->begin(); colorspace_itr != ColorSpaceList->end(); colorspace_itr++ ) {
                    FZZOFDColorSpace * colorSpace = *colorspace_itr;
                    if ( colorSpace == NULL ) {
                        continue;
                    }
                    m_colorSpaceMap[colorSpace->getID()] = colorSpace;
                }
                
            } else if ( ( ofdDrawParams = dynamic_cast<FZZOFDDrawParams*>(temp) ) != NULL ) {
                vector<FZZOFDDrawParam*> * DrawParamList = ofdDrawParams->getDrawParamList();
                if ( DrawParamList == NULL ) {
                    continue;
                }
                vector<FZZOFDDrawParam*>::const_iterator drawParam_itr;
                for( drawParam_itr = DrawParamList->begin(); drawParam_itr != DrawParamList->end(); drawParam_itr++ ) {
                    FZZOFDDrawParam * drawParam = *drawParam_itr;
                    if ( drawParam == NULL ) {
                        continue;
                    }
                    m_drawParamMap[drawParam->getID()] = drawParam;
                }
            } else if ( ( ofdMultiMeedias = dynamic_cast<FZZOFDMultiMedias*>(temp) ) != NULL ) {
                vector<FZZOFDMultiMedia*> * MultiMediaList = ofdMultiMeedias->getMultiMediaList();
                if ( MultiMediaList == NULL ) {
                    continue;
                }
                vector<FZZOFDMultiMedia*>::const_iterator MultiMedia_itr;
                for( MultiMedia_itr = MultiMediaList->begin(); MultiMedia_itr != MultiMediaList->end(); MultiMedia_itr++ ) {
                    FZZOFDMultiMedia * MultiMedia = *MultiMedia_itr;
                    if ( MultiMedia == NULL ) {
                        continue;
                    }
                    m_multiMediaMap[MultiMedia->getID()] = MultiMedia;
                }
            } else if ( ( ofdCompositeGraphicUnits = dynamic_cast<FZZOFDCompositeGraphicUnits*>(temp) ) != NULL ) {
                vector<FZZOFDVectorG*> * VectorGList = ofdCompositeGraphicUnits->getVectorGList();
                
                if ( VectorGList == NULL ) {
                    continue;
                }
                vector<FZZOFDVectorG*>::const_iterator VectorG_itr;
                for( VectorG_itr = VectorGList->begin(); VectorG_itr != VectorGList->end(); VectorG_itr++ ) {
                    FZZOFDVectorG * VectorG = *VectorG_itr;
                    if ( VectorG == NULL ) {
                        continue;
                    }
                    m_compositeGraphicUnitMap[VectorG->getID()] = VectorG;
                }
            }
            
            
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDPageDir *> * FZZOFD::getAnnotationList()
{
    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return NULL;
    }
    
    FZZOFDAnnotsDir * annotsDir = docDir->getAnnotsDir();
    if ( annotsDir == NULL ) {
        return NULL;
    }
    
    return annotsDir->getPageDirList();
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZOFD::getImage(FZZOFDImageObject * imageObject)
{
    FZZBytes image;
    if ( imageObject == NULL ) {
        return image;
    }
    
    image = getImage(imageObject->getResourceID());
    string strImageMask = imageObject->getImageMask();
    if (!strImageMask.empty()) {
        FZZBytes image_mask = getImage(strImageMask);
        if (image_mask.getLen() == 0) {

            FZZImageUtil fzImageUtil;
            fzImageUtil.renderMask(image,image_mask);
            image = fzImageUtil.PngEncode();

        }
    }
    return image;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes FZZOFD::getImage(string refID)
{
    FZZBytes imgPath;
    FZZOFDMultiMedia* multiMedia = getMultiMedia(refID);
    if (multiMedia == NULL) return imgPath;
    
    if (FZZOFDMediaType::TYPE::TYPE_Image != multiMedia->getType()) return imgPath;

    FZZOFDFileLoc * ofdFileLoc = multiMedia->getMediaFile();
    if (ofdFileLoc == NULL) return imgPath;
    
    FZZOFDResDir * resDir = getResDir_default();

    if ( resDir == NULL ) return imgPath;
    
    string filename = ofdFileLoc->getValue();
    filename = FZZConst::replace_all(filename,"\\","/");
    //filename = FZZConst::replace_all(filename,"\n","");
//    if ( filename[0] == '/' ) {
//        filename = filename.substr(1);
//    }
    size_t pos = filename.find_last_of("/");
    if ( pos != string::npos ) {
        filename = filename.substr(pos+1);
    }
    
    FZZBytes * tempBytes = resDir->getResFile(filename);
    if ( tempBytes == NULL ) {
        return imgPath;
    }
    
    imgPath = *tempBytes;
    
    
    size_t indexOf = filename.find_last_of('.');
    if (indexOf != string::npos) {
        string extName = filename.substr(indexOf);
        transform(extName.begin(), extName.end(), extName.begin(), ::tolower);
        if ( extName == ".jb2" || extName == ".gbig2" ) {

            FZZImageUtil fzImageUtil;
            fzImageUtil.LoadImage(imgPath);
            imgPath = fzImageUtil.PngEncode();

        }
    }
    
    return imgPath;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocDir* FZZOFD::setDocDir_default()
{
    FZZOFDDocDir* docDir = NULL;
    if ( m_OFDDir == NULL ) {
        if ( m_workDir.empty() ) {
            m_workDir = FZZConst::createuuid();
        }
        m_OFDDir = new FZZOFDDir(&m_OFDFilesContainer,m_workDir);
    }
    if ( m_OFDDir != NULL ) {
        docDir = m_OFDDir->setDocDir_default();
    }
    
    return docDir;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageXML * FZZOFD::addPage()
{
    FZZOFDPageXML * page = NULL;
    FZZOFDDocDir* docDefault = setDocDir_default();
    if ( docDefault == NULL ) {
        return page;
    }
    
    FZZOFDDocumentXML* doc = docDefault->getDocumentXML();
    if (doc == NULL) {
        return page;
    }
    
    FZZOFDPages * pages = doc->setPages();
    if (pages == NULL) {
        return page;
    }
    
    FZZOFDPageDir * pageDir = docDefault->addPageDir();
    if (pageDir == NULL) {
        return page;
    }
    
    page = pageDir->setPageXML();
    if (page == NULL) {
        return page;
    }
    
    FZZOFDPageElem * pageElem = pages->addPage();
    pageElem->setID(m_maxUnitID.incrementAndGet());
    pageElem->setBaseLoc(docDefault->getFileName_RelativePath(pageDir->getPath()+FZZOFDPAGEXML_FILENAME));
    
    return  page;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::addFontFile(string fontFileName,FZZBytes * fontData)
{
    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return;
    }
    
    FZZOFDResDir * resDir = getResDir_default();
    if ( resDir == NULL ) {
        return;
    }
    
    FZZOFDPublicResXML* publicResXML = docDir->setPublicResXML();
    if ( publicResXML == NULL ) {
        return;
    }
    
    FZZOFDFonts* ofdFonts = publicResXML->setFonts();
    if ( ofdFonts == NULL ) {
        return;
    }
    FZZOFDFont * ofdFont = ofdFonts->addFont();
    if ( ofdFont == NULL ) {
        return;
    }
    ofdFont->setID(m_maxUnitID.incrementAndGet());
    ofdFont->setFontName(fontFileName);
    
    fontFileName = fontFileName+".ttf";
    resDir->FlushResFile(fontFileName, fontData);
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFD::addFileAttachment(FZZBytes * fileData,string name,string format,string * AttachmentID/*out*/)
{
    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return false;
    }
    FZZOFDDocumentXML* documentXML = docDir->getDocumentXML();
    if ( documentXML == NULL ) {
        return false;
    }
    
    FZZOFDAttachsDir * attachsDir = docDir->getAttachsDir();
    if ( attachsDir == NULL ) {
        return false;
    }
    
    FZZOFDAttachmentsXML* attachmentsXML = attachsDir->setAttachmentsXML();
    if ( attachmentsXML == NULL ) {
        return false;
    }
    
    FZZOFDDocument_Attachments * document_Attachments = documentXML->setAttachments();
    if ( document_Attachments == NULL ) {
        return false;
    }
    
    FZZOFDAttachment* ofdAttachment = attachmentsXML->addAttachment();
    if ( ofdAttachment == NULL ) {
        return false;
    }
    
    FZZOFDFileLoc * fileLoc = ofdAttachment->setFileLoc();
    if ( fileLoc == NULL ) {
        return false;
    }
    
    string strAttachmentID = FZZConst::fmt(m_maxUnitID.incrementAndGet());
    ofdAttachment->setID(strAttachmentID);
    time_t now;
    time(&now);
    ofdAttachment->setCreationDate(FZZConst::format_time_YYYY_MM_DD_hh_mm_ss(now));
    ofdAttachment->setSize(fileData->getLen());
    ofdAttachment->setFormat(format);
    
    
    string strFileName = name+"."+format;
    if ( attachsDir->existsFile(strFileName) ) {
        string tempName = name+FZZConst::fmt(attachsDir->getFileNameIndex());
        strFileName = tempName+"."+format;
        ofdAttachment->setName(tempName);
    } else {
        ofdAttachment->setName(name);
    }
    fileLoc->setValue(strFileName);
    
    attachsDir->FlushResFile(strFileName, fileData);
    
    document_Attachments->setValue(docDir->getFileName_RelativePath( attachsDir->getPath()+FZZOFDATTACHMENTSXML_FILENAME));
    
    *AttachmentID = strAttachmentID;
    
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageAnnotXML * FZZOFD::addAnnotation(int pageIndex)
{
    FZZOFDPageAnnotXML * pageAnnot = NULL;
    
    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return pageAnnot;
    }
    
    FZZOFDDocumentXML* documentXML = docDir->getDocumentXML();
    if ( documentXML == NULL ) {
        return pageAnnot;
    }
    
    FZZOFDAnnotsDir * annotsDir = docDir->getAnnotsDir();
    if ( annotsDir == NULL ) {
        return pageAnnot;
    }
    
    FZZOFDPageDir * pageDir = annotsDir->getPageDir(FZZConst::fmt(pageIndex));
    if ( pageDir == NULL ) {
        return pageAnnot;
    }
    
    FZZOFDDocument_Annotations * document_Annotations = documentXML->setAnnotations();
    if ( document_Annotations == NULL ) {
        return pageAnnot;
    }
    
    FZZOFDAnnotationsXML* annotationsXML= annotsDir->setAnnotationsXML();
    if ( annotationsXML == NULL ) {
        return pageAnnot;
    }
    
    FZZOFDAnnPage* annPage = annotationsXML->addPage();
    if ( annPage == NULL ) {
        return pageAnnot;
    }
    
    FZZOFDFileLoc * fileLoc = annPage->setFileLoc();
    if ( fileLoc == NULL ) {
        return pageAnnot;
    }

    FZZOFDPages * pagees =  documentXML->getPages();
    if ( pagees == NULL ) {
        return pageAnnot;
    }
    
    vector<FZZOFDPageElem*> * pageElemList = pagees->getPageList();
    if ( pageElemList == NULL || pageIndex >= pageElemList->size()  ) {
        return pageAnnot;
    }
    
    FZZOFDPageElem* pageElem = *(pageElemList->begin()+pageIndex);
    if ( pageElem == NULL ) {
        return pageAnnot;
    }
    
    
    pageAnnot = pageDir->setAnnotationXML();
    if ( pageAnnot == NULL ) {
        return pageAnnot;
    }
    
    annPage->setPageID(pageElem->getID());
    string pageDirPath = pageDir->getPath();
    string annotsDirPath = annotsDir->getPath();
    size_t pos = pageDirPath.find(annotsDirPath);
    if ( pos != string::npos ) {
        pageDirPath = pageDirPath.substr(pos+annotsDirPath.length());
    }
    fileLoc->setValue(pageDirPath+FZZOFDPAGEANNOTXML_FILENAME);
    document_Annotations->setValue(docDir->getFileName_RelativePath(annotsDirPath+FZZOFDANNOTATIONSXML_FILENAME));
    
    return pageAnnot;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDocumentResXML* FZZOFD::getDocumentResXML()
{

    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return NULL;
    }

    return docDir->setDocumentResXML();
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPublicResXML* FZZOFD::getPublicResXML()
{

    FZZOFDDocDir * docDir = getDocDir_default();
    if ( docDir == NULL ) {
        return NULL;
    }

    return docDir->setPublicResXML();
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageBlock* FZZOFD::addPageBlock_Page(FZZOFDLayer* layer)
{
    if ( layer == NULL ) {
        return NULL;
    }
    FZZOFDPageBlock* block = (FZZOFDPageBlock*)layer->addPageBlock(FZZOFDPageBlockType::TYPE::TYPE_PageBlock);
    if ( block != NULL ) {
        block->setID(m_maxUnitID.incrementAndGet());
    }
    return block;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDDrawContext * FZZOFD::newDrawContext(FZZOFDPageBlock* block)
{
    FZZOFDDrawContext * ret = NULL;
    if ( block == NULL ) {
        return ret;
    }
    ret = new FZZOFDDrawContext(this,block,&m_maxUnitID);
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFD::addImageRes(const unsigned char* const imgData,int imgLen,const char * const imageType)
{
    string strID = "";
    FZZOFDDocumentResXML* resMenu = getDocumentResXML();
    if ( resMenu == NULL ) return strID;
    FZZOFDResDir * resDir = getResDir_default();
    if ( resDir == NULL ) return strID;
    
    FZZOFDMultiMedias * ofdMultiMedias = NULL;
    vector<FZZOFDBaseRes*> * BaseResList = resMenu->getResourceList();
    if ( BaseResList != NULL && BaseResList->size() > 0 ) {
        vector<FZZOFDBaseRes*>::const_iterator baseRes_itr;
        for( baseRes_itr = BaseResList->begin(); baseRes_itr != BaseResList->end(); baseRes_itr++ ) {
            FZZOFDBaseRes * tempItem = *baseRes_itr;
            if ( tempItem != NULL ) {
                if ( ( ofdMultiMedias = dynamic_cast<FZZOFDMultiMedias*>(tempItem) ) != NULL ) {
                    break;
                }
            }
        }
    }
    
    
    if (ofdMultiMedias == NULL) {
        ofdMultiMedias = resMenu->addMultiMedias();
        if (ofdMultiMedias == NULL) {
            return strID;
        }
    }
    FZZOFDMultiMedia * multiMedia = ofdMultiMedias->addMultiMedia();
        
    if ( multiMedia == NULL ) return strID;
    FZZOFDFileLoc * fileLoc = multiMedia->setMediaFile();
    if ( fileLoc == NULL ) return strID;
    multiMedia->setType(FZZOFDMediaType::TYPE::TYPE_Image);
    if ( imageType != NULL && strlen(imageType) > 0 ) {
        multiMedia->setFormat(imageType);
    }
    strID = FZZConst::fmt( m_maxUnitID.incrementAndGet() );
    multiMedia->setID(strID);
        
    string fileName = "image_";
    fileName += strID;
    fileName += ".";
    fileName += imageType;
    fileLoc->setValue(fileName);
        
        
    resDir->FlushResFile(fileName, imgData,imgLen);
    
    return strID;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFD::addFontRes(string fontName,string familyName,FZZBytes* fontdata,int serif,int bold,int italic,int fixedwidth)
{
    string strID = "";
    FZZOFDPublicResXML* resMenu = getPublicResXML();
    if ( resMenu == NULL ) return strID;
    FZZOFDResDir * resDir = getResDir_default();
    if ( resDir == NULL ) return strID;
    
    string fullFontName = fontName;
    if ( !familyName.empty() ) {
        fullFontName += "_" + familyName;
    }
    
    FZZOFDFont * ctFont = ((FZZOFDFont*)(m_cache[fullFontName]));
    if (ctFont == NULL) {
        FZZOFDFonts * ofdFonts = NULL;
        vector<FZZOFDBaseRes*> * BaseResList = resMenu->getResourceList();
        if ( BaseResList != NULL && BaseResList->size() > 0 ) {
            vector<FZZOFDBaseRes*>::const_iterator baseRes_itr;
            for( baseRes_itr = BaseResList->begin(); baseRes_itr != BaseResList->end(); baseRes_itr++ ) {
                FZZOFDBaseRes * tempItem = *baseRes_itr;
                if ( tempItem != NULL ) {
                    if ( ( ofdFonts = dynamic_cast<FZZOFDFonts*>(tempItem) ) != NULL ) {
                        break;
                    }
                }
            }
        }
        
        if (ofdFonts == NULL) {
            ofdFonts = resMenu->setFonts();
            if (ofdFonts == NULL) {
                return strID;
            }
        }
        ctFont = ofdFonts->addFont();
        if ( ctFont == NULL ) return strID;
        m_cache[fullFontName] = ctFont;
        
        strID = FZZConst::fmt(m_maxUnitID.incrementAndGet());
        ctFont->setID(strID);

        
        ctFont->setFontName(fontName);
        ctFont->setFamilyName(familyName);
        
        if (fontdata != NULL && fontdata->getLen() > 0) {
            string fontFileName = fullFontName+".ttf";
            FZZOFDFontFile * ofdFontFile = ctFont->setFontFile();
            if ( ofdFontFile != NULL ) {
                ofdFontFile->setValue(fontFileName);
                resDir->FlushResFile(fontFileName, fontdata);
            }
        }
        
        transform(familyName.begin(), familyName.end(), familyName.begin(), ::tolower);
        
        if (familyName == "serif" || serif == 1) {
            ctFont->setSerif(true);
        }
        if (familyName == "bold" || bold == 1) {
            ctFont->setBold(true);
        }
        if (familyName == "italic" || italic == 1 ) {
            ctFont->setItalic(true);
        }
        if (familyName == "fixedwidth" || fixedwidth == 1) {
            ctFont->setFixedWidth(true);
        }

    } else {
    
        strID = ((FZZOFDFont*)(m_cache[fullFontName]))->getID();
    }
    return strID;
    
    
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFD::isHaveFont(string cacheKey)
{
    map<string, void *>::iterator it = m_cache.find(cacheKey);
    return it != m_cache.end();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::updateFontFile(string completeFontName,FZZBytes & FontFileData)
{
    FZZOFDFont * ctFont = (FZZOFDFont *)(m_cache[completeFontName]);
    if (ctFont == NULL) {
        return;
    }
    
    FZZOFDResDir * resDir = getResDir_default();
    if ( resDir == NULL ) return;
    
    string fontFileName = completeFontName+".ttf";
    if ( FontFileData.getLen() > 0 ) {
        FZZOFDFontFile * ofdFontFile = ctFont->setFontFile();
        if ( ofdFontFile != NULL ) {
            ofdFontFile->setValue(fontFileName);
            resDir->FlushResFile(fontFileName, FontFileData.getData(),(int)FontFileData.getLen());
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFD::UpdateMaxUnitID()
{
    FZZOFDDocumentXML* documentXML = getDocumentXML_default();
    if ( documentXML != NULL ) {

        FZZOFDCommonData * commonData = documentXML->getCommonData();
        if ( commonData != NULL )  {
            FZZOFDMaxUnitID * maxUnitID = commonData->setMaxUnitID();
            if ( maxUnitID != NULL )  {
                maxUnitID->setValue(m_maxUnitID.incrementAndGet());
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFD::isProtect()
{
    bool isRet = false;
    
    FZZOFDDir* ofdDir = getOFDDir();
    if ( ofdDir == NULL ) return isRet;
    
    FZZOFDEntriesXML* ofdEntriesXML = ofdDir->getEntriesXML();
    isRet = ofdEntriesXML != NULL ;
    return isRet;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDEntriesXML* FZZOFD::getEntriesXML()
{
    FZZOFDDir* ofdDir = getOFDDir();
    if ( ofdDir == NULL ) return NULL;
    
    return ofdDir->getEntriesXML();
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZOFD::isEncrypt()
{
    FZZOFDDir* ofdDir = getOFDDir();
    if ( ofdDir == NULL ) return false;
    
    FZZOFDEncryptionsXML* EncryptionsXML = ofdDir->getEncryptionsXML();
    if ( EncryptionsXML == NULL )  return false;
    
    return true;
}
//-----------------------------------------------------------------------------------------------------------------
