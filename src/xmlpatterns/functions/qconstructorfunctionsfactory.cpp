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

#include "qatomictype_p.h"
#include "qbuiltintypes_p.h"
#include "qcastas_p.h"
#include "qcommonnamespaces_p.h"
#include "qcommonsequencetypes_p.h"
#include "qfunctionargument_p.h"
#include "qfunctioncall_p.h"
#include "qgenericsequencetype_p.h"
#include "qschematype_p.h"
#include "qschematypefactory_p.h"

#include "qconstructorfunctionsfactory_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

ConstructorFunctionsFactory::ConstructorFunctionsFactory(const NamePool::Ptr &np, const SchemaTypeFactory::Ptr &f) : m_typeFactory(f)
{
    Q_ASSERT(m_typeFactory);
    Q_ASSERT(np);
    const auto &schemaHash = m_typeFactory->types();
    SchemaType::Hash::const_iterator it(schemaHash.constBegin());
    const SchemaType::Hash::const_iterator end(schemaHash.constEnd());

    FunctionArgument::List args;
    const QXmlName argName(StandardNamespaces::empty, StandardLocalNames::sourceValue);

    args.append(FunctionArgument::Ptr(new FunctionArgument(argName,
                                                           CommonSequenceTypes::ZeroOrOneAtomicType)));

    while(it != end)
    {
        if(!BuiltinTypes::xsAnyAtomicType->wxsTypeMatches(*it) ||
           *BuiltinTypes::xsAnyAtomicType == *static_cast<const AtomicType *>((*it).data()) ||
           *BuiltinTypes::xsNOTATION == *static_cast<const AtomicType *>((*it).data()))
        {
            /* It's not a valid type for a constructor function -- skip it. */
            ++it;
            continue;
        }

        const QXmlName name((*it)->name(np));
        FunctionSignature::Ptr s(new FunctionSignature(name, 1, 1,
                                                       makeGenericSequenceType(AtomicType::Ptr(*it),
                                                                               Cardinality::zeroOrOne())));
        s->setArguments(args);
        m_signatures.insert(name, s);
        ++it;
    }
}

Expression::Ptr ConstructorFunctionsFactory::retrieveExpression(const QXmlName name,
                                                                const Expression::List &args,
                                                                const FunctionSignature::Ptr &sign) const
{
    Q_UNUSED(sign);

    /* This function is only called if the callsite is valid, so createSchemaType() will always
     * return an AtomicType. */
    const AtomicType::Ptr at(static_cast<AtomicType *>(m_typeFactory->createSchemaType(name).data()));

    return Expression::Ptr(new CastAs(args.first(),
                                      makeGenericSequenceType(at,
                                                              Cardinality::zeroOrOne())));
}

FunctionSignature::Ptr ConstructorFunctionsFactory::retrieveFunctionSignature(const NamePool::Ptr &np, const QXmlName name)
{
    Q_UNUSED(np);
    return functionSignatures().value(name);
}

QT_END_NAMESPACE
