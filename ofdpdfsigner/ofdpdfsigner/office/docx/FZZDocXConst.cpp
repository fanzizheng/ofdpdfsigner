//
//  Created by zizheng fan on 2023/04/03.
//
#include "basic/FZZConst.h"
#include "office/docx/FZZDocXConst.h"

//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZDocXConst**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
long MillimetersToETU(float mm)
{
    return mm/25.4*914400;
}
//-----------------------------------------------------------------------------------------------------------------
long PixelToETU(float pix)
{
    return pix/72*914400;
}
//-----------------------------------------------------------------------------------------------------------------
float ETUToMillimeters(long etu)
{
    return (float)etu/914400*25.4;
}
//-----------------------------------------------------------------------------------------------------------------
float ETUToPixel(long etu)
{
    return (float)etu/914400*72;
}
//-----------------------------------------------------------------------------------------------------------------
float PoundToPixel(long Pound)
{
    return (float)Pound/20;
}
//-----------------------------------------------------------------------------------------------------------------
long PixelToPound(float pix)
{
    return pix*20;
}
//-----------------------------------------------------------------------------------------------------------------
float PoundToMillimeters(long Pound)
{
    return (float)Pound/20/72*25.4;
}
//-----------------------------------------------------------------------------------------------------------------
long MillimetersToPound(float mm)
{
    return mm/25.4*72*20;
}
//-----------------------------------------------------------------------------------------------------------------
float Alpha_WordToPDF(string alpha)
{
    long data = strtol(alpha.c_str(), NULL, 10);
    return data/(float)100000;
}
//-----------------------------------------------------------------------------------------------------------------
string Alpha_PDFToWord(float alpha)
{
    long data = alpha*100000;
    return FZZConst::fmt(data);
}
//-----------------------------------------------------------------------------------------------------------------
int Alpha_WordToOFD(string alpha)
{
    return Alpha_WordToPDF(alpha)*255;
}
//-----------------------------------------------------------------------------------------------------------------
string Alpha_OFDToWord(int alpha)
{
    return Alpha_PDFToWord(alpha/(float)255);
}
//-----------------------------------------------------------------------------------------------------------------
string ColorToString(int r,int g,int b)
{
    string retstr = "";
    char buf[4] = {0};
    sprintf(buf,"%02X",r);
    retstr += buf;
    sprintf(buf,"%02X",g);
    retstr += buf;
    sprintf(buf,"%02X",b);
    retstr += buf;
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
void ColorToInt(string colorstr,bool isAuto_white,int & r,int & g,int & b)
{
    if ( colorstr.find("auto") != string::npos ) {
        if ( isAuto_white ) {
            r = 255;
            g = 255;
            b = 255;
        } else {
            r = 0;
            g = 0;
            b = 0;
        }
        return;
    }
    if ( colorstr.find("black") != string::npos ) {
        r = 0;
        g = 0;
        b = 0;
        return;
    }
    if ( colorstr.find("red") != string::npos ) {
        r = 255;
        g = 0;
        b = 0;
        return;
    }
    
    size_t len = colorstr.length();
    if ( len >= 6 ) {
        string temp = "";
        size_t beginpos = 0;
        temp = colorstr.substr(0,1);
        if ( temp == "#" ) {
            beginpos = 1;
        }
        
        temp = colorstr.substr(beginpos+0,2);
        r = (int)strtol(temp.c_str(), NULL, 16);
        temp = colorstr.substr(beginpos+2,2);
        g = (int)strtol(temp.c_str(), NULL, 16);
        temp = colorstr.substr(beginpos+4,2);
        b = (int)strtol(temp.c_str(), NULL, 16);
    }
 
}
//-----------------------------------------------------------------------------------------------------------------
void stringToPt(string data,float & X)
{
    if ( data.empty() ) {
        X = (float)0.0;
        return;
    }
    size_t pos = data.find("pt");
    if ( pos != string::npos ) {
        data = data.substr(0,pos);
        X = strtof(data.c_str(), NULL);
        return;
    }
    pos = data.find("mm");
    if ( pos != string::npos ) {
        data = data.substr(0,pos);
        X = strtof(data.c_str(), NULL);
        X = X * 72 / 25.4;
        return;
    }
    X = strtof(data.c_str(), NULL);
}
//-----------------------------------------------------------------------------------------------------------------
void stringToPt_defautPound(string data,float & X)
{
    if ( data.empty() ) {
        X = (float)0.0;
        return;
    }
    size_t pos = data.find("pt");
    if ( pos != string::npos ) {
        data = data.substr(0,pos);
        X = strtof(data.c_str(), NULL);
        return;
    }
    pos = data.find("mm");
    if ( pos != string::npos ) {
        data = data.substr(0,pos);
        X = strtof(data.c_str(), NULL);
        X = X * 72 / 25.4;
        return;
    }
    long X1 = strtol(data.c_str(), NULL,10);
    X = PoundToPixel(X1);
}
//-----------------------------------------------------------------------------------------------------------------
void stringToPt(string data,float & X,float & Y)
{
    if ( data.empty() ) {
        X = (float)0.0;
        Y = (float)0.0;
        return;
    }
    vector<string> strlist;
    FZZConst::split(data.c_str(), ",", strlist);
    if ( strlist.size() == 2 ) {
        stringToPt(strlist[0],X);
        stringToPt(strlist[1],Y);
    } else {
        X = (float)0.0;
        Y = (float)0.0;
    }
    strlist.clear();
}
//-----------------------------------------------------------------------------------------------------------------
void stringToPt_defautPound(string data,float & X,float & Y)
{
    if ( data.empty() ) {
        X = (float)0.0;
        Y = (float)0.0;
        return;
    }
    vector<string> strlist;
    FZZConst::split(data.c_str(), ",", strlist);
    if ( strlist.size() == 2 ) {
        stringToPt_defautPound(strlist[0],X);
        stringToPt_defautPound(strlist[1],Y);
    } else {
        X = (float)0.0;
        Y = (float)0.0;
    }
    strlist.clear();
}
//-----------------------------------------------------------------------------------------------------------------
string PtToString(float X)
{
    return FZZConst::fmt(X)+"pt";
}
//-----------------------------------------------------------------------------------------------------------------
void stringToRect(string data,float & X,float & Y,float & width,float &height)
{
    if ( data.empty() ) {
        X = (float)0.0;
        Y = (float)0.0;
        width = (float)0.0;
        height = (float)0.0;
        return;
    }
    vector<string> strlist;
    FZZConst::split(data.c_str(), ",", strlist);
    if ( strlist.size() == 4 ) {
        stringToPt(strlist[0],X);
        stringToPt(strlist[1],Y);
        stringToPt(strlist[2],width);
        stringToPt(strlist[3],height);
    } else {
        X = (float)0.0;
        Y = (float)0.0;
        width = (float)0.0;
        height = (float)0.0;
    }
    strlist.clear();
}
//-----------------------------------------------------------------------------------------------------------------
//uint32_t Utf32LeToUtf32Be(uint32_t code)
//{
//    unsigned char * bytes = (unsigned char *)&code;
//    uint32_t ret = (uint32_t)(((unsigned char)bytes[3] << 24) |
//                     ((unsigned char)bytes[2] << 16) |
//                     ((unsigned char)bytes[1] << 8) |
//                     (unsigned char)bytes[0]);
//    return ret;
//}
//-----------------------------------------------------------------------------------------------------------------
bool isKorea(uint32_t code)
{
    bool isTF = false;
//    uint32_t temp = Utf32LeToUtf32Be(code);
//    if ( temp >= 0xAC00 && temp <= 0xD7A3 ) {
//        isTF = true;
//    } else if ( temp >= 0x3130 && temp <= 0x318F ) {
//        isTF = true;
//    } else if ( temp >= 0x1100 && temp <= 0x11FF ) {
//        isTF = true;
//    }
    if ( code >= 0xAC00 && code <= 0xD7A3 ) {
        isTF = true;
    } else if ( code >= 0x3130 && code <= 0x318F ) {
        isTF = true;
    } else if ( code >= 0x1100 && code <= 0x11FF ) {
        isTF = true;
    }
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
bool isJapan(uint32_t code)
{
    bool isTF = false;
//    uint32_t temp = Utf32LeToUtf32Be(code);
//    if ( temp >= 0x3040 && temp <= 0x30FF ) {
//        isTF = true;
//    } else if ( temp >= 0x31F0 && temp <= 0x31FF ) {
//        isTF = true;
//    }
    
    if ( code >= 0x3040 && code <= 0x30FF ) {
        isTF = true;
    } else if ( code >= 0x31F0 && code <= 0x31FF ) {
        isTF = true;
    }
    return isTF;
}
//-----------------------------------------------------------------------------------------------------------------
void xmldata_format(char * data,size_t datalen,FZZBytes * outdata)
{
    if ( outdata == NULL ) {
        return;
    }
    char * tempChar = (char *)malloc(datalen+1);
    if ( tempChar == NULL ) {
        return;
    }
    memset(tempChar,0x00,datalen+1);
    memcpy(tempChar,data,datalen);
    
    string strdata = tempChar;
    free(tempChar);
    
    string find_value = "xml:space=\"preserve\"";
    string find_value2 = ">";
    
    string newStrData = "";
    string::size_type pos = 0;
    string::size_type beginpos = 0;
    while ( (pos = strdata.find(find_value,pos))!= string::npos ) {
        newStrData += strdata.substr(beginpos,pos - beginpos +find_value.length());
        beginpos = pos + find_value.length();
        pos = beginpos;
        //strdata = strdata.substr(pos+find_value.length());
        if ( (pos = strdata.find(find_value2,pos))!= string::npos ) {
            newStrData += strdata.substr(beginpos,pos - beginpos +find_value2.length());
            beginpos = pos + find_value2.length();
            pos = beginpos;
            //strdata = strdata.substr(pos+find_value2.length());
            //WS -> WhiteSpace
            newStrData += "|*WS*|";
        }
    }
    
    newStrData += strdata.substr(beginpos,strdata.length()-beginpos);
    
    outdata->setData((unsigned char *)(newStrData.c_str()), newStrData.length());
}
//-----------------------------------------------------------------------------------------------------------------
string xmldata_format_value(string data)
{
    //WS -> WhiteSpace
    string finevalue = "|*WS*|";
    string newStrData = "";
    string::size_type pos = 0;
    if ( (pos = data.find(finevalue))!= string::npos ) {
        newStrData = data.substr(pos+finevalue.length(),data.length()-pos-finevalue.length());
    } else {
        newStrData = data;
    }
    return newStrData;
}
//-----------------------------------------------------------------------------------------------------------------
string numToChinese(long num)
{
    vector<string> digits = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
    vector<string> units = {"", "十", "百", "千"};
    vector<string> thousands = {"", "万", "亿"};
    vector<string> result;
    string retstr = "";
  
    int unit = 0;
    int digit = 0;
    while (num > 0) {
        int d = num % 10;
        if (d != 0) {
            result.insert(result.begin(), digits[d] + units[unit]);
        } else if (result.empty() || result[0] != "零") {
            result.insert(result.begin(), digits[0] + units[unit]);
        }
        num /= 10;
        unit++;
        digit++;
        if (digit == 4 && d == 0 && unit != 0) {
            result.insert(result.begin(), thousands[digit / 4]);
            digit = 0;
            unit = 0;
        }
    }
  
    
    vector<string>::const_iterator itr;
    for ( itr = result.begin(); itr != result.end(); itr++ ) {
        retstr += *itr;
    }
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
