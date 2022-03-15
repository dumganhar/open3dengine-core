/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <AzCore/std/ranges/ranges.h>
#include <AzCore/std/createdestroy.h>
#include <AzCore/std/iterator.h>
#include <AzCore/std/limits.h>

#include <string_view>

namespace AZStd
{
namespace StringInternal
{
    constexpr size_t min_size(size_t left, size_t right) { return (left < right) ? left : right; }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT char_find(const CharT* s, size_t count, CharT ch, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        const CharT* foundIter = Traits::find(s, count, ch);
        return foundIter ? AZStd::distance(s, foundIter) : npos;
    }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT find(const CharT* data, SizeT size, const CharT* ptr, SizeT offset, SizeT count, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        if (offset > size || count > size)
        {
            return npos;
        }
        if (count == 0)
        {
            return offset; // count == 0 means that highest index should be returned
        }

        size_t searchRange = size - offset;
        for (size_t searchIndex = offset; searchIndex < size;)
        {
            size_t charFindIndex = char_find<Traits>(&data[searchIndex], searchRange, *ptr, npos);
            if (charFindIndex == npos)
            {
                return npos;
            }
            size_t foundIndex = searchIndex + charFindIndex;
            if (foundIndex + count > size)
            {
                return npos; // the rest of the string doesnt fit in the remainder of the data buffer
            }
            if (Traits::compare(&data[foundIndex], ptr, count) == 0)
            {
                return foundIndex;
            }

            searchRange = size - (foundIndex + 1);
            searchIndex = foundIndex + 1;
        }

        return npos;
    }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT find(const CharT* data, SizeT size, CharT c, SizeT offset, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        if (offset > size)
        {
            return npos;
        }

        size_t charFindIndex = char_find<Traits>(&data[offset], size - offset, c, npos);
        return charFindIndex != npos ? offset + charFindIndex : npos;
    }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT rfind(const CharT* data, SizeT size, const CharT* ptr, SizeT offset, SizeT count, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        if (size == 0 || count > size)
        {
            return npos;
        }

        if (count == 0)
        {
            return offset > size ? size : offset; // count == 0 means that highest index should be returned
        }

        // Add one to offset so that for loop condition can check against 0 as the breakout condition
        size_t lastIndex = StringInternal::min_size(offset, size - count) + 1;

        for (; lastIndex; --lastIndex)
        {
            if (Traits::eq(*ptr, data[lastIndex - 1]) && Traits::compare(ptr, &data[lastIndex - 1], count) == 0)
            {
                return lastIndex - 1;
            }
        }

        return npos;
    }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT rfind(const CharT* data, SizeT size, CharT c, SizeT offset, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        if (size == 0)
        {
            return npos;
        }

        // Add one to offset so that for loop condition can check against 0 as the breakout condition
        size_t lastIndex = offset > size ? size : offset + 1;

        for (; lastIndex; --lastIndex)
        {
            if (Traits::eq(c, data[lastIndex - 1]))
            {
                return lastIndex - 1;
            }
        }

        return npos;
    }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT find_first_of(const CharT* data, SizeT size, const CharT* ptr, SizeT offset, SizeT count, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        if (size == 0)
        {
            return npos;
        }

        if (count == 0)
        {
            return npos; // count == 0 means that the set of valid entries is empty
        }

        for (size_t firstIndex = offset; firstIndex < size; ++firstIndex)
        {
            size_t charFindIndex = char_find<Traits>(ptr, count, data[firstIndex], npos);
            if (charFindIndex != npos)
            {
                return firstIndex;
            }
        }
        return npos;
    }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT find_last_of(const CharT* data, SizeT size, const CharT* ptr, SizeT offset, SizeT count, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        if (size == 0)
        {
            return npos;
        }

        if (count == 0)
        {
            return npos; // count == 0 means that the set of valid entries is empty
        }

        // Add one to offset so that for loop condition can against 0 as the breakout condition
        size_t lastIndex = offset > size ? size : offset + 1;
        for (; lastIndex; --lastIndex)
        {
            size_t charFindIndex = char_find<Traits>(ptr, count, data[lastIndex - 1], npos);
            if (charFindIndex != npos)
            {
                return lastIndex - 1;
            }
        }

        return npos;
    }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT find_first_not_of(const CharT* data, SizeT size, const CharT* ptr, SizeT offset, SizeT count, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        if (size == 0)
        {
            return npos;
        }

        if (count == 0)
        {
            return offset; // count == 0 means that the every character is part of the set of valid entries
        }

        for (size_t firstIndex = offset; firstIndex < size; ++firstIndex)
        {
            size_t charFindIndex = char_find<Traits>(ptr, count, data[firstIndex], npos);
            if (charFindIndex == npos)
            {
                return firstIndex;
            }
        }
        return npos;
    }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT find_first_not_of(const CharT* data, SizeT size, CharT c, SizeT offset, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        if (size == 0)
        {
            return npos;
        }

        for (size_t firstIndex = offset; firstIndex < size; ++firstIndex)
        {
            if (!Traits::eq(c, data[firstIndex]))
            {
                return firstIndex;
            }
        }
        return npos;
    }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT find_last_not_of(const CharT* data, SizeT size, const CharT* ptr, SizeT offset, SizeT count, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        if (size == 0)
        {
            return npos;
        }

        // Add one to offset so that for loop condition can check against 0 as the breakout condition
        size_t lastIndex = offset > size ? size : offset + 1;
        if (count == 0)
        {
            return lastIndex - 1; // count == 0 means that the every character is part of the set of valid entries
        }

        for (; lastIndex; --lastIndex)
        {
            size_t charFindIndex = char_find<Traits>(ptr, count, data[lastIndex - 1], npos);
            if (charFindIndex == npos)
            {
                return lastIndex - 1;
            }
        }

        return npos;
    }

    template<class Traits, class CharT, class SizeT>
    constexpr SizeT find_last_not_of(const CharT* data, SizeT size, CharT c, SizeT offset, SizeT npos = static_cast<SizeT>(-1)) noexcept
    {
        if (size == 0)
        {
            return npos;
        }

        // Add one to offset so that for loop condition can against 0 as the breakout condition
        size_t lastIndex = offset > size ? size : offset + 1;
        for (; lastIndex; --lastIndex)
        {
            if (!Traits::eq(c, data[lastIndex - 1]))
            {
                return lastIndex - 1;
            }
        }
        return npos;
    }
}

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

template <typename It, typename End>
constexpr string_view make_string_view(It first, End last) {
    return string_view{} ;//TODO(cjh) AZStd::to_address(first), AZStd::to_address(last) - AZStd::to_address(first)};
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
//! Example: AZStd::format_string("Safely formatted: %.*s", AZ_STRING_ARG(myString));
#define AZ_STRING_ARG(str) aznumeric_cast<int>(str.size()), str.data()

//! Can be used with AZ_STRING_ARG for convenience, rather than manually including "%.*s" in format strings
//! Example: AZStd::format_string("Safely formatted: " AZ_STRING_FORMAT, AZ_STRING_ARG(myString));
#define AZ_STRING_FORMAT "%.*s"
