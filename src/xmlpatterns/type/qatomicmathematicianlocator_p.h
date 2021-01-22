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

#ifndef Patternist_AtomicTypeVisitorResultLocator_H
#define Patternist_AtomicTypeVisitorResultLocator_H

#include <private/qatomictypedispatch_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @todo Docs missing
     *
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AtomicMathematicianLocator : public ParameterizedAtomicTypeVisitor
    {
    public:
        typedef QExplicitlySharedDataPointer<AtomicMathematicianLocator> Ptr;

        inline AtomicMathematicianLocator()
        {
        }

        virtual ~AtomicMathematicianLocator();

        AtomicTypeVisitorResult::Ptr visit(const AnyAtomicType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const AnyURIType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const Base64BinaryType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const BooleanType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DateTimeType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DateType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DayTimeDurationType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DecimalType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DoubleType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DurationType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const FloatType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const GDayType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const GMonthDayType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const GMonthType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const GYearMonthType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const GYearType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const HexBinaryType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const IntegerType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const NOTATIONType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const QNameType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const StringType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const SchemaTimeType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const UntypedAtomicType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const YearMonthDurationType *,
                                           const qint16 op,
                                           const SourceLocationReflection *const reflection) const override;
    };
}

QT_END_NAMESPACE

#endif
