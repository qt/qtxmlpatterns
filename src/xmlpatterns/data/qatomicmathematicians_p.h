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

#ifndef Patternist_AtomicMathematicians_H
#define Patternist_AtomicMathematicians_H

#include <private/qatomicmathematician_p.h>
#include <private/qsourcelocationreflection_p.h>

/**
 * @file
 * @short Contains classes performing arithemetic operations between atomic values, such as
 * subtracting two dates.
 */

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class DecimalMathematician : public AtomicMathematician
                               , public DelegatingSourceLocationReflection
    {
    public:
        inline DecimalMathematician(const SourceLocationReflection *const r) : DelegatingSourceLocationReflection(r)
        {
        }

        virtual Item calculate(const Item &o1,
                               const Operator op,
                               const Item &o2,
                               const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    };

    /**
     * @short Performs arithmetics between Integer values.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class IntegerMathematician : public AtomicMathematician
                               , public DelegatingSourceLocationReflection
    {
    public:
        inline IntegerMathematician(const SourceLocationReflection *const r) : DelegatingSourceLocationReflection(r)
        {
        }

        virtual Item calculate(const Item &o1,
                               const Operator op,
                               const Item &o2,
                               const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    };

    /**
     * @short Performs division or multiplication between either DayTimeDuration or YearMonthDuration
     * and Double values.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class DurationNumericMathematician : public AtomicMathematician
                                       , public DelegatingSourceLocationReflection
    {
    public:
        inline DurationNumericMathematician(const SourceLocationReflection *const r) : DelegatingSourceLocationReflection(r)
        {
        }

        virtual Item calculate(const Item &o1,
                               const Operator op,
                               const Item &o2,
                               const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    };

    /**
     * @short Performs division between DayTimeDuration and DayTimeDuration, or
     * YearMonthDuration and YearMonthDuration.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class DurationDurationDivisor : public AtomicMathematician
    {
    public:
        virtual Item calculate(const Item &o1,
                               const Operator op,
                               const Item &o2,
                               const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    };

    /**
     * @short Performs arithmetics between DayTimeDuration and DayTimeDuration, or
     * YearMonthDuration and YearMonthDuration.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class DurationDurationMathematician : public AtomicMathematician
    {
    public:
        virtual Item calculate(const Item &o1,
                               const Operator op,
                               const Item &o2,
                               const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    };

    /**
     * @short Delegates an AtomicMathematician and switches its operands.
     *
     * Switches the operands of the call to a call to the calculate()
     * on an AtomicMathematician such that the left operand becomes the right, and
     * vice versa.
     *
     * Its constructor takes an AtomicMathematician instance which this OperandSwitcherMathematician
     * should act as as a middle-man for, having the role of switching the two operands. Thus,
     * OperandSwitcherMathematician can be described as a proxy or delegator class.
     *
     * This class is used for implementing operator combinations such as
     * <tt>numeric * xs:yearMonthDuration</tt> and
     * <tt>xs:yearMonthDuration * numeric</tt>.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class OperandSwitcherMathematician : public AtomicMathematician
    {
    public:
        /**
         * Creates an OperandSwitcherMathematician.
         *
         * @param mathematician the AtomicMathematician this OperandSwitcherMathematician
         * should switch the operands for. Must be a non @c null, valid pointer.
         */
        OperandSwitcherMathematician(const AtomicMathematician::Ptr &mathematician);

        /**
         * Switch @p o1 and @p o2, and returns the value from the AtomicMathematician
         * this OperandSwitcherMathematician represents.
         */
        virtual Item calculate(const Item &o1,
                               const Operator op,
                               const Item &o2,
                               const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    private:
        const AtomicMathematician::Ptr m_mather;
    };

    /**
     * @short Performs arithmetics between an AbstractDateTime value and
     * an AbstractDuration value.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class DateTimeDurationMathematician : public AtomicMathematician
                                        , public DelegatingSourceLocationReflection
    {
    public:

        inline DateTimeDurationMathematician(const SourceLocationReflection *const r) : DelegatingSourceLocationReflection(r)
        {
        }

        /**
         * @p o1 is an AbstractDateTime and @p o2 is an AbstractDuration.
         *
         */
        virtual Item calculate(const Item &o1,
                               const Operator op,
                               const Item &o2,
                               const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    };

    /**
     * @short Performs arithmetics between two AbstractDateTime values.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AbstractDateTimeMathematician : public AtomicMathematician
    {
    public:
        virtual Item calculate(const Item &o1,
                               const Operator op,
                               const Item &o2,
                               const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    };
}

QT_END_NAMESPACE

#endif
