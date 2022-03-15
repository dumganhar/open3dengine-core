/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#ifndef AZSTD_SMART_PTR_SHARED_PTR
#define AZSTD_SMART_PTR_SHARED_PTR

//////////////////////////////////////////////////////////////////////////
// Standard C++0x 20.8.10.2, which was drafted from boost.
// We use as a base boost 1.46 implementation
//
// IMPORTANT:
// Even though we do follow the standard 100%, there are some important internal
// differences (from the boost implementation) and some important notes on
// how we use shared_ptr.
// - We never call new ... all allocation are made using the allocators.
// - By default (when no user allocator is provided) we use AZStd::allocator
//     which keeps the same behavior as all containers.
// - Allocators are passed at construction time; this keeps the shared_ptr<T> as is in the
//     standard and keeps the templated type simple.
// - As with containers in libs, you should always use lib allocators and you should never
//     use the default one. This is because we work in memory managed environments and the lib
//     users have the right to choose where to allocate memory from! \ref AZStd::allocator
// \ref Containers
//

//
//  shared_ptr.hpp
//
//  (C) Copyright Greg Colvin and Beman Dawes 1998, 1999.
//  Copyright (c) 2001-2008 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  See http://www.boost.org/libs/smart_ptr/shared_ptr.htm for documentation.
//

#include <AzCore/std/allocator.h>
#include <AzCore/std/smart_ptr/unique_ptr.h>
#include <AzCore/std/smart_ptr/shared_count.h>
#include <AzCore/std/smart_ptr/sp_convertible.h>
#include <AzCore/std/utils.h>
#include <AzCore/RTTI/RTTI.h>

#include <memory>

namespace AZStd
{

} // namespace AZStd

#endif  // #ifndef AZSTD_SMART_PTR_SHARED_PTR
#pragma once
