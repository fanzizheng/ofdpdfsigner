//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDDIRECTION_H
#define FZZOFDDIRECTION_H



class FZZOFDDirection
{
public:
    typedef enum {
        Angle_0,
        Angle_90,
        Angle_180,
        Angle_270
    } TYPE;

    static string toString(FZZOFDDirection::TYPE type) {
        string ret = "0";
        switch (type) {
            case FZZOFDDirection::TYPE::Angle_0:
                ret = "0";
                break;
            case FZZOFDDirection::TYPE::Angle_90:
                ret = "90";
                break;
            case FZZOFDDirection::TYPE::Angle_180:
                ret = "180";
                break;
            case FZZOFDDirection::TYPE::Angle_270:
                ret = "270";
                break;
            
            default:
                ret = "0";
                break;

        }
        
        return ret;
    }

    static FZZOFDDirection::TYPE toType(const char * const strtype) {
        FZZOFDDirection::TYPE temp = FZZOFDDirection::TYPE::Angle_0;
        if (strcmp(strtype, "0") == 0) {
            temp = FZZOFDDirection::TYPE::Angle_0;
        }
        else if (strcmp(strtype, "90") == 0) {
            temp = FZZOFDDirection::TYPE::Angle_90;
        }
        else if (strcmp(strtype, "180") == 0) {
            temp = FZZOFDDirection::TYPE::Angle_180;
        }
        else if (strcmp(strtype, "270") == 0) {
            temp = FZZOFDDirection::TYPE::Angle_270;
        }
        
        return temp;
        
        
    }
};

#endif


