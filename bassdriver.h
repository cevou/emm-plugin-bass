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

#ifndef BASSDRIVER_H
#define BASSDRIVER_H

#include <audio/idriver.h>

namespace Bass {

namespace Internal {

class BassDriver : public Audio::IDriver
{
    Q_OBJECT
public:
    BassDriver();

    QString id() const override;
    QString name() const override;
    QStringList supportedMimeTypes() const override;
};

} // namespace Internal
} // namespace Bass

#endif // BASSDRIVER_H
