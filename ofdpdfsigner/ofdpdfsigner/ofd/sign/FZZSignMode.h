//
//  Created by zizheng fan on 2023/01/04.
//
#ifndef FZZSIGNMODE_H
#define FZZSIGNMODE_H

//#include "basic/FZZConst.h"

class FZZSignMode
{
public:
	typedef enum {
		TYPE_WholeProtected,
		TYPE_ContinueSign
	} TYPE;

//	static string toString(SigType::TYPE type) {
//		string temp = "Seal";
//		switch (type) {
//		case TYPE_Seal:
//			temp = "Seal";
//			break;
//		case TYPE_Sign:
//			temp = "Sign";
//			break;
//		}
//		return temp;
//	}
//
//	static SigType::TYPE toType(const char * const strtype) {
//		SigType::TYPE temp = TYPE_Seal;
//		if (strcmp(strtype, "Seal") == 0) {
//			temp = TYPE_Seal;
//		} else if (strcmp(strtype, "Sign") == 0) {
//			temp = TYPE_Sign;
//		}
//
//		return temp;
//	}

};

#endif //FZZSIGNMODE_H
