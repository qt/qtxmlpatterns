/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtQml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
****************************************************************************/

#include <QtQml/qqmlextensionplugin.h>
#include <QtQml/qqml.h>

#include "qqmlxmllistmodel_p.h"

QT_BEGIN_NAMESPACE

class QmlXmlListModelPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    QmlXmlListModelPlugin(QObject *parent = 0) : QQmlExtensionPlugin(parent) { }
    void registerTypes(const char *uri) override
    {
        Q_ASSERT(QLatin1String(uri) == QLatin1String("QtQuick.XmlListModel"));
        qmlRegisterType<QQuickXmlListModel>(uri,2,0,"XmlListModel");
        qmlRegisterType<QQuickXmlListModelRole>(uri,2,0,"XmlRole");

        // Auto-increment the import to stay in sync with ALL future QtQuick minor versions from 5.11 onward
        qmlRegisterModule(uri, 2, QT_VERSION_MINOR);
    }
};

QT_END_NAMESPACE

#include "plugin.moc"
