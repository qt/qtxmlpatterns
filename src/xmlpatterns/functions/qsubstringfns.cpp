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

#include "qboolean_p.h"
#include "qcommonvalues_p.h"
#include "qliteral_p.h"
#include "qatomicstring_p.h"

#include "qsubstringfns_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item ContainsFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item op1(m_operands.first()->evaluateSingleton(context));
    QString str1;

    if(op1)
        str1 = op1.stringValue();

    const Item op2(m_operands.at(1)->evaluateSingleton(context));
    QString str2;

    if(op2)
        str2 = op2.stringValue();

    if(str2.isEmpty())
        return CommonValues::BooleanTrue;

    if(str1.isEmpty())
        return CommonValues::BooleanFalse;

    return Boolean::fromValue(str1.contains(str2, caseSensitivity()));
}

Item StartsWithFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item op1(m_operands.first()->evaluateSingleton(context));
    QString str1;

    if(op1)
        str1 = op1.stringValue();

    const Item op2(m_operands.at(1)->evaluateSingleton(context));
    QString str2;

    if(op2)
        str2 = op2.stringValue();

    if(str2.isEmpty())
        return CommonValues::BooleanTrue;

    if(str1.isEmpty())
        return CommonValues::BooleanFalse;

    return Boolean::fromValue(str1.startsWith(str2, caseSensitivity()));
}

Item EndsWithFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item op1(m_operands.first()->evaluateSingleton(context));
    QString str1;

    if(op1)
        str1 = op1.stringValue();

    const Item op2(m_operands.at(1)->evaluateSingleton(context));
    QString str2;

    if(op2)
        str2 = op2.stringValue();

    if(str2.isEmpty())
        return CommonValues::BooleanTrue;

    if(str1.isEmpty())
        return CommonValues::BooleanFalse;

    return Boolean::fromValue(str1.endsWith(str2, caseSensitivity()));
}

Item SubstringBeforeFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item op1(m_operands.first()->evaluateSingleton(context));
    QString str1;

    if(op1)
        str1 = op1.stringValue();

    const Item op2(m_operands.at(1)->evaluateSingleton(context));
    QString str2;

    if(op2)
        str2 = op2.stringValue();

    const int pos = str1.indexOf(str2);
    if(pos == -1)
        return CommonValues::EmptyString;

    return AtomicString::fromValue(QString(str1.left(pos)));
}

Item SubstringAfterFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item op1(m_operands.first()->evaluateSingleton(context));
    QString str1;

    if(op1)
        str1 = op1.stringValue();

    const Item op2(m_operands.at(1)->evaluateSingleton(context));
    QString str2;

    if(op2)
        str2 = op2.stringValue();

    if(str2.isEmpty())
    {
        if(op1)
            return op1;
        else
            return CommonValues::EmptyString;
    }

    const int pos = str1.indexOf(str2);

    if(pos == -1)
        return CommonValues::EmptyString;

    return AtomicString::fromValue(QString(str1.right(str1.length() - (pos + str2.length()))));
}

QT_END_NAMESPACE
