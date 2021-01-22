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

#include "qxpathhelper_p.h"

#include "qsubsequenceiterator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

SubsequenceIterator::SubsequenceIterator(const Item::Iterator::Ptr &iterator,
                                         const xsInteger start,
                                         const xsInteger len)
                                         : m_position(0),
                                           m_it(iterator),
                                           m_counter(start),
                                           m_start(start),
                                           m_len(len),
                                           m_stop(m_start + m_len)
{
    Q_ASSERT(iterator);
    Q_ASSERT(start >= 1);
    Q_ASSERT(len == -1 || len >= 1);

    /* Note, "The first item of a sequence is located at position 1, not position 0." */
    for(xsInteger i = 1; i != m_start; ++i)
        m_it->next();
}

Item SubsequenceIterator::next()
{
    if(m_position == -1)
        return Item();

    m_current = m_it->next();
    ++m_position;

    if(m_len == -1)
    {
        if(!m_current)
            m_position = -1;

        return m_current;
    }

    ++m_counter;

    if(!(m_counter > m_stop) && m_current)
        return m_current;

    m_position = -1;
    m_current.reset();
    return Item();
}

Item SubsequenceIterator::current() const
{
    return m_current;
}

xsInteger SubsequenceIterator::position() const
{
    return m_position;
}

Item::Iterator::Ptr SubsequenceIterator::copy() const
{
    return Item::Iterator::Ptr(new SubsequenceIterator(m_it->copy(), m_start, m_len));
}

QT_END_NAMESPACE
