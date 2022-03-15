/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/RTTI/TypeInfo.h>
#include <AzCore/std/containers/array.h>
#include <AzCore/std/function/invoke.h>
#include <AzCore/std/utils.h>
#include <AzCore/std/typetraits/is_same.h>
#include <AzCore/std/typetraits/void_t.h>
#include <tuple>
#include <AzCore/std/typetraits/conjunction.h>

namespace AZStd
{

}



// Adds typeinfo specialization for tuple type
namespace AZ
{
    AZ_TYPE_INFO_INTERNAL_SPECIALIZED_TEMPLATE_PREFIX_UUID(AZStd::tuple, "tuple", "{F99F9308-DC3E-4384-9341-89CBF1ABD51E}", AZ_TYPE_INFO_INTERNAL_TYPENAME_VARARGS);
}
