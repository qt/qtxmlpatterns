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

#include "qboolean_p.h"
#include "qgenericsequencetype_p.h"

#include "qrangevariablereference_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

RangeVariableReference::RangeVariableReference(const Expression::Ptr &source,
                                               const VariableSlotID slotP) : VariableReference(slotP),
                                                                             m_sourceExpression(source)
{
    Q_ASSERT(source);
}

bool RangeVariableReference::evaluateEBV(const DynamicContext::Ptr &context) const
{
    Q_ASSERT_X(context->rangeVariable(slot()), Q_FUNC_INFO, "The range variable must be set.");
    return Boolean::evaluateEBV(context->rangeVariable(slot()), context);
}

Item RangeVariableReference::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    Q_ASSERT_X(context->rangeVariable(slot()), Q_FUNC_INFO, "The range variable must be set.");
    return context->rangeVariable(slot());
}

SequenceType::Ptr RangeVariableReference::staticType() const
{
    return makeGenericSequenceType(m_sourceExpression->staticType()->itemType(),
                                   Cardinality::exactlyOne());
}

Expression::ID RangeVariableReference::id() const
{
    return IDRangeVariableReference;
}

ExpressionVisitorResult::Ptr
RangeVariableReference::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

Expression::Properties RangeVariableReference::properties() const
{
    return DependsOnLocalVariable;
}

QT_END_NAMESPACE
