//
// Created on 2024/6/13.
// zizheng fan
//
//-------------------------------------------------------------------------------------------
interface Key {
  keyType: string; //"SM4","SM2_Public","SM2_Private"
  key: Uint8Array;
}

interface KeyPair {
  publicKey: Key;
  privateKey: Key;
}

interface EncryptData {
  encryptData: Uint8Array;
  macData: Uint8Array;
}

interface PageSize {
  width: number;
  height: number;
}

interface WaterMarkImage {
  image : Uint8Array;
  width: number;
  height: number;
}

interface TPColor {
  r: number;
  g: number;
  b: number;
  a: number;
}

interface TextParams {
  text: string[];
  textAlign: string;
  color: TPColor[];
  font : string[];
  fontSize: number[];
  isFontBold: boolean[];
  lineSpacing: number[];
}
//-------------------------------------------------------------------------------------------
//SystemManager
export const setTempPath : (filePath : string) => boolean;
export const setWorkPath : (filePath : string) => boolean;
//-------------------------------------------------------------------------------------------
//FontManager
export const getAllSystemFontFileName : (systemFontFileName : (string) => void ) => boolean;
export const saveFontFileNameCache : (fontFileName : string) => boolean;
//-------------------------------------------------------------------------------------------
//Crypto
export const generateRandom: (length: number) => Uint8Array;
export const generateDigest: (algType:string,sourceData: Uint8Array) => Uint8Array;
export const generateSymKey: (algType:string,length: number) => Key;
export const generateAsymKey: (algType:string,length: number) => KeyPair;
//algType:SM4_CBC，SM4_GCM,SM4_CTR,SM2_ENC
export const encrypt: (algType:string,encryptKey: Key,sourceData: Uint8Array) => EncryptData;
export const decrypt: (algType:string,decryptKey: Key,encryptData: EncryptData) => Uint8Array;
export const encryptSM4CBC: (encryptKey: Key,ivData: Uint8Array,sourceData: Uint8Array) => Uint8Array;
export const decryptSM4CBC: (decryptKey: Key,ivData: Uint8Array,encryptData: Uint8Array) => Uint8Array;
//algType：SM3_SM2
export const sign: (algType:string,privateKey: Key,sourceData: Uint8Array) => Uint8Array;
export const verify: (algType:string,publicKey: Key,sourceData: Uint8Array,signData: Uint8Array) => boolean;
export const generateRootCert: (certDN:string,publicKey: Key,validDays: number,rootPrivateKey: Key) => Uint8Array;
export const generateCert: (isSignCert: boolean,certDN:string,publicKey: Key,validDays: number,rootCertDN:string,rootPrivateKey: Key) => Uint8Array;

//-------------------------------------------------------------------------------------------
//pfd
export const pdf_open: (fileData: Uint8Array) => number;
export const pdf_close: (handle: number) => boolean;
export const pdf_getPageCount: (fileHandle: number) => number;
export const pdf_getPageSize: (fileHandle: number,pageNumber: number) => PageSize;
export const pdf_isNeedPassWord: (fileHandle: number) => number;
export const pdf_setPassWord: (fileHandle: number,passWord:string) => number;
export const pdf_documnetEncryptDecrypt: (fileHandle: number,isEncrypt: boolean,passWord:string) => Uint8Array;
//-------------------------------------------------------------------------------------------
//ofd
export const ofd_open: (fileData: Uint8Array) => number;
export const ofd_close: (handle: number) => boolean;
export const ofd_getPageCount: (fileHandle: number) => number;
export const ofd_getPageSize: (fileHandle: number,pageNumber: number) => PageSize;
export const ofd_isProtect: (fileHandle: number) => number;
export const ofd_isEncrypt: (fileHandle: number) => number;
export const ofd_protect: (fileHandle: number,signCallBack: (sourceData) => Uint8Array,getUserCertCallback: () => Uint8Array) => Uint8Array;
export const ofd_protectionVerify: (fileHandle: number, verifyCallBack: (algType,pubKey,sourceData,signData) => boolean) => string;
export const ofd_encryptDocument:(fileHandle: number, userInfo: string, encryptSM4CBCCallBack: (key,iv,sourceData) => Uint8Array, decryptSM4CBCCallBack: (key,iv,encryptData) => Uint8Array,encryptSM2CallBack: (publicKey,sourceData) => Uint8Array, decryptSM2CallBack: (encryptData) => Uint8Array, generateRandomCallBack: (len) => Uint8Array) => Uint8Array;
export const ofd_decryptDocument:(fileHandle: number, mode: number, passWord: string, userName: string,userType: string, encryptSM4CBCCallBack: (key,iv,sourceData) => Uint8Array, decryptSM4CBCCallBack: (key,iv,encryptData) => Uint8Array, encryptSM2CallBack: (publicKey,sourceData) => Uint8Array, decryptSM2CallBack: (encryptData) => Uint8Array, generateRandomCallBack: (len) => Uint8Array) => Uint8Array;
//-------------------------------------------------------------------------------------------

//PDFConverter
export const pdf_toImage: (fileHandle: number,imageFormat: string,scale: number) => Uint8Array[];
export const pdf_pageToImage: (fileHandle: number,imageFormat: string,pageNumber: number,scale: number) => Uint8Array;
export const pdf_toImageZip: (fileHandle: number,imageFormat: string,scale: number) => Uint8Array;
export const pdfToOfd: (fileHandle: number,isIncludeStamp: boolean) => Uint8Array;
//-------------------------------------------------------------------------------------------
//OFDConverter
export const ofd_toImage: (fileHandle: number,imageFormat: string,scale: number) => Uint8Array[];
export const ofd_pageToImage: (fileHandle: number,imageFormat: string,pageNumber: number,scale: number) => Uint8Array;
export const ofd_toImageZip: (fileHandle: number,imageFormat: string,scale: number) => Uint8Array;
export const ofdToPdf: (fileHandle: number,isIncludeStamp: boolean,isEncrypt: boolean,password : string) => Uint8Array;
//-------------------------------------------------------------------------------------------
//SealManager
export const createSeal: ( code : string,type : string,name : string,format : string,image : Uint8Array,width : number,height : number,createTime : string,startTime : string,endTime : string, signCallBack: (sourceData) => Uint8Array,getUserCertCallback: () => Uint8Array,getSealCertCallback: () => Uint8Array) => Uint8Array;
export const verifySeal: ( sealData: Uint8Array,verifyCallBack: (algType,pubKey,sourceData,signData) => boolean) => number;
export const getSealImageData: ( sealData: Uint8Array) => Uint8Array;
export const getSealUserCertData: ( sealData: Uint8Array) => Uint8Array;
//-------------------------------------------------------------------------------------------
//OFDStamp
export const ofd_positionSign: (fileHandle: number,sealData : Uint8Array,pageNumber : number,stampX : number,stampY : number,
                                width : number, height : number,isLocked : boolean,
                                signCallBack: (sourceData) => Uint8Array,getUserCertCallback: () => Uint8Array) => Uint8Array;
export const ofd_ridingSign: (fileHandle : number,sealData : Uint8Array,ridingType : string,
                              width : number, height : number,isLocked : boolean,
                              signCallBack: (sourceData) => Uint8Array,getUserCertCallback: () => Uint8Array) => Uint8Array;
export const ofd_keywordSign: (fileHandle : number,sealData : Uint8Array, keyWord : string,keyWordRules : string,
                               width : number, height : number,isLocked : boolean,
                               signCallBack: (sourceData) => Uint8Array,getUserCertCallback: () => Uint8Array) => Uint8Array;
export const ofd_verify: (fileData: Uint8Array,verifyCallBack: (algType,pubKey,sourceData,signData) => boolean) => string;

export const ofd_clearSigns: (fileHandle : number) => Uint8Array;
//-------------------------------------------------------------------------------------------
//PDFStamp
export const pdf_positionSign: (fileHandle : number,sealImageData : Uint8Array,sealAlpha : number, pageNumber : number,stampX : number,stampY : number,
                                width : number, height : number,isLocked : boolean,
                                signCallBack: (sourceData) => Uint8Array,getUserCertCallback: () => Uint8Array) => Uint8Array;
export const pdf_ridingSign: (fileHandle : number,sealImageData : Uint8Array,sealAlpha : number, ridingType : string,
                              width : number, height : number,isLocked : boolean,
                              signCallBack: (sourceData) => Uint8Array,getUserCertCallback: () => Uint8Array) => Uint8Array;
export const pdf_keywordSign: (fileHandle : number,sealImageData : Uint8Array,sealAlpha : number, keyWord : string,keyWordRules : string,
                               width : number, height : number,isLocked : boolean,
                               signCallBack: (sourceData) => Uint8Array,getUserCertCallback: () => Uint8Array) => Uint8Array;
export const pdf_verify: (fileData: Uint8Array,password : string,verifyCallBack: (algType,pubKey,sourceData,signData) => boolean) => string;

export const pdf_clearSigns: (fileHandle : number) => Uint8Array;
//-------------------------------------------------------------------------------------------
//WaterMark
export const createWaterMark: (rotation : number, scale : number, isImage : boolean,
                                image : Uint8Array, textParams : TextParams) => WaterMarkImage;
//-------------------------------------------------------------------------------------------

