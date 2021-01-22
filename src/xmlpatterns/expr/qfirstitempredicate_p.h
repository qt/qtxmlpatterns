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

#ifndef Patternist_FirstItemPredicate_H
#define Patternist_FirstItemPredicate_H

#include <private/qsinglecontainer_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A predicate that always selects the first item from its sequence.
     *
     * FirstItemPredicate corresponds exactly to the predicate
     * in the expression <tt>input[1]</tt>.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class FirstItemPredicate : public SingleContainer
    {
    public:
        /**
         * Creates a FirstItemPredicate that filters @p source.
         */
        FirstItemPredicate(const Expression::Ptr &source);

        /**
         * @returns the first item, if any, from evaluating the source expression.
         */
        virtual Item evaluateSingleton(const DynamicContext::Ptr &) const;

        /**
         * @returns a list containing one CommonSequenceTypes::ZeroOrMoreItems instance.
         */
        virtual SequenceType::List expectedOperandTypes() const;

        /**
         * @returns a SequenceType where the item type is the same as the source expression
         * and where the cardinality is either Cardinality::zeroOrOne() or Cardinality::exactlyOne(),
         * depending on the source expression.
         */
        virtual SequenceType::Ptr staticType() const;
        virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;

        /**
         * Rewrites <tt>expression[1][1]</tt> into <tt>expression[1]</tt>.
         */
        virtual Expression::Ptr compress(const StaticContext::Ptr &context);

        /**
         * @returns always IDFirstItemPredicate.
         */
        virtual ID id() const;
    };
}

QT_END_NAMESPACE

#endif
