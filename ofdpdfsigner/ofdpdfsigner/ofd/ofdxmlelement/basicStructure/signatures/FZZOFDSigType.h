//
//  Created by zizheng fan on 2024/03/06.
//
#ifndef FZZOFDSIGTYPE_H
#define FZZOFDSIGTYPE_H


class FZZOFDSigType
{
public:
	typedef enum {
		TYPE_Seal,
		TYPE_Sign
	} TYPE;

	static string toString(FZZOFDSigType::TYPE type) {
		string temp = "Seal";
		switch (type) {
		case TYPE_Seal:
			temp = "Seal";
			break;
		case TYPE_Sign:
			temp = "Sign";
			break;
		}
		return temp;
	}

	static FZZOFDSigType::TYPE toType(const char * const strtype) {
		FZZOFDSigType::TYPE temp = TYPE_Seal;
		if (strcmp(strtype, "Seal") == 0) {
			temp = TYPE_Seal;
		} else if (strcmp(strtype, "Sign") == 0) {
			temp = TYPE_Sign;
		}
		
		return temp;
	}

};

#endif //FZZOFDSIGTYPE_H
