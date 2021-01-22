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

#include "qxsdfacet_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

XsdFacet::XsdFacet()
    : m_type(None)
{
}

void XsdFacet::setType(Type type)
{
    m_type = type;
}

XsdFacet::Type XsdFacet::type() const
{
    return m_type;
}

void XsdFacet::setValue(const AtomicValue::Ptr &value)
{
    m_value = value;
}

AtomicValue::Ptr XsdFacet::value() const
{
    return m_value;
}

void XsdFacet::setMultiValue(const AtomicValue::List &value)
{
    m_multiValue = value;
}

AtomicValue::List XsdFacet::multiValue() const
{
    return m_multiValue;
}

void XsdFacet::setAssertions(const XsdAssertion::List &assertions)
{
    m_assertions = assertions;
}

XsdAssertion::List XsdFacet::assertions() const
{
    return m_assertions;
}

void XsdFacet::setFixed(bool fixed)
{
    m_fixed = fixed;
}

bool XsdFacet::fixed() const
{
    return m_fixed;
}

QString XsdFacet::typeName(Type type)
{
    switch (type) {
        case Length: return QLatin1String("length"); break;
        case MinimumLength: return QLatin1String("minLength"); break;
        case MaximumLength: return QLatin1String("maxLength"); break;
        case Pattern: return QLatin1String("pattern"); break;
        case WhiteSpace: return QLatin1String("whiteSpace"); break;
        case MaximumInclusive: return QLatin1String("maxInclusive"); break;
        case MaximumExclusive: return QLatin1String("maxExclusive"); break;
        case MinimumInclusive: return QLatin1String("minInclusive"); break;
        case MinimumExclusive: return QLatin1String("minExclusive"); break;
        case TotalDigits: return QLatin1String("totalDigits"); break;
        case FractionDigits: return QLatin1String("fractionDigits"); break;
        case Enumeration: return QLatin1String("enumeration"); break;
        case Assertion: return QLatin1String("assertion"); break;
        case None: // fall through
        default: return QLatin1String("none"); break;
    }
}

QT_END_NAMESPACE
