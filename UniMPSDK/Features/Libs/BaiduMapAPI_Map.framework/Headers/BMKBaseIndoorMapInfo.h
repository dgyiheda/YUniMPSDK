//
//  BMKBaseIndoorMapInfo.h
//  MapComponent
//
//  Created by wzy on 16/4/2.
//  Copyright © 2016年 baidu. All rights reserved.
//

#ifndef BMKBaseIndoorMapInfo_h
#define BMKBaseIndoorMapInfo_h

#import <Foundation/Foundation.h>

/// 此类表示室内图基础信息
@interface BMKBaseIndoorMapInfo : NSObject

/// 室内ID
@property (nonatomic, copy) NSString *strID;

/// 当前楼层
@property (nonatomic, copy) NSString *strFloor;

/// 所有楼层信息
@property (nonatomic, copy) NSArray<NSString *> *arrStrFloors;

@end

#endif /* BMKBaseIndoorMapInfo_h */
