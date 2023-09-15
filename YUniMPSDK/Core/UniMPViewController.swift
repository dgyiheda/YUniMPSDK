//
//  UniMPViewController.swift
//  YhdSuperApp
//
//  Copyright © 2023 Dongguan Yiheda Automation Co., Ltd.
//
//

import Foundation
import UIKit

/// 小程序SDK 视图管理器
public class UniMPViewController: UIViewController, DCUniMPSDKEngineDelegate {

  /// APPID
  public var appId: String = ""

  /// 保存当前打开的小程序应用的引用 注意：请使用 weak 修辞，否则应在关闭小程序时置为 nil
  public weak var currentUniMP: DCUniMPInstance?

  /// 初始化器
  //    public init(appId: String = "", currentUniMP: DCUniMPInstance?) {
  //        self.appId = appId
  //        self.currentUniMP = currentUniMP
  //    }
  //
  //    required init?(coder: NSCoder) {
  //        fatalError("init(coder:) has not been implemented")
  //    }

  // MARK: - View Controller Life Cycle

  override public func viewDidLoad() {
    super.viewDidLoad()
    self.setDelegate()
  }

  /// 设置小程序公用菜单选项
  /// - Parameter menuItems: 菜单项数组
  public func setDefaultMenu(_ menuItems: [DCUniMPMenuActionSheetItem]) {
    //        let item = DCUniMPMenuActionSheetItem.init(title: "将小程序隐藏到后台", identifier: "enterBackground")
    //        let item2 = DCUniMPMenuActionSheetItem.init(title: "关闭小程序", identifier: "closeUniMP")
    DCUniMPSDKEngine.setDefaultMenuItems(menuItems)
  }

  /// 设置Uni小程序代理
  public func setDelegate() {
    DCUniMPSDKEngine.setDelegate(self)
  }

  // MARK: - 检测小程序资源是否解压

  /// 如未解压解压
  public func checkUniMPResoutce() -> Bool {
    let wgtPath = Bundle.main.path(forResource: self.appId, ofType: "wgt") ?? ""
    if DCUniMPSDKEngine.isExistsUniMP(self.appId) {
      let version = DCUniMPSDKEngine.getUniMPVersionInfo(withAppid: self.appId)!
      let name = version["code"]!
      let code = version["code"]!
      print("小程序：\(self.appId) 资源已存在，版本信息：name:\(name) code:\(code)")
      return true
    } else {
      do {
        try DCUniMPSDKEngine.installUniMPResource(
          withAppid: self.appId,
          resourceFilePath: wgtPath,
          password: nil
        )
        let version = DCUniMPSDKEngine.getUniMPVersionInfo(withAppid: self.appId)!
        let name = version["name"]!
        let code = version["code"]!
        print("✅ 小程序：\(self.appId) 资源释放成功，版本信息：name:\(name) code:\(code)")
        return true
      } catch let customErr as NSError {
        print("❌ 小程序：\(appId) 资源释放失败:\(customErr)")
        return false
      }
    }
  }
    
  // MARK: - 释放资源
    func installUniMPResource(wgtPath: String?, appid: String) {
        if (wgtPath != nil) {
//      DCUniMPSDKEngine.installUniMPResource(withAppid: appid, resourceFilePath: wgt, password: T##String?)
        }
    }
    
    
  // MARK: - 预加载小程序

  /// 预加载小程序
  func preloadUniMP(configuration: DCUniMPConfiguration = DCUniMPConfiguration.init()) {
      let weakSelf = self
      
      DCUniMPSDKEngine.preloadUniMP(self.appId, configuration: configuration) { instance, error in
          if instance != nil {
            print("预加载小程序完成")
            weakSelf.currentUniMP = instance
          } else {
            print(error as Any)
          }
      }
  }
    
    

  // MARK: - 打开uni小程序

  /// 打开uni小程序
    @IBAction public func openUniMP(
        configuration: DCUniMPConfiguration = DCUniMPConfiguration.init()
    ) {
//    let configuration = DCUniMPConfiguration()
        // 是否后台启动
        configuration.enableBackground = true
        configuration.enableGestureClose = false

        let weakSelf = self

        // 打开小程序
        DCUniMPSDKEngine.openUniMP(self.appId, configuration: configuration) { instance, error in
          if instance != nil {
            print("小程序打开成功")
            weakSelf.currentUniMP = instance
          } else {
            print(error as Any)
          }
        }
   }
    
 

  // MARK: - 监听关闭按钮点击

  /// 监听关闭按钮点击
  // func closeButtonClicked(appid: String) {
  //    print("======== 小程序：\(appid) 关闭 ========")
  // }

  // MARK: - DCUniMPSDKEngineDelegate 监听小程序关闭实现

  public func uniMP(onClose appid: String) {
    print("======== 小程序：\(appid) 关闭 ========")
    self.currentUniMP = nil
  }

  // MARK: - DCUniMPSDKEngineDelegate 小图标菜单点击触发回调
  
  ///
  public func defaultMenuItemClicked(_ appid: String, identifier: String) {
    print("======== defaultMenuItemClicked：\(appid) \(identifier) ========")
    if identifier == "closeUniMP" {
      self.currentUniMP?.close(completion: { success, error in
        if success {
          print("======== defaultMenuItemClicked：\(appid) \(identifier) success ========")
        } else {
          print("======== defaultMenuItemClicked：\(appid) \(identifier) \(error.debugDescription) error ========")
        }
      })
    }
  }

  // MARK: - 返回打开小程序时的自定义闪屏视图(用于自定义启动页)

  public func splashView(forApp appid: String) -> UIView {
      // 获取当前小程序页面
//      self.currentUniMP
    let splashView:UIView = Bundle.main.loadNibNamed(
        "SplashView",
        owner: self,
        options: nil
    )?.last as! UIView
    return splashView
  }
    
}
