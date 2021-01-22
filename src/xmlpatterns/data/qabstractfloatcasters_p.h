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

#ifndef Patternist_AbstractFloatCasters_H
#define Patternist_AbstractFloatCasters_H

#include <private/qabstractfloat_p.h>
#include <private/qatomiccaster_p.h>
#include <private/qschemanumeric_p.h>

/**
 * @file
 * @short Contains classes sub-classing AtomicCaster and which
 * are responsible of casting an atomic value to AbstractFloat.
 */

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Casts a @c numeric value, such as @c xs:integer or @c xs:float, to @c xs:double or xs:float.
     *
     * castFrom() uses Numeric::toDouble() for doing the actual casting.
     *
     * @ingroup Patternist_xdm
     * @author Vincent Ricard <magic@magicninja.org>
     */
    template <const bool isDouble>
    class NumericToAbstractFloatCaster : public AtomicCaster
    {
    public:
        virtual Item castFrom(const Item &from,
                              const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    };

    /**
     * @short Casts a string value, @c xs:string or @c xs:untypedAtomic, to @c xs:double or xs:float.
     *
     * @ingroup Patternist_xdm
     * @author Vincent Ricard <magic@magicninja.org>
     */
    template <const bool isDouble>
    class StringToAbstractFloatCaster : public AtomicCaster
    {
    public:
        virtual Item castFrom(const Item &from,
                              const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    };

    /**
     * @short Casts a value of type @c xs:boolean to @c xs:double or xs:float.
     *
     * @ingroup Patternist_xdm
     * @author Vincent Ricard <magic@magicninja.org>
     */
    template <const bool isDouble>
    class BooleanToAbstractFloatCaster : public AtomicCaster
    {
        public:
            virtual Item castFrom(const Item &from,
                                  const QExplicitlySharedDataPointer<DynamicContext> &context) const;
    };

#include "qabstractfloatcasters_tpl_p.h"

   /**
    * @short Casts a @c numeric value, such as @c xs:integer or @c xs:float, to @c xs:double.
    *
    * castFrom() uses Numeric::toDouble() for doing the actual casting.
    *
    * @ingroup Patternist_xdm
    * @author Frans Englich <frans.englich@nokia.com>
    */
    typedef NumericToAbstractFloatCaster<true> NumericToDoubleCaster;

   /**
    * @short Casts a @c numeric value, such as @c xs:double or @c xs:decimal, to @c xs:float.
    *
    * castFrom() uses Numeric::toFloat() for doing the actual casting.
    *
    * @ingroup Patternist_xdm
    * @author Frans Englich <frans.englich@nokia.com>
    */
    typedef NumericToAbstractFloatCaster<false> NumericToFloatCaster;

    /**
     * @short Casts a string value, @c xs:string or @c xs:untypedAtomic, to @c xs:double.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    typedef StringToAbstractFloatCaster<true> StringToDoubleCaster;

    /**
     * @short Casts a string value, @c xs:string or @c xs:untypedAtomic, to @c xs:float.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    typedef StringToAbstractFloatCaster<false> StringToFloatCaster;

   /**
    * @short Casts a value of type @c xs:boolean to @c xs:double.
    *
    * @ingroup Patternist_xdm
    * @author Frans Englich <frans.englich@nokia.com>
    */
    typedef BooleanToAbstractFloatCaster<true> BooleanToDoubleCaster;

    /**
     * @short Casts a value of type @c xs:boolean to @c xs:float.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    typedef BooleanToAbstractFloatCaster<false> BooleanToFloatCaster;
}

QT_END_NAMESPACE

#endif
