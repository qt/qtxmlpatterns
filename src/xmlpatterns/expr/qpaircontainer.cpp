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

#include "qpaircontainer_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

PairContainer::PairContainer(const Expression::Ptr &operand1,
                             const Expression::Ptr &operand2) : m_operand1(operand1),
                                                                m_operand2(operand2)
{
    Q_ASSERT(m_operand1);
    Q_ASSERT(m_operand2);
}

Expression::List PairContainer::operands() const
{
    Expression::List list;
    list.append(m_operand1);
    list.append(m_operand2);
    return list;
}

void PairContainer::setOperands(const Expression::List &ops)
{
    Q_ASSERT(ops.count() == 2);
    m_operand1 = ops.first();
    m_operand2 = ops.last();
    Q_ASSERT(m_operand1);
    Q_ASSERT(m_operand2);
}

bool PairContainer::compressOperands(const StaticContext::Ptr &context)
{
    Q_ASSERT(m_operand1);
    Q_ASSERT(m_operand2);
    rewrite(m_operand1, m_operand1->compress(context), context);
    rewrite(m_operand2, m_operand2->compress(context), context);

    return m_operand1->isEvaluated() && m_operand2->isEvaluated();
}

QT_END_NAMESPACE
