#ifndef UTIL_H
#define UTIL_H

#include <QString>
//#define _HAS_STD_BYTE 0
//#include <vector>
//#include <map>


//using namespace std;


#define BACKGROUD_COLOR_DOCMENT "rgb(227,232,227);"
#define BACKGROUD_COLOR_TABBAR "rgb(238,238,238);"
#define BORDE_COLOR "rgb(200,200,200);"
#define BACKGROUD_COLOR_TITLEBAR "rgb(232,232,232);"
#define BACKGROUD_COLOR_LEFTBAR "rgb(210,210,210);"

#define LEFTBAR_TIME_COLOR "rgb(160,160,160);"

#define LEFTBAR_TREEITEM_SELECT_COLOR "rgb(215,215,215);"



class DocWord
{
public:
    int m_PageIndex;
    QString m_Word;
    float m_x;
    float m_y;
    float m_w;
    float m_h;
};



#endif // UTIL_H
