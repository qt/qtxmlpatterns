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

#ifndef Patternist_XsdSchemaTypesFactory_H
#define Patternist_XsdSchemaTypesFactory_H

#include <QtCore/QHash>
#include <private/qschematypefactory_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Factory for creating schema types for the types defined in XSD.
     *
     * @ingroup Patternist_types
     * @author Tobias Koenig <tobias.koenig@nokia.com>
     */
    class XsdSchemaTypesFactory : public SchemaTypeFactory
    {
        public:
            /**
             * Creates a new schema type factory.
             *
             * @param namePool The name pool all type names belong to.
             */
            XsdSchemaTypesFactory(const NamePool::Ptr &namePool);

            /**
             * Creates a primitive type for @p name. If @p name is not supported,
             * @c null is returned.
             *
             * @note This does not handle user defined types, only builtin types.
             */
            virtual SchemaType::Ptr createSchemaType(const QXmlName) const;

            /**
             * Returns a hash of all available types.
             */
            virtual SchemaType::Hash types() const;

        private:
            /**
             * A dictonary of all predefined schema types.
             */
            SchemaType::Hash               m_types;

            NamePool::Ptr                  m_namePool;
            mutable SchemaTypeFactory::Ptr m_basicTypesFactory;
    };
}

QT_END_NAMESPACE

#endif
