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

#include "qatomiccomparator_p.h"
#include "qcommonvalues_p.h"
#include "qschemadatetime_p.h"
#include "qdaytimeduration_p.h"
#include "qdecimal_p.h"
#include "qinteger_p.h"
#include "qpatternistlocale_p.h"

#include "qdatetimefn_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item DateTimeFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item di(m_operands.first()->evaluateSingleton(context));
    if(!di)
        return Item();

    const Item ti(m_operands.last()->evaluateSingleton(context));
    if(!ti)
        return Item();

    QDateTime date(di.as<AbstractDateTime>()->toDateTime());
    Q_ASSERT(date.isValid());
    QDateTime time(ti.as<AbstractDateTime>()->toDateTime());
    Q_ASSERT(time.isValid());

    if(date.timeSpec() == time.timeSpec() || /* Identical timezone properties. */
       time.timeSpec() == Qt::LocalTime) /* time has no timezone, but date do. */
    {
        date.setTime(time.time());
        Q_ASSERT(date.isValid());
        return DateTime::fromDateTime(date);
    }
    else if(date.timeSpec() == Qt::LocalTime) /* date has no timezone, but time do. */
    {
        time.setDate(date.date());
        Q_ASSERT(time.isValid());
        return DateTime::fromDateTime(time);
    }
    else
    {
        context->error(QtXmlPatterns::tr("If both values have zone offsets, "
                                         "they must have the same zone offset. "
                                         "%1 and %2 are not the same.")
                       .arg(formatData(di.stringValue()),
                            formatData(di.stringValue())),
                       ReportContext::FORG0008, this);
        return Item(); /* Silence GCC warning. */
    }
}

QT_END_NAMESPACE
