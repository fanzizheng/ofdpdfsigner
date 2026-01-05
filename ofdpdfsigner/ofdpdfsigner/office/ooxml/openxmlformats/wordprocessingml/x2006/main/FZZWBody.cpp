//
//  Created by zizheng fan on 2023/08/31
//
#include "basic/FZZConst.h"
#include "office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBody.h"
#include "office/FZZOfficeObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZWBody**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZWBody::FZZWBody() : FZZXMLElementObject(),m_FZZWSectPr(NULL)
{
    //DLOG("FZZWBody()");
    FZZConst::addClassCount("FZZWBody");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBody::FZZWBody(FZZOfficeObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZXMLElementObject(parent,doc,node,key,true),m_FZZWSectPr(NULL)
{
    //DLOG("CT_Action(XMLDocument* doc, XMLNode* node)");
    FZZConst::addClassCount("FZZWBody");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBody::FZZWBody(FZZOfficeObject * parent) : FZZXMLElementObject(parent),m_FZZWSectPr(NULL)
{
    FZZConst::addClassCount("FZZWBody");
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBody::FZZWBody(const FZZWBody& obj) : FZZXMLElementObject(obj)
{
    //DLOG("CT_Action(const CT_Action& obj)");
    FZZConst::addClassCount("FZZWBody");
    if ( this == &obj ) {
        return;
    }
    m_FZZWSectPr = obj.m_FZZWSectPr != NULL ? new FZZWSectPr(*obj.m_FZZWSectPr) : NULL;
    
    
    vector<FZZWP*>::const_iterator itr;
    for( itr = obj.m_FZZWPs.begin(); itr != obj.m_FZZWPs.end(); itr++ ) {
        FZZWP * temp = *itr;
        if ( temp != NULL ) {
            m_FZZWPs.push_back(new FZZWP(*temp));
        }
    }
    
    vector<FZZWTbl*>::const_iterator itr_FZZWTbl;
    for( itr_FZZWTbl = obj.m_FZZWTbls.begin(); itr_FZZWTbl != obj.m_FZZWTbls.end(); itr_FZZWTbl++ ) {
        FZZWTbl * temp = *itr_FZZWTbl;
        if ( temp != NULL ) {
            m_FZZWTbls.push_back(new FZZWTbl(*temp));
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZWBody::~FZZWBody()
{
    //DLOG("~FZZWBody()");
    FZZConst::delClassCount("FZZWBody");
    if ( m_FZZWSectPr != NULL ) {
        delete m_FZZWSectPr;
        m_FZZWSectPr = NULL;
    }
    
    
    
    
    vector<FZZWP*>::const_iterator itr;
    for( itr = m_FZZWPs.begin(); itr != m_FZZWPs.end(); itr++ ) {
        FZZWP * temp = *itr;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWPs.clear();
    
    vector<FZZWTbl*>::const_iterator itr_FZZWTbl;
    for( itr_FZZWTbl = m_FZZWTbls.begin(); itr_FZZWTbl != m_FZZWTbls.end(); itr_FZZWTbl++ ) {
        FZZWTbl * temp = *itr_FZZWTbl;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FZZWTbls.clear();
    
    vector<PageElement*>::const_iterator itr_PageElement;
    for( itr_PageElement = m_AllPageElements.begin(); itr_PageElement != m_AllPageElements.end(); itr_PageElement++ ) {
        PageElement * temp = *itr_PageElement;
        if ( temp != NULL ) {
            if ( temp->object != NULL ) {
                delete temp->object;
            }
            delete temp;
        }
    }
    m_AllPageElements.clear();
}
//-----------------------------------------------------------------------------------------------------------------
FZZWP * FZZWBody::addP()
{
    return addElementObject(&m_FZZWPs,FZZWP_Find_Key,FZZWP_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWP*> * FZZWBody::getPList()
{
    getElementObjectList(&m_FZZWPs,FZZWP_Find_Key,FZZWP_Name);
    return &m_FZZWPs;
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSectPr * FZZWBody::setSectPr()
{
    return m_FZZWSectPr = setElementObject(m_FZZWSectPr,FZZWSECTPT_Find_Key,FZZWSECTPT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWSectPr * FZZWBody::getSectPr()
{
    return m_FZZWSectPr = getElementObject(m_FZZWSectPr,FZZWSECTPT_Find_Key,FZZWSECTPT_Name);
}
//-----------------------------------------------------------------------------------------------------------------
FZZWTbl * FZZWBody::addTable()
{
    return addElementObject(&m_FZZWTbls,FZZWTBL_Find_Key,FZZWTBL_Name);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZWTbl*> * FZZWBody::getTableList()
{
    getElementObjectList(&m_FZZWTbls,FZZWTBL_Find_Key,FZZWTBL_Name);
    return &m_FZZWTbls;
}
//-----------------------------------------------------------------------------------------------------------------
vector<PageElement*>* FZZWBody::getPageElements()
{
    if ( m_ofd_Node == NULL ) {
        return &m_AllPageElements;
    }
    
    if ( m_AllPageElements.size() > 0 ) {
        return &m_AllPageElements;
    }
    
    //vector<FZZWPPr*>::const_iterator itr_ppr;
    
  
    FZZWSectPr * tempSectPr = NULL;
    FZZWPPr * tempPpr = NULL;
    FZZWP* tempP = NULL;
    //vector<FZZWPPr*> * pprlist = NULL;
    PageElement* tempPageEle = NULL;
    FZZXMLElementObject * tempElementObject = NULL;
    XMLElement* ele = m_ofd_Node->FirstChildElement();
    bool isHaveHeader = false;
    bool isHaveFooter = false;
    while (ele != NULL) {
        tempElementObject = NULL;
        string elename = ele->Name();
        if ( elename == "w:sectPr" ) {
            tempElementObject = FZZXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZWSectPr*)NULL);
            if ( tempElementObject != NULL ) {
                RefreshAllPageElements((FZZWSectPr *)tempElementObject);
                
                vector<FZZWFooterReference*> * ctwFooterList = ((FZZWSectPr *)tempElementObject)->getFooterReferences();
                vector<FZZWHeaderReference*> * ctwHeaderList = ((FZZWSectPr *)tempElementObject)->getHeaderReferences();
                if ( ctwFooterList->size() > 0 || ctwHeaderList->size() > 0 ) {
                    if ( ctwFooterList->size() > 0 ) {
                        isHaveFooter = true;
                    }
                    if ( ctwHeaderList->size() > 0 ) {
                        isHaveHeader = true;
                    }
                    RefreshAllPageElements_HeaderAndFooter(ctwFooterList,ctwHeaderList);
                }
                
                delete tempElementObject;
                tempElementObject = NULL;
            }
        } else if (elename == "w:p") {
            tempElementObject = FZZXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZWP*)NULL);
        } else if (elename == "w:tbl") {
            tempElementObject = FZZXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZWTbl*)NULL);
        }

        if ( tempElementObject != NULL ) {
            tempPageEle = new PageElement();
            if ( tempPageEle != NULL ) {
                tempPageEle->type = elename;
                tempPageEle->pageHeight = -1;
                tempPageEle->pageWidth = -1;
                tempPageEle->pgMar_Top = 0;
                tempPageEle->pgMar_Right = 0;
                tempPageEle->pgMar_Bottom = 0;
                tempPageEle->pgMar_Left = 0;
                tempPageEle->pgMar_Header = 0;
                tempPageEle->pgMar_Footer = 0;
                tempPageEle->pgMar_Gutter = 0;
                tempPageEle->colsSpace = 0;
                tempPageEle->titlePg = false;
                tempPageEle->object = tempElementObject;
                tempPageEle->isHaveHeader = isHaveHeader;
                tempPageEle->isHaveFooter = isHaveFooter;
                tempPageEle->isHaveHeaderOrFooter_tmp = false;
//                tempPageEle->footer_Default_Type = "";
//                tempPageEle->footer_Even_Type = "";
//                tempPageEle->footer_First_Type = "";
//                tempPageEle->header_Default_Type = "";
//                tempPageEle->header_Even_Type = "";
//                tempPageEle->header_First_Type = "";
                
                tempPageEle->footer_Default_rid = "";
                tempPageEle->footer_Even_rid = "";
                tempPageEle->footer_First_rid = "";
                tempPageEle->header_Default_rid = "";
                tempPageEle->header_Even_rid = "";
                tempPageEle->header_First_rid = "";
                m_AllPageElements.push_back(tempPageEle);
                
                if ( elename == "w:p" ) {
                    tempP = (FZZWP*)tempElementObject;
                    tempPpr = tempP->getPPr();
                    if ( tempPpr != NULL ) {
                        tempSectPr = tempPpr->getSectPr();
                        if ( tempSectPr != NULL ) {
                            RefreshAllPageElements(tempSectPr);
                            vector<FZZWFooterReference*> * ctwFooterList = tempSectPr->getFooterReferences();
                            vector<FZZWHeaderReference*> * ctwHeaderList = tempSectPr->getHeaderReferences();
                            if ( ctwFooterList->size() > 0 || ctwHeaderList->size() > 0 ) {
                                if ( ctwFooterList->size() > 0 ) {
                                    isHaveFooter = true;
                                }
                                if ( ctwHeaderList->size() > 0 ) {
                                    isHaveHeader = true;
                                }
                                RefreshAllPageElements_HeaderAndFooter(ctwFooterList,ctwHeaderList);
                            }
                        }//if ( tempSectPr != NULL )
                        
                    } //if ( tempPpr != NULL )
                            
                }//if ( elename == "w:p" )
            } else {
                delete tempElementObject;
                tempElementObject = NULL;
            }
        }
        
        
        ele = ele->NextSiblingElement();
    }
    return &m_AllPageElements;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWBody::RefreshAllPageElements(FZZWSectPr * ctwSectPr)
{
    FZZWPgSz * tempPgSz = NULL;
    FZZWPgMar * tempPgMar = NULL;
    FZZWCols * tempCols = NULL;
    FZZWDocGrid * tempDocGrid = NULL;
    PageElement* tempPageEle = NULL;
    FZZWTitlePg * titlePg = NULL;
    vector<PageElement*>::const_iterator itr_PageElement;
    FZZWSectPr * tempSectPr = ctwSectPr;
    if ( tempSectPr != NULL ) {
        tempDocGrid = tempSectPr->getDocGrid();
        tempCols = tempSectPr->getCols();
        tempPgMar = tempSectPr->getPgMar();
        tempPgSz = tempSectPr->getPgSz();
        titlePg = tempSectPr->getTitlePg();
        
        
        if ( tempPgSz != NULL ) {
            for( itr_PageElement = m_AllPageElements.end()-1; itr_PageElement >=  m_AllPageElements.begin(); itr_PageElement-- ) {
                tempPageEle = *itr_PageElement;
                if ( tempPageEle != NULL ) {
                    tempPageEle->titlePg = titlePg != NULL;
                    if ( tempPageEle->pageWidth == -1 && tempPageEle->pageHeight == -1 ) {
                        tempPageEle->pageWidth = strtol(tempPgSz->getW().c_str(),NULL,10);
                        tempPageEle->pageHeight = strtol(tempPgSz->getH().c_str(),NULL,10);
                        if ( tempPgMar != NULL ) {
                            tempPageEle->pgMar_Top = strtol(tempPgMar->getTop().c_str(),NULL,10);
                            tempPageEle->pgMar_Right = strtol(tempPgMar->getRight().c_str(),NULL,10);
                            tempPageEle->pgMar_Bottom = strtol(tempPgMar->getBottom().c_str(),NULL,10);
                            tempPageEle->pgMar_Left = strtol(tempPgMar->getLeft().c_str(),NULL,10);
                            tempPageEle->pgMar_Header = strtol(tempPgMar->getHeader().c_str(),NULL,10);
                            tempPageEle->pgMar_Footer = strtol(tempPgMar->getFooter().c_str(),NULL,10);
                            tempPageEle->pgMar_Gutter = strtol(tempPgMar->getGutter().c_str(),NULL,10);
                            
                        }
                        if ( tempCols != NULL ) {
                            string strColsNum = tempCols->getNum();
                            if ( strColsNum.empty() ) {
                                tempPageEle->colsNum = 1;
                            } else {
                                tempPageEle->colsNum = strtol(strColsNum.c_str(),NULL,10);
                            }
                            
                            tempPageEle->colsSpace = strtol(tempCols->getSpace().c_str(),NULL,10);
                        }
                        if ( tempDocGrid != NULL ) {
                            tempPageEle->docGrid_type = tempDocGrid->getType();
                            if ( tempPageEle->docGrid_type == "lines" ) {
                                tempPageEle->docGrid_value = strtol(tempDocGrid->getLinePitch().c_str(),NULL,10);
                                if ( tempPageEle->docGrid_value == 1 ) {
                                    tempPageEle->docGrid_value = 312;
                                }
                            } else if (tempPageEle->docGrid_type == "linesAndChars") {
                                long lines = strtol(tempDocGrid->getLinePitch().c_str(),NULL,10);
                                long chars = strtol(tempDocGrid->getCharSpace().c_str(),NULL,10);
                                tempPageEle->docGrid_value = abs(lines+chars);
                                if ( tempPageEle->docGrid_value > 30 ) {
                                    //tempPageEle->docGrid_value = tempPageEle->docGrid_value / 10;
                                    tempPageEle->docGrid_value = 312;
                                }
                            }
                        } else {
                            tempPageEle->docGrid_type = "";
                            tempPageEle->docGrid_value = 0;
                        }
                        
                        
                    } else {
                        break;
                    }
                }
            } //for
            
            
        }//if ( tempPgSz != NULL )
    }//if ( tempSectPr != NULL )
}
//-----------------------------------------------------------------------------------------------------------------
void FZZWBody::RefreshAllPageElements_HeaderAndFooter(vector<FZZWFooterReference*> * ctwFooterList,vector<FZZWHeaderReference*> * ctwHeaderList)
{
    vector<PageElement*>::const_iterator itr_PageElement;
    PageElement* tempPageEle = NULL;
    for( itr_PageElement = m_AllPageElements.end()-1; itr_PageElement >=  m_AllPageElements.begin(); itr_PageElement-- ) {
        tempPageEle = *itr_PageElement;
        if ( tempPageEle != NULL ) {
            if ( tempPageEle->isHaveHeaderOrFooter_tmp ) {
                break;
            } else {
                tempPageEle->isHaveHeaderOrFooter_tmp = true;
                
                if ( ctwFooterList->size() > 0 ) {
                    tempPageEle->isHaveFooter = true;
                    vector<FZZWFooterReference*>::const_iterator footer_itr;
                    for( footer_itr = ctwFooterList->begin(); footer_itr != ctwFooterList->end(); footer_itr++ ) {
                        FZZWFooterReference * temp = *footer_itr;
                        if ( temp != NULL ) {
                            string strType = temp->getType();
                            string strRid = temp->getRID();
                            if ( strRid.empty() ) {
                                continue;
                            }
                                                   
                            if ( strType == "even" ) {
                                tempPageEle->footer_Even_rid = strRid;
                            } else if ( strType == "default" ) {
                                tempPageEle->footer_Default_rid = strRid;
                            } else if ( strType == "first" ) {
                                tempPageEle->footer_First_rid = strRid;
                            }
                            
                        }
                    }
                }
                if ( ctwHeaderList->size() > 0) {
                    tempPageEle->isHaveHeader = true;
                    vector<FZZWHeaderReference*>::const_iterator header_itr;
                    for( header_itr = ctwHeaderList->begin(); header_itr != ctwHeaderList->end(); header_itr++ ) {
                        FZZWHeaderReference * temp = *header_itr;
                        if ( temp != NULL ) {
                            string strType = temp->getType();
                            string strRid = temp->getRID();
                            if ( strRid.empty() ) {
                                continue;
                            }
                                                   
                            if ( strType == "even" ) {
                                tempPageEle->header_Even_rid = strRid;
                            } else if ( strType == "default" ) {
                                tempPageEle->header_Default_rid = strRid;
                            } else if ( strType == "first" ) {
                                tempPageEle->header_First_rid = strRid;
                            }
                            
                        }
                    }
                }
            }
        }//if ( tempPageEle != NULL )
    }//for
    
    
    
}
//-----------------------------------------------------------------------------------------------------------------
