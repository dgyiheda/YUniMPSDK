//
//  BMKMultiPolyline.h
//  MapComponent
//
//  Created by zhangbaojin on 2021/7/28.
//  Copyright © 2021 Baidu. All rights reserved.
//

#import "BMKPolyline.h"

NS_ASSUME_NONNULL_BEGIN

/// 此文件定义分段折线 since 6.5.0
@interface BMKMultiPolyline : BMKPolyline

/// 颜色/纹理索引数组
@property (nonatomic, copy) NSArray<NSNumber *> *drawIndexs;

/// 根据指定直角坐标点生成一段折线
/// 分段纹理绘制/分段颜色绘制，根据指定坐标点生成一段折线
/// 分段纹理绘制：其对应的BMKMultiTexturePolylineView必须使用 textureImages 加载纹理图片；
/// 分段颜色绘制：其对应的BMKMultiColorPolylineView必须设置strokeColors属性
/// @param points  指定的直角坐标点数组
/// @param count  points数组中坐标点的个数
/// @param drawIndexs  纹理索引数组（颜色索引数组），成员为NSNumber,且为非负数，负数按0处理
/// @return 新生成的折线对象
+ (nullable instancetype)multiPolylineWithPoints:(BMKMapPoint *)points
                                           count:(NSUInteger)count
                                      drawIndexs:(NSArray<NSNumber *> *)drawIndexs;

/// 根据指定经纬度坐标点生成一段折线
/// 分段纹理绘制：其对应的BMKMultiTexturePolylineView必须使用 textureImages 加载纹理图片；
/// 分段颜色绘制：其对应的BMKMultiColorPolylineView必须设置strokeColors属性
/// @param coords 指定的经纬度坐标点数组
/// @param count  coords数组中坐标点的个数
/// @param drawIndexs 纹理索引数组（颜色索引数组），成员为NSNumber,且为非负数，负数按0处理
/// @return 新生成的折线对象
+ (nullable instancetype)multiPolylineWithCoordinates:(CLLocationCoordinate2D *)coords
                                                count:(NSUInteger)count
                                           drawIndexs:(NSArray<NSNumber *> *)drawIndexs;

/// 重新设置折线坐标点 和 纹理索引
/// @param points 指定的直角坐标点数组
/// @param count points数组中坐标点的个数
/// @param drawIndexs 纹理索引数组（颜色索引数组），成员为NSNumber,且为非负数，负数按0处理
/// @return 是否设置成功
- (BOOL)setMultiPolylineWithPoints:(BMKMapPoint *)points
                             count:(NSUInteger)count
                        drawIndexs:(NSArray<NSNumber *> *)drawIndexs;

/// 重新设置折线经纬度 和 纹理索引
/// @param coords 指定的经纬度坐标点数组
/// @param count coords数组中坐标点的个数
/// @param drawIndexs  纹理索引数组（颜色索引数组），成员为NSNumber,且为非负数，负数按0处理
/// @return 是否设置成功
- (BOOL)setMultiPolylineWithCoordinates:(CLLocationCoordinate2D *)coords
                                  count:(NSUInteger)count
                             drawIndexs:(NSArray<NSNumber *> *)drawIndexs;

@end

NS_ASSUME_NONNULL_END
