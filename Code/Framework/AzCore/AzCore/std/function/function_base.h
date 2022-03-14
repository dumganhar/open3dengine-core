/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
// Based on boost 1.39.0

#ifndef AZSTD_FUNCTION_BASE_HEADER
#define AZSTD_FUNCTION_BASE_HEADER

#include <functional>
#include <AzCore/std/base.h>
#include <AzCore/std/utils.h>
#include <AzCore/std/function/function_fwd.h>
#include <AzCore/std/typetraits/type_id.h>
#include <AzCore/std/typetraits/alignment_of.h>
#include <AzCore/std/typetraits/is_member_pointer.h>
#include <AzCore/std/typetraits/is_const.h>
#include <AzCore/std/typetraits/remove_cvref.h>
#include <AzCore/std/typetraits/is_volatile.h>
#include <AzCore/std/createdestroy.h>

#define AZSTD_FUNCTION_TARGET_FIX(x)
#define AZSTD_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, Type)  AZStd::enable_if_t<!std::is_integral_v<Functor> && !std::is_null_pointer_v<Functor>, Type>


#undef AZSTD_FUNCTION_ENABLE_IF_NOT_INTEGRAL
//#undef aztypeid
//#undef aztypeid_cmp

#endif // AZSTD_FUNCTION_BASE_HEADER
#pragma once
