//
//  Created by zizheng fan on 2024/07/23.
//
#ifndef FZZMATRIX_H
#define FZZMATRIX_H

class FZZMatrix
{
public :
    FZZMatrix();
    FZZMatrix(const FZZMatrix & obj);
	virtual ~FZZMatrix();
    const FZZMatrix& operator=(const FZZMatrix& data);
public:
    fz_matrix getMatrix() { return m_Matrix; }
    void setMatrix(fz_matrix ctm) { m_Matrix = ctm; }
    
    //skia format 
    void setAll(float scaleX, float skewX,  float transX,
                float skewY,  float scaleY, float transY);
    
    void setScale(float sx,float sy) { m_Matrix.a = sx;m_Matrix.d = sy; }
    
    float getScaleX() { return m_Matrix.a; }
    float getScaleY() { return m_Matrix.d; }
    
    
    float getTranslateX() { return m_Matrix.e; }
    float getTranslateY() { return m_Matrix.f; }
public:
    void reset() { m_Matrix = MUPDF_fz_identity; }
    
    void postSkew(float sx, float sy);
    void setRotate(float rotate,float x, float y);
    void postRotate(float rotate,float x, float y);
    void postRotate(float rotate);
    void postTranslate(float x, float y);
    void preTranslate(float x, float y);
    void setTranslate(float x, float y);
    //e,f不计算
    void preScale(float sx,float sy);
    void postScale(float sx,float sy);
    
    void postConcat(FZZMatrix & other);
    void postConcat(fz_matrix & other);
    
private:
    fz_matrix m_Matrix;
};

#endif //FZZMATRIX_H
