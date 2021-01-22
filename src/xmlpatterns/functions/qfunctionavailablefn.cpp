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

#include "qboolean_p.h"
#include "qdelegatingnamespaceresolver_p.h"
#include "qinteger_p.h"
#include "qqnameconstructor_p.h"

#include "qfunctionavailablefn_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item FunctionAvailableFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const QString lexQName(m_operands.first()->evaluateSingleton(context).stringValue());

    NamespaceResolver::Bindings override;
    override.insert(StandardPrefixes::empty, m_defFuncNS);

    const NamespaceResolver::Ptr resolver(new DelegatingNamespaceResolver(staticNamespaces(), override));

    const QXmlName name
        (QNameConstructor::expandQName<DynamicContext::Ptr,
                                       ReportContext::XTDE1400,
                                       ReportContext::XTDE1400>(lexQName,
                                                                context,
                                                                resolver,
                                                                this));

    xsInteger arity;

    if(m_operands.count() == 2)
        arity = m_operands.at(1)->evaluateSingleton(context).as<Numeric>()->toInteger();
    else
        arity = FunctionSignature::UnlimitedArity;

    return Boolean::fromValue(m_functionFactory->isAvailable(context->namePool(), name, arity));
}

Expression::Ptr FunctionAvailableFN::typeCheck(const StaticContext::Ptr &context,
                                               const SequenceType::Ptr &reqType)
{
    m_functionFactory = context->functionSignatures();
    Q_ASSERT(m_functionFactory);
    m_defFuncNS = context->namePool()->allocateNamespace(context->defaultFunctionNamespace());
    /* m_defFuncNS can be empty/null or an actual value. */

    return StaticNamespacesContainer::typeCheck(context, reqType);
}

QT_END_NAMESPACE
