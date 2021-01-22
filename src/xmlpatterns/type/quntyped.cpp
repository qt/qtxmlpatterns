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

#include "quntyped_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Untyped::Untyped()
{
}

SchemaType::Ptr Untyped::wxsSuperType() const
{
    return BuiltinTypes::xsAnyType;
}

QXmlName Untyped::name(const NamePool::Ptr &np) const
{
    return np->allocateQName(StandardNamespaces::xs, QLatin1String("untyped"));
}

ItemType::Ptr Untyped::atomizedType() const
{
    return BuiltinTypes::xsUntypedAtomic;
}

SchemaType::TypeCategory Untyped::category() const
{
    return SchemaType::ComplexType;
}

SchemaType::DerivationMethod Untyped::derivationMethod() const
{
    return NoDerivation;
}

QT_END_NAMESPACE
