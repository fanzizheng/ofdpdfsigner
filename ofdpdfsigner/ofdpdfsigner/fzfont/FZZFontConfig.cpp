//
//  Created by zizheng fan on 2024/07/17.
//
#include "basic/FZZConst.h"
#include "fzfont/FZZFontConfig.h"
#include "rapidjson/document.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZFontConfig**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZFontConfig::FZZFontConfig() : m_DefaultFontFileName(""),m_DefaultFontName(""),m_ClipMaxLen(409600)
{
    //DLOG("FZZFontConfig()");
    FZZConst::addClassCount("FZZFontConfig");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZFontConfig::~FZZFontConfig()
{
    //DLOG("~FZZFontConfig()");
    FZZConst::delClassCount("FZZFontConfig");
   
 
    map<string,FontConfigItem *>::const_iterator it;
 
    for (it = m_FontConfigList.begin(); it != m_FontConfigList.end(); it++) {
        FontConfigItem * temp = it->second;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FontConfigList.clear();
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZFontConfig::load(string jsonData)
{
    bool isRet = false;
    rapidjson::Document dom;
    if (dom.Parse(jsonData.c_str()).HasParseError()) {
        return isRet;
    }
    
    if (!(dom.HasMember("default") && dom["default"].IsString() )) {
        return isRet;
    }
    
    m_DefaultFontFileName = dom["default"].GetString();
    
    if ( dom.HasMember("clipmaxlen") && dom["clipmaxlen"].IsInt() ) {
        m_ClipMaxLen = dom["clipmaxlen"].GetInt();
    }
    
    if (!(dom.HasMember("fonstlist") && dom["fonstlist"].IsArray() )) {
        return isRet;
    }
    const rapidjson::Value& fonstlist_Array = dom["fonstlist"];
    for (int i = 0; i < fonstlist_Array.Size(); ++i) {
        FontConfigItem * fontConfigItem = new FontConfigItem();
        if ( fontConfigItem == NULL ) {
            continue;
        }
        string fileNameItem = "";
        const rapidjson::Value& fonstlist_Array_Item = fonstlist_Array[i];
        
        if (fonstlist_Array_Item.HasMember("filename") && fonstlist_Array_Item["filename"].IsString()) {
            fileNameItem = fonstlist_Array_Item["filename"].GetString();
        }
        
        if (fonstlist_Array_Item.HasMember("fontname") && fonstlist_Array_Item["fontname"].IsString()) {
            string tempString = fonstlist_Array_Item["fontname"].GetString();
            transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);
            fontConfigItem->m_fontName = tempString;
            
        }
        
        if (fonstlist_Array_Item.HasMember("isClip") && fonstlist_Array_Item["isClip"].IsBool()) {
            bool isClip = fonstlist_Array_Item["isClip"].GetBool();
            fontConfigItem->m_isClip = isClip;
            m_FontNameClipList.insert(pair<string,bool>(fontConfigItem->m_fontName,fontConfigItem->m_isClip));
        }
        
        if (!(fonstlist_Array_Item.HasMember("aliases") && fonstlist_Array_Item["aliases"].IsArray() )) {
            return isRet;
        }
        const rapidjson::Value& aliases_Array = fonstlist_Array_Item["aliases"];
        for (int i_aliase = 0; i_aliase < aliases_Array.Size(); ++i_aliase) {
            if ( aliases_Array[i_aliase].IsString() ) {
                string tempString = aliases_Array[i_aliase].GetString();
                transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);
                fontConfigItem->m_aliases.push_back(tempString);
            }
        }
        
        if (!(fonstlist_Array_Item.HasMember("contain") && fonstlist_Array_Item["contain"].IsArray() )) {
            return isRet;
        }
        const rapidjson::Value& contain_Array = fonstlist_Array_Item["contain"];
        for (int i_contain = 0; i_contain < contain_Array.Size(); ++i_contain) {
            if ( !contain_Array[i_contain].IsArray() ) {
                continue;
            }
            const rapidjson::Value& contain_Array_Item = contain_Array[i_contain];
            if ( contain_Array_Item.Size() > 0 ) {
                vector<string> * tempList = new vector<string>();
                for (int i_contain_item = 0; i_contain_item < contain_Array_Item.Size(); ++i_contain_item) {
                    if ( contain_Array_Item[i_contain_item].IsString() ) {
                        string tempString = contain_Array_Item[i_contain_item].GetString();
                        transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);
                        tempList->push_back(tempString);
                    }
                }
                fontConfigItem->m_contain.push_back(tempList);
            }
        }
        
        auto isExitPari = m_FontConfigList.insert(pair<string,FontConfigItem *>(fileNameItem,fontConfigItem));
        if ( !isExitPari.second ) {
            delete fontConfigItem;
        }
    }
    
    isRet = true;
    return isRet;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZFontConfig::getFontName(string FontFile)
{
    string fontName = "";
    if ( FontFile.empty() ) {
        FontFile = m_DefaultFontFileName;
    }
    map<string,FontConfigItem *>::const_iterator it;
    for (it = m_FontConfigList.begin(); it != m_FontConfigList.end(); it++) {
        if ( FontFile != it->first ) {
            continue;
        }
        FontConfigItem * temp = it->second;
        if ( temp == NULL ) {
            continue;
        }
        
        fontName = temp->m_fontName;
    }
    return fontName;
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZFontConfig::isClip(string FontName)
{
    bool retIsClip = true;
    if ( FontName.empty() ) {
        FontName = getDefaultFontName();
    }
    map<string,bool>::const_iterator itr = m_FontNameClipList.find(FontName);
    if ( itr != m_FontNameClipList.end() ) {
        retIsClip = itr->second;
    }
    return retIsClip;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZFontConfig::getFontName_FullPath(string FontFile)
{
    string temppath = FontFile;
    temppath = FZZConst::replace_all(temppath, "\\", "/");
    size_t pos = temppath.find_last_of("/");
    if (pos != string::npos) {
        temppath = temppath.substr(pos+1);
    }
    return getFontName(temppath);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZFontConfig::getDefaultFontName()
{
    if ( m_DefaultFontName.empty() ) {
        m_DefaultFontName = getFontName(m_DefaultFontFileName);
    }
    return m_DefaultFontName;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZFontConfig::getDefaultFontFile()
{
    string rootpath = FZZConst::getDefaultFontPath();
#ifdef _MSC_VER
    rootpath = FZZConst::GB2312toUtf8(rootpath);
#endif
    return rootpath+m_DefaultFontFileName;
}
//-----------------------------------------------------------------------------------------------------------------
string FZZFontConfig::ConvertSysFontName(string fontName)
{
    string retFontName = getDefaultFontName();
    
    if ( fontName.empty() ) {
        return retFontName;
    }
    
    transform(fontName.begin(), fontName.end(), fontName.begin(), ::tolower);
    
    map<string,FontConfigItem *>::const_iterator it;
    for (it = m_FontConfigList.begin(); it != m_FontConfigList.end(); it++) {
        FontConfigItem * temp = it->second;
        if ( temp == NULL ) {
            continue;
        }
        
        if ( fontName == temp->m_fontName ) {
            retFontName = temp->m_fontName;
            break;
        }
        
        bool isAliase = false;
        vector<string>::const_iterator it_aliase_item;
        for (it_aliase_item = temp->m_aliases.begin(); it_aliase_item != temp->m_aliases.end(); it_aliase_item++) {
            if ( fontName == *it_aliase_item ) {
                isAliase = true;
                break;
            }
        }//for (it_aliase_item = temp->m_aliases.begin(); it_aliase_item != temp->m_aliases.end(); it_aliase_item++)
        if ( isAliase ) {
            retFontName = temp->m_fontName;
            break;
        }
        
        bool isContain = false;
        vector<vector<string> *>::const_iterator it_contain;
        for (it_contain = temp->m_contain.begin(); it_contain != temp->m_contain.end(); it_contain++) {
            vector<string> * templist = *it_contain;
            if ( templist == NULL ) {
                continue;
            }
            
            int isFind = -1;
            
            vector<string>::const_iterator it_contain_item;
            for (it_contain_item = templist->begin(); it_contain_item != templist->end(); it_contain_item++) {
                if ( fontName.find((*it_contain_item)) == string::npos ) {
                    isFind = 0;
                    break;
                } else {
                    isFind = 1;
                }
            }
            
            if ( isFind == 1 ) {
                isContain = true;
                break;
            }
            
        }//for (it_contain = temp->m_contain.begin(); it_contain != temp->m_contain.end(); it_contain++)
        
        if ( isContain ) {
            retFontName = temp->m_fontName;
            break;
        }
        
        
    }//for (it = m_FontConfigList.begin(); it != m_FontConfigList.end(); it++)
    return retFontName;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZFontConfig::getSysFontFullPath(string fontName,vector<string> & fullpaths)
{
    if ( fontName.empty() ) {
        return;
    }
    transform(fontName.begin(), fontName.end(), fontName.begin(), ::tolower);
    string rootpath = FZZConst::getDefaultFontPath();
#ifdef _MSC_VER
        rootpath = FZZConst::GB2312toUtf8(rootpath);
#endif
    map<string,FontConfigItem *>::const_iterator it;
    for (it = m_FontConfigList.begin(); it != m_FontConfigList.end(); it++) {
        FontConfigItem * temp = it->second;
        if ( temp == NULL ) {
            continue;
        }
        
        if ( fontName == temp->m_fontName ) {
            fullpaths.push_back(rootpath + it->first );
            continue;
        }
        
        bool isAliase = false;
        vector<string>::const_iterator it_aliase_item;
        for (it_aliase_item = temp->m_aliases.begin(); it_aliase_item != temp->m_aliases.end(); it_aliase_item++) {
            if ( fontName == *it_aliase_item ) {
                isAliase = true;
                break;
            }
        }//for (it_aliase_item = temp->m_aliases.begin(); it_aliase_item != temp->m_aliases.end(); it_aliase_item++)
        if ( isAliase ) {
            fullpaths.push_back(rootpath + it->first );
            continue;
        }
        
        bool isContain = false;
        vector<vector<string> *>::const_iterator it_contain;
        for (it_contain = temp->m_contain.begin(); it_contain != temp->m_contain.end(); it_contain++) {
            vector<string> * templist = *it_contain;
            if ( templist == NULL ) {
                continue;
            }
            
            int isFind = -1;
            
            vector<string>::const_iterator it_contain_item;
            for (it_contain_item = templist->begin(); it_contain_item != templist->end(); it_contain_item++) {
                if ( fontName.find((*it_contain_item)) == string::npos ) {
                    isFind = 0;
                    break;
                } else {
                    isFind = 1;
                }
            }
            
            if ( isFind == 1 ) {
                isContain = true;
                break;
            }
            
        }//for (it_contain = temp->m_contain.begin(); it_contain != temp->m_contain.end(); it_contain++)
        
        if ( isContain ) {
            fullpaths.push_back(rootpath + it->first );
            continue;
        }
        
        
    }//for (it = m_FontConfigList.begin(); it != m_FontConfigList.end(); it++)
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZFontConfig::isExist_SysFont(string fontName)
{
    vector<string> fullpaths;
    getSysFontFullPath(fontName,fullpaths);
    return fullpaths.size() > 0;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZFontConfig::getSysFontFullPath(vector<string> & fullpaths)
{
    string rootpath = FZZConst::getDefaultFontPath();
#ifdef _MSC_VER
        rootpath = FZZConst::GB2312toUtf8(rootpath);
#endif
    map<string,FontConfigItem *>::const_iterator it;
    for (it = m_FontConfigList.begin(); it != m_FontConfigList.end(); it++) {
        fullpaths.push_back(rootpath + it->first );
    }
}
//-----------------------------------------------------------------------------------------------------------------
string FZZFontConfig::ConvertSysFontName_Korea(string fontName)
{
    //batang 字体中 족 不能正常显示，因为他时由三个字合成的
//    if (fontName.empty()) {
//        fontName = "malgun";
//    } else {
//        if (fontName == "宋体" || fontName == "batang" || fontName == "malgun" ) {
//            fontName = "malgun";
//        } else if (fontName.find("simkai") != string::npos || fontName.find("KaiTi") != string::npos || fontName == "楷体" ) {
//            fontName = "malgun";
//        } else if ( fontName == "微软雅黑" || fontName.find("仿宋") != string::npos || fontName.find("malgun") != string::npos) {
//            fontName = "malgun";
//        } else if (fontName == "黑体"  ) {
//            fontName = "malgun";
//        } else if (fontName == "方正小标宋简体" ) {
//            fontName = "malgun";
//        }
//    }
    fontName = "malgun";
    return fontName;
}
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FontConfigItem**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FontConfigItem::FontConfigItem() : m_fontName("")
{
    //DLOG("FontConfigItem()");
    FZZConst::addClassCount("FontConfigItem");
    
}
//-----------------------------------------------------------------------------------------------------------------
FontConfigItem::~FontConfigItem()
{
    //DLOG("~FontConfigItem()");
    FZZConst::delClassCount("FontConfigItem");
   
    m_aliases.clear();
    
    vector<vector<string> *>::const_iterator it;
    for (it = m_contain.begin(); it != m_contain.end(); it++) {
        vector<string> * templist = *it;
        if ( templist != NULL ) {
            delete templist;
        }
        
    }
    m_contain.clear();
    
   
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
