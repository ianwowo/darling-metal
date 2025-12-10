/*
 * This file is part of Darling.
 *
 * Copyright (C) 2022 Darling developers
 *
 * Darling is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Darling is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Darling.  If not, see <http://www.gnu.org/licenses/>.
 */

#import <Metal/MTLStageInputOutputDescriptor.h>
#import <Metal/MTLVertexDescriptor.h>
#import <Metal/stubs.h>

@implementation MTLAttributeDescriptor

#if DARLING_METAL_ENABLED

@synthesize format = _format;
@synthesize offset = _offset;
@synthesize bufferIndex = _bufferIndex;

- (id)copyWithZone:(NSZone *)zone
{
    NSLog(@"STUB: copyWithZone");
    return 0;
}

#else

MTL_UNSUPPORTED_CLASS

#endif

@end

// ----------------------------------------------------------------------------

@implementation MTLBufferLayoutDescriptor

@synthesize stride = _stride;
@synthesize stepFunction = _stepFunction;
@synthesize stepRate = _stepRate;

- (id)copyWithZone:(NSZone *)zone
{
    NSLog(@"STUB: copyWithZone");
    return 0;
}

@end

// ----------------------------------------------------------------------------

@implementation MTLStageInputOutputDescriptor

@synthesize layouts = _layouts;
@synthesize attributes = _attributes;
@synthesize indexType = _indexType;
@synthesize indexBufferIndex = _indexBufferIndex;

+ (MTLStageInputOutputDescriptor *)stageInputOutputDescriptor
{
    NSLog(@"STUB: stageInputOutputDescriptor");
    return 0;
}

- (id)copyWithZone:(NSZone *)zone
{
    NSLog(@"STUB: copyWithZone");
    return 0;
}

- (void)reset
{
    NSLog(@"STUB: reset");
}

@end

// ----------------------------------------------------------------------------

@implementation MTLBufferLayoutDescriptorArray

- (MTLBufferLayoutDescriptor *)objectAtIndexedSubscript:(NSUInteger)index
{
    NSLog(@"STUB: objectAtIndexedSubscript");
    return 0;
}
- (void)setObject:(nullable MTLBufferLayoutDescriptor *)bufferDesc atIndexedSubscript:(NSUInteger)index
{
    NSLog(@"STUB: setObject");
}

@end

// ----------------------------------------------------------------------------

@implementation MTLVertexAttributeDescriptor

@synthesize format = _format;
@synthesize offset = _offset;
@synthesize bufferIndex = _bufferIndex;

- (id)copyWithZone:(NSZone *)zone
{
    NSLog(@"STUB: copyWithZone");
    return 0;
}

@end

// ----------------------------------------------------------------------------

@implementation MTLVertexBufferLayoutDescriptor

@synthesize stride = _stride;
@synthesize stepFunction = _stepFunction;
@synthesize stepRate = _stepRate;

- (id)copyWithZone:(NSZone *)zone
{
    NSLog(@"STUB: copyWithZone");
    return 0;
}

@end

// ----------------------------------------------------------------------------


