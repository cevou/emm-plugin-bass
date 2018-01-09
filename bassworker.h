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

#ifndef BASSWORKER_H
#define BASSWORKER_H

#include <QObject>
#include <bass.h>

namespace Bass {

namespace Internal {


class BassWorker : public QObject
{
    Q_OBJECT
public:
    ~BassWorker();

public slots:
    void initialize(int deviceId);

private:
    bool m_initialized = false;
    BASS_INFO m_info;

signals:
    void outputCountUpdated(int);
    void errorOccured(int);
};

} // namespace Internal
} // namespace Bass

#endif // BASSWORKER_H
