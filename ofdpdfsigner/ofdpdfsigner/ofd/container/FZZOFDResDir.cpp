//
//  Created by zizheng fan on 2024/03/07.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/container/FZZOFDResDir.h"


//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDResDir**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDResDir::FZZOFDResDir() :FZZOFDBaseDir()
{
    //DLOG("FZZOFDResDir()");
    FZZConst::addClassCount("FZZOFDResDir");
    
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDResDir::FZZOFDResDir(FZZOFDFilesContainer* filesContainer,string Root,string path) :FZZOFDBaseDir(filesContainer,Root)
{
    FZZConst::addClassCount("FZZOFDResDir");
    //Doc_0/Signs/
    setPath(path);
    
  
}
//-----------------------------------------------------------------------------------------------------------------
FZZOFDResDir::~FZZOFDResDir()
{
    //DLOG("~FZZOFDResDir()");
    FZZConst::delClassCount("FZZOFDResDir");
    
}
//-----------------------------------------------------------------------------------------------------------------

