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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef QXMLSCHEMA_P_H
#define QXMLSCHEMA_P_H

#include <QAbstractMessageHandler>
#include <QAbstractUriResolver>
#include <private/qautoptr_p.h>
#include <private/qcoloringmessagehandler_p.h>
#include <private/qreferencecountedvalue_p.h>

#include <private/qxsdschemacontext_p.h>
#include <private/qxsdschemaparser_p.h>
#include <private/qxsdschemaparsercontext_p.h>

#include <QtCore/QSharedData>
#include <QtNetwork/QNetworkAccessManager>

QT_BEGIN_NAMESPACE

class QXmlSchemaPrivate : public QSharedData
{
    public:
        QXmlSchemaPrivate(const QXmlNamePool &namePool);
        QXmlSchemaPrivate(const QPatternist::XsdSchemaContext::Ptr &schemaContext);
        QXmlSchemaPrivate(const QXmlSchemaPrivate &other);

        void load(const QUrl &source, const QString &targetNamespace);
        void load(QIODevice *source, const QUrl &documentUri, const QString &targetNamespace);
        void load(const QByteArray &data, const QUrl &documentUri, const QString &targetNamespace);
        bool isValid() const;
        QXmlNamePool namePool() const;
        QUrl documentUri() const;
        void setMessageHandler(QAbstractMessageHandler *handler);
        QAbstractMessageHandler *messageHandler() const;
        void setUriResolver(const QAbstractUriResolver *resolver);
        const QAbstractUriResolver *uriResolver() const;
        void setNetworkAccessManager(QNetworkAccessManager *networkmanager);
        QNetworkAccessManager *networkAccessManager() const;

        QXmlNamePool                                                     m_namePool;
        QAbstractMessageHandler*                                         m_userMessageHandler;
        const QAbstractUriResolver*                                      m_uriResolver;
        QNetworkAccessManager*                                           m_userNetworkAccessManager;
        QPatternist::ReferenceCountedValue<QAbstractMessageHandler>::Ptr m_messageHandler;
        QPatternist::ReferenceCountedValue<QNetworkAccessManager>::Ptr   m_networkAccessManager;

        QPatternist::XsdSchemaContext::Ptr                               m_schemaContext;
        QPatternist::XsdSchemaParserContext::Ptr                         m_schemaParserContext;
        bool                                                             m_schemaIsValid;
        QUrl                                                             m_documentUri;
};

QT_END_NAMESPACE

#endif
