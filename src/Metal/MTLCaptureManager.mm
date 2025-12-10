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

#import <Metal/MTLCaptureManager.h>
#import <Foundation/NSMethodSignature.h>
#import <Foundation/NSInvocation.h>
#import <Metal/stubs.h>

@implementation MTLCaptureDescriptor

@synthesize captureObject = _captureObject;
@synthesize destination = _destination;
@synthesize outputURL = _outputURL;

- (id)copyWithZone:(NSZone *)zone
{
    NSLog(@"STUB: copyWithZone");
    return 0;
}

@end

@implementation MTLCaptureManager

#if DARLING_METAL_ENABLED

@synthesize defaultCaptureScope = _defaultCaptureScope;
@synthesize isCapturing = _isCapturing;

- (void)stopCapture
{
    NSLog(@"STUB: stopCapture");
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector
{
    return [NSMethodSignature signatureWithObjCTypes: "v@:"];
}

- (void)forwardInvocation:(NSInvocation *)anInvocation
{
    NSLog(@"Stub called: %@ in %@", NSStringFromSelector([anInvocation selector]), [self class]);
}

#else

MTL_UNSUPPORTED_CLASS

#endif

@end
