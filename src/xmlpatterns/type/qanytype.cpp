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

#include "qatomictype_p.h"

#include "qanytype_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

AnyType::~AnyType()
{
}

bool AnyType::wxsTypeMatches(const SchemaType::Ptr &other) const
{
    if(other)
        return this == other.data() ? true : wxsTypeMatches(other->wxsSuperType());
    else
        return false;
}

bool AnyType::isAbstract() const
{
    return false;
}

QXmlName AnyType::name(const NamePool::Ptr &np) const
{
    return np->allocateQName(StandardNamespaces::xs, QLatin1String("anyType"));
}

QString AnyType::displayName(const NamePool::Ptr &) const
{
    /* A bit faster than calling name()->displayName() */
    return QLatin1String("xs:anyType");
}

SchemaType::Ptr AnyType::wxsSuperType() const
{
    return SchemaType::Ptr();
}

SchemaType::TypeCategory AnyType::category() const
{
    return None;
}

bool AnyType::isComplexType() const
{
    return true;
}

SchemaType::DerivationMethod AnyType::derivationMethod() const
{
    return NoDerivation;
}

SchemaType::DerivationConstraints AnyType::derivationConstraints() const
{
    return SchemaType::DerivationConstraints();
}

QT_END_NAMESPACE
