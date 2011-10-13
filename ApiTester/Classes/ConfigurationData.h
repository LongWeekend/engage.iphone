//
//  ConfigurationData.h
//  ApiTester
//
//  Created by lilli on 9/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CustomViewBuilder.h"
#import "JREngage.h"
#import "JREngage+CustomInterface.h"

typedef enum
{
    CDNone,
    CDSignIn,
    CDSharing,
} SignInOrSharing;

typedef enum
{
    CDSignInTestTypeNone,
    CDSignInTestTypeBasic,
    CDSignInTestTypeCustomInterface,
    CDSignInTestTypeProviderConfiguration,
} SignInTestType;

typedef enum
{
    CDSharingTestTypeNone,
    CDSharingTestTypeBasic,
    CDSharingTestTypeEmailSms,
    CDSharingTestTypeCustomInterface,
    CDSharingTestTypeActivityChanges,
    CDSharingTestTypeBadActivityParams,
} SharingTestType;

typedef enum
{
    CDNavigationControllerTypeLibrary,
    CDNavigationControllerTypeApplication,
    CDNavigationControllerTypeCustom,
} NavigationControllerType;

@interface ConfigurationData : NSObject <JREngageDelegate>
{
    JREngage *jrEngage;

    SignInOrSharing signInOrSharing;
    SignInTestType  signInTestType;
    SharingTestType sharingTestType;

    BOOL authenticationBackgroundColor;
    BOOL authenticationBackgroundImageView;
    BOOL providerTableTitleView;
    BOOL providerTableTitleString;
    BOOL providerTableHeaderView;
    BOOL providerTableFooterView;
    BOOL providerTableSectionHeaderView;
    BOOL providerTableSectionFooterView;
    BOOL providerTableSectionHeaderTitleString;
    BOOL providerTableSectionFooterTitleString;

    JRActivityObject    *activity;

    NSString *activityAction;
    NSString *activityUrl;
    NSString *activityTitle;
    NSString *activityDescription;

    NSMutableArray      *activityMediaArray;
    NSMutableArray      *activityActionLinksArray;
    NSMutableDictionary *activityPropertiesDictionary;

    JREmailObject *activityEmailObject;
    JRSmsObject   *activitySmsObject;

 /* Default activity properties, which are set in the constructor using static, constant strings; The static constant
    strings can be changed to test various things. Also, default activity properties can be added to an activity
    independently, to allow for testing various configurations. */
    NSString *defaultActivityAction;
    NSString *defaultActivityUrl;
    NSString *defaultActivityTitle;
    NSString *defaultActivityDescription;

    JRImageMediaObject  *defaultActivityImage;
    JRMp3MediaObject    *defaultActivitySong;
    JRFlashMediaObject  *defaultActivityVideo;
    JREmailObject       *defaultActivityEmail;
    JRSmsObject         *defaultActivitySms;
    JRActionLink        *defaultActivityActionLink;
    NSMutableDictionary *defaultActivityProperties;

    BOOL activityAddDefaultAction;
    BOOL activityAddDefaultUrl;
    BOOL activityAddDefaultTitle;
    BOOL activityAddDefaultDescription;
    BOOL activityAddDefaultImage;
    BOOL activityAddDefaultSong;
    BOOL activityAddDefaultVideo;
    BOOL activityAddDefaultActionLinks;
    BOOL activityAddDefaultProperties;
    BOOL activityAddDefaultEmailObject;
    BOOL activityAddDefaultSmsObject;

    NSMutableDictionary *customInterface;
}

+ (ConfigurationData*)sharedConfigurationData;

@property SignInOrSharing signInOrSharing;
@property SignInTestType  signInTestType;
@property SharingTestType sharingTestType;

@property BOOL authenticationBackgroundColor;
@property BOOL authenticationBackgroundImageView;
@property BOOL providerTableTitleView;
@property BOOL providerTableTitleString;
@property BOOL providerTableHeaderView;
@property BOOL providerTableFooterView;
@property BOOL providerTableSectionHeaderView;
@property BOOL providerTableSectionFooterView;
@property BOOL providerTableSectionHeaderTitleString;
@property BOOL providerTableSectionFooterTitleString;

@property BOOL activityAddDefaultAction;
@property BOOL activityAddDefaultUrl;
@property BOOL activityAddDefaultTitle;
@property BOOL activityAddDefaultDescription;
@property BOOL activityAddDefaultImage;
@property BOOL activityAddDefaultSong;
@property BOOL activityAddDefaultVideo;
@property BOOL activityAddDefaultActionLinks;
@property BOOL activityAddDefaultProperties;
@property BOOL activityAddDefaultEmailObject;
@property BOOL activityAddDefaultSmsObject;

@property (copy) NSString *activityAction;
@property (copy) NSString *activityUrl;
@property (copy) NSString *activityTitle;
@property (copy) NSString *activityDescription;

- (void)resetActivity;
- (void)resetCustomInterface;

- (void)addActivityImageWithSrc:(NSString *)src andHref:(NSString *)href;
- (void)addActivitySongWithSrc:(NSString *)src title:(NSString *)title artist:(NSString *)artist andAlbum:(NSString *)album;
- (void)addActivityVideoWithSwfsrc:(NSString *)swfsrc imgsrc:(NSString *)imgsrc width:(NSUInteger)width height:(NSUInteger)height
                     expandedWidth:(NSUInteger)expandedWidth andExpandedHeight:(NSUInteger)expandedHeight;
- (void)addActivityPropertiesWithDictionary:(NSDictionary *)properties;
- (void)addActivityEmailWithSubject:(NSString *)subject body:(NSString *)body isHtml:(BOOL)isHtml andUrls:(NSArray *)urls;
- (void)addActivitySmsWithMessage:(NSString *)message andUrls:(NSArray *)urls;

- (void)startTestWithNavigationController:(NavigationControllerType)navigationControllerType;
@end
