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

#ifndef _METAL_MTLCOMPILEOPTIONS_H_
#define _METAL_MTLCOMPILEOPTIONS_H_

#import <Foundation/Foundation.h>
#import <Metal/MTLLibrary.h>

typedef NS_ENUM(NSUInteger, MTLLanguageVersion) {
    MTLLanguageVersion1_0 API_DEPRECATED("Use a newer language standard", ios(9.0, 16.0)) API_UNAVAILABLE(macos, macCatalyst) = (1 << 16),
    MTLLanguageVersion1_1 API_AVAILABLE(macos(10.11), ios(9.0)) = (1 << 16) + 1,
    MTLLanguageVersion1_2 API_AVAILABLE(macos(10.12), ios(10.0)) = (1 << 16) + 2,
    MTLLanguageVersion2_0 API_AVAILABLE(macos(10.13), ios(11.0)) = (2 << 16),
    MTLLanguageVersion2_1 API_AVAILABLE(macos(10.14), ios(12.0)) = (2 << 16) + 1,
    MTLLanguageVersion2_2 API_AVAILABLE(macos(10.15), ios(13.0)) = (2 << 16) + 2,
    MTLLanguageVersion2_3 API_AVAILABLE(macos(11.0), ios(14.0)) = (2 << 16) + 3,
    MTLLanguageVersion2_4 API_AVAILABLE(macos(12.0), ios(15.0)) = (2 << 16) + 4,
    MTLLanguageVersion3_0 API_AVAILABLE(macos(13.0), ios(16.0)) =
    (3 << 16) + 0,
    MTLLanguageVersion3_1 API_AVAILABLE(macos(14.0), ios(17.0)) =
    (3 << 16) + 1,
};// API_AVAILABLE(macos(10.11), ios(9.0));

typedef NS_ENUM(NSInteger, MTLLibraryOptimizationLevel)
{
    MTLLibraryOptimizationLevelDefault = 0,
    MTLLibraryOptimizationLevelSize = 1,
}; // API_AVAILABLE(macos(13.0), ios(16.0));

typedef NS_ENUM(NSInteger, MTLCompileSymbolVisibility)
{
    MTLCompileSymbolVisibilityDefault = 0,
    MTLCompileSymbolVisibilityHidden = 1,
}; // API_AVAILABLE(macos(13.3), ios(16.4));

MTL_EXPORT //API_AVAILABLE(macos(10.11), ios(8.0))
@interface MTLCompileOptions : NSObject <NSCopying>

// Pre-processor options
@property (nullable, readwrite, copy, nonatomic) NSDictionary <NSString *, NSObject *> *preprocessorMacros;

// Math intrinsics options
@property (readwrite, nonatomic) BOOL fastMathEnabled;
@property (readwrite, nonatomic) MTLLanguageVersion languageVersion;// API_AVAILABLE(macos(10.11), ios(9.0));
@property (readwrite, nonatomic) MTLLibraryType libraryType;// API_AVAILABLE(macos(11.0), ios(14.0));
@property (readwrite, nullable, copy, nonatomic) NSString *installName;// API_AVAILABLE(macos(11.0), ios(14.0));
@property (readwrite, nullable, copy, nonatomic) NSArray<id<MTLDynamicLibrary>> *libraries;// API_AVAILABLE(macos(11.0), ios(14.0));
@property (readwrite, nonatomic) BOOL preserveInvariance;// API_AVAILABLE(macos(11.0), macCatalyst(14.0), ios(14.0));
@property (readwrite, nonatomic) MTLLibraryOptimizationLevel optimizationLevel;// API_AVAILABLE(macos(13.0), ios(16.0));
@property (readwrite, nonatomic) MTLCompileSymbolVisibility compileSymbolVisibility;// API_AVAILABLE(macos(13.3), ios(16.4));
@property (readwrite, nonatomic) BOOL allowReferencingUndefinedSymbols;// API_AVAILABLE(macos(13.3), ios(16.4));
@property (readwrite, nonatomic) NSUInteger maxTotalThreadsPerThreadgroup;// API_AVAILABLE(macos(13.3), ios(16.4));

@end

#endif // _METAL_MTLCOMPILEOPTIONS_H_
