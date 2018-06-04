//
//  SHImagerPickerOption.h
//  SHImagePickerControllerDemo
//
//  Created by angle on 2018/5/31.
//  Copyright © 2018 uuzu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Photos/Photos.h>

/**
 @brief 横竖屏模式
 
 @since 1.0.0
 */
typedef NS_ENUM(NSInteger, SHAlbumHorizontalPortraitMode) {
    SHAlbumHorizontalPortraitModeLandscape , //横屏模式
    SHAlbumHorizontalPortraitModeVertical    //竖屏模式
};

@interface SHImagerPickerOption : NSObject

/**
 Default is YZLiveAlbumHorizontalPortraitModeVertical
 默认竖屏模式
 */
@property (nonatomic, assign) SHAlbumHorizontalPortraitMode interfaceOrientation;

/**
 Default is 9
 默认最大可选9张图片
 */
@property (nonatomic, assign) NSInteger maxImagesCount;

/**
 The minimum count photos user must pick, Default is 0
 最小照片必选张数,默认是0
 */
@property (nonatomic, assign) NSInteger minImagesCount;

/**
 Always enale the done button, not require minimum 1 photo be picked Default is YES
 让完成按钮一直可以点击，无须最少选择一张图片 默认yes
 */
@property (nonatomic, assign) BOOL alwaysEnableDoneBtn;

/**
 Sort photos ascending by modificationDate，Default is YES
 对照片排序，按修改时间升序，默认是YES。如果设置为NO,最新的照片会显示在最前面，内部的拍照按钮会排在第一个
 */
@property (nonatomic, assign) BOOL sortAscendingByModificationDate;

/**
 The pixel width of output image, Default is 828px
 导出图片的宽度，默认828像素宽
 */
@property (nonatomic, assign) CGFloat photoWidth;

/**
 Default is 600px
 默认600像素宽
 */
@property (nonatomic, assign) CGFloat photoPreviewMaxWidth;

/**
 Default is 15, While fetching photo, HUD will dismiss automatic if timeout
 超时时间，默认为15秒，当取图片时间超过15秒还没有取成功时，会自动dismiss HUD
 */
@property (nonatomic, assign) NSInteger timeout;

/**
 Default is YES, if set NO, the original photo button will hide. user can't picking original photo.
 默认为YES，如果设置为NO,原图按钮将隐藏，用户不能选择发送原图
 */
@property (nonatomic, assign) BOOL allowPickingOriginalPhoto;

/**
 Default is YES, if set NO, user can't picking video.
 默认为YES，如果设置为NO,用户将不能选择视频
 */
@property (nonatomic, assign) BOOL allowPickingVideo;

/**
 Default is NO, and you can select video/GIF images when YES, and share the maximum optional number of maxImagesCount with photos
 默认为NO，为YES时可以多选视频/gif图片，和照片共享最大可选张数maxImagesCount的限制
 */
@property (nonatomic, assign) BOOL allowPickingMultipleVideo;

/**
 Default is NO, if set YES, user can picking gif image.
 默认为NO，如果设置为YES,用户可以选择gif图片
 */
@property (nonatomic, assign) BOOL allowPickingGif;

/**
 Default is YES, if set NO, user can't picking image.
 默认为YES，如果设置为NO,用户将不能选择发送图片
 */
@property(nonatomic, assign) BOOL allowPickingImage;

/**
 Default is YES, if set NO, user can't take picture.
 默认为YES，如果设置为NO, 用户将不能拍摄照片
 */
@property(nonatomic, assign) BOOL allowTakePicture;

/**
 Default is YES, if set NO, user can't take video.
 默认为YES，如果设置为NO, 用户将不能拍摄视频
 */
@property(nonatomic, assign) BOOL allowTakeVideo;

/**
 Default value is 10 minutes
 视频最大拍摄时间，默认是10分钟，单位是秒
 */
@property (assign, nonatomic) NSTimeInterval videoMaximumDuration;

/**
 Customizing other properties, such as videoQuality
 定制视频拍摄质量videoQuality
 */
@property (nonatomic, assign) UIImagePickerControllerQualityType videoQuality;

/**
 首选语言，如果设置了就用该语言，不设则取当前系统语言。
 由于目前只支持中文、繁体中文、英文、越南语。故该属性只支持zh-Hans、zh-Hant、en、vi四种值，其余值无效。
 */
@property (copy, nonatomic) NSString *preferredLanguage;

/**
 语言bundle，preferredLanguage变化时languageBundle会变化
 可通过手动设置bundle，让选择器支持新的的语言（需要在设置preferredLanguage后设置languageBundle）。欢迎提交PR把语言文件提交上来~
 */
@property (strong, nonatomic) NSBundle *languageBundle;

/**
 Default is YES, if set NO, user can't preview photo.
 默认为YES，如果设置为NO,预览按钮将隐藏,用户将不能去预览照片
 */
@property (nonatomic, assign) BOOL allowPreview;

/**
 Default is YES, if set NO, the picker don't dismiss itself.
 默认为YES，如果设置为NO, 选择器将不会自己dismiss
 */
@property(nonatomic, assign) BOOL autoDismiss;

/**
 Default is NO, if set YES, in the delegate method the photos and infos will be nil, only assets hava value.
 默认为NO，如果设置为YES，代理方法里photos和infos会是nil，只返回assets
 */
@property (assign, nonatomic) BOOL onlyReturnAsset;

/**
 Default is NO, if set YES, will show the image's selected index.
 默认为NO，如果设置为YES，会显示照片的选中序号
 */
@property (assign, nonatomic) BOOL showSelectedIndex;

/**
 Default is NO, if set YES, when selected photos's count up to maxImagesCount, other photo will show float layer what's color is cannotSelectLayerColor.
 默认是NO，如果设置为YES，当照片选择张数达到maxImagesCount时，其它照片会显示颜色为cannotSelectLayerColor的浮层
 */
@property (assign, nonatomic) BOOL showPhotoCannotSelectLayer;

/**
 Default is white color with 0.8 alpha
 */
@property (strong, nonatomic) UIColor *cannotSelectLayerColor;

/**
 @abstract 使用默认配置生成一个 YZLiveAlbumOption 对象
 
 @return 生成的 YZLiveAlbumOption 对象
 
 @since v1.0.0
 */
+ (SHImagerPickerOption *)defaultOption;

@end
