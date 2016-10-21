/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3DRENDER_QRENDERQMLTOTEXTURE_H
#define QT3DRENDER_QRENDERQMLTOTEXTURE_H

#include <QtCore/QUrl>
#include <QtCore/QEvent>

#include <Qt3DRender/qframegraphnode.h>
#include <Qt3DRender/qabstracttexture.h>
#include <Qt3DRender/qt3drender_global.h>

QT_BEGIN_NAMESPACE

namespace Qt3DRender {

class QRenderQmlToTexturePrivate;

class QT3DRENDERSHARED_EXPORT QRenderQmlToTexture : public Qt3DRender::QFrameGraphNode
{
    Q_OBJECT

    Q_PROPERTY(Qt3DRender::QAbstractTexture *texture READ texture WRITE setTexture NOTIFY textureChanged)
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(bool renderOnce READ renderOnce WRITE setRenderOnce NOTIFY renderOnceChanged)
    Q_PROPERTY(bool loaded READ loaded NOTIFY loadedChanged)

public:
    explicit QRenderQmlToTexture(Qt3DCore::QNode *parent = nullptr);
    ~QRenderQmlToTexture();

    QUrl source() const;
    QAbstractTexture *texture() const;
    bool loaded() const;
    bool renderOnce() const;

public Q_SLOTS:
    void setSource(const QUrl &url);
    void setTexture(QAbstractTexture *texture);
    void setRenderOnce(bool once);

Q_SIGNALS:
    void sourceChanged(const QUrl &url);
    void textureChanged(QAbstractTexture *texture);
    void loadedChanged(bool loaded);
    void renderOnceChanged(bool once);

protected:
    Q_DECLARE_PRIVATE(QRenderQmlToTexture)

private:
    Qt3DCore::QNodeCreatedChangeBasePtr createNodeCreationChange() const Q_DECL_OVERRIDE;
    void textureDestroyed(QObject *object);

    void sourceLoaded();
};

} // namespace Qt3DRender

QT_END_NAMESPACE

#endif // QT3DRENDER_QRENDERQMLTOTEXTURE_H