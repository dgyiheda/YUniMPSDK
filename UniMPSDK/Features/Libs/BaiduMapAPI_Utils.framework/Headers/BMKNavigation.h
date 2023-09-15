/*
 *  BMKNavigation.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */
#import <UIKit/UIKit.h>
#import <BaiduMapAPI_Base/BMKTypes.h>
//定义调起导航的两种类型
//注：自2.8.0开始废弃，只支持调起客户端导航，在调起客户端导航时，才会调起web导航
typedef enum
{
    BMK_NAVI_TYPE_NATIVE = 0, /// 客户端导航
    BMK_NAVI_TYPE_WEB /// web导航
} BMK_NAVI_TYPE;

typedef enum
{
    BMK_NAVI_ROUTE_PLAN_TYPE_BLK = 0, /// 躲避拥堵(自驾)
    BMK_NAVI_ROUTE_PLAN_TYPE_TIME, /// 最短时间,高速优先(自驾)
    BMK_NAVI_ROUTE_PLAN_TYPE_DIS, /// 最短路程,不走高速(自驾)；不支持（货车）
    BMK_NAVI_ROUTE_PLAN_TYPE_FEE, /// 少走高速,避免收费(自驾);不走高速（货车）
    BMK_NAVI_ROUTE_PLAN_TYPE_DEFAULT, /// 智能推荐
    BMK_NAVI_ROUTE_PLAN_TYPE_ECONOMICS /// 省钱路线(仅货车)
} BMK_NAVI_ROUTE_PLAN_TYPE;

///此类管理调起导航时传入的参数
@interface BMKNaviPara : NSObject
{
	BMKPlanNode* _startPoint;
	BMKPlanNode* _endPoint;
	BMK_NAVI_TYPE _naviType;
    NSString* _appScheme;
    NSString* _appName;
}
/// 起点，必须包含经纬度坐标（调起地图客户端时设置起点无效，以“我的位置”为起点）
@property (nonatomic, strong) BMKPlanNode *startPoint;
/// 终点，必须包含经纬度坐标
@property (nonatomic, strong) BMKPlanNode *endPoint;
/// 导航类型 注：自2.8.0开始废弃，只支持调起客户端导航，在调起客户端导航时，才会调起web导航
@property (nonatomic, assign) BMK_NAVI_TYPE naviType __deprecated_msg("自2.8.0开始废弃");
/// 应用返回scheme
@property (nonatomic, copy) NSString *appScheme;
/// 应用名称
@property (nonatomic, copy) NSString *appName;
/// 调起百度地图客户端驾车导航失败后（步行、骑行导航设置该参数无效），是否支持调起web地图，默认：YES
@property (nonatomic, assign) BOOL isSupportWeb;
/// 导航路线偏好设置（步行（AR）、骑行导航设置该参数无效）,可选，默认：BMK_NAVI_ROUTE_PLAN_TYPE_DEFAULT(智能推荐)
@property (nonatomic, assign) BMK_NAVI_ROUTE_PLAN_TYPE preferenceType;
/// 途径点（步行（AR）、骑行导航设置该参数无效）,可选
@property (nonatomic, strong) NSArray<BMKPlanNode *> *viaPoints;

@end

/// 货车导航参数
@interface BMKTruckNaviPara : BMKNaviPara
/// 车辆高度,单位米，范围[0,10],可选
@property (nonatomic, assign) float height;
/// 车辆宽度, 单位米，范围[0,5],可选
@property (nonatomic, assign) float width;
/// 车辆总重,单位吨,范围[0,100],可选
@property (nonatomic, assign) float weight;
/// 车辆长度,单位米,范围[0,25],可选
@property (nonatomic, assign) float length;
/// 轴重,单位吨,范围[0,100],可选
@property (nonatomic, assign) float axleWeight;
/// 轴数,范围[0, 50],可选
@property (nonatomic, assign) int axleCount;
/// 是否挂车,可选
@property (nonatomic, assign) BOOL isTrailer;
/// 车牌省份，如京，粤,可选
@property (nonatomic, copy) NSString *plateProvince;
/// 车牌号码，省份外的号码，如B69999,可选
@property (nonatomic, copy) NSString *plateNumber;
/// 车牌颜色,0:蓝色(默认) 1:黄 2:黑 3:白 4:绿,可选
@property (nonatomic, assign) int plateColor;
/// 百公里油耗，单位L,可选
@property (nonatomic, assign) float displacement;
/// 动力类型1-汽油;2-柴油;3-电动;4-混合,可选
@property (nonatomic, assign) int powerType;
/// 排放标准 。取值范围1-6，对 应国1-国6标准,可选
@property (nonatomic, assign) int emissionLimit;
/// 核定载重。单位吨，范围[0,100],可选
@property (nonatomic, assign) BOOL loadWeight;

@end

/// 调起百度地图 -- 导航（驾车、步行、骑行、新能源、摩托车、货车）
@interface BMKNavigation : NSObject

/**
*调起百度地图客户端驾车导航页面(不支持调起web地图)
*@param para 调起驾车导航时传入得参数
*/
+ (BMKOpenErrorCode)openBaiduMapNavigation:(BMKNaviPara *)para;

/**
 *调起百度地图客户端步行导航页面(不支持调起web地图)
 *客户端v8.8以后支持
 *@param para 调起步行导航时传入参数
 */
+ (BMKOpenErrorCode)openBaiduMapWalkNavigation:(BMKNaviPara *)para;

/**
 *调起百度地图客户端骑行导航页面(不支持调起web地图)
 *客户端v8.8以后支持
 *@param para 调起骑行导航时传入参数
 */
+ (BMKOpenErrorCode)openBaiduMapRideNavigation:(BMKNaviPara *)para;
/**
 *调起百度地图AR步行导航
 *百度地图客户端v9.7.5以后支持AR步行导航，低于此版本，默认调用步行导航；注：客户端版本低于8.6.9，不支持步行导航。
 *@param para 调起AR步行导航时传入参数 
 */
+ (BMKOpenErrorCode)openBaiduMapwalkARNavigation:(BMKNaviPara *)para;

/**
*调起百度地图客户端驾车（新能源车）导航页面(不支持调起web地图)
*@param para 调起驾车导航时传入得参数
*/
+ (BMKOpenErrorCode)openBaiduMapNewEngNavigation:(BMKNaviPara *)para;

/**
 *调起百度地图客户端货车导航页面(不支持调起web地图)
 *百度地图客户端15.4.0以后支持
 *@param para 调起驾车导航时传入得参数
*/
+ (BMKOpenErrorCode)openBaiduMapTruckNavigation:(BMKTruckNaviPara *)para;

/**
*调起百度地图客户端摩托车导航页面(不支持调起web地图)
*@param para 调起驾车导航时传入得参数
*/
+ (BMKOpenErrorCode)openBaiduMapMotorNavigation:(BMKNaviPara *)para;

@end


