//
//  ofdpdfsigner_iosApp.swift
//  ofdpdfsigner_ios
//
//  Created by zizheng fan on 2025/4/10.
//

import SwiftUI

@main
struct ofdpdfsigner_iosApp: App {
    init() {
        //OFDPDFSignerInit()
        // 监听应用进入后台的通知
        NotificationCenter.default.addObserver(forName: UIApplication.didEnterBackgroundNotification, object: nil, queue: .main) {  notification in
            // 在这里处理应用进入后台的逻辑
            // 例如，保存用户数据到磁盘
            print("App did enter background")
            // ... 其他清理操作 ...
        }
        
        NotificationCenter.default.addObserver(forName: UIApplication.willTerminateNotification, object: nil, queue: .main) {  notification in
            // 在这里执行一些轻量级的清理工作
            // 例如，取消后台任务、释放资源等
            print("App will be terminated")
            // ... 其他清理操作 ...
        }
    }
    
    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}
