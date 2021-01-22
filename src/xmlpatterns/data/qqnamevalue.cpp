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

#include "qanyuri_p.h"
#include "qbuiltintypes_p.h"
#include "qxpathhelper_p.h"

#include "qqnamevalue_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

QNameValue::QNameValue(const NamePool::Ptr &np, const QXmlName name) : m_qName(name)
                                                                     , m_namePool(np)
{
    Q_ASSERT(!name.isNull());
    Q_ASSERT(m_namePool);
}

QNameValue::Ptr QNameValue::fromValue(const NamePool::Ptr &np, const QXmlName name)
{
    Q_ASSERT(!name.isNull());
    return QNameValue::Ptr(new QNameValue(np, name));
}

QString QNameValue::stringValue() const
{
    return m_namePool->toLexical(m_qName);
}

ItemType::Ptr QNameValue::type() const
{
    return BuiltinTypes::xsQName;
}

QT_END_NAMESPACE
