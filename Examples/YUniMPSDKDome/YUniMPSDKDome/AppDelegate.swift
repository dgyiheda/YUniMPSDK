//
//  AppDelegate.swift
//  YUniMPSDKDome
//
//  Created by 谭浩 on 2023/9/15.
//

import UIKit
import YUniMPSDK

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        window = UIWindow.init(frame: UIScreen.main.bounds)
        window?.backgroundColor = .white
        window?.rootViewController = ViewController()
        window?.makeKeyAndVisible()
        
        let mpOptions = NSMutableDictionary(dictionary: launchOptions ?? [:])
        mpOptions.setValue(NSNumber(value: true), forKey: "debug")
        
        DCUniMPSDKEngine.initSDKEnvironment(launchOptions: mpOptions as! [AnyHashable: Any])
        DCUniMPSDKEngine.setCapsuleButtonHidden(false)
        DCUniMPSDKEngine.setAutoControlNavigationBar(true)
        
        let capsuleButtonStyle = DCUniMPCapsuleButtonStyle.init()
        // 胶囊按钮背景颜色
        capsuleButtonStyle.backgroundColor = "rgba(169,169,169,0.2)"
        // 胶囊按钮 “···｜x” 的字体颜色
        capsuleButtonStyle.textColor = "#FFFFFF"
        // 胶囊按钮按下状态背景颜色
        capsuleButtonStyle.highlightColor = "rgb(203,204,205)"
        // 胶囊按钮边框颜色
        capsuleButtonStyle.borderColor = "rgba(229,229,229,0.3)"
        // 设置样式
        DCUniMPSDKEngine.configCapsuleButtonStyle(capsuleButtonStyle)
        
        return true
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        print("applicationDidBecomeActive")
    }
    
    func applicationDidEnterBackground(_ application: UIApplication) {
        print("applicationDidEnterBackground")
    }
    
}

