//
//  Created by zizheng fan on 2022/08/25.
//
#include "basic/FZZConst.h"

#include "font/FZZGenFont.h"

//#include <codecvt>


#include "font/sfntly/sfntly/font.h"
#include "font/sfntly/subtly/character_predicate.h"
#include "font/sfntly/subtly/stats.h"
#include "font/sfntly/subtly/subsetter.h"
#include "font/sfntly/subtly/utils.h"

using namespace subtly;
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZGenFont**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZGenFont::FZZGenFont() : m_isGenNewFontOK(false),m_isGenFont(true)
{
    //DLOG("FZZGenFont()");
    FZZConst::addClassCount("FZZGenFont");
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
FZZGenFont::~FZZGenFont()
{
    //DLOG("~FZZGenFont()");
    FZZConst::delClassCount("FZZGenFont");
   
}
//-----------------------------------------------------------------------------------------------------------------
void FZZGenFont::addData(string data)
{
//    int pos = m_NewFontCharData.find(data);
//    if ( pos == string::npos ) {
//        m_NewFontCharData += data;
//    }
    if ( data != " " ) {
        uint32_t unicode = StringToWstring(data.c_str());
        m_NewFontCharData.insert(unicode);
    }
    
    
    //for (const auto &unicode : wstr) {
        //addData(unicode);
   // }
}
//-----------------------------------------------------------------------------------------------------------------
void FZZGenFont::addData(int32_t data)
{

//    vector<int32_t>::const_iterator it;
//    bool isTF = false;
//    for( it = m_NewFontCharData.begin(); it != m_NewFontCharData.end(); it++ ) {
//        if ( *it == data ) {
//            isTF = true;
//            break;
//        }
//    }
//    if ( !isTF ) {
//        m_NewFontCharData.push_back(data);
//    }
    if ( data != 32 ) {
        m_NewFontCharData.insert(data);
    }
}
//-----------------------------------------------------------------------------------------------------------------
bool FZZGenFont::genNewFont(FZZBytes & newFontData)
{
    
    bool isTF = true;
    if ( m_isGenFont ) {
        if ( m_OldFontData.getLen() == 0 ) {
            //DLOG(" FZZGenFont :: font is null");
            //newFontData.setData(m_OldFontData.getData(), m_OldFontData.getLen());
            return isTF;
        }
        
        if ( m_NewFontCharData.empty() ) {
            //DLOG(" FZZGenFont :: chars is null");
            newFontData.setData(m_OldFontData.getData(), m_OldFontData.getLen());
            return isTF;
        }
        
        FontPtr font;
        font.Attach(subtly::LoadFont(m_OldFontData.getData(),(int)m_OldFontData.getLen()));
        if (font->num_tables() == 0) {
            //DLOG("FZZGenFont :: Could not load font");
            newFontData.setData(m_OldFontData.getData(), m_OldFontData.getLen());
            return isTF;
        }
        
        //std::wstring wstr = StringToWstring(m_NewFontCharData.c_str());
    //    auto charaters = new std::set<int32_t >;
    //    for (const auto &unicode : wstr) {
    //        charaters->insert((int32_t)unicode);
    //    }
        //AcceptSet delete charaters
        std::set<int32_t > * charaters = new std::set<int32_t >();
        //unordered_set<int32_t>::const_iterator it;
    //    vector<int32_t>::const_iterator it;
    //    for( it = m_NewFontCharData.begin(); it != m_NewFontCharData.end(); it++ ) {
    //        charaters->insert(*it);
    //    }
        *charaters = m_NewFontCharData;
        
        Ptr<CharacterPredicate> set_predicate =
                new AcceptSet(charaters);
        Ptr<Subsetter> subsetter = new Subsetter(font, set_predicate);
        Ptr<subtly::Font> new_font;
        new_font.Attach(subsetter->Subset());
        if (!new_font) {
            //DLOG("FZZGenFont :: Cannot create subFont.");
            newFontData.setData(m_OldFontData.getData(), m_OldFontData.getLen());
            return isTF;
        }

     
        bool success = subtly::SerializeFont(newFontData, new_font);
        if (!success) {
            //DLOG("FZZGenFont :: Cannot create font file");
            newFontData.setData(m_OldFontData.getData(), m_OldFontData.getLen());
            return isTF;
        }
    } else {
        newFontData.setData(m_OldFontData.getData(), m_OldFontData.getLen());
    }
    
    //isTF = true;
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
uint32_t FZZGenFont::StringToWstring(const char* utf8Bytes)
{
//    using convert_type = std::codecvt_utf8<typename std::wstring::value_type >;
//    std::wstring_convert<convert_type, typename std::wstring::value_type> converter;
//    return converter.from_bytes(utf8Bytes);
    string temp = utf8Bytes;
    return FZZConst::Utf8ToUtf32LE(temp);
}
//-----------------------------------------------------------------------------------------------------------------
//string FZZGenFont::WstringToString(wstring & wstr)
//{
////    using convert_type = std::codecvt_utf8<typename std::wstring::value_type >;
////    std::wstring_convert<convert_type, typename std::wstring::value_type> converter;
////    return converter.to_bytes(wstr);
//    return FZZConst::Utf32LEToUtf8(wstr.c_str()[0]);
//}
//-----------------------------------------------------------------------------------------------------------------
