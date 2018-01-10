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

#include <QSettings>
#include <extensionsystem/pluginmanager.h>

#include "settingspage.h"
#include "ui_settingspage.h"

using namespace Bass::Internal;

SettingsPage::SettingsPage() :
    Settings::ISettingsPage(),
    m_ui(new Ui::SettingsPage)
{
    m_ui->setupUi(this);
}

SettingsPage::~SettingsPage()
{
    delete m_ui;
}

QString SettingsPage::id() const
{
    return "BassSettings";
}

void SettingsPage::apply()
{
    QSettings *settings = ExtensionSystem::PluginManager::instance()->settings();
    settings->beginGroup("bass");
    settings->setValue("buffer", m_ui->bufferSpinBox->value());
    settings->endGroup();
}

void SettingsPage::load()
{
    QSettings *settings = ExtensionSystem::PluginManager::instance()->settings();
    settings->beginGroup("bass");
    m_ui->bufferSpinBox->setValue(settings->value("buffer", 500).toInt());
    settings->endGroup();
}
