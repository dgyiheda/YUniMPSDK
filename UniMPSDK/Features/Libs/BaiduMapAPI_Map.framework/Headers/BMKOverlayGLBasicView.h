/*
*  BMKOverlayGLBasicView.h
*  BMapKit
*
*  Copyright 2011 Baidu Inc. All rights reserved.
*
*/

#import "BMKOverlayView.h"

NS_ASSUME_NONNULL_BEGIN
/// 该类定义了一个用opengl绘制的OverlayView的基类，如果需要用gdi进行绘制请继承于BMKOverlayPathView类
@interface BMKOverlayGLBasicView : BMKOverlayView 

/// 纹理图片 since 6.5.0
/// opengl要求图片宽高必须是2的n次幂
@property (nonatomic, strong, nullable) UIImage *textureImage;

/// 纹理图片是否缩放，默认NO
@property (nonatomic, assign) BOOL keepScale;

/// path对象
@property (nullable) CGPathRef path __deprecated_msg("已废弃since 6.5.0");

/// 是否为虚线样式，默认NO
@property (nonatomic) BOOL lineDash __deprecated_msg("已废弃since 5.0.0, 请使用lineDashType绘制虚线");

/// 是否纹理图片平铺绘制，默认NO
@property (nonatomic, assign) BOOL tileTexture __deprecated_msg("已废弃since 5.0.0");


@end
NS_ASSUME_NONNULL_END
