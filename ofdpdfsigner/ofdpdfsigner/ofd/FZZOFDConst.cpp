//
//  Created by zizheng fan on 2024/03/11.
//
#include "ofd/FZZOFDConst.h"


//-----------------------------------------------------------------------------------------------------------------
void ST_ID_ToString(long id,/*out*/string & strId)
{
    strId = std::to_string(id);
}
//-----------------------------------------------------------------------------------------------------------------
void ST_ID_ToLong(string & strId,/*out*/long & id)
{
    id = strtol(strId.c_str(),NULL,10);
}
//-----------------------------------------------------------------------------------------------------------------
void ST_Pos_ToString(double x, double y,/*out*/string & strPos)
{
    strPos = FZZConst::fmt(x) + " " + FZZConst::fmt(y);
}
//-----------------------------------------------------------------------------------------------------------------
void ST_Pos_ToDouble(string & value,/*out*/double & x, /*out*/double & y)
{
    size_t pos = value.find(" ");
    if ( pos != string::npos ) {
        x = strtod(value.substr(0, pos).c_str(),NULL);
        y = strtod(value.substr(pos+1).c_str(),NULL);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void ST_Box_ToString(double x, double y,double width, double height,/*out*/string & strPos)
{
    strPos = FZZConst::fmt(x) + " " + FZZConst::fmt(y) + " " + FZZConst::fmt(width) + " " + FZZConst::fmt(height);
}
//-----------------------------------------------------------------------------------------------------------------
void ST_Box_ToDouble(string & value,/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height)
{
    vector<std::string> list;
    FZZConst::split(value.c_str(), " ", list);
    if ( list.size() == 4 ) {
        x = strtod((*(list.begin())).c_str(),NULL);
        y = strtod((*(list.begin()+1)).c_str(),NULL);
        width = strtod((*(list.begin()+2)).c_str(),NULL);
        height = strtod((*(list.begin()+3)).c_str(),NULL);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void ST_Array_ToString(double a1,double a2,double a3,double a4,double a5,double a6,/*out*/string & value)
{
    value = FZZConst::fmt(a1) + " " + FZZConst::fmt(a2) + " " + FZZConst::fmt(a3) + " " + FZZConst::fmt(a4) + " " + FZZConst::fmt(a5) + " " + FZZConst::fmt(a6);
}
//-----------------------------------------------------------------------------------------------------------------
void ST_Array_ToString(const vector<string> & array,/*out*/string & value)
{
    string ret = "";
    bool istf = false;
    vector<string>::const_iterator iter;
    for (iter = array.begin(); iter != array.end(); iter++) {
        ret = ret + *iter;
        ret = ret + " ";
        istf = true;
    }
    
    value = istf?ret.substr(0,ret.length()-1):ret;
}
//-----------------------------------------------------------------------------------------------------------------
void ST_Array_ToArray(string & value, /*out*/vector<string> & array)
{
    FZZConst::split(value.c_str()," ", array);
}
//-----------------------------------------------------------------------------------------------------------------
void ST_Array_ToArray(string & value, /*out*/vector<double> & array)
{
    vector<string> strarray;
    FZZConst::split(value.c_str()," ", strarray);
    vector<string>::const_iterator itr;
    for ( itr = strarray.begin(); itr != strarray.end(); itr++  ) {
        array.push_back(strtod((*itr).c_str(), NULL));
    }
}
//-----------------------------------------------------------------------------------------------------------------
string CTM_Mul(double A0,double A1,double A2,double A3,double A4,double A5,double B0,double B1,double B2,double B3,double B4,double B5)
{
    double a[3][3];
    a[0][0] = A0;
    a[0][1] = A1;
    a[0][2] = 0;
    a[1][0] = A2;
    a[1][1] = A3;
    a[1][2] = 0;
    a[2][0] = A4;
    a[2][1] = A5;
    a[2][2] = 0;


    double b[3][3];
    b[0][0] = B0;
    b[0][1] = B1;
    b[0][2] = 0;
    b[1][0] = B2;
    b[1][1] = B3;
    b[1][2] = 0;
    b[2][0] = B4;
    b[2][1] = B5;
    b[2][2] = 0;

    double res[3][3];

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    string strdata = FZZConst::fmt(res[0][0])+" ";
    strdata += FZZConst::fmt(res[0][1]) + " ";
    strdata += FZZConst::fmt(res[1][0]) + " ";
    strdata += FZZConst::fmt(res[1][1]) + " ";
    strdata += FZZConst::fmt(res[2][0]) + " ";
    strdata += FZZConst::fmt(res[2][1]) + " ";

    return strdata;
}
//-----------------------------------------------------------------------------------------------------------------
