//
//  Created by zizheng fan on 2024/01/03.
//
#ifndef FZZERRORCODE_H
#define FZZERRORCODE_H

#define ERR_SUCCESS 0
//未知错误
#define ERR_FAIL 0xEFFFFF
//分配内存失败
#define ERR_ALLOC_MEMORY 0xEFFFFE
//文档类型不对
#define ERR_DOC_TYPE 0xEFFFFD
//文档类型不对
#define ERR_CALLBACK_NULL 0xEFFFFC
//产生水印图片失败
#define ERR_WATERMARK_CREATEIMAGE 0xEFFFFB
//--------------------------------------------------------------------------------
//crypto and seal
//证书加载失败
#define ERR_CERT_LOAD 0xEFF502
//验证失败
#define ERR_VERIFY 0xEFF503
//不在有效期
#define ERR_NOT_VALIDITY 0xEFF504
//--------------------------------------------------------------------------------
//ofd
//读取ofd文档失败
#define ERR_OFD_LOAD 0xEFF401
//ofd文档被锁定，不能签名
#define ERR_OFD_NOT_SIGN 0xEFF402
//ofd文档签章失败
#define ERR_OFD_SIGNSTAMP 0xEFF403
//解析关键字规则失败
#define ERR_OFD_KEYWORDRULE 0xEFF404
//生产OFD文档失败
#define ERR_OFD_GEN 0xEFF405
//OFD文档没有被加密
#define ERR_OFD_NOT_ENCRYPT 0xEFF406
//OFD文档没有被完整性保护
#define ERR_OFD_NOT_PROTECT 0xEFF407
//OFD文档完整性保护失败
#define ERR_OFD_PROTECT 0xEFF408
//OFD文档完整性保护验证失败
#define ERR_OFD_PROTECT_VERIFY 0xEFF409
//OFD 文档解密失败
#define ERR_OFD_DECRYPT 0xEFF40A
//OFD 文档加密失败
#define ERR_OFD_ENCRYPT 0xEFF40B
//OFD 文档加密时，解析用户信息失败
#define ERR_OFD_ENCRYPT_USERINFO 0xEFF40C
//--------------------------------------------------------------------------------
//pdf
//生产PDF文档失败
#define ERR_PDF_GEN 0xEFF301
//读取PDF文档失败
#define ERR_PDF_LOAD 0xEFF302
//加载PDF 页码失败
#define ERR_PDF_PAGE_LOAD 0xEFF303

//不需要密码
#define ERR_PDF_NOT_NEED_PW 0xEFF304
//验证密码错误
#define ERR_PDF_VERIFY_PW 0xEFF305
//没有设置密码
#define ERR_PDF_NOT_SET_PW 0xEFF306
//删除电子印章失败
#define ERR_PDF_DEL_STAMP 0xEFF307
#endif //FZZERRORCODE_H
