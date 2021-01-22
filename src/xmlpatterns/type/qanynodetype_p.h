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

#ifndef Patternist_AnyNodeType_H
#define Patternist_AnyNodeType_H

#include <private/qatomictype_p.h>
#include <private/qitem_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Represents the <tt>node()</tt> item type.
     *
     * @ingroup Patternist_types
     * @see BuiltinNodeType
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AnyNodeType : public ItemType
    {
    public:

        typedef QExplicitlySharedDataPointer<AnyNodeType> Ptr;

        bool xdtTypeMatches(const ItemType::Ptr &other) const override;
        bool itemMatches(const Item &item) const override;
        QString displayName(const NamePool::Ptr &np) const override;

        ItemType::Ptr xdtSuperType() const override;

        bool isNodeType() const override;
        bool isAtomicType() const override;

        /**
         * @see <a href="http://www.w3.org/TR/xpath-datamodel/#acc-summ-typed-value">XQuery 1.0
         * and XPath 2.0 Data Model, G.15 dm:typed-value Accessor</a>
         */
        ItemType::Ptr atomizedType() const override;

        /**
         * @returns the node kind this node ItemType tests for. If it matches any node, zero is returned.
         */
        virtual QXmlNodeModelIndex::NodeKind nodeKind() const;

        virtual PatternPriority patternPriority() const;

    protected:
        friend class BuiltinTypes;

        inline AnyNodeType()
        {
        }

    };
}

QT_END_NAMESPACE

#endif
