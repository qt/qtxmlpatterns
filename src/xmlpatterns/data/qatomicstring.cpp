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

#include "qbuiltintypes_p.h"

#include "qatomicstring_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

AtomicString::AtomicString(const QString &s) : m_value(s)
{
}

AtomicString::Ptr AtomicString::fromValue(const QString &value)
{
    return AtomicString::Ptr(new AtomicString(value));
}

bool AtomicString::evaluateEBV(const QExplicitlySharedDataPointer<DynamicContext> &) const
{
    return m_value.length() > 0;
}

QString AtomicString::stringValue() const
{
    return m_value;
}

ItemType::Ptr AtomicString::type() const
{
    return BuiltinTypes::xsString;
}

QT_END_NAMESPACE
