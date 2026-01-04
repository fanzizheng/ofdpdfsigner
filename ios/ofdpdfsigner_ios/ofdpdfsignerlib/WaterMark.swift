//
//  WaterMark.swift
//  ofdcreatorlib
//
//  Created by zizheng fan on 2024/6/11.
//

import Foundation

//----------------------------------------------------------------------------------------
typealias Type_CreateWaterMarkImage = @convention(c) (Bool,Bool,Double,Double,Double,Double,UnsafeRawPointer?, Int32,Int32,Double,Double,
                                                        UnsafePointer<CChar>?,UnsafePointer<CChar>?,Double,Bool,Bool,Double,
                                                        Double,Double,Double,
                                                        Double,
                                                        UnsafePointer<CChar>?,UnsafePointer<CChar>?,Double,Bool,Bool,Double,
                                                        Double,Double,Double,
                                                        Double,
                                                        UnsafePointer<CChar>?,UnsafePointer<CChar>?,Double,Bool,Bool,Double,
                                                        Double,Double,Double,
                                                        Double,Double,UnsafeMutablePointer<UnsafeMutablePointer<UInt8>?>?, UnsafeMutablePointer<size_t>?,UnsafeMutablePointer<Double>?,UnsafeMutablePointer<Double>?
    ) -> Int32
private var Function_CreateWaterMarkImage: Type_CreateWaterMarkImage? = unsafeBitCast(dlsym(UnsafeMutableRawPointer(bitPattern: -2), "createWaterMarkImage"), to: Type_CreateWaterMarkImage.self)
//----------------------------------------------------------------------------------------
public class WaterMark {
    
    public static func createWaterMark( rotation : Double, scale : Double, isImage : Bool,
                                        image : [UInt8]?, textParams : TextParams?) -> WaterMarkImage?
    {
        let ret : WaterMarkImage = WaterMarkImage()
        if !isImage && (textParams == nil || textParams!.textArray == nil || textParams!.colorArray == nil || textParams!.fontNameArray == nil
                        || textParams!.fontSizeArray == nil || textParams!.isFontBoldArray == nil
                        || textParams!.textArray!.count <= 0
                        || textParams!.textArray?.count != textParams!.colorArray?.count
                        || textParams!.textArray?.count != textParams!.fontNameArray?.count
                        || textParams!.textArray?.count != textParams!.fontSizeArray?.count
                        || textParams!.textArray?.count != textParams!.isFontBoldArray?.count ) {
            return ret
        }
        
        if isImage && ( image == nil || image!.count < 10 ) {
            return ret;
        }
    
        var text_1 : String = "";
        var fontName_1 : String = "";
        var fontSize_1 : Double = 0;
        var isBlob_1 : Bool = false;
        var isItalic_1 : Bool = false;
        var colorR_1 : Double = 0;
        var colorG_1 : Double = 0;
        var colorB_1 : Double = 0;
        var alpha_1 : Double = 0;


        var text_2 : String = "";
        var fontName_2 : String = "";
        var fontSize_2 : Double = 0;
        var isBlob_2 : Bool = false;
        var isItalic_2 : Bool = false;
        var colorR_2 : Double = 0;
        var colorG_2 : Double = 0;
        var colorB_2 : Double = 0;
        var alpha_2 : Double = 0;

        var text_3 : String = "";
        var fontName_3 : String = "";
        var fontSize_3 : Double = 0;
        var isBlob_3 : Bool = false;
        var isItalic_3 : Bool = false;
        var colorR_3 : Double = 0;
        var colorG_3 : Double = 0;
        var colorB_3 : Double = 0;
        var alpha_3 : Double = 0;

        var lineSpacing0_1 : Double = 8;
        var lineSpacing1_2 : Double = 8;

        var textAlign : Int32 = 1;
        
        if ( !isImage ) {
            if textParams!.textArray!.count >= 1 {
                text_1 = textParams!.textArray![0]
                fontName_1 = textParams!.fontNameArray![0]
                fontSize_1 = textParams!.fontSizeArray![0]
                isBlob_1 = textParams!.isFontBoldArray![0]
                isItalic_1 = false
                colorR_1 = textParams!.colorArray![0].red
                colorG_1 = textParams!.colorArray![0].green
                colorB_1 = textParams!.colorArray![0].blue
                alpha_1 = textParams!.colorArray![0].alpha
            }

            if textParams!.textArray!.count >= 2 {
                text_2 = textParams!.textArray![1]
                fontName_2 = textParams!.fontNameArray![1]
                fontSize_2 = textParams!.fontSizeArray![1]
                isBlob_2 = textParams!.isFontBoldArray![1]
                isItalic_2 = false
                colorR_2 = textParams!.colorArray![1].red
                colorG_2 = textParams!.colorArray![1].green
                colorB_2 = textParams!.colorArray![1].blue
                alpha_2 = textParams!.colorArray![1].alpha
            }

            if textParams!.textArray!.count >= 3 {
                text_3 = textParams!.textArray![2]
                fontName_3 = textParams!.fontNameArray![2]
                fontSize_3 = textParams!.fontSizeArray![2]
                isBlob_3 = textParams!.isFontBoldArray![2]
                isItalic_3 = false
                colorR_3 = textParams!.colorArray![2].red
                colorG_3 = textParams!.colorArray![2].green
                colorB_3 = textParams!.colorArray![2].blue
                alpha_3 = textParams!.colorArray![2].alpha
            }

            if let lineSpacing = textParams!.lineSpacingArray {
                if lineSpacing.count >= 1  {
                    lineSpacing0_1 = lineSpacing[0];
                }
                if ( lineSpacing.count >= 2 ) {
                    lineSpacing1_2 = lineSpacing[1];
                }
            }
            
            let strtextAlign = textParams!.textAlignment.lowercased()

            if strtextAlign == "left"  {
                textAlign = 1;
            } else if  strtextAlign == "right"  {
                textAlign = 2;
            } else if  strtextAlign == "center"  {
                textAlign = 3;
            }

        } else {
            //image
        }

        if let function = Function_CreateWaterMarkImage {
            //print("createSeal")
            var inDataPointer : UnsafeRawPointer? = nil
            var inDatalen : Int32 = 0
            if isImage {
                inDataPointer = image!.withUnsafeBytes({ $0 }).baseAddress
                inDatalen = Int32(image!.count)
            }
            
            
            var dataPtr: UnsafeMutablePointer<UInt8>? = nil
            var datalen: size_t = 0
            var imageWidth: Double = 0
            var imageHeight: Double = 0
            
            let result = function(false, isImage,0,
                                  0, 0, 0,inDataPointer,inDatalen,
                                  textAlign, 0, 0,

                                  text_1, fontName_1, fontSize_1,
                                  isBlob_1, isItalic_1, colorR_1,
                                  colorG_1, colorB_1, alpha_1,
                                  
                                  lineSpacing0_1,
                                  
                                  text_2, fontName_2, fontSize_2,
                                  isBlob_2, isItalic_2, colorR_2,
                                  colorG_2, colorB_2, alpha_2,
                                  
                                  lineSpacing1_2,
                                  
                                  text_3, fontName_3, fontSize_3,
                                  isBlob_3, isItalic_3, colorR_3,
                                  colorG_3, colorB_3, alpha_3,
                                  
                                  rotation, scale,&dataPtr, &datalen,&imageWidth,&imageHeight)
            
            if result == 0 {
                ret.imageData = Utils.convertToData(bytes: dataPtr, lenght: Int32(datalen))
                ret.imageWidth = imageWidth
                ret.imageHeight = imageHeight
            } else {
                print("positionSign error:")
                print(result)
            }
            
            if let pdataPtr = dataPtr {
                Utils.freeHandle(handlePtr: pdataPtr)
            }
        }
        
        
        return ret;
         
    }
     
}
//----------------------------------------------------------------------------------------
