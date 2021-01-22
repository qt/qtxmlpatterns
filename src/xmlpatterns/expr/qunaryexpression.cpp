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

#include "qarithmeticexpression_p.h"
#include "qcommonvalues_p.h"
#include "qliteral_p.h"
#include "qschemanumeric_p.h"

#include "qunaryexpression_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

UnaryExpression::UnaryExpression(const AtomicMathematician::Operator op,
                                 const Expression::Ptr &operand,
                                 const StaticContext::Ptr &context) : ArithmeticExpression(wrapLiteral(CommonValues::IntegerZero, context, operand.data()),
                                                                                           op,
                                                                                           operand)
{
    Q_ASSERT(op == AtomicMathematician::Substract ||
             op == AtomicMathematician::Add);
    Q_ASSERT(context);
}

Item UnaryExpression::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    if(operatorID() == AtomicMathematician::Substract)
    {
        const Item item(m_operand2->evaluateSingleton(context));

        if (item)
            // If the item is an untypedAtomic (or atomicString), the cast to Numeric will
            // return a garbage object and will most likely cause a crash.
            // There is simply no way to static cast from an instance of AtomicString to a Number.
            return item.as<Numeric>()->toNegated();
        else
            return Item();
    }
    else
        return m_operand2->evaluateSingleton(context);
}

QT_END_NAMESPACE
