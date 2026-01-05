//
//  Created by zizheng fan on 2024/02/23.
//
#ifndef FZZOFD_H
#define FZZOFD_H

#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/FZZOFDXMLElementObject.h"

#include "basic/FZZOFDFilesContainer.h"
#include "ofd/container/FZZOFDDir.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDImageObject.h"

#include "ofd/sign/FZZStampAnnotEntity.h"
#include "basic/FZZAtomicInteger.h"
#include "ofd/draw/FZZOFDDrawContext.h"

class FZZZipTracks;

//typedef struct S_TemplatePageInfo
//{
//    string id;
//    Type type;
//    FZZOFDTemplateDir * templateDir;
//    FZZOFDPageXML * pageXML;
//
//} TTemplatePageInfo;

typedef struct S_PageInfo {
    int pageNum;
    string id;
    FZZOFDPageDir* pageDir;
    FZZOFDPageXML * pageXML;
    double pageSize_x;
    double pageSize_y;
    double pageSize_width;
    double pageSize_height;
    string pagePath;
    //vector<TTemplatePageInfo> templatePageInfoList;
    vector<FZZOFDLayer *> layerList;
    
} TPageInfo;

typedef struct S_Annotion {
    string pageid;
    FZZOFDPageAnnotXML * annotationXml;
} TAnnotion;



class FZZOFD 
{
public:
    FZZOFD();
    virtual ~FZZOFD();
    
public:
    bool Read(FZZBytes & indata);
    bool Read(const unsigned char * const ofdData,size_t ofdDatalen);
    FZZBytes * getFileData();
    void FlushAll();
    void Close(FZZBytes & outdata);
    void clear();
    //文档一致性
    bool isProtect();
    FZZOFDEntriesXML* getEntriesXML();
    //-----------
    bool isEncrypt();
    
    FZZOFDXML* getOFDXML();
    FZZOFDDir* getOFDDir() { return m_OFDDir; }
    FZZOFDDocDir * getDocDir_default();
    FZZOFDResDir * getResDir_default();
    FZZOFDDocumentXML* getDocumentXML_default();
    
    long getPageObjectId(int pageNum);
    int getPageCount();
    FZZOFDPageXML* getPage(int pageNum);
    string getPageSize(FZZOFDPageXML* page,/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);
    void getPageWidthHeight(int pageNum,/*out*/double & width, /*out*/double & height) {
        width = 0;
        height = 0;
        FZZOFDPageXML* pageXML = getPage(pageNum);
        if ( pageXML != NULL ) {
            double x = 0,y = 0;
            getPageSize(pageXML,x,y,width,height);
        }
    }
    
   
    vector<FZZStampAnnotEntity*> * getStampAnnots();
    vector<TPageInfo*> * getPageInfoList();
    vector<FZZOFDPageDir *> * getAnnotationList();
    
    FZZOFDDrawParam * getDrawParam(string id);
    FZZOFDColorSpace * getColorSpace(string id);
    FZZOFDFont * getFont(string id);
    FZZOFDMultiMedia * getMultiMedia(string id);
    FZZOFDVectorG * getCompositeGraphicUnit(string id);
    
    FZZBytes getImage(FZZOFDImageObject * imageObject);
    //-------------------------------------------------------
    FZZOFDDocDir* setDocDir_default();
    FZZOFDPageXML * addPage();
    void addFontFile(string fontFileName,FZZBytes * fontData);
    bool addFileAttachment(FZZBytes * fileData,string name,string format,string * AttachmentID/*out*/);
    FZZOFDPageAnnotXML * addAnnotation(int pageIndex);
    long getNewID() { return m_maxUnitID.incrementAndGet(); }
    FZZOFDDocumentResXML* getDocumentResXML();
    FZZOFDPublicResXML* getPublicResXML();
    FZZOFDPageBlock* addPageBlock_Page(FZZOFDLayer* layer);
    //free
    FZZOFDDrawContext * newDrawContext(FZZOFDPageBlock* block);
    string addImageRes(const unsigned char* const imgData,int imgLen,const char * const imageType);
    string addFontRes(string fullFontName,string familyName = "",FZZBytes* fontdata = NULL,int serif = -1,int bold = -1,int italic = -1,int fixedwidth = -1);
    bool isHaveFont(string cacheKey);
    void updateFontFile(string completeFontName,FZZBytes & FontFileData);
    void UpdateMaxUnitID();
    //-----------------------------------------------------

    
protected:
    FZZOFDFilesContainer m_OFDFilesContainer;
private:
    void zip_mem(FZZBytes & outData);
    void addZip(FZZZipTracks* zipTracks,string rootpath);
    
    void addLayer(FZZOFDDocDir * docDir,string TplID,TPageInfo * pageInfo);
    void addLayer(FZZOFDPageXML * pageXML,TPageInfo * pageInfo);
    
    void getAllResource();
    void loadRes(FZZOFDResXML * resXML);
    FZZBytes getImage(string refID);
    
    

private:
    string m_workDir;
    FZZOFDDir* m_OFDDir;
    
    vector<FZZStampAnnotEntity*> m_StampAnnotEntityList;
    vector<TPageInfo*> m_PageInfoList;
    
    //res
    map<string, FZZOFDColorSpace*> m_colorSpaceMap;
    map<string, FZZOFDDrawParam*> m_drawParamMap;
    map<string, FZZOFDFont*> m_fontMap;
    map<string, FZZOFDMultiMedia*> m_multiMediaMap;
    map<string, FZZOFDVectorG*> m_compositeGraphicUnitMap;
    FZZOFDColorSpace * m_ColorSpace_default;
    FZZAtomicInteger m_maxUnitID;
    //font cache
    map<string, void *> m_cache;
    
    FZZBytes m_FileData;
};

#endif //FZZOFD_H
