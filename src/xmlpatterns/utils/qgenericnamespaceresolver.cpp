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

#include "qgenericnamespaceresolver_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

GenericNamespaceResolver::GenericNamespaceResolver(const Bindings &list) : m_bindings(list)
{
}

void GenericNamespaceResolver::addBinding(const QXmlName nb)
{
    if(nb.namespaceURI() == StandardNamespaces::UndeclarePrefix)
        m_bindings.remove(nb.prefix());
    else
        m_bindings.insert(nb.prefix(), nb.namespaceURI());
}

QXmlName::NamespaceCode GenericNamespaceResolver::lookupNamespaceURI(const QXmlName::PrefixCode prefix) const
{
    return m_bindings.value(prefix, NoBinding);
}

NamespaceResolver::Ptr GenericNamespaceResolver::defaultXQueryBindings()
{
    Bindings list;

    list.insert(StandardPrefixes::xml,    StandardNamespaces::xml);
    list.insert(StandardPrefixes::xs,     StandardNamespaces::xs);
    list.insert(StandardPrefixes::xsi,    StandardNamespaces::xsi);
    list.insert(StandardPrefixes::fn,     StandardNamespaces::fn);
    list.insert(StandardPrefixes::local,  StandardNamespaces::local);
    list.insert(StandardPrefixes::empty,  StandardNamespaces::empty);

    return NamespaceResolver::Ptr(new GenericNamespaceResolver(list));
}

NamespaceResolver::Ptr GenericNamespaceResolver::defaultXSLTBindings()
{
    Bindings list;

    list.insert(StandardPrefixes::xml,    StandardNamespaces::xml);
    list.insert(StandardPrefixes::empty,  StandardNamespaces::empty);

    return NamespaceResolver::Ptr(new GenericNamespaceResolver(list));
}

NamespaceResolver::Bindings GenericNamespaceResolver::bindings() const
{
    return m_bindings;
}

QT_END_NAMESPACE
