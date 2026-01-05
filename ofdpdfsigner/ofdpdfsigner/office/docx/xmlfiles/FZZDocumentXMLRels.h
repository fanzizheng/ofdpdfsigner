//
//  Created by zizheng fan on 2023/04/15.
//
#ifndef FZZDOCUMENTXMLRELS_H
#define FZZDOCUMENTXMLRELS_H


#include "office/FZZOfficeObject.h"
#include "office/ooxml/openxmlformats/package/x2006/FZZRelationship.h"


#define DOCUMENTXMLRELS_FILENAME "document.xml.rels"

#define DOCUMENTXMLRELS_TYPE_STYLES "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles"

#define DOCUMENTXMLRELS_TYPE_SETTINGS "http://schemas.openxmlformats.org/officeDocument/2006/relationships/settings"
#define DOCUMENTXMLRELS_TYPE_WEBSETTINGS "http://schemas.openxmlformats.org/officeDocument/2006/relationships/webSettings"
#define DOCUMENTXMLRELS_TYPE_FONTTABLE "http://schemas.openxmlformats.org/officeDocument/2006/relationships/fontTable"
#define DOCUMENTXMLRELS_TYPE_THEME "http://schemas.openxmlformats.org/officeDocument/2006/relationships/theme"
#define DOCUMENTXMLRELS_TYPE_IMAGE "http://schemas.openxmlformats.org/officeDocument/2006/relationships/image"

#define DOCUMENTXMLRELS_TYPE_ENDNOTES "http://schemas.openxmlformats.org/officeDocument/2006/relationships/endnotes"
#define DOCUMENTXMLRELS_TYPE_FOOTNOTES "http://schemas.openxmlformats.org/officeDocument/2006/relationships/footnotes"
#define DOCUMENTXMLRELS_TYPE_FOOTER "http://schemas.openxmlformats.org/officeDocument/2006/relationships/footer"
#define DOCUMENTXMLRELS_TYPE_HEADER "http://schemas.openxmlformats.org/officeDocument/2006/relationships/header"
#define DOCUMENTXMLRELS_TYPE_NUMBERING "http://schemas.openxmlformats.org/officeDocument/2006/relationships/numbering"

class FZZDocumentXMLRels : public FZZOfficeObject
{
public:
    FZZDocumentXMLRels();
    FZZDocumentXMLRels(XMLDocument * doc);
    FZZDocumentXMLRels(const FZZDocumentXMLRels& obj);
    virtual ~FZZDocumentXMLRels();
    
 
public:
    vector<FZZRelationship *> * getRelationships() ;
    FZZRelationship * addRelationship();
    
public:
    string getNexId();
    string getTarget(string Id);
    void getTarget(string Type,vector<string> & idlist,vector<string> & targetlist);
protected:
    
private:
    
    vector<FZZRelationship *> m_RelationshipList;
    
    int m_id;
};

#endif //FZZDOCUMENTXMLRELS_H
