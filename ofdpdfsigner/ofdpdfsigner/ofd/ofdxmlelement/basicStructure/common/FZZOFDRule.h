//
//  Created by zizheng fan on 2024/03/05.
//
#ifndef FZZOFDRULE_H
#define FZZOFDRULE_H



class FZZOFDRule
{
public:
	typedef enum {
       
        NonZero,
        
        Even_Odd
        
	} TYPE;

    static string toString(FZZOFDRule::TYPE type) {
        string temp = "NonZero";
        switch (type) {
        case FZZOFDRule::TYPE::Even_Odd:
            temp = "Even-Odd";
            break;
        case FZZOFDRule::TYPE::NonZero:
            temp = "NonZero";
            break;
        default:
            temp = "NonZero";
            break;
        
        }
        
        return temp;
    }

    static FZZOFDRule::TYPE toType(const char * const strtype) {
        FZZOFDRule::TYPE temp = FZZOFDRule::TYPE::NonZero;
        if (strcmp(strtype, "NonZero") == 0) {
            temp = FZZOFDRule::TYPE::NonZero;
        } else if (strcmp(strtype, "Even-Odd") == 0) {
            temp = FZZOFDRule::TYPE::Even_Odd;
        }
        
        return temp;
        
        
    }
};

#endif


