//
//  Created by zizheng fan on 2022/10/24.
//
#ifndef FZZKEYWORDINFO_H
#define FZZKEYWORDINFO_H



class FZZKeyWordInfo
{
public:
    FZZKeyWordInfo();
    FZZKeyWordInfo(int pageIndex,string & keyWord,float x,float y,float w,float h);
    ~FZZKeyWordInfo();
public:
    void setData(int pageIndex, string& keyWord, float x, float y, float w, float h);
    
    int getPageIndex() { return m_PageIndex; }
    string getKeyWord() { return m_KeyWord; }
    float getX() { return m_X; }
    float getY() { return m_Y; }
    float getW() { return m_W; }
    float getH() { return m_H; }
    
    int getIndex() { return m_index; }
    void setIndex(int index) { m_index = index; }
protected:
    
private:

private:
    int m_PageIndex;
    string m_KeyWord;
    float m_X;
    float m_Y;
    float m_W;
    float m_H;
    int m_index;
};

#endif //FZZKEYWORDINFO_H

