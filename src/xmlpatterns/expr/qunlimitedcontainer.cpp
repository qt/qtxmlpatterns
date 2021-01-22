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

#include "qunlimitedcontainer_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

UnlimitedContainer::UnlimitedContainer(const Expression::List &ops) : m_operands(ops)
{
}

void UnlimitedContainer::setOperands(const Expression::List &list)
{
    m_operands = list;
}

Expression::List UnlimitedContainer::operands() const
{
    return m_operands;
}

bool UnlimitedContainer::compressOperands(const StaticContext::Ptr &context)
{
    const Expression::List::iterator end(m_operands.end());
    Expression::List::iterator it(m_operands.begin());
    int evaled = 0;

    for(; it != end; ++it)
    {
        Q_ASSERT((*it));
        rewrite((*it), (*it)->compress(context), context);
        if((*it)->isEvaluated())
                ++evaled;
    }

    return evaled == m_operands.count();
}

QT_END_NAMESPACE
