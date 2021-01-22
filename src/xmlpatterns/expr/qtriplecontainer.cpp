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

#include <QList>

#include "qtriplecontainer_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

TripleContainer::TripleContainer(const Expression::Ptr &operand1,
                                 const Expression::Ptr &operand2,
                                 const Expression::Ptr &operand3) : m_operand1(operand1),
                                                                    m_operand2(operand2),
                                                                    m_operand3(operand3)
{
    Q_ASSERT(operand1);
    Q_ASSERT(operand2);
    Q_ASSERT(operand3);
}

Expression::List TripleContainer::operands() const
{
    Expression::List result;
    result.append(m_operand1);
    result.append(m_operand2);
    result.append(m_operand3);
    return result;
}

void TripleContainer::setOperands(const Expression::List &ops)
{
    Q_ASSERT(ops.count() == 3);
    m_operand1 = ops.first();
    m_operand2 = ops.at(1);
    m_operand3 = ops.at(2);
}

bool TripleContainer::compressOperands(const StaticContext::Ptr &context)
{
    rewrite(m_operand1, m_operand1->compress(context), context);
    rewrite(m_operand2, m_operand2->compress(context), context);
    rewrite(m_operand3, m_operand3->compress(context), context);

    return m_operand1->isEvaluated() && m_operand2->isEvaluated() && m_operand3->isEvaluated();
}

QT_END_NAMESPACE
