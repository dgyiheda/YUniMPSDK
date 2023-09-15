//
//  UIView+Layout.h
//
//  Created by 谭真 on 15/2/24.
//  Copyright © 2015年 谭真. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    DCTZOscillatoryAnimationToBigger,
    DCTZOscillatoryAnimationToSmaller,
} DCTZOscillatoryAnimationType;

@interface UIView (DCLayout)

@property (nonatomic) CGFloat dctz_left;        ///< Shortcut for frame.origin.x.
@property (nonatomic) CGFloat dctz_top;         ///< Shortcut for frame.origin.y
@property (nonatomic) CGFloat dctz_right;       ///< Shortcut for frame.origin.x + frame.size.width
@property (nonatomic) CGFloat dctz_bottom;      ///< Shortcut for frame.origin.y + frame.size.height
@property (nonatomic) CGFloat dctz_width;       ///< Shortcut for frame.size.width.
@property (nonatomic) CGFloat dctz_height;      ///< Shortcut for frame.size.height.
@property (nonatomic) CGFloat dctz_centerX;     ///< Shortcut for center.x
@property (nonatomic) CGFloat dctz_centerY;     ///< Shortcut for center.y
@property (nonatomic) CGPoint dctz_origin;      ///< Shortcut for frame.origin.
@property (nonatomic) CGSize  dctz_size;        ///< Shortcut for frame.size.

+ (void)showOscillatoryAnimationWithLayer:(CALayer *)layer type:(DCTZOscillatoryAnimationType)type;

@end
