//
//  Created by zizheng fan on 2024/07/17.
//
#ifndef FZZFONTCONFIG_H
#define FZZFONTCONFIG_H


class FontConfigItem
{
public:
    FontConfigItem();
    virtual ~FontConfigItem();
public:
    string m_fontName;
    bool m_isClip;
    vector<string> m_aliases;
    vector<vector<string> *> m_contain;
};

class FZZFontConfig
{
public:
    FZZFontConfig();
    virtual ~FZZFontConfig();
    
public:
    bool isLoad() { return m_FontConfigList.size() > 0; }
    bool load(string jsonData);
    string getDefaultFontName();
    string getDefaultFontFile();
    string getFontName_FullPath(string FontFile);
    string getFontName(string FontFile);
    void getSysFontFullPath(string fontName,vector<string> & fullpaths);
    bool isExist_SysFont(string fontName);
    void getSysFontFullPath(vector<string> & fullpaths);
    string ConvertSysFontName_Korea(string fontName);
    string ConvertSysFontName(string fontName);
    bool isClip(string fontName);
    long getClipMaxLen() { return m_ClipMaxLen; }
protected:
   
private:
    string m_DefaultFontFileName;
    string m_DefaultFontName;
    long m_ClipMaxLen;
   
    map<string,FontConfigItem *> m_FontConfigList;
    map<string,bool> m_FontNameClipList;
    
};

#endif //FZZFONTCONFIG_H
