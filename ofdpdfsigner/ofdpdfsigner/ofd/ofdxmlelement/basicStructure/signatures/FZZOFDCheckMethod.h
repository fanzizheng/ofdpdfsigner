//
//  Created by zizheng fan on 2024/03/07.
//
#ifndef FZZOFDCHECKMETHOD_H
#define FZZOFDCHECKMETHOD_H

class FZZOFDCheckMethod
{
public:
	typedef enum {
		TYPE_MD5,
		TYPE_SHA1,
		TYPE_SHA256,
		TYPE_SM3
	} TYPE;

	static string toString(FZZOFDCheckMethod::TYPE type) {
		string temp = "SM3";
		switch (type) {
		case TYPE_SM3:
			temp = "SM3";
			break;
		case TYPE_MD5:
			temp = "MD5";
			break;
		case TYPE_SHA1:
			temp = "SHA1";
			break;
		case TYPE_SHA256:
			temp = "SHA256";
			break;
		}
		return temp;
	}

	static FZZOFDCheckMethod::TYPE toType(const char * const strtype) {
		FZZOFDCheckMethod::TYPE temp = TYPE_SM3;
		if (strcmp(strtype, "SM3") == 0) {
			temp = TYPE_SM3;
		} else if (strcmp(strtype, "MD5") == 0) {
			temp = TYPE_MD5;
		}
		else if (strcmp(strtype, "SHA1") == 0) {
			temp = TYPE_SHA1;
		}
		else if (strcmp(strtype, "SHA256") == 0) {
			temp = TYPE_SHA256;
		}
		
		return temp;
	}

};

#endif //FZZOFDCHECKMETHOD_H
