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

#ifndef Patternist_XPath20CoreFunctions_H
#define Patternist_XPath20CoreFunctions_H

#include <private/qabstractfunctionfactory_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Handles the functions defines in XQuery 1.0 and XPath 2.0
     * Function and Operators, except those also available in XPath 1.0.
     *
     * All XPath 2.0 functions is the union of the functions available in XPath20CoreFunctions
     * and XPath10CoreFunctions. One could therefore say that the name XPath20CoreFunctions is a
     * bit misleading.
     *
     * @see XPath10CoreFunctions
     * @see <a href ="http://www.w3.org/TR/xpath-functions/">XQuery 1.0
     * and XPath 2.0 Functions and Operators</a>
     * @see <a href="http://www.w3.org/TR/xpath.html#corelib">XML Path Language (XPath)
     * Version 1.0, 4 Core Function Library</a>
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_functions
     */
    class XPath20CoreFunctions : public AbstractFunctionFactory
    {
    protected:
        virtual Expression::Ptr retrieveExpression(const QXmlName name,
                                                   const Expression::List &args,
                                                   const FunctionSignature::Ptr &sign) const;

        virtual FunctionSignature::Ptr retrieveFunctionSignature(const NamePool::Ptr &np,
                                                                 const QXmlName name);
    };
}

QT_END_NAMESPACE

#endif
