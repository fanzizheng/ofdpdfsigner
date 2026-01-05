//
//  Created by zizheng fan on 2024/03/04.
//
#ifndef FZZOFDPAGEBLOCKTYPE_H
#define FZZOFDPAGEBLOCKTYPE_H

class FZZOFDPageBlockType
{
public:
    typedef enum {
        TYPE_PageBlock,
        TYPE_Layer,
        TYPE_CellContent,
        TYPT_CompositeObject,
        TYPT_ImageObject,
        TYPT_PathObject,
        TYPT_TextObject
    } TYPE;
public:
	virtual ~FZZOFDPageBlockType() {};
public:
    FZZOFDPageBlockType* Copy_PageBlockType(FZZOFDPageBlockType* data);
    void Delete_PageBlockType(FZZOFDPageBlockType* data);
};

#endif

