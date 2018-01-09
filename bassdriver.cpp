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

#include <bass.h>

#include "bassdriver.h"
#include "bassdevice.h"

using namespace Bass::Internal;

BassDriver::BassDriver() : Audio::IDriver()
{
    BASS_DEVICEINFO info;
    for (int a = 1; BASS_GetDeviceInfo(a, &info); a++) {
        if (info.flags & BASS_DEVICE_ENABLED) {
            m_devices.append(new BassDevice(a, info));
        }
    }
}

QString BassDriver::id() const
{
    return "bass";
}

QString BassDriver::name() const
{
    return "BASS";
}

QStringList BassDriver::supportedMimeTypes() const
{

    QStringList mimeTypes;
    mimeTypes << "audio/mpeg" << "audio/x-wav" << "audio/ogg" << "audio/x-aiff";
    return mimeTypes;
}
