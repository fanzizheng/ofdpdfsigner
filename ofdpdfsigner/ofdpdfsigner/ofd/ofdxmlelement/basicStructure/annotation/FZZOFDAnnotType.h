//
//  Created by zizheng fan on 2024/03/08.
//
#ifndef FZZOFDANNOTTYPE_H
#define FZZOFDANNOTTYPE_H



class FZZOFDAnnotType
{
public:
	typedef enum {
		TYPE_Link,
		TYPE_Path,
		TYPE_Highlight,
		TYPE_Stamp,
		TYPE_Watermark
	} TYPE;

	static string toString(FZZOFDAnnotType::TYPE type) {
		string temp = "Link";
		switch (type) {
		case TYPE_Link:
			temp = "Link";
			break;
		case TYPE_Path:
			temp = "Path";
			break;
		case TYPE_Highlight:
			temp = "Highlight";
			break;
		case TYPE_Stamp:
			temp = "Stamp";
			break;
		case TYPE_Watermark:
			temp = "Watermark";
			break;
		}
		return temp;
	}

	static FZZOFDAnnotType::TYPE toType(const char * const strtype) {
		FZZOFDAnnotType::TYPE temp = TYPE_Link;
		if (strcmp(strtype, "Link") == 0) {
			temp = TYPE_Link;
		} else if (strcmp(strtype, "Path") == 0) {
			temp = TYPE_Path;
		}
		else if (strcmp(strtype, "Highlight") == 0) {
			temp = TYPE_Highlight;
		}
		else if (strcmp(strtype, "Stamp") == 0) {
			temp = TYPE_Stamp;
		}
		else if (strcmp(strtype, "Watermark") == 0) {
			temp = TYPE_Watermark;
		}
		return temp;
	}

};


#endif //FZZOFDANNOTTYPE_H
