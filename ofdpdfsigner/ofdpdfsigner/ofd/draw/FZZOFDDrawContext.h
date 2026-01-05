//
//  Created by zizheng fan on 2024/03/25.
//
#ifndef FZZOFDDRAWCONTEXT_H
#define FZZOFDDRAWCONTEXT_H


#include "basic/FZZAtomicInteger.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTextObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDImageObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPathObject.h"


struct s_OFD_Box
{
    string strBox;
    double box_x;
    double box_y;
    double box_width;
    double box_height;
} ;

struct clipItem
{
    FZZOFDAbbreviatedData* clip_PathData;
    s_OFD_Box * clip_Box;
    string * clip_ctms;
    bool clip_isFill;
    bool clip_isStroke;
    float clip_StrokeLineWidth;
};

class FZZOFD;

class FZZOFDDrawContext
{
public:
    
    FZZOFDDrawContext(FZZOFD * ofd,FZZOFDPageBlock * container,FZZAtomicInteger* maxUnitID);
    virtual ~FZZOFDDrawContext();

public:
    void setBoundary(string boundary);
    double getBoundary_X() {return m_BoundaryBox_x;}
    double getBoundary_Y() {return m_BoundaryBox_y;}
    void setCTM(string ctm) { m_ctm = ctm; }
    void setGlobalAlpha(float alpha) { m_alpha = alpha; }
    //path
    void beginPath();
    void setFillColor(int r, int g, int b);
    void fill();
    void setStrokeColor(int r, int g, int b);
    void stroke();
    void moveTo(double x, double y);
    void lineTo(double x, double y);
    void quadraticCurveTo(double cpx, double cpy, double x, double y);
    void bezierCurveTo(double cp1x, double cp1y,
        double cp2x, double cp2y,
        double x, double y);
    void arc(double a, double b,
        double angle,
        bool large,
        bool sweep,
        double x, double y);
    void arc(double x, double y,
        double r,
        double sAngle, double eAngle,
        bool counterclockwise);
    void arc(double x, double y,
        double r,
        double sAngle, double eAngle);
    void rect(double x, double y, double width, double height);
    void closePath();
    void setPathObject_Actiton(string cmd);
    void flushPath();
    void setLineWidth(double lineWidth);
    void setDashOffset(double dashOffset);
    void setMiterLimit(double miterLimit);
    void setDashPattern(string dashPattern);
    void setCap(FZZOFDLineCapType::TYPE cap);
    void setLineJoin(FZZOFDLineJoinType::TYPE join);
//    void close(vector<FZZOFDAbbreviatedData*>* clip_PathDatas,vector<s_OFD_Box> * clip_Boxs,
//                                vector<string> * clip_ctms,vector<bool> * clip_isFill,vector<bool>* clip_isStroke,vector<float> * clip_StrokeLineWidth);
    void close(vector<clipItem*>* clipItemList,vector<s_OFD_Box*> * clip_Boxs);
    //image
//    void drawImage(const unsigned char * imageBuffer,int imageSize,const char * const imageType,
//        double x, double y,
//        double width, double height,vector<FZZOFDAbbreviatedData*>* clip_PathDatas,
//                   vector<s_OFD_Box> * clip_Boxs,vector<string> * clip_ctms,vector<bool> * clip_isFill,vector<bool>* clip_isStroke,vector<float> * clip_StrokeLineWidth);
    void drawImage(const unsigned char * imageBuffer,int imageSize,const char * const imageType,
        double x, double y,
        double width, double height,vector<clipItem*>* clipItemList,vector<s_OFD_Box*> * clip_Boxs);
    //text
    void setFontParam(string fontName,double fontSize,bool isBold,bool isItalic);
//    void drawText(const char * const text, double x, double y,bool isFill,bool isStroke,double lineWidth,double miterLimit, vector<string> &DeltaX,vector<string> &DeltaY,vector<string> &glyphs,
//                               vector<FZZOFDAbbreviatedData*>* clip_PathDatas,vector<s_OFD_Box> * clip_Boxs,
//                                   vector<string> * clip_ctms,vector<bool> * clip_isFill,vector<bool>* clip_isStroke,vector<float> * clip_StrokeLineWidth);
    void drawText(const char * const text, double x, double y,bool isFill,bool isStroke,double lineWidth,double miterLimit, vector<string> &DeltaX,vector<string> &DeltaY,vector<string> &glyphs,
                  vector<clipItem*>* clipItemList,vector<s_OFD_Box*> * clip_Boxs);
    
    FZZOFDCellContent * setPath_Pattern(double width,double height,double XStep,double YStep);
public:
  
protected:
    FZZOFDDrawContext();
private:
    FZZAtomicInteger* m_maxUnitID;
    FZZOFDPageBlock* m_container;
    string m_boundary;
    double m_BoundaryBox_x;
    double m_BoundaryBox_y;
    double m_BoundaryBox_width;
    double m_BoundaryBox_height;
    string m_ctm;
    float m_alpha;
    FZZOFDPathObject * m_workPathObj;
    FZZOFDAbbreviatedData * m_pathData;
    FZZOFD * m_FZZOFD;

    string m_FontName;
    double m_FontSize;
    bool m_FontBold;
    bool m_FontItalic;
    int m_fillColor[3];
    int m_strokeColor[3];
};
//-----------------------------------------------------------------------------------------------------------------

#endif //FZZOFDDRAWCONTEXT_H
