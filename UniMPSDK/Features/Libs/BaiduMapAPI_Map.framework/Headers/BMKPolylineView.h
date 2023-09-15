/*
 *  BMKPolylineView.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import "BMKGeometryView.h"
#import "BMKPolyline.h"

NS_ASSUME_NONNULL_BEGIN
/// 此类用于定义一个折线View
@interface BMKPolylineView : BMKGeometryView

/// 根据指定的折线生成一个折线View
/// @param polyline 指定的折线数据对象
/// @return 新生成的折线View
- (nullable instancetype)initWithPolyline:(BMKPolyline *)polyline;

/// 该View对应的折线数据对象
@property (nonatomic, readonly) BMKPolyline *polyline;

/// LineJoinType,默认是kBMKLineJoinBevel（不支持虚线）
@property (assign, nonatomic) BMKLineJoinType lineJoinType;

/// LineCapType,默认是kBMKLineCapButt (不支持虚线)
@property (assign, nonatomic) BMKLineCapType lineCapType;


#pragma mark - 以下方法和属性只适用于分段纹理绘制/分段颜色绘制

/// 是否分段纹理/分段颜色绘制（突出显示），默认YES，YES:使用分段纹理绘制 NO:使用默认的灰色纹理绘制
@property (nonatomic, assign) BOOL isFocus __deprecated_msg("已废弃since 5.0.0");

/// 使用分段颜色绘制时，必须设置（内容必须为UIColor）
/// 注：请使用 - (UIColor *)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha; 初始化UIColor。
/// 使用[UIColor ***Color]初始化时，个别case转换成RGB后会有问题
@property (nonatomic, copy, nullable) NSArray<UIColor *> *colors __deprecated_msg("已废弃since 6.5.0, 请使用BMKMultiColorPolylineView中strokeColors");

@end
NS_ASSUME_NONNULL_END
