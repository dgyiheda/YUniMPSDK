//
//  BMKGeometryView.h
//  MapComponent
//
//  Created by zhangbaojin on 2021/7/28.
//  Copyright © 2021 Baidu. All rights reserved.
//

#import "BMKOverlayGLBasicView.h"

NS_ASSUME_NONNULL_BEGIN
/// 该类定义了一个用opengl绘制geometry的基类
@interface BMKGeometryView : BMKOverlayGLBasicView

/// 填充颜色
/// 注：请使用 - (UIColor *)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha; 初始化UIColor。
/// 使用[UIColor ***Color]初始化时，个别case转换成RGB后会有问题
@property (nonatomic, strong, nullable) UIColor *fillColor;

/// 画笔颜色
/// 注：请使用 - (UIColor *)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha; 初始化UIColor。
/// 使用[UIColor ***Color]初始化时，个别case转换成RGB后会有问题
@property (nonatomic, strong, nullable) UIColor *strokeColor;

/// 画笔宽度，默认为0
@property (nonatomic, assign) CGFloat lineWidth;

/// 虚线类型, since 5.0.0，默认kBMKLineDashTypeNone (仅支持颜色虚线)
@property (nonatomic, assign) BMKLineDashType lineDashType;

@end
NS_ASSUME_NONNULL_END
