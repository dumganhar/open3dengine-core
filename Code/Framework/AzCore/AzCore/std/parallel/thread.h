/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <AzCore/std/parallel/config.h>
#include <thread>

#define AFFINITY_MASK_ALL          AZ_TRAIT_THREAD_AFFINITY_MASK_ALLTHREADS
#define AFFINITY_MASK_MAINTHREAD   AZ_TRAIT_THREAD_AFFINITY_MASK_MAINTHREAD
#define AFFINITY_MASK_RENDERTHREAD AZ_TRAIT_THREAD_AFFINITY_MASK_RENDERTHREAD
#define AFFINITY_MASK_USERTHREADS  AZ_TRAIT_THREAD_AFFINITY_MASK_WORKERTHREADS

namespace AZStd
{

}



