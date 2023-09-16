# YUniMPSDK（怡合达Uni原生小程序SDK）

- Y：怡合达
- UniMPSDK：uniapp原生小程序SDK

<p align="center" >
  <img src="https://yhd-fe-monitor.oss-cn-shenzhen.aliyuncs.com/static/images/code.png" title="logo" float=left>
</p>

[![UniMP](https://img.shields.io/badge/UniMPSDK-3.8.12-forestgreen?style=flat-square)](https://nativesupport.dcloud.net.cn/README)
[![Swift](https://img.shields.io/badge/Swift-5.8-orange?style=flat-square)](https://img.shields.io/badge/Swift-5.8-Orange?style=flat-square)
[![Platforms](https://img.shields.io/badge/Platforms-iOS11+-yellowgreen?style=flat-square)](https://img.shields.io/badge/Platforms-iOS11+-Green?style=flat-square)
[![CocoaPods tips](https://img.shields.io/badge/CocoaPods-Tips-4BC51D.svg?style=flat)](https://cocoapods.org/)
<!-- [![Carthage Compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat-square)](https://github.com/Carthage/Carthage) -->
<!-- [![Swift Package Manager](https://img.shields.io/badge/Swift_Package_Manager-compatible-orange?style=flat-square)](https://img.shields.io/badge/Swift_Package_Manager-compatible-orange?style=flat-square) -->

## 简介

uni小程序SDK，是为原生App打造的可运行基于 uni-app 开发的小程序前端项目的框架，从而帮助原生App快速获取小程序的能力，效果如下：

<img src="https://ask.dcloud.net.cn/uploads/article/20200208/17968bd5afe1e15f1b0b4965a194726f.gif" width=230>

### 为什么Uni官方提供了SDK还是要剥离出依赖？

A：虽然UNI官方提供了SDK，但并未提供SPM、cocoapods、Carthage依赖包，而UniMP SDK更新又比较频繁需要维护支持的内容较多，并且目前无法确定后期会不会有多个APP需要使用UniMPSDK。考虑到SDK统一管理、扩展及维护性决定剥离依赖。

## 功能

<!-- &#x2705; ✅ -->
<!-- &#x274E; ❎ -->

- [x] UniMP原生小程序容器基础包
- [x] UniMP原生小程序 Accelerometer(加速度传感器)
- [x] UniMP原生小程序 Audio(音频)
- [x] UniMP原生小程序 Camera(摄像头)/Gallery(图片选择)
- [x] UniMP原生小程序 Contacts(通讯录)    
- [x] UniMP原生小程序 File(文件系统)    
- [x] UniMP原生小程序 Geolocation定位(百度)
- [x] UniMP原生小程序 native.js 
- [x] UniMP原生小程序 Messaging(短彩邮件消息)
- [x] UniMP原生小程序 Orientation(设备方向)    
- [x] UniMP原生小程序 Proximity(距离传感器)    
- [x] UniMP原生小程序 XMLHttpRequest(网络请求)    
- [x] UniMP原生小程序 zip(解压缩)  
- [x] UniMP原生小程序 fingerprint(指纹识别)    
- [x] UniMP原生小程序 faceId（人脸识别）      
- [x] UniMP原生小程序 BlueTooth(蓝牙)          
- [x] UniMP原生小程序 sqlite（数据库）            
- [x] UniMP原生小程序 iBeacon（低功耗蓝牙）            
- [x] UniMP原生小程序扫描二维码、一维码
- [x] UniMP原生小程序支付（微信、支付宝）
- [x] UniMP原生小程序登陆鉴权（微信登陆、QQ登陆、新浪微博登陆）
- [x] UniMP原生小程序外部分享（微信分享、QQ分享、新浪微博分享）
- [x] UniMP原生小程序地图（百度）
- [x] UniMP原生小程序Video（视频播放）
- [ ] UniMP原生小程序语音输入（百度）
- [ ] UniMP原生小程序友盟统计
- [ ] UniMP原生小程序直播推流（又拍云）


## 安装

在项目中使用YUniMP有三种方法:
- 使用 CocoaPods
- 使用 Carthage (暂不支持)
- 使用 Swift Package Manager (暂不支持)

注意：因UniMP官方SDK使用资源文件未进行处理 Carthage、Swift Package Manager 暂不支持，但仍然存在临时方案：如强制使用 Carthage、Swift Package Manager 需将拉下来的包里的静态资源文件手动复制到工程中！

### 使用CocoaPods安装（推荐！！！）

[CocoaPods](http://cocoapods.org/) 是Objective-C的依赖管理器，它自动化并简化了在项目中使用第三方库的过程。 请参阅 [Get Started](http://cocoapods.org/#get_started) 有关更多详细信息的部分。

#### Podfile
<!-- # 指定私有源 -->
<!-- source 'http://10.11.0.55/yhd-app-project/utilities/ios-librarys/YSpecs.git' -->
```
# target 中加入依赖
target 'TestApp' do 
  platform :ios, '13.0'
  # 默认依赖：Core(uniMP基础库)、Audio(音频)、Accelerometer（加速传感器）、Camera(摄像头、Gallery(图片选择))、Contacts(通讯录)、NativeJs、Video（视频播放）、Zip(解压缩) 、Barcode (扫码)
  pod 'YUniMPSDK', '~> 3.8.12'
  # Basic 基础库
  # pod 'YUniMPSDK/Core', '~> 3.8.12'
  # 百度SDK（包含百度地图、百度定位）
  # pod 'YUniMPSDK/BaiduSDK', '~> 3.8.12'
  # WeChatSDK 微信SDK（包含微信分享、微信登录鉴权、微信支付）
  # pod 'YUniMPSDK/WeChatSDK', '~> 3.8.12'
  # AlipaySDK 支付宝支付SDK（仅支付宝支付）
  # pod 'YUniMPSDK/AlipaySDK', '~> 3.8.12'
  # WeiBoSDK 微博SDK（含微博分享、微博登录）
  # pod 'YUniMPSDK/WeiBoSDK', '~> 3.8.12'
  # TencentQQSDK 腾讯QQSDK（含QQ分享、QQ登录）
  # pod 'YUniMPSDK/TencentQQSDK', '~> 3.8.12'
  # Camera(摄像头、Gallery(图片选择))
  # pod 'YUniMPSDK/Camera', '~> 3.8.12'
  # Barcode (扫码)
  # pod 'YUniMPSDK/Barcode', '~> 3.8.12'
  # Audio(音频)
  # pod 'YUniMPSDK/Audio', '~> 3.8.12'
  # Accelerometer(加速度传感器)
  # pod 'YUniMPSDK/Accelerometer', '~> 3.8.12'
  # Contacts(通讯录)
  # pod 'YUniMPSDK/Contacts', '~> 3.8.12'
  # NativeJs 
  # pod 'YUniMPSDK/NativeJs', '~> 3.8.12'
  # Messaging(短彩邮件消息)
  # pod 'YUniMPSDK/Messaging', '~> 3.8.12'
  # Orientation(设备方向)
  # pod 'YUniMPSDK/Orientation', '~> 3.8.12'
  # Proximity(距离传感器)
  # pod 'YUniMPSDK/Proximity', '~> 3.8.12'
  # XMLHttpRequest(网络请求)
  # pod 'YUniMPSDK/XMLHttpRequest', '~> 3.8.12'
  # Zip(解压缩)
  # pod 'YUniMPSDK/Zip', '~> 3.8.12'
  # Fingerprint(指纹识别)
  # pod 'YUniMPSDK/Fingerprint', '~> 3.8.12'
  # Video（视频播放）
  # pod 'YUniMPSDK/Video', '~> 3.8.12'
  # FaceId（人脸识别）
  # pod 'YUniMPSDK/FaceId', '~> 3.8.12'
  # BlueTooth(蓝牙)
  # pod 'YUniMPSDK/BlueTooth', '~> 3.8.12'
  # Sqlite（数据库）
  # pod 'YUniMPSDK/Sqlite', '~> 3.8.12'
  # iBeacon（轻蓝牙）
  # pod 'YUniMPSDK/iBeacon', '~> 3.8.12'
end
```

<!--##### Swift 和 static framework-->
<!---->
<!--Swift项目以前必须使用`use_frameworks!`将所有Pods变成动态框架，让CocoaPods工作。-->
<!---->
<!--然而，从`CocoaPods 1.5.0+`（带有`Xcode 9+`）开始，它支持将Objective-C和Swift代码构建到静态框架中。您可以使用模块化标头将YUniMPSDK用作静态框架，而无需`use_frameworks!`:-->
<!---->
<!--```-->
<!--platform :ios, '13.0'-->
<!--# 当您希望所有Pod作为静态框架时，取消注释下一行-->
<!--# use_modular_headers!-->
<!--pod 'YUniMP', :modular_headers => true-->
<!--```-->
<!---->
<!--查看更多 [CocoaPods 1.5.0 — Swift Static Libraries](http://blog.cocoapods.org/CocoaPods-1.5.0/)-->
<!---->
<!--否则，您仍然需要添加`use_frameworks!`将YUniMP作为动态框架：-->
<!---->
<!--```-->
<!--platform :ios, '13.0'-->
<!--use_frameworks!-->
<!--pod 'YUniMP'-->
<!--```-->

<!--#### Subspecs-->
<!---->
<!--There are 2 subspecs available now: `YUniMPSDK` and `YUniMPBarcode` (this means you can install only some of the SDWebImage modules. By default, you get just `YUniMPSDK`, so if you need `YUniMPBarcode`, you need to specify it). -->
<!---->
<!--Podfile example:-->
<!---->
<!--```-->
<!--pod 'YUniMP/YUniMPBarcode'-->
<!--```-->

<!--### 使用 Carthage 安装-->
<!---->
<!--[Carthage](https://github.com/Carthage/Carthage) 是Swift和Objective-C的轻量级依赖管理器。它利用了CocoaTouch模块，比CocoaPods侵入性更小。-->
<!---->
<!--要安装Carthage，请按照 [Carthage](https://github.com/Carthage/Carthage)-->
<!---->
<!--Carthage用户可以指向此存储库，并使用他们想要的任何生成的框架：YUniMP、YUniMPSDK.-->
<!---->
<!--在Cartfile文件中输入以下条目: `git "http://10.11.0.55/yhd-app-project/utilities/ios-librarys/yunimp.git"`-->
<!--然后运行`carthage update`-->
<!--如果这是你第一次在项目中使用Carthage，需要按照文档完成一些额外的步骤 [over at Carthage](https://github.com/Carthage/Carthage#adding-frameworks-to-an-application).-->
<!---->
<!---->
<!--### 使用 Swift Package Manager 安装 (Xcode 11+)-->
<!---->
<!--[Swift Package Manager](https://swift.org/package-manager/) (SwiftPM) 是管理Swift代码的分发以及C家族依赖项的工具。从Xcode 11开始，SwiftPM与Xcode原生集成。-->
<!---->
<!--要使用SwiftPM，您应该使用Xcode 11+打开项目。 点击 `File` -> `Swift Packages` -> `Add Package Dependency`, 输入 [YUniMP repo's URL](http://10.11.0.55/yhd-app-project/utilities/ios-librarys/yunimp.git). 或者，您可以使用GitLib帐户登录Xcode，只需键入“YUniMP”即可进行搜索。-->
<!---->
<!--选择软件包后，您可以选择依赖类型（标记版本、分支或提交）然后Xcode将为您设置所有内容。-->
<!---->
<!--如果您是框架作者并使用YUniMP作为依赖项，请更新您的`Package.swift`文件:-->
<!---->
<!--```swift-->
<!--let package = Package(-->
<!--    // 1.0.0 ..< 2.0.0-->
<!--    dependencies: [-->
<!--        .package(url: "http://10.11.0.55/yhd-app-project/utilities/ios-librarys/yunimp.git", from: "1.0.0")-->
<!--    ],-->
<!--    // ...-->
<!--)-->
<!--```-->

## 入门

### 环境要求

<!-- - [Swift Package Manager >=5.7](https://github.com/apple/swift-package-manager) -->
- [Cocoapods >= 1.11.x](https://guides.cocoapods.org/using/getting-started.html)
- [XCode >= 14.x+](https://apps.apple.com/cn/app/xcode/id497799835)


### 开发文档

- [uniapp-uni小程序SDK-IOSAPI](https://nativesupport.dcloud.net.cn/UniMPDocs/API/ios.html)
- [uniapp-uni小程序SDK-IOS内置模块](https://nativesupport.dcloud.net.cn/UniMPDocs/UseModule/ios/ios.html#)
- [uniapp-uni小程序SDK-IOS扩展原生能力](https://nativesupport.dcloud.net.cn/UniMPDocs/Extension/ios.html)

<!--
### 更新UniMPSDK

1. [官网下载最新SDK](https://nativesupport.dcloud.net.cn/UniMPDocs/SDKDownload/ios.html)
2. 替换整个`UniMPSDK`目录
3. 更改 `UniMPSDK` 中相应资源 例如： `YUniMPSDK.podspec` 对应子模块中的 `s.resources` 资源列表、`s.vendored_frameworks/s.vendored_libraries` 动静态库
4. 更改`YUniMPSDK.podspec`中的版本号，提交代码,打版本TAG
5. 运行 `pod repo push YSpecs YUniMPSDK.podspec --allow-warnings --verbose` 发布最新包至`cocoapods`私有库,发布过程中时间较长请耐心等待！
6. 在项目中更改依赖版本，验证发布包是否正确
-->

<!--### framework 合并为xcframework-->
<!--```bash-->
<!--// 进入编译目录-->
<!--cd .build/Products-->
<!--// 编译xcframework-->
<!--xcodebuild -create-xcframework -framework Release-iphoneos/YUniMPSDK.framework -framework Release-iphonesimulator/YUniMPSDK.framework -output ../../Sources/Libs/YUniMPSDK.xcframework -->
<!--```-->

### 项目中使用

1. 使用 Cocoapods 引入小程序SDK依赖
2. 下载小程序wgt文件热更新包
3. 将.wgt文件导入项目资源或发布至远程依赖(OSS)
4. 使用Swift 组件 `UniMPView` 传入APPID（wgt文件名），初始化回调使用会返回一个UniMPViewController类，里面包含checkUniMPResources、openUniMP等方法
5. 使用UniMP内置功能请查看[uniapp官方文档](https://nativesupport.dcloud.net.cn/UniMPDocs/UseModule/ios/ios)
