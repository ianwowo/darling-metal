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

#import <Metal/MTLTextureDescriptor.h>
#import <Foundation/NSMethodSignature.h>
#import <Foundation/NSInvocation.h>

@implementation MTLTextureDescriptor

#if DARLING_METAL_ENABLED
- (id)copyWithZone:(NSZone *)zone
{
    NSLog(@"STUB: copyWithZone");
    return 0;
}

+ (MTLTextureDescriptor*)texture2DDescriptorWithPixelFormat:(MTLPixelFormat)pixelFormat width:(NSUInteger)width height:(NSUInteger)height mipmapped:(BOOL)mipmapped
{
    NSLog(@"STUB: texture2DDescriptorWithPixelFormat");
    return 0;
}

+ (MTLTextureDescriptor*)textureCubeDescriptorWithPixelFormat:(MTLPixelFormat)pixelFormat size:(NSUInteger)size mipmapped:(BOOL)mipmapped
{
    NSLog(@"STUB: textureCubeDescriptorWithPixelFormat");
    return 0;
}

+ (MTLTextureDescriptor*)textureBufferDescriptorWithPixelFormat:(MTLPixelFormat)pixelFormat
                                                          width:(NSUInteger)width
                                                resourceOptions:(MTLResourceOptions)resourceOptions
                                                          usage:(MTLTextureUsage)usage API_AVAILABLE(macos(10.14), ios(12.0))
{
    NSLog(@"STUB: textureBufferDescriptorWithPixelFormat");
    return 0;
}

@synthesize textureType = _textureType;
@synthesize pixelFormat = _pixelFormat;
@synthesize width = _width;
@synthesize height = _height;
@synthesize depth = _depth;
@synthesize mipmapLevelCount = _mipmapLevelCount;
@synthesize sampleCount = _sampleCount;
@synthesize arrayLength = _arrayLength;
@synthesize resourceOptions = _resourceOptions;
@synthesize cpuCacheMode = _cpuCacheMode;
@synthesize storageMode = _storageMode;
@synthesize hazardTrackingMode = _hazardTrackingMode;
@synthesize usage = _usage;
@synthesize allowGPUOptimizedContents = _allowGPUOptimizedContents;
@synthesize compressionType = _compressionType;
@synthesize swizzle = _swizzle;

- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector
{
    return [NSMethodSignature signatureWithObjCTypes: "v@:"];
}

- (void)forwardInvocation:(NSInvocation *)anInvocation
{
    NSLog(@"Stub called: %@ in %@", NSStringFromSelector([anInvocation selector]), [self class]);
}

#endif

@end
