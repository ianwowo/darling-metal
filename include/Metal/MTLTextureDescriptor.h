/*
 This file is part of Darling.

 Copyright (C) 2025 Darling Developers

 Darling is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Darling is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Darling.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _METAL_MTLTEXTUREDESCRIPTOR_H_
#define _METAL_MTLTEXTUREDESCRIPTOR_H_

#import <Foundation/Foundation.h>
#import <Metal/MTLTexture.h>

typedef NS_ENUM(NSInteger, MTLTextureCompressionType)
{
    MTLTextureCompressionTypeLossless = 0,
    MTLTextureCompressionTypeLossy = 1,
}; // API_AVAILABLE(macos(12.5), ios(15.0));

MTL_EXPORT //API_AVAILABLE(macos(10.11), ios(8.0))
@interface MTLTextureDescriptor : NSObject <NSCopying>

/*!
 @method texture2DDescriptorWithPixelFormat:width:height:mipmapped:
 @abstract Create a TextureDescriptor for a common 2D texture.
 */
+ (MTLTextureDescriptor*)texture2DDescriptorWithPixelFormat:(MTLPixelFormat)pixelFormat width:(NSUInteger)width height:(NSUInteger)height mipmapped:(BOOL)mipmapped;

/*!
 @method textureCubeDescriptorWithPixelFormat:size:mipmapped:
 @abstract Create a TextureDescriptor for a common Cube texture.
 */
+ (MTLTextureDescriptor*)textureCubeDescriptorWithPixelFormat:(MTLPixelFormat)pixelFormat size:(NSUInteger)size mipmapped:(BOOL)mipmapped;

/*!
 @method textureBufferDescriptorWithPixelFormat:width:resourceOptions:usage:
 @abstract Create a TextureDescriptor for a common texture buffer.
 */
+ (MTLTextureDescriptor*)textureBufferDescriptorWithPixelFormat:(MTLPixelFormat)pixelFormat
                                                          width:(NSUInteger)width
                                                resourceOptions:(MTLResourceOptions)resourceOptions
                                                          usage:(MTLTextureUsage)usage API_AVAILABLE(macos(10.14), ios(12.0));

/*!
 @property type
 @abstract The overall type of the texture to be created. The default value is MTLTextureType2D.
 */
@property (readwrite, nonatomic) MTLTextureType textureType;

/*!
 @property pixelFormat
 @abstract The pixel format to use when allocating this texture. This is also the pixel format that will be used to when the caller writes or reads pixels from this texture. The default value is MTLPixelFormatRGBA8Unorm.
 */
@property (readwrite, nonatomic) MTLPixelFormat pixelFormat;

/*!
 @property width
 @abstract The width of the texture to create. The default value is 1.
 */
@property (readwrite, nonatomic) NSUInteger width;

/*!
 @property height
 @abstract The height of the texture to create. The default value is 1.
 @discussion height If allocating a 1D texture, height must be 1.
 */
@property (readwrite, nonatomic) NSUInteger height;

/*!
 @property depth
 @abstract The depth of the texture to create. The default value is 1.
 @discussion depth When allocating any texture types other than 3D, depth must be 1.
 */
@property (readwrite, nonatomic) NSUInteger depth;

/*!
 @property mipmapLevelCount
 @abstract The number of mipmap levels to allocate. The default value is 1.
 @discussion When creating Buffer and Multisample textures, mipmapLevelCount must be 1.
 */
@property (readwrite, nonatomic) NSUInteger mipmapLevelCount;

/*!
 @property sampleCount
 @abstract The number of samples in the texture to create. The default value is 1.
 @discussion When creating Buffer textures sampleCount must be 1. Implementations may round sample counts up to the next supported value.
 */
@property (readwrite, nonatomic) NSUInteger sampleCount;

/*!
 @property arrayLength
 @abstract The number of array elements to allocate. The default value is 1.
 @discussion When allocating any non-Array texture type, arrayLength has to be 1. Otherwise it must be set to something greater than 1 and less than 2048.
 */
@property (readwrite, nonatomic) NSUInteger arrayLength;

/*!
 @property resourceOptions
 @abstract Options to control memory allocation parameters, etc.
 @discussion Contains a packed set of the storageMode, cpuCacheMode and hazardTrackingMode properties.
 */
@property (readwrite, nonatomic) MTLResourceOptions resourceOptions;

/*!
 @property cpuCacheMode
 @abstract Options to specify CPU cache mode of texture resource.
 */
@property (readwrite, nonatomic) MTLCPUCacheMode cpuCacheMode API_AVAILABLE(macos(10.11), ios(9.0));

/*!
 @property storageMode
 @abstract To specify storage mode of texture resource.
 */
@property (readwrite, nonatomic) MTLStorageMode storageMode API_AVAILABLE(macos(10.11), ios(9.0));


/*!
 @property hazardTrackingMode
 @abstract Set hazard tracking mode for the texture. The default value is MTLHazardTrackingModeDefault.
 @discussion
 For resources created from the device, MTLHazardTrackingModeDefault is treated as MTLHazardTrackingModeTracked.
 For resources created on a heap, MTLHazardTrackingModeDefault is treated as the hazardTrackingMode of the heap itself.
 In either case, it is possible to opt-out of hazard tracking by setting MTLHazardTrackingModeUntracked.
 It is not possible to opt-in to hazard tracking on a heap that itself is not hazard tracked.
 For optimal performance, perform hazard tracking manually through MTLFence or MTLEvent instead.
 */
@property (readwrite, nonatomic) MTLHazardTrackingMode hazardTrackingMode API_AVAILABLE(macos(10.15), ios(13.0));

/*!
 @property usage
 @abstract Description of texture usage
 */
@property (readwrite, nonatomic) MTLTextureUsage usage API_AVAILABLE(macos(10.11), ios(9.0));

/*!
 @property allowGPUOptimizedContents
 @abstract Allow GPU-optimization for the contents of this texture. The default value is true.
 @discussion Useful for opting-out of GPU-optimization when implicit optimization (e.g. RT writes) is regressing CPU-read-back performance. See the documentation for optimizeContentsForGPUAccess: and optimizeContentsForCPUAccess: APIs.
 */
@property (readwrite, nonatomic) BOOL allowGPUOptimizedContents API_AVAILABLE(macos(10.14), ios(12.0));

/*!
 @property compressionType
 @abstract Controls how the texture contents will be compressed when written to by the GPU. Compression can be used to reduce the bandwidth usage and storage requirements of a texture.
 @discussion The default compression type is lossless, meaning that no loss of precision will occur when the texture content is modified.
 Losslessly compressed textures may benefit from reduced bandwidth usage when regions of correlated color values are written, but do not benefit from reduced storage requirements.
 Enabling lossy compression for textures that can tolerate some precision loss will guarantee both reduced bandwidth usage and reduced storage requirements.
 The amount of precision loss depends on the color values stored; regions with correlated color values can be represented with limited to no precision loss, whereas regions with unrelated color values suffer more precision loss.
 Enabling lossy compression requires both storageMode == MTLStorageModePrivate, allowGPUOptimizedContents == YES, and cannot be combined with either MTLTextureUsagePixelFormatView, MTLTextureUsageShaderWrite, MTLTextureUsageShaderAtomic, MTLTextureType1D(Array) or MTLTextureTypeTextureBuffer.
 Moreover, not all MTLPixelFormat are supported with lossy compression, verify that the MTLDevice's GPU family supports the lossy compression feature for the pixelFormat requested.
 Set allowGPUOptimizedContents to NO to opt out of both lossless and lossy compression; such textures do not benefit from either reduced bandwidth usage or reduced storage requirements, but have predictable CPU readback performance.
 */
@property (readwrite, nonatomic) MTLTextureCompressionType compressionType API_AVAILABLE(macos(12.5), ios(15.0));

/*!
 @property swizzle
 @abstract Channel swizzle to use when reading or sampling from the texture, the default value is MTLTextureSwizzleChannelsDefault.
 */
@property (readwrite, nonatomic) MTLTextureSwizzleChannels swizzle API_AVAILABLE(macos(10.15), ios(13.0));

@end

#endif // _METAL_MTLTEXTUREDESCRIPTOR_H_
