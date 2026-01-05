//
//  Created by zizheng fan on 2023/04/07.
//
#include "basic/FZZConst.h"
#include "office/docx/container/FZZMediaDir.h"
#include "office/docx/FZZDocXConst.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZMediaDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZMediaDir::FZZMediaDir() :FZZBaseDir()
{
    //DLOG("FZZMediaDir()");
    FZZConst::addClassCount("FZZMediaDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZMediaDir::FZZMediaDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZBaseDir(filesContainer,Root)
{
    FZZConst::addClassCount("FZZMediaDir");
    setPath(path);
}
//-----------------------------------------------------------------------------------------------------------------
FZZMediaDir::~FZZMediaDir()
{
    //DLOG("~FZZMediaDir()");
    FZZConst::delClassCount("FZZMediaDir");
    
}
//-----------------------------------------------------------------------------------------------------------------

