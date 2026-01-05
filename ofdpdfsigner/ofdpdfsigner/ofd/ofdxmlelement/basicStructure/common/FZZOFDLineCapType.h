//
//  Created by zizheng fan on 2022/04/10.
//
#ifndef FZZOFDLINECAPTYPE_H
#define FZZOFDLINECAPTYPE_H


class FZZOFDLineCapType
{
public:
	typedef enum {
        TYPE_None,
		TYPE_Butt,
		TYPE_Round,
		TYPE_Square
	} TYPE;

	static string toString(FZZOFDLineCapType::TYPE type) {
		string temp = "Butt";
		switch (type) {
        case TYPE_None:
		case TYPE_Butt:
			temp = "Butt";
			break;
		case TYPE_Round:
			temp = "Round";
			break;
		case TYPE_Square:
			temp = "Square";
			break;
        
		}
		return temp;
	}

	static FZZOFDLineCapType::TYPE toType(const char * const strtype) {
		FZZOFDLineCapType::TYPE temp = TYPE_Butt;
		if (strcmp(strtype, "Butt") == 0) {
			temp = TYPE_Butt;
		} else if (strcmp(strtype, "Round") == 0) {
			temp = TYPE_Round;
		}
		else if (strcmp(strtype, "Square") == 0) {
			temp = TYPE_Square;
		}
		
		return temp;
	}

};

#endif //MEDIATYPE_H
