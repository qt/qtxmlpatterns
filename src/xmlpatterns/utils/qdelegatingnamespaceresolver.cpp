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

#include "qnamepool_p.h"

#include "qdelegatingnamespaceresolver_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

DelegatingNamespaceResolver::DelegatingNamespaceResolver(const NamespaceResolver::Ptr &resolver) : m_nsResolver(resolver)
{
    Q_ASSERT(m_nsResolver);
}

DelegatingNamespaceResolver::DelegatingNamespaceResolver(const NamespaceResolver::Ptr &ns,
                                                         const Bindings &overrides) : m_nsResolver(ns)
                                                                                    , m_bindings(overrides)
{
    Q_ASSERT(m_nsResolver);
}

QXmlName::NamespaceCode DelegatingNamespaceResolver::lookupNamespaceURI(const QXmlName::PrefixCode prefix) const
{
    const QXmlName::NamespaceCode val(m_bindings.value(prefix, NoBinding));

    if(val == NoBinding)
        return m_nsResolver->lookupNamespaceURI(prefix);
    else
        return val;
}

NamespaceResolver::Bindings DelegatingNamespaceResolver::bindings() const
{
    Bindings bs(m_nsResolver->bindings());
    const Bindings::const_iterator end(m_bindings.constEnd());
    Bindings::const_iterator it(m_bindings.constBegin());

    for(; it != end; ++it)
        bs.insert(it.key(), it.value());

    return bs;
}

void DelegatingNamespaceResolver::addBinding(const QXmlName nb)
{
    if(nb.namespaceURI() == StandardNamespaces::UndeclarePrefix)
        m_bindings.remove(nb.prefix());
    else
        m_bindings.insert(nb.prefix(), nb.namespaceURI());
}

QT_END_NAMESPACE
