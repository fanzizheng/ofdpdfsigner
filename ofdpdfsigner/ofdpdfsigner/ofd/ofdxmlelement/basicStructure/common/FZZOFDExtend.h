//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDEXTEND_H
#define FZZOFDEXTEND_H

class FZZOFDExtend
{
public:
	typedef enum {
		TYPE_0,
		TYPE_1,
		TYPE_2,
		TYPE_3
	} TYPE;

	static string toString(FZZOFDExtend::TYPE type) {
		string temp = "0";
		switch (type) {
		case TYPE_0:
			temp = "0";
			break;
		case TYPE_1:
			temp = "1";
			break;
		case TYPE_2:
			temp = "2";
			break;
		case TYPE_3:
			temp = "3";
			break;
		}
		return temp;
	}

	static FZZOFDExtend::TYPE toType(const char * const strtype) {
		FZZOFDExtend::TYPE temp = TYPE_0;
		if (strcmp(strtype, "0") == 0) {
			temp = TYPE_0;
		} else if (strcmp(strtype, "1") == 0) {
			temp = TYPE_1;
		}
		else if (strcmp(strtype, "2") == 0) {
			temp = TYPE_2;
		}
		else if (strcmp(strtype, "3") == 0) {
			temp = TYPE_3;
		}
		return temp;
	}

};

#endif 
