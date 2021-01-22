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

#ifndef Patternist_ExpressionSequence_H
#define Patternist_ExpressionSequence_H

#include <private/qunlimitedcontainer_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Implements the comma(",") operator, the sequence constructor.
     *
     * For example, the expression <tt>alpha, beta</tt> evaluates to a sequence
     * containing the items the nodetest @c alpha evaluates to, concatenated
     * with the items the nodetest @c beta evaluates to.
     *
     * @see <a href="http://www.w3.org/TR/xpath20/#construct_seq">XML Path Language
     * (XPath) 2.0, 3.3.1 Constructing Sequences</a>
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class ExpressionSequence : public UnlimitedContainer
    {
    public:
        /**
         * Creates an ExpressionSequence with the operands @p operands. @p operands
         * must contain two or more Expression instances.
         */
        ExpressionSequence(const Expression::List &operands);

        virtual Item::Iterator::Ptr evaluateSequence(const DynamicContext::Ptr &) const;

        /**
         * Forwards the call to its children.
         */
        virtual void evaluateToSequenceReceiver(const DynamicContext::Ptr &context) const;

        virtual SequenceType::List expectedOperandTypes() const;
        virtual SequenceType::Ptr staticType() const;

        /**
         * Removes any empty sequences, typically "()", from its list of children. If
         * after that rewrite has no children, it rewrites itself to the CommonValues::empty;
         * if it has only one, it rewrites to the child.
         *
         * This optimization is not very usable by itself, but potentially becomes effective after other
         * optimizations have rewritten themselves into empty sequences. Thus,
         * saving memory consumption and runtime overhead.
         */
        virtual Expression::Ptr compress(const StaticContext::Ptr &context);

        inline Item::Iterator::Ptr mapToSequence(const Expression::Ptr &,
                                                 const DynamicContext::Ptr &) const;

        virtual Expression::Ptr typeCheck(const StaticContext::Ptr &context,
                                          const SequenceType::Ptr &reqType);
        /**
         * @returns Expression::DisableElimination, plus the union
         * of all this ExpressionSequence's children's properties. If any child
         * does not have IsEvaluated, it is removed from the result.
         */
        virtual Expression::Properties properties() const;
        virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;
        virtual ID id() const;
    private:
        typedef QExplicitlySharedDataPointer<const ExpressionSequence> ConstPtr;
    };
}

QT_END_NAMESPACE

#endif
