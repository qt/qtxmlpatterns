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
#include "qstaticcompatibilitycontext_p.h"

#include "qstaticcompatibilitystore_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

StaticCompatibilityStore::StaticCompatibilityStore(const Expression::Ptr &operand) : SingleContainer(operand)
{
}

Expression::Ptr StaticCompatibilityStore::typeCheck(const StaticContext::Ptr &context,
                                              const SequenceType::Ptr &reqType)
{
    const StaticContext::Ptr newContext(new StaticCompatibilityContext(context));
    return m_operand->typeCheck(newContext, reqType);
}

SequenceType::Ptr StaticCompatibilityStore::staticType() const
{
    return m_operand->staticType();
}

SequenceType::List StaticCompatibilityStore::expectedOperandTypes() const
{
    SequenceType::List ops;
    ops.append(CommonSequenceTypes::ZeroOrMoreItems);
    return ops;
}

ExpressionVisitorResult::Ptr StaticCompatibilityStore::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

QT_END_NAMESPACE
