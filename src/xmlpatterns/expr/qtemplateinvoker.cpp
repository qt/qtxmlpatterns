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

#include "qtemplateinvoker_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

TemplateInvoker::TemplateInvoker(const WithParam::Hash &withParams,
                                 const QXmlName &name) : CallSite(name)
                                                       , m_withParams(withParams)
{
    const WithParam::Hash::const_iterator end(m_withParams.constEnd());

    for(WithParam::Hash::const_iterator it(m_withParams.constBegin()); it != end; ++it)
    {
        /* In the case of for instance:
         *  <xsl:with-param name="empty_seq" as="item()"/>
         *
         * we have no default expression. */
        Q_ASSERT(it.value()->sourceExpression());
        m_operands.append(it.value()->sourceExpression());
    }
}

Expression::Ptr TemplateInvoker::compress(const StaticContext::Ptr &context)
{
    /* CallSite::compress() may have changed our children, so update
     * our m_withParams. */
    const Expression::Ptr me(CallSite::compress(context));
    const WithParam::Hash::const_iterator end(m_withParams.constEnd());
    int exprIndex = -1;

    for(WithParam::Hash::const_iterator it(m_withParams.constBegin()); it != end; ++it)
    {
        if(it.value()->sourceExpression())
        {
            ++exprIndex;
            it.value()->setSourceExpression(m_operands.at(exprIndex));
        }
    }

    return me;
}

SequenceType::List TemplateInvoker::expectedOperandTypes() const
{
    SequenceType::List result;

    /* We don't return the type of the m_template->templateParameters(), we
     * return the type of the @c xsl:with-param first. @em After that, we
     * manually apply the parameter types in typeCheck(). */
    const WithParam::Hash::const_iterator end(m_withParams.constEnd());

    for(WithParam::Hash::const_iterator it(m_withParams.constBegin()); it != end; ++it)
    {
        /* We're not guaranteed to have a with-param, we may be using the
         * default value of the xsl:param. Tunnel parameters may also play
         * in. */
        result.append(it.value()->type());
    }

    return result;
}

QT_END_NAMESPACE

