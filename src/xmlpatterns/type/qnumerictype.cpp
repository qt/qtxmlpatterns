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
#include "qitem_p.h"
#include "qschematype_p.h"

#include "qnumerictype_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

NumericType::NumericType()
{
}

NumericType::~NumericType()
{
}

bool NumericType::itemMatches(const Item &item) const
{
    if(item.isNode())
        return false;

    return BuiltinTypes::xsDouble->itemMatches(item)    ||
           BuiltinTypes::xsDecimal->itemMatches(item)   ||
           BuiltinTypes::xsFloat->itemMatches(item);
}

bool NumericType::xdtTypeMatches(const ItemType::Ptr &t) const
{
    return BuiltinTypes::xsDouble->xdtTypeMatches(t)    ||
           BuiltinTypes::xsDecimal->xdtTypeMatches(t)   ||
           BuiltinTypes::xsFloat->xdtTypeMatches(t)     ||
           *t == *this; /* If it's NumericType */
}

QString NumericType::displayName(const NamePool::Ptr &) const
{
    return QLatin1String("numeric");
}

SchemaType::Ptr NumericType::wxsSuperType() const
{
    return BuiltinTypes::xsAnyAtomicType;
}

ItemType::Ptr NumericType::xdtSuperType() const
{
    return BuiltinTypes::xsAnyAtomicType;
}

bool NumericType::isAbstract() const
{
    return true;
}

bool NumericType::isNodeType() const
{
    return false;
}

bool NumericType::isAtomicType() const
{
    return true;
}

ItemType::Ptr NumericType::atomizedType() const
{
    return AtomicType::Ptr();
}

AtomicTypeVisitorResult::Ptr NumericType::accept(const AtomicTypeVisitor::Ptr &,
                                                 const SourceLocationReflection *const) const
{
    return AtomicTypeVisitorResult::Ptr();
}

AtomicTypeVisitorResult::Ptr NumericType::accept(const ParameterizedAtomicTypeVisitor::Ptr &,
                                                 const qint16,
                                                 const SourceLocationReflection *const) const
{
    return AtomicTypeVisitorResult::Ptr();
}

AtomicComparatorLocator::Ptr NumericType::comparatorLocator() const
{
    return AtomicComparatorLocator::Ptr();
}

AtomicMathematicianLocator::Ptr NumericType::mathematicianLocator() const
{
    return AtomicMathematicianLocator::Ptr();
}

AtomicCasterLocator::Ptr NumericType::casterLocator() const
{
    return AtomicCasterLocator::Ptr();
}

QT_END_NAMESPACE
