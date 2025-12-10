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

#ifndef _METAL_MTLSTENCILDESCRIPTOR_H_
#define _METAL_MTLSTENCILDESCRIPTOR_H_

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, MTLCompareFunction) {
    MTLCompareFunctionNever = 0,
    MTLCompareFunctionLess = 1,
    MTLCompareFunctionEqual = 2,
    MTLCompareFunctionLessEqual = 3,
    MTLCompareFunctionGreater = 4,
    MTLCompareFunctionNotEqual = 5,
    MTLCompareFunctionGreaterEqual = 6,
    MTLCompareFunctionAlways = 7,
};// API_AVAILABLE(macos(10.11), ios(8.0));

typedef NS_ENUM(NSUInteger, MTLStencilOperation) {
    MTLStencilOperationKeep = 0,
    MTLStencilOperationZero = 1,
    MTLStencilOperationReplace = 2,
    MTLStencilOperationIncrementClamp = 3,
    MTLStencilOperationDecrementClamp = 4,
    MTLStencilOperationInvert = 5,
    MTLStencilOperationIncrementWrap = 6,
    MTLStencilOperationDecrementWrap = 7,
};// API_AVAILABLE(macos(10.11), ios(8.0));


//MTL_EXPORT //API_AVAILABLE(macos(10.11), ios(8.0))
@interface MTLStencilDescriptor : NSObject <NSCopying>

@property (nonatomic) MTLCompareFunction stencilCompareFunction;
@property (nonatomic) MTLStencilOperation stencilFailureOperation;
@property (nonatomic) MTLStencilOperation depthFailureOperation;
@property (nonatomic) MTLStencilOperation depthStencilPassOperation;
@property (nonatomic) uint32_t readMask;
@property (nonatomic) uint32_t writeMask;

@end

#endif // _METAL_MTLSTENCILDESCRIPTOR_H_
