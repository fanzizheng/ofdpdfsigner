//
//  Created by zizheng fan on 2024/07/23.
//
#include "basic/FZZConst.h"
#include "basic/FZZMatrix.h"

#define _USE_MATH_DEFINES
#include "math.h"
//-----------------------------------------------------------------------------------------------------------------
/********************************************FZZMatrix************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMatrix::FZZMatrix()
{
    //DLOG("FZZMatrix() ");
    FZZConst::addClassCount("FZZMatrix");
    m_Matrix = MUPDF_fz_identity;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMatrix::FZZMatrix(const FZZMatrix & obj)
{
    if ( this == &obj ) {
        return;
    }
    FZZConst::addClassCount("FZZMatrix");
    
    m_Matrix = obj.m_Matrix;
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMatrix::~FZZMatrix()
{
    //DLOG("~FZZMatrix()");
    FZZConst::delClassCount("FZZMatrix");
	
}
//-----------------------------------------------------------------------------------------------------------------
const FZZMatrix& FZZMatrix::operator=(const FZZMatrix& data)
{
    if ( this == &data ) {
        return *this;
    }
    
    m_Matrix = data.m_Matrix;
    
    return *this;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::postSkew(float sx, float sy)
{
    fz_matrix skew = {1,sy,sx,1,0,0};
    m_Matrix = fz_concat(m_Matrix, skew);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::postRotate(float rotate,float x, float y)
{
    float c = cos(rotate * M_PI / 180.0);
    float s = sin(rotate * M_PI / 180.0);
    float dx = s*y + (1 - c)*x;
    float dy = -s*x + (1 -c)*y;
    
    fz_matrix R = {c,s,-s,c,dx,dy};
    
    m_Matrix = fz_concat(m_Matrix, R);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::postRotate(float rotate)
{
    float c = cos(rotate * M_PI / 180.0);
    float s = sin(rotate * M_PI / 180.0);

    fz_matrix R = {c,s,-s,c,0,0};
    
    m_Matrix = fz_concat(m_Matrix, R);

    //m_Matrix = fz_pre_rotate(m_Matrix, rotate);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::postTranslate(float x, float y)
{
    m_Matrix = fz_concat(m_Matrix, fz_translate(x, y));
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::preTranslate(float x, float y)
{
    m_Matrix = fz_pre_translate(m_Matrix, x, y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::setTranslate(float x, float y)
{
    m_Matrix.e = x; m_Matrix.f = y;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::preScale(float sx,float sy)
{
    m_Matrix = fz_pre_scale(m_Matrix, sx,sy);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::postScale(float sx,float sy)
{
    fz_matrix S = {sx,0,0,sy,0,0};
    m_Matrix = fz_concat(m_Matrix, S);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::setRotate(float rotate,float x, float y)
{
    preTranslate(x, y);
    m_Matrix = fz_pre_rotate(m_Matrix, rotate);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::postConcat(FZZMatrix & other)
{
    m_Matrix = fz_concat(m_Matrix, other.getMatrix());
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::postConcat(fz_matrix & other)
{
    m_Matrix = fz_concat(m_Matrix, other);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZMatrix::setAll(float scaleX, float skewX,  float transX,
                      float skewY,  float scaleY, float transY)
{
    m_Matrix = {scaleX,skewY,skewX,scaleY,transX,transY};
}
//-----------------------------------------------------------------------------------------------------------------
