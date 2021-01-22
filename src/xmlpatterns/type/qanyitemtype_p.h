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

#ifndef Patternist_AnyItemType_H
#define Patternist_AnyItemType_H

#include <private/qatomictype_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Represents the <tt>item()</tt> item type.
     *
     * @ingroup Patternist_types
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AnyItemType : public ItemType
    {
    public:
        /**
         * @returns always "item()"
         */
        QString displayName(const NamePool::Ptr &np) const override;

        /**
         * @returns always @c true
         */
        bool itemMatches(const Item &item) const override;

        /**
         * @returns always 0, item() is the super type in the
         * XPath Data Model hierarchy
         */
        ItemType::Ptr xdtSuperType() const override;

        /**
         * @returns always @c false
         */
        bool isNodeType() const override;

        /**
         * @returns always @c false
         */
        bool isAtomicType() const override;

        /**
         * @returns always @c true
         */
        bool xdtTypeMatches(const ItemType::Ptr &type) const override;

        /**
         * @returns xs:anyAtomicType
         */
        ItemType::Ptr atomizedType() const override;

    protected:
        friend class BuiltinTypes;
        AnyItemType();
    };
}

QT_END_NAMESPACE

#endif
