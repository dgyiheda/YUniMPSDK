//
//  BMKBuildingSearchResult.h
//  BaiduMapAPI_Search
//
//  Created by zhangbaojin on 2021/4/19.
//  Copyright © 2021 Baidu. All rights reserved.
//

#import <BaiduMapAPI_Base/BMKTypes.h>

NS_ASSUME_NONNULL_BEGIN

/// 建筑物返回结果类
@interface BMKBuildingSearchResult : NSObject

/// 建筑物返回结果列表
@property (nonatomic, copy) NSArray<BMKBuildInfo *> *buildingList;
@end



NS_ASSUME_NONNULL_END
