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
#include "qcommonvalues_p.h"
#include "qdynamiccontext_p.h"

#include "qexternalvariableloader_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

ExternalVariableLoader::~ExternalVariableLoader()
{
}


SequenceType::Ptr ExternalVariableLoader::announceExternalVariable(const QXmlName name,
                                                                   const SequenceType::Ptr &declaredType)
{
    Q_ASSERT(!name.isNull());
    Q_ASSERT(declaredType);
    Q_UNUSED(name); /* Needed when compiling in release mode. */
    Q_UNUSED(declaredType); /* Needed when compiling in release mode. */

    return SequenceType::Ptr();
}

Item::Iterator::Ptr ExternalVariableLoader::evaluateSequence(const QXmlName name,
                                                             const DynamicContext::Ptr &context)
{
    Q_ASSERT(!name.isNull());
    const Item item(evaluateSingleton(name, context));

    if(item)
        return makeSingletonIterator(item);
    else
        return CommonValues::emptyIterator;
}

Item ExternalVariableLoader::evaluateSingleton(const QXmlName name,
                                                    const DynamicContext::Ptr &context)
{
    Q_ASSERT(!name.isNull());
    return Boolean::fromValue(evaluateEBV(name, context));
}

bool ExternalVariableLoader::evaluateEBV(const QXmlName name,
                                         const DynamicContext::Ptr &context)
{
    Q_ASSERT(!name.isNull());
    return Boolean::evaluateEBV(evaluateSequence(name, context), context);
}

QT_END_NAMESPACE
