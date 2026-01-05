//
//  Created by zizheng fan on 2024/03/11.
//
#ifndef FZZOFDCONST_H
#define FZZOFDCONST_H

#include "basic/FZZConst.h"

void ST_ID_ToString(long id,/*out*/string & strId);
void ST_ID_ToLong(string & strId,/*out*/long & id);

void ST_Pos_ToString(double x, double y,/*out*/string & strPos);
void ST_Pos_ToDouble(string & value,/*out*/double & x, /*out*/double & y);

void ST_Pos_ToString(double x, double y,/*out*/string & strPos);
void ST_Pos_ToDouble(string & value,/*out*/double & x, /*out*/double & y);

void ST_Box_ToString(double x, double y,double width, double height,/*out*/string & strPos);
void ST_Box_ToDouble(string & value,/*out*/double & x, /*out*/double & y,/*out*/double & width, /*out*/double & height);

void ST_Array_ToString(double a1,double a2,double a3,double a4,double a5,double a6,/*out*/string & value);
void ST_Array_ToString(const vector<string> & array,/*out*/string & value);
void ST_Array_ToArray(string & value, /*out*/vector<string> & array);
void ST_Array_ToArray(string & value, /*out*/vector<double> & array);
//ST_Array Mul
string CTM_Mul(double A0,double A1,double A2,double A3,double A4,double A5,double B0,double B1,double B2,double B3,double B4,double B5);

#endif //FZZOFDCONST_H
