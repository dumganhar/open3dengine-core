/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#ifndef AZSTD_LOCK_H
#define AZSTD_LOCK_H 1

#include <AzCore/std/parallel/config.h>
#include <AzCore/std/createdestroy.h>
#include <AzCore/std/parallel/thread.h>

namespace AZStd
{
template <class Mutex>
class shared_lock
{
public:
    typedef Mutex mutex_type;
    AZ_FORCE_INLINE explicit shared_lock(mutex_type& mutex)
        : m_mutex(mutex)
    {
        m_mutex.lock_shared();
    }
    AZ_FORCE_INLINE shared_lock(mutex_type& mutex, adopt_lock_t)
        : m_mutex(mutex) {}
    AZ_FORCE_INLINE ~shared_lock() { m_mutex.unlock_shared(); }

private:
    AZ_FORCE_INLINE shared_lock(shared_lock const&);
    AZ_FORCE_INLINE shared_lock& operator=(shared_lock const&);
    mutex_type& m_mutex; // exposition only
};
}

#endif // AZSTD_LOCK_H
#pragma once
