/*
 *  BMKGradient.h
 *  BMapKit
 *
 *  Copyright 2013 Baidu Inc. All rights reserved.
 *
 */
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
/// 此类表示热力图渐变色
@interface BMKGradient : NSObject
/// 渐变色用到的所有颜色数组,数组成员类型为UIColor,默认值[0x0000c8,0x00e100,0xff0000]
@property (nonatomic, strong) NSArray <UIColor *> *mColors;
/// 每一个颜色的起始点数组,数组成员类型为 [0,1]的double值, given as a percentage of the maximum intensity,个数和mColors的个数必须相同，
/// 数组内元素必须时递增的,默认值[@0.08, @0.4, @1.0]
@property (nonatomic, strong) NSArray<NSNumber *> *mStartPoints;

/// 渐变色的初始化方法,使用默认colorMapSize:1000进行初始化
- (instancetype)initWithColors:(NSArray<UIColor *> *)colors startPoints:(NSArray<NSNumber *>*)startPoints;
@end





