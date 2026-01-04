import hilog from '@ohos.hilog';

export class SystemManager {

  static setWorkPath(filePath: string): boolean {
    hilog.info(0x0000, 'SystemManager', filePath);
    return true;
  }

  static setTempPath(filePath: string): boolean {
    hilog.info(0x0000, 'SystemManager', filePath);
    return true;
  }
}