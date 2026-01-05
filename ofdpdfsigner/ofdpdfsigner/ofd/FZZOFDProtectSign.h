//
//  Created by zizheng fan on 2024/09/25.
//
#ifndef FZZOFDPROTECTSIGN_H
#define FZZOFDPROTECTSIGN_H

#include "basic/FZZBytes.h"
#include "ofd/FZZOFD.h"

/*
 OFD文档完整性保护
 GM/T 0099-2020 中 没有说明保护证书是谁或机构
 标准没有提及加密和完整性保护的先后关系。因此我们的实现：
 如果文档加密了，要先解密后才能验证文档的完整性。
 文档加密时不加密完整性保护所属文件。
 */
class FZZOFDProtectSign
{
public:
    FZZOFDProtectSign(FZZOFD* reader);
	~FZZOFDProtectSign();
	
public:
    /*
     添加不需要保护的文件
     注意：保护和验证，两者调用必须以同样的方式调用该函数
     (in param) fileName: 不保护的文件，第一个字符必须是 '/'
     */
    void addNotProtectFileName(string filename) {
        transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
        if ( filename[0] != '/' ) {
            filename = "/" + filename;
        }
        m_NotProtectFileName.push_back(filename);
    }
    /*
     OFD文档完整性保护
     注意：该函数调用后，要调用generateOFD函数产生保护后的ofd文档数据
          如果之前已经做过完整性保护，再次做完整性保护，将根据当前文档重新计算，因此没有必要删除完整性保护后再做完整性保护。
     (in param) signFunc: 签名回调函数
     (in param) getCertFunc: 获得签名用户证书回调函数
     (in param) callBack_Param: 回调函数上下文参数
     (return) 完整性保护是否成功
     */
    bool exeProtect(CallBack_Sign signFunc,CallBack_getUserCert getCertFunc,const void * callBack_Param);
    /*
     产生保护后的ofd文档数据
     (out param) outOFDData: 输出保护后的ofd文档数据
     */
    void generateOFD(FZZBytes & outOFDData);
   
    /*
     OFD文档验证完整性保护
     注意：该函数调用后，要调用generateOFD函数产生保护后的ofd文档数据
     (in param) verifyFunc: 验证签名回调函数
     (in param) callBack_Param: 回调函数上下文参数
     (out param) outNotHaveFileName: 输出 验证时发现丢失的文件
     (return) false：完整性被破坏，但outNotHaveFileName不一定有值，可能验证签名失败
              注意：
               返回值失败时：
               1。验证签名失败 nothavefile:[]
               2。验证签名成功，但 文档的文件个数有增加或减少 nothavefile:[]
               3。验证签名成功，文档的文件个数相等，但文件名称不同 nothavefile:[保护前缺少的文件名]
                 比如将 /doc_0/annots/page_0/annotation.xml 改名为 /doc_0/annots/page_0/annotation_1.xml
                 nothavefile中的文件名为 /doc_0/annots/page_0/annotation.xml
     */
    bool isIntegrity(CallBack_Verify verifyFunc,const void * callBack_Param,vector<string> & outNotHaveFileName);
    //------------
    /*
     判断文档是否被完整性保护
     (return) 该文档是否被完整性保护
     */
    bool isProtect();
    
protected:
    bool findNotProtectFileName(string filename);
private:
    FZZOFDProtectSign();
private:
    FZZOFD* m_reader;
    FZZAtomicInteger m_maxUnitID;
    vector<string> m_NotProtectFileName;
};

#endif //FZZOFDPROTECTSIGN_H


