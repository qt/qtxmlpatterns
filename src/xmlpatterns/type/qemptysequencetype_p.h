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

#ifndef Patternist_EmptySequenceType_H
#define Patternist_EmptySequenceType_H

#include <private/qatomictype_p.h>
#include <private/qsequencetype_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Represents the <tt>empty-sequence()</tt> type.
     *
     * @ingroup Patternist_types
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class EmptySequenceType : public ItemType,
                              public SequenceType
    {
    public:
        typedef QExplicitlySharedDataPointer<EmptySequenceType> Ptr;

        /**
         * Possibly surprisingly, this function also returns true for the @c none type.
         *
         * @returns @c true if @p other is NoneType or EmptySequenceType, otherwise @c false.
         */
        bool xdtTypeMatches(const ItemType::Ptr &other) const override;

        /**
         * @returns always @c false
         */
        bool itemMatches(const Item &item) const override;

        /**
         * @returns always "empty-sequence()"
         */
        QString displayName(const NamePool::Ptr &np) const override;

        ItemType::Ptr xdtSuperType() const override;

        bool isNodeType() const override;
        bool isAtomicType() const override;

        /**
         * @return always Cardinality::empty()
         */
        Cardinality cardinality() const override;

        /**
         * @returns always 'this' since it is also an ItemType
         */
        ItemType::Ptr itemType() const override;

        /**
         * @returns always @c xs:anyAtomicType
         */
        ItemType::Ptr atomizedType() const override;

    protected:
        friend class CommonSequenceTypes;
        EmptySequenceType();
    };
}

QT_END_NAMESPACE

#endif
