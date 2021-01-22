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

#ifndef Patternist_Validate_H
#define Patternist_Validate_H

#include <private/qexpression_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Handles XQuery 1.0's <tt>validate</tt> expression.
     *
     * This class is currently not used. The Schema Validation Feature is not supported.
     *
     * @see <a href="http://www.w3.org/TR/xquery/#id-validate">XQuery 1.0: An XML
     * Query Language, 3.13 Validate Expressions</a>
     * @see <a href="http://www.w3.org/TR/xquery/#id-schema-validation-feature">XQuery 1.0: An
     * XML Query Language, 5.2.2 Schema Validation Feature</a>
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class Validate
    {
    public:

        /**
         * Represents the validation mode.
         */
        enum Mode
        {
            Lax = 1,
            Strict
        };

        /**
         * Creates the necessary Expression instances
         * that validates the operand node @p operandNode in mode @p validationMode,
         * and returns it.
         */
        static Expression::Ptr create(const Expression::Ptr &operandNode,
                                      const Mode validationMode,
                                      const StaticContext::Ptr &context);
    private:
        Validate();
        Q_DISABLE_COPY(Validate)
    };
}

QT_END_NAMESPACE

#endif
