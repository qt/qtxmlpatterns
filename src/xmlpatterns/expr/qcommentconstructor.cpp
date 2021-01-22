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
#include "qpatternistlocale_p.h"
#include "qnodebuilder_p.h"

#include "qcommentconstructor_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

CommentConstructor::CommentConstructor(const Expression::Ptr &op) : SingleContainer(op)
{
}

QString CommentConstructor::evaluateContent(const DynamicContext::Ptr &context) const
{
    const Item item(m_operand->evaluateSingleton(context));

    if(!item)
        return QString();

    const QString content(item.stringValue());

    if(content.contains(QLatin1String("--")))
    {
        context->error(QtXmlPatterns::tr("A comment cannot contain %1")
                       .arg(formatData("--")),
                       ReportContext::XQDY0072, this);
    }
    else if(content.endsWith(QLatin1Char('-')))
    {
        context->error(QtXmlPatterns::tr("A comment cannot end with a %1.")
                       .arg(formatData(QLatin1Char('-'))),
                       ReportContext::XQDY0072, this);
    }

    return content;
}

Item CommentConstructor::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const QString content(evaluateContent(context));
    const NodeBuilder::Ptr nodeBuilder(context->nodeBuilder(QUrl()));
    nodeBuilder->comment(content);

    const QAbstractXmlNodeModel::Ptr nm(nodeBuilder->builtDocument());
    context->addNodeModel(nm);

    return nm->root(QXmlNodeModelIndex());
}

void CommentConstructor::evaluateToSequenceReceiver(const DynamicContext::Ptr &context) const
{
    const QString content(evaluateContent(context));
    QAbstractXmlReceiver *const receiver = context->outputReceiver();

    receiver->comment(content);
}

SequenceType::Ptr CommentConstructor::staticType() const
{
    return CommonSequenceTypes::ExactlyOneComment;
}

SequenceType::List CommentConstructor::expectedOperandTypes() const
{
    SequenceType::List result;
    result.append(CommonSequenceTypes::ZeroOrOneString);
    return result;
}

Expression::Properties CommentConstructor::properties() const
{
    return DisableElimination | IsNodeConstructor;
}

ExpressionVisitorResult::Ptr
CommentConstructor::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

QT_END_NAMESPACE
