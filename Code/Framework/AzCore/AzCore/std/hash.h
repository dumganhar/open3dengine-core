/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#ifndef AZSTD_HASH_H
#define AZSTD_HASH_H 1

#include <AzCore/std/base.h>

#include <limits>
#include <functional>
//#include <AzCore/std/function/invoke.h>
//#include <AzCore/std/utils.h>
//#include <AzCore/std/typetraits/conjunction.h>
//#include <AzCore/std/typetraits/disjunction.h>
//#include <AzCore/std/typetraits/is_abstract.h>
//#include <AzCore/std/typetraits/negation.h>
//#include <AzCore/std/typetraits/remove_cv.h>
//
//#include "typetraits/has_member_function.h"
//#include "typetraits/is_abstract.h"

namespace AZStd
{

template <class T>
constexpr void hash_combine(AZStd::size_t& seed, T const& v)
{
    hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <class T1, class T2, class... RestTypes>
constexpr void hash_combine(AZStd::size_t& seed, const T1& firstElement, const T2& secondElement, const RestTypes&... restElements)
{
    hash_combine(seed, firstElement);
    hash_combine(seed, secondElement, restElements...);
}

template <class It>
constexpr AZStd::size_t hash_range(It first, It last)
{
    AZStd::size_t seed = 0;
    for (; first != last; ++first)
    {
        hash_combine(seed, *first);
    }
    return seed;
}

template <class It>
constexpr void hash_range(AZStd::size_t& seed, It first, It last)
{
    for (; first != last; ++first)
    {
        hash_combine(seed, *first);
    }
}

}

#endif // AZSTD_HASH_H
#pragma once
