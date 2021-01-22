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

#include "qgday_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

GDay::GDay(const QDateTime &dateTime) : AbstractDateTime(dateTime)
{
}

GDay::Ptr GDay::fromLexical(const QString &lexical)
{
    static const CaptureTable captureTable( // STATIC DATA
        /* The extra paranthesis is a build fix for GCC 3.3. */
        (QRegExp(QLatin1String(
                "^\\s*"                                 /* Any preceding whitespace. */
                "---"                                   /* Delimiter. */
                "(\\d{2})"                              /* The day part, "03". */
                "(?:(?:(\\+|-))(\\d{2}):(\\d{2})|(Z))?" /* Timezone, "+08:24". */
                "\\s*$"                                 /* Any whitespace at the end. */))),
        /*zoneOffsetSignP*/         2,
        /*zoneOffsetHourP*/         3,
        /*zoneOffsetMinuteP*/       4,
        /*zoneOffsetUTCSymbolP*/    5,
        /*yearP*/                   -1,
        /*monthP*/                  -1,
        /*dayP*/                    1);

    AtomicValue::Ptr err;
    const QDateTime retval(create(err, lexical, captureTable));

    return err ? err : GDay::Ptr(new GDay(retval));
}

GDay::Ptr GDay::fromDateTime(const QDateTime &dt)
{
    const QDate date(DefaultYear, DefaultMonth, dt.date().day());
    QDateTime result(date.startOfDay());
    copyTimeSpec(dt, result);

    return GDay::Ptr(new GDay(result));
}

QString GDay::stringValue() const
{
    return m_dateTime.toString(QLatin1String("---dd")) + zoneOffsetToString();
}

ItemType::Ptr GDay::type() const
{
    return BuiltinTypes::xsGDay;
}

QT_END_NAMESPACE
