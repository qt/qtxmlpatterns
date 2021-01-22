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
#include "qitem_p.h"

#include "qanynodetype_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

bool AnyNodeType::xdtTypeMatches(const ItemType::Ptr &other) const
{
    return other->isNodeType();
}

bool AnyNodeType::itemMatches(const Item &item) const
{
    return item.isNode();
}

ItemType::Ptr AnyNodeType::atomizedType() const
{
    return BuiltinTypes::xsAnyAtomicType;
}

QString AnyNodeType::displayName(const NamePool::Ptr &) const
{
    return QLatin1String("node()");
}

ItemType::Ptr AnyNodeType::xdtSuperType() const
{
    return BuiltinTypes::item;
}

bool AnyNodeType::isNodeType() const
{
    return true;
}

bool AnyNodeType::isAtomicType() const
{
    return false;
}

QXmlNodeModelIndex::NodeKind AnyNodeType::nodeKind() const
{
    /* node() is an abstract type, so we don't have a value for it in
     * QXmlNodeModelIndex::NodeKind. */
    return QXmlNodeModelIndex::NodeKind(0);
}

PatternPriority AnyNodeType::patternPriority() const
{
    return -0.5;
}

QT_END_NAMESPACE
