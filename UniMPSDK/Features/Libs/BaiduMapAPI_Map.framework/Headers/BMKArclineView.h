/*
 *  BMKArclineView.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import "BMKGeometryView.h"
#import "BMKArcline.h"

NS_ASSUME_NONNULL_BEGIN
/// 此类用于定义一个圆弧View
@interface BMKArclineView : BMKGeometryView

/// 根据指定的弧线生成一个圆弧View
/// @param arcline 指定的弧线数据对象
/// @return 新生成的弧线View
- (nullable instancetype)initWithArcline:(BMKArcline *)arcline;

/// 该View对应的圆弧数据对象
@property (nonatomic, readonly) BMKArcline *arcline;

@end
NS_ASSUME_NONNULL_END
