//
//  NSBundle+TZImagePicker.h
//  TZImagePickerController
//
//  Created by 谭真 on 16/08/18.
//  Copyright © 2016年 谭真. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSBundle (DCTZImagePicker)

+ (NSBundle *)dctz_imagePickerBundle;

+ (NSString *)dctz_localizedStringForKey:(NSString *)key value:(NSString *)value;
+ (NSString *)dctz_localizedStringForKey:(NSString *)key;

@end

