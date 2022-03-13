/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <AzCore/RTTI/ReflectContext.h>
//cjh #include <AzCore/Serialization/SerializeContext.h>
#include "ComponentBus.h"

namespace AZ
{
    /*static*/ void EntityComponentIdPair::Reflect(AZ::ReflectContext* context)
    {
//cjh        AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(context);
//
//        if (serializeContext)
//        {
//            serializeContext->Class<EntityComponentIdPair>()
//                ->Field("EntityId", &EntityComponentIdPair::m_entityId)
//                ->Field("ComponentId", &EntityComponentIdPair::m_componentId)
//                ->Version(0);
//        }
    }
}
