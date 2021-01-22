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

#ifndef Patternist_NumericType_H
#define Patternist_NumericType_H

#include <private/qatomictype_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Represents the internal and abstract type @c fs:numeric.
     *
     * @see <a href="http://www.w3.org/TR/xquery-semantics/#dt-fs_numeric">XQuery 1.0
     * and XPath 2.0 Formal Semantics, Definition: fs:numeric</a>
     * @ingroup Patternist_types
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class NumericType : public AtomicType
    {
    public:
        virtual ~NumericType();

        bool itemMatches(const Item &item) const override;
        bool xdtTypeMatches(const ItemType::Ptr &other) const override;

        /**
         * @returns always "numeric". That is, no namespace prefix
         */
        QString displayName(const NamePool::Ptr &np) const override;

        /**
         * @returns always @c true
         */
        bool isAbstract() const override;

        /**
         * @returns always @c false
         */
        bool isNodeType() const override;

        /**
         * @returns always @c true
         */
        bool isAtomicType() const override;

        /**
         * @returns always xs:anyAtomicType
         */
        SchemaType::Ptr wxsSuperType() const override;

        /**
         * @returns always xs:anyAtomicType
         */
        ItemType::Ptr xdtSuperType() const override;

        /**
         * @returns @c null. It makes no sense to atomize the abstract type @c fs:numeric.
         */
        ItemType::Ptr atomizedType() const override;

        /**
         * NumericType cannot be visited. This function is only implemented
         * to satisfy the abstract super class's interface.
         *
         * @returns always a @c null pointer
         */
        AtomicTypeVisitorResult::Ptr accept(const AtomicTypeVisitor::Ptr &visitor,
                                            const SourceLocationReflection *const) const override;

        /**
         * NumericType cannot be visited. This function is only implemented
         * to satisfy the abstract super class's interface.
         *
         * @returns always a @c null pointer
         */
        AtomicTypeVisitorResult::Ptr accept(const ParameterizedAtomicTypeVisitor::Ptr &visitor,
                                            const qint16 op,
                                            const SourceLocationReflection *const) const override;

        /**
         * The type @c fs:numeric is an abstract type which therefore
         * cannot be involved in comparisons. Hence, this function returns
         * @c null. This function is only implemented to satisfy the abstract
         * super class's interface.
         *
         * @returns always a @c null pointer
         */
        AtomicComparatorLocator::Ptr comparatorLocator() const override;

        /**
         * The type @c fs:numeric is an abstract type which therefore
         * cannot be involved in arithmetics. Hence, this function returns
         * @c null. This function is only implemented to satisfy the abstract
         * super class's interface.
         *
         * @returns always a @c null pointer
         */
        AtomicMathematicianLocator::Ptr mathematicianLocator() const override;


        /**
         * The type @c fs:numeric is an abstract type which therefore
         * cannot be involved in casting. Hence, this function returns
         * @c null. This function is only implemented to satisfy the abstract
         * super class's interface.
         *
         * @returns always a @c null pointer
         */
        AtomicCasterLocator::Ptr casterLocator() const override;

    protected:
        friend class BuiltinTypes;
        NumericType();
    };
}

QT_END_NAMESPACE

#endif
