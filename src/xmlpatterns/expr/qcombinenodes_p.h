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

#ifndef Patternist_CombineNodes_H
#define Patternist_CombineNodes_H

#include <private/qpaircontainer_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Implements XPath 2.0's operators for combining node sequences: @c union,
     * @c intersect and @c except.
     *
     * @see <a href="http://www.w3.org/TR/xquery/#combining_seq">XQuery 1.0: An XML Query
     * Language, 3.3.3 Combining QXmlNodeModelIndex Sequences</a>
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class Q_AUTOTEST_EXPORT CombineNodes : public PairContainer
    {
    public:
        enum Operator
        {
            Union       = 1,
            Intersect   = 2,
            Except      = 4
        };

        CombineNodes(const Expression::Ptr &operand1,
                     const Operator op,
                     const Expression::Ptr &operand2);

        virtual Item::Iterator::Ptr evaluateSequence(const DynamicContext::Ptr &context) const;
        virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;
        virtual bool evaluateEBV(const DynamicContext::Ptr &context) const;
        virtual SequenceType::Ptr staticType() const;
        virtual SequenceType::List expectedOperandTypes() const;
        virtual Expression::Ptr typeCheck(const StaticContext::Ptr &context,
                                          const SequenceType::Ptr &reqType);

        Operator operatorID() const;
        virtual ID id() const;

        /**
         * Determines the string representation for operator @p op.
         *
         * @return "union" if @p op is Union, "intersect" if @p op
         * is Intersect and "except" if @p op is Except.
         */
        static QString displayName(const Operator op);

        virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;

    private:
        const Operator m_operator;
    };
}

QT_END_NAMESPACE

#endif
