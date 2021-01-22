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

#ifndef Patternist_PositionVariableReference_H
#define Patternist_PositionVariableReference_H

#include <private/qvariablereference_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A reference to an @c at variable, declared with the
     * <tt>for</tt>-part in XQuery's FLWOR expression.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class PositionalVariableReference : public VariableReference
    {
    public:
        typedef QExplicitlySharedDataPointer<PositionalVariableReference> Ptr;
        PositionalVariableReference(const VariableSlotID slot);

        virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;

        /**
         * Returns always @c true, since a positional variable is always one or more, and the
         * Effective %Boolean Value for that range is always @c true.
         *
         * @returns always @c true
         */
        virtual bool evaluateEBV(const DynamicContext::Ptr &context) const;

        /**
         * @returns always CommonSequenceTypes::ExactlyOneInteger
         */
        virtual SequenceType::Ptr staticType() const;

        virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;
        virtual Properties properties() const;
    };
}

QT_END_NAMESPACE

#endif
