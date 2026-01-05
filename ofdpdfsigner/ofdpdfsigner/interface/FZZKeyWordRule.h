//
//  Created by zizheng fan on 2022/12/02.
//
//  根据规和关键字列表筛选符合规则的关键字
//
#ifndef FZZKEYWORDRULE_H
#define FZZKEYWORDRULE_H

#include "ofd/keyword/FZZKeyWordInfo.h"


class FZZKeyWordRule
{
public:
    FZZKeyWordRule();

    ~FZZKeyWordRule();
public:
    /*
     函数描述：
        根据规和关键字列表筛选符合规则的关键字
     输入参数：
        doctype：文档类型 1:ofd; 2: pdf
        inKeyWordList: 关键字列表
        Rule：json规则字符串
        stampwidth： 印章的宽度
        stampHeight：印章的高度
     输出参数：
        无
     返回：
        根据规和关键字列表筛选符合规则的关键字列表
     */
    vector<FZZKeyWordInfo*> * getRule(int doctype,vector<FZZKeyWordInfo*> * inKeyWordList,string Rule,float stampwidth,float stampHeight);
protected:
    
private:
    //函数描述：释放筛选符合的关键字列表
    void clear();
    /*
     函数描述：
        加入筛选符合的关键字列表
     输入参数：
         doctype：文档类型 1:ofd; 2: pdf
         temp: 关键字
         tempOffset_X：位置x
         tempOffset_Y：位置y
         stampwidth：印章宽度
         stampHeight：印章高度
     输出参数：
        无
     返回：
        根据规和关键字列表筛选符合规则的关键字列表
    */
    void addList(int doctype,FZZKeyWordInfo * temp,int tempOffset_X,int tempOffset_Y,float stampwidth,float stampHeight);
private:
    vector<FZZKeyWordInfo*> m_KeyWordList;
};

#endif //FZZKEYWORDRULE_H

