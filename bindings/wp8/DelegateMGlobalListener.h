/**
* @file DelegateMGlobalListener.h
* @brief Delegate to get information about global events.
*
* (c) 2013-2018 by Mega Limited, Auckland, New Zealand
*
* This file is part of the MEGA SDK - Client Access Engine.
*
* Applications using the MEGA API must present a valid application key
* and comply with the the rules set forth in the Terms of Service.
*
* The MEGA SDK is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* @copyright Simplified (2-clause) BSD License.
*
* You should have received a copy of the license along with this
* program.
*/

#pragma once

#include "MegaSDK.h"
#include "MGlobalListenerInterface.h"

#include "megaapi.h"

namespace mega
{
    ref class MegaSDK;

    using namespace Windows::Foundation;
    using Platform::String;

    private class DelegateMGlobalListener : public MegaGlobalListener
    {
    public:
        DelegateMGlobalListener(MegaSDK^ megaSDK, MGlobalListenerInterface^ listener);
        MGlobalListenerInterface^ getUserListener();

        void onUsersUpdate(MegaApi* api, MegaUserList *users);
        void onUserAlertsUpdate(MegaApi* api, MegaUserAlertList *alerts);
        void onNodesUpdate(MegaApi* api, MegaNodeList *nodes);
        void onAccountUpdate(MegaApi* api);
        void onContactRequestsUpdate(MegaApi* api, MegaContactRequestList* requests);
        void onReloadNeeded(MegaApi* api);
        void onEvent(MegaApi* api, MegaEvent* ev);

    private:
        MegaSDK^ megaSDK;
        MGlobalListenerInterface^ listener;
    };
}