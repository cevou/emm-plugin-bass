/**************************************************************************
 * Event Music Machine
 * Copyright (C) 2014-2017 Christoph Kraemer
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 **************************************************************************/

#include <extensionsystem/pluginmanager.h>
#include <audio/devicemanager.h>
#include <settings/settingsmanager.h>
#include <settings/navigationtreeitem.h>

#include "bassplugin.h"
#include "bassdriver.h"
#include "settingsfactory.h"

using namespace Bass::Internal;

BassPlugin::BassPlugin()
{

}

BassPlugin::~BassPlugin()
{

}

bool BassPlugin::initialize(const QStringList &arguments, QString *errorMessage)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorMessage)

    Audio::DeviceManager::instance()->registerDriver(new BassDriver);

    Settings::NavigationTreeItem *settingsItem = Settings::SettingsManager::createNavigationNode("BASS", tr("BASS"));
    settingsItem->setFactory(new SettingsFactory());
    Settings::SettingsManager::navigationNode("AUDIO")->addChild(settingsItem);

    return true;
}

void BassPlugin::extensionsInitialized()
{

}

ExtensionSystem::IPlugin::ShutdownFlag BassPlugin::aboutToShutdown()
{
    return SynchronousShutdown;
}
