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


#include "qremovaliterator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

RemovalIterator::RemovalIterator(const Item::Iterator::Ptr &target,
                                 const xsInteger pos) : m_target(target),
                                                        m_removalPos(pos),
                                                        m_position(0)
{
    Q_ASSERT(target);
    Q_ASSERT(pos >= 1);
}

Item RemovalIterator::next()
{
    if(m_position == -1)
        return Item();

    m_current = m_target->next();

    if(!m_current)
    {
        m_position = -1;
        m_current.reset();
        return Item();
    }

    ++m_position;

    if(m_position == m_removalPos)
    {
        next(); /* Recurse, return the next item. */
        --m_position; /* Don't count the one we removed. */
        return m_current;
    }

    return m_current;
}

xsInteger RemovalIterator::count()
{
    const xsInteger itc = m_target->count();

    if(itc < m_removalPos)
        return itc;
    else
        return itc - 1;
}

Item RemovalIterator::current() const
{
    return m_current;
}

xsInteger RemovalIterator::position() const
{
    return m_position;
}

Item::Iterator::Ptr RemovalIterator::copy() const
{
    return Item::Iterator::Ptr(new RemovalIterator(m_target->copy(), m_removalPos));
}

QT_END_NAMESPACE
