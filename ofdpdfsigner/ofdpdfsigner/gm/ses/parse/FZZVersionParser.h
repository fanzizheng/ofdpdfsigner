//
//  Created by zizheng fan on 2022/11/18.
//
#ifndef FZZSESVERSIONPARSER_H
#define FZZSESVERSIONPARSER_H

#include "gm/ses/parse/FZZSESVersionHolder.h"

class FZZVersionParser
{
public:
    FZZVersionParser();
    FZZVersionParser(const FZZVersionParser& obj);
	virtual ~FZZVersionParser();
public:
    //free
    static FZZSESVersionHolder* parseSES_SealVersion(const FZZBytes& o);
    //free
    static FZZSESVersionHolder* parseSES_SignatureVersion(const FZZBytes& o);
protected:
	
private:
    static FZZSESVersion::TYPE isV4Version(const FZZBytes& o);
private:
	
    
};

#endif //FZZSESVERSIONPARSER_H

