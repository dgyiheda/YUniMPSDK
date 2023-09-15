/*
 *  BMKPolygonView.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import "BMKGeometryView.h"
#import "BMKPolygon.h"


NS_ASSUME_NONNULL_BEGIN
/// 此类用于定义一个多边形View
@interface BMKPolygonView : BMKGeometryView

/// 根据指定的多边形生成一个多边形View
/// @param polygon 指定的多边形数据对象
/// @return 新生成的多边形View
- (nullable instancetype)initWithPolygon:(BMKPolygon *)polygon;

/// 该View对应的多边形数据
@property (nonatomic, readonly) BMKPolygon *polygon;

@end
NS_ASSUME_NONNULL_END
