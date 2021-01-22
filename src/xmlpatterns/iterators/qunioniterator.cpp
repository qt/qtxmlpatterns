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

#include "qitem_p.h"

#include "qunioniterator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

UnionIterator::UnionIterator(const Item::Iterator::Ptr &it1,
                             const Item::Iterator::Ptr &it2) : m_it1(it1),
                                                               m_it2(it2),
                                                               m_position(0),
                                                               m_node1(m_it1->next()),
                                                               m_node2(m_it2->next())
{
    Q_ASSERT(m_it1);
    Q_ASSERT(m_it2);
}

Item UnionIterator::next()
{
    ++m_position;
    if(m_node1 && m_node2)
    {
        if(m_node1.asNode().model() != m_node2.asNode().model())
        {
            m_current = m_node1;
            m_node1 = m_it1->next();
            return m_current;
        }

        switch(m_node1.asNode().compareOrder(m_node2.asNode()))
        {
            case QXmlNodeModelIndex::Precedes:
            {
                m_current = m_node1;
                m_node1 = m_it1->next();
                return m_current;
            }
            case QXmlNodeModelIndex::Follows:
            {
                m_current = m_node2;
                m_node2 = m_it2->next();
                return m_current;
            }
            default:
            {
                m_current = m_node2;
                m_node1 = m_it1->next();
                m_node2 = m_it2->next();
                return m_current;
            }
        }
    }

    if(m_node1)
    {
        m_current = m_node1;
        m_node1 = m_it1->next();
        return m_current;
    }

    if(m_node2)
    {
        m_current = m_node2;
        m_node2 = m_it2->next();
        return m_current;
    }

    m_current.reset();
    m_position = -1;
    return Item();
}

Item UnionIterator::current() const
{
    return m_current;
}

xsInteger UnionIterator::position() const
{
    return m_position;
}

Item::Iterator::Ptr UnionIterator::copy() const
{
    return Item::Iterator::Ptr(new UnionIterator(m_it1->copy(), m_it2->copy()));
}

QT_END_NAMESPACE
