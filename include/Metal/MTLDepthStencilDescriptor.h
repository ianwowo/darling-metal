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

#ifndef _METAL_MTLDEPTHSTENCILDESCRIPTOR_H_
#define _METAL_MTLDEPTHSTENCILDESCRIPTOR_H_

#import <Foundation/Foundation.h>
#import <Metal/MTLDefines.h>
#import <Metal/MTLStencilDescriptor.h>

MTL_EXPORT //API_AVAILABLE(macos(10.11), ios(8.0))
@interface MTLDepthStencilDescriptor : NSObject <NSCopying>

@property (nonatomic) MTLCompareFunction depthCompareFunction;
@property (nonatomic, getter=isDepthWriteEnabled) BOOL depthWriteEnabled;
@property (copy, nonatomic, null_resettable) MTLStencilDescriptor *frontFaceStencil;
@property (copy, nonatomic, null_resettable) MTLStencilDescriptor *backFaceStencil;
@property (nullable, copy, nonatomic) NSString *label;

@end

#endif // _METAL_MTLDEPTHSTENCILDESCRIPTOR_H_
