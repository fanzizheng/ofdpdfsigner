//
//  Created by zizheng fan on 2022/04/10.
//
#ifndef FZZOFDLINEJOINTYPE_H
#define FZZOFDLINEJOINTYPE_H



class FZZOFDLineJoinType
{
public:
	typedef enum {
        TYPE_NONE,
		TYPE_Miter,
		TYPE_Round,
		TYPE_Bevel
	} TYPE;

	static string toString(FZZOFDLineJoinType::TYPE type) {
		string temp = "Miter";
		switch (type) {
		case TYPE_Miter:
			temp = "Miter";
			break;
		case TYPE_Round:
			temp = "Round";
			break;
		case TYPE_Bevel:
			temp = "Bevel";
			break;
        case TYPE_NONE:
            temp = "Miter";
            break;
		}
		return temp;
	}

	static FZZOFDLineJoinType::TYPE toType(const char * const strtype) {
		FZZOFDLineJoinType::TYPE temp = TYPE_Miter;
		if (strcmp(strtype, "Miter") == 0) {
			temp = TYPE_Miter;
		} else if (strcmp(strtype, "Round") == 0) {
			temp = TYPE_Round;
		}
		else if (strcmp(strtype, "Bevel") == 0) {
			temp = TYPE_Bevel;
		}
		
		return temp;
	}

};

#endif 
