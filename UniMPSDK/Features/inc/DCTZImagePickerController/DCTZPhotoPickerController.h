//
//  TZPhotoPickerController.h
//  TZImagePickerController
//
//  Created by 谭真 on 15/12/24.
//  Copyright © 2015年 谭真. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DCTZAlbumModel;
@interface DCTZPhotoPickerController : UIViewController

@property (nonatomic, assign) BOOL isFirstAppear;
@property (nonatomic, assign) NSInteger columnNumber;
@property (nonatomic, strong) DCTZAlbumModel *model;

// 窦 解决iOS14下 相册在可选照片状态下 修改后不更新的Bug 新增一个刷新UI的函数
-(void)optionModeUpdateUI;
@end


@interface DCTZCollectionView : UICollectionView

@end
