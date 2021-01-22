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

#include "qbuiltintypes_p.h"
#include "qcommonsequencetypes_p.h"

#include "qparentnodeaxis_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item ParentNodeAxis::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    return context->contextItem().asNode().iterate(QXmlNodeModelIndex::AxisParent)->next();
}

Expression::Properties ParentNodeAxis::properties() const
{
    return DisableElimination | RequiresContextItem;
}

ExpressionVisitorResult::Ptr ParentNodeAxis::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

ItemType::Ptr ParentNodeAxis::expectedContextItemType() const
{
    return BuiltinTypes::node;
}

SequenceType::Ptr ParentNodeAxis::staticType() const
{
    // Parentless node exists.
    return CommonSequenceTypes::ZeroOrOneNode;
}

QT_END_NAMESPACE
