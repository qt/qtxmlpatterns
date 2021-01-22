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
#include "qbuiltintypes_p.h"

#include "qanyitemtype_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

AnyItemType::AnyItemType()
{
}

bool AnyItemType::itemMatches(const Item &) const
{
    return true;
}

bool AnyItemType::xdtTypeMatches(const ItemType::Ptr &) const
{
    return true;
}

QString AnyItemType::displayName(const NamePool::Ptr &) const
{
    return QLatin1String("item()");
}

ItemType::Ptr AnyItemType::xdtSuperType() const
{
    return ItemType::Ptr();
}

bool AnyItemType::isNodeType() const
{
    return false;
}

bool AnyItemType::isAtomicType() const
{
    return false;
}

ItemType::Ptr AnyItemType::atomizedType() const
{
    return BuiltinTypes::xsAnyAtomicType;
}

QT_END_NAMESPACE
