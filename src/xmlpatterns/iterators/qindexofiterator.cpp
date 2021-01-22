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

#include "qinteger_p.h"

#include "qindexofiterator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

IndexOfIterator::IndexOfIterator(const Item::Iterator::Ptr &seq,
                                 const Item &searchParam,
                                 const AtomicComparator::Ptr &comp,
                                 const DynamicContext::Ptr &context,
                                 const Expression::ConstPtr &expr)
                                : m_seq(seq)
                                , m_searchParam(searchParam)
                                , m_context(context)
                                , m_expr(expr)
                                , m_position(0)
                                , m_seqPos(0)
{
    Q_ASSERT(seq);
    Q_ASSERT(searchParam);
    prepareComparison(comp);
}

Item IndexOfIterator::next()
{
    if(m_position == -1)
        return Item();

    const Item item(m_seq->next());
    ++m_seqPos;

    if(!item)
    {
        m_current.reset();
        m_position = -1;
        return Item();
    }

    if(flexibleCompare(item, m_searchParam, m_context))
    {
        ++m_position;
        return Integer::fromValue(m_seqPos);
    }

    return next();
}

Item IndexOfIterator::current() const
{
    return m_current;
}

xsInteger IndexOfIterator::position() const
{
    return m_position;
}

Item::Iterator::Ptr IndexOfIterator::copy() const
{
    return Item::Iterator::Ptr(new IndexOfIterator(m_seq->copy(),
                                                   m_searchParam,
                                                   comparator(),
                                                   m_context,
                                                   m_expr));
}

const SourceLocationReflection *IndexOfIterator::actualReflection() const
{
    return m_expr.data();
}

QT_END_NAMESPACE
