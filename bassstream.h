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

#ifndef BASSSTREAM_H
#define BASSSTREAM_H

#include <QObject>
#include <QTimer>
#include <bass.h>

namespace Bass {

namespace Internal {

class BassStream : public QObject
{
    Q_OBJECT
public:
    BassStream();
    ~BassStream();

public slots:
    void initialize();
    bool load(QString fileName);
    void play();
    void stop();
    bool isPlaying();

private:
    HSTREAM m_stream;
    QTimer *m_timer = nullptr;
    float m_length;

private slots:
    void updatePosition();

signals:
    void errorOccured(int code);
    void lengthUpdated(float length);
    void positionChanged(float position, float length);
};

} // namespace Internal
} // namespace Bass

#endif // BASSSTREAM_H
