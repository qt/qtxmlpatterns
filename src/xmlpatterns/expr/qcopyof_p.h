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

#ifndef Patternist_CopyOf_H
#define Patternist_CopyOf_H

#include <private/qsinglecontainer_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Does node copying in a parameterized way, in order to deal with
     * namespace preservation/inheritance.
     *
     * If someone tries to call evaluateEBV(), evaluateSingleton() or
     * evaluateSequence() on us, we will infinitely loop. But apparently
     * that's not possible because we're always a child of ElementConstructor,
     * currently.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class CopyOf : public SingleContainer
    {
    public:
        /**
         * Creats a CopyOf where it is checked that the expression @p operand conforms
         * to the type @p reqType.
         */
        CopyOf(const Expression::Ptr &operand,
               const bool inheritNSS,
               const bool preserveNSS);

        virtual void evaluateToSequenceReceiver(const DynamicContext::Ptr &context) const;

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

        inline Item mapToItem(const Item &source,
                              const DynamicContext::Ptr &context) const;

        virtual Expression::Ptr compress(const StaticContext::Ptr &context);

        virtual Properties properties() const;
        virtual ItemType::Ptr expectedContextItemType() const;

    private:
        typedef QExplicitlySharedDataPointer<const CopyOf> ConstPtr;
        const bool                                      m_inheritNamespaces;
        const bool                                      m_preserveNamespaces;
        const QAbstractXmlNodeModel::NodeCopySettings   m_settings;
    };
}

QT_END_NAMESPACE

#endif
