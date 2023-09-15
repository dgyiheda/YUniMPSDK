//
//  BMKGeodesicLine.h
//  MapComponent
//
//  Created by zhangbaojin on 2021/3/22.
//  Copyright © 2021 Baidu. All rights reserved.
//

#import "BMKPolyline.h"

NS_ASSUME_NONNULL_BEGIN
/// 此类用于定义一段大地曲线 since 6.3.0
@interface BMKGeodesicLine : BMKPolyline

/// 根据指定坐标点生成大地曲线
/// @param points  指定的直角坐标点数组
/// @param count 点的个数
/// @return 生成的大地曲线
+ (nullable instancetype)geodesicLineWithPoints:(BMKMapPoint *)points
                                          count:(NSUInteger)count NS_SWIFT_NAME(geodesic(points:count:));

/// 根据经纬度生成大地曲线
/// @param coords 经纬度
/// @param count 点的个数
/// @return 生成的大地曲线
+ (nullable instancetype)geodesicLineWithCoordinates:(CLLocationCoordinate2D *)coords
                                               count:(NSUInteger)count NS_SWIFT_NAME(geodesic(coordinates:count:));

/// 重新设置坐标点.
/// @param points  指定的直角坐标点数组，C数组，内部会做copy，调用者负责内存管理。
/// @param count 坐标点的个数
/// @return 是否设置成功
- (BOOL)setGeodesicLineWithPoints:(BMKMapPoint *)points count:(NSUInteger)count;

/// 重新设置坐标点.
/// @param coords  指定的经纬度数组，C数组，内部会做copy，调用者负责内存管理。
/// @param count 坐标点的个数
/// @return 是否设置成功
- (BOOL)setGeodesicLineWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count;

@end

NS_ASSUME_NONNULL_END
