/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/std/config.h>

namespace AZStd
{
    template<class T>
    /*concept*/ constexpr bool destructible = is_nothrow_destructible_v<T>;
}
