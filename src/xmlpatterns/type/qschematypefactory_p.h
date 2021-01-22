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

#ifndef Patternist_SchemaTypeFactory_H
#define Patternist_SchemaTypeFactory_H

#include <QSharedData>

#include <private/qreportcontext_p.h>
#include <private/qitemtype_p.h>
#include <private/qschematype_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A factory creating schema types.
     *
     * @ingroup Patternist_types
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class SchemaTypeFactory : public QSharedData
    {
    public:
        typedef QExplicitlySharedDataPointer<SchemaTypeFactory> Ptr;

        SchemaTypeFactory();
        virtual ~SchemaTypeFactory();

        /**
         * @returns a schema type for name @p name. If no schema type exists for @p name, @c null
         * is returned
         */
        virtual SchemaType::Ptr createSchemaType(const QXmlName name) const = 0;

        /**
         * @returns a dictionary containing the types this factory serves. The key
         * is the type's QName in Clark name syntax.
         */
        virtual SchemaType::Hash types() const = 0;

    private:
        Q_DISABLE_COPY(SchemaTypeFactory)
    };
}

QT_END_NAMESPACE

#endif
