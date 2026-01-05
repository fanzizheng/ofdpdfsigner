//
//  Created by zizheng fan on 2023/01/08.
//
#ifndef FZZNORMALSTAMPPOS_H
#define FZZNORMALSTAMPPOS_H

//#include "core/signatures/Signature.h"
//#include "core/basicStructure/FZZOFDObject.h"
#include "ofd/sign/stamppos/FZZStampAppearance.h"

class FZZNormalStampPos : public FZZStampAppearance
{
public:
    FZZNormalStampPos();
    FZZNormalStampPos(int pageIndex,double x,double y, double width, double height);
    virtual ~FZZNormalStampPos();
	
public:
    int getPageIndex() {return m_PageIndex;}
    void setPage(int page) {m_PageIndex = page;}
    double getX() {return m_X;}
    void setX(double x) {m_X = x;}
    double getY() {return m_Y;}
    void setY(double y) {m_Y = y;}
    double getWidth() {return m_Width;}
    void setWidth(double width) {m_Width = width;}
    double getHeight() {return m_Height;}
    void setHeight(double height) {m_Height = height;}
    
    virtual void getAppearance(FZZOFD* ctx, FZZSignIDProvider* idProvider,FZZOFDSignedInfo * signedInfo);
protected:
    
private:
    int m_PageIndex;
    //mm
    double m_X;
    //mm
    double m_Y;
    //mm
    double m_Width;
    //mm
    double m_Height;
};

#endif //FZZNORMALSTAMPPOS_H


