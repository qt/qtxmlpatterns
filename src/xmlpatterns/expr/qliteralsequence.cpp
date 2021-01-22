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
#include "qgenericsequencetype_p.h"

#include "qliteralsequence_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

LiteralSequence::LiteralSequence(const Item::List &list) : m_list(list)
{
    Q_ASSERT(list.size() >= 2);
}

Item::Iterator::Ptr LiteralSequence::evaluateSequence(const DynamicContext::Ptr &) const
{
    return makeListIterator(m_list);
}

SequenceType::Ptr LiteralSequence::staticType() const
{
    const Item::List::const_iterator end(m_list.constEnd());
    Item::List::const_iterator it(m_list.constBegin());

    /* Load the first item. */
    ItemType::Ptr t((*it).type());
    ++it;

    for(; end != it; ++it)
        t |= (*it).type();

    return makeGenericSequenceType(t, Cardinality::fromCount(m_list.size()));
}

ExpressionVisitorResult::Ptr LiteralSequence::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

Expression::ID LiteralSequence::id() const
{
    return IDLiteralSequence;
}

Expression::Properties LiteralSequence::properties() const
{
    return IsEvaluated;
}

QT_END_NAMESPACE
