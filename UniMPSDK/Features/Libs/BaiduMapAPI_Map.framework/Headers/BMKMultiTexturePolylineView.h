//
//  BMKMultiTexturePolylineView.h
//  MapComponent
//
//  Created by zhangbaojin on 2021/7/28.
//  Copyright © 2021 Baidu. All rights reserved.
//

#import "BMKPolylineView.h"
#import "BMKMultiPolyline.h"

NS_ASSUME_NONNULL_BEGIN

/// 此文件定义分段多纹理折线View since 6.5.0
@interface BMKMultiTexturePolylineView : BMKPolylineView

/// 根据指定的折线生成一个分段多纹理折线View
/// @param multiPolyline 指定的折线数据对象
/// @return 新生成的折线View
- (nullable instancetype)initWithMultiPolyline:(BMKMultiPolyline *)multiPolyline;

/// 该View对应的折线数据对象
@property (nonatomic, readonly) BMKMultiPolyline *multiPolyline;

/// 加载分段纹理绘制 所需的纹理图片 since 6.5.0
/// 必须UIImage数组，opengl要求图片宽高必须是2的n次幂
@property (nonatomic, copy) NSArray<UIImage *> *textureImages;

@end

NS_ASSUME_NONNULL_END
