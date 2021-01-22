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

#include "qresourcedelegator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

bool ResourceDelegator::isUnparsedTextAvailable(const QUrl &uri,
                                                const QString &encoding)
{
    return m_parentLoader->isUnparsedTextAvailable(uri, encoding);
}

ItemType::Ptr ResourceDelegator::announceUnparsedText(const QUrl &uri)
{
    return m_parentLoader->announceUnparsedText(uri);
}

Item ResourceDelegator::openUnparsedText(const QUrl &uri,
                                         const QString &encoding,
                                         const ReportContext::Ptr &context,
                                         const SourceLocationReflection *const where)
{
    return m_parentLoader->openUnparsedText(uri, encoding, context, where);
}

Item ResourceDelegator::openDocument(const QUrl &uri,
                                     const ReportContext::Ptr &context)
{
    if(m_needsOverride.contains(uri))
        return m_forDeviceLoader->openDocument(uri, context);
    else
        return m_parentLoader->openDocument(uri, context);
}

SequenceType::Ptr ResourceDelegator::announceDocument(const QUrl &uri, const Usage usageHint)
{
    return m_parentLoader->announceDocument(uri, usageHint);
}

bool ResourceDelegator::isDocumentAvailable(const QUrl &uri)
{
    return m_parentLoader->isDocumentAvailable(uri);
}

Item::Iterator::Ptr ResourceDelegator::openCollection(const QUrl &uri)
{
    return m_parentLoader->openCollection(uri);
}

SequenceType::Ptr ResourceDelegator::announceCollection(const QUrl &uri)
{
    return m_parentLoader->announceCollection(uri);
}

QSet<QUrl> ResourceDelegator::deviceURIs() const
{
    QSet<QUrl> uris(m_needsOverride);
    uris |= m_forDeviceLoader->deviceURIs();
    return uris;
}

QT_END_NAMESPACE
