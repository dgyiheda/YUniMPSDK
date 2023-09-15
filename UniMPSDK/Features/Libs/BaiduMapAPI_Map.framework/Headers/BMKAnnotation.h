//
//  BMKAnnotation.h
//  BMapKit
//
//  Copyright 2011 Baidu Inc. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

/// 该类为标注点的protocol，提供了标注类的基本信息函数
@protocol BMKAnnotation <NSObject, NSCopying>

/// 标注view中心坐标.
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

@optional

/// 获取annotation标题
- (NSString *)title;

/// 获取annotation副标题
- (NSString *)subtitle;

/// 设置标注的坐标，在拖拽时会被调用.
/// @param newCoordinate 新的坐标值
- (void)setCoordinate:(CLLocationCoordinate2D)newCoordinate;

@end
