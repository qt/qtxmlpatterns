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

#ifndef Patternist_ValueFactory_H
#define Patternist_ValueFactory_H

#include <private/qitem_p.h>
#include <private/qreportcontext_p.h>
#include <private/qschematype_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Provides fromLexical(), which allows instantiation of atomic
     * values from arbitrary types.
     *
     * This class wraps the helper class CastingPlatform with a more specific,
     * high-level API.
     *
     * @see CastingPlatform
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_schema
     */
    class ValueFactory
    {
    public:
        /**
         * @short Returns an AtomicValue of type @p type from the lexical space
         * @p lexicalValue, and raise an error through @p context if that's
         * impossible.
         *
         * ValueFactory does not take ownership of @p sourceLocationReflection.
         */
        static AtomicValue::Ptr fromLexical(const QString &lexicalValue,
                                            const SchemaType::Ptr &type,
                                            const ReportContext::Ptr &context,
                                            const SourceLocationReflection *const sourceLocationReflection);

    private:
        Q_DISABLE_COPY(ValueFactory)
    };
}

QT_END_NAMESPACE

#endif
