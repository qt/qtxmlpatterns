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

#ifndef Patternist_AtomicCaster_H
#define Patternist_AtomicCaster_H

#include <private/qdynamiccontext_p.h>
#include <private/qitem_p.h>
#include <private/qatomictypedispatch_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short AtomicCaster is an abstract base class for classes
     * that performs casting between two atomic values of specific types.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AtomicCaster : public AtomicTypeVisitorResult
    {
    public:
        typedef QExplicitlySharedDataPointer<AtomicCaster> Ptr;
        AtomicCaster();
        virtual ~AtomicCaster();

        /**
         * Casts @p from to an atomic value of the type this class
         * casts to, and returns that value. The @p context is used
         * for reporting errors in case the casting fails, and to in general
         * access information from the dynamic context.
         */
        virtual Item castFrom(const Item &from,
                              const QExplicitlySharedDataPointer<DynamicContext> &context) const = 0;
    };
}

QT_END_NAMESPACE

#endif
