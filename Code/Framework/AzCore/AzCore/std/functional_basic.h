/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <AzCore/std/base.h>
#include <AzCore/std/typetraits/void_t.h>
#include <AzCore/std/utils.h>

namespace AZStd
{

namespace Internal
{
    // The second template parameter is to the template parameter of the operator function that called is_transparent to to trigger SFINAE
    // error instead of a hard error
    // i.e
    // template<typename ComparableToKey>
    // node_ptr_type DoUpperBound(const ComparableToKey& key, Internal::is_transparent<Compare>::value) const
    // will not cause a substitution failure if ComparableToKey is not used as part of the is_transparent template and therefore will cause a hard error
    //
    // template<typename ComparableToKey>
    // node_ptr_type DoUpperBound(const ComparableToKey& key, Internal::is_transparent<Compare, ComparableToKey>::value) const
    // will cause a substitution error in this case if the Compare function is missing the is_transparent type alias and therefore can proceed
    // to use the next template candidate
    template <class T, class Unused, class = void>
    struct is_transparent
        : false_type {};

    template <class T, class Unused>
    struct is_transparent<T, Unused, void_t<typename T::is_transparent>>
        : true_type {};
}

}
