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

#include "qfunctionsignature_p.h"

#include "qfunctionfactory_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

FunctionFactory::~FunctionFactory()
{
}

bool FunctionFactory::isAvailable(const NamePool::Ptr &np,
                                  const QXmlName name, const xsInteger arity)
{
    const FunctionSignature::Ptr sign(retrieveFunctionSignature(np, name));

    if(sign)
        return arity == FunctionSignature::UnlimitedArity || sign->isArityValid(arity);
    else
        return false;
}

bool FunctionFactory::hasSignature(const FunctionSignature::Ptr &signature) const
{
    const FunctionSignature::Hash signs(functionSignatures());
    const FunctionSignature::Hash::const_iterator end(signs.constEnd());
    FunctionSignature::Hash::const_iterator it(signs.constBegin());

    for(; it != end; ++it)
    {
        if(*(*it) == *signature)
            return true;
    }

    return false;
}
QT_END_NAMESPACE
