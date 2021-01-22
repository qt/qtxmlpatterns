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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_TimezoneFNs_H
#define Patternist_TimezoneFNs_H

#include <private/qatomiccomparator_p.h>
#include <private/qfunctioncall_p.h>

/**
 * @file
 * @short Contains classes implementing the functions found in
 * <a href="http://www.w3.org/TR/xpath-functions/#timezone.functions">XQuery 1.0 and
 * XPath 2.0 Functions and Operators, 10.7 Timezone Adjustment on Dates and SchemaTime Values</a>.
 * @ingroup Patternist_functions
 */

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Base class for classes implementing functions changing the timezone
     * on values.
     *
     * It would be possible to implement this with the Curiously Recurring Template Pattern, in order
     * to avoid the virtual call dispatching that is done via createValue(). However, these are not
     * very hot code paths and evaluateSingleton() is quite large, which would lead to heavy code
     * expansion.
     *
     * @see <a href="http://en.wikipedia.org/wiki/Curiously_recurring_template_pattern">Curiously
     * Recurring Template Pattern, Wikipedia, the free encyclopedia</a>
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AdjustTimezone : public FunctionCall
    {
    public:
        virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;

    protected:
        virtual Item createValue(const QDateTime &dt) const = 0;
    };

    /**
     * @short Implements the function <tt>fn:adjust-dateTime-to-timezone()</tt>.
     *
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AdjustDateTimeToTimezoneFN : public AdjustTimezone
    {
    protected:
        virtual Item createValue(const QDateTime &dt) const;
    };

    /**
     * @short Implements the function <tt>fn:adjust-dateTime-to-timezone()</tt>.
     *
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AdjustDateToTimezoneFN : public AdjustTimezone
    {
    protected:
        virtual Item createValue(const QDateTime &dt) const;
    };

    /**
     * @short Implements the function <tt>fn:adjust-time-to-timezone()</tt>.
     *
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AdjustTimeToTimezoneFN : public AdjustTimezone
    {
    protected:
        virtual Item createValue(const QDateTime &dt) const;
    };
}

QT_END_NAMESPACE

#endif
