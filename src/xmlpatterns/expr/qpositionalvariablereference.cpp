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

#include "qcommonsequencetypes_p.h"
#include "qinteger_p.h"

#include "qpositionalvariablereference_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

PositionalVariableReference::PositionalVariableReference(const VariableSlotID s) : VariableReference(s)
{
}

Item PositionalVariableReference::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    Q_ASSERT(context);
    Q_ASSERT(context->positionIterator(slot()));
    return Integer::fromValue(context->positionIterator(slot())->position());
}

bool PositionalVariableReference::evaluateEBV(const DynamicContext::Ptr &) const
{
    return true;
}

SequenceType::Ptr PositionalVariableReference::staticType() const
{
    return CommonSequenceTypes::ExactlyOneInteger;
}

Expression::Properties PositionalVariableReference::properties() const
{
    return DependsOnLocalVariable;
}

ExpressionVisitorResult::Ptr

PositionalVariableReference::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

QT_END_NAMESPACE
