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

#include "qgmonthday_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

GMonthDay::GMonthDay(const QDateTime &dateTime) : AbstractDateTime(dateTime)
{
}

GMonthDay::Ptr GMonthDay::fromLexical(const QString &lexical)
{
    static const CaptureTable captureTable( // STATIC DATA
        /* The extra paranthesis is a build fix for GCC 3.3. */
        (QRegExp(QLatin1String(
                "^\\s*"                             /* Any preceding whitespace. */
                "--"                                /* Delimiter. */
                "(\\d{2})"                          /* The month part. */
                "-"                                 /* Delimiter. */
                "(\\d{2})"                          /* The day part. */
                "(?:(\\+|-)(\\d{2}):(\\d{2})|(Z))?" /* The zone offset, "+08:24". */
                "\\s*$"                             /* Any terminating whitespace. */))),
        /*zoneOffsetSignP*/         3,
        /*zoneOffsetHourP*/         4,
        /*zoneOffsetMinuteP*/       5,
        /*zoneOffsetUTCSymbolP*/    6,
        /*yearP*/                   -1,
        /*monthP*/                  1,
        /*dayP*/                    2);

    AtomicValue::Ptr err;
    const QDateTime retval(create(err, lexical, captureTable));

    return err ? err : GMonthDay::Ptr(new GMonthDay(retval));
}

GMonthDay::Ptr GMonthDay::fromDateTime(const QDateTime &dt)
{
    QDateTime result(QDate(DefaultYear, dt.date().month(), dt.date().day()).startOfDay());
    copyTimeSpec(dt, result);

    return GMonthDay::Ptr(new GMonthDay(result));
}

QString GMonthDay::stringValue() const
{
    return m_dateTime.toString(QLatin1String("--MM-dd")) + zoneOffsetToString();
}

ItemType::Ptr GMonthDay::type() const
{
    return BuiltinTypes::xsGMonthDay;
}

QT_END_NAMESPACE
