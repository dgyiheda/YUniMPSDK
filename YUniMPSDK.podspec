#
#  Be sure to run `pod spec lint YUniMPSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name             = 'YUniMPSDK'
  s.version          = '3.96'
  s.summary          = 'uniapp 原生小程序SDK'
  s.homepage         = 'https://github.com/dgyiheda/YUniMPSDK'
  s.license = 'MIT'
  s.author           = { 'tanhao' => '1779084072@qq.com' }
  s.source           = { :git => 'https://github.com/dgyiheda/YUniMPSDK.git', :tag => "#{s.version}" }
  # s.source = {:http => 'http://127.0.0.1:5500/YUniMPSDK_8.zip'}
  s.swift_versions = '5.7'
  # s.social_media_url = 'https://twitter.com/artsyopensource'
  s.ios.deployment_target = '11.0'
  s.module_name = 'YUniMPSDK'
  # pods工程配置项
  s.pod_target_xcconfig = {
     'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
  }
  # 主工程配置项
  s.user_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
  }
  s.requires_arc = false
  # 编译标志
  # s.compiler_flags = "-Wall -Werror -Wextra"
  # 默认模块
  s.default_subspecs = %w[Core Barcode NativeJs Audio Camera Contacts Video Zip]
  # s.static_framework = false

  # 划分子模块
  # UniMPSDK Basic 基础库
  s.subspec 'Basic' do |bs|
    bs.ios.deployment_target = '11.0'
    bs.public_header_files = ['UniMPSDK/Core/Headers/**/*.h','UniMPSDK/Core/Headers/*.h']
    bs.source_files = ['UniMPSDK/Core/Headers/**/*.h','UniMPSDK/Core/Headers/**/*.h']
    # 依赖的系统库
    bs.libraries =  ['c++', 'iconv']
    # 非系统库
    bs.vendored_frameworks = [
      'UniMPSDK/Core/Libs/storage.framework',
    ]
    # 依赖的非系统的静态库
    bs.vendored_libraries = [
        'UniMPSDK/Core/Libs/libcoreSupport.a',
        'UniMPSDK/Core/Libs/liblibIO.a',
        'UniMPSDK/Core/Libs/liblibNativeObj.a',
        'UniMPSDK/Core/Libs/liblibNativeUI.a',
        'UniMPSDK/Core/Libs/liblibNavigator.a',
        'UniMPSDK/Core/Libs/liblibPDRCore.a',
        'UniMPSDK/Core/Libs/liblibStorage.a',
        'UniMPSDK/Core/Libs/liblibUI.a',
        'UniMPSDK/Core/Libs/liblibWeex.a',
        'UniMPSDK/Core/Libs/libSDWebImage.a'
    ]
    bs.resources = [
        'UniMPSDK/Core/Resources/PandoraApi.bundle',
        'UniMPSDK/Core/Resources/__uniappes6.js',
        'UniMPSDK/Core/Resources/uni-jsframework-vue3.js',
        'UniMPSDK/Core/Resources/uni-jsframework.js',
        'UniMPSDK/Core/Resources/unincomponents.ttf',
        'UniMPSDK/Core/Resources/weex-polyfill.js',
        'UniMPSDK/Core/Resources/weexUniJs.js',
    ]
    # 系统framework
    bs.frameworks = [
        'JavaScriptCore',
        'CoreMedia',
        'MediaPlayer',
        'AVFoundation',
        'AVKit',
        'GLKit',
        'OpenGLES',
        'CoreText',
        'QuartzCore',
        'CoreGraphics',
        'QuickLook',
        'CoreTelephony',
        'Foundation',
        'WebKit',
        'SystemConfiguration',
        'MobileCoreServices'
    ]
  end

   # UniMPSDK Barcode 扫码库
  s.subspec 'Barcode' do |b|
    b.source_files = 'YUniMPSDK/Barcode/*.{swift}'
    b.vendored_libraries = [
        'UniMPSDK/Features/Libs/libDCUniBarcode.a',
        'UniMPSDK/Features/Libs/liblibBarcode.a',
        'UniMPSDK/Features/Libs/libDCUniZXing.a',
        'UniMPSDK/Features/Libs/libuchardet.a'
    ]
    b.frameworks = [
        'AVFoundation',
        'ImageIO',
        'CoreVideo',
        'CoreMedia',
    ]
    b.libraries = [
        'iconv.2'
    ]
  end
 
 
  # UniMPSDK native.js
  s.subspec 'NativeJs' do |n|
    n.source_files = 'YUniMPSDK/NativeJS/*.{swift}'
    n.vendored_libraries = ['UniMPSDK/Features/Libs/liblibPGInvocation.a']
  end
  
  # UniMPSDK iBeacon（轻蓝牙）
  s.subspec 'iBeacon' do |ib|
    ib.source_files = 'YUniMPSDK/IBeacon/*.{swift}'
    ib.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibBeacon.a'
    ]
    ib.frameworks = [
        'CoreBluetooth',
        'CoreLocation'
    ]
  end
  
  # UniMPSDK Accelerometer(加速度传感器)
  s.subspec 'Accelerometer' do |a|
    a.source_files = 'YUniMPSDK/Accelerometer/*.{swift}'
    a.vendored_libraries = ['UniMPSDK/Features/Libs/liblibAccelerometer.a']
    a.frameworks = ['Accelerate']
  end

  # UniMPSDK Audio(音频)
  s.subspec 'Audio' do |audio|
    audio.source_files = 'YUniMPSDK/Audio/*.{swift}'
    audio.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibMedia.a',
        'UniMPSDK/Features/Libs/libopencore-amrnb.a',
        'UniMPSDK/Features/Libs/libmp3lame.a'
    ]
    audio.frameworks = ['AVFoundation']
  end
  
  # UniMPSDK Camera(摄像头)/Gallery(图片选择)
  s.subspec 'Camera' do |c|
    c.source_files = 'YUniMPSDK/Camera/*.{swift}'
    c.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibCamera.a'
    ]
    c.frameworks = [
        'AssetsLibrary',
        'Photos',
        'CoreMedia',
        'MetalKit',
        'GLKit'
    ]
    c.resources = [
        'UniMPSDK/Features/Resources/DCTZImagePickerController.bundle',
        'UniMPSDK/Features/Resources/DCMediaEditingController.bundle'
    ]
  end
  
  # UniMPSDK Contacts(通讯录)
  s.subspec 'Contacts' do |co|
    co.source_files = 'YUniMPSDK/Contacts/*.{swift}'
    co.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibContacts.a'
    ]
    co.frameworks = [
        'AddressBookUI',
        'AddressBook',
        'AVFoundation',
        'CoreVideo',
        'CoreMedia'
    ]
  end
  
  # UniMPSDK BaiduSDK (百度定位/百度地图)
  s.subspec 'BaiduSDK' do |bd|
    bd.source_files = 'YUniMPSDK/BaiduSDK/*.{swift}'
    bd.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibGeolocation.a',
        'UniMPSDK/Features/Libs/libBaiduLocationPlugin.a',
        'UniMPSDK/Features/Libs/libBaiduKeyVerify.a',
        'UniMPSDK/Features/Libs/liblibMap.a',
        'UniMPSDK/Features/Libs/libbmapimp.a',
        'UniMPSDK/Features/Libs/libssl.a',
        'UniMPSDK/Features/Libs/libcrypto.a'
    ]
    bd.vendored_frameworks = [
        'UniMPSDK/Features/Libs/BaiduMapAPI_Utils.framework',
        'UniMPSDK/Features/Libs/BaiduMapAPI_Base.framework',
        'UniMPSDK/Features/Libs/BaiduMapAPI_Search.framework',
        'UniMPSDK/Features/Libs/BaiduMapAPI_Map.framework',
        'UniMPSDK/Features/Libs/BMKLocationKit.framework'
    ]
    bd.frameworks = [
        'SystemConfiguration',
        'Security',
        'CoreLocation',
        'MapKit',
        'QuartzCore',
        'OpenGLES',
        'CoreGraphics',
        'CoreTelephony'
    ]
    # 依赖的系统库
    bd.libraries = [
        'c++',
        'sqlite3.0'
    ]
    # 资源
    bd.resources = [
        'UniMPSDK/Features/Resources/mapapi.bundle'
    ]
  end
  
  # UniMPSDK Messaging(短彩邮件消息)
  s.subspec 'Messaging' do |m|
    m.source_files = 'YUniMPSDK/Messaging/*.{swift}'
    m.vendored_libraries = ['UniMPSDK/Features/Libs/liblibMessage.a']
    m.frameworks = [
        'MessageUI'
    ]
  end

  # UniMPSDK Orientation(设备方向)
  s.subspec 'Orientation' do |ori|
    ori.source_files = 'YUniMPSDK/Orientation/*.{swift}'
    ori.vendored_libraries = ['UniMPSDK/Features/Libs/liblibOrientation.a']
    ori.frameworks = [
        'CoreLocation'
    ]
  end
  
  # UniMPSDK Proximity(距离传感器)
  s.subspec 'Proximity' do |pr|
    pr.source_files = 'YUniMPSDK/Proximity/*.{swift}'
    pr.vendored_libraries = ['UniMPSDK/Features/Libs/liblibPGProximity.a']
  end
  
  # UniMPSDK XMLHttpRequest(网络请求)
  s.subspec 'XMLHttpRequest' do |x|
    x.source_files = 'YUniMPSDK/XMLHttpRequest/*.{swift}'
    x.vendored_libraries = ['UniMPSDK/Features/Libs/liblibXHR.a']
  end
  
  # UniMPSDK zip(解压缩)
  s.subspec 'Zip' do |z|
    z.source_files = 'YUniMPSDK/Zip/*.{swift}'
    z.vendored_libraries = ['UniMPSDK/Features/Libs/liblibZip.a']
  end
  
  # UniMPSDK WeChatSDK(微信分享、微信支付、微信登录)
  s.subspec 'WeChatSDK' do |wx|
    wx.source_files = 'YUniMPSDK/WeChatSDK/*.{swift}'
    wx.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibShare.a',
        'UniMPSDK/Features/Libs/libweixinShare.a',
        'UniMPSDK/Features/Libs/libWeChatSDK_pay.a',
        'UniMPSDK/Features/Libs/liblibPayment.a',
        'UniMPSDK/Features/Libs/libwxpay.a',
        'UniMPSDK/Features/Libs/liblibOauth.a',
        'UniMPSDK/Features/Libs/libWXOauth.a'
    ]
    wx.libraries = [
        'sqlite3.0',
        'z'
    ]
    wx.frameworks = [
        'CoreTelephony',
        'SystemConfiguration'
    ]
  end
  
  # UniMPSDK AlipaySDK(支付宝支付)
  s.subspec 'AlipaySDK' do |al|
    al.source_files = 'YUniMPSDK/AlipaySDK/*.{swift}'
    al.vendored_frameworks = [
        'UniMPSDK/Features/Libs/AlipaySDK.framework'
    ]
    al.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibPayment.a',
        'UniMPSDK/Features/Libs/libalixpayment.a'
    ]
    al.libraries = [
        'c++',
        'z'
    ]
    al.frameworks = [
        'CFNetwork',
        'SystemConfiguration',
        'CoreMotion',
        'Security',
        'WebKit'
    ]
    al.resources = [
        'UniMPSDK/Features/Resources/AlipaySDK.bundle'
    ]
  end
  
  # UniMPSDK TencentQQSDK(QQ分享、QQ登录)
  s.subspec 'TencentQQSDK' do |tx|
    tx.source_files = 'YUniMPSDK/TencentQQSDK/*.{swift}'
    tx.vendored_frameworks = [
        'UniMPSDK/Features/Libs/TencentOpenAPI.framework'
    ]
    tx.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibShare.a',
        'UniMPSDK/Features/Libs/libQQShare.a',
        'UniMPSDK/Features/Libs/liblibOauth.a',
        'UniMPSDK/Features/Libs/libQQOauth.a'
    ]
    # s.resources = [
    #     'UniMPSDK/Features/Resources/TencentOpenApi_IOS_Bundle.bundle'
    # ]
  end
  
  # UniMPSDK WeiBoSDK(微博分享、微博登录)
  s.subspec 'WeiBoSDK' do |wb|
    wb.source_files = 'YUniMPSDK/WeiBoSDK/*.{swift}'
    wb.vendored_libraries = [
        'UniMPSDK/Features/Libs/libWeiboSDK.a',
        'UniMPSDK/Features/Libs/liblibShare.a',
        'UniMPSDK/Features/Libs/libSinaShare.a',
        'UniMPSDK/Features/Libs/liblibOauth.a',
        'UniMPSDK/Features/Libs/libSinaWBOauth.a'
    ]
    wb.libraries = [
        'sqlite3.0'
    ]
    wb.frameworks = [
        'ImageIO'
    ]
    wb.resources = [
        'UniMPSDK/Features/Resources/WeiboSDK.bundle'
    ]
  end
  
  # UniMPSDK Video（视频播放）
  s.subspec 'Video' do |v|
    v.source_files = 'YUniMPSDK/Video/*.{swift}'
    v.vendored_frameworks = [
        'UniMPSDK/Features/Libs/IJKMediaFrameworkWithSSL.framework',
        'UniMPSDK/Features/Libs/DCUniVideoPublic.framework',
        'UniMPSDK/Features/Libs/Masonry.framework'
    ]
    v.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibVideo.a',
        'UniMPSDK/Features/Libs/libDCUniVideo.a'
    ]
    v.libraries = [
        'c++',
        'bz2',
        'z'
    ]
    v.frameworks = [
        'AudioToolbox',
        'AVFoundation',
        'CoreGraphics',
        'CoreMedia',
        'CoreVideo',
        'VideoToolbox',
        'MediaPlayer',
        'MobileCoreServices',
        'OpenGLES',
        'QuartzCore',
        'UIKit'
    ]
    v.resources = [
        'UniMPSDK/Features/Resources/DCSVProgressHUD.bundle',
        'UniMPSDK/Features/Resources/DCPGVideo.bundle'
    ]
  end
  
  # UniMPSDK Fingerprint(指纹识别)
  s.subspec 'Fingerprint' do |fi|
    fi.source_files = 'YUniMPSDK/Fingerprint/*.{swift}'
    fi.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibFingerprint.a'
    ]
    fi.frameworks = [
        'LocalAuthentication'
    ]
  end
  
  # UniMPSDK faceId（人脸识别）
  s.subspec 'FaceId' do |f|
    f.source_files = 'YUniMPSDK/FaceId/*.{swift}'
    f.vendored_libraries = [
        'UniMPSDK/Features/Libs/libDCUniFaceId.a'
    ]
    f.frameworks = [
        'LocalAuthentication'
    ]
  end
  
  # UniMPSDK BlueTooth(蓝牙)
  s.subspec 'BlueTooth' do |bt|
    bt.source_files = 'YUniMPSDK/BlueTooth/*.{swift}'
    bt.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibBlueTooth.a'
    ]
    bt.frameworks = [
        'CoreBluetooth'
    ]
  end
  
  # UniMPSDK sqlite（数据库）
  s.subspec 'Sqlite' do |sql|
    sql.source_files = 'YUniMPSDK/Sqlite/*.{swift}'
    sql.vendored_libraries = [
        'UniMPSDK/Features/Libs/liblibSqlite.a'
    ]
    sql.libraries = [
        'sqlite3.0'
    ]
  end

  # UniMPSDK Core（核心组件代码）
  s.subspec 'Core' do |c|
    c.ios.dependency 'YUniMPSDK/Basic'
    c.source_files = ['YUniMPSDK/Core/*.{swift,h}']
  end
  
end
