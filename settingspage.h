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

#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <settings/isettingspage.h>

namespace Bass {

namespace Internal {

namespace Ui {
class SettingsPage;
}

class SettingsPage : public Settings::ISettingsPage
{
    Q_OBJECT

public:
    SettingsPage();
    ~SettingsPage();

    QString id() const override;

    void load() override;
    void apply() override;

private:
    Ui::SettingsPage *m_ui;
};

} // namespace Internal
} // namespace Bass

#endif // SETTINGSPAGE_H
