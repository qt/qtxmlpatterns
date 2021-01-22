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
#include "qboolean_p.h"
#include "qbuiltintypes_p.h"
#include "qcommonsequencetypes_p.h"
#include "qemptysequence_p.h"
#include "qoptimizationpasses_p.h"

#include "qvaluecomparison_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

ValueComparison::ValueComparison(const Expression::Ptr &op1,
                                 const AtomicComparator::Operator op,
                                 const Expression::Ptr &op2) : PairContainer(op1, op2),
                                                               m_operator(op)
{
}

/*! \internal */
ValueComparison::~ValueComparison()
{
}

Item ValueComparison::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item it1(m_operand1->evaluateSingleton(context));
    if(!it1)
        return Item();

    const Item it2(m_operand2->evaluateSingleton(context));
    if(!it2)
        return Item();

    return Boolean::fromValue(flexibleCompare(it1, it2, context));
}

Expression::Ptr ValueComparison::typeCheck(const StaticContext::Ptr &context,
                                           const SequenceType::Ptr &reqType)
{
    const Expression::Ptr me(PairContainer::typeCheck(context, reqType));
    const ItemType::Ptr t1(m_operand1->staticType()->itemType());
    const ItemType::Ptr t2(m_operand2->staticType()->itemType());
    Q_ASSERT(t1);
    Q_ASSERT(t2);

    if(*CommonSequenceTypes::Empty == *t1 ||
       *CommonSequenceTypes::Empty == *t2)
    {
        return EmptySequence::create(this, context);
    }
    else
    {
        prepareComparison(fetchComparator(t1, t2, context));

        return me;
    }
}

Expression::Ptr ValueComparison::compress(const StaticContext::Ptr &context)
{
    const Expression::Ptr me(PairContainer::compress(context));

    if(me != this)
        return me;

    if(isCaseInsensitiveCompare(m_operand1, m_operand2))
        useCaseInsensitiveComparator();

    return me;
}

bool ValueComparison::isCaseInsensitiveCompare(Expression::Ptr &op1, Expression::Ptr &op2)
{
    Q_ASSERT(op1);
    Q_ASSERT(op2);

    const ID iD = op1->id();

    if((iD == IDLowerCaseFN || iD == IDUpperCaseFN) && iD == op2->id())
    {
        /* Both are either fn:lower-case() or fn:upper-case(). */

        /* Replace the calls to the functions with its operands. */
        op1 = op1->operands().first();
        op2 = op2->operands().first();

        return true;
    }
    else
        return false;
}

OptimizationPass::List ValueComparison::optimizationPasses() const
{
    return OptimizationPasses::comparisonPasses;
}

SequenceType::List ValueComparison::expectedOperandTypes() const
{
    SequenceType::List result;
    result.append(CommonSequenceTypes::ZeroOrOneAtomicType);
    result.append(CommonSequenceTypes::ZeroOrOneAtomicType);
    return result;
}

SequenceType::Ptr ValueComparison::staticType() const
{
    if(m_operand1->staticType()->cardinality().allowsEmpty() ||
       m_operand2->staticType()->cardinality().allowsEmpty())
        return CommonSequenceTypes::ZeroOrOneBoolean;
    else
        return CommonSequenceTypes::ExactlyOneBoolean;
}

ExpressionVisitorResult::Ptr ValueComparison::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

Expression::ID ValueComparison::id() const
{
    return IDValueComparison;
}

QT_END_NAMESPACE
