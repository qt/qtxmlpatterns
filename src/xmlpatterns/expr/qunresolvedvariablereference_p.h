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

#ifndef Patternist_UnresolvedVariableReference_H
#define Patternist_UnresolvedVariableReference_H

#include <private/qemptycontainer_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Compile time only AST-node which is a marker for variable
     * references whose declaration has not yet appeared in the source code.
     *
     * This can not appear in XQuery, but can in XSL-T.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     * @since 4.5
     */
    class Q_AUTOTEST_EXPORT UnresolvedVariableReference : public EmptyContainer
    {
    public:
        UnresolvedVariableReference(const QXmlName &name);

        virtual Expression::Ptr typeCheck(const StaticContext::Ptr &context,
                                          const SequenceType::Ptr &reqType);
        virtual SequenceType::List expectedOperandTypes() const;
        virtual SequenceType::Ptr staticType() const;
        virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;
        virtual ID id() const;

        inline void bindTo(const Expression::Ptr &body);

        inline Expression::Ptr replacement() const;

    private:
        const QXmlName  m_name;
        Expression::Ptr m_replacement;
    };

    void UnresolvedVariableReference::bindTo(const Expression::Ptr &body)
    {
        Q_ASSERT(body);
        m_replacement = body;
    }

    Expression::Ptr UnresolvedVariableReference::replacement() const
    {
        Q_ASSERT(m_replacement);
        return m_replacement;
    }

}

QT_END_NAMESPACE

#endif
