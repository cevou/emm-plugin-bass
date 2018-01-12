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

#ifndef BASSDEVICE_H
#define BASSDEVICE_H

#include <QThread>
#include <audio/idevice.h>
#include <bass.h>

namespace Audio {
class IChannel;
} // namespace Audio

namespace Bass {

namespace Internal {

class BassDevice : public Audio::IDevice
{
public:
    BassDevice(int deviceId, BASS_DEVICEINFO deviceInfo);
    ~BassDevice();

    void init();
    QString name() override;
    int outputCount() override;
    Audio::IChannel *createChannel() override;

private:
    int m_deviceId;
    QThread m_bassThread;
    BASS_DEVICEINFO m_deviceInfo;
    bool m_initialized = false;
    int m_channelCount = 0;

private slots:
    void updateOutputCount(int count);
};

} // namespace Internal
} // namespace Audio

#endif // BASSDEVICE_H
