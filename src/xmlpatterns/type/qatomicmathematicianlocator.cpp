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

#include "qatomicmathematicianlocator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

AtomicMathematicianLocator::~AtomicMathematicianLocator()
{
}

#define implVisit(type)                                                                                     \
AtomicTypeVisitorResult::Ptr AtomicMathematicianLocator::visit(const type *, const qint16,                  \
                                                               const SourceLocationReflection *const) const \
{                                                                                                           \
    return AtomicTypeVisitorResult::Ptr();                                                                  \
}

implVisit(AnyAtomicType)
implVisit(AnyURIType)
implVisit(Base64BinaryType)
implVisit(BooleanType)
implVisit(DateTimeType)
implVisit(DateType)
implVisit(DayTimeDurationType)
implVisit(DecimalType)
implVisit(DoubleType)
implVisit(DurationType)
implVisit(FloatType)
implVisit(GDayType)
implVisit(GMonthDayType)
implVisit(GMonthType)
implVisit(GYearMonthType)
implVisit(GYearType)
implVisit(HexBinaryType)
implVisit(IntegerType)
implVisit(NOTATIONType)
implVisit(QNameType)
implVisit(StringType)
implVisit(SchemaTimeType)
implVisit(UntypedAtomicType)
implVisit(YearMonthDurationType)
#undef implVisit

QT_END_NAMESPACE
