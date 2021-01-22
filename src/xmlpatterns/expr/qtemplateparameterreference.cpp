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

#include "qtemplateparameterreference_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

TemplateParameterReference::TemplateParameterReference(const VariableDeclaration *varDecl) : m_varDecl(varDecl)
{
}

bool TemplateParameterReference::evaluateEBV(const DynamicContext::Ptr &context) const
{
    return context->templateParameterStore()[m_varDecl->name]->evaluateEBV(context);
}

Item TemplateParameterReference::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    return context->templateParameterStore()[m_varDecl->name]->evaluateSingleton(context);
}

Item::Iterator::Ptr TemplateParameterReference::evaluateSequence(const DynamicContext::Ptr &context) const
{
    Q_ASSERT(!m_varDecl->name.isNull());
    Q_ASSERT(context->templateParameterStore()[m_varDecl->name]);
    return context->templateParameterStore()[m_varDecl->name]->evaluateSequence(context);
}

ExpressionVisitorResult::Ptr TemplateParameterReference::accept(const ExpressionVisitor::Ptr &visitor) const
{
    return visitor->visit(this);
}

Expression::Properties TemplateParameterReference::properties() const
{
    return DisableElimination;
}

SequenceType::Ptr TemplateParameterReference::staticType() const
{
    /* We can't use m_varDecl->expression()'s static type here, because
     * it's the default argument. */
    if(!m_varDecl->sequenceType)
        return CommonSequenceTypes::ZeroOrMoreItems;
    else
        return m_varDecl->sequenceType;
}

QT_END_NAMESPACE
