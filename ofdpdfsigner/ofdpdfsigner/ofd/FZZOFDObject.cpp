//
//  Created by zizheng fan on 2024/02/23.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/FZZOFDObject.h"
//-----------------------------------------------------------------------------------------------------------------
/********************************************FZZOFDObject************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDObject::FZZOFDObject() : m_doc(NULL),m_ofd_Node(NULL)
{
    //DLOG("FZZOFDObject() ");
    FZZConst::addClassCount("FZZOFDObject");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDObject::FZZOFDObject(XMLDocument * doc) : FZZOFDObject()
{
    //DLOG("FZZOFDObject(XMLDocument * doc)");
    
    m_doc = doc;
    m_ofd_Node = m_doc->FirstChildElement();
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDObject::FZZOFDObject(const FZZOFDObject & obj)
{
    if ( this == &obj ) {
        return;
    }
    FZZConst::addClassCount("FZZOFDObject");
    
    if ( obj.m_doc == NULL ) {
        m_doc = NULL;
        m_ofd_Node = NULL;
    } else {
        m_doc = new XMLDocument();
        obj.m_doc->DeepCopy(m_doc);
        m_ofd_Node = m_doc->FirstChildElement();
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDObject::~FZZOFDObject()
{
    //DLOG("~FZZOFDObject()");
    FZZConst::delClassCount("FZZOFDObject");
	if (m_doc != NULL) {
		delete m_doc;
		m_doc = NULL;
	}
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDObject::getXMLData()
{
	string ret = "";
	if (m_doc != NULL) {
		XMLPrinter streamer;
		m_doc->Print(&streamer);
		ret = streamer.CStr();
#ifdef _DEBUG
		//printf("%s\n",ret.c_str());
#endif
	}
    //m_doc->Parse("");
	return ret;
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
