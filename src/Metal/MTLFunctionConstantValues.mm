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

#import <Metal/MTLFunctionConstantValues.h>
#import <Metal/stubs.h>

@implementation MTLFunctionConstantValues

- (id)copyWithZone:(NSZone *)zone
{
    NSLog(@"STUB: copyWithZone");
    return 0;
}

- (void)setConstantValue:(const void *)value type:(MTLDataType)type atIndex:(NSUInteger)index
{
    NSLog(@"STUB: setConstantValue");
}

- (void)setConstantValues:(const void *)values type:(MTLDataType)type withRange:(NSRange)range
{
    NSLog(@"STUB: setConstantValues");
}

- (void)setConstantValue:(const void *)value type:(MTLDataType)type withName:(NSString *)name
{
    NSLog(@"STUB: setConstantValue");
}

- (void)reset
{
    NSLog(@"STUB: reset");
}

@end
