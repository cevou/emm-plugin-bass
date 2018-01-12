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

#include "bassstream.h"

using namespace Bass::Internal;

BassStream::BassStream() : QObject()
{
}

BassStream::~BassStream()
{
    m_timer->stop();
    delete m_timer;

    // Do nothing if no stream is loaded
    if (m_stream == 0) {
        return;
    }

    BASS_StreamFree(m_stream);
}

void BassStream::initialize()
{
    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &BassStream::updatePosition);
}

bool BassStream::load(QString fileName)
{
    m_stream = BASS_StreamCreateFile(false, fileName.toLatin1(), 0, 0, BASS_SAMPLE_FLOAT /*| BASS_STREAM_DECODE*/);
    if (m_stream == 0) {
        emit errorOccured(BASS_ErrorGetCode());
        return false;
    }

    m_length = BASS_ChannelBytes2Seconds(m_stream, BASS_ChannelGetLength(m_stream, BASS_POS_BYTE));
    emit lengthUpdated(m_length);

    return true;
}

void BassStream::play()
{
    // Do nothing if no stream is loaded
    if (m_stream == 0) {
        return;
    }

    if (!BASS_ChannelPlay(m_stream,true)) {
        emit errorOccured(BASS_ErrorGetCode());
        return;
    }

    m_timer->start(100);
}

void BassStream::stop()
{
    // Do nothing if no stream is loaded
    if (m_stream == 0) {
        return;
    }

    BASS_ChannelStop(m_stream);
}

bool BassStream::isPlaying()
{
    // Do nothing if no stream is loaded
    if (m_stream == 0) {
        return false;
    }

    return BASS_ChannelIsActive(m_stream) == BASS_ACTIVE_PLAYING;
}

void BassStream::updatePosition()
{
    // Do nothing if no stream is loaded
    if (m_stream == 0) {
        return;
    }

    double pos = BASS_ChannelBytes2Seconds(m_stream, BASS_ChannelGetPosition(m_stream, BASS_POS_BYTE));
    emit positionChanged(pos, m_length);
}
