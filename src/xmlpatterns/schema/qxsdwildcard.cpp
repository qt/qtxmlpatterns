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

#include "qxsdwildcard_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

QString XsdWildcard::absentNamespace()
{
    return QLatin1String("__ns_absent");
}

void XsdWildcard::NamespaceConstraint::setVariety(Variety variety)
{
    m_variety = variety;
}

XsdWildcard::NamespaceConstraint::Variety XsdWildcard::NamespaceConstraint::variety() const
{
    return m_variety;
}

void XsdWildcard::NamespaceConstraint::setNamespaces(const QSet<QString> &namespaces)
{
    m_namespaces = namespaces;
}

QSet<QString> XsdWildcard::NamespaceConstraint::namespaces() const
{
    return m_namespaces;
}

void XsdWildcard::NamespaceConstraint::setDisallowedNames(const QSet<QString> &names)
{
    m_disallowedNames = names;
}

QSet<QString> XsdWildcard::NamespaceConstraint::disallowedNames() const
{
    return m_disallowedNames;
}

XsdWildcard::XsdWildcard()
    : m_namespaceConstraint(new NamespaceConstraint())
    , m_processContents(Strict)
{
    m_namespaceConstraint->setVariety(NamespaceConstraint::Any);
}

bool XsdWildcard::isWildcard() const
{
    return true;
}

void XsdWildcard::setNamespaceConstraint(const NamespaceConstraint::Ptr &namespaceConstraint)
{
    m_namespaceConstraint = namespaceConstraint;
}

XsdWildcard::NamespaceConstraint::Ptr XsdWildcard::namespaceConstraint() const
{
    return m_namespaceConstraint;
}

void XsdWildcard::setProcessContents(ProcessContents contents)
{
    m_processContents = contents;
}

XsdWildcard::ProcessContents XsdWildcard::processContents() const
{
    return m_processContents;
}

QT_END_NAMESPACE
