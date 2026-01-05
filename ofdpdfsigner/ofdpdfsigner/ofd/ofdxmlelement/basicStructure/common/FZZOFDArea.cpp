//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDArea.h"
#include "ofd/FZZOFDXMLFileObject.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDArea**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArea::FZZOFDArea() : FZZOFDXMLElementObject()
{
    //DLOG("FZZOFDArea()");
    FZZConst::addClassCount("FZZOFDArea");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArea::FZZOFDArea(FZZOFDXMLFileObject * parent,XMLDocument* doc, XMLNode* node,string key) : FZZOFDXMLElementObject(parent,doc,node,key,false)
{
    
    FZZConst::addClassCount("FZZOFDArea");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArea::FZZOFDArea(FZZOFDXMLFileObject * parent) : FZZOFDXMLElementObject(parent)
{
    FZZConst::addClassCount("FZZOFDArea");
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArea::FZZOFDArea(const FZZOFDArea& obj) : FZZOFDXMLElementObject(obj)
{
    
    FZZConst::addClassCount("FZZOFDArea");
    if ( this == &obj ) {
        return;
    }
    
    FZZOFDMove * ofdMove = NULL;
    FZZOFDLine * ofdLine = NULL;
    FZZOFDQuadraticBezier * ofdQuadraticBezier = NULL;
    FZZOFDClose * ofdClose = NULL;
    FZZOFDArc * ofdArc = NULL;
    FZZOFDCubicBezier * ofdCubicBezier = NULL;
    
    vector<FZZOFDCommand*>::const_iterator itr;
    for( itr = obj.m_FZZOFDCommands.begin(); itr != obj.m_FZZOFDCommands.end(); itr++ ) {
        FZZOFDCommand * temp = *itr;
        if ( temp != NULL ) {
            ofdMove = NULL;
            ofdLine = NULL;
            ofdQuadraticBezier = NULL;
            ofdClose = NULL;
            ofdArc = NULL;
            ofdCubicBezier = NULL;
            
            if ( ( ofdMove = dynamic_cast<FZZOFDMove*>(temp) ) != NULL ) {
                m_FZZOFDCommands.push_back(new FZZOFDMove(*ofdMove));
            } else if ( ( ofdLine = dynamic_cast<FZZOFDLine*>(temp) ) != NULL ) {
                m_FZZOFDCommands.push_back(new FZZOFDLine(*ofdLine));
            } else if ( ( ofdQuadraticBezier = dynamic_cast<FZZOFDQuadraticBezier*>(temp) ) != NULL ) {
                m_FZZOFDCommands.push_back(new FZZOFDQuadraticBezier(*ofdQuadraticBezier));
            } else if ( ( ofdClose = dynamic_cast<FZZOFDClose*>(temp) ) != NULL ) {
                m_FZZOFDCommands.push_back(new FZZOFDClose(*ofdClose));
            } else if ( ( ofdArc = dynamic_cast<FZZOFDArc*>(temp) ) != NULL ) {
                m_FZZOFDCommands.push_back(new FZZOFDArc(*ofdArc));
            } else if ( ( ofdCubicBezier = dynamic_cast<FZZOFDCubicBezier*>(temp) ) != NULL ) {
                m_FZZOFDCommands.push_back(new FZZOFDCubicBezier(*ofdCubicBezier));
            }
            
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArea::~FZZOFDArea()
{
    //DLOG("~FZZOFDArea()");
    FZZConst::delClassCount("FZZOFDArea");
    
    FZZOFDMove * ofdMove = NULL;
    FZZOFDLine * ofdLine = NULL;
    FZZOFDQuadraticBezier * ofdQuadraticBezier = NULL;
    FZZOFDClose * ofdClose = NULL;
    FZZOFDArc * ofdArc = NULL;
    FZZOFDCubicBezier * ofdCubicBezier = NULL;
    
    vector<FZZOFDCommand*>::const_iterator itr;
    for( itr = m_FZZOFDCommands.begin(); itr != m_FZZOFDCommands.end(); itr++ ) {
        FZZOFDCommand * temp = *itr;
        if ( temp != NULL ) {
            ofdMove = NULL;
            ofdLine = NULL;
            ofdQuadraticBezier = NULL;
            ofdClose = NULL;
            ofdArc = NULL;
            ofdCubicBezier = NULL;
            
            if ( ( ofdMove = dynamic_cast<FZZOFDMove*>(temp) ) != NULL ) {
                delete ofdMove;
            } else if ( ( ofdLine = dynamic_cast<FZZOFDLine*>(temp) ) != NULL ) {
                delete ofdLine;
            } else if ( ( ofdQuadraticBezier = dynamic_cast<FZZOFDQuadraticBezier*>(temp) ) != NULL ) {
                delete ofdQuadraticBezier;
            } else if ( ( ofdClose = dynamic_cast<FZZOFDClose*>(temp) ) != NULL ) {
                delete ofdClose;
            } else if ( ( ofdArc = dynamic_cast<FZZOFDArc*>(temp) ) != NULL ) {
                delete ofdArc;
            } else if ( ( ofdCubicBezier = dynamic_cast<FZZOFDCubicBezier*>(temp) ) != NULL ) {
                delete ofdCubicBezier;
            }
            
            
        }
    }
    m_FZZOFDCommands.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArea::setStart(string value)
{
    setAttribute_String("Start",value);
}
//-----------------------------------------------------------------------------------------------------------------
string FZZOFDArea::getStart()
{
    return getAttribute_String("Start");
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArea::setStart(double x, double y)
{
    string strValue;
    ST_Pos_ToString(x,y,strValue);
    setAttribute_String("Start",strValue);
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDArea::getStart(/*out*/double & x, /*out*/double & y)
{
    string strid = getAttribute_String("Start");
    ST_Pos_ToDouble(strid, x,y);
}
//-----------------------------------------------------------------------------------------------------------------
vector<FZZOFDCommand*> * FZZOFDArea::getCommands()
{
    if ( m_FZZOFDCommands.size() <= 0 ) {
        XMLElement* ele = m_ofd_Node->FirstChildElement();
        while (ele != NULL) {
            const char* elename = ele->Name();
            FZZOFDCommand * tempObject = NULL;
            
            if (strcmp(elename, FZZOFDMOVE_Name) == 0) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDMove*)NULL);
            } else if ( strcmp(elename, FZZOFDLINE_Name ) == 0 ) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDLine*)NULL);
            } else if ( strcmp(elename, FZZOFDQUADRATICBEZIER_Name ) == 0 ) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDQuadraticBezier*)NULL);
            } else if ( strcmp(elename, FZZOFDCUBICBEZIER_Name ) == 0 ) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDCubicBezier*)NULL);
            } else if ( strcmp(elename, FZZOFDARC_Name ) == 0 ) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDArc*)NULL);
            } else if ( strcmp(elename, FZZOFDCLOSE_Name ) == 0 ) {
                tempObject = FZZOFDXMLElementObject::getInstance(m_Parent,m_doc, ele,(FZZOFDClose*)NULL);
            }
                       
            if ( tempObject != NULL ) {
                m_FZZOFDCommands.push_back(tempObject);
            }

            ele = ele->NextSiblingElement();
        }//while
    }//if ( m_FZZOFDCommands.size() <= 0 )
    
    return &m_FZZOFDCommands;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDMove * FZZOFDArea::addMove()
{
    FZZOFDMove * cofdMove = NULL;
    cofdMove = addElementObject_NoAddList(cofdMove,FZZOFDMOVE_Name);
    if ( cofdMove != NULL ) {
        m_FZZOFDCommands.push_back(cofdMove);
    }
    return cofdMove;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDLine * FZZOFDArea::addLine()
{
    FZZOFDLine * ofdLine = NULL;
    ofdLine = addElementObject_NoAddList(ofdLine,FZZOFDLINE_Name);
    if ( ofdLine != NULL ) {
        m_FZZOFDCommands.push_back(ofdLine);
    }
    return ofdLine;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDQuadraticBezier * FZZOFDArea::addQuadraticBezier()
{
    FZZOFDQuadraticBezier * ofdQuadraticBezier = NULL;
    ofdQuadraticBezier = addElementObject_NoAddList(ofdQuadraticBezier,FZZOFDQUADRATICBEZIER_Name);
    if ( ofdQuadraticBezier != NULL ) {
        m_FZZOFDCommands.push_back(ofdQuadraticBezier);
    }
    return ofdQuadraticBezier;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDCubicBezier * FZZOFDArea::addCubicBezier()
{
    FZZOFDCubicBezier * ofdCubicBezier = NULL;
    ofdCubicBezier = addElementObject_NoAddList(ofdCubicBezier,FZZOFDCUBICBEZIER_Name);
    if ( ofdCubicBezier != NULL ) {
        m_FZZOFDCommands.push_back(ofdCubicBezier);
    }
    return ofdCubicBezier;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDArc * FZZOFDArea::addArc()
{
    FZZOFDArc * ofdArc = NULL;
    ofdArc = addElementObject_NoAddList(ofdArc,FZZOFDARC_Name);
    if ( ofdArc != NULL ) {
        m_FZZOFDCommands.push_back(ofdArc);
    }
    return ofdArc;
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDClose * FZZOFDArea::addClose()
{
    FZZOFDClose * ofdClose = NULL;
    ofdClose = addElementObject_NoAddList(ofdClose,FZZOFDCLOSE_Name);
    if ( ofdClose != NULL ) {
        m_FZZOFDCommands.push_back(ofdClose);
    }
    return ofdClose;
}
//-----------------------------------------------------------------------------------------------------------------
