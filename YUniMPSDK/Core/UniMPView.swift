//
//  UniMPView.swift
//  YhdSuperApp
//
//  Copyright © 2023 Dongguan Yiheda Automation Co., Ltd.
//
//

import SwiftUI
// https://blog.csdn.net/daiyucheng88/article/details/105965269/

// MARK: - 小程序UIKit组件

@available(iOS 13.0, *)
public struct UniMPView: UIViewControllerRepresentable {
  /// 类型别名
  public typealias UIViewControllerType = UniMPViewController

  /// appId
  public var appId: String

  /// 初始化回调
  public var result: (Coordinator?) -> Void

  /// 初始化器
  public init(appId: String, result: @escaping (UniMPViewController?) -> Void) {
    self.appId = appId
    self.result = result
  }

  /// 当前SDK引擎(桥接UiViewController)
  //  var coordinator: Coordinator?

  ///  创建协调类（桥接）
  public func makeCoordinator() -> UniMPViewController {
    UniMPViewController()
  }

  ///  创建UIViewController视图
  public func makeUIViewController(context _: Context) -> UIViewControllerType {
    // 初始化UIViewController
    let uniMPViewController = UniMPViewController()
    // 设置小程序AppId
    uniMPViewController.appId = self.appId
    // 初始化完成的回调
    self.result(uniMPViewController)

    return uniMPViewController
  }

  /// 更新UI View Controller 视图
  public func updateUIViewController(_: UIViewControllerType, context _: Context) {}
}

// @available(iOS 14.0, *)
// struct UniMPView_Previews: PreviewProvider {
//    static var previews: some View {
//        //        UniMPView(appId: "__UNI__11E9B73", coordinator: Binding<UniMPViewController?>)
//        IndexView()
//        IndexView().preferredColorScheme(.dark)
//    }
// }
