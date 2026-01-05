//
//  Created by zizheng fan on 2024/03/13.
//
#ifndef FZZOFDSIGNCLEANER_H
#define FZZOFDSIGNCLEANER_H

//#include "core/signatures/Signature.h"
//#include "core/basicStructure/FZZOFDObject.h"
#include "basic/FZZBytes.h"
#include "ofd/FZZOFD.h"

class FZZOFDSignCleaner
{
public:
    FZZOFDSignCleaner(FZZOFD* reader);
	~FZZOFDSignCleaner();
	
public:
    void clean(FZZBytes & outOFDFileData);
protected:
    
private:
    FZZOFDSignCleaner();
private:
    FZZOFD* m_reader;

	
};

#endif //FZZOFDSIGNCLEANER_H


