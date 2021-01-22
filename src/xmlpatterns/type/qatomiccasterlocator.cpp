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

#include "qatomiccasterlocator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

#define implCasterVisit(type)                                                                           \
AtomicTypeVisitorResult::Ptr AtomicCasterLocator::visit(const type *,                                   \
                                                        const SourceLocationReflection *const) const    \
{                                                                                                       \
    return AtomicTypeVisitorResult::Ptr();                                                              \
}

implCasterVisit(AnyAtomicType)
implCasterVisit(AnyURIType)
implCasterVisit(Base64BinaryType)
implCasterVisit(BooleanType)
implCasterVisit(DateTimeType)
implCasterVisit(DateType)
implCasterVisit(DayTimeDurationType)
implCasterVisit(DecimalType)
implCasterVisit(DoubleType)
implCasterVisit(DurationType)
implCasterVisit(FloatType)
implCasterVisit(GDayType)
implCasterVisit(GMonthDayType)
implCasterVisit(GMonthType)
implCasterVisit(GYearMonthType)
implCasterVisit(GYearType)
implCasterVisit(HexBinaryType)
implCasterVisit(IntegerType)
implCasterVisit(NOTATIONType)
implCasterVisit(QNameType)
implCasterVisit(StringType)
implCasterVisit(SchemaTimeType)
implCasterVisit(UntypedAtomicType)
implCasterVisit(YearMonthDurationType)

#undef implCasterVisit

QT_END_NAMESPACE
