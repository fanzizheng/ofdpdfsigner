//
//  Created by zizheng fan on 2023/01/10.
//
#ifndef FZZCUTTINGRIDINGSTAMPPOS_H
#define FZZCUTTINGRIDINGSTAMPPOS_H

#include "ofd/sign/stamppos/FZZStampAppearance.h"
#include "ofd/sign/stamppos/FZZRidingStampPos.h"

class FZZCuttingRideStampPos : public FZZStampAppearance
{
public:
    struct CuttingRatio
    {
        double left;
        double right;
    };
public:
    FZZCuttingRideStampPos(FZZRidingStampPos::TYPE side,double offset, double width, double height, double margin);
    virtual ~FZZCuttingRideStampPos();
	
public:
    FZZRidingStampPos::TYPE getSide() {return m_side;}
    void setSide(FZZRidingStampPos::TYPE side) {m_side = side;}
    
    double getMargin() {return m_margin;}
    void setMargin(double margin) {m_margin = margin;}
    double getOffset() {return m_offset;}
    void setOffset(double offset) {m_offset = offset;}
    
    double getWidth() {return m_Width;}
    void setWidth(double width) {m_Width = width;}
    double getHeight() {return m_Height;}
    void setHeight(double height) {m_Height = height;}
    
    void addCuttingRatio(double left,double right)
    {
        CuttingRatio cr;
        cr.left = left;
        cr.right = right;
        m_cuttingRatios.push_back(cr);
    }
    
    virtual void getAppearance(FZZOFD* ctx, FZZSignIDProvider* idProvider,FZZOFDSignedInfo * signedInfo);
    
protected:
    FZZCuttingRideStampPos();
private:
    int floor_div(int a, int b);
    int floorMod(int a, int b);
private:
    FZZRidingStampPos::TYPE m_side;
    //mm
    double m_offset;
    //mm
    double m_margin;
    //mm
    double m_Width;
    //mm
    double m_Height;
    
    vector<CuttingRatio> m_cuttingRatios;
};

#endif //FZZCUTTINGRIDINGSTAMPPOS_H


