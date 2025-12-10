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

#ifndef _METAL_MTLSAMPLERDESCRIPTOR_H_
#define _METAL_MTLSAMPLERDESCRIPTOR_H_

#import <Foundation/Foundation.h>
#import <Metal/MTLTypes.h>
#import <Metal/MTLDefines.h>
#import <Metal/MTLDevice.h>
#import <Metal/MTLDepthStencilDescriptor.h>

typedef NS_ENUM(NSUInteger, MTLSamplerMinMagFilter) {
    MTLSamplerMinMagFilterNearest = 0,
    MTLSamplerMinMagFilterLinear = 1,
}; // API_AVAILABLE(macos(10.11), ios(8.0));

typedef NS_ENUM(NSUInteger, MTLSamplerMipFilter) {
    MTLSamplerMipFilterNotMipmapped = 0,
    MTLSamplerMipFilterNearest = 1,
    MTLSamplerMipFilterLinear = 2,
}; // API_AVAILABLE(macos(10.11), ios(8.0));


typedef NS_ENUM(NSUInteger, MTLSamplerAddressMode) {
    MTLSamplerAddressModeClampToEdge = 0,
    MTLSamplerAddressModeMirrorClampToEdge API_AVAILABLE(macos(10.11), ios(14.0)) = 1,
    MTLSamplerAddressModeRepeat = 2,
    MTLSamplerAddressModeMirrorRepeat = 3,
    MTLSamplerAddressModeClampToZero = 4,
    MTLSamplerAddressModeClampToBorderColor API_AVAILABLE(macos(10.12), ios(14.0)) = 5,
}; // API_AVAILABLE(macos(10.11), ios(8.0));


typedef NS_ENUM(NSUInteger, MTLSamplerBorderColor) {
    MTLSamplerBorderColorTransparentBlack = 0,  // {0,0,0,0}
    MTLSamplerBorderColorOpaqueBlack = 1,       // {0,0,0,1}
    MTLSamplerBorderColorOpaqueWhite = 2,       // {1,1,1,1}
}; // API_AVAILABLE(macos(10.12), ios(14.0));

@interface MTLSamplerDescriptor : NSObject
/*!
 @property minFilter
 @abstract Filter option for combining texels within a mipmap level the sample footprint is larger than a pixel (minification).
 @discussion The default value is MTLSamplerMinMagFilterNearest.
 */
@property (nonatomic) MTLSamplerMinMagFilter minFilter;

/*!
 @property magFilter
 @abstract Filter option for combining texels within a mipmap level the sample footprint is smaller than a pixel (magnification).
 @discussion The default value is MTLSamplerMinMagFilterNearest.
 */
@property (nonatomic) MTLSamplerMinMagFilter magFilter;

/*!
 @property mipFilter
 @abstract Filter options for filtering between two mipmap levels.
 @discussion The default value is MTLSamplerMipFilterNotMipmapped
 */
@property (nonatomic) MTLSamplerMipFilter mipFilter;

/*!
 @property maxAnisotropy
 @abstract The number of samples that can be taken to improve quality of sample footprints that are anisotropic.
 @discussion The default value is 1.
 */
@property (nonatomic) NSUInteger maxAnisotropy;

/*!
 @property sAddressMode
 @abstract Set the wrap mode for the S texture coordinate.  The default value is MTLSamplerAddressModeClampToEdge.
 */
@property (nonatomic) MTLSamplerAddressMode sAddressMode;

/*!
 @property tAddressMode
 @abstract Set the wrap mode for the T texture coordinate.  The default value is MTLSamplerAddressModeClampToEdge.
 */
@property (nonatomic) MTLSamplerAddressMode tAddressMode;

/*!
 @property rAddressMode
 @abstract Set the wrap mode for the R texture coordinate.  The default value is MTLSamplerAddressModeClampToEdge.
 */
@property (nonatomic) MTLSamplerAddressMode rAddressMode;

/*!
 @property borderColor
 @abstract Set the color for the MTLSamplerAddressMode to one of the predefined in the MTLSamplerBorderColor enum.
 */
@property (nonatomic) MTLSamplerBorderColor borderColor API_AVAILABLE(macos(10.12), ios(14.0));

/*!
 @property normalizedCoordinates.
 @abstract If YES, texture coordates are from 0 to 1.  If NO, texture coordinates are 0..width, 0..height.
 @discussion normalizedCoordinates defaults to YES.  Non-normalized coordinates should only be used with 1D and 2D textures with the ClampToEdge wrap mode, otherwise the results of sampling are undefined.
 */
@property (nonatomic) BOOL normalizedCoordinates;

/*!
 @property lodMinClamp
 @abstract The minimum level of detail that will be used when sampling from a texture.
 @discussion The default value of lodMinClamp is 0.0.  Clamp values are ignored for texture sample variants that specify an explicit level of detail.
 */
@property (nonatomic) float lodMinClamp;

/*!
 @property lodMaxClamp
 @abstract The maximum level of detail that will be used when sampling from a texture.
 @discussion The default value of lodMaxClamp is FLT_MAX.  Clamp values are ignored for texture sample variants that specify an explicit level of detail.
 */
@property (nonatomic) float lodMaxClamp;

/*!
 @property lodAverage
 @abstract If YES, an average level of detail will be used when sampling from a texture. If NO, no averaging is performed.
 @discussion lodAverage defaults to NO. This option is a performance hint. An implementation is free to ignore this property.
 */
@property (nonatomic) BOOL lodAverage API_AVAILABLE(ios(9.0), macos(11.0), macCatalyst(14.0));

/*!
 @property compareFunction
 @abstract Set the comparison function used when sampling shadow maps. The default value is MTLCompareFunctionNever.
 */
@property (nonatomic) MTLCompareFunction compareFunction API_AVAILABLE(macos(10.11), ios(9.0));

/*!
 @property supportArgumentBuffers
 @abstract true if the sampler can be used inside an argument buffer
*/
@property (nonatomic) BOOL supportArgumentBuffers API_AVAILABLE(macos(10.13), ios(11.0));

/*!
 @property label
 @abstract A string to help identify the created object.
 */
@property (nullable, copy, nonatomic) NSString *label;

@end

/*!
 @protocol MTLSamplerState
 @abstract An immutable collection of sampler state compiled for a single device.
 */
API_AVAILABLE(macos(10.11), ios(8.0))
@protocol MTLSamplerState <NSObject>

/*!
 @property label
 @abstract A string to help identify this object.
 */
@property (nullable, readonly) NSString *label;

/*!
 @property device
 @abstract The device this resource was created against.  This resource can only be used with this device.
 */
@property (readonly) id <MTLDevice> device;

/*!
 @property gpuResourceID
 @abstract Handle of the GPU resource suitable for storing in an Argument Buffer
 */
@property (readonly) MTLResourceID gpuResourceID API_AVAILABLE(macos(13.0), ios(16.0));
@end

#endif // _METAL_MTLSAMPLERDESCRIPTOR_H_
