//
//  BMKBaseLog.h
//  BaseComponent
//
//  Created by zhaoxiangru on 2020/12/30.
//  Copyright © 2020 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BMKTypes.h"
NS_ASSUME_NONNULL_BEGIN

@interface BMKBaseLog : NSObject
/// 获取某个模块日志是否打开
+ (BOOL)getlogEnableWithModule:(BMKMapModule)mapModule;
/// 获取某个模块的日志文件目录
+ (NSString *)getLogFilePathWithModule:(BMKMapModule)mapModule;
/// 设置某个模块日志是否打开
+ (void)setlogEnable:(BOOL)enable module:(BMKMapModule)mapModule;
/// 设置某个模块的日志文件目录，默认放在沙盒Library/Caches/相关目录下
+ (void)setlogFilePath:(NSString *)logFilePath module:(BMKMapModule)mapModule;
@end

NS_ASSUME_NONNULL_END
