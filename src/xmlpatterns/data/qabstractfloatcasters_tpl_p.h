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
//

/*
 * NOTE: This file is included by qabstractfloatcasters_p.h
 * if you need some includes, put them in qabstractfloatcasters_p.h (outside of the namespace)
 */

template <const bool isDouble>
Item NumericToAbstractFloatCaster<isDouble>::castFrom(const Item &from,
                                                           const QExplicitlySharedDataPointer<DynamicContext> &) const
{
    // toDouble() returns same thing than toFloat()
    return toItem(AbstractFloat<isDouble>::fromValue(from.template as<Numeric>()->toDouble()));
}

template <const bool isDouble>
Item StringToAbstractFloatCaster<isDouble>::castFrom(const Item &from,
                                                          const QExplicitlySharedDataPointer<DynamicContext> &) const
{
    return toItem(AbstractFloat<isDouble>::fromLexical(from.stringValue()));
}

template <const bool isDouble>
Item BooleanToAbstractFloatCaster<isDouble>::castFrom(const Item &from,
                                                           const QExplicitlySharedDataPointer<DynamicContext> &context) const
{
    // RVCT doesn't like using template parameter in trinary operator when the trinary operator result is
    // passed directly into another constructor.
    bool tempDouble = isDouble;
    if(from.template as<AtomicValue>()->evaluateEBV(context))
        return tempDouble ? toItem(CommonValues::DoubleOne) : toItem(CommonValues::FloatOne);
    else
        return tempDouble ? toItem(CommonValues::DoubleZero) : toItem(CommonValues::FloatZero);
}

