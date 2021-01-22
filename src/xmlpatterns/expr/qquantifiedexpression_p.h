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

#ifndef Patternist_QuantifiedExpression_H
#define Patternist_QuantifiedExpression_H

#include <private/qpaircontainer_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Implements XPath 2.0's quantification expressions @c some and @c every.
     *
     * @see <a href="http://www.w3.org/TR/xpath20/#id-quantified-expressions">XML Path Language
     * (XPath) 2.0, 3.9 Quantified Expressions</a>
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class Q_AUTOTEST_EXPORT QuantifiedExpression : public PairContainer
    {
    public:
        enum Operator
        {
            Some    = 1,
            Every
        };

        QuantifiedExpression(const VariableSlotID varSlot,
                             const Operator quantifier,
                             const Expression::Ptr &inClause,
                             const Expression::Ptr &testExpression);

        virtual bool evaluateEBV(const DynamicContext::Ptr &context) const;
        virtual SequenceType::Ptr staticType() const;
        virtual SequenceType::List expectedOperandTypes() const;

        Operator operatorID() const;

        /**
         * Determines the string representation for a quantification operator.
         *
         * @return "some" if @p quantifier is Some, or "every" if @p quantifier
         * is Every
         */
        static QString displayName(const Operator quantifier);

        virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;

        inline Item mapToItem(const Item &item, const DynamicContext::Ptr &context) const;

    private:
        typedef QExplicitlySharedDataPointer<const QuantifiedExpression> ConstPtr;
        const VariableSlotID m_varSlot;
        const Operator m_quantifier;
    };
}

QT_END_NAMESPACE

#endif
