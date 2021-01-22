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

#include <QUrl>

#include "qcommonsequencetypes_p.h"
#include "qnodebuilder_p.h"

#include "qtextnodeconstructor_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

TextNodeConstructor::TextNodeConstructor(const Expression::Ptr &op) : SingleContainer(op)
{
}

Item TextNodeConstructor::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item chars(m_operand->evaluateSingleton(context));

    if(!chars)
        return Item();

    const NodeBuilder::Ptr nodeBuilder(context->nodeBuilder(QUrl()));
    const QString &v = chars.stringValue();
    nodeBuilder->characters(QStringRef(&v));

    const QAbstractXmlNodeModel::Ptr nm(nodeBuilder->builtDocument());
    context->addNodeModel(nm);

    return nm->root(QXmlNodeModelIndex());
}

void TextNodeConstructor::evaluateToSequenceReceiver(const DynamicContext::Ptr &context) const
{
    const Item item(m_operand->evaluateSingleton(context));

    QAbstractXmlReceiver *const receiver = context->outputReceiver();

    if(item)
    {
        const QString &v = item.stringValue();
        receiver->characters(QStringRef(&v));
    }
    else
        receiver->characters(QStringRef());
}

SequenceType::Ptr TextNodeConstructor::staticType() const
{
    if(m_operand->staticType()->cardinality().allowsEmpty())
        return CommonSequenceTypes::ZeroOrOneTextNode;
    else
        return CommonSequenceTypes::ExactlyOneTextNode;
}

SequenceType::List TextNodeConstructor::expectedOperandTypes() const
{
    SequenceType::List result;
    result.append(CommonSequenceTypes::ZeroOrOneString);
    return result;
}

Expression::Properties TextNodeConstructor::properties() const
{
    return DisableElimination | IsNodeConstructor;
}

ExpressionVisitorResult::Ptr
TextNodeConstructor::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

QT_END_NAMESPACE
