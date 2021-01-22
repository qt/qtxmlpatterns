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

#ifndef QXMLNAMEPOOL_H
#define QXMLNAMEPOOL_H

#include <QtCore/QSharedData>
#include <QtCore/QString>
#include <QtXmlPatterns/qtxmlpatternsglobal.h>

QT_BEGIN_NAMESPACE


namespace QPatternist
{
    class NamePool;
    class XsdSchemaParser;
    class XsdValidatingInstanceReader;
}

namespace QPatternistSDK
{
    class Global;
}

class QXmlQueryPrivate;
class QXmlName;

class Q_XMLPATTERNS_EXPORT QXmlNamePool
{
public:
    QXmlNamePool();
    QXmlNamePool(const QXmlNamePool &other);
    ~QXmlNamePool();
    QXmlNamePool &operator=(const QXmlNamePool &other);

private:
    QXmlNamePool(QPatternist::NamePool *namePool);
    friend class QXmlQueryPrivate;
    friend class QXmlQuery;
    friend class QXmlSchemaPrivate;
    friend class QXmlSchemaValidatorPrivate;
    friend class QXmlSerializerPrivate;
    friend class QXmlName;
    friend class QPatternist::XsdSchemaParser;
    friend class QPatternist::XsdValidatingInstanceReader;
    friend class QPatternistSDK::Global;
    QExplicitlySharedDataPointer<QPatternist::NamePool> d;
};

QT_END_NAMESPACE

#endif
