/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#ifndef AZSTD_RATIO_H
#define AZSTD_RATIO_H

#include <AzCore/std/base.h>
#include <AzCore/std/typetraits/integral_constant.h>

#include <cstdlib>
#include <climits>
#include <limits>

// Fix for windows without NO_MIN_MAX define, or any other abuse of such basic keywords.
#if defined(AZ_COMPILER_MSVC)
#   ifdef min
#       pragma push_macro("min")
#       undef min
#       define AZ_WINDOWS_MIN_PUSHED
#   endif
#   ifdef max
#       pragma push_macro("max")
#       undef max
#       define AZ_WINDOWS_MAX_PUSHED
#   endif
#endif

namespace AZStd
{
}

#ifdef AZ_WINDOWS_MIN_PUSHED
#   pragma pop_macro("min")
#   undef AZ_WINDOWS_MIN_PUSHED
#endif
#ifdef AZ_WINDOWS_MAX_PUSHED
#   pragma pop_macro("max")
#   undef AZ_WINDOWS_MAX_PUSHED
#endif

#endif // AZSTD_RATIO_H
#pragma once


