//
//  BMKMultiColorPolylineView.h
//  MapComponent
//
//  Created by zhangbaojin on 2021/7/28.
//  Copyright © 2021 Baidu. All rights reserved.
//

#import "BMKPolylineView.h"
#import "BMKMultiPolyline.h"

NS_ASSUME_NONNULL_BEGIN

/// 此文件定义分段多颜色折线View since 6.5.0
@interface BMKMultiColorPolylineView : BMKPolylineView

/// 根据指定的折线生成一个分段多颜色折线View
/// @param multiPolyline 指定的折线数据对象
/// @return 新生成的折线View
- (nullable instancetype)initWithMultiPolyline:(BMKMultiPolyline *)multiPolyline;

/// 该View对应的折线数据对象
@property (nonatomic, readonly) BMKMultiPolyline *multiPolyline;

/// 使用分段颜色绘制时，必须设置（内容必须为UIColor）
/// 注：请使用 - (UIColor *)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha; 初始化UIColor。
/// 使用[UIColor ***Color]初始化时，个别case转换成RGB后会有问题
@property (nonatomic, copy) NSArray<UIColor *> *strokeColors;


@end

NS_ASSUME_NONNULL_END
