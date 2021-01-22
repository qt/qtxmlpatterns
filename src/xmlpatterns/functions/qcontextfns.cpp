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

#include "qanyuri_p.h"
#include "qdate_p.h"
#include "qschemadatetime_p.h"
#include "qdaytimeduration_p.h"
#include "qinteger_p.h"
#include "qliteral_p.h"
#include "qatomicstring_p.h"
#include "qschematime_p.h"

#include "qcontextfns_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item PositionFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    Q_ASSERT(context);
    return Integer::fromValue(context->contextPosition());
}

Item LastFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    Q_ASSERT(context);
    return Integer::fromValue(context->contextSize());
}

Item ImplicitTimezoneFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    return toItem(context->implicitTimezone());
}

Item CurrentDateTimeFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    return toItem(DateTime::fromDateTime(context->currentDateTime()));
}

Item CurrentDateFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    return toItem(Date::fromDateTime(context->currentDateTime()));
}

Item CurrentTimeFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    return toItem(SchemaTime::fromDateTime(context->currentDateTime()));
}

Expression::Ptr StaticBaseURIFN::typeCheck(const StaticContext::Ptr &context,
                                           const SequenceType::Ptr &reqType)
{
    /* Our base URI can never be undefined. */
    return wrapLiteral(toItem(AnyURI::fromValue(context->baseURI())), context, this)->typeCheck(context, reqType);
}

Expression::Ptr DefaultCollationFN::typeCheck(const StaticContext::Ptr &context,
                                              const SequenceType::Ptr &reqType)
{
    return wrapLiteral(AtomicString::fromValue(context->defaultCollation().toString()), context, this)->typeCheck(context, reqType);
}

QT_END_NAMESPACE
