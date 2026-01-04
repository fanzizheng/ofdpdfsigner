//
//  ContentView.swift
//  ofdpdfsigner_ios
//
//  Created by zizheng fan on 2025/4/10.
//

import SwiftUI
import ofdpdfsignerlib

var userCert : [UInt8]? = nil
var sealCert : [UInt8]? = nil
var rootCert : [UInt8]? = nil
var keyRootPair : KeyPair? = nil
var keyPair_User : KeyPair? = nil
var keyPair_Seal : KeyPair? = nil

struct ContentView: View {
    
    @State private var images: [UIImage?] = []
    
    @State private var pdfHandle : UInt = 0
    @State private var ofdHandle : UInt = 0
    
    @State private var strType: String = ""
    
    @State private var SEALImageData : Data? = nil
    
    @State private var showingAlert = false
    
    @State private var SEALData : [UInt8]? = nil
    
    @State private var OFDStampData : [UInt8]? = nil
    @State private var PDFStampData : [UInt8]? = nil
    
    init() {
        copyOFDFonts()
        //----------------------
        let documentsDirectory = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first!
        if !SystemMamager.setWorkPath(filePath: documentsDirectory.path) {
            print("设置工作目录失败！")
        }
        //----------------------
        let documentsTempDirectory = documentsDirectory.appendingPathComponent("/temp")
        var isDir: ObjCBool = false
        if !(FileManager.default.fileExists(atPath: documentsTempDirectory.path, isDirectory: &isDir) && isDir.boolValue) {
            // 目录不存在，尝试创建它（包括中间目录）
            do {
                try FileManager.default.createDirectory(at: documentsTempDirectory, withIntermediateDirectories: true, attributes: nil)
          
            } catch {
                // 创建目录时发生错误
                print("无法创建目录：\(documentsTempDirectory.path)")
                
            }
        }
        if !SystemMamager.setTempPath(filePath: documentsTempDirectory.path) {
            print("设置工作目录失败！")
        }
        //----------------------
        if !FontManager.getAllSystemFontFileName(withClosure: { param,fullFileName in
            let messageString = String(cString: fullFileName)
            FontManager.saveFontFileNameCache(fontFileName: messageString)
            //print("font name received: \(messageString)")
        })
        {
            print("获取系统系统文件列表失败！")
        }
        //----------------------
        
        
        
//        if let data = loadFileFromBundle(fileName: "seal", fileExtension: "ofd") {
//            // 此时 data 就是你的文件内容，类型为 Data，类似于 byte[]
//            // 你可以根据需要对它进行处理，例如转换为字符串或解析 JSON
//
//            // 转换为字符串（如果文件是文本文件）
//            if let string = String(data: data, encoding: .utf8) {
//                print(string)
//            }
//        }
        
    }
    
    func copyOFDFonts() {
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "fonts", fileExtension: "json")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "simsun", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "fzysong_b_gbk", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "arial", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "Helvetica", fileExtension: "otf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "lathab", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "calibri", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "cour", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "Deng", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "msyh", fileExtension: "ttc")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "NSimSun", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "simfang", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "simhei", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "simkai", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "STSong-Light-UniGB-UCS2-H", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "times", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "webdings", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "fzxiaobiaosong-b05s", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "AdobeSongStd-Light", fileExtension: "otf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "STSongStd-Light-Acro", fileExtension: "otf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "wenquanyizenhei", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "malgun", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "wingdings2", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "Wingdings3", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "Wingdings", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "stliti", fileExtension: "ttf")
        copyFileFromBundleToDocuments(pathdir:"OFDFonts/",fileName: "msgothic", fileExtension: "ttc")
    }
    
    func loadFileFromBundle(fileName: String, fileExtension: String) -> Data? {
        // 构造文件的 URL
        if let bundlePath = Bundle.main.path(forResource: "OFDFonts", ofType: "bundle"),
           let bundle = Bundle(path: bundlePath) {
           if let fileUrl = bundle.url(forResource: fileName, withExtension: fileExtension) {
               do {
                   let data = try Data(contentsOf: fileUrl)
                   return data
               } catch {
                   print("无法加载文件 \(fileName).\(fileExtension)")
                   return nil
               }
           }
        }
        return nil
    }
    
    func copyFileFromBundleToDocuments(pathdir : String,fileName: String, fileExtension: String) -> URL? {
        // 获取 Documents 目录的 URL
        let documentsDirectory = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first!
        let documentsDirectorydir = documentsDirectory.appendingPathComponent("\(pathdir)")
        let destinationFileURL = documentsDirectorydir.appendingPathComponent("\(fileName).\(fileExtension)")
        var isDir: ObjCBool = false
        if !(FileManager.default.fileExists(atPath: documentsDirectorydir.path, isDirectory: &isDir) && isDir.boolValue) {
            // 目录不存在，尝试创建它（包括中间目录）
            do {
                try FileManager.default.createDirectory(at: documentsDirectorydir, withIntermediateDirectories: true, attributes: nil)
          
            } catch {
                // 创建目录时发生错误
                print("无法创建目录：\(documentsDirectorydir.path)")
                return nil
            }
        }
        
        // 检查文件是否已存在于 Documents 目录中
        if FileManager.default.fileExists(atPath: destinationFileURL.path) {
            return destinationFileURL
        }
     
        if let bundlePath = Bundle.main.path(forResource: "OFDFonts", ofType: "bundle"),
           let bundle = Bundle(path: bundlePath) {
           if let fileUrl = bundle.url(forResource: pathdir+fileName, withExtension: fileExtension) {
               do {
                   try FileManager.default.copyItem(at: fileUrl, to: destinationFileURL)
                   return destinationFileURL
               } catch {
                   print("无法复制文件到 Documents 目录")
                   return nil
               }
           }
        }
        return destinationFileURL
    }
    
    func ShowMessage(message : String) -> Alert?
    {
        Alert(
                        title: Text("提示"),
                        message: Text(message),
                        primaryButton: .default(Text("确定"), action: {
                            // 用户点击“确定”按钮时的操作
                            //print("用户点击了确定按钮")
                            // 关闭Alert
                            showingAlert = false
                        }),
                        secondaryButton: .cancel(Text("取消"), action: {
                            // 用户点击“确定”按钮时的操作
                            //print("用户点击了取消按钮")
                            // 关闭Alert
                            showingAlert = false
                        })
        )
    }
    
    var body: some View {
        VStack(spacing: 0) {
            HStack {
                if !images.isEmpty {
                    ScrollView(.horizontal, showsIndicators: false) {
                        HStack(spacing: 10) {
                            ForEach(images, id: \.self) {
                                image in
                                Image(uiImage: image ?? UIImage())
                                    .resizable()
                                    .aspectRatio(contentMode: .fit)
                                    .frame(width: UIScreen.main.bounds.width,alignment: .leading)
                            }//ForEach
                        }//HStack
                    }.frame(maxWidth: .infinity, maxHeight: .infinity)
                    //ScrollView
                }//if
            }
            //.background(Color(red: 0.6, green: 0.847, blue: 0.898))
                .frame(maxWidth: .infinity, maxHeight: .infinity)
            
            //Spacer(minLength: 0)
            //HStack
            HStack(spacing: 0){
                
                Group {
                    Image("ofdopen") // 使用系统图标
                        .resizable()
                        .frame(width: 48, height: 48)
                        .onTapGesture { // 添加点击事件
                            self.openOFD()
                        }.padding([.top],10) // 顶部和底部填充
                        .padding([.leading], 10)
                        .alert(isPresented: $showingAlert) {
                            ShowMessage(message: "成功")!
                        }
                    Spacer(minLength: 0)
                    Image("pdfopen") // 使用系统图标
                        .resizable()
                        .frame(width: 48, height: 48)
                        .onTapGesture { // 添加点击事件
                            self.openPDF()
                        }.padding([.top],10) // 顶部和底部填充
                        .alert(isPresented: $showingAlert) {
                            ShowMessage(message: "成功")!
                        }
                    Spacer(minLength: 0)
                    Image("stamppos") // 使用系统图标
                        .resizable()
                        .frame(width: 48, height: 48)
                        .onTapGesture { // 添加点击事件
                            self.stampPos()
                        }.padding([.top],10) // 顶部和底部填充
                        .alert(isPresented: $showingAlert) {
                            ShowMessage(message: "成功")!
                        }
                }
                
                Spacer(minLength: 0)
                
                Group {
                    Image("stampriding") // 使用系统图标
                        .resizable()
                        .frame(width: 48, height: 48)
                        .onTapGesture { // 添加点击事件
                            self.stampRiding()
                        }.padding([.top],10) // 顶部和底部填充
                        .alert(isPresented: $showingAlert) {
                            ShowMessage(message: "成功")!
                        }
                    Spacer(minLength: 0)
                    Image("stampkey") // 使用系统图标
                        .resizable()
                        .frame(width: 48, height: 48)
                        .onTapGesture { // 添加点击事件
                            self.stampKey()
                        }.padding([.top],10) // 顶部和底部填充
                        .alert(isPresented: $showingAlert) {
                            ShowMessage(message: "成功")!
                        }
                    Spacer(minLength: 0)
                    Image("stampverify") // 使用系统图标
                        .resizable()
                        .frame(width: 48, height: 48)
                        .onTapGesture { // 添加点击事件
                            self.verify()
                        }.padding([.top],10) // 顶部和底部填充
                        .padding([.trailing], 10)
                        .alert(isPresented: $showingAlert) {
                            ShowMessage(message: "成功")!
                        }
                }
                
              
            }.background(Color(red: 0.8117, green: 0.847, blue: 0.898))
             .frame(maxWidth: .infinity,alignment: .leading)
            //HStack
        }.frame(maxWidth: .infinity, maxHeight: .infinity)
            //.background(Color.blue)
        //VStack
    } //body
    
    func openOFD()
    {
        createSeal()
        if ofdHandle == 0 {
            let OFDData = loadFileFromBundle(fileName: "src", fileExtension: "ofd")
            let ofdData = Utils.dataToUInt8Array(data:OFDData!)
            self.ofdHandle = OFD.open(fileData: ofdData)
            
            OFD.protect(fileHandle: ofdHandle, withClosure: { param,sourceData,sourceDatalen,outData,outDatalen in
                outDatalen!.pointee = 0
                if sourceData == nil || sourceDatalen == 0 || outData == nil || outDatalen == nil  {
                    return;
                }
            
                let srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
                if let signData = Crypto.sign(algType: Crypto.SM3_SM2,privateKey: keyPair_User!.getPrivateKey()!,sourceData: srcdata) {
                    let bufferSize = signData.count
                    if bufferSize > 0  {
                        if let actualPointer = outData!.pointee {
                            actualPointer.initialize(from: signData, count: bufferSize)
                            outDatalen!.pointee = bufferSize
                        } else {
                            outDatalen!.pointee = bufferSize
                        }
                    } else {
                        outDatalen!.pointee = 0
                    }
                }
                
            },
            withClosure: { param,outData,outDatalen in
                if outData == nil || outDatalen == nil || userCert == nil {
                    outDatalen!.pointee = 0
                    return;
                }
                let certBufferSize = userCert!.count
                if certBufferSize > 0  {
                    if let actualPointer = outData!.pointee {
                        actualPointer.initialize(from: userCert!, count: certBufferSize)
                        outDatalen!.pointee = certBufferSize
                    } else {
                        outDatalen!.pointee = certBufferSize
                    }
                } else {
                    outDatalen!.pointee = 0
                }
            })
            
            if OFD.IsProtect(fileHandle: ofdHandle) == 1 {
                print("OFD is Protect");
                let strProVerify : String? = OFD.protectionVerify(fileHandle: ofdHandle, withClosure: { param,algType,keyData,keyDatalen,sourceData,sourceDatalen,signData,signDatalen in
                    
                    if keyData == nil || keyDatalen == 0 || sourceData == nil || sourceDatalen == 0 || signData == nil || signDatalen == 0 {
                        return false;
                    }
                
                    let publicKey : Key = Key(keyType: Key.SM2_PUB_KEY,key: Data(bytes: keyData!, count: Int(keyDatalen)))
                
                    let srcData = Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)
                    let sigData = Utils.convertToData(bytes: signData, lenght: signDatalen)
                
                    let srcUInt8s = Utils.dataToUInt8Array(data: srcData!)
                    let signUInt8s = Utils.dataToUInt8Array(data: sigData!)
                
                    let isVerify = Crypto.verify(algType: Crypto.SM3_SM2, publicKey: publicKey, sourceData: srcUInt8s, signData: signUInt8s)
                    //print(isVerify)
                    return isVerify
                
                })
                
                print(strProVerify!);
                
            }
            let certbase = Data(userCert!).base64EncodedString(options: [])
            
            OFD.encryptDocument(fileHandle: ofdHandle, userInfo: "[{\"mode\":1,\"passWordCert\":\"12345678\",\"userName\":\"user 1\",\"userType\":\"User\"},{\"mode\":2,\"passWordCert\":\""+certbase+"\",\"userName\":\"user 2\",\"userType\":\"Owner\"}]", withClosure: {
                param,keyData,KeyDatalen,ivData,ivDatalen,sourceData,sourceDatalen,outEncData,outEncDatalen in
                outEncDatalen!.pointee = 0
                if keyData == nil || KeyDatalen == 0 || ivData == nil || ivDatalen == 0 || sourceData == nil || sourceDatalen == 0 || outEncData == nil || outEncDatalen == nil  {
                    outEncDatalen!.pointee = size_t(sourceDatalen) + 16
                    return;
                }
                
                
//                if ( sourceDatalen == 16 ) {
//                    print("enc sm4 key:")
//                    let sm4keydata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: keyData, lenght: KeyDatalen)!)
//                    print(sm4keydata)
//                    print("enc sm4 iv:")
//                    let sm4ivdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: ivData, lenght: ivDatalen)!)
//                    print(sm4ivdata)
//                    print("enc sm4 sourceData:")
//                    let sm4srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
//                    print(sm4srcdata)
//                }
                
                
                let srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
                let ivdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: ivData, lenght: ivDatalen)!)
                let sm4Key : Key = Key(keyType: Key.SM4,key: Data(bytes: keyData!, count: Int(KeyDatalen)))
            
//                if let EncryptData = Crypto.encrypt(algType: Crypto.SM4_CBC, encryptKey: sm4Key, sourceData: srcdata) {
//                    let encdata = Utils.dataToUInt8Array(data: (EncryptData.getEncryptData())!)
                if let encdata = Crypto.encryptSM4CBC(encryptKey: sm4Key, ivData: ivdata, sourceData: srcdata) {
//                    if ( sourceDatalen == 16 ) {
//                        print("enc sm4 encData:")
//                        print(encdata)
//                    }
                    let bufferSize = encdata.count
                    if bufferSize > 0  {
                        if let actualPointer = outEncData!.pointee {
                            actualPointer.initialize(from: encdata, count: bufferSize)
                            outEncDatalen!.pointee = bufferSize
                        } else {
                            outEncDatalen!.pointee = bufferSize
                        }
                    } else {
                        outEncDatalen!.pointee = 0
                    }
                }
            }, withClosure: {
                param,keyData,KeyDatalen,ivData,ivDatalen,encData,encDatalen,outDecData,outDecDatalen in
                outDecDatalen!.pointee = 0
            }, withClosure: {
                param,keyData, KeyDatalen,sourceData,sourceDatalen,outEncData,outEncDatalen in
                outEncDatalen!.pointee = 0
                if keyData == nil || KeyDatalen == 0 || sourceData == nil || sourceDatalen == 0 || outEncData == nil || outEncDatalen == nil  {
                    outEncDatalen!.pointee = size_t(sourceDatalen) + 120
                    return;
                }
                
                let srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
                let sm2PubKey : Key = Key(keyType: Key.SM2_PUB_KEY,key: Data(bytes: keyData!, count: Int(KeyDatalen)))
            
                if let EncryptData = Crypto.encrypt(algType: Crypto.SM2_ENC, encryptKey: sm2PubKey, sourceData: srcdata) {
                
                    let encdata = Utils.dataToUInt8Array(data: (EncryptData.getEncryptData())!)
                    
                    let bufferSize = encdata.count
                    if bufferSize > 0  {
                        if let actualPointer = outEncData!.pointee {
                            actualPointer.initialize(from: encdata, count: bufferSize)
                            outEncDatalen!.pointee = bufferSize
                        } else {
                            outEncDatalen!.pointee = bufferSize
                        }
                    } else {
                        outEncDatalen!.pointee = 0
                    }
                }
                
            }, withClosure: {
                param, encData, encDatalen,outDecData,outDecDatalen in
                outDecDatalen!.pointee = 0
            }, withClosure: {
                param, len,outData,outDatalen in
                outDatalen!.pointee = 0
                
                if let randomData = Crypto.generateRandom(length: Int32(len)) {
                    
                    
                    let bufferSize = randomData.count
                    if bufferSize > 0  {
                        if let actualPointer = outData!.pointee {
                            actualPointer.initialize(from: randomData, count: bufferSize)
                            outDatalen!.pointee = bufferSize
                        } else {
                            outDatalen!.pointee = bufferSize
                        }
                    } else {
                        outDatalen!.pointee = 0
                    }
                }
            })
            
            if OFD.IsEncrypt(fileHandle: ofdHandle) == 1 {
                print("OFD is encrypt");
                //OFD.decryptDocument(fileHandle: ofdHandle, mode: 1, passWord: "12345678", userName: "user 1", userType: "User",
                OFD.decryptDocument(fileHandle: ofdHandle, mode: 2, passWord: "", userName: "user 2", userType: "Owner",
                                    withClosure: {
                    param,keyData,KeyDatalen,ivData,ivDatalen,sourceData,sourceDatalen,outEncData,outEncDatalen in
                    outEncDatalen!.pointee = 0
                    
                }, withClosure: {
                    param,keyData,KeyDatalen,ivData,ivDatalen,encData,encDatalen,outDecData,outDecDatalen in
                    outDecDatalen!.pointee = 0
                    if keyData == nil || KeyDatalen == 0 || ivData == nil || ivDatalen == 0 || encData == nil || encDatalen == 0 || outDecData == nil || outDecDatalen == nil  {
                        outDecDatalen!.pointee = size_t(encDatalen)
                        return;
                    }
                    
                    
//                    if encDatalen == 32 {
//                        print("dec sm4 key:")
//                        let sm4keydata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: keyData, lenght: KeyDatalen)!)
//                        print(sm4keydata)
//                        print("dec sm4 iv:")
//                        let sm4ivdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: ivData, lenght: ivDatalen)!)
//                        print(sm4ivdata)
//                        print("dec sm4 encdata:")
//                        let sm4srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: encData, lenght: encDatalen)!)
//                        print(sm4srcdata)
//                    }
                    
                    let tempencdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: encData, lenght: encDatalen)!)
                    let ivdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: ivData, lenght: ivDatalen)!)
                    let sm4Key : Key = Key(keyType: Key.SM4,key: Data(bytes: keyData!, count: Int(KeyDatalen)))
                
//                    let encryptData : EncryptData = EncryptData()
//                    encryptData.setEncryptData(Utils.convertToData(fromBytes: tempencdata));
//
//                    if let srcdata = Crypto.decrypt(algType: Crypto.SM4_CBC, decryptKey: sm4Key, encryptData: encryptData) {
                        
                    if let srcdata = Crypto.decryptSM4CBC(decryptKey: sm4Key, ivData: ivdata, encryptData: tempencdata) {
//                        if encDatalen == 32 {
//                            print("dec sm4 srcdata:")
//                            print(srcdata)
//                        }
                        let bufferSize = srcdata.count
                        if bufferSize > 0  {
                            if let actualPointer = outDecData!.pointee {
                                actualPointer.initialize(from: srcdata, count: bufferSize)
                                outDecDatalen!.pointee = bufferSize
                            } else {
                                outDecDatalen!.pointee = bufferSize
                            }
                        } else {
                            outDecDatalen!.pointee = 0
                        }
                    }
                    
                }, withClosure: {
                    param,keyData, KeyDatalen,sourceData,sourceDatalen,outEncData,outEncDatalen in
                    outEncDatalen!.pointee = 0
                    
                }, withClosure: {
                    param, encData, encDatalen,outDecData,outDecDatalen in
                    outDecDatalen!.pointee = 0
                    
                    if encData == nil || encDatalen == 0 || outDecData == nil || outDecDatalen == nil  {
                        outDecDatalen!.pointee = size_t(encDatalen)
                        return;
                    }
                    
                    let encdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: encData, lenght: encDatalen)!)
                    
                    let encryptData : EncryptData = EncryptData()
                    encryptData.setEncryptData(Utils.convertToData(fromBytes: encdata));
                    
                    if let srcData = Crypto.decrypt(algType: Crypto.SM2_ENC, decryptKey: keyPair_User!.getPrivateKey()!, encryptData: encryptData) {
                    
                        
                        
                        let bufferSize = srcData.count
                        if bufferSize > 0  {
                            if let actualPointer = outDecData!.pointee {
                                actualPointer.initialize(from: srcData, count: bufferSize)
                                outDecDatalen!.pointee = bufferSize
                            } else {
                                outDecDatalen!.pointee = bufferSize
                            }
                        } else {
                            outDecDatalen!.pointee = 0
                        }
                    }
                    
                }, withClosure: {
                    param, len,outData,outDatalen in
                    outDatalen!.pointee = 0
                })
            }
        }
        
        if ofdHandle != 0 {
            strType = "OFD";
            reLoad()
//            images.removeAll()
//
//            if let jpgPageDatas = OFDConverter.ofd2Image(fileHandle: ofdHandle, imageFormat: "JPG") {
//                for jpgData in jpgPageDatas {
//                    if let image = UIImage(data: jpgData!) {
//                        images.append(image)
//                    }
//                }
//            }
            
            
            
            //close 方法在释放时必须调用，本例中因为测试而没有调用
            //OFD.close(handle: ofdHandle)
            //ofdHandle = 0
            showingAlert = true
        }
        
    }
    
    func openPDF()
    {
        createSeal()
        if pdfHandle == 0 {
            //let PDFData = loadFileFromBundle(fileName: "src2", fileExtension: "pdf")
            if let PDFData = loadFileFromBundle(fileName: "src", fileExtension: "pdf") {
                let pdfData = Utils.dataToUInt8Array(data:PDFData)
                self.pdfHandle = PDF.open(fileData: pdfData)
                
                //let encPdfData = PDF.documnetEncryptDecrypt(fileHandle: pdfHandle,isEncrypt:true,passWord:"");
                //PDF.documnetEncryptDecrypt(fileHandle: pdfHandle,isEncrypt:true,passWord:"12345678");
                //let isneed = PDF.isNeedPassword(fileHandle: pdfHandle)
                //if  isneed == 1  {
                //    print("pdf need password\n")
                //    PDF.setPassword(fileHandle: pdfHandle,passWord:"12345678");
                //}
                //PDF.documnetEncryptDecrypt(fileHandle: pdfHandle,isEncrypt:false,passWord:"");
            }
        }
        print("openPDF: 1")
        if pdfHandle != 0 {
            strType = "PDF";
            reLoad()
//            images.removeAll()
//
//            if let jpgPageDatas = PDFConverter.pdf2Image(fileHandle: pdfHandle, imageFormat: "JPG") {
//                for jpgData in jpgPageDatas {
//                    if let image = UIImage(data: jpgData!) {
//                        images.append(image)
//                    }
//                }
//            }
            
            //close 方法在释放时必须调用，本例中因为测试而没有调用
            //PDF.close(handle: pdfHandle)
            //pdfHandle = 0
            showingAlert = true
        }
        
        
    }
    
    
    func stampPos()
    {
        if strType == "OFD" && ofdHandle != 0 {
            
            OFDStampData = OFDStamp.positionSign(fileHandle: ofdHandle, sealData: SEALData, pageNumber: 1, stampX: 100, stampY: 100, width: 42, height: 42, isLocked: false, withClosure: { param,sourceData,sourceDatalen,outData,outDatalen in
                outDatalen!.pointee = 0
                if sourceData == nil || sourceDatalen == 0 || outData == nil || outDatalen == nil  {
                    return;
                }
            
                let srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
                if let signData = Crypto.sign(algType: Crypto.SM3_SM2,privateKey: keyPair_User!.getPrivateKey()!,sourceData: srcdata) {
                    let bufferSize = signData.count
                    if bufferSize > 0  {
                        if let actualPointer = outData!.pointee {
                            actualPointer.initialize(from: signData, count: bufferSize)
                            outDatalen!.pointee = bufferSize
                        } else {
                            outDatalen!.pointee = bufferSize
                        }
                    } else {
                        outDatalen!.pointee = 0
                    }
                }
                
            },
            withClosure: { param,outData,outDatalen in
                if outData == nil || outDatalen == nil || userCert == nil {
                    outDatalen!.pointee = 0
                    return;
                }
                let certBufferSize = userCert!.count
                if certBufferSize > 0  {
                    if let actualPointer = outData!.pointee {
                        actualPointer.initialize(from: userCert!, count: certBufferSize)
                        outDatalen!.pointee = certBufferSize
                    } else {
                        outDatalen!.pointee = certBufferSize
                    }
                } else {
                    outDatalen!.pointee = 0
                }
            })
            
        } else if strType == "PDF" && pdfHandle != 0 {
            if  PDF.isNeedPassword(fileHandle: pdfHandle) == 1  {
                print("sign pos ,pdf need password")
                PDF.setPassword(fileHandle: pdfHandle,passWord:"12345678");
            }
            PDFStampData = PDFStamp.positionSign(fileHandle: pdfHandle, sealImageData: Utils.dataToUInt8Array(data: SEALImageData!), sealAlpha: 0.86,pageNumber: 1, stampX: 100, stampY: 100, width: 42, height: 42, isLocked: false, withClosure: { param,sourceData,sourceDatalen,outData,outDatalen in
                outDatalen!.pointee = 0
                if sourceData == nil || sourceDatalen == 0 || outData == nil || outDatalen == nil  {
                    return;
                }
            
                let srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
                if let signData = Crypto.sign(algType: Crypto.SM3_SM2,privateKey: keyPair_User!.getPrivateKey()!,sourceData: srcdata) {
                    let bufferSize = signData.count
                    if bufferSize > 0  {
                        if let actualPointer = outData!.pointee {
                            actualPointer.initialize(from: signData, count: bufferSize)
                            outDatalen!.pointee = bufferSize
                        } else {
                            outDatalen!.pointee = bufferSize
                        }
                    } else {
                        outDatalen!.pointee = 0
                    }
                }
                
            },
            withClosure: { param,outData,outDatalen in
                if outData == nil || outDatalen == nil || userCert == nil {
                    outDatalen!.pointee = 0
                    return;
                }
                let certBufferSize = userCert!.count
                if certBufferSize > 0  {
                    if let actualPointer = outData!.pointee {
                        actualPointer.initialize(from: userCert!, count: certBufferSize)
                        outDatalen!.pointee = certBufferSize
                    } else {
                        outDatalen!.pointee = certBufferSize
                    }
                } else {
                    outDatalen!.pointee = 0
                }
            })
        }
        
        reLoad()
        
        showingAlert = true
    }
    
    func stampRiding()
    {
        if strType == "OFD" && ofdHandle != 0 {
            
            OFDStampData = OFDStamp.ridingSign(fileHandle: ofdHandle, sealData: SEALData, ridingType: "1", width: 42, height: 42, isLocked: false, withClosure: { param,sourceData,sourceDatalen,outData,outDatalen in
                outDatalen!.pointee = 0
                if sourceData == nil || sourceDatalen == 0 || outData == nil || outDatalen == nil  {
                    return;
                }
            
                let srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
                if let signData = Crypto.sign(algType: Crypto.SM3_SM2,privateKey: keyPair_User!.getPrivateKey()!,sourceData: srcdata) {
                    let bufferSize = signData.count
                    if bufferSize > 0  {
                        if let actualPointer = outData!.pointee {
                            actualPointer.initialize(from: signData, count: bufferSize)
                            outDatalen!.pointee = bufferSize
                        } else {
                            outDatalen!.pointee = bufferSize
                        }
                    } else {
                        outDatalen!.pointee = 0
                    }
                }
                
            },
            withClosure: { param,outData,outDatalen in
                if outData == nil || outDatalen == nil || userCert == nil {
                    outDatalen!.pointee = 0
                    return;
                }
                let certBufferSize = userCert!.count
                if certBufferSize > 0  {
                    if let actualPointer = outData!.pointee {
                        actualPointer.initialize(from: userCert!, count: certBufferSize)
                        outDatalen!.pointee = certBufferSize
                    } else {
                        outDatalen!.pointee = certBufferSize
                    }
                } else {
                    outDatalen!.pointee = 0
                }
            })
            
        } else if strType == "PDF" && pdfHandle != 0 {
            if  PDF.isNeedPassword(fileHandle: pdfHandle) == 1  {
                PDF.setPassword(fileHandle: pdfHandle,passWord:"12345678");
            }
            PDFStampData = PDFStamp.ridingSign(fileHandle: pdfHandle, sealImageData: Utils.dataToUInt8Array(data: SEALImageData!), sealAlpha: 0.86,ridingType: "1", width: 42, height: 42, isLocked: false, withClosure: { param,sourceData,sourceDatalen,outData,outDatalen in
                outDatalen!.pointee = 0
                if sourceData == nil || sourceDatalen == 0 || outData == nil || outDatalen == nil  {
                    return;
                }
            
                let srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
                if let signData = Crypto.sign(algType: Crypto.SM3_SM2,privateKey: keyPair_User!.getPrivateKey()!,sourceData: srcdata) {
                    let bufferSize = signData.count
                    if bufferSize > 0  {
                        if let actualPointer = outData!.pointee {
                            actualPointer.initialize(from: signData, count: bufferSize)
                            outDatalen!.pointee = bufferSize
                        } else {
                            outDatalen!.pointee = bufferSize
                        }
                    } else {
                        outDatalen!.pointee = 0
                    }
                }
                
            },
            withClosure: { param,outData,outDatalen in
                if outData == nil || outDatalen == nil || userCert == nil {
                    outDatalen!.pointee = 0
                    return;
                }
                let certBufferSize = userCert!.count
                if certBufferSize > 0  {
                    if let actualPointer = outData!.pointee {
                        actualPointer.initialize(from: userCert!, count: certBufferSize)
                        outDatalen!.pointee = certBufferSize
                    } else {
                        outDatalen!.pointee = certBufferSize
                    }
                } else {
                    outDatalen!.pointee = 0
                }
            })
        }
        
        reLoad()
        
        
        showingAlert = true
    }
    
    func stampKey()
    {
        let KeywordRule : String = "[{\"indexRules\":[{\"index\":-1,\"offsetX\":10.0,\"offsetY\":20.0}],\"pageNumber\":-1}]";
        if strType == "OFD" && ofdHandle != 0 {
            let KeyWord : String = "二十三年";
            OFDStampData = OFDStamp.keywordSign(fileHandle: ofdHandle, sealData: SEALData, keyWord : KeyWord,keyWordRules : KeywordRule, width: 42, height: 42, isLocked: false, withClosure: { param,sourceData,sourceDatalen,outData,outDatalen in
                outDatalen!.pointee = 0
                if sourceData == nil || sourceDatalen == 0 || outData == nil || outDatalen == nil  {
                    return;
                }
            
                let srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
                if let signData = Crypto.sign(algType: Crypto.SM3_SM2,privateKey: keyPair_User!.getPrivateKey()!,sourceData: srcdata) {
                    let bufferSize = signData.count
                    if bufferSize > 0  {
                        if let actualPointer = outData!.pointee {
                            actualPointer.initialize(from: signData, count: bufferSize)
                            outDatalen!.pointee = bufferSize
                        } else {
                            outDatalen!.pointee = bufferSize
                        }
                    } else {
                        outDatalen!.pointee = 0
                    }
                }
                
            },
            withClosure: { param,outData,outDatalen in
                if outData == nil || outDatalen == nil || userCert == nil {
                    outDatalen!.pointee = 0
                    return;
                }
                let certBufferSize = userCert!.count
                if certBufferSize > 0  {
                    if let actualPointer = outData!.pointee {
                        actualPointer.initialize(from: userCert!, count: certBufferSize)
                        outDatalen!.pointee = certBufferSize
                    } else {
                        outDatalen!.pointee = certBufferSize
                    }
                } else {
                    outDatalen!.pointee = 0
                }
            })
        } else if strType == "PDF" && pdfHandle != 0 {
            if  PDF.isNeedPassword(fileHandle: pdfHandle) == 1  {
                PDF.setPassword(fileHandle: pdfHandle,passWord:"12345678");
            }
            let KeyWord : String = "films";
            PDFStampData = PDFStamp.keywordSign(fileHandle: pdfHandle, sealImageData: Utils.dataToUInt8Array(data: SEALImageData!), sealAlpha: 0.86, keyWord : KeyWord,keyWordRules : KeywordRule, width: 42, height: 42, isLocked: false, withClosure: { param,sourceData,sourceDatalen,outData,outDatalen in
                outDatalen!.pointee = 0
                if sourceData == nil || sourceDatalen == 0 || outData == nil || outDatalen == nil  {
                    return;
                }
            
                let srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
                if let signData = Crypto.sign(algType: Crypto.SM3_SM2,privateKey: keyPair_User!.getPrivateKey()!,sourceData: srcdata) {
                    let bufferSize = signData.count
                    if bufferSize > 0  {
                        if let actualPointer = outData!.pointee {
                            actualPointer.initialize(from: signData, count: bufferSize)
                            outDatalen!.pointee = bufferSize
                        } else {
                            outDatalen!.pointee = bufferSize
                        }
                    } else {
                        outDatalen!.pointee = 0
                    }
                }
                
            },
            withClosure: { param,outData,outDatalen in
                if outData == nil || outDatalen == nil || userCert == nil {
                    outDatalen!.pointee = 0
                    return;
                }
                let certBufferSize = userCert!.count
                if certBufferSize > 0  {
                    if let actualPointer = outData!.pointee {
                        actualPointer.initialize(from: userCert!, count: certBufferSize)
                        outDatalen!.pointee = certBufferSize
                    } else {
                        outDatalen!.pointee = certBufferSize
                    }
                } else {
                    outDatalen!.pointee = 0
                }
            })
        }
        
        reLoad()
        
        showingAlert = true
    }
    
    func verify()
    {
        if strType == "OFD"  &&  OFDStampData != nil && OFDStampData!.count > 0 {
            
            if let strVerify : String = OFDStamp.verify(fileData: OFDStampData, withClosure: { param,algType,keyData,keyDatalen,sourceData,sourceDatalen,signData,signDatalen in
                
                    if keyData == nil || keyDatalen == 0 || sourceData == nil || sourceDatalen == 0 || signData == nil || signDatalen == 0 {
                        return false;
                    }
                
                    let publicKey : Key = Key(keyType: Key.SM2_PUB_KEY,key: Data(bytes: keyData!, count: Int(keyDatalen)))
                
                    let srcData = Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)
                    let sigData = Utils.convertToData(bytes: signData, lenght: signDatalen)
                
                    let srcUInt8s = Utils.dataToUInt8Array(data: srcData!)
                    let signUInt8s = Utils.dataToUInt8Array(data: sigData!)
                
                    let isVerify = Crypto.verify(algType: Crypto.SM3_SM2, publicKey: publicKey, sourceData: srcUInt8s, signData: signUInt8s)
                    //print(isVerify)
                    return isVerify
                
            }) {
                print(strVerify)
            }
            
            //OFDStamp.clearSigns(fileHandle: ofdHandle)
            //reLoad()
        } else if strType == "PDF" &&  PDFStampData != nil && PDFStampData!.count > 0  {
            var strPassWord : String = ""
            if  PDF.isNeedPassword(fileHandle: pdfHandle) == 1  {
                strPassWord = "12345678"
            }
            
            if let strVerify = PDFStamp.verify(fileData: PDFStampData,password: strPassWord, withClosure: { param,algType,keyData,keyDatalen,sourceData,sourceDatalen,signData,signDatalen in
                
                    if keyData == nil || keyDatalen == 0 || sourceData == nil || sourceDatalen == 0 || signData == nil || signDatalen == 0 {
                        return false;
                    }
                
                    let publicKey : Key = Key(keyType: Key.SM2_PUB_KEY,key: Data(bytes: keyData!, count: Int(keyDatalen)))
                
                    let srcData = Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)
                    let sigData = Utils.convertToData(bytes: signData, lenght: signDatalen)
                
                    let srcUInt8s = Utils.dataToUInt8Array(data: srcData!)
                    let signUInt8s = Utils.dataToUInt8Array(data: sigData!)
                
                    let isVerify = Crypto.verify(algType: Crypto.SM3_SM2, publicKey: publicKey, sourceData: srcUInt8s, signData: signUInt8s)
                    //print(isVerify)
                    return isVerify
                
            }) {
                print(strVerify)
            }
            
            //PDFStamp.clearSigns(fileHandle: pdfHandle)
            //reLoad()
        }
        
        

        
        
        showingAlert = true
    }
    
    func reLoad()
    {
        if strType == "OFD" && ofdHandle != 0 {
            images.removeAll()
            
            if let jpgPageDatas = OFDConverter.ofd2Image(fileHandle: ofdHandle, imageFormat: "PNG",scale: 1) {
                
                for jpgData in jpgPageDatas {
                    if let image = UIImage(data: jpgData!) {
                        images.append(image)
                    }
                }
            }
        } else if strType == "PDF" && pdfHandle != 0 {
            images.removeAll()
           
            if let jpgPageDatas = PDFConverter.pdf2Image(fileHandle: pdfHandle, imageFormat: "PNG",scale: 1) {
                
                for jpgData in jpgPageDatas {
                    if let image = UIImage(data: jpgData!) {
                        images.append(image)
                    }
                }
            }
        }
        print("reLoad end")
    }
    
    func createSeal() {
        
        if SEALData != nil {
            return
        }
        
        let RootDN = "C=CN,cn=rootCA,O=fzz"
        let DN_user = "C=CN,cn=user,O=fzz"
        let DN_seal = "C=CN,cn=stamp,O=fzz"
        
        if keyRootPair == nil  {
            keyRootPair = Crypto.generateAsymKey(algType: Crypto.SM2, length: 0)!
        }
        if keyPair_User == nil  {
            keyPair_User = Crypto.generateAsymKey(algType: Crypto.SM2, length: 0)!
        }
        if keyPair_Seal == nil  {
            keyPair_Seal = Crypto.generateAsymKey(algType: Crypto.SM2, length: 0)!
        }
        if rootCert == nil {
            rootCert = Crypto.generateRootCert(certDN: RootDN, publicKey: keyRootPair!.getPublicKey()!, validDays: 400, rootPrivateKey: keyRootPair!.getPrivateKey()!)
        }
        if userCert == nil {
            userCert = Crypto.generateCert(isSignCert: true, certDN: DN_user, publicKey: keyPair_User!.getPublicKey()!, validDays: 400, rootCertDN: RootDN, rootPrivateKey: keyRootPair!.getPrivateKey()!)
        }
        if sealCert == nil {
            sealCert = Crypto.generateCert(isSignCert: true, certDN: DN_seal, publicKey: keyPair_Seal!.getPublicKey()!, validDays: 400, rootCertDN: RootDN, rootPrivateKey: keyRootPair!.getPrivateKey()!)
        }
        
        // 获取当前日期和时间（注意：Swift 中的 Date 是基于绝对时间点的，不仅仅是日期和时间）
        let currentTime = Date()
          
        // 创建一个日历对象用于日期计算
        let calendar = Calendar.current
          
        var strCreateTime : String = ""
        if let date = calendar.date(byAdding: .day, value:-2, to: currentTime) {
            // 创建一个日期格式化器
            let formatter = DateFormatter()
            formatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
            formatter.locale = Locale.current
              
            // 格式化日期
            strCreateTime = formatter.string(from: date)
            print("strCreateTime: \(strCreateTime)")
        }
        
        var strStartTime : String = ""
        if let date = calendar.date(byAdding: .day, value: -1, to: currentTime) {
            // 创建一个日期格式化器
            let formatter = DateFormatter()
            formatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
            formatter.locale = Locale.current
              
            // 格式化日期
            strStartTime = formatter.string(from: date)
            print("strCreateTime: \(strStartTime)")
        }
        
        var strEndTime : String = ""
        if let date = calendar.date(byAdding: .day, value: 365, to: currentTime) {
            // 创建一个日期格式化器
            let formatter = DateFormatter()
            formatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
            formatter.locale = Locale.current
              
            // 格式化日期
            strEndTime = formatter.string(from: date)
            print("strCreateTime: \(strEndTime)")
        }
        if SEALImageData == nil {
            SEALImageData = loadFileFromBundle(fileName: "seal", fileExtension: "png")
        }
        
        if SEALImageData != nil {
            let imageData = Utils.dataToUInt8Array(data: SEALImageData!)
        
            SEALData = SealManager.createSeal(code: "11112222", type: "06", name: "test stamp", format: "PNG", image: imageData, width: 300, height: 300, createTime: strCreateTime, startTime: strStartTime, endTime: strEndTime,
                withClosure: { param,sourceData,sourceDatalen,outData,outDatalen in
                    outDatalen!.pointee = 0
                    if sourceData == nil || sourceDatalen == 0 || outData == nil || outDatalen == nil  {
                        return;
                    }
                
                    let srcdata = Utils.dataToUInt8Array(data: Utils.convertToData(bytes: sourceData, lenght: sourceDatalen)!)
                    if let signData = Crypto.sign(algType: Crypto.SM3_SM2,privateKey: keyPair_Seal!.getPrivateKey()!,sourceData: srcdata) {
                        let bufferSize = signData.count
                        if bufferSize > 0  {
                            if let actualPointer = outData!.pointee {
                                actualPointer.initialize(from: signData, count: bufferSize)
                                outDatalen!.pointee = bufferSize
                            } else {
                                outDatalen!.pointee = bufferSize
                            }
                        } else {
                            outDatalen!.pointee = 0
                        }
                    }
                    
                },
                withClosure: { param,outData,outDatalen in
                    if outData == nil || outDatalen == nil || userCert == nil {
                        outDatalen!.pointee = 0
                        return;
                    }
                    let certBufferSize = userCert!.count
                    if certBufferSize > 0  {
                        if let actualPointer = outData!.pointee {
                            actualPointer.initialize(from: userCert!, count: certBufferSize)
                            outDatalen!.pointee = certBufferSize
                        } else {
                            outDatalen!.pointee = certBufferSize
                        }
                    } else {
                        outDatalen!.pointee = 0
                    }
                },
                withClosure: { param,outData,outDatalen in
                    if outData == nil || outDatalen == nil || sealCert == nil {
                        outDatalen!.pointee = 0
                        return;
                    }
                    let certBufferSize = sealCert!.count
                    if certBufferSize > 0  {
                        if let actualPointer = outData!.pointee {
                            actualPointer.initialize(from: sealCert!, count: certBufferSize)
                            outDatalen!.pointee = certBufferSize
                        } else {
                            outDatalen!.pointee = certBufferSize
                        }
                    } else {
                        outDatalen!.pointee = 0
                    }
                })
                
            //print(SEALData!.count)
            
        } //if SEALImageData != nil
        
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
