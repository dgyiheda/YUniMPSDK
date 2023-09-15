/*
 *  BMKHeatMap.h
 *  BMapKit
 *
 *  Copyright 2013 Baidu Inc. All rights reserved.
 *
 */
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#ifdef USE_NAVI
#import <BaiduMapAPI_Base_Navi/BMKTypes.h>
#else
#import <BaiduMapAPI_Base/BMKTypes.h>
#endif
#import "BMKGradient.h"
///热力图节点信息
@interface BMKHeatMapNode : NSObject{
    double                 _intensity;
    CLLocationCoordinate2D _pt;
}

/// 点的强度权值,默认值1，范围[>= 1]
@property (nonatomic) double intensity;
/// 点的位置坐标,经度：[72.508319 ~ 135.942198],纬度：[0.37532 ~ 54.562495]
@property (nonatomic) CLLocationCoordinate2D pt;

@end



/// 热力图的绘制数据和显示样式类
@interface BMKHeatMap : NSObject
{
	int    _mRadius; //Heatmap point radius
    BMKGradient* _mGradient;//Gradient of the color map
    double   _mOpacity;//Opacity of the overall heatmap overlay [0...1]
    NSMutableArray*  _mData;
    
}
/// 设置热力图点半径，默认为12ps，范围[10~50]
@property (nonatomic, assign) int mRadius;
/// 设置热力图渐变，有默认值 DEFAULT_GRADIENT
@property (nonatomic, strong) BMKGradient *mGradient;
/// 设置热力图层透明度，默认 0.6,范围[0~1]
@property (nonatomic, assign) double mOpacity;
/// 用户传入的热力图数据,数组,成员类型为BMKHeatMapNode
@property (nonatomic, strong) NSMutableArray <BMKHeatMapNode *> *mData;

@end



