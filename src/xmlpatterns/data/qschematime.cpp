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
#include "qitem_p.h"

#include "qschematime_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

SchemaTime::SchemaTime(const QDateTime &dateTime) : AbstractDateTime(dateTime)
{
}

SchemaTime::Ptr SchemaTime::fromLexical(const QString &lexical)
{
    static const CaptureTable captureTable( // STATIC DATA
        /* The extra paranthesis is a build fix for GCC 3.3. */
        (QRegExp(QLatin1String(
                "^\\s*"                             /* Any preceding whitespace. */
                "(\\d{2})"                          /* Hour part */
                ":"                                 /* Delimiter. */
                "(\\d{2})"                          /* Minutes part */
                ":"                                 /* Delimiter. */
                "(\\d{2,})"                         /* Seconds part. */
                "(?:\\.(\\d+))?"                    /* Milli seconds part. */
                "(?:(\\+|-)(\\d{2}):(\\d{2})|(Z))?" /* The zone offset, "+08:24". */
                "\\s*$"                             /* Any terminating whitespace. */))),
        /*zoneOffsetSignP*/         5,
        /*zoneOffsetHourP*/         6,
        /*zoneOffsetMinuteP*/       7,
        /*zoneOffsetUTCSymbolP*/    8,
        /*yearP*/                   -1,
        /*monthP*/                  -1,
        /*dayP*/                    -1,
        /*hourP*/                   1,
        /*minutesP*/                2,
        /*secondsP*/                3,
        /*msecondsP*/               4);

    AtomicValue::Ptr err;
    const QDateTime retval(create(err, lexical, captureTable));

    return err ? err : SchemaTime::Ptr(new SchemaTime(retval));
}

SchemaTime::Ptr SchemaTime::fromDateTime(const QDateTime &dt)
{
    Q_ASSERT(dt.isValid());
    /* Singleton value, allocated once instead of each time it's needed. */
    // STATIC DATA
    static const QDate time_defaultDate(AbstractDateTime::DefaultYear,
                                        AbstractDateTime::DefaultMonth,
                                        AbstractDateTime::DefaultDay);

    QDateTime result;
    copyTimeSpec(dt, result);

    result.setDate(time_defaultDate);
    result.setTime(dt.time());

    return SchemaTime::Ptr(new SchemaTime(result));
}

Item SchemaTime::fromValue(const QDateTime &dt) const
{
    Q_ASSERT(dt.isValid());
    return fromDateTime(dt);
}

QString SchemaTime::stringValue() const
{
    return timeToString() + zoneOffsetToString();
}

ItemType::Ptr SchemaTime::type() const
{
    return BuiltinTypes::xsTime;
}

QT_END_NAMESPACE
