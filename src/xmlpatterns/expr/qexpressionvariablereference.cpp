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


#include "qexpressionvariablereference_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

ExpressionVariableReference::ExpressionVariableReference(const VariableSlotID slotP,
                                                         const VariableDeclaration *varDecl) : VariableReference(slotP)
                                                                                             , m_varDecl(varDecl)
{
}

bool ExpressionVariableReference::evaluateEBV(const DynamicContext::Ptr &context) const
{
    return context->expressionVariable(slot())->evaluateEBV(context);
}

Item ExpressionVariableReference::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    return context->expressionVariable(slot())->evaluateSingleton(context);
}

Item::Iterator::Ptr ExpressionVariableReference::evaluateSequence(const DynamicContext::Ptr &context) const
{
    return context->expressionVariable(slot())->evaluateSequence(context);
}
Expression::Ptr ExpressionVariableReference::typeCheck(const StaticContext::Ptr &context,
                                                       const SequenceType::Ptr &reqType)
{
    if(m_varDecl->canSourceRewrite)
        return m_varDecl->expression()->typeCheck(context, reqType);
    else
        return VariableReference::typeCheck(context, reqType);
}

Expression::ID ExpressionVariableReference::id() const
{
    return IDExpressionVariableReference;
}

ExpressionVisitorResult::Ptr ExpressionVariableReference::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

SequenceType::Ptr ExpressionVariableReference::staticType() const
{
    return m_varDecl->expression()->staticType();
}

QT_END_NAMESPACE
