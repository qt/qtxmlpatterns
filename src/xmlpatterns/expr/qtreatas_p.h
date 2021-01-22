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

#ifndef Patternist_TreatAs_H
#define Patternist_TreatAs_H

#include <private/qsinglecontainer_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Implements XPath 2.0's <tt>treat as</tt> expression.
     *
     * TreatAs is always a compile-time class only, and is always deallocated
     * by re-writing to CardinalityVerifier or ItemVerifier or both, by calling
     * TypeChecker::applyFunctionConversion().
     *
     *
     * One approach could be to skip instantiating TreatAs and simply let the
     * return value of TypeChecker::applyFunctionConversion() be inserted into
     * the AST, but that wouldn't handle type checking the context item
     * properly, which depends on that the StaticContext have been set by the
     * parent Expression.
     *
     * @see <a href="http://www.w3.org/TR/xpath20/#id-treat">XML Path Language
     * (XPath) 2.0, 3.10.5 Treat</a>
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class TreatAs : public SingleContainer
    {
    public:
        /**
         * Creats a TreatAs where it is checked that the expression @p operand conforms
         * to the type @p reqType.
         */
        TreatAs(const Expression::Ptr &operand,
                const SequenceType::Ptr &reqType);

        /**
         * This function rewrites always. First the type that this TreatAs expression tests for
         * is verified. Then, the type the <tt>treat as</tt> expression itself must match, @p reqType,
         * is verified.
         */
        virtual Expression::Ptr typeCheck(const StaticContext::Ptr &context,
                                          const SequenceType::Ptr &reqType);

        /**
         * @returns always the SequenceType passed in the constructor to this class. That is, the
         * SequenceType that the operand must conform to.
         */
        virtual SequenceType::Ptr staticType() const;

        /**
         * @returns a list containing one CommonSequenceTypes::ZeroOrMoreItems
         */
        virtual SequenceType::List expectedOperandTypes() const;

        virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;

    private:
        const SequenceType::Ptr m_reqType;
    };
}

QT_END_NAMESPACE

#endif
