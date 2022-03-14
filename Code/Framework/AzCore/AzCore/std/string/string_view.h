/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <string_view>

namespace AZStd
{
    using std::basic_string_view;
    using string_view = basic_string_view<char>;
    using wstring_view = basic_string_view<wchar_t>;


    inline namespace literals
    {
        inline namespace string_view_literals
        {
            constexpr string_view operator "" _sv(const char* str, size_t len) noexcept
            {
                return string_view{ str, len };
            }

            constexpr wstring_view operator "" _sv(const wchar_t* str, size_t len) noexcept
            {
                return wstring_view{ str, len };
            }
        }
    }

    /// For string hashing we are using FNV-1a algorithm 64 bit version.
    template<class RandomAccessIterator>
    constexpr size_t hash_string(RandomAccessIterator first, size_t length)
    {
        size_t hash = 14695981039346656037ULL;
        constexpr size_t fnvPrime = 1099511628211ULL;

        const RandomAccessIterator last(first + length);
        for (; first != last; ++first)
        {
            hash ^= static_cast<size_t>(*first);
            hash *= fnvPrime;
        }
        return hash;
    }

} // namespace AZStd

//cjh namespace AZStd::ranges
//{
//    template <class Element, class Traits>
//    inline constexpr bool enable_borrowed_range<basic_string_view<Element, Traits>> = true;
//
//    template <class Element, class Traits>
//    inline constexpr bool enable_view<basic_string_view<Element, Traits>> = true;
//}

//! Use this macro to simplify safe printing of a string_view which may not be null-terminated.
//! Example: AZStd::string::format("Safely formatted: %.*s", AZ_STRING_ARG(myString));
#define AZ_STRING_ARG(str) aznumeric_cast<int>(str.size()), str.data()

//! Can be used with AZ_STRING_ARG for convenience, rather than manually including "%.*s" in format strings
//! Example: AZStd::string::format("Safely formatted: " AZ_STRING_FORMAT, AZ_STRING_ARG(myString));
#define AZ_STRING_FORMAT "%.*s"
