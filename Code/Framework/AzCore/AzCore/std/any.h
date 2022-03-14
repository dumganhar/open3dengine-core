/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <AzCore/Casting/numeric_cast.h>
#include <any>

namespace AZStd
{
using std::any;
using std::any_cast;
using std::make_any;

    /**
     * Extension: Converts an any to a convertible numeric type (see aznumeric_cast)
     *
     * \param operand   The any to cast
     * \param result    The variable to assign the result into if cast succeeds
     *
     * \returns true if conversion is successful, false if unsuccessful
     */
    template <typename ValueType, typename = enable_if_t<std::numeric_limits<ValueType>::is_specialized>>
    bool any_numeric_cast(const any* operand, ValueType& result)
    {
        if (!operand || operand->empty())
        {
            return false;
        }

        // Checks if operand is Type, and if so aznumeric_cast's from Type to ValueType
#define CHECK_TYPE(Type) if (operand->is<Type>()) { result = aznumeric_cast<ValueType>(*any_cast<Type>(operand)); }

        // Test if operand is of type ValueType
        if (auto value = any_cast<ValueType>(operand))
        {
            result = *value;
        }
        else CHECK_TYPE(char)
        else CHECK_TYPE(short)
        else CHECK_TYPE(int)
        else CHECK_TYPE(long)
        else CHECK_TYPE(AZ::s64)
        else CHECK_TYPE(unsigned char)
        else CHECK_TYPE(unsigned short)
        else CHECK_TYPE(unsigned int)
        else CHECK_TYPE(unsigned long)
        else CHECK_TYPE(AZ::u64)
        else CHECK_TYPE(float)
        else CHECK_TYPE(double)
        else
        {
            return false;
        }

        return true;

#undef CHECK_TYPE
    }
}
