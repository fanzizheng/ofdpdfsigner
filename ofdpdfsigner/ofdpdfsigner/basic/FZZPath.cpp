//
//  Created by zizheng fan on 2024/07/23.
//
#include "basic/FZZConst.h"
#include "basic/FZZPath.h"

//-----------------------------------------------------------------------------------------------------------------
static void add_path_moveto(fz_context *ctx, void *arg, float x, float y)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_moveto(ctx, temp, x, y);
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
static void add_path_lineto(fz_context *ctx, void *arg, float x, float y)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_lineto(ctx, temp, x, y);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void add_path_curveto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2, float x3, float y3)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_curveto(ctx, temp, x1, y1, x2, y2,x3,y3);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void add_path_close(fz_context *ctx, void *arg)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_closepath(ctx, temp);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void add_path_quadto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_quadto(ctx, temp, x1, y1, x2, y2);
    }
}
//-----------------------------------------------------------------------------------------------------------------
//static void add_path_curvetov(fz_context *ctx, void *arg, float x2, float y2, float x3, float y3)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_curvetov(ctx, temp, x2, y2, x3, y3);
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
//static void add_path_curvetoy(fz_context *ctx, void *arg, float x1, float y1, float x3, float y3)
//{
//    fz_path * temp = (fz_path*)arg;
//    if ( temp != NULL ) {
//        fz_curvetoy(ctx, temp, x1, y1, x3, y3);
//    }
//}
//-----------------------------------------------------------------------------------------------------------------
static void add_path_rectto(fz_context *ctx, void *arg, float x1, float y1, float x2, float y2)
{
    fz_path * temp = (fz_path*)arg;
    if ( temp != NULL ) {
        fz_rectto(ctx, temp, x1, y1, x2, y2);
    }
}
//-----------------------------------------------------------------------------------------------------------------
static const fz_path_walker add_path_proc =
{
    add_path_moveto,
    add_path_lineto,
    add_path_curveto,
    add_path_close,
    add_path_quadto,
    NULL,//add_dev_path_curvetov,
    NULL,//add_dev_path_curvetoy,
    add_path_rectto
};
//-----------------------------------------------------------------------------------------------------------------
typedef enum
{
    FZ_MOVETO = 'M',
    FZ_LINETO = 'L',
    FZ_DEGENLINETO = 'D',
    FZ_CURVETO = 'C',
    FZ_CURVETOV = 'V',
    FZ_CURVETOY = 'Y',
    FZ_HORIZTO = 'H',
    FZ_VERTTO = 'I',
    FZ_QUADTO = 'Q',
    FZ_RECTTO = 'R',
    FZ_MOVETOCLOSE = 'm',
    FZ_LINETOCLOSE = 'l',
    FZ_DEGENLINETOCLOSE = 'd',
    FZ_CURVETOCLOSE = 'c',
    FZ_CURVETOVCLOSE = 'v',
    FZ_CURVETOYCLOSE = 'y',
    FZ_HORIZTOCLOSE = 'h',
    FZ_VERTTOCLOSE = 'i',
    FZ_QUADTOCLOSE = 'q',
} fz_path_item_kind;
//-----------------------------------------------------------------------------------------------------------------
struct fz_path
{
    int8_t refs;
    uint8_t packed;
    int cmd_len, cmd_cap;
    unsigned char *cmds;
    int coord_len, coord_cap;
    float *coords;
    fz_point current;
    fz_point begin;
};
//-----------------------------------------------------------------------------------------------------------------
//fz_transform_path() 导致泄漏和崩溃 修改的函数
//old fz_transform_path()：
//if (path->cmd_len + extra_cmd < path->cmd_cap)
//{
//    path->cmds = fz_realloc_array(ctx, path->cmds, path->cmd_len + extra_cmd, unsigned char);
//    path->cmd_cap = path->cmd_len + extra_cmd;
//}
//if (path->coord_len + extra_coord < path->coord_cap)
//{
//    path->coords = fz_realloc_array(ctx, path->coords, path->coord_len + extra_coord, float);
//    path->coord_cap = path->coord_len + extra_coord;
//}

void fz_transform_path_ext(fz_context *ctx, fz_path *path, fz_matrix ctm)
{
    int i, k, n;
    fz_point p, p1, p2, p3, q, s;

    if (path->packed)
        fz_throw(ctx, FZ_ERROR_GENERIC, "Cannot transform a packed path");

    if (ctm.b == 0 && ctm.c == 0)
    {
        /* Simple, in place transform */
        i = 0;
        k = 0;
        while (i < path->cmd_len)
        {
            uint8_t cmd = path->cmds[i];

            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_LINETO:
            case FZ_MOVETOCLOSE:
            case FZ_LINETOCLOSE:
                n = 1;
                break;
            case FZ_DEGENLINETO:
            case FZ_DEGENLINETOCLOSE:
                n = 0;
                break;
            case FZ_CURVETO:
            case FZ_CURVETOCLOSE:
                n = 3;
                break;
            case FZ_RECTTO:
                s.x = path->coords[k];
                s.y = path->coords[k+1];
                n = 2;
                break;
            case FZ_CURVETOV:
            case FZ_CURVETOY:
            case FZ_QUADTO:
            case FZ_CURVETOVCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_QUADTOCLOSE:
                n = 2;
                break;
            case FZ_HORIZTO:
            case FZ_HORIZTOCLOSE:
                q.x = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.x;
                n = 0;
                break;
            case FZ_VERTTO:
            case FZ_VERTTOCLOSE:
                q.y = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.y;
                n = 0;
                break;
            default:
                assert("Unknown path cmd" == NULL);
            }
            while (n > 0)
            {
                q.x = path->coords[k];
                q.y = path->coords[k+1];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.x;
                path->coords[k++] = p.y;
                n--;
            }
            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_MOVETOCLOSE:
                s = q;
                break;
            case FZ_LINETOCLOSE:
            case FZ_DEGENLINETOCLOSE:
            case FZ_CURVETOCLOSE:
            case FZ_CURVETOVCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_QUADTOCLOSE:
            case FZ_HORIZTOCLOSE:
            case FZ_VERTTOCLOSE:
            case FZ_RECTTO:
                q = s;
                break;
            }
            i++;
        }
    }
    else if (ctm.a == 0 && ctm.d == 0)
    {
      
        /* In place transform with command rewriting */
        i = 0;
        k = 0;
        while (i < path->cmd_len)
        {
            uint8_t cmd = path->cmds[i];

            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_LINETO:
            case FZ_MOVETOCLOSE:
            case FZ_LINETOCLOSE:
                n = 1;
                break;
            case FZ_DEGENLINETO:
            case FZ_DEGENLINETOCLOSE:
                n = 0;
                break;
            case FZ_CURVETO:
            case FZ_CURVETOCLOSE:
                n = 3;
                break;
            case FZ_RECTTO:
                s.x = path->coords[k];
                s.y = path->coords[k+1];
                n = 2;
                break;
            case FZ_CURVETOV:
            case FZ_CURVETOY:
            case FZ_QUADTO:
            case FZ_CURVETOVCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_QUADTOCLOSE:
                n = 2;
                break;
            case FZ_HORIZTO:
                q.x = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.y;
                path->cmds[i] = FZ_VERTTO;
                n = 0;
                break;
            case FZ_HORIZTOCLOSE:
                q.x = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.y;
                path->cmds[i] = FZ_VERTTOCLOSE;
                n = 0;
                break;
            case FZ_VERTTO:
                q.y = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.x;
                path->cmds[i] = FZ_HORIZTO;
                n = 0;
                break;
            case FZ_VERTTOCLOSE:
                q.y = path->coords[k];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.x;
                path->cmds[i] = FZ_HORIZTOCLOSE;
                n = 0;
                break;
            default:
                assert("Unknown path cmd" == NULL);
            }
            while (n > 0)
            {
                q.x = path->coords[k];
                q.y = path->coords[k+1];
                p = fz_transform_point(q, ctm);
                path->coords[k++] = p.x;
                path->coords[k++] = p.y;
                n--;
            }
            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_MOVETOCLOSE:
                s = q;
                break;
            case FZ_LINETOCLOSE:
            case FZ_DEGENLINETOCLOSE:
            case FZ_CURVETOCLOSE:
            case FZ_CURVETOVCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_QUADTOCLOSE:
            case FZ_HORIZTOCLOSE:
            case FZ_VERTTOCLOSE:
            case FZ_RECTTO:
                q = s;
                break;
            }
            i++;
        }
    }
    else
    {
        
       

        int extra_coord = 0;
        int extra_cmd = 0;
        int coord_read, coord_write, cmd_read, cmd_write;

        /* General case. Have to allow for rects/horiz/verts
         * becoming non-rects/horiz/verts. */
        for (i = 0; i < path->cmd_len; i++)
        {
            uint8_t cmd = path->cmds[i];
            switch (cmd)
            {
            case FZ_HORIZTO:
            case FZ_VERTTO:
            case FZ_HORIZTOCLOSE:
            case FZ_VERTTOCLOSE:
                extra_coord += 1;
                break;
            case FZ_RECTTO:
                extra_coord += 2;
                extra_cmd += 3;
                break;
            default:
                /* Do nothing */
                break;
            }
        }
        if (path->cmd_len + extra_cmd > path->cmd_cap)
        {
            path->cmds = fz_realloc_array(ctx, path->cmds, path->cmd_len + extra_cmd, unsigned char);
            path->cmd_cap = path->cmd_len + extra_cmd;
        }
        if (path->coord_len + extra_coord > path->coord_cap)
        {
            path->coords = fz_realloc_array(ctx, path->coords, path->coord_len + extra_coord, float);
            path->coord_cap = path->coord_len + extra_coord;
        }
        memmove(path->cmds + extra_cmd, path->cmds, path->cmd_len * sizeof(unsigned char));
        path->cmd_len += extra_cmd;
        memmove(path->coords + extra_coord, path->coords, path->coord_len * sizeof(float));
        path->coord_len += extra_coord;

        for (cmd_write = 0, cmd_read = extra_cmd, coord_write = 0, coord_read = extra_coord; cmd_read < path->cmd_len; i += 2)
        {
            uint8_t cmd = path->cmds[cmd_write++] = path->cmds[cmd_read++];

            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_LINETO:
            case FZ_MOVETOCLOSE:
            case FZ_LINETOCLOSE:
                n = 1;
                break;
            case FZ_DEGENLINETO:
            case FZ_DEGENLINETOCLOSE:
                n = 0;
                break;
            case FZ_CURVETO:
            case FZ_CURVETOCLOSE:
                n = 3;
                break;
            case FZ_CURVETOV:
            case FZ_CURVETOY:
            case FZ_QUADTO:
            case FZ_CURVETOVCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_QUADTOCLOSE:
                n = 2;
                break;
            case FZ_RECTTO:
                p.x = path->coords[coord_read++];
                p.y = path->coords[coord_read++];
                p2.x = path->coords[coord_read++];
                p2.y = path->coords[coord_read++];
                p1.x = p2.x;
                p1.y = p.y;
                p3.x = p.x;
                p3.y = p2.y;
                s = p;
                p = fz_transform_point(p, ctm);
                p1 = fz_transform_point(p1, ctm);
                p2 = fz_transform_point(p2, ctm);
                p3 = fz_transform_point(p3, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                path->coords[coord_write++] = p1.x;
                path->coords[coord_write++] = p1.y;
                path->coords[coord_write++] = p2.x;
                path->coords[coord_write++] = p2.y;
                path->coords[coord_write++] = p3.x;
                path->coords[coord_write++] = p3.y;
                path->cmds[cmd_write-1] = FZ_MOVETO;
                path->cmds[cmd_write++] = FZ_LINETO;
                path->cmds[cmd_write++] = FZ_LINETO;
                path->cmds[cmd_write++] = FZ_LINETOCLOSE;
                n = 0;
                break;
            case FZ_HORIZTO:
                q.x = path->coords[coord_read++];
                p = fz_transform_point(q, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                path->cmds[cmd_write-1] = FZ_LINETO;
                n = 0;
                break;
            case FZ_HORIZTOCLOSE:
                p.x = path->coords[coord_read++];
                p.y = q.y;
                p = fz_transform_point(p, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                path->cmds[cmd_write-1] = FZ_LINETOCLOSE;
                q = s;
                n = 0;
                break;
            case FZ_VERTTO:
                q.y = path->coords[coord_read++];
                p = fz_transform_point(q, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                path->cmds[cmd_write-1] = FZ_LINETO;
                n = 0;
                break;
            case FZ_VERTTOCLOSE:
                p.x = q.x;
                p.y = path->coords[coord_read++];
                p = fz_transform_point(p, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                path->cmds[cmd_write-1] = FZ_LINETOCLOSE;
                q = s;
                n = 0;
                break;
            default:
                assert("Unknown path cmd" == NULL);
            }
            while (n > 0)
            {
                q.x = path->coords[coord_read++];
                q.y = path->coords[coord_read++];
                p = fz_transform_point(q, ctm);
                path->coords[coord_write++] = p.x;
                path->coords[coord_write++] = p.y;
                n--;
            }
            switch (cmd)
            {
            case FZ_MOVETO:
            case FZ_MOVETOCLOSE:
                s = q;
                break;
            case FZ_LINETOCLOSE:
            case FZ_DEGENLINETOCLOSE:
            case FZ_CURVETOCLOSE:
            case FZ_CURVETOYCLOSE:
            case FZ_CURVETOVCLOSE:
            case FZ_QUADTOCLOSE:
            case FZ_HORIZTOCLOSE:
            case FZ_VERTTOCLOSE:
            case FZ_RECTTO:
                q = s;
                break;
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
static void
add_arc_segment(fz_context *ctx, fz_path *path, fz_matrix mtx, float th0, float th1, int iscw)
{
    float t, d;
    fz_point p;

    while (th1 < th0)
        th1 += FZ_PI * 2;

    d = FZ_PI / 180; /* 1-degree precision */

    if (iscw)
    {
        for (t = th0 + d; t < th1 - d/2; t += d)
        {
            p = fz_transform_point_xy(cosf(t), sinf(t), mtx);
            fz_lineto(ctx, path, p.x, p.y);
        }
    }
    else
    {
        th0 += FZ_PI * 2;
        for (t = th0 - d; t > th1 + d/2; t -= d)
        {
            p = fz_transform_point_xy(cosf(t), sinf(t), mtx);
            fz_lineto(ctx, path, p.x, p.y);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
static float
angle_between(const fz_point u, const fz_point v)
{
    float det = u.x * v.y - u.y * v.x;
    float sign = (det < 0 ? -1 : 1);
    float magu = u.x * u.x + u.y * u.y;
    float magv = v.x * v.x + v.y * v.y;
    float udotv = u.x * v.x + u.y * v.y;
    float t = udotv / (magu * magv);
    /* guard against rounding errors when near |1| (where acos will return NaN) */
    if (t < -1) t = -1;
    if (t > 1) t = 1;
    return sign * acosf(t);
}
//-----------------------------------------------------------------------------------------------------------------
static void
add_arc(fz_context *ctx, fz_path *path,
    float size_x, float size_y, float rotation_angle,
    int is_large_arc, int is_clockwise,
    float point_x, float point_y)
{
    fz_matrix rotmat, revmat;
    fz_matrix mtx;
    fz_point pt;
    float rx, ry;
    float x1, y1, x2, y2;
    float x1t, y1t;
    float cxt, cyt, cx, cy;
    float t1, t2, t3;
    float sign;
    float th1, dth;

    pt = fz_currentpoint(ctx, path);
    x1 = pt.x;
    y1 = pt.y;
    x2 = point_x;
    y2 = point_y;
    rx = size_x;
    ry = size_y;

    if (is_clockwise != is_large_arc)
        sign = 1;
    else
        sign = -1;

    rotmat = fz_rotate(rotation_angle);
    revmat = fz_rotate(-rotation_angle);

    
    rx = fabsf(rx);
    ry = fabsf(ry);
    if (rx < 0.001f || ry < 0.001f || (x1 == x2 && y1 == y2))
    {
        fz_lineto(ctx, path, x2, y2);
        return;
    }

    /* F.6.5.1 */
    pt.x = (x1 - x2) / 2;
    pt.y = (y1 - y2) / 2;
    pt = fz_transform_vector(pt, revmat);
    x1t = pt.x;
    y1t = pt.y;

    /* F.6.6.2 -- ensure radii are large enough */
    t1 = (x1t * x1t) / (rx * rx) + (y1t * y1t) / (ry * ry);
    if (t1 > 1)
    {
        rx = rx * sqrtf(t1);
        ry = ry * sqrtf(t1);
    }

    /* F.6.5.2 */
    t1 = (rx * rx * ry * ry) - (rx * rx * y1t * y1t) - (ry * ry * x1t * x1t);
    t2 = (rx * rx * y1t * y1t) + (ry * ry * x1t * x1t);
    t3 = t1 / t2;
    /* guard against rounding errors; sqrt of negative numbers is bad for your health */
    if (t3 < 0) t3 = 0;
    t3 = sqrtf(t3);

    cxt = sign * t3 * (rx * y1t) / ry;
    cyt = sign * t3 * -(ry * x1t) / rx;

    /* F.6.5.3 */
    pt.x = cxt;
    pt.y = cyt;
    pt = fz_transform_vector(pt, rotmat);
    cx = pt.x + (x1 + x2) / 2;
    cy = pt.y + (y1 + y2) / 2;

    /* F.6.5.4 */
    {
        fz_point coord1, coord2, coord3, coord4;
        coord1.x = 1;
        coord1.y = 0;
        coord2.x = (x1t - cxt) / rx;
        coord2.y = (y1t - cyt) / ry;
        coord3.x = (x1t - cxt) / rx;
        coord3.y = (y1t - cyt) / ry;
        coord4.x = (-x1t - cxt) / rx;
        coord4.y = (-y1t - cyt) / ry;
        th1 = angle_between(coord1, coord2);
        dth = angle_between(coord3, coord4);
        if (dth < 0 && !is_clockwise)
            dth += ((FZ_PI / 180) * 360);
        if (dth > 0 && is_clockwise)
            dth -= ((FZ_PI / 180) * 360);
    }

    mtx = fz_pre_scale(fz_pre_rotate(fz_translate(cx, cy), rotation_angle), rx, ry);
    add_arc_segment(ctx, path, mtx, th1, th1 + dth, is_clockwise);

    fz_lineto(ctx, path, point_x, point_y);
}
//-----------------------------------------------------------------------------------------------------------------
/********************************************FZZPath************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZPath::FZZPath() : m_Path(NULL),m_CTX(NULL)
{
    //DLOG("FZZPath() ");
    FZZConst::addClassCount("FZZPath");
}
//-----------------------------------------------------------------------------------------------------------------
FZZPath::FZZPath(fz_context * ctx) : FZZPath()
{
    //DLOG("FZZPath(fz_context * ctx)");
    m_CTX = ctx;
    if ( m_CTX == NULL ) {
        return;
    }
    m_Path = fz_new_path(m_CTX);
}
//-----------------------------------------------------------------------------------------------------------------
FZZPath::FZZPath(fz_context * ctx,fz_path * path) : FZZPath()
{
    m_CTX = ctx;
    if ( m_CTX == NULL ) {
        return;
    }
    m_Path = fz_clone_path(m_CTX,path);
}
//-----------------------------------------------------------------------------------------------------------------
//FZZPath::FZZPath(const FZZPath & obj)
//{
//    m_Path = NULL;
//    m_CTX = NULL;
//    if ( this == &obj ) {
//        return;
//    }
//    FZZConst::addClassCount("FZZPath");
//    
//    if ( obj.m_CTX == NULL ) {
//        return;
//    }
//    m_CTX = obj.m_CTX;
//    m_Path = fz_clone_path(m_CTX,obj.m_Path);
//    
//}
//-----------------------------------------------------------------------------------------------------------------
FZZPath::~FZZPath()
{
    //DLOG("~FZZPath()");
    FZZConst::delClassCount("FZZPath");
    if ( m_Path != NULL ) {
        fz_drop_path(m_CTX, m_Path);
        m_Path = NULL;
    }
    m_CTX = NULL;
}
//-----------------------------------------------------------------------------------------------------------------
const FZZPath& FZZPath::operator=(const FZZPath& data)
{
    if ( this == &data ) {
        return *this;
    }
    
    if ( data.m_CTX == NULL || data.m_Path == NULL ) {
        return *this;
    }
    
    m_CTX = data.m_CTX;
    
    if ( m_Path != NULL ) {
        fz_drop_path(m_CTX, m_Path);
        m_Path = NULL;
    }
    
    m_Path = fz_clone_path(m_CTX,data.m_Path);
    
    return *this;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::reset()
{
    if ( m_CTX == NULL ) {
        return;
    }
    if ( m_Path != NULL ) {
        fz_drop_path(m_CTX, m_Path);
        m_Path = NULL;
    }
    m_Path = fz_new_path(m_CTX);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::addPath(fz_path * srcpath)
{
    if ( m_CTX == NULL || m_Path == NULL ) {
        return;
    }
    if ( srcpath == NULL ) {
        return;
    }
    fz_walk_path(m_CTX, srcpath, &add_path_proc, m_Path);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::transform( fz_matrix ctm)
{
    if ( m_CTX == NULL || m_Path == NULL ) {
        return;
    }
    fz_transform_path_ext(m_CTX,m_Path,ctm);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::addPath(fz_path * srcpath,fz_matrix ctm)
{
    if ( m_CTX == NULL || m_Path == NULL ) {
        return;
    }
    
    if ( srcpath == NULL ) {
        return;
    }
    fz_path * srcpath_clone = fz_clone_path(m_CTX,(fz_path *)srcpath);
    if ( srcpath_clone != NULL ) {
        fz_transform_path_ext(m_CTX,srcpath_clone,ctm);
        addPath(srcpath_clone);
        fz_drop_path(m_CTX, srcpath_clone);
    }
}
//-----------------------------------------------------------------------------------------------------------------
fz_rect FZZPath::getBounds()
{
    return fz_bound_path(m_CTX, m_Path, NULL, MUPDF_fz_identity);
}
//-----------------------------------------------------------------------------------------------------------------
fz_rect FZZPath::getBounds(fz_stroke_state* stroke,fz_matrix ctm)
{
    return fz_bound_path(m_CTX, m_Path, stroke, ctm);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::close()
{
    if ( m_CTX == NULL || m_Path == NULL ) {
        return;
    }
    fz_closepath(m_CTX, m_Path);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::moveTo(float x,float y)
{
    if ( m_CTX == NULL || m_Path == NULL ) {
        return;
    }
    fz_moveto(m_CTX, m_Path,x, y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::lineTo(float x,float y)
{
    if ( m_CTX == NULL || m_Path == NULL ) {
        return;
    }
    fz_lineto(m_CTX, m_Path, x, y);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::quadTo(float x1, float y1, float x2, float y2)
{
    if ( m_CTX == NULL || m_Path == NULL ) {
        return;
    }
    fz_quadto(m_CTX, m_Path,x1, y1, x2, y2);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::cubicTo(float x0, float y0, float x1, float y1, float x2, float y2)
{
    if ( m_CTX == NULL || m_Path == NULL ) {
        return;
    }
    fz_curveto(m_CTX, m_Path, x0, y0, x1, y1, x2, y2);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::arcTo(float size_x, float size_y, float rotation_angle,int is_large_arc, int is_clockwise,float point_x, float point_y)
{
    if ( m_CTX == NULL || m_Path == NULL ) {
        return;
    }
    add_arc(m_CTX, m_Path,size_x, size_y, rotation_angle, is_large_arc, is_clockwise, point_x, point_y);
    
}
//-----------------------------------------------------------------------------------------------------------------
fz_point FZZPath::getCurrentPoint()
{
    if ( m_CTX == NULL || m_Path == NULL ) {
        fz_point ret = {0,0};
        return ret;
    }
    return fz_currentpoint(m_CTX, m_Path);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZPath::rectTo(float x0, float y0, float x1, float y1)
{
    fz_rectto(m_CTX, m_Path,x0,  y0,  x1,  y1);
}
//-----------------------------------------------------------------------------------------------------------------
