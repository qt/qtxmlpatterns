/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
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

#ifndef QXMLSCHEMA_H
#define QXMLSCHEMA_H

#include <QtCore/QSharedDataPointer>
#include <QtCore/QUrl>
#include <QtXmlPatterns/QXmlNamePool>

QT_BEGIN_NAMESPACE


class QAbstractMessageHandler;
class QAbstractUriResolver;
class QIODevice;
class QNetworkAccessManager;
class QUrl;
class QXmlNamePool;
class QXmlSchemaPrivate;

class Q_XMLPATTERNS_EXPORT QXmlSchema
{
    friend class QXmlSchemaValidatorPrivate;

    public:
        QXmlSchema();
        QXmlSchema(const QXmlSchema &other);
        QXmlSchema &operator=(const QXmlSchema &other);
        ~QXmlSchema();

        bool load(const QUrl &source);
        bool load(QIODevice *source, const QUrl &documentUri = QUrl());
        bool load(const QByteArray &data, const QUrl &documentUri = QUrl());

        bool isValid() const;

        QXmlNamePool namePool() const;
        QUrl documentUri() const;

        void setMessageHandler(QAbstractMessageHandler *handler);
        QAbstractMessageHandler *messageHandler() const;

        void setUriResolver(const QAbstractUriResolver *resolver);
        const QAbstractUriResolver *uriResolver() const;

        void setNetworkAccessManager(QNetworkAccessManager *networkmanager);
        QNetworkAccessManager *networkAccessManager() const;

    private:
        QSharedDataPointer<QXmlSchemaPrivate> d;
};

QT_END_NAMESPACE

#endif
