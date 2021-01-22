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

#ifndef Patternist_XSLTNodeTest_H
#define Patternist_XSLTNodeTest_H

#include <private/qanynodetype_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Represents @c node() in patterns in XSL-T, which
     * are just like how @c node() usually is, except that it doesn't
     * match document nodes.
     *
     * @see <a href="http://www.w3.org/TR/xslt20/#pattern-semantics">XSL
     * Transformations (XSLT) Version 2.0, 5.5.3 The Meaning of a Pattern</a>
     * @ingroup Patternist_types
     * @author Frans Englich <frans.englich@nokia.com>
     * @since 4.5
     */
    class XSLTNodeTest : public AnyNodeType
    {
    public:
        bool xdtTypeMatches(const ItemType::Ptr &other) const override;
        bool itemMatches(const Item &item) const override;

        ItemType::Ptr xdtSuperType() const override;

    protected:
        friend class BuiltinTypes;

        /**
         * This constructor does nothing, but exists in order to make it impossible to
         * instantiate this class from anywhere but from BuiltinTypes.
         */
        inline XSLTNodeTest()
        {
        }
    };
}

QT_END_NAMESPACE

#endif
