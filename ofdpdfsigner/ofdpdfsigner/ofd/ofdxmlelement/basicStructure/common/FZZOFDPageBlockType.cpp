//
//  Created by zizheng fan on 2024/02/28.
//
#include "ofd/FZZOFDConst.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlockType.h"
#include "ofd/FZZOFDXMLFileObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCellContent.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDLayer.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlock.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDCompositeObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDImageObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDPathObject.h"
#include "ofd/ofdxmlelement/basicStructure/common/FZZOFDTextObject.h"
//-----------------------------------------------------------------------------------------------------------------
/***********************************************FZZOFDPageBlockType**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
FZZOFDPageBlockType* FZZOFDPageBlockType::Copy_PageBlockType(FZZOFDPageBlockType* data)
{
    FZZOFDPageBlockType* ret = NULL;
    
    FZZOFDCellContent * ofdCellContent = NULL;
    FZZOFDLayer * ofdLayer = NULL;
    FZZOFDPageBlock * ofdPageBlock = NULL;
    FZZOFDCompositeObject * ofdCompositeObject = NULL;
    FZZOFDImageObject * ofdImageObject = NULL;
    FZZOFDPathObject * ofdPathObject = NULL;
    FZZOFDTextObject * ofdTextObject = NULL;
    
    if ( ( ofdCellContent = dynamic_cast<FZZOFDCellContent*>(data) ) != NULL ) {
        ret = (FZZOFDPageBlockType*)new FZZOFDCellContent(*ofdCellContent);
    } else if ( ( ofdLayer = dynamic_cast<FZZOFDLayer*>(data) ) != NULL ) {
        ret = (FZZOFDPageBlockType*)new FZZOFDLayer(*ofdLayer);
    } else if ( ( ofdPageBlock = dynamic_cast<FZZOFDPageBlock*>(data) ) != NULL ) {
        ret = (FZZOFDPageBlockType*)new FZZOFDPageBlock(*ofdPageBlock);
    } else if ( ( ofdCompositeObject = dynamic_cast<FZZOFDCompositeObject*>(data) ) != NULL ) {
        ret = (FZZOFDPageBlockType*)new FZZOFDCompositeObject(*ofdCompositeObject);
    } else if ( ( ofdImageObject = dynamic_cast<FZZOFDImageObject*>(data) ) != NULL ) {
        ret = (FZZOFDPageBlockType*)new FZZOFDImageObject(*ofdImageObject);
    } else if ( ( ofdPathObject = dynamic_cast<FZZOFDPathObject*>(data) ) != NULL ) {
        ret = (FZZOFDPageBlockType*)new FZZOFDPathObject(*ofdPathObject);
    } else if ( ( ofdTextObject = dynamic_cast<FZZOFDTextObject*>(data) ) != NULL ) {
        ret = (FZZOFDPageBlockType*)new FZZOFDTextObject(*ofdTextObject);
    }
    
    return ret;
}
//-----------------------------------------------------------------------------------------------------------------
void FZZOFDPageBlockType::Delete_PageBlockType(FZZOFDPageBlockType* data)
{
    FZZOFDCellContent * ofdCellContent = NULL;
    FZZOFDLayer * ofdLayer = NULL;
    FZZOFDPageBlock * ofdPageBlock = NULL;
    FZZOFDCompositeObject * ofdCompositeObject = NULL;
    FZZOFDImageObject * ofdImageObject = NULL;
    FZZOFDPathObject * ofdPathObject = NULL;
    FZZOFDTextObject * ofdTextObject = NULL;
    
    if ( ( ofdCellContent = dynamic_cast<FZZOFDCellContent*>(data) ) != NULL ) {
        delete ofdCellContent;
    } else if ( ( ofdLayer = dynamic_cast<FZZOFDLayer*>(data) ) != NULL ) {
        delete ofdLayer;
    } else if ( ( ofdPageBlock = dynamic_cast<FZZOFDPageBlock*>(data) ) != NULL ) {
        delete ofdPageBlock;
    } else if ( ( ofdCompositeObject = dynamic_cast<FZZOFDCompositeObject*>(data) ) != NULL ) {
        delete ofdCompositeObject;
    } else if ( ( ofdImageObject = dynamic_cast<FZZOFDImageObject*>(data) ) != NULL ) {
        delete ofdImageObject;
    } else if ( ( ofdPathObject = dynamic_cast<FZZOFDPathObject*>(data) ) != NULL ) {
        delete ofdPathObject;
    } else if ( ( ofdTextObject = dynamic_cast<FZZOFDTextObject*>(data) ) != NULL ) {
        delete ofdTextObject;
    }
}
//-----------------------------------------------------------------------------------------------------------------
