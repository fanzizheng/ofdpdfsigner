//
//  Created by zizheng fan on 2023/01/09.
//
#ifndef FZZRIDINGSTAMPPOS_H
#define FZZRIDINGSTAMPPOS_H

//#include "core/signatures/Signature.h"
//#include "core/basicStructure/FZZOFDObject.h"
#include "ofd/sign/stamppos/FZZStampAppearance.h"

class FZZRidingStampPos : public FZZStampAppearance
{
public:
    typedef enum {
        TYPE_Left,
        TYPE_Right,
        TYPE_Top,
        TYPE_Bottom
    } TYPE;
public:
    FZZRidingStampPos();
    FZZRidingStampPos(double width, double height);
    FZZRidingStampPos(FZZRidingStampPos::TYPE side, double width, double height);
    FZZRidingStampPos(FZZRidingStampPos::TYPE side, double offset, double width, double height);
    FZZRidingStampPos(FZZRidingStampPos::TYPE side, double offset, double width, double height, double margin);
    FZZRidingStampPos(FZZRidingStampPos::TYPE side, double offset, int clipNumber, double width, double height, double margin);
    virtual ~FZZRidingStampPos();
	
public:
    FZZRidingStampPos::TYPE getSide() {return m_side;}
    void setSide(FZZRidingStampPos::TYPE side) {m_side = side;}
    
    int getClipNumber() {return m_clipNumber;}
    void setClipNumber(int clipNumber) { m_clipNumber = clipNumber;}
    
    
    double getMargin() {return m_margin;}
    void setMargin(double margin) {m_margin = margin;}
    double getOffset() {return m_offset;}
    void setOffset(double offset) {m_offset = offset;}
    
    double getWidth() {return m_Width;}
    void setWidth(double width) {m_Width = width;}
    double getHeight() {return m_Height;}
    void setHeight(double height) {m_Height = height;}
    
    
    virtual void getAppearance(FZZOFD* ctx, FZZSignIDProvider* idProvider,FZZOFDSignedInfo * signedInfo);
protected:
    
private:
    int floor_div(int a, int b);
    int floorMod(int a, int b);
private:
    FZZRidingStampPos::TYPE m_side;
    int m_clipNumber;
    //mm
    double m_offset;
    //mm
    double m_margin;
    //mm
    double m_Width;
    //mm
    double m_Height;
};

#endif //FZZRIDINGSTAMPPOS_H


