//
//  Created by zizheng fan on 2024/11/10.
//
//  该接口为C 接口
//
//
#ifndef FZZCINTERFACE_H
#define FZZCINTERFACE_H

//----------------------------------------------------------------------------------------------------
/****************************************defined****************************/
//----------------------------------------------------------------------------------------------------

#if defined(_MSC_VER)
    #define DEVAPI __stdcall

    #ifdef WIN32DLL_EXPORTS
        #define DLL_API __declspec(dllexport)
    #else
        #define DLL_API __declspec(dllimport)
    #endif
#else
    //#define DEVAPI __fastcall
    #define DEVAPI
    #define DLL_API

#endif

#define FZZKEYTYPE_SM4 0
#define FZZKEYTYPE_SM2_PUB 1
#define FZZKEYTYPE_SM2_PRI 2

#define FZZCRYPTOTYPEE_SM2 0
#define FZZCRYPTOTYPEE_SM4_CBC 1
#define FZZCRYPTOTYPEE_SM4_GCM 2
#define FZZCRYPTOTYPEE_SM4_CTR 3


typedef void * HANDLE;
class FZZKeyWordInfo;
//-----------------------------------------------------------------------------------------------------------------
/***********************************************utils function**************************************************************/
//-----------------------------------------------------------------------------------------------------------------
void ClearKeyWordList(vector<FZZKeyWordInfo*> * list);
//----------------------------------------------------------------------------------------------------



#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------------------------------------------
/****************************************************Util*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 释放电子印章基础插件内部分配的内存
 注意：FZZFreeHandle 函数名称不能修改为 freeHandle，freeHandle这个函数名很容易和其他系统库发生冲突
 (in param) handle: 内存指针
 */
DLL_API void DEVAPI FZZFreeHandle(HANDLE handle);

/*
 设置工作路径，例如：字体所在路径为 c:\app\OFDFonts,这里的路径应该为c:\app
 (in param) filePath: 设置文件路径
 return：true 执行成功
 */
DLL_API bool DEVAPI setWorkPath(const char* const filePath);

/*
 设置临时路径，用于存储临时文件
 (in param) filePath: 设置临时文件路径
 return：true 执行成功
 */
DLL_API bool DEVAPI setTempPath(const char* const filePath);
/*
 根据图片获取图片的宽和高
 (in param) imageData: 图片数据
 (in param) imageLenght: 图片数据长度
 (out param) imageWidth: 图片宽度 ， 像素
 (out param) imageHeight: 图片高度 ， 像素
 return：true 执行成功
 */
DLL_API bool DEVAPI getImageWidthHeight(const unsigned char * const imageData,size_t imageLenght,/*out*/size_t* imageWidth,/*out*/size_t* imageHeight);
/*
 将图片拆分成n等份
 (in param) imageData: 图片数据
 (in param) imageLenght: 图片数据长度
 (in param) imageType: 输出图片类型
 (in param) isHorizontal: 是否横向拆分
 (in param) count: 拆分成几等份
 (out param) outData: 图片数据集合
 (out param) intoutDatalen: 图片数据集合长度
 (out param) outDatalen: 转换后的每一个图片数据长度，如：123，234，198
 (out param) imageWidth: 图片宽度 ， 像素
 (out param) imageHeight: 图片高度 ， 像素
 return：true 执行成功
 */
DLL_API bool DEVAPI splitImage(const unsigned char * const imageData,int imageLenght,const char * imageType,bool isHorizontal,size_t count,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen,size_t* imageWidth,size_t* imageHeight);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************字体*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 字体保存到缓存
 (in param) fontFileName: 字体库名称,必须是全路径
 return：true 执行成功
 */
DLL_API bool DEVAPI saveFontFileNameCache(const char* const fontFileName);

/*
 获取印章系统的全部字体文件
 (in param) systemFontFileNameFunc: 获取系统字体的文件名字（全路径）回调函数
 (in param) callBack_Param: 回调函数的参数
 return：true 执行成功
 */
DLL_API bool DEVAPI getAllSystemFontFileName(CallBack_SystemFontFileNameFunc systemFontFileNameFunc,const void * callBack_Param);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************crypto*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 生成根证书
 (in param) keyType: 0，默认值
 (in param) keyData: 根证书公钥数据
 (in param) keyDatalen: 根证书公钥数据长度
 (in param) dnData: dn数据
 (in param) dnlen: dn数据长度
 (in param) days: 有效天数
 (in param) rootKeyData: 根证书私钥数据
 (in param) rootKeyDatalen: 根证书私钥数据长度
 (out param) outData: 根证书数据
 (out param) outDatalen: 根证书数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI generateRootCert(int keyType,unsigned char * keyData,int keyDatalen,unsigned char * dnData,int dnlen,int days,unsigned char * rootKeyData,int rootKeyDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);

/*
 生成证书
 (in param) keyType: 0，默认值
 (in param) isSign: 0，加密证书;1:签名证书
 (in param) keyData: 证书公钥数据
 (in param) keyDatalen: 证书公钥数据长度
 (in param) dnData: dn数据
 (in param) dnlen: dn数据长度
 (in param) dnRootData: 根证书dn数据
 (in param) dnRootlen: 根证书dn数据长度
 (in param) days: 有效天数
 (in param) rootKeyData: 根证书私钥数据
 (in param) rootKeyDatalen: 根证书私钥数据长度
 (out param) outData: 证书数据
 (out param) outDatalen: 证书数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI generateCert(int keyType,int isSign,unsigned char * keyData,int keyDatalen,unsigned char * dnData,int dnlen,unsigned char * dnRootData,int dnRootlen,int days,unsigned char * rootKeyData,int rootKeyDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 生成随机数
 (in param) length: 随机数长度
 (out param) outData: 随机数数据
 (out param) outDatalen: 随机数数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI generateRandom(int length,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 生成摘要
 (in param) sourceData: 原文数据
 (in param) sourceDataLength: 原文数据长度
 (out param) outData: 文摘数据
 (out param) outDatalen: 文摘数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI generateDigest(unsigned char * sourceData,int sourceDataLength,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 生成对称密钥
 (out param) outData: 对称密钥数据
 (out param) outDatalen: 对称密钥数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI generateSymKey(/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 生成非对称密钥
 (out param) outPublicKeyData: 公钥数据
 (out param) outPublicKeyDatalen: 公钥数据长度
 (out param) outPrivateKeyData: 私钥数据
 (out param) outPrivateKeyDatalen: 私钥数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI generateAsymKey(/*out*/unsigned char ** outPublicKeyData,/*out*/size_t * outPublicKeyDatalen,/*out*/unsigned char ** outPrivateKeyData,/*out*/size_t * outPrivateKeyDatalen);
/*
 加密数据 ，函数名不能用 encrypt,encrypt和系统的函数冲突，因此函数名改为 encipher
 (in param) keyType: key类型 ，KEYTYPE_SM4，KEYTYPE_SM2_PUB
 (in param) keyData: 密钥数据
 (in param) keyDatalen: 密钥数据长度
 (in param) algType: 算法类型，FZZCRYPTOTYPEE_SM2，FZZCRYPTOTYPEE_SM4_CBC，FZZCRYPTOTYPEE_SM4_GCM，FZZCRYPTOTYPEE_SM4_CTR
 (in param) sourceData: 原文数据
 (in param) sourceDatalen: 原文数据长度
 (out param) encData: 密文数据
 (out param) encDatalen: 密文数据长度
 (out param) sm4GCMData: SM4 GCM 数据
 (out param) sm4GCMDatalen: SM4 GCM 数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI encipher(int keyType,unsigned char * keyData,int keyDatalen,int algType,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** encData,/*out*/size_t * encDatalen,/*out*/unsigned char ** sm4GCMData,/*out*/size_t * sm4GCMDatalen);
/*
 解密数据
 (in param) keyType: key类型 ，FZZKEYTYPE_SM4，FZZKEYTYPE_SM2_PRI
 (in param) keyData: 密钥数据
 (in param) keyDatalen: 密钥数据长度
 (in param) algType: 算法类型，FZZCRYPTOTYPEE_SM2，FZZCRYPTOTYPEE_SM4_CBC，FZZCRYPTOTYPEE_SM4_GCM，FZZCRYPTOTYPEE_SM4_CTR
 (in param) encData: 密文数据
 (in param) encDatalen: 密文数据长度
 (in param) sm4GCMData: SM4 GCM 数据
 (in param) sm4GCMDatalen: SM4 GCM 数据长度
 (out param) outData: 明文数据
 (out param) outDatalen: 明文数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI decipher(int keyType,unsigned char * keyData,int keyDatalen,int algType,unsigned char * encData,int encDatalen,unsigned char * sm4GCMData,int sm4GCMDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 签名
 (in param) keyType: key类型 ，FZZKEYTYPE_SM2_PRI
 (in param) keyData: 密钥数据
 (in param) keyDatalen: 密钥数据长度
 (in param) algType: 算法类型，FZZCRYPTOTYPEE_SM2
 (in param) sourceData: 原文数据
 (in param) sourceDatalen: 原文数据长度
 (out param) outData: 签名数据
 (out param) outDatalen: 签名数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI sign(int keyType,unsigned char * keyData,int keyDatalen,int algType,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 验签
 (in param) keyType: key类型 ，FZZKEYTYPE_SM2_PUB
 (in param) keyData: 密钥数据
 (in param) keyDatalen: 密钥数据长度
 (in param) algType: 算法类型，FZZCRYPTOTYPEE_SM2
 (in param) sourceData: 原文数据
 (in param) sourceDatalen: 原文数据长度
 (in param) signData: 签名数据
 (in param) signDatalen: 签名数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI verify(int keyType,unsigned char * keyData,int keyDatalen,int algType,unsigned char * sourceData,int sourceDatalen,unsigned char * signData,int signDatalen);
/*
 SM4 CBC 加密数据
 (in param) keyData: 密钥数据
 (in param) keyDatalen: 密钥数据长度
 (in param) ivData: iv数据
 (in param) ivDatalen: iv数据长度
 (in param) sourceData: 原文数据
 (in param) sourceDatalen: 原文数据长度
 (out param) encData: 密文数据
 (out param) encDatalen: 密文数据长度
 return：true 执行成功
 */
DLL_API bool DEVAPI encryptSM4CBC(unsigned char * keyData,int keyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * sourceData,int sourceDatalen,/*out*/unsigned char ** encData,/*out*/size_t * encDatalen);
/*
 SM4 CBC 解密数据
 (in param) keyData: 密钥数据
 (in param) keyDatalen: 密钥数据长度
 (in param) ivData: iv数据
 (in param) ivDatalen: iv数据长度
 (in param) encData: 密文数据
 (in param) encDatalen: 密文数据长度
 (out param) outData: 原文数据
 (out param) outDatalen: 原文数据长度
 return: true 执行成功
 */
DLL_API bool DEVAPI decryptSM4CBC(unsigned char * keyData,int keyDatalen,unsigned char * ivData,int ivDatalen,unsigned char * encData,int encDatalen,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************Seal*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 创建符合国办标准的电子印章
 (in param) code: 印章编号
 (in param) type: 印章类型代码
                 0-电子个人名章
                 1-电子法定名称章
                 2-电子财务专用章
                 3-电子发票专用章
                 4-电子合同专用章
                 5-电子法定代表人名章
                 6-业务专用章
                 99-其他
 (in param) name: 印章名称
 (in param) width: 印章图片宽度
 (in param) height: 印章图片高度
 (in param) createTime: 制章日期，格式：YYYY-MM-DD HH:MM:SS
 (in param) startTime: 有效起始时间，格式：YYYY-MM-DD HH:MM:SS
 (in param) endTime: 有效终止时间，格式：YYYY-MM-DD HH:MM:SS
 (in param) format: 印章图片类型，必须为PNG
 (in param) imageData: 印章图片数据
 (in param) imageDatalen: 印章图片数据长度
 (in param) signFunc: 签名回调函数
 (in param) getUserCertFunc: 获取用户证书回调函数
 (in param) getSealCertFunc: 获取印章证书回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outSealData: 印章数据
 (out param) outSealDatalen: 印章数据长度
 return: 0 执行成功
 */
DLL_API int DEVAPI createSeal(const char * const code,int type,const char * const name,int width,int height,
                                const char * const createTime,const char * const startTime,const char * const endTime,const char * const format,
                                const unsigned char * const imageData,int imageDatalen,CallBack_Sign signFunc,CallBack_getUserCert getUserCertFunc,CallBack_getSealCert getSealCertFunc,const void * callBack_Param,
                              /*out*/unsigned char ** outSealData,/*out*/size_t * outSealDatalen);
/*
 在符合国办电子印章格式的数据中提取电子印章的印模。
 (in param) sealData: 印章数据
 (in param) sealDatalen: 印章数据长度
 (out param) outImageData: 印章图片数据
 (out param) outImageDatalen: 印章图片数据长度
 return: 0 执行成功
 */
DLL_API int DEVAPI getSealImageData(const unsigned char * const sealData,int sealDatalen,
                              /*out*/unsigned char ** outImageData,/*out*/size_t * outImageDatalen
                              );
/*
 在符合国办电子印章格式的数据中提取电子印章的用户证书
 (in param) sealData: 印章数据
 (in param) sealDatalen: 印章数据长度
 (out param) outData: 印章图片数据
 (out param) outDatalen: 印章图片数据长度
 return: 0 执行成功
 */

DLL_API int DEVAPI getSealUserCertData(const unsigned char * const sealData,int sealDatalen,
                              /*out*/unsigned char ** outData,/*out*/size_t * outDatalen
                              );
/*
 验证符合国办电子印章是否有效
 (in param) sealData: 印章数据
 (in param) sealDatalen: 印章数据长度
 (in param) verifyFunc: 验证签名回调函数
 (in param) callBack_Param: 回调函数参数
 return: 0 执行成功
 */
DLL_API int DEVAPI verifySeal(const unsigned char * const sealData,int sealDatalen,CallBack_Verify verifyFunc,const void * callBack_Param);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************Watermark*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 生成水印图片
 (in param) isTile: 是否平铺,
                    true 平铺： pageWidth,pageHeight 必须大于零;beginPosX,beginPosY 是最左侧单元起始位置,但因为平铺是文档对角线长度做正方形平铺，因此beginPosX,beginPosY值偏小时看不到效果
                    false 不平铺：pageWidth,pageHeight 为零时，按实际大小产生图片；pageWidth,pageHeight 大于零时,beginPosX,beginPosY 单元起始位置,这个位置是旋转后的左上点，-1和-1为居中
 (in param) isImage: 内容类型，true为图片，false为文本.
                     图片时，仅仅使用 bool isTile,bool isImage,double pageWidth,double pageHeight,double beginPosX,double beginPosY ,double rotate这几个参数
 (in param) pageWidth: 页面宽度
 (in param) pageHeight: 页面高度
 (in param) beginPosX: 开始位置 X
 (in param) beginPosY: 开始位置 Y
 (in param) imageData: 图片数据
 (in param) imageDataLen: 图片数据长度
 (in param) textAlign: 文字对齐：
                         左对齐：1；
                         居中：3；
                         右对齐：2；
 (in param) horizontalSpacing: 横向间距
 (in param) verticalSpacing: 竖向间距
 (in param) firstLineText: 第一行文字
 (in param) firstLineText_FontName: 第一行文字 字体名字
 (in param) firstLineText_fontSize: 第一行文字 字体大小
 (in param) isBlob_first: 第一行文字 是否为粗体
 (in param) isItalic_first: 第一行文字 是否为斜体
 (in param) firstLineText_color_R: 第一行文字 颜色RGB
 (in param) firstLineText_color_G: 第一行文字 颜色RGB
 (in param) firstLineText_color_B: 第一行文字 颜色RGB
 (in param) firstLineText_alpha: 第一行文字 透明度
 (in param) lineSpacing0_1: 第一行文字 和 第二行文字的行间距
 
 (in param) secondLineText: 第二行文字
 (in param) secondLineText_FontName: 第二行文字 字体名字
 (in param) secondLineText_fontSize: 第二行文字 字体大小
 (in param) isBlob_second: 第二行文字 是否为粗体
 (in param) isItalic_second: 第二行文字 是否为斜体
 (in param) secondLineText_color_R: 第二行文字 颜色RGB
 (in param) secondLineText_color_G: 第二行文字 颜色RGB
 (in param) secondLineText_color_B: 第二行文字 颜色RGB
 (in param) secondLineText_alpha: 第二行文字 透明度
 (in param) lineSpacing1_2: 第二行文字 和 第三行文字的行间距
 
 (in param) thirdLineText: 第三行文字
 (in param) thirdLineText_FontName: 第三行文字 字体名字
 (in param) thirdLineText_fontSize: 第三行文字 字体大小
 (in param) isBlob_third: 第三行文字 是否为粗体
 (in param) isItalic_third: 第三行文字 是否为斜体
 (in param) thirdLineText_color_R: 第三行文字 颜色RGB
 (in param) thirdLineText_color_G: 第三行文字 颜色RGB
 (in param) thirdLineText_color_B: 第三行文字 颜色RGB
 (in param) thirdLineText_alpha: 第三行文字 透明度
 (in param) rotate: 旋转角度，单位为度，推荐用 -22
 (in param) scaled: 缩放比例。
                     只在文本数据时生效，图片数据将忽略此参数
                     放大比例系数：
                     1.0：阈值大于200%失真了
                     2.0：阈值大于400%失真了（推荐用2.0）
                     对于1.0时，文档的放大将导致水印的失真，放大几倍取决于文档在放大几倍时失真的可接受范围，一般 2.0可以支持文档的400%的放大。这个值越大，将导致性能损失和文档的大小几何倍增加
                     在盖章时，显示的大小请使用返还值的宽高。
 
 (out param) outData: 水印图片数据
 (out param) outDatalen: 水印图片数据长度
 (out param) imageWidth: 当文字时：盖章时印章的宽，毫米，这个值不是图片实际宽高，实际宽高要乘以scale
                         当图片时：该参数为图片的真实宽度，盖章时印章的高请自行决定大小
 (out param) imageHeight: 当文字时：盖章时印章的高，毫米，这个值不是图片实际宽高，实际宽高要乘以scale
                          当图片时：该参数为图片的真实高度，盖章时印章的高请自行决定大小
 return: 0 执行成功
 */
DLL_API int DEVAPI createWaterMarkImage(bool isTile,bool isImage,double pageWidth,double pageHeight,double beginPosX,double beginPosY,const unsigned char * const imageData,size_t imageDataLen,int textAlign,double horizontalSpacing,double verticalSpacing,
                                          const char * const firstLineText,const char * const firstLineText_FontName,double firstLineText_fontSize,bool isBlob_first,bool isItalic_first,double firstLineText_color_R,
                                          double firstLineText_color_G,double firstLineText_color_B,double firstLineText_alpha,
                                          double lineSpacing0_1,
                                          const char * const secondLineText,const char * const secondLineText_FontName,double secondLineText_fontSize,bool isBlob_second,bool isItalic_second,double secondLineText_color_R,
                                          double secondLineText_color_G,double secondLineText_color_B,double secondLineText_alpha,
                                          double lineSpacing1_2,
                                          const char * const thirdLineText,const char * const thirdLineText_FontName,double thirdLineText_fontSize,bool isBlob_third,bool isItalic_third,double thirdLineText_color_R,
                                          double thirdLineText_color_G,double thirdLineText_color_B,double thirdLineText_alpha,
                                          double rotate,double scaled,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen,/*out*/double * imageWidth,/*out*/double * imageHeight);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************  OFD  *********************************************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 打开OFD文件，并返回文件句柄
 注意：当打开文档后，调用位置盖章，骑缝章，关键字盖章后，该句柄指向最后一次盖章的文档内存，前文档内存被自动释放。
 (in param) ofdData: OFD文档数据
 (in param) ofdDatalen: OFD文档长度
 return: 返回的文件句柄
         值为0时打开文档失败
 */
DLL_API HANDLE DEVAPI ofd_open(const unsigned char * const ofdData,int ofdDatalen);
/*
 关闭OFD文件，并释放内存
 (in param) fileHandle: 文件句柄
 */
DLL_API void DEVAPI ofd_close(HANDLE fileHandle);

/*
 获取文件数据
 (in param) fileHandle: 文件句柄
 (out param) outData: 返回文档数据
 (out param) outDatalen: 返回文档数据长度
 */
DLL_API int DEVAPI ofd_getFileData(HANDLE fileHandle,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 获取OFD文档的总页数
 (in param) fileHandle: 文件句柄
 return: 总页数
 */
DLL_API int DEVAPI ofd_getPageCount(HANDLE fileHandle);
/*
 获取OFD文档的总页数
 (in param) fileHandle: 文件句柄
 (in param) pageNumber: 页码 从 1 开始
 (out param) pageWidth: 页面宽度 毫米
 (out param) pageHeight: 页面高度 毫米
 return: 0 执行成功
 */
DLL_API int DEVAPI ofd_getPageSize(HANDLE fileHandle,int pageNumber,/*out*/double &pageWidth,/*out*/double &pageHeight);
/*
 判断ofd 是否 被完整性保护
 (in param) fileHandle: ofd 文件句柄
 (return) false: 文档未完整性保护；true:文档完整性保护
 */
DLL_API bool DEVAPI ofd_isProtect(HANDLE fileHandle);
/*
 OFD 文档完整性保护
 (in param) fileHandle: ofd 文件句柄
 (in param) SignFunc: 签名回调函数
 (in param) getUserCertFunc: 证书回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回完整性保护的文档数据
 (out param) outDatalen: 返回完整性保护的文档数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI ofd_protect(HANDLE fileHandle,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,
                              /*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 OFD 文档完整性保护验证
 (in param) fileHandle: ofd 文件句柄
 (in param) verifyFunc: 验证签名回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回验证时发现丢失的文件，不一定有值，可能验证签名失败
 (out param) outDatalen: 返回验证时发现丢失的文件数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI ofd_protectionVerify(HANDLE fileHandle,CallBack_Verify verifyFunc,const void * callBack_Param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 判断ofd 是否为 加密
 (in param) fileHandle: ofd 文件句柄
 (return) false: 文档未加密；true:文档加密
 */
DLL_API bool DEVAPI ofd_isEncrypt(HANDLE fileHandle);
/*
 OFD 加密文档
 (in param) fileHandle: ofd 文件句柄
 (in param) userInfo：用户信息json:[{mode:1,passWordCert:"12345678",userName:"user 1",userType:"User"},
            {mode:2,passWordCert:"证书base64",userName:"user 1",userType:"Owner"}]
           mode：1 密码，2 证书
           passWordCert：密码 或 证书base64
           userName：用户名
           userType：用户类型：User 普通用户；Owner 文档管理员；
 (in param) encSm4CBC: sm4 cbc 加密回调函数
 (in param) decSm4CBC: sm4 cbc 解密回调函数
 (in param) encSM2: sm2 加密回调函数
 (in param) decSM2: sm2 解密回调函数
 (in param) genRandom: 随机数回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回加密的文档数据
 (out param) outDatalen: 返回加密的文档数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI ofd_encryptDocument(HANDLE fileHandle,const char * userInfo,CallBack_EncryptSM4CBC encSm4CBC,CallBack_DecryptSM4CBC decSm4CBC,CallBack_EncryptSM2 encSM2,CallBack_DecryptSM2 decSM2,CallBack_GenerateRandom genRandom,const void * callBack_Param,
                              /*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 OFD 解密文档
 (in param) fileHandle: ofd 文件句柄
 (in param) mode：1 密码，2 证书
 (in param) password：密码 ，当 mode为1时 必填；当 mode为2时 空字符串 ""
 (in param) username：用户名
 (in param) usertype：用户类型：User 普通用户；Owner 文档管理员；
 (in param) encSm4CBC: sm4 cbc 加密回调函数
 (in param) decSm4CBC: sm4 cbc 解密回调函数
 (in param) encSM2: sm2 加密回调函数
 (in param) decSM2: sm2 解密回调函数
 (in param) genRandom: 随机数回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回解密后的OFD 文档
 (out param) outDatalen: 返回解密后的OFD 文档数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI ofd_decryptDocument(HANDLE fileHandle,int mode,const char * password,const char * username,const char * usertype,CallBack_EncryptSM4CBC encSm4CBC,CallBack_DecryptSM4CBC decSm4CBC,CallBack_EncryptSM2 encSM2,CallBack_DecryptSM2 decSM2,CallBack_GenerateRandom genRandom,const void * callBack_Param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
//-----------------------------------------------------------------------------------------------------------------
/****************************************OFDStamp****************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 OFD文件位置签章，坐标，印章宽度 使用毫米单位
 (in param) handle: ofd 文件句柄
 (in param) stampData：印章数据
 (in param) stampDatalen：印章数据长度
 (in param) pageIndex：1、指定页码 , 页码从 1 开始
                       2、所有页-1
 (in param) x：签章X位置，单位：毫米；
 (in param) y: 签章y位置，单位：毫米
 (in param) stampwidth: 印章显示宽度，单位：毫米
 (in param) stampheight: 印章显示高度，单位：毫米
 (in param) isContinueSign: 是否可以继续盖章
 (in param) SignFunc: 签名回调函数
 (in param) getUserCertFunc: 证书回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回盖章后的文档数据
 (out param) outDatalen: 返回盖章后的文档数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI ofd_positionSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,int pageIndex,double x,double y,double stampwidth, double stampheight,bool isContinueSign,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,
                              /*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 OFD文件骑缝章签章，印章宽度 使用毫米单位
 (in param) handle: ofd 文件句柄
 (in param) stampData：印章数据
 (in param) stampDatalen：印章数据长度
 (in param) RidingType：骑缝章类型
                         0：骑缝章-左
                         1：骑缝章-右
                         2 : 骑缝章-顶
                         3 : 骑缝章-底
                         4 : 两页骑缝章-左右
                         5 : 两页骑缝章-顶底
 (in param) stampwidth: 印章显示宽度，单位：毫米
 (in param) stampheight: 印章显示高度，单位：毫米
 (in param) isContinueSign: 是否可以继续盖章
 (in param) SignFunc: 签名回调函数
 (in param) getUserCertFunc: 证书回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回盖章后的文档数据
 (out param) outDatalen: 返回盖章后的文档数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI ofd_ridingSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,
                                      int RidingType, double stampwidth,
                                      double stampheight,bool isContinueSign,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,
                                        /*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 OFD文件关键字签章，印章宽度 使用毫米单位
 (in param) handle: ofd 文件句柄
 (in param) stampData：印章数据
 (in param) stampDatalen：印章数据长度
 (in param) keyWord：关键字
 (in param) pKeywordRule：关键字规则
                如：string KeywordRule = "[" +
                     "{" +
                         "\"pageNumber\":1," +
                         "\"indexRules\":[" +
                             "{" +
                                 "\"index\":1," +
                                 "\"offsetX\":10," +
                                 "\"offsetY\":20" +
                             "}," +
                             "{" +
                                 "\"index\":2," +
                                 "\"offsetX\":10," +
                                 "\"offsetY\":20" +
                             "}" +
                         "]" +
                     "}," +
                     "{" +
                         "\"pageNumber\":5," +
                         "\"indexRules\":[" +
                             "{" +
                                 "\"index\":-1," +
                                 "\"offsetX\":10," +
                                 "\"offsetY\":20" +
                             "}" +
 
                         "]" +
                     "}" +
                 "]" ;
 (in param) stampwidth: 印章显示宽度，单位：毫米
 (in param) stampheight: 印章显示高度，单位：毫米
 (in param) isContinueSign: 是否可以继续盖章
 (in param) SignFunc: 签名回调函数
 (in param) getUserCertFunc: 证书回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回盖章后的文档数据
 (out param) outDatalen: 返回盖章后的文档数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI ofd_keywordSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,
                                      const char * const keyword,const char * const pKeywordRule, double stampwidth,
                                      double stampheight,bool isContinueSign,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,
                                          /*out*/unsigned char ** outData,/*out*/size_t * outDatalen);

/*
 删除OFD文档中全部印章
 (in param) handle: OFD 文件句柄
 (out param) outData: 删除OFD文档中全部印章后的文档数据
 (out param) outDatalen: 删除OFD文档中全部印章后的文档数据长度
 return：0 为成功
 */
DLL_API int DEVAPI ofd_clearSigns(HANDLE handle,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 验证OFD/PDF文档中全部电子印章
 (in param) handle: OFD 文件句柄
 (in param) doctype: 文档类型 ，1 OFD;2 PDF
 (in param) passWord: PDF文档密码。当文档类型为 2 PDF时，该参数有效
 (in param) verifyFunc: 验证签名回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回验证数据
             如：验证数据
             [
             {
                      "verify":true, //印章是否验证成功
                      "certCN":"c=cn", //证书dn
                      "signTime":"YYYYMMDDHHMMSSZ",//签名时间
                      "pageNumber": 1,  //页码，从1开始
                      "AlgType":"SM3-SM2" //签名算法
                    }
                    ....
             ]
 (out param) outDatalen: 返回验证数据长度
 return：0 为成功
 */
DLL_API int DEVAPI verifyDocment(const unsigned char * const docdata,int doclen,int doctype,char * passWord,CallBack_Verify verifyFunc,const void * callBack_Param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
//-----------------------------------------------------------------------------------------------------------------
/****************************************OFD Converter ****************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 OFD指定页码转换图片。
 (in param) handle: 文档句柄
 (in param) imageType: 转换后的图片类型，"PNG","JPG","SVG"
 (in param) pageIndex: 转换第几页，从 0 开始
 (in param) scale: 缩放比例，SVG 忽略此参数
 (out param) outData: 转换后的图片数据
 (out param) outDatalen: 转换后的图片数据长度
 (return) : true 成功；
 */
DLL_API bool DEVAPI ofd_pageToImage(HANDLE handle,const char * const imageType,int pageIndex,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 OFD转换图片。
 (in param) handle: 文档句柄
 (in param) imageType: 转换后的图片类型，"PNG","JPG","SVG"
 (in param) scale: 缩放比例，SVG 忽略此参数
 (out param) outData: 转换后的图片数据集合
 (out param) intoutDatalen: 转换后的图片数据集合长度
 (out param) outDatalen: 转换后的每一个图片数据长度，如：123，234，198
 (return) : true 成功；
 */
DLL_API bool DEVAPI ofd_toImage(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen);
/*
 OFD转换图片并压缩为zip。
 (in param) handle: 文档句柄
 (in param) imageType: 转换后的图片类型，"PNG","JPG","SVG"
 (in param) scale: 缩放比例，SVG 忽略此参数
 (out param) outData: 转换后的图片数据zip
 (out param) outDatalen: 转换后的图片数据zip长度
 (return) : true 成功；
 */
DLL_API bool DEVAPI ofd_toImageZip(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 OFD转换PDF。
 (in param) handle: 文档句柄
 (in param) isNoStamp: true 不包含印章转换
 (in param) isEncrypt: true 转换后的pdf 为加密pdf文件
 (in param) password: 如果不为空， 转换后的pdf 为密码加密pdf文件。该参数不为空时，将忽略isEncrypt参数
 (out param) outData: 转换后的图片数据zip
 (out param) outDatalen: 转换后的图片数据zip长度
 (return) : true 成功；
 */
DLL_API bool DEVAPI ofdToPdf(HANDLE handle,bool isNoStamp,bool isEncrypt,const char * password,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************  PDF  *********************************************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 打开PDF文件，并返回文件句柄
 注意：当打开文档后，调用位置盖章，骑缝章，关键字盖章后，该句柄指向最后一次盖章的文档内存，前文档内存被自动释放。
 (in param) fileData: PDF文档数据
 (in param) fileDatalen: PDF文档长度
 return: 返回的文件句柄
         值为0时打开文档失败
 */
DLL_API HANDLE DEVAPI pdf_open(const unsigned char * const fileData,int fileDatalen);
/*
 关闭PDF文件，并释放内存
 (in param) fileHandle: 文件句柄
 */
DLL_API void DEVAPI pdf_close(HANDLE fileHandle);

/*
 获取文件数据
 (in param) fileHandle: 文件句柄
 (out param) outData: 返回文档数据
 (out param) outDatalen: 返回文档数据长度
 */
DLL_API int DEVAPI pdf_getFileData(HANDLE fileHandle,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 获取PDF文档的总页数
 (in param) fileHandle: 文件句柄
 return: 总页数
 */
DLL_API int DEVAPI pdf_getPageCount(HANDLE fileHandle);
/*
 获取PDF文档的总页数
 (in param) fileHandle: 文件句柄
 (in param) pageNumber: 页码 从 1 开始
 (out param) pageWidth: 页面宽度 像素
 (out param) pageHeight: 页面高度 像素
 return: 0 执行成功
 */
DLL_API int DEVAPI pdf_getPageSize(HANDLE fileHandle,int pageNumber,/*out*/double &pageWidth,/*out*/double &pageHeight);
/*
 判断pdf 是否为 密码加密
 (in param) handle: pdf 文件句柄
 (return) false: 文档未加密；true:文档密码加密
 */
DLL_API bool DEVAPI pdf_isNeedPassWord(HANDLE fileHandle);
/*
 设置pdf打开文档密码
 (in param) handle: pdf 文件句柄
 (in param) password: 文档密码
 */
DLL_API void DEVAPI pdf_setPassWord(HANDLE fileHandle,char * password);

/*
 pdf 加密/用密码加密
 注意：isEncrypt为false 并 passWord = “”，这时为输出为明文文档
 (in param) handle: pdf 文件句柄
 (in param) isEncrypt: 文档是否加密
 (in param) passWord: 用密码加密文档，不用 为 空字符串 “”
 (out param) outData: 返回加密后的PDF 文档
 (out param) outDatalen: 返回加密后的PDF 文档数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI pdf_documnetEncryptDecrypt(HANDLE fileHandle,bool isEncrypt,char * passWord,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDFStamp*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 PDF文件位置签章，坐标，印章宽度 使用像素单位
 (in param) handle: PDF 文件句柄
 (in param) stampData：印章数据
 (in param) stampDatalen：印章数据长度
 (in param) alpha：印章图片透明度，1.0到0.86，1.0为不透明，低于0.86图片颜色会逐步变浅，可以根据实际情况调整。推荐值0.86
 (in param) pageIndex：1、指定页码 , 页码从 1 开始
                       2、所有页-1
 (in param) x：签章X位置，单位：像素；
 (in param) y: 签章y位置，单位：像素
 (in param) stampwidth: 印章显示宽度，单位：毫米
 (in param) stampheight: 印章显示高度，单位：毫米
 (in param) SignFunc: 签名回调函数
 (in param) getUserCertFunc: 证书回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回盖章后的文档数据
 (out param) outDatalen: 返回盖章后的文档数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI pdf_positionSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,double alpha,int pageIndex,double x,double y,double stampwidth, double stampheight,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,
                              /*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 PDF文件骑缝章签章，印章宽度 使用毫米单位
 (in param) handle: 文件句柄
 (in param) stampData：印章数据
 (in param) stampDatalen：印章数据长度
 (in param) alpha：印章图片透明度，1.0到0.86，1.0为不透明，低于0.86图片颜色会逐步变浅，可以根据实际情况调整。推荐值0.86
 (in param) RidingType：骑缝章类型
                         0：骑缝章-左
                         1：骑缝章-右
                         2 : 骑缝章-顶
                         3 : 骑缝章-底
                         4 : 两页骑缝章-左右
                         5 : 两页骑缝章-顶底
 (in param) stampwidth: 印章显示宽度，单位：毫米
 (in param) stampheight: 印章显示高度，单位：毫米
 (in param) isContinueSign: 是否可以继续盖章
 (in param) SignFunc: 签名回调函数
 (in param) getUserCertFunc: 证书回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回盖章后的文档数据
 (out param) outDatalen: 返回盖章后的文档数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI pdf_ridingSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,double alpha,
                                      int RidingType, double stampwidth,
                                        double stampheight,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 OFD文件关键字签章，印章宽度 使用毫米单位
 (in param) handle: ofd 文件句柄
 (in param) stampData：印章数据
 (in param) stampDatalen：印章数据长度
 (in param) alpha：印章图片透明度，1.0到0.86，1.0为不透明，低于0.86图片颜色会逐步变浅，可以根据实际情况调整。推荐值0.86
 (in param) keyWord：关键字
 (in param) pKeywordRule：关键字规则
                如：string KeywordRule = "[" +
                     "{" +
                         "\"pageNumber\":1," +
                         "\"indexRules\":[" +
                             "{" +
                                 "\"index\":1," +
                                 "\"offsetX\":10," +
                                 "\"offsetY\":20" +
                             "}," +
                             "{" +
                                 "\"index\":2," +
                                 "\"offsetX\":10," +
                                 "\"offsetY\":20" +
                             "}" +
                         "]" +
                     "}," +
                     "{" +
                         "\"pageNumber\":5," +
                         "\"indexRules\":[" +
                             "{" +
                                 "\"index\":-1," +
                                 "\"offsetX\":10," +
                                 "\"offsetY\":20" +
                             "}" +
 
                         "]" +
                     "}" +
                 "]" ;
 (in param) stampwidth: 印章显示宽度，单位：毫米
 (in param) stampheight: 印章显示高度，单位：毫米
 (in param) SignFunc: 签名回调函数
 (in param) getUserCertFunc: 证书回调函数
 (in param) callBack_Param: 回调函数参数
 (out param) outData: 返回盖章后的文档数据
 (out param) outDatalen: 返回盖章后的文档数据长度
 (return) 0: 成功；
 */
DLL_API int DEVAPI pdf_keywordSign(HANDLE handle,const unsigned char * const stampData,int stampDatalen,double alpha,
                                      const char * const keyword,const char * const pKeywordRule, double stampwidth,
                                         double stampheight,CallBack_Sign SignFunc,CallBack_getUserCert getUserCertFunc,const void * callBack_Param,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 删除pdf文档中全部印章
 (in param) handle: pdf 文件句柄
 (out param) outData: 删除pdf文档中全部印章后的文档数据
 (out param) outDatalen: 删除pdf文档中全部印章后的文档数据长度
 return：0 为成功
 */
DLL_API int DEVAPI pdf_clearSigns(HANDLE handle,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
//-----------------------------------------------------------------------------------------------------------------
/****************************************************PDF Converter*********************************************************/
//-----------------------------------------------------------------------------------------------------------------
/*
 PDF指定页码转换图片
 (in param) handle: 文档句柄
 (in param) imageType: 转换后的图片类型，"PNG","JPG","SVG"
 (in param) pageIndex: 转换第几页，从 0 开始
 (in param) scale: 缩放比例，SVG 忽略此参数
 (out param) outData: 转换后的图片数据
 (out param) outDatalen: 转换后的图片数据长度
 (return) : true 成功；
 */
DLL_API bool DEVAPI pdf_pageToImage(HANDLE handle,const char * const imageType,int pageIndex,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 PDF转换图片。
 (in param) handle: 文档句柄
 (in param) imageType: 转换后的图片类型，"PNG","JPG","SVG"
 (in param) scale: 缩放比例，SVG 忽略此参数
 (out param) outData: 转换后的图片数据集合
 (out param) intoutDatalen: 转换后的图片数据集合长度
 (out param) outDatalen: 转换后的每一个图片数据长度，如：123，234，198
 (return) : true 成功；
 */
DLL_API bool DEVAPI pdf_toImage(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * intoutDatalen,/*out*/char ** outDatalen);
/*
 PDF转换图片并压缩为zip。
 (in param) handle: 文档句柄
 (in param) imageType: 转换后的图片类型，"PNG","JPG","SVG"
 (in param) scale: 缩放比例，SVG 忽略此参数
 (out param) outData: 转换后的图片数据zip
 (out param) outDatalen: 转换后的图片数据zip长度
 (return) : true 成功；
 */
DLL_API bool DEVAPI pdf_toImageZip(HANDLE handle,const char * const imageType,double scale,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);
/*
 PDF转换OFD。
 (in param) handle: 文档句柄
 (in param) isNoStamp: true 不包含印章转换
 (out param) outData: 转换后的图片数据zip
 (out param) outDatalen: 转换后的图片数据zip长度
 (return) : true 成功；
 */
DLL_API bool DEVAPI pdfToOfd(HANDLE handle,bool isNoStamp,/*out*/unsigned char ** outData,/*out*/size_t * outDatalen);

//-----------------------------------------------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif

#endif //FZZCINTERFACE_H

