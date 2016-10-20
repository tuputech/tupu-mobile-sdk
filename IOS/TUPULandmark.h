//
//  TUPULandmark.h
//  tupuSDK
//
//  Created by drakeDan on 7/19/16.
//  Copyright © 2016 tupu. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>
#import <Foundation/Foundation.h>

@interface TUPULandmark : NSObject

/** 获取版本号 */
+ (NSString *)getVersion;

/** 关键点个数 */
@property (nonatomic, assign, readonly) int pointsNumber;

/**
 *  初始化方法 必须使用该方法初始化，否则会导致初始化失败。
 *
 *  @param modelPath Model资源路径
 *  @return Model加载成功标志
 */
- (BOOL)initWithModel:(NSString *)modelPath;

/**
 *  人脸关键点（83点）检测
 *
 *  @param sampleBuffer 视频帧
 *  @param landmarkPoints 存放关键点的数组
 *  @return 有效关键点标志（TRUE：有效，FALSE：无效）
 */
- (BOOL)getLandmark:(CMSampleBufferRef)sampleBuffer landmarkPoints:(NSArray <NSValue *>*)landmarkPoints;

/** 释放Model资源和内部数据 */
- (void)releaseModel;

@end

