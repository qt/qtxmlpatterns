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

#include "qnamespaceconstructor_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

NamespaceConstructor::NamespaceConstructor(const QXmlName nb) : m_binding(nb)
{
    Q_ASSERT(!m_binding.isNull());
}

/*! \internal */
NamespaceConstructor::~NamespaceConstructor()
{
}

void NamespaceConstructor::evaluateToSequenceReceiver(const DynamicContext::Ptr &context) const
{
    context->outputReceiver()->namespaceBinding(m_binding);
}

SequenceType::Ptr NamespaceConstructor::staticType() const
{
    return CommonSequenceTypes::ExactlyOneAttribute;
}

SequenceType::List NamespaceConstructor::expectedOperandTypes() const
{
    SequenceType::List result;
    result.append(CommonSequenceTypes::ExactlyOneString);
    return result;
}

Expression::Properties NamespaceConstructor::properties() const
{
    return DisableElimination | IsNodeConstructor;
}

ExpressionVisitorResult::Ptr NamespaceConstructor::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

Expression::ID NamespaceConstructor::id() const
{
    return IDNamespaceConstructor;
}

QT_END_NAMESPACE
