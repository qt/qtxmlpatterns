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

#include "qcommonvalues_p.h"
#include "qgenericsequencetype_p.h"
#include "qschemanumeric_p.h"

#include "qnumericfns_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item FloorFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item num(m_operands.first()->evaluateSingleton(context));

    if(!num)
        return Item();

    return toItem(num.as<Numeric>()->floor());
}

Item AbsFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item num(m_operands.first()->evaluateSingleton(context));

    if(!num)
        return Item();

    return toItem(num.as<Numeric>()->abs());
}

Item RoundFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item num(m_operands.first()->evaluateSingleton(context));

    if(!num)
        return Item();

    return toItem(num.as<Numeric>()->round());
}

Item CeilingFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item num(m_operands.first()->evaluateSingleton(context));

    if(!num)
        return Item();

    return toItem(num.as<Numeric>()->ceiling());
}

Item RoundHalfToEvenFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item num(m_operands.first()->evaluateSingleton(context));

    if(!num)
        return Item();

    xsInteger scale = 0;

    if(m_operands.count() == 2)
        scale = m_operands.at(1)->evaluateSingleton(context).as<Numeric>()->toInteger();

    return toItem(num.as<Numeric>()->roundHalfToEven(scale));
}

QT_END_NAMESPACE
