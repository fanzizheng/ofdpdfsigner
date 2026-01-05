//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDMAPTYPE_H
#define FZZOFDMAPTYPE_H

class FZZOFDMapType
{
public:
	typedef enum {
		TYPE_Direct,
		TYPE_Repeat,
		TYPE_Reflect
	} TYPE;

	static string toString(FZZOFDMapType::TYPE type) {
		string temp = "Direct";
		switch (type) {
		case TYPE_Direct:
			temp = "Direct";
			break;
		case TYPE_Repeat:
			temp = "Repeat";
			break;
		case TYPE_Reflect:
			temp = "Reflect";
			break;
		}
		return temp;
	}

	static FZZOFDMapType::TYPE toType(const char * const strtype) {
		FZZOFDMapType::TYPE temp = TYPE_Direct;
		if (strcmp(strtype, "Direct") == 0) {
			temp = TYPE_Direct;
		} else if (strcmp(strtype, "Repeat") == 0) {
			temp = TYPE_Repeat;
		}
		else if (strcmp(strtype, "Reflect") == 0) {
			temp = TYPE_Reflect;
		}
		
		return temp;
	}

};

#endif 
