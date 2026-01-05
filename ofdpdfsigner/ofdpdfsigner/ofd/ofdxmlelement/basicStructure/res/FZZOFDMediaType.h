//
//  Created by zizheng fan on 2024/03/11.
//
#ifndef FZZOFDMEDIATYPE_H
#define FZZOFDMEDIATYPE_H


class FZZOFDMediaType
{
public:
	typedef enum {
		TYPE_Image,
		TYPE_Audio,
		TYPE_Video
	} TYPE;

	static string toString(FZZOFDMediaType::TYPE type) {
		string temp = "Image";
		switch (type) {
		case TYPE_Image:
			temp = "Image";
			break;
		case TYPE_Audio:
			temp = "Audio";
			break;
		case TYPE_Video:
			temp = "Video";
			break;
		}
		return temp;
	}

	static FZZOFDMediaType::TYPE toType(const char * const strtype) {
		FZZOFDMediaType::TYPE temp = TYPE_Image;
		if (strcmp(strtype, "Image") == 0) {
			temp = TYPE_Image;
		} else if (strcmp(strtype, "Audio") == 0) {
			temp = TYPE_Audio;
		}
		else if (strcmp(strtype, "Video") == 0) {
			temp = TYPE_Video;
		}
		
		return temp;
	}

};

#endif //FZZOFDMEDIATYPE_H
