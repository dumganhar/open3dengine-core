/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <AzCore/std/concepts/concepts_assignable.h>
#include <AzCore/std/concepts/concepts_constructible.h>
#include <AzCore/std/concepts/concepts_copyable.h>
#include <AzCore/std/concepts/concepts_movable.h>
#include <AzCore/std/function/invoke.h>
#include <AzCore/std/iterator/iterator_primitives.h>
#include <AzCore/std/ranges/swap.h>
#include <AzCore/std/ranges/iter_move.h>
#include <AzCore/std/ranges/iter_swap.h>

#include <AzCore/std/typetraits/add_pointer.h>
#include <AzCore/std/typetraits/common_reference.h>
#include <AzCore/std/typetraits/is_array.h>
#include <AzCore/std/typetraits/is_class.h>
#include <AzCore/std/typetraits/is_enum.h>
#include <AzCore/std/typetraits/is_function.h>
#include <AzCore/std/typetraits/is_integral.h>
#include <AzCore/std/typetraits/is_object.h>
#include <AzCore/std/typetraits/is_same.h>
#include <AzCore/std/typetraits/is_signed.h>
#include <AzCore/std/typetraits/is_void.h>
#include <AzCore/std/typetraits/remove_cvref.h>
#include <AzCore/std/typetraits/void_t.h>
#include <AzCore/std/utility/declval.h>
#include <AzCore/std/utility/move.h>

#include <concepts>

namespace AZStd
{

}
