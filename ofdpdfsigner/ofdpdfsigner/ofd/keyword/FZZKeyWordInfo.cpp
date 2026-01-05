//
//  Created by zizheng fan on 2022/10/24.
//
#include "basic/FZZConst.h"
#include "ofd/keyword/FZZKeyWordInfo.h"

//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZKeyWordInfo******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZKeyWordInfo::FZZKeyWordInfo() : m_PageIndex(0),m_KeyWord(""),m_X(0),m_Y(0),m_W(0),m_H(0),m_index(0)
{
    //DLOG("FZZKeyWordInfo()");
    FZZConst::addClassCount("FZZKeyWordInfo");
    //DLOG("FZZKeyWordInfo::FZZKeyWordInfo() %s", m_KeyWord.c_str());
}
//-----------------------------------------------------------------------------------------------------------------

FZZKeyWordInfo::~FZZKeyWordInfo()
{
    //DLOG("~FZZKeyWordInfo()");
    FZZConst::delClassCount("FZZKeyWordInfo");
}
//-----------------------------------------------------------------------------------------------------------------
FZZKeyWordInfo::FZZKeyWordInfo(int pageIndex,string & keyWord,float x,float y,float w,float h) : FZZKeyWordInfo()
{
    setData(pageIndex,keyWord,x,y,w,h);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZKeyWordInfo::setData(int pageIndex, string& keyWord, float x, float y, float w, float h) {
    m_PageIndex = pageIndex;
    m_KeyWord = keyWord;
    m_X = x;
    m_Y = y;
    m_W = w;
    m_H = h;
    //DLOG("FZZKeyWordInfo::setData %s", m_KeyWord.c_str());
}
//-----------------------------------------------------------------------------------------------------------------




