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

#ifndef Patternist_NamespaceResolver_H
#define Patternist_NamespaceResolver_H

#include <QSharedData>
#include <QXmlName>


QT_BEGIN_NAMESPACE

template<typename A, typename B> class QHash;

namespace QPatternist
{

    /**
     * @short Base class for namespace resolvers.
     *
     * @ingroup Patternist
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class NamespaceResolver : public QSharedData
    {
    public:
        enum Constants
        {
            NoBinding = -1
        };

        typedef QExplicitlySharedDataPointer<NamespaceResolver> Ptr;

        /**
         * A list of namespace bindings. The key is the prefix, and the value is
         * the namespace URI.
         */
        typedef QHash<QXmlName::PrefixCode, QXmlName::NamespaceCode> Bindings;

        NamespaceResolver();
        virtual ~NamespaceResolver();

        /**
         * Adds the mapping from @p prefix to @p namespaceURI to
         * this NamespaceResolver. If this NamespaceResolver already contains
         * a binding involving @p prefix, the old binding is replaced.
         */
        virtual void addBinding(const QXmlName nb) = 0;

        /**
         * Resolves the @p prefix to the corresponding namespace URI. If no binding
         * exists for @p prefix, NoBinding is returned.
         *
         * @returns the namespace corresponding to @p prefix.
         */
        virtual QXmlName::NamespaceCode lookupNamespaceURI(const QXmlName::PrefixCode prefix) const = 0;

        /**
         * @returns all bindings this NamespaceResolver handles.
         */
        virtual Bindings bindings() const = 0;
    };
}

QT_END_NAMESPACE

#endif
