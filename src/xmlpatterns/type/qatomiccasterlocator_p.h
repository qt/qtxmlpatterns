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

#ifndef Patternist_AtomicCasterLocator_H
#define Patternist_AtomicCasterLocator_H

#include <private/qatomictypedispatch_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AtomicCasterLocator : public AtomicTypeVisitor
    {
    public:
        typedef QExplicitlySharedDataPointer<AtomicCasterLocator> Ptr;

        AtomicTypeVisitorResult::Ptr visit(const AnyAtomicType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const AnyURIType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const Base64BinaryType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const BooleanType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DateTimeType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DateType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DayTimeDurationType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DecimalType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DoubleType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const DurationType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const FloatType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const GDayType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const GMonthDayType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const GMonthType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const GYearMonthType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const GYearType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const HexBinaryType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const IntegerType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const NOTATIONType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const QNameType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const StringType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const SchemaTimeType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const UntypedAtomicType *,
                                           const SourceLocationReflection *const reflection) const override;
        AtomicTypeVisitorResult::Ptr visit(const YearMonthDurationType *,
                                           const SourceLocationReflection *const reflection) const override;
    };
}

QT_END_NAMESPACE

#endif
