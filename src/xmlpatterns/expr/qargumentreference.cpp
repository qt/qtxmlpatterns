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


#include "qargumentreference_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

ArgumentReference::ArgumentReference(const SequenceType::Ptr &sourceType,
                                     const VariableSlotID slotP) : VariableReference(slotP),
                                                                   m_type(sourceType)
{
    Q_ASSERT(m_type);
}

bool ArgumentReference::evaluateEBV(const DynamicContext::Ptr &context) const
{
    return context->expressionVariable(slot())->evaluateEBV(context);
}

Item ArgumentReference::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    return context->expressionVariable(slot())->evaluateSingleton(context);
}

Item::Iterator::Ptr ArgumentReference::evaluateSequence(const DynamicContext::Ptr &context) const
{
    return context->expressionVariable(slot())->evaluateSequence(context);
}

SequenceType::Ptr ArgumentReference::staticType() const
{
    return m_type;
}

ExpressionVisitorResult::Ptr ArgumentReference::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

Expression::ID ArgumentReference::id() const
{
    return IDArgumentReference;
}

QT_END_NAMESPACE
