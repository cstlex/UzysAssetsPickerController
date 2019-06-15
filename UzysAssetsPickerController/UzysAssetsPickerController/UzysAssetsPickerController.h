//
//  UzysAssetsPickerController.h
//  UzysAssetsPickerController
//
//  Created by Uzysjung on 2014. 2. 12..
//  Copyright (c) 2014년 Uzys. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UzysAssetsPickerController_Configuration.h"
#import "UzysAppearanceConfig.h"
#import <CoreLocation/CoreLocation.h>

@class UzysAssetsPickerController;
@protocol UzysAssetsPickerControllerDelegate<NSObject>
- (void)uzysAssetsPickerController:(UzysAssetsPickerController *)picker didFinishPickingAssets:(NSArray *)assets;
@optional
- (void)uzysAssetsPickerControllerDidCancel:(UzysAssetsPickerController *)picker;
- (void)uzysAssetsPickerControllerDidExceedMaximumNumberOfSelection:(UzysAssetsPickerController *)picker;
@end

typedef BOOL (^AssetFilter)(ALAsset *asset);

@interface UzysAssetsPickerController : UIViewController
@property (nonatomic, strong) ALAssetsFilter *assetsFilter;
@property (nonatomic, strong) CLLocation * location;
@property (nonatomic, assign) NSInteger maximumNumberOfSelectionVideo;
@property (nonatomic, assign) NSInteger maximumNumberOfSelectionPhoto;
//--------------------------------------------------------------------
@property (nonatomic, assign) NSInteger maximumNumberOfSelectionMedia;
@property (nonatomic, copy) AssetFilter filterBlock;

@property (nonatomic, weak) id <UzysAssetsPickerControllerDelegate> delegate;
+ (ALAssetsLibrary *)defaultAssetsLibrary;
/**
 *  setup the appearance, including the all the properties in UzysAppearanceConfig, check UzysAppearanceConfig.h out for details.
 *
 *  @param config UzysAppearanceConfig instance.
 */
+ (void)setUpAppearanceConfig:(UzysAppearanceConfig *)config;

@end