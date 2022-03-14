/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/std/typetraits/typetraits.h>

namespace AZStd
{
    // models the invocable concept
    template <class F, class... Args>
    /*concept*/ constexpr bool invocable = is_invocable_v<F, Args...>;

    // models the regular_invocable concept
    template <class F, class... Args>
    /*concept*/ constexpr bool regular_invocable = invocable<F, Args...>;
}
