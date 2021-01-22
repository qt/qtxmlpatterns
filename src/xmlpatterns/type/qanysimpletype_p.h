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

#ifndef Patternist_AnySimpleType_H
#define Patternist_AnySimpleType_H

#include <private/qanytype_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    class AtomicType;

    /**
     * @short Represents the @c xs:anySimpleType item type.
     *
     * @ingroup Patternist_types
     * @see <a href="http://www.w3.org/TR/xmlschema-2/#dt-anySimpleType">XML Schema Part 2:
     * Datatypes Second Edition, The simple ur-type definition</a>
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AnySimpleType : public AnyType
    {
    public:
        typedef QExplicitlySharedDataPointer<AnySimpleType> Ptr;
        typedef QList<AnySimpleType::Ptr> List;
        friend class BuiltinTypes;

        ~AnySimpleType();

        QXmlName name(const NamePool::Ptr &np) const override;

        /**
         * @returns always @c xs:anySimpleType
         */
        QString displayName(const NamePool::Ptr &np) const override;

        /**
         * @returns always BuiltinTypes::xsAnyType
         */
        SchemaType::Ptr wxsSuperType() const override;

        /**
         * xs:anySimpleType is the special "simple ur-type". Therefore this function
         * returns SchemaType::None
         *
         * @returns SchemaType::None
         */
        TypeCategory category() const override;

        /**
         * The simple ur-type is a "special restriction of the ur-type definition",
         * according to XML Schema Part 2: Datatypes Second Edition about xs:anySimpleType
         *
         * @returns DERIVATION_RESTRICTION
         */
        SchemaType::DerivationMethod derivationMethod() const override;

        /**
         * Always returns @c true.
         */
        bool isSimpleType() const override;

        /**
         * Always returns @c false.
         */
        bool isComplexType() const override;

    protected:
        AnySimpleType();

    };
}

QT_END_NAMESPACE

#endif
