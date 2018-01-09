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

#include <audio/ichannel.h>

#include "bassdevice.h"
#include "bassworker.h"
#include "basschannel.h"

using namespace Bass::Internal;

BassDevice::BassDevice(int deviceId,  BASS_DEVICEINFO deviceInfo) : Audio::IDevice()
{
    m_deviceId = deviceId;
    m_deviceInfo = deviceInfo;
    m_bassThread.start();
}

BassDevice::~BassDevice()
{
    m_bassThread.quit();
    m_bassThread.wait();
}

void BassDevice::init()
{
    BassWorker *worker = new BassWorker();
    worker->moveToThread(&m_bassThread);

    connect(&m_bassThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(worker, &BassWorker::outputCountUpdated, this, &BassDevice::updateOutputCount);
    connect(worker, &BassWorker::outputCountUpdated, this, &IDevice::outputCountUpdated);

    QMetaObject::invokeMethod(worker, "initialize", Qt::QueuedConnection, Q_ARG(int, m_deviceId));

    m_initialized = true;
}

QString BassDevice::name()
{
    return m_deviceInfo.name;
}

void BassDevice::updateOutputCount(int count)
{
    m_channelCount = count;
}

int BassDevice::outputCount()
{
    if (!m_initialized) {
        init();
    }

    return m_channelCount;
}

Audio::IChannel *BassDevice::createChannel(QString fileName)
{
    return new BassChannel(fileName);
}
