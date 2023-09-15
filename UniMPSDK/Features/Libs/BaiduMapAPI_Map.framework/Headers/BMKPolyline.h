/*
 *  BMKPolyline.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import "BMKMultiPoint.h"
#import "BMKOverlay.h"
#import "BMKLineDrawType.h"

NS_ASSUME_NONNULL_BEGIN
/// 此类用于定义一段折线
@interface BMKPolyline : BMKMultiPoint <BMKOverlay>

/// 是否需要对Polyline坐标数据进行抽稀，默认为YES
/// since 5.3.0
@property (nonatomic, assign) BOOL isThined;

/// 折线经度跨180所需字段 since 6.3.0
/// 不跨180为kBMKLineDirectionCross180TypeNone，
/// 从东往西为kBMKLineDirectionCross180TypeEAST_TO_WEST
/// 从西往东为kBMKLineDirectionCross180TypeWEST_TO_EAST
/// 默认kBMKLineDirectionCross180TypeNone
@property (nonatomic, assign) BMKLineDirectionCross180Type lineDirectionCross180;

/// 根据指定坐标点生成一段折线
/// @param points  指定的直角坐标点数组
/// @param count  points数组中坐标点的个数
/// @return 新生成的折线对象
+ (nullable instancetype)polylineWithPoints:(BMKMapPoint *)points count:(NSUInteger)count;

/// 根据指定坐标点生成一段折线
/// @param coords 指定的经纬度坐标点数组
/// @param count coords数组中坐标点的个数
/// @return 新生成的折线对象
+ (nullable instancetype)polylineWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count;

/// 重新设置折线坐标点
/// @param points  指定的直角坐标点数组
/// @param count points数组中坐标点的个数
/// @return 是否设置成功
- (BOOL)setPolylineWithPoints:(BMKMapPoint *)points count:(NSUInteger)count;

/// 重新设置折线坐标点
/// @param coords 指定的经纬度坐标点数组
/// @param count coords数组中坐标点的个数
/// @return 是否设置成功
- (BOOL)setPolylineWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count;


#pragma mark - 以下方法和属性只适用于分段纹理绘制和分段颜色绘制

/**
 * 注意：since 6.5.0 绘制多颜色/多纹理折线请使用BMKMultiPolyline
 * 以下接口自6.5.0起不在维护
 */

/// 颜色/纹理索引数组
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *textureIndex __deprecated_msg("已废弃since 6.5.0, 请使用BMKMultiPolyline中drawIndexs");

/// 分段纹理绘制/分段颜色绘制，根据指定坐标点生成一段折线
/// 分段纹理绘制：其对应的BMKPolylineView必须使用 - (BOOL)loadStrokeTextureImages:(NSArray <UIImage *>*)textureImages; 加载纹理图片；否则使用默认的灰色纹理绘制
/// 分段颜色绘制：其对应的BMKPolylineView必须设置colors属性
/// @param points  指定的直角坐标点数组
/// @param count  points数组中坐标点的个数
/// @param textureIndex  纹理索引数组（颜色索引数组），成员为NSNumber,且为非负数，负数按0处理
/// @return 新生成的折线对象
+ (nullable instancetype)polylineWithPoints:(BMKMapPoint *)points
                                      count:(NSUInteger)count
                               textureIndex:(NSArray<NSNumber *> *)textureIndex __deprecated_msg("已废弃since 6.5.0, 请使用BMKMultiPolyline中multiPolylineWithPoints:count:drawIndexs:替换");

/// 根据指定坐标点生成一段折线
/// 分段纹理绘制：其对应的BMKPolylineView必须使用 - (BOOL)loadStrokeTextureImages:(NSArray <UIImage *>*)textureImages; 加载纹理图片；否则使用默认的灰色纹理绘制
/// 分段颜色绘制：其对应的BMKPolylineView必须设置colors属性
/// @param coords 指定的经纬度坐标点数组
/// @param count  coords数组中坐标点的个数
/// @param textureIndex 纹理索引数组（颜色索引数组），成员为NSNumber,且为非负数，负数按0处理
/// @return 新生成的折线对象
+ (nullable instancetype)polylineWithCoordinates:(CLLocationCoordinate2D *)coords
                                           count:(NSUInteger)count
                                    textureIndex:(NSArray<NSNumber *> *)textureIndex __deprecated_msg("已废弃since 6.5.0, 请使用BMKMultiPolyline中multiPolylineWithCoordinates:count:drawIndexs:替换");

/// 重新设置折线坐标点 和 纹理索引
/// @param points 指定的直角坐标点数组
/// @param count points数组中坐标点的个数
/// @param textureIndex 纹理索引数组（颜色索引数组），成员为NSNumber,且为非负数，负数按0处理
/// @return 是否设置成功
- (BOOL)setPolylineWithPoints:(BMKMapPoint *)points
                        count:(NSUInteger)count
                 textureIndex:(NSArray<NSNumber *> *)textureIndex __deprecated_msg("已废弃since 6.5.0, 请使用BMKMultiPolyline中setMultiPolylineWithPoints:count:drawIndexs:替换");

/// 重新设置折线坐标点
/// @param coords 指定的经纬度坐标点数组
/// @param count coords数组中坐标点的个数
/// @param textureIndex  纹理索引数组（颜色索引数组），成员为NSNumber,且为非负数，负数按0处理
/// @return 是否设置成功
- (BOOL)setPolylineWithCoordinates:(CLLocationCoordinate2D *)coords
                             count:(NSUInteger)count
                      textureIndex:(NSArray<NSNumber *> *)textureIndex __deprecated_msg("已废弃since 6.5.0, 请使用BMKMultiPolyline中setMultiPolylineWithCoordinates:count:drawIndexs:替换");

@end
NS_ASSUME_NONNULL_END
