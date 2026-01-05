//
//  Created by zizheng fan on 2024/02/23.
//
#ifndef FZZOFDOBJIECT
#define FZZOFDOBJIECT

class FZZOFDObject
{
public :
    FZZOFDObject(XMLDocument * doc);
    FZZOFDObject(const FZZOFDObject & obj);
	virtual ~FZZOFDObject();
public:
	string getXMLData();
	XMLDocument* getXMLDocument() { return m_doc; }
protected:
    FZZOFDObject();
protected:
	XMLDocument* m_doc;
    XMLNode* m_ofd_Node;
};

#endif //FZZOFDOBJIECT
