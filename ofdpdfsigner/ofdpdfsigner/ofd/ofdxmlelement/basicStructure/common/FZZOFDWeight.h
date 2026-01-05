//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDWEIGHT_H
#define FZZOFDWEIGHT_H



class FZZOFDWeight
{
public:
    typedef enum {
        W_100 = 100,
        W_200 = 200,
        W_300 = 300,
        /**
         * default
         */
         W_400 = 400,
         W_500 = 500,
         W_600 = 600,
         W_700 = 700,
         W_800 = 800,
         W_900 = 900
    } TYPE;

    static string toString(FZZOFDWeight::TYPE type) {
        string ret = "400";
        switch (type) {
            case FZZOFDWeight::TYPE::W_400:
                ret = "400";
                break;
            case FZZOFDWeight::TYPE::W_100:
                ret = "100";
                break;
            case FZZOFDWeight::TYPE::W_200:
                ret = "200";
                break;
            case FZZOFDWeight::TYPE::W_300:
                ret = "300";
                break;
            case FZZOFDWeight::TYPE::W_500:
                ret = "500";
                break;
            case FZZOFDWeight::TYPE::W_600:
                ret = "600";
                break;
            case FZZOFDWeight::TYPE::W_700:
                ret = "700";
                break;
            case FZZOFDWeight::TYPE::W_800:
                ret = "800";
                break;
            case FZZOFDWeight::TYPE::W_900:
                ret = "900";
                break;
            default:
                ret = "400";
                break;

        }
        return ret;
    }

    static FZZOFDWeight::TYPE toType(const char * const data) {
        FZZOFDWeight::TYPE temp = FZZOFDWeight::TYPE::W_400;
        if (strcmp(data, "400") == 0) {
            temp = FZZOFDWeight::TYPE::W_400;
        }
        else if (strcmp(data, "100") == 0) {
            temp = FZZOFDWeight::TYPE::W_100;
        }
        else if (strcmp(data, "200") == 0) {
            temp = FZZOFDWeight::TYPE::W_200;
        }
        else if (strcmp(data, "300") == 0) {
            temp = FZZOFDWeight::TYPE::W_300;
        }
        else if (strcmp(data, "500") == 0) {
            temp = FZZOFDWeight::TYPE::W_500;
        }
        else if (strcmp(data, "600") == 0) {
            temp = FZZOFDWeight::TYPE::W_600;
        }
        else if (strcmp(data, "700") == 0) {
            temp = FZZOFDWeight::TYPE::W_700;
        }
        else if (strcmp(data, "800") == 0) {
            temp = FZZOFDWeight::TYPE::W_800;
        }
        else if (strcmp(data, "900") == 0) {
            temp = FZZOFDWeight::TYPE::W_900;
        }
        
        return temp;
        
        
    }
};

#endif


