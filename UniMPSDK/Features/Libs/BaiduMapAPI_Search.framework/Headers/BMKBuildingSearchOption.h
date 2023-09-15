//
//  BMKBuildingSearchOption.h
//  BaiduMapAPI_Search
//
//  Created by zhangbaojin on 2021/4/19.
//  Copyright © 2021 Baidu. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/// 建筑物请求信息类
@interface BMKBuildingSearchOption : NSObject

/// 待解析的经纬度坐标（必选）
@property (nonatomic, assign) CLLocationCoordinate2D location;


@end

NS_ASSUME_NONNULL_END
