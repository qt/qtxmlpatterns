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

#include "qxsdxpathexpression_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

void XsdXPathExpression::setNamespaceBindings(const QList<QXmlName> &set)
{
    m_namespaceBindings = set;
}

QList<QXmlName> XsdXPathExpression::namespaceBindings() const
{
    return m_namespaceBindings;
}

void XsdXPathExpression::setDefaultNamespace(const AnyURI::Ptr &defaultNs)
{
    m_defaultNamespace = defaultNs;
}

AnyURI::Ptr XsdXPathExpression::defaultNamespace() const
{
    return m_defaultNamespace;
}

void XsdXPathExpression::setBaseURI(const AnyURI::Ptr &uri)
{
    m_baseURI = uri;
}

AnyURI::Ptr XsdXPathExpression::baseURI() const
{
    return m_baseURI;
}

void XsdXPathExpression::setExpression(const QString &expression)
{
    m_expression = expression;
}

QString XsdXPathExpression::expression() const
{
    return m_expression;
}

QT_END_NAMESPACE
