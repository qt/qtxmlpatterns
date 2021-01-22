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

#include "qgyear_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

GYear::GYear(const QDateTime &dateTime) : AbstractDateTime(dateTime)
{
}

GYear::Ptr GYear::fromLexical(const QString &lexical)
{
    static const CaptureTable captureTable( // STATIC DATA
        /* The extra paranthesis is a build fix for GCC 3.3. */
        (QRegExp(QLatin1String(
                "^\\s*"                             /* Any preceding whitespace. */
                "(-?)"                              /* Any preceding minus. */
                "(-?\\d{4,})"                       /* The year part, "1999". */
                "(?:(\\+|-)(\\d{2}):(\\d{2})|(Z))?" /* The zone offset, "+08:24". */
                "\\s*$"                             /* Any terminating whitespace. */))),
        /*zoneOffsetSignP*/         3,
        /*zoneOffsetHourP*/         4,
        /*zoneOffsetMinuteP*/       5,
        /*zoneOffsetUTCSymbolP*/    6,
        /*yearP*/                   2,
        /*monthP*/                  -1,
        /*dayP*/                    -1,
        /*hourP*/                   -1,
        /*minutesP*/                -1,
        /*secondsP*/                -1,
        /*msecondsP*/               -1,
        /*yearSign*/                1);

    AtomicValue::Ptr err;
    const QDateTime retval(create(err, lexical, captureTable));

    return err ? err : GYear::Ptr(new GYear(retval));
}

GYear::Ptr GYear::fromDateTime(const QDateTime &dt)
{
    const QDate date(dt.date().year(), DefaultMonth, DefaultDay);
    QDateTime result(date.startOfDay());
    copyTimeSpec(dt, result);

    return GYear::Ptr(new GYear(result));
}

QString GYear::stringValue() const
{
    return m_dateTime.toString(QLatin1String("yyyy")) + zoneOffsetToString();
}

ItemType::Ptr GYear::type() const
{
    return BuiltinTypes::xsGYear;
}

QT_END_NAMESPACE
