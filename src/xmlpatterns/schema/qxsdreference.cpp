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

#include "qxsdreference_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

bool XsdReference::isReference() const
{
    return true;
}

void XsdReference::setType(Type type)
{
    m_type = type;
}

XsdReference::Type XsdReference::type() const
{
    return m_type;
}

void XsdReference::setReferenceName(const QXmlName &referenceName)
{
    m_referenceName = referenceName;
}

QXmlName XsdReference::referenceName() const
{
    return m_referenceName;
}

void XsdReference::setSourceLocation(const QSourceLocation &location)
{
    m_sourceLocation = location;
}

QSourceLocation XsdReference::sourceLocation() const
{
    return m_sourceLocation;
}

QT_END_NAMESPACE
