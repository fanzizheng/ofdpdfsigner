//
//  Created by zizheng fan on 2024/07/30.
//
#ifndef FZZOFDTOPDF_H
#define FZZOFDTOPDF_H

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

#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"

/*
 pdf 的 fz_begin_group 是可以使用的，但没有图片的效果，仅仅是一个图层
 */
class FZZGenFont;

class FZZOFDToPDF
{
public:
    
    FZZOFDToPDF(FZZOFD * reader);
    virtual ~FZZOFDToPDF();
    
public:
    int getOFDPageCount();
    void setGenFontFlag(bool data) {m_isGenFont = data;}
    void SetNoStamp(bool isNoStamp) { m_isNoStamp = isNoStamp; }
    bool makePage(int pageIndex);
    void generatePDFFont();
    FZZBytes generatePDF();
    
    //setPassWord 和 setEncrypt 同时只能使用一个
    //加入密码并加密文档
    void setPassWord(string password) { m_Password = password; }
    //仅仅加密文档
    void setEncrypt(bool isEncrypt) { m_IsEncrypt = isEncrypt; }
    
    void test();
protected:
    FZZOFDToPDF();
private:
    void writePage(fz_device * dev, TPageInfo* pageInfo,FZZMatrix & matrix);
    void writeStampAnnot( fz_device * dev, FZZStampAnnotEntity* stampAnnotVo, FZZOFDStampAnnot* stampAnnot);
    void writeContent( fz_device * dev, FZZOFDPageBlock* pageBlock, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha = false,int preAlpha = 0xFF,bool isNoText = false);
    void writeText_genFontFile( fz_device * dev, FZZOFDTextObject* textObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix);
    void writeText( fz_device * dev, FZZOFDTextObject* textObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix);
    void writeImage( fz_device * dev, FZZOFDImageObject* imageObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix);
    void writePath_genFontFile( fz_device * dev, FZZOFDPathObject* pathObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha = false,int preAlpha = 0xFF);
    void writePath( fz_device * dev, FZZOFDPathObject* pathObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha = false,int preAlpha = 0xFF);
    void writeComposite( fz_device * dev, FZZOFDCompositeObject* compositeObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isNoText = false);
private:
    void addDrawParams(vector<FZZOFDDrawParam*>& drawParams, const string& refID);
    void clipsAble(fz_device * dev,FZZOFDClips * clips,FZZMatrix& clipsmatrix,double preboundary_x, double preboundary_y,int & clipscount);
    void clipsText(fz_device * dev,vector<double> & ctm,FZZOFDText * ct_text,FZZMatrix& clipsmatrix,bool TransFlag);
    void clipsPath(fz_device * dev,vector<double> & ctm,FZZOFDPath * ct_path,FZZMatrix& matrix,double preboundary_x, double preboundary_y,bool TransFlag,/*out*/FZZPath& destpath);
    double getLineWidth(FZZOFDBaseGraphic* graphicUnit, vector<FZZOFDDrawParam*>* drawParams);
    TOFDColor* getStrokeColor(FZZOFDColor* color, FZZOFDColor* defaultColor, vector<FZZOFDDrawParam*>* drawParams);
    TOFDColor* getFillColor(FZZOFDColor* color, FZZOFDColor* defaultColor, vector<FZZOFDDrawParam*>* drawParams);
    TOFDColor* getColor(FZZOFDColor* ctColor);
    bool ShaderObject(FZZImageUtil & graphics,FZZOFDAxialShd * ct_AxialShd,string & strBoundary,double BoundaryBox_x, double BoundaryBox_y, double BoundaryBox_width, double BoundaryBox_height);
    bool PatternObject(fz_device * dev,FZZOFDPattern * ct_Pattern,string & strboundary,double BoundaryBox_x, double BoundaryBox_y, double BoundaryBox_width, double BoundaryBox_height);
    bool PatternTextObject(fz_device * dev,FZZOFDTextObject* textObject,string& boundary, double BoundaryBox_width, double BoundaryBox_height,double xStep,double yStep);
    bool PatternImageObject(fz_device * dev,FZZOFDImageObject* imageObject,string & preboundary,double preboundary_x, double preboundary_y,double BoundaryBox_width, double BoundaryBox_height,fz_rect view,fz_point pXY);
    
    
private:
    FZZFontCache* getFont(FZZOFDTextObject* textObject,bool & isGen,string & outfontname);
    FZZFontCache* getFont_PDF(FZZOFDTextObject* textObject);
    void parseDelta(vector<string> & array,vector<double> & arr);
    size_t getGlyphsSize(FZZOFDGlyphs * ofdglyphs);
private:
    FZZOFD * m_reader;
    bool m_isNoStamp;
    vector<TPageInfo*> * m_pages;
    bool m_isGenFont;
    
    FZZTempFontList* m_FZTempFontList;
    
    double m_CurrPage_WidthPixel;
    double m_CurrPage_HeightPixel;
    int m_PDFPageMaxIndex;
    fz_context * m_CTX;
    pdf_document * m_Doc;
    
    map<string,FZZGenFont*> m_genFont;
    //map<string,FZZBytes*> m_PDFFontData;
    bool m_IsEncrypt;
    string m_Password;
    
};

#endif //FZZOFDTOPDF_H



