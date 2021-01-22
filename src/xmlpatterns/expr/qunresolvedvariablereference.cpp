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

#include "qunresolvedvariablereference_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

UnresolvedVariableReference::UnresolvedVariableReference(const QXmlName &name) : m_name(name)
{
    Q_ASSERT(!m_name.isNull());
}

Expression::Ptr UnresolvedVariableReference::typeCheck(const StaticContext::Ptr &context,
                                                       const SequenceType::Ptr &reqType)
{
    /* We may be called before m_replacement is called, when we're part of a
     * function body whose type checking is performed for. See
     * UserFunctionCallsite::typeCheck(). */
    if(m_replacement)
        return m_replacement->typeCheck(context, reqType);
    else
        return EmptyContainer::typeCheck(context, reqType);
}

SequenceType::Ptr UnresolvedVariableReference::staticType() const
{
    /* We may be called by xmlpatternsview before the typeCheck() stage. */
    if(m_replacement)
        return m_replacement->staticType();
    else
        return CommonSequenceTypes::ZeroOrMoreItems;
}

SequenceType::List UnresolvedVariableReference::expectedOperandTypes() const
{
    return SequenceType::List();
}

ExpressionVisitorResult::Ptr UnresolvedVariableReference::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

Expression::ID UnresolvedVariableReference::id() const
{
    return IDUnresolvedVariableReference;
}

QT_END_NAMESPACE
