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

#include "qvaluecomparison_p.h"

#include "qcomparescaseaware_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

ComparesCaseAware::ComparesCaseAware() : m_caseSensitivity(Qt::CaseSensitive)
{
}

Expression::Ptr ComparesCaseAware::compress(const StaticContext::Ptr &context)
{
    Q_ASSERT(m_operands.size() >= 2);

    if(ValueComparison::isCaseInsensitiveCompare(m_operands.first(), m_operands[1]))
        m_caseSensitivity = Qt::CaseInsensitive;
    else
    {
        /* Yes, we could probably skip this since m_caseSensitivity is initialized to this value,
         * but perhaps subsequent calls to compress() can make isCaseInsensitiveCompare() return
         * a different value. */
        m_caseSensitivity = Qt::CaseSensitive;
    }

    return FunctionCall::compress(context);
}

QT_END_NAMESPACE
