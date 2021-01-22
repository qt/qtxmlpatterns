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

#ifndef Patternist_ConstructorFunctionsFactory_H
#define Patternist_ConstructorFunctionsFactory_H

#include <private/qabstractfunctionfactory_p.h>
#include <private/qschematypefactory_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short A function factory that handles the builtin constructor functions, such
     * as <tt>xs:time()</tt>.
     *
     * @see <a href="http://www.w3.org/TR/xpath20/#id-constructor-functions">XML Path
     * Language (XPath) 2.0, 3.10.4 Constructor Functions</a>
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_functions
     */
    class ConstructorFunctionsFactory : public AbstractFunctionFactory
    {
    public:
        ConstructorFunctionsFactory(const NamePool::Ptr &np, const SchemaTypeFactory::Ptr &);

        virtual FunctionSignature::Ptr retrieveFunctionSignature(const NamePool::Ptr &np, const QXmlName name);

    protected:
         virtual Expression::Ptr retrieveExpression(const QXmlName name,
                                                    const Expression::List &args,
                                                    const FunctionSignature::Ptr &sign) const;

    private:
        const SchemaTypeFactory::Ptr m_typeFactory;
    };
}

QT_END_NAMESPACE

#endif
