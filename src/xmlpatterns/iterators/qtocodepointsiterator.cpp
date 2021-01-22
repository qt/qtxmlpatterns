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

#include "qtocodepointsiterator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

ToCodepointsIterator::ToCodepointsIterator(const QString &string)
                             : m_string(string),
                               m_len(string.length()),
                               m_position(0)
{
    Q_ASSERT(!string.isEmpty());
}

Item ToCodepointsIterator::next()
{
    if(m_position == -1)
        return Item();

    ++m_position;
    if(m_position > m_len)
    {
        m_position = -1;
        m_current.reset();
        return m_current;
    }

    m_current = Integer::fromValue(m_string.at(m_position - 1).unicode());
    return m_current;
}

xsInteger ToCodepointsIterator::count()
{
    return m_len;
}

Item ToCodepointsIterator::current() const
{
    return m_current;
}

xsInteger ToCodepointsIterator::position() const
{
    return m_position;
}

Item::Iterator::Ptr ToCodepointsIterator::copy() const
{
    return Item::Iterator::Ptr(new ToCodepointsIterator(m_string));
}

QT_END_NAMESPACE
