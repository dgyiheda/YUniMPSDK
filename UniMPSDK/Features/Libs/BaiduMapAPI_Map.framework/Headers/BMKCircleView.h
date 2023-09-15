/*
 *  BMKCircleView.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import "BMKGeometryView.h"
#import "BMKCircle.h"

NS_ASSUME_NONNULL_BEGIN
/// 该类用于定义圆对应的View
@interface BMKCircleView : BMKGeometryView

/// 根据指定圆生成对应的View
/// @param circle 指定的圆
/// @return 生成的View
- (nullable instancetype)initWithCircle:(BMKCircle *)circle;

/// 该View对应的圆
@property (nonatomic, readonly) BMKCircle *circle;

@end
NS_ASSUME_NONNULL_END
