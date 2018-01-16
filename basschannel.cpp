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

#include "basschannel.h"
#include "bassstream.h"

using namespace Bass::Internal;

BassChannel::BassChannel(BassStream *stream) :
    Audio::IChannel(),
    m_stream(stream)
{
    QMetaObject::invokeMethod(m_stream, "initialize", Qt::QueuedConnection);

    connect(m_stream, &BassStream::lengthUpdated, this, &BassChannel::lengthUpdated);
    connect(m_stream, &BassStream::positionChanged, this, &BassChannel::positionChanged);
}

BassChannel::~BassChannel()
{
    m_stream->deleteLater();
}

void BassChannel::load(QString fileName)
{
    QMetaObject::invokeMethod(m_stream, "load", Qt::QueuedConnection, Q_ARG(QString, fileName));
}

void BassChannel::play()
{
    QMetaObject::invokeMethod(m_stream, "play", Qt::QueuedConnection);
}

void BassChannel::pause()
{

}

void BassChannel::stop()
{
    QMetaObject::invokeMethod(m_stream, "stop", Qt::QueuedConnection);
}

bool BassChannel::isPlaying()
{
    bool playing;
    QMetaObject::invokeMethod(m_stream, "isPlaying", Qt::DirectConnection, Q_RETURN_ARG(bool, playing));
    return playing;
}
