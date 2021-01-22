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

#include "qatomicstring_p.h"
#include "qqnameconstructor_p.h"

#include "qsystempropertyfn_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item SystemPropertyFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const QString lexQName(m_operands.first()->evaluateSingleton(context).stringValue());

    const QXmlName name
        (QNameConstructor::expandQName<DynamicContext::Ptr,
                                       ReportContext::XTDE1390,
                                       ReportContext::XTDE1390>(lexQName,
                                                                context,
                                                                staticNamespaces(), this));

    return AtomicString::fromValue(retrieveProperty(name));
}

QString SystemPropertyFN::retrieveProperty(const QXmlName name)
{
    if(name.namespaceURI() != StandardNamespaces::xslt)
        return QString();

    switch(name.localName())
    {
        case StandardLocalNames::version:
            /*
             * The supported XSL-T version.
             *
             * @see <a href="http://www.w3.org/TR/xslt20/#system-property">The Note paragraph
             * at the very end of XSL Transformations (XSLT) Version 2.0,
             * 16.6.5 system-property</a>
             */
            return QString::number(1.20);
        case StandardLocalNames::vendor:
            return QLatin1String("Digia Plc and/or its subsidiary(-ies), a Digia Company");
        case StandardLocalNames::vendor_url:
            return QLatin1String("http://qt.digia.com/");
        case StandardLocalNames::product_name:
            return QLatin1String("QtXmlPatterns");
        case StandardLocalNames::product_version:
            return QLatin1String("0.1");
        case StandardLocalNames::is_schema_aware:
        case StandardLocalNames::supports_backwards_compatibility:
        case StandardLocalNames::supports_serialization:
            return QLatin1String("no");
        default:
            return QString();
    }
}

QT_END_NAMESPACE
