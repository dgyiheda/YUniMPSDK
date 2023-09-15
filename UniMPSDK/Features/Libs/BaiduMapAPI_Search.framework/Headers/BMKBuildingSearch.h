//
//  BMKBuildingSearch.h
//  BaiduMapAPI_Search
//
//  Created by zhangbaojin on 2021/4/19.
//  Copyright © 2021 Baidu. All rights reserved.
//

#import "BMKSearchBase.h"
#import "BMKBuildingSearchOption.h"
#import "BMKBuildingSearchResult.h"
NS_ASSUME_NONNULL_BEGIN

@protocol BMKBuildingSearchDelegate;
/// 建筑物检索类，建筑物检索为高级服务，AK需要申请高级权限 since 6.4.0
@interface BMKBuildingSearch : BMKSearchBase

/// 建筑检索模块的delegate
@property (nonatomic, weak) id<BMKBuildingSearchDelegate> delegate;

/// 建筑检索
- (BOOL)buildingSearch:(BMKBuildingSearchOption *)buildingOption;

@end



/// 搜索delegate，用于获取搜索结果
@protocol BMKBuildingSearchDelegate<NSObject>

@optional
/// 返回建筑物检索结果
/// @param searcher 检索对象
/// @param result 检索结果
/// @param error 错误号，@see BMKSearchErrorCode
- (void)onGetBuildingResult:(BMKBuildingSearch *)searcher result:(BMKBuildingSearchResult *)result errorCode:(BMKSearchErrorCode)error;


@end


NS_ASSUME_NONNULL_END
