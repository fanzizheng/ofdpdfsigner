import hilog from '@ohos.hilog';


import ofdpdfsigner, { Key, KeyPair,TextParams } from 'libofdpdfsigner.so'
import resourceManager from '@ohos.resourceManager';
import { SystemManager } from '../ofdpdfsigner/SystemMamager';

import image from '@ohos.multimedia.image';
import fs from '@ohos.file.fs'
import util from '@ohos.util';
import promptAction from '@ohos.promptAction';


@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  @State imageDatas: Array<image.PixelMap> = [undefined];

  ofdHandle : number = 0;
  pdfHandle : number = 0;
  sealData : Uint8Array = null;
  sealImageData : Uint8Array = null;

  keyRootPair : KeyPair = null;
  keyPair_User : KeyPair = null;
  keyPair_Seal : KeyPair = null;
  rootCert : Uint8Array = null;
  userCert : Uint8Array = null;
  sealCert : Uint8Array = null;
  openType : number = 0;

  ofdStampData : Uint8Array = null;
  pdfStampData : Uint8Array = null;



  uint8ArrayToHex(uint8Array: Uint8Array): string {
    let hexParts: string[] = [];
    for (let i = 0; i < uint8Array.length; i++) {
      let hexPart = uint8Array[i].toString(16).padStart(2, '0');
      hexParts.push(hexPart);
    }
    return hexParts.join(' ');
  }

  stringToUint8Array(str: string): Uint8Array {
    return new util.TextEncoder().encodeInto(str);//utf-8
  }

  uint8ArrayToString(data:Uint8Array):string {
    return util.TextDecoder.create("utf-8").decodeWithStream(data);
  }

  formatDateTime(date: Date): string {
    // 获取年、月、日、时、分、秒
    const year = date.getFullYear();
    const month = (date.getMonth() + 1).toString().padStart(2, '0'); // 月份是从0开始的
    const day = date.getDate().toString().padStart(2, '0');
    const hours = date.getHours().toString().padStart(2, '0');
    const minutes = date.getMinutes().toString().padStart(2, '0');
    const seconds = date.getSeconds().toString().padStart(2, '0');

    // 拼接成字符串
    const formattedDateTime = `${year}-${month}-${day} ${hours}:${minutes}:${seconds}`;

    return formattedDateTime;
  }

  createSealSub() {
    if ( this.sealData === null || this.sealData === undefined ) {
      let RootDN = "C=CN,cn=rootCA,O=fzz";
      let DN_user = "C=CN,cn=user,O=fzz";
      let DN_seal = "C=CN,cn=stamp,O=fzz";

      if (this.keyRootPair === null || this.keyRootPair === undefined )  {
        this.keyRootPair = ofdpdfsigner.generateAsymKey('SM2',0);
      }
      if (this.keyPair_User === null || this.keyPair_User === undefined ) {
        this.keyPair_User = ofdpdfsigner.generateAsymKey('SM2',0);
      }
      if (this.keyPair_Seal === null || this.keyPair_Seal === undefined )  {
        this.keyPair_Seal = ofdpdfsigner.generateAsymKey('SM2',0);
      }
      if (this.rootCert === null || this.rootCert === undefined ) {
        this.rootCert = ofdpdfsigner.generateRootCert(RootDN, this.keyRootPair.publicKey, 400, this.keyRootPair.privateKey);
      }
      if (this.userCert === null || this.userCert === undefined ) {
        this.userCert = ofdpdfsigner.generateCert(true, DN_user, this.keyPair_User.publicKey, 400, RootDN, this.keyRootPair.privateKey);
      }
      if (this.sealCert === null || this.sealCert === undefined ) {
        this.sealCert = ofdpdfsigner.generateCert(true, DN_seal, this.keyPair_Seal.publicKey, 400, RootDN, this.keyRootPair.privateKey);
      }

      let now = new Date();

      let createTime = new Date(now);
      createTime.setDate(createTime.getDate() - 2);
      let startTime = new Date(now);
      startTime.setDate(startTime.getDate() - 1);
      let endTime = new Date(now);
      endTime.setDate(endTime.getDate() + 365);

      let strCreateTime = this.formatDateTime(createTime);
      let strStartTime = this.formatDateTime(startTime);
      let strEndTime = this.formatDateTime(endTime);

      this.sealData = ofdpdfsigner.createSeal('111222','06','test stamp','PNG',this.sealImageData,300,300,strCreateTime,strStartTime,strEndTime,
        (sourceData) => {
          if (sourceData === null || sourceData === undefined ) {
            return null;
          }
          return ofdpdfsigner.sign('SM3_SM2',this.keyPair_Seal.privateKey,sourceData);
        },
        () => {
          return this.userCert;
        },
        () => {
          return this.sealCert;
        }
       );

      hilog.info(0x0000, 'fzz',  'createSeal end %{public}d',this.sealData.length);
      /*
      if ( ofdpdfsigner.verifySeal(this.sealData,(algType,pubKey,sourceData,signData) => {
        hilog.info(0x0000, 'fzz',  'verifySeal algType => '+ algType);
        return ofdpdfsigner.verify('SM3_SM2',pubKey,sourceData,signData);
      }) == 0 ) {
        hilog.info(0x0000, 'fzz',  'verifySeal => true');
        let imageData = ofdpdfsigner.getSealImageData(this.sealData);
        hilog.info(0x0000, 'fzz',  'verifySeal imageData => %{public}d', imageData.length);
        let userCertData = ofdpdfsigner.getSealUserCertData(this.sealData);
        hilog.info(0x0000, 'fzz',  'verifySeal imageData => %{public}d', userCertData.length);

      } else {
        hilog.info(0x0000, 'fzz',  'verifySeal => false');

      }
      */

    }
  }

  createStamp() {
    if ( this.sealImageData === null || this.sealImageData === undefined ) {
      const context: Context = getContext(this);
      const resourceMge: resourceManager.ResourceManager = context.resourceManager;
      resourceMge.getRawFileContent('seal.png').then((fileData:Uint8Array) => {
        this.sealImageData = fileData;

        this.createSealSub();
      });

    } else {
      this.createSealSub();
    }

  }

  deleteImageData() {
    ForEach(this.imageDatas, item => {
      if (item !== null && item !== undefined) {
        item.release();
      }
    })
    this.imageDatas.length = 0;
  }

  copyFileToCache(rawImageFile: string,cacheDir : string) {
    const fontsDir = cacheDir+'/OFDFonts/';
    const targetFontFilePath = cacheDir+'/'+rawImageFile;

    if (!fs.accessSync(fontsDir)) {
      fs.mkdirSync(fontsDir); // 使用 recursive 选项确保所有父目录都被创建
      //hilog.info(0x0000, 'fzz',  'create dir:'+fontsDir);
    }

    if (!fs.accessSync(targetFontFilePath)) {
      const context: Context = getContext(this);
      const resourceMge: resourceManager.ResourceManager = context.resourceManager;

      resourceMge.getRawFileContent(rawImageFile).then((fileData:Uint8Array) => {
          let file = fs.openSync(targetFontFilePath,fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
          fs.writeSync(file.fd, fileData.buffer );
          fs.fsyncSync(file.fd); // 以同步方法同步文件数据。
          fs.closeSync(file.fd);

      })
      //hilog.info(0x0000, 'fzz',  'write file:'+targetFontFilePath);
    }
  }

  Init() {
    const context: Context = getContext(this);
    const cacheDir = context.cacheDir;
    hilog.info(0x0000, 'fzz',  'cacheDir:'+cacheDir);
    //this.copyFileToCache("OFDFonts/AdobeSongStd-Light.otf",cacheDir);
    this.copyFileToCache("OFDFonts/simsun.ttf",cacheDir);
    //this.copyFileToCache("OFDFonts/fzysong_b_gbk.TTF",cacheDir);
    //this.copyFileToCache("OFDFonts/arial.ttf",cacheDir);
    //this.copyFileToCache("OFDFonts/arialbd.ttf",cacheDir);
    //this.copyFileToCache("OFDFonts/arialbi.ttf",cacheDir);
   // this.copyFileToCache("OFDFonts/ariali.ttf",cacheDir);
    //this.copyFileToCache("OFDFonts/ariblk.ttf",cacheDir);
    //this.copyFileToCache("OFDFonts/calibri.ttf",cacheDir);
    //this.copyFileToCache("OFDFonts/calibrib.ttf",cacheDir);
    //this.copyFileToCache("OFDFonts/calibrii.ttf",cacheDir);
    //this.copyFileToCache("OFDFonts/calibril.ttf",cacheDir);
    //this.copyFileToCache("OFDFonts/calibrili.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/calibriz.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/cour.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/courbd.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/courbi.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/couri.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/Deng.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/Dengb.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/Dengl.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/msyh.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/msyhbd.ttc",cacheDir);
    // this.copyFileToCache("OFDFonts/msyhl.ttc",cacheDir);
    // this.copyFileToCache("OFDFonts/NSimSun.ttf",cacheDir);
    this.copyFileToCache("OFDFonts/simfang.ttf",cacheDir);
    this.copyFileToCache("OFDFonts/simhei.ttf",cacheDir);
    this.copyFileToCache("OFDFonts/simkai.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/STSong-Light-UniGB-UCS2-H.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/tahoma.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/tahomabd.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/times.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/timesbd.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/timesbi.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/timesi.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/webdings.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/fzxiaobiaosong-b05s.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/STSongStd-Light-Acro.otf",cacheDir);
    // this.copyFileToCache("OFDFonts/wenquanyizenhei.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/batang.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/malgun.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/wingdings2.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/Wingdings3.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/Wingdings.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/stliti.ttf",cacheDir);
    // this.copyFileToCache("OFDFonts/msgothic.ttf",cacheDir);

    const tempDir = cacheDir+'/temp';
    if (!fs.accessSync(tempDir)) {
      fs.mkdirSync(tempDir); // 使用 recursive 选项确保所有父目录都被创建
      hilog.info(0x0000, 'fzz',  'temp dir:'+tempDir);
    }

    try {
      ofdpdfsigner.setTempPath(tempDir);
      ofdpdfsigner.setWorkPath(cacheDir);
      if (ofdpdfsigner.getAllSystemFontFileName((fileName) => {
        hilog.info(0x0000, 'fzz', 'getAllSystemFontFileName = '+fileName);
        // if (ofdpdfsigner.saveFontFileNameCache(fileName)) {
        //   hilog.info(0x0000, 'fzz', 'saveFontFileNameCache => true');
        // } else {
        //   hilog.info(0x0000, 'fzz', 'saveFontFileNameCache => false');
        // }
      })) {
        hilog.info(0x0000, 'fzz', 'getAllSystemFontFileName => true');
      } else {
        hilog.info(0x0000, 'fzz', 'getAllSystemFontFileName => false');
      }

      if (ofdpdfsigner.saveFontFileNameCache('/data/storage/el2/base/haps/entry/cache/OFDFonts/simsun.ttf')) {
        hilog.info(0x0000, 'fzz', 'saveFontFileNameCache => true');
      } else {
        hilog.info(0x0000, 'fzz', 'saveFontFileNameCache => false');
      }
      ofdpdfsigner.saveFontFileNameCache('/data/storage/el2/base/haps/entry/cache/OFDFonts/simhei.ttf');
      ofdpdfsigner.saveFontFileNameCache('/data/storage/el2/base/haps/entry/cache/OFDFonts/simkai.ttf');
      ofdpdfsigner.saveFontFileNameCache('/data/storage/el2/base/haps/entry/cache/OFDFonts/simfang.ttf');
    } catch (error) {
      hilog.info(0x0000, 'fzz',  'error:'+error.message);
    }

    this.createStamp();

    hilog.info(0x0000, 'fzz',  'Init() ok');
  }

  pdfImageDatas : Uint8Array[] = [];
  pdfImageDatasIndex : number = 0;
  ofdImageDatas : Uint8Array[] = [];
  ofdImageDatasIndex : number = 0;

  loadPDFImageSub() {
    if (this.pdfImageDatasIndex < this.pdfImageDatas.length) {
      hilog.info(0x0000, 'fzz',  'pdf image len  %{public}d',this.pdfImageDatas[this.pdfImageDatasIndex].length);
      const imageSource: image.ImageSource = image.createImageSource(this.pdfImageDatas[this.pdfImageDatasIndex].buffer.slice(0));
      imageSource.createPixelMap().then((pixelMap: image.PixelMap) => {
        this.imageDatas.push(pixelMap);
        this.pdfImageDatasIndex++;
        this.loadPDFImageSub();
      });
    }
  }

  loadPDFImage() {
    if ( this.pdfHandle != 0 ) {
      hilog.info(0x0000, 'fzz',  'loadPDFImage begin');
      this.pdfImageDatas = ofdpdfsigner.pdf_toImage(this.pdfHandle,"JPG",1);
      hilog.info(0x0000, 'fzz',  'pdf_toImage end  %{public}d',this.pdfImageDatas.length);
      this.deleteImageData();
      if ( this.pdfImageDatas.length > 0 ) {
        this.pdfImageDatasIndex = 0;
        this.loadPDFImageSub();

      }
    }//if
  }

  loadOFDImageSub() {
    if (this.ofdImageDatasIndex < this.ofdImageDatas.length) {
      hilog.info(0x0000, 'fzz',  'ofd image len  %{public}d',this.ofdImageDatas[this.ofdImageDatasIndex].length);
      const imageSource: image.ImageSource = image.createImageSource(this.ofdImageDatas[this.ofdImageDatasIndex].buffer.slice(0));
      hilog.info(0x0000, 'fzz',  'imageSource ok');
      imageSource.createPixelMap().then((pixelMap: image.PixelMap) => {
        this.imageDatas.push(pixelMap);
        this.ofdImageDatasIndex++;
        this.loadOFDImageSub();
      });
    }
  }

  loadOFDImage() {
    if ( this.ofdHandle != 0 ) {
      hilog.info(0x0000, 'fzz',  'loadOFDImage begin');
      this.ofdImageDatas = ofdpdfsigner.ofd_toImage(this.ofdHandle,"JPG",1);
      hilog.info(0x0000, 'fzz',  'ofd_toImage end %{public}d',this.ofdImageDatas.length);
      this.deleteImageData();
      if ( this.ofdImageDatas.length > 0 ) {
        this.ofdImageDatasIndex = 0;
        this.loadOFDImageSub();

      }

    }
  }

  createKey(keyTypeData:string, keyData:Uint8Array) : Key {
    return {
      keyType: keyTypeData, //"SM4","SM2_Public","SM2_Private"
      key: keyData
    }
  }


  build() {
    Column() {

      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Swiper() {

          if (this.imageDatas.length == 0) {
            Image($r('app.media.icon'))
              .width('100%')
              .height('100%')
              .objectFit(ImageFit.Contain);
          } else {

            ForEach(this.imageDatas, item => {
              if (item !== null && item !== undefined) {
                Image(item)
                  .width('100%')
                  .height('100%')
                  .objectFit(ImageFit.Contain);
              } else {
                Image($r('app.media.icon'))
                  .width('100%')
                  .height('100%')
                  .objectFit(ImageFit.Contain);
              }
            })
          }

        }.onAppear(() => {
          this.Init();
        })


      }
      .layoutWeight(1)
      .width('100%')
      //.backgroundColor("#8EE5EE")
      Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.SpaceBetween }) {
        Image($r('app.media.ofdopen')).width(52).height(52).onClick(()=>{
          this.openType = 1;
          if ( this.ofdHandle == 0 ) {
            const context: Context = getContext(this);
            const resourceMge: resourceManager.ResourceManager = context.resourceManager;

            resourceMge.getRawFileContent('src.ofd').then((fileData:Uint8Array) => {

              this.ofdHandle = ofdpdfsigner.ofd_open(fileData);

              let base64 = new util.Base64Helper();
              let certBase64 = base64.encodeToStringSync(this.userCert);
              ofdpdfsigner.ofd_encryptDocument(this.ofdHandle,'[{"mode":1,"passWordCert":"12345678","userName":"user 1","userType":"User"},{"mode":2,"passWordCert":"'+certBase64+'","userName":"user 2","userType":"Owner"}]',
                (key,iv,sourceData) => {
                  //hilog.info(0x0000, 'fzz crypto', 'ofd_encryptDocument => sm4 enc');

                  return ofdpdfsigner.encryptSM4CBC(key,iv,sourceData);
                }, (key,iv,encryptData) => {
                  return null;
                },(publicKey,sourceData) => {
                  //hilog.info(0x0000, 'fzz crypto', 'ofd_encryptDocument => sm2 enc');

                  let encData_sm2 =ofdpdfsigner.encrypt('SM2_ENC',publicKey,sourceData);
                  return encData_sm2.encryptData;
                }, (encryptData) => {
                  return null;
                }, (len) => {
                  //hilog.info(0x0000, 'fzz crypto', 'ofd_encryptDocument => generateRandom');
                  return ofdpdfsigner.generateRandom(len);
                });
              ofdpdfsigner.ofd_protect(this.ofdHandle,(sourceData) => {
                hilog.info(0x0000, 'fzz crypto', 'ofd_protect => sm2 sign');
                if (sourceData === null || sourceData === undefined ) {
                  return null;
                }
                return ofdpdfsigner.sign('SM3_SM2',this.keyPair_User.privateKey,sourceData);
              },
                () => {
                  return this.userCert;
                });

              if ( ofdpdfsigner.ofd_isProtect(this.ofdHandle) == 1 ) {
                let proverify = ofdpdfsigner.ofd_protectionVerify(this.ofdHandle, (algType, pubKey, sourceData, signData) => {
                  return ofdpdfsigner.verify('SM3_SM2', pubKey, sourceData, signData);
                });

                promptAction.showToast({message: 'OFD 验证完整性保护成功！'+proverify, duration: 2000, bottom: 100 });
              }

              ofdpdfsigner.ofd_decryptDocument(this.ofdHandle,1, '12345678', 'user 1', 'User',
                (key,iv,sourceData) => {
                return null;
              }, (key,iv,encryptData) => {


                return ofdpdfsigner.decryptSM4CBC(key,iv,encryptData);
              },(publicKey,sourceData) => {
                return null;
              }, (encryptData) => {
                return ofdpdfsigner.decrypt('SM2_ENC',this.keyPair_User.privateKey, { encryptData:encryptData,macData:null });
              }, (len) => {
                return null;
              });

              if ( this.ofdHandle != 0 ) {
                this.loadOFDImage();
                // if ( this.pdfHandle != 0 ) {
                //   ofdpdfsigner.pdf_close(this.pdfHandle);
                //
                // }
                // let pdfdata = ofdpdfsigner.ofdToPdf(this.ofdHandle,true);
                // this.pdfHandle = ofdpdfsigner.pdf_open(pdfdata);
                //
                // if ( this.pdfHandle != 0 ) {
                //   this.loadPDFImage();
                // }
              }

            });
          } else {
            this.loadOFDImage();
          }

          hilog.info(0x0000, 'testTag', 'OpenRDF => onclick');
        })
        Image($r('app.media.pdfopen')).width(52).height(52).onClick(()=>{
          this.openType = 2;
          if ( this.pdfHandle == 0 ) {
            const context: Context = getContext(this);
            const resourceMge: resourceManager.ResourceManager = context.resourceManager;
            resourceMge.getRawFileContent('src.pdf').then((fileData:Uint8Array) => {
              this.pdfHandle = ofdpdfsigner.pdf_open(fileData);
              if ( this.pdfHandle != 0 ) {
                //ofdpdfsigner.pdf_documnetEncryptDecrypt(this.pdfHandle,true,"");
                ofdpdfsigner.pdf_documnetEncryptDecrypt(this.pdfHandle,true,"12345678");
                if ( ofdpdfsigner.pdf_isNeedPassWord(this.pdfHandle) == 1 ) {
                  ofdpdfsigner.pdf_setPassWord(this.pdfHandle,"12345678");
                }
                //ofdpdfsigner.pdf_documnetEncryptDecrypt(this.pdfHandle,false,"");
                this.loadPDFImage();
                // if ( this.ofdHandle != 0 ) {
                //   ofdpdfsigner.ofd_close(this.ofdHandle);
                //
                // }
                // let ofddata = ofdpdfsigner.pdfToOfd(this.pdfHandle,true);
                // this.ofdHandle = ofdpdfsigner.ofd_open(ofddata);
                //
                // if ( this.ofdHandle != 0 ) {
                //   this.loadOFDImage();
                // }
              }

            });
          } else {
            this.loadPDFImage();
          }


          hilog.info(0x0000, 'testTag', 'pdf open => onclick');
        })
        Image($r('app.media.stamppos')).width(52).height(52).onClick(()=>{
          if ( this.openType == 1 && this.ofdHandle != 0 ) {
            //ofd
            this.ofdStampData = ofdpdfsigner.ofd_positionSign(this.ofdHandle,this.sealData,1,100,100,42,42,false,
              (sourceData) => {
                if (sourceData === null || sourceData === undefined ) {
                  return null;
                }
                return ofdpdfsigner.sign('SM3_SM2',this.keyPair_User.privateKey,sourceData);
              },
              () => {
                return this.userCert;
              }
            );
            this.loadOFDImage();
            promptAction.showToast({message: 'OFD位置盖章成功！', duration: 2000, bottom: 100 });
          } else if ( this.openType == 2 && this.pdfHandle != 0 ){
            //pdf
            if ( ofdpdfsigner.pdf_isNeedPassWord(this.pdfHandle) == 1 ) {
              ofdpdfsigner.pdf_setPassWord(this.pdfHandle,"12345678");
            }
            this.pdfStampData = ofdpdfsigner.pdf_positionSign(this.pdfHandle,this.sealImageData,0.86,1,100,100,42,42,false,
              (sourceData) => {
                if (sourceData === null || sourceData === undefined ) {
                  return null;
                }
                return ofdpdfsigner.sign('SM3_SM2',this.keyPair_User.privateKey,sourceData);
              },
              () => {
                return this.userCert;
              }
            );
            this.loadPDFImage();
            promptAction.showToast({message: 'PDF位置盖章成功！', duration: 2000, bottom: 100 });
          }


        })
        Image($r('app.media.stampriding')).width(52).height(52).onClick(()=>{
          if ( this.openType == 1 && this.ofdHandle != 0 ) {
            //ofd
            this.ofdStampData = ofdpdfsigner.ofd_ridingSign(this.ofdHandle,this.sealData,"1",42,42,false,
              (sourceData) => {
                if (sourceData === null || sourceData === undefined ) {
                  return null;
                }
                return ofdpdfsigner.sign('SM3_SM2',this.keyPair_User.privateKey,sourceData);
              },
              () => {
                return this.userCert;
              }
            );
            this.loadOFDImage();
            promptAction.showToast({message: 'OFD奇峰盖章成功！', duration: 2000, bottom: 100 });
          } else if ( this.openType == 2 && this.pdfHandle != 0 ){
            //pdf
            if ( ofdpdfsigner.pdf_isNeedPassWord(this.pdfHandle) == 1 ) {
              ofdpdfsigner.pdf_setPassWord(this.pdfHandle,"12345678");
            }
            this.pdfStampData = ofdpdfsigner.pdf_ridingSign(this.pdfHandle,this.sealImageData,0.86,"1",42,42,false,
              (sourceData) => {
                if (sourceData === null || sourceData === undefined ) {
                  return null;
                }
                return ofdpdfsigner.sign('SM3_SM2',this.keyPair_User.privateKey,sourceData);
              },
              () => {
                return this.userCert;
              }
            );
            this.loadPDFImage();
            promptAction.showToast({message: 'PDF奇峰盖章成功！', duration: 2000, bottom: 100 });
          }

        })
        Image($r('app.media.stampkey')).width(52).height(52).onClick(()=>{
          const KeywordRule : string = '[{"indexRules":[{"index":-1,"offsetX":10.0,"offsetY":20.0}],"pageNumber":-1}]';

          if ( this.openType == 1 && this.ofdHandle != 0 ) {
            //ofd
            this.ofdStampData = ofdpdfsigner.ofd_keywordSign(this.ofdHandle,this.sealData,'二十三年',KeywordRule,42,42,false,
              (sourceData) => {
                if (sourceData === null || sourceData === undefined ) {
                  return null;
                }
                return ofdpdfsigner.sign('SM3_SM2',this.keyPair_User.privateKey,sourceData);
              },
              () => {
                return this.userCert;
              }
            );
            this.loadOFDImage();
            promptAction.showToast({message: 'OFD关键字盖章成功！', duration: 2000, bottom: 100 });
          } else if ( this.openType == 2 && this.pdfHandle != 0 ){
            //pdf
            if ( ofdpdfsigner.pdf_isNeedPassWord(this.pdfHandle) == 1 ) {
              ofdpdfsigner.pdf_setPassWord(this.pdfHandle,"12345678");
            }
            this.pdfStampData = ofdpdfsigner.pdf_keywordSign(this.pdfHandle,this.sealImageData,0.86,'films',KeywordRule,42,42,false,
              (sourceData) => {
                if (sourceData === null || sourceData === undefined ) {
                  return null;
                }
                return ofdpdfsigner.sign('SM3_SM2',this.keyPair_User.privateKey,sourceData);
              },
              () => {
                return this.userCert;
              }
            );
            this.loadPDFImage();
            promptAction.showToast({message: 'PDF关键字盖章成功！', duration: 2000, bottom: 100 });
          }

        })
        Image($r('app.media.stampverify')).width(52).height(52).onClick(()=>{
          if ( this.openType == 1 && this.ofdStampData !== null ) {
            //ofd
            let ofdv =ofdpdfsigner.ofd_verify(this.ofdStampData,(algType,pubKey,sourceData,signData) => {
              return ofdpdfsigner.verify('SM3_SM2',pubKey,sourceData,signData);
            });
            promptAction.showToast({message: 'OFD验证盖章成功！'+ofdv, duration: 2000, bottom: 100 });
          } else if ( this.openType == 2 && this.pdfStampData !== null ) {
            //pdf
            if (ofdpdfsigner.pdf_isNeedPassWord(this.pdfHandle) == 1) {
              let pdfv = ofdpdfsigner.pdf_verify(this.pdfStampData, '12345678', (algType, pubKey, sourceData, signData) => {
                return ofdpdfsigner.verify('SM3_SM2', pubKey, sourceData, signData);
              });
              promptAction.showToast({message: 'PDF验证盖章成功！'+pdfv, duration: 2000, bottom: 100 });
            } else {

              let pdfv = ofdpdfsigner.pdf_verify(this.pdfStampData, '', (algType, pubKey, sourceData, signData) => {
                return ofdpdfsigner.verify('SM3_SM2', pubKey, sourceData, signData);
              });
              promptAction.showToast({message: 'PDF验证盖章成功！'+pdfv, duration: 2000, bottom: 100 });
            }

          }
          // let textParams: TextParams = {
          //   text: ["附件多少积分多少", "房价多少","而扼腕发货的"],
          //   textAlign: "left",
          //   color: [
          //     { r: 154, g: 124, b: 63 ,a: 150},
          //     { r: 153, g: 64, b: 92 ,a:150},
          //     { r: 62, g: 78, b: 155 ,a:150}
          //   ],
          //   font: ["楷体", "黑体", "黑体"],
          //   fontSize: [24, 18, 16],
          //   isFontBold: [false, false,false],
          //   lineSpacing: [8, 8]
          // };
          //
          // // let waterMarkImage = ofdpdfsigner.createWaterMark(-22,2,false,null,textParams);
          // // this.deleteImageData();
          // // const imageSource: image.ImageSource = image.createImageSource(waterMarkImage.image.buffer.slice(0));
          // // imageSource.createPixelMap().then((pixelMap: image.PixelMap) => {
          // //   this.imageDatas.push(pixelMap);
          // // });
          //
          // let waterMarkImage_2 = ofdpdfsigner.createWaterMark(-22,2,true,this.sealImageData,textParams);
          // this.deleteImageData();
          // const imageSource: image.ImageSource = image.createImageSource(waterMarkImage_2.image.buffer.slice(0));
          // imageSource.createPixelMap().then((pixelMap: image.PixelMap) => {
          //   this.imageDatas.push(pixelMap);
          //
          //
          // });



        })
      }
      .height(64)
      .width('100%')
      .backgroundColor("#CFD8E5")
      .padding({ left: '20px', right: '20px',top:'20px' })
    }
    .width('100%')
    .height('100%')

  }
}
//------------------------------------------------------------------------
// let data = ofdpdfsigner.generateRandom(16);
// const strvalue = this.uint8ArrayToHex(data);
// hilog.info(0x0000, 'fzz crypto', 'generateRandom => '+ strvalue );
//------------------------------------------------------------------------
// let data = ofdpdfsigner.generateDigest('SM3',this.stringToUint8Array('aabbccjfds积分多少了'));
// const strvalue = this.uint8ArrayToHex(data);
// hilog.info(0x0000, 'fzz crypto', 'generateDigest => '+ strvalue );
//------------------------------------------------------------------------
// let sm4Key = ofdpdfsigner.generateSymKey('SM4',0);
// const strvalue = this.uint8ArrayToHex(sm4Key.key);
// hilog.info(0x0000, 'fzz crypto', 'generateSymKey => keyType:'+sm4Key.keyType + ' key:'+ strvalue );
//
// let sm2Key = ofdpdfsigner.generateAsymKey('SM2',0);
//
// const strvaluepub = this.uint8ArrayToHex(sm2Key.publicKey.key);
// hilog.info(0x0000, 'fzz crypto', 'generateAsymKey->pubkey => keyType:'+sm2Key.publicKey.keyType + ' key:'+ strvaluepub );
// const strvaluepri = this.uint8ArrayToHex(sm2Key.privateKey.key);
// hilog.info(0x0000, 'fzz crypto', 'generateAsymKey->prikey => keyType:'+sm2Key.privateKey.keyType + ' key:'+ strvaluepri );
//------------------------------------------------------------------------
// let srcdata = ofdpdfsigner.generateDigest('SM3',this.stringToUint8Array('aabbccjfds积分多少了'));
// let sm4Key = ofdpdfsigner.generateSymKey('SM4',0);
// const strvalue = this.uint8ArrayToHex(sm4Key.key);
// hilog.info(0x0000, 'fzz crypto', 'generateSymKey => keyType:'+sm4Key.keyType + ' key:'+ strvalue );
//
//
// let encData_cbc = ofdpdfsigner.encrypt("SM4_CBC",sm4Key,srcdata);
// hilog.info(0x0000, 'fzz crypto', 'encrypt => SM4_CBC, encData:'+ this.uint8ArrayToHex(encData_cbc.encryptData) );
// if (!(encData_cbc.macData === null || encData_cbc.macData === undefined)) {
//   hilog.info(0x0000, 'fzz crypto', 'encrypt => SM4_CBC, encData.macData:'+ this.uint8ArrayToHex(encData_cbc.macData) );
// }
// let decData_cbc = ofdpdfsigner.decrypt("SM4_CBC",sm4Key,encData_cbc);
// hilog.info(0x0000, 'fzz crypto', 'decrypt => SM4_CBC, decData:'+ this.uint8ArrayToString(decData_cbc) );
//
// let encData_gcm = ofdpdfsigner.encrypt("SM4_GCM",sm4Key,srcdata);
// hilog.info(0x0000, 'fzz crypto', 'encrypt => SM4_GCM, encData:'+ this.uint8ArrayToHex(encData_gcm.encryptData) );
// if (!(encData_gcm.macData === null || encData_gcm.macData === undefined)) {
//   hilog.info(0x0000, 'fzz crypto', 'encrypt => SM4_GCM, encData.macData:'+ this.uint8ArrayToHex(encData_gcm.macData) );
// }
// let decData_gcm = ofdpdfsigner.decrypt("SM4_GCM",sm4Key,encData_gcm);
// hilog.info(0x0000, 'fzz crypto', 'decrypt => SM4_GCM, decData:'+ this.uint8ArrayToString(decData_gcm) );
//
// let encData_ctr = ofdpdfsigner.encrypt("SM4_CTR",sm4Key,srcdata);
// hilog.info(0x0000, 'fzz crypto', 'encrypt => SM4_CTR, encData:'+ this.uint8ArrayToHex(encData_ctr.encryptData) );
// if (!(encData_ctr.macData === null || encData_ctr.macData === undefined)) {
//   hilog.info(0x0000, 'fzz crypto', 'encrypt => SM4_CTR, encData.macData:'+ this.uint8ArrayToHex(encData_ctr.macData) );
// }
// let decData_ctr = ofdpdfsigner.decrypt("SM4_CTR",sm4Key,encData_ctr);
// hilog.info(0x0000, 'fzz crypto', 'decrypt => SM4_CTR, decData:'+ this.uint8ArrayToString(decData_ctr) );
//
// let sm2Key = ofdpdfsigner.generateAsymKey('SM2',0);
//
// const strvaluepub = this.uint8ArrayToHex(sm2Key.publicKey.key);
// hilog.info(0x0000, 'fzz crypto', 'generateAsymKey->pubkey => keyType:'+sm2Key.publicKey.keyType + ' key:'+ strvaluepub );
// const strvaluepri = this.uint8ArrayToHex(sm2Key.privateKey.key);
// hilog.info(0x0000, 'fzz crypto', 'generateAsymKey->prikey => keyType:'+sm2Key.privateKey.keyType + ' key:'+ strvaluepri );
// let encData_sm2 = ofdpdfsigner.encrypt("SM2_ENC",sm2Key.publicKey,srcdata);
// hilog.info(0x0000, 'fzz crypto', 'encrypt => SM2_ENC, encData:'+ this.uint8ArrayToHex(encData_sm2.encryptData) );
// if (!(encData_sm2.macData === null || encData_sm2.macData === undefined)) {
//   hilog.info(0x0000, 'fzz crypto', 'encrypt => SM2_ENC, encData.macData:'+ this.uint8ArrayToHex(encData_sm2.macData) );
// }
// let decData_sm2 = ofdpdfsigner.decrypt("SM2_ENC",sm2Key.privateKey,encData_sm2);
// hilog.info(0x0000, 'fzz crypto', 'decrypt => SM2_ENC, decData:'+ this.uint8ArrayToString(decData_sm2) );
//------------------------------------------------------------------------
// let srcData = this.stringToUint8Array('aabbccjfds积分多少了');
// let sm2Key = ofdpdfsigner.generateAsymKey('SM2',0);
// let signData = ofdpdfsigner.sign('SM3_SM2',sm2Key.privateKey,srcData);
// hilog.info(0x0000, 'fzz crypto', 'sign => '+ this.uint8ArrayToHex(signData) );
// if ( ofdpdfsigner.verify('SM3_SM2',sm2Key.publicKey,srcData,signData) ) {
//   hilog.info(0x0000, 'fzz crypto', 'verify => true' );
// } else {
//   hilog.info(0x0000, 'fzz crypto', 'verify => false' );
// }
//------------------------------------------------------------------------
// let rootDN = "C=CN,cn=rootCA,O=fzz";
// let DN = "C=CN,cn=stamp,O=fzz";
// let keyRootPair = ofdpdfsigner.generateAsymKey('SM2',0);
// let keyPair = ofdpdfsigner.generateAsymKey('SM2',0);
// let keyPair_enc = ofdpdfsigner.generateAsymKey('SM2',0);
//
// let rootCert = ofdpdfsigner.generateRootCert(rootDN,keyRootPair.publicKey,356,keyRootPair.privateKey);
// let signCert = ofdpdfsigner.generateCert(true,DN,keyPair.publicKey,356,rootDN,keyRootPair.privateKey);
// let encCert = ofdpdfsigner.generateCert(false,DN,keyPair_enc.publicKey,356,rootDN,keyRootPair.privateKey);
//
// hilog.info(0x0000, 'fzz crypto', 'rootCert => '+ this.uint8ArrayToHex(rootCert) );
// hilog.info(0x0000, 'fzz crypto', 'signCert => '+ this.uint8ArrayToHex(signCert) );
// hilog.info(0x0000, 'fzz crypto', 'encCert => '+ this.uint8ArrayToHex(encCert) );
//------------------------------------------------------------------------







