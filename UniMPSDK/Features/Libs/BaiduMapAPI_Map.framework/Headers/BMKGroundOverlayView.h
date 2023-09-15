/*
 *  BMKGroundOverlayView.h
 *  BMapKit
 *
 *  Copyright 2013 Baidu Inc. All rights reserved.
 *
 */

#import "BMKOverlayGLBasicView.h"
#import "BMKGroundOverlay.h"

NS_ASSUME_NONNULL_BEGIN
/// 该类用于定义一个BMKGroundOverlayView
@interface BMKGroundOverlayView : BMKOverlayGLBasicView

/// 根据指定的groundOverlay生成一个View
/// @param groundOverlay 指定的groundOverlay数据对象
/// @return 新生成的View
- (nullable instancetype)initWithGroundOverlay:(BMKGroundOverlay *)groundOverlay;

/// 该View对应的ground数据对象
@property (nonatomic, readonly) BMKGroundOverlay *groundOverlay;

@end
NS_ASSUME_NONNULL_END
