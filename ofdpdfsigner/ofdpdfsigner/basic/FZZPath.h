//
//  Created by zizheng fan on 2024/07/23.
//
#ifndef FZZPATH_H
#define FZZPATH_H

class FZZPath
{
public :
    FZZPath(fz_context * ctx);
    FZZPath(fz_context * ctx,fz_path * path);
    //FZZPath(const FZZPath & obj);
	virtual ~FZZPath();
    const FZZPath& operator=(const FZZPath& data);
public:
    void reset();
    fz_path * getPath() { return m_Path; }
    fz_context * getContext() { return m_CTX; }
public:
    void addPath(fz_path * srcpath);
    void transform( fz_matrix ctm);
    void addPath(fz_path * srcpath,fz_matrix ctm);
    
    fz_rect getBounds();
    fz_rect getBounds(fz_stroke_state* stroke,fz_matrix ctm);
    fz_point getCurrentPoint();
public:
    void close();
    void moveTo(float x,float y);
    void lineTo(float x,float y);
    void quadTo(float x1, float y1, float x2, float y2);
    void cubicTo(float x0, float y0, float x1, float y1, float x2, float y2);
    void arcTo(float size_x, float size_y, float rotation_angle,int is_large_arc, int is_clockwise,float point_x, float point_y);
    
    void rectTo(float x0, float y0, float x1, float y1);
    
private:
	FZZPath();
private:
    fz_path * m_Path;
    fz_context * m_CTX;
};

#endif //FZZPATH_H
