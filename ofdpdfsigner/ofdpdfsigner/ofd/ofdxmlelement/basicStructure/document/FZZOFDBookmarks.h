//
//  Created by zizheng fan on 2024/02/27.
//
#ifndef FZZOFDBOOKMARKS_H
#define FZZOFDBOOKMARKS_H

#include "ofd/FZZOFDXMLElementObject.h"
#include "ofd/ofdxmlelement/basicStructure/document/FZZOFDBookmark.h"

#define FZZOFDBOOKMARKS_Name "ofd:Bookmarks"

class FZZOFDBookmarks : public FZZOFDXMLElementObject
{
public:
    
    FZZOFDBookmarks(FZZOFDXMLFileObject * parent);
    FZZOFDBookmarks(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key);
    FZZOFDBookmarks(const FZZOFDBookmarks& obj);
    virtual ~FZZOFDBookmarks();
    
public:
    FZZOFDBookmark * addBookmark();
    vector<FZZOFDBookmark*> * getBookmarkList();
    
protected:
    FZZOFDBookmarks();
private:
 
    vector<FZZOFDBookmark*> m_FZZOFDBookmarks;
};

#endif //FZZOFDBOOKMARKS_H
