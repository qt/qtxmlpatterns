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
#include "qcommonvalues_p.h"

#include "qyearmonthduration_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

YearMonthDuration::YearMonthDuration(const bool isPositiveP,
                                     const YearProperty yearsP,
                                     const MonthProperty monthsP) : AbstractDuration(isPositiveP),
                                                                    m_years(yearsP),
                                                                    m_months(monthsP)
{
    Q_ASSERT(monthsP < 32 && monthsP > -32);
}

YearMonthDuration::Ptr YearMonthDuration::fromLexical(const QString &lexical)
{
    static const CaptureTable captureTable(
        /* The extra paranthesis is a build fix for GCC 3.3. */
        (QRegExp(QLatin1String(
                "^\\s*"         /* Any preceding whitespace. */
                "(-)?"          /* Sign, if any. */
                "P"             /* Delimiter. */
                "(?:(\\d+)Y)?"  /* The years part. */
                "(?:(\\d+)M)?"  /* The months part. */
                "\\s*$"         /* Any terminating whitespace. */))),
        2,                      /* yearP. */
        3                       /* monthP. */);

    YearProperty years = 0;
    MonthProperty months = 0;
    bool isPos;

    const AtomicValue::Ptr err(create(captureTable, lexical, &isPos, &years,
                                      &months, 0, 0, 0, 0, 0));

    return err ? err : YearMonthDuration::Ptr(new YearMonthDuration(isPos, years, months));
}

YearMonthDuration::Ptr YearMonthDuration::fromComponents(const bool isPositive,
                                                         const YearProperty years,
                                                         const MonthProperty months)
{
    return YearMonthDuration::Ptr(new YearMonthDuration(isPositive, years, months));
}

QString YearMonthDuration::stringValue() const
{
    QString retval;

    if(!m_isPositive)
        retval.append(QLatin1Char('-'));

    retval.append(QLatin1Char('P'));

    /* When years == 0 and months == 0, we get "P0M", which
     * is the correct canonical form. */
    if(m_years)
    {
        retval.append(QString::number(m_years));
        retval.append(QLatin1Char('Y'));

        if(m_months)
        {
            retval.append(QString::number(m_months));
            retval.append(QLatin1Char('M'));
        }
    }
    else
    {
        if(m_months)
        {
            retval.append(QString::number(m_months));
            retval.append(QLatin1Char('M'));
        }
        else
            return QLatin1String("P0M"); /* Ensure the canonical form. */
    }

    return retval;
}

AbstractDuration::Value YearMonthDuration::value() const
{
    return (m_years * 12 + m_months) * (m_isPositive ? 1 : -1);
}

Item YearMonthDuration::fromValue(const Value val) const
{
    if(val == 0)
        return toItem(CommonValues::YearMonthDurationZero);
    else
    {
        const Value absValue = qAbs(val);
        return toItem(YearMonthDuration::fromComponents(val >= 0,
                                                        absValue / 12,
                                                        absValue % 12));
    }
}

ItemType::Ptr YearMonthDuration::type() const
{
    return BuiltinTypes::xsYearMonthDuration;
}

YearProperty YearMonthDuration::years() const
{
    return m_years;
}

MonthProperty YearMonthDuration::months() const
{
    return m_months;
}

DayCountProperty YearMonthDuration::days() const
{
    return 0;
}

HourProperty YearMonthDuration::hours() const
{
    return 0;
}

MinuteProperty YearMonthDuration::minutes() const
{
    return 0;
}

SecondProperty YearMonthDuration::seconds() const
{
    return 0;
}

MSecondProperty YearMonthDuration::mseconds() const
{
    return 0;
}


QT_END_NAMESPACE
