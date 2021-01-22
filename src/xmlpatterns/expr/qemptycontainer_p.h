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

#ifndef Patternist_EmptyContainer_H
#define Patternist_EmptyContainer_H

#include <private/qexpression_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Base class for expressions that has no operands.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class Q_AUTOTEST_EXPORT EmptyContainer : public Expression
    {
    public:
        /**
         * @returns always an empty list.
         */
        virtual Expression::List operands() const;

        /**
         * Does nothing, since sub-classes has no operands. Calling
         * it makes hence no sense, and it also results in an assert crash.
         */
        virtual void setOperands(const Expression::List &);

    protected:
        /**
         * @returns always @c true
         */
        virtual bool compressOperands(const StaticContext::Ptr &context);

        /**
         * @returns always an empty list since it has no operands.
         */
        virtual SequenceType::List expectedOperandTypes() const;

    };
}

QT_END_NAMESPACE

#endif
