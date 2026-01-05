//
//  Created by zizheng fan on 2022/12/02.
//
#include "basic/FZZConst.h"
#include "interface/FZZKeyWordRule.h"
#include "rapidjson/document.h"
//-----------------------------------------------------------------------------------------------------------------
/*****************************************************FZZKeyWordRule******************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZKeyWordRule::FZZKeyWordRule()
{
    //DLOG("FZZKeyWordRule()");
    FZZConst::addClassCount("FZZKeyWordRule");
 
}
//-----------------------------------------------------------------------------------------------------------------

FZZKeyWordRule::~FZZKeyWordRule()
{
    //DLOG("~FZZKeyWordRule()");
    FZZConst::delClassCount("FZZKeyWordRule");
    clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZKeyWordRule::clear()
{
    vector<FZZKeyWordInfo*>::const_iterator it;
    for( it = m_KeyWordList.begin(); it != m_KeyWordList.end(); it++ ) {
        FZZKeyWordInfo * temp = *it;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_KeyWordList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZKeyWordInfo*> * FZZKeyWordRule::getRule(int doctype,vector<FZZKeyWordInfo*> * inKeyWordList,string Rule,float stampwidth,float stampHeight)
{
    clear();
    
    Rule = "{\"KeyWordPosInfo\":" + Rule + "}";
    
    rapidjson::Document dom;
    if (dom.Parse(Rule.c_str()).HasParseError()) {
        return NULL;
    }
    
    if (!(dom.HasMember("KeyWordPosInfo") && dom["KeyWordPosInfo"].IsArray())) {
        return NULL;
    }
    
    const rapidjson::Value& KeyWordPosInfo_Array = dom["KeyWordPosInfo"];
    int tempPageIndex = -1;
    int tempKeyWordIndex = -1;
    int tempOffset_X = 0;
    int tempOffset_Y = 0;

    vector<FZZKeyWordInfo*>::const_iterator it;
    for (int i = 0; i < KeyWordPosInfo_Array.Size(); ++i) {
        tempPageIndex = -1;
        const rapidjson::Value& KeyWordPosInfo_Array_Item = KeyWordPosInfo_Array[i];
        if (KeyWordPosInfo_Array_Item.HasMember("pageNumber") && KeyWordPosInfo_Array_Item["pageNumber"].IsInt()) {
            tempPageIndex = KeyWordPosInfo_Array_Item["pageNumber"].GetInt() - 1;
            if ( tempPageIndex == -1 ) {
                tempPageIndex = 0;
            } else if ( tempPageIndex == -2 ) {
                tempPageIndex = -1;
            }
        }
        
        if (KeyWordPosInfo_Array_Item.HasMember("indexRules") && KeyWordPosInfo_Array_Item["indexRules"].IsArray()) {
            const rapidjson::Value& KeyWordIndexs_Array = KeyWordPosInfo_Array_Item["indexRules"];
            for (int x = 0; x < KeyWordIndexs_Array.Size(); ++x) {
                tempKeyWordIndex = -1;
                tempOffset_X = 0;
                tempOffset_Y = 0;
                const rapidjson::Value& KeyWordIndexs_Array_Item = KeyWordIndexs_Array[x];
                if (KeyWordIndexs_Array_Item.HasMember("index") && KeyWordIndexs_Array_Item["index"].IsInt()) {
                    tempKeyWordIndex = KeyWordIndexs_Array_Item["index"].GetInt() - 1;
                    if ( tempKeyWordIndex == -1 ) {
                        tempKeyWordIndex = 0;
                    } else if ( tempKeyWordIndex == -2 ) {
                        tempKeyWordIndex = -1;
                    }
                }
                if (KeyWordIndexs_Array_Item.HasMember("offsetX") && KeyWordIndexs_Array_Item["offsetX"].IsInt()) {
                    tempOffset_X = KeyWordIndexs_Array_Item["offsetX"].GetInt();
                }
                if (KeyWordIndexs_Array_Item.HasMember("offsetY") && KeyWordIndexs_Array_Item["offsetY"].IsInt()) {
                    tempOffset_Y = KeyWordIndexs_Array_Item["offsetY"].GetInt();
                }
                
                
                for( it = inKeyWordList->begin(); it != inKeyWordList->end(); it++ ) {
                    FZZKeyWordInfo * temp = *it;
                    if ( temp != NULL ) {
                        if ( tempPageIndex == -1 ) {
                            if ( tempKeyWordIndex == -1 ) {
                                
                                addList(doctype,temp,tempOffset_X,tempOffset_Y,stampwidth,stampHeight);
                            } else if ( tempKeyWordIndex != -1 && tempKeyWordIndex == temp->getIndex() ) {
                                addList(doctype,temp,tempOffset_X,tempOffset_Y,stampwidth,stampHeight);
                            }
                        } else if ( tempPageIndex != -1 && tempPageIndex == temp->getPageIndex() ) {
                            if ( tempKeyWordIndex == -1 ) {
                                addList(doctype,temp,tempOffset_X,tempOffset_Y,stampwidth,stampHeight);
                            } else if ( tempKeyWordIndex != -1 && tempKeyWordIndex == temp->getIndex() ) {
                                addList(doctype,temp,tempOffset_X,tempOffset_Y,stampwidth,stampHeight);
                            }
                        }
                        
                    }
                }
                
                if ( tempKeyWordIndex == -1 ) {
                    break;
                }
            }
        }
        
        if ( tempPageIndex == -1 ) {
            break;
        }
        
    }
    
    return &m_KeyWordList;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZKeyWordRule::addList(int doctype,FZZKeyWordInfo * temp,int tempOffset_X,int tempOffset_Y,float stampwidth,float stampHeight)
{
    float tempX = 0;
    float tempY = 0;
    //if ( doctype == 1 ) {
        //ofd
//        if ( tempOffset_X == 0 ) {
//            tempX = temp->getX()+temp->getW()/2 - stampwidth/2;
//        } else {
//            tempX = temp->getX()+temp->getW() + tempOffset_X;
//        }
        tempX = temp->getX() + temp->getW()/2 - stampwidth/2 + tempOffset_X;
        tempY = temp->getY() + temp->getH()/2 - stampHeight/2 + tempOffset_Y;
//    } else {
//
//        tempY = temp->getY() + temp->getH()/2 - stampHeight/2 + tempOffset_Y;
//    }
    
    string tempWord = temp->getKeyWord();
    m_KeyWordList.push_back(new FZZKeyWordInfo(temp->getPageIndex(),tempWord,tempX,tempY,0,0));
}
//-----------------------------------------------------------------------------------------------------------------

