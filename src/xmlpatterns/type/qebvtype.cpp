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
#include "qcommonsequencetypes_p.h"
#include "qitem_p.h"

#include "qebvtype_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

EBVType::EBVType()
{
}

bool EBVType::itemMatches(const Item &item) const
{
    if(item.isNode())
        return false;

    return BuiltinTypes::xsBoolean->itemMatches(item)       ||
           BuiltinTypes::numeric->itemMatches(item)         ||
           BuiltinTypes::xsString->itemMatches(item)        ||
           BuiltinTypes::xsAnyURI->itemMatches(item)        ||
           CommonSequenceTypes::Empty->itemMatches(item)    ||
           BuiltinTypes::xsUntypedAtomic->itemMatches(item);
}

bool EBVType::xdtTypeMatches(const ItemType::Ptr &t) const
{
    return BuiltinTypes::node->xdtTypeMatches(t)            ||
           BuiltinTypes::xsBoolean->xdtTypeMatches(t)       ||
           BuiltinTypes::numeric->xdtTypeMatches(t)         ||
           BuiltinTypes::xsString->xdtTypeMatches(t)        ||
           BuiltinTypes::xsAnyURI->xdtTypeMatches(t)        ||
           *CommonSequenceTypes::Empty == *t                ||
           BuiltinTypes::xsUntypedAtomic->xdtTypeMatches(t) ||
           /* Item & xs:anyAtomicType is ok, we do the checking at runtime. */
           *BuiltinTypes::item == *t                        ||
           *BuiltinTypes::xsAnyAtomicType == *t;
}

QString EBVType::displayName(const NamePool::Ptr &) const
{
    /* Some QName-lexical is not used here because it makes little sense
     * for this strange type. Instead the operand type of the fn:boolean()'s
     * argument is used. */
    return QLatin1String("item()*(: EBV extractable type :)");
}

Cardinality EBVType::cardinality() const
{
    return Cardinality::zeroOrMore();
}

ItemType::Ptr EBVType::xdtSuperType() const
{
    return BuiltinTypes::item;
}

ItemType::Ptr EBVType::itemType() const
{
    return ItemType::Ptr(const_cast<EBVType *>(this));
}

bool EBVType::isAtomicType() const
{
    return false;
}

bool EBVType::isNodeType() const
{
    return true;
}

ItemType::Ptr EBVType::atomizedType() const
{
    Q_ASSERT_X(false, Q_FUNC_INFO,
               "That this function is called makes no sense.");
    return AtomicType::Ptr();
}

QT_END_NAMESPACE
