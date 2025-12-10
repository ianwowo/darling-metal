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

#import <Metal/MTLCompileOptions.h>
#import <Foundation/NSMethodSignature.h>
#import <Foundation/NSInvocation.h>

@implementation MTLCompileOptions

#if DARLING_METAL_ENABLED

// Pre-processor options
@synthesize preprocessorMacros = _preprocessorMacros;
// Math intrinsics options
@synthesize fastMathEnabled = _fastMathEnabled;
@synthesize languageVersion = _languageVersion;
@synthesize libraryType = _libraryType;
@synthesize installName = _installName;
@synthesize libraries = _libraries;
@synthesize preserveInvariance = _preserveInvariance;
@synthesize optimizationLevel = _optimizationLevel;
@synthesize compileSymbolVisibility = _compileSymbolVisibility;
@synthesize allowReferencingUndefinedSymbols = _allowReferencingUndefinedSymbols;
@synthesize maxTotalThreadsPerThreadgroup = _maxTotalThreadsPerThreadgroup;

- (id)copyWithZone:(NSZone *)zone
{
    NSLog(@"STUB: copyWithZone");
    return 0;
}

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
