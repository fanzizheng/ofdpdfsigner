//
//  Created by zizheng fan on 2024/08/06.
//
#ifndef FZZOFDFINDKEYWORD_H
#define FZZOFDFINDKEYWORD_H

#include "basic/FZZBytes.h"
#include "ofd/FZZOFD.h"

#include "ofd/sign/FZZStampAnnotEntity.h"
#include "fzfont/FZZTempFontList.h"
#include "basic/FZZMatrix.h"
#include "ofd/keyword/FZZKeyWordInfo.h"

#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCellContent.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLayer.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCompositeObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDImageObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPathObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTextObject.h"


class FZZOFDFindKeyWord
{
public:
    FZZOFDFindKeyWord(FZZOFD* reader);
    ~FZZOFDFindKeyWord();
public:
    int pageSize() { return m_pages == NULL ? 0 : (int)m_pages->size(); }
    vector<FZZKeyWordInfo*> * find(int pageIndex,string  keyWord);
protected:
    
private:
    FZZOFDFindKeyWord();
    FZZOFDFindKeyWord(const FZZOFDFindKeyWord& obj);
    void clearKeyWordList();
    void writePage(int pageIndex,TPageInfo* pageInfo,FZZMatrix & matrix);
    void writeContent(int pageIndex,FZZOFDPageBlock* pageBlock, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix,bool isUsePreAlpha,int preAlpha);
    void addDrawParams(vector<FZZOFDDrawParam*>& drawParams, const string& refID);
    void writeComposite(int pageIndex, FZZOFDCompositeObject* compositeObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix);
    void writeText(int pageIndex,FZZOFDTextObject* textObject, vector<FZZOFDDrawParam*>* drawParams,FZZMatrix & parentMatrix);

    FZZFontCache* getFont(FZZOFDTextObject* textObject);

    void parseDelta(vector<string> & array,vector<double> & arr);
    
    size_t getGlyphsSize(FZZOFDGlyphs * glyphs);
private:
    vector<FZZKeyWordInfo*> m_KeyWordList;
    vector<FZZKeyWordInfo*> m_GKeyWordList;
    
    FZZOFD* m_reader;
    vector<TPageInfo*> * m_pages;

    FZZTempFontList m_FZTempFontList;

};

#endif //FZZOFDFINDKEYWORD_H

