//
//  MTLHeap.h
//  Metal
//
//  Copyright (c) 2016 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Metal/MTLDefines.h>
#import <Metal/MTLResource.h>
#import <Metal/MTLBuffer.h>
#import <Metal/MTLTexture.h>
#import <Metal/MTLTypes.h>
#import <Metal/MTLDevice.h>
//#import <Metal/MTLAccelerationStructure.h>

//NS_ASSUME_NONNULL_BEGIN
METAL_DECLARATIONS_BEGIN
/*!
 @enum MTLHeapType
 @abstract Describes the mode of operation for an MTLHeap.
 @constant MTLHeapTypeAutomatic
 In this mode, resources are placed in the heap automatically.
 Automatically placed resources have optimal GPU-specific layout, and may perform better than MTLHeapTypePlacement.
 This heap type is recommended when the heap primarily contains temporary write-often resources.
 @constant MTLHeapTypePlacement
 In this mode, the app places resources in the heap.
 Manually placed resources allow the app to control memory usage and heap fragmentation directly.
 This heap type is recommended when the heap primarily contains persistent write-rarely resources.
 */
typedef NS_ENUM(NSInteger, MTLHeapType)
{
    MTLHeapTypeAutomatic = 0,
    MTLHeapTypePlacement = 1,
    MTLHeapTypeSparse API_AVAILABLE(macos(11.0), macCatalyst(14.0)) = 2 ,
};// API_AVAILABLE(macos(10.15), ios(13.0));

/*!
 @class MTLHeapDescriptor
 */
MTL_EXPORT //API_AVAILABLE(macos(10.13), ios(10.0))
@interface MTLHeapDescriptor : NSObject <NSCopying>

/*!
 @property size
 @abstract Requested size of the heap's backing memory.
 @discussion The size may be rounded up to GPU page granularity.
 */
@property (readwrite, nonatomic) NSUInteger size;

/*!
 @property storageMode
 @abstract Storage mode for the heap. Default is MTLStorageModePrivate.
 @discussion All resources created from this heap share the same storage mode.
 MTLStorageModeManaged and MTLStorageModeMemoryless are disallowed.
 */
@property (readwrite, nonatomic) MTLStorageMode storageMode;

/*!
 @property cpuCacheMode
 @abstract CPU cache mode for the heap. Default is MTLCPUCacheModeDefaultCache.
 @discussion All resources created from this heap share the same cache mode.
 CPU cache mode is ignored for MTLStorageModePrivate.
 */
@property (readwrite, nonatomic) MTLCPUCacheMode cpuCacheMode;



/*!
 @property sparsePageSize
 @abstract The sparse page size to use for resources created from the heap.
 */
@property (readwrite, nonatomic) MTLSparsePageSize sparsePageSize API_AVAILABLE(macos(13.0), ios(16.0));


/*!
 @property hazardTrackingMode
 @abstract Set hazard tracking mode for the heap. The default value is MTLHazardTrackingModeDefault.
 @discussion For heaps, MTLHazardTrackingModeDefault is treated as MTLHazardTrackingModeUntracked.
 Setting hazardTrackingMode to MTLHazardTrackingModeTracked causes hazard tracking to be enabled heap.
 When a resource on a hazard tracked heap is modified, reads and writes from all resources suballocated on that heap will be delayed until the modification is complete.
 Similarly, modifying heap resources will be delayed until all in-flight reads and writes from all resources suballocated on that heap have completed.
 For optimal performance, perform hazard tracking manually through MTLFence or MTLEvent instead.
 All resources created from this heap shared the same hazard tracking mode.
 */
@property (readwrite, nonatomic) MTLHazardTrackingMode hazardTrackingMode API_AVAILABLE(macos(10.15), ios(13.0));

/*!
 @property resourceOptions
 @abstract A packed tuple of the storageMode, cpuCacheMode and hazardTrackingMode properties.
 @discussion Modifications to this property are reflected in the other properties and vice versa.
 */
@property (readwrite, nonatomic) MTLResourceOptions resourceOptions API_AVAILABLE(macos(10.15), ios(13.0));

/*!
 @property type
 @abstract The type of the heap. The default value is MTLHeapTypeAutomatic.
 @discussion This constrains the resource creation functions that are available.
 */
@property (readwrite, nonatomic) MTLHeapType type API_AVAILABLE(macos(10.15), ios(13.0));

@end

//NS_ASSUME_NONNULL_END
METAL_DECLARATIONS_END
