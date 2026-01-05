//
//  Created by zizheng fan on 2024/07/23.
//
#ifndef FZZOFDTOIMAGE_H
#define FZZOFDTOIMAGE_H

#include "ofd/FZZOFD.h"

#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCellContent.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLayer.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCompositeObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDImageObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPathObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTextObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDClips.h"



#include "converter/utils/FZZImageUtil.h"
#include "basic/FZZMatrix.h"
#include "basic/FZZPath.h"
#include "fzfont/FZZTempFontList.h"

class FZZOFDToImage 
{
public:
    
    FZZOFDToImage(FZZOFD * reader,double ppm);
    virtual ~FZZOFDToImage();
    
public:
    int pageSize();
    FZZBytes makePage(int pageIndex,string imageType,bool isNoText = false,bool isNoStamp = false);
    void test();
protected:
    FZZOFDToImage();
private:
    void writePage(FZZImageUtil& graphics, TPageInfo* pageInfo,FZZMatrix & matrix,bool isNoText = false,bool isNoStamp = false);
    void writeStampAnnot( FZZImageUtil& graphics, FZZStampAnnotEntity* stampAnnotVo, FZZOFDStampAnnot* stampAnnot);
    void writeContent( FZZImageUtil& graphics, FZZOFDPageBlock* pageBlock, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha = false,int preAlpha = 0xFF,bool isNoText = false);
    void writeText( FZZImageUtil& graphics, FZZOFDTextObject* textObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix);
    void writeImage( FZZImageUtil& graphics, FZZOFDImageObject* imageObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix);
    void writePath( FZZImageUtil& graphics, FZZOFDPathObject* pathObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha = false,int preAlpha = 0xFF);
    void writeComposite( FZZImageUtil& graphics, FZZOFDCompositeObject* compositeObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isNoText = false);
private:
    void addDrawParams(vector<FZZOFDDrawParam*>& drawParams, const string& refID);
    void clipsAble(FZZImageUtil& graphics,FZZOFDClips * clips,FZZMatrix& clipsmatrix,double preboundary_x, double preboundary_y,int & clipscount);
    void clipsText(FZZImageUtil& graphics,vector<double> & ctm,FZZOFDText * ct_text,FZZMatrix& clipsmatrix,bool TransFlag);
    void clipsPath(FZZImageUtil& graphics,vector<double> & ctm,FZZOFDPath * ct_path,FZZMatrix& matrix,double preboundary_x, double preboundary_y,bool TransFlag,/*out*/FZZPath& destpath);
    double getLineWidth(FZZOFDBaseGraphic* graphicUnit, vector<FZZOFDDrawParam*>* drawParams);
    TOFDColor* getStrokeColor(FZZOFDColor* color, FZZOFDColor* defaultColor, vector<FZZOFDDrawParam*>* drawParams);
    TOFDColor* getFillColor(FZZOFDColor* color, FZZOFDColor* defaultColor, vector<FZZOFDDrawParam*>* drawParams);
    TOFDColor* getColor(FZZOFDColor* ctColor);
    bool ShaderObject(FZZImageUtil& graphics,FZZOFDAxialShd * ct_AxialShd,string & strBoundary,double BoundaryBox_x, double BoundaryBox_y, double BoundaryBox_width, double BoundaryBox_height);
    bool PatternObject(FZZImageUtil& graphics,FZZOFDPattern * ct_Pattern,string & strboundary,double BoundaryBox_x, double BoundaryBox_y, double BoundaryBox_width, double BoundaryBox_height);
    bool PatternTextObject(FZZImageUtil& graphics,FZZOFDTextObject* textObject,string& boundary, double BoundaryBox_width, double BoundaryBox_height,double xStep,double yStep);
    bool PatternImageObject(FZZImageUtil& graphics,FZZOFDImageObject* imageObject,string & preboundary,double preboundary_x, double preboundary_y,double BoundaryBox_width, double BoundaryBox_height,fz_rect view,fz_point pXY);
private:
    FZZFontCache* getFont(FZZOFDTextObject* textObject);
    void parseDelta(vector<string> & array,vector<double> & arr);
    size_t getGlyphsSize(FZZOFDGlyphs * ofdglyphs);
private:
    FZZOFD * m_reader;
    double m_ppm;
    bool m_NoText;
    bool m_NoStamp;
    vector<TPageInfo*> * m_pages;
    bool m_isAnnotation;
    
    FZZTempFontList m_FZTempFontList;
};

#endif //FZZOFDTOIMAGE_H



