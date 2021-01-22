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


#include "qdistinctiterator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

DistinctIterator::DistinctIterator(const Item::Iterator::Ptr &seq,
                                   const AtomicComparator::Ptr &comp,
                                   const Expression::ConstPtr &expression,
                                   const DynamicContext::Ptr &context)
                                  : m_seq(seq)
                                  , m_context(context)
                                  , m_expr(expression)
                                  , m_position(0)
{
    Q_ASSERT(seq);
    prepareComparison(comp);
}

Item DistinctIterator::next()
{
    if(m_position == -1)
        return Item();

    const Item nitem(m_seq->next());
    if(!nitem)
    {
        m_position = -1;
        m_current.reset();
        return Item();
    }

    const Item::List::const_iterator end(m_processed.constEnd());
    Item::List::const_iterator it(m_processed.constBegin());

    for(; it != end; ++it)
    {
        if(flexibleCompare(*it, nitem, m_context))
        {
            return next();
        }
    }

    m_current = nitem;
    ++m_position;
    m_processed.append(nitem);
    return nitem;
}

Item DistinctIterator::current() const
{
    return m_current;
}

xsInteger DistinctIterator::position() const
{
    return m_position;
}

Item::Iterator::Ptr DistinctIterator::copy() const
{
    return Item::Iterator::Ptr(new DistinctIterator(m_seq->copy(), comparator(), m_expr, m_context));
}

const SourceLocationReflection *DistinctIterator::actualReflection() const
{
    return m_expr.data();
}

QT_END_NAMESPACE
