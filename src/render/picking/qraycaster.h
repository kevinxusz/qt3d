/****************************************************************************
**
** Copyright (C) 2018 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3DRENDER_QRAYCASTER_H
#define QT3DRENDER_QRAYCASTER_H

#include <Qt3DRender/qt3drender_global.h>
#include <Qt3DRender/QAbstractRayCaster>

#include <QtGui/QVector3D>

QT_BEGIN_NAMESPACE

namespace Qt3DRender {

class QT3DRENDERSHARED_EXPORT QRayCaster : public QAbstractRayCaster
{
    Q_OBJECT
    Q_PROPERTY(QVector3D origin READ origin WRITE setOrigin NOTIFY originChanged)
    Q_PROPERTY(QVector3D direction READ direction WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(float length READ length WRITE setLength NOTIFY lengthChanged)

public:
    explicit QRayCaster(QNode *parent = nullptr);
    ~QRayCaster();

    QVector3D origin() const;
    QVector3D direction() const;
    float length() const;

public Q_SLOTS:
    void setOrigin(const QVector3D& origin);
    void setDirection(const QVector3D& direction);
    void setLength(float length);

    void trigger();
    void trigger(const QVector3D& origin, const QVector3D& direction, float length = -1.f);

Q_SIGNALS:
    void originChanged(const QVector3D &origin);
    void directionChanged(const QVector3D &direction);
    void lengthChanged(float length);

protected:
    explicit QRayCaster(QAbstractRayCasterPrivate &dd, QNode *parent = nullptr);
};

} // Qt3D

QT_END_NAMESPACE

#endif // QT3DRENDER_QRAYCASTER_H