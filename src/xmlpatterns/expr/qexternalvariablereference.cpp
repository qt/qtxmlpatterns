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


#include "qexternalvariablereference_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

ExternalVariableReference::ExternalVariableReference(const QXmlName &name,
                                                     const SequenceType::Ptr &type) : m_name(name),
                                                                                      m_seqType(type)
{
    Q_ASSERT(!m_name.isNull());
    Q_ASSERT(m_seqType);
}

Item::Iterator::Ptr ExternalVariableReference::evaluateSequence(const DynamicContext::Ptr &context) const
{
    Q_ASSERT(context->externalVariableLoader());
    return context->externalVariableLoader()->evaluateSequence(m_name, context);
}

Item ExternalVariableReference::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    return context->externalVariableLoader()->evaluateSingleton(m_name, context);
}

bool ExternalVariableReference::evaluateEBV(const DynamicContext::Ptr &context) const
{
    return context->externalVariableLoader()->evaluateEBV(m_name, context);
}

SequenceType::Ptr ExternalVariableReference::staticType() const
{
    return m_seqType;
}

Expression::Properties ExternalVariableReference::properties() const
{
    return DisableElimination;
}

ExpressionVisitorResult::Ptr ExternalVariableReference::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

QT_END_NAMESPACE
