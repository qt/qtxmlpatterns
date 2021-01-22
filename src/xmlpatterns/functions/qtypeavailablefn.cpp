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
#include "qqnameconstructor_p.h"

#include "qtypeavailablefn_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item TypeAvailableFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const QString lexQName(m_operands.first()->evaluateSingleton(context).stringValue());

    const QXmlName name
        (QNameConstructor::expandQName<DynamicContext::Ptr,
                                       ReportContext::XTDE1428,
                                       ReportContext::XTDE1428>(lexQName,
                                                                context,
                                                                staticNamespaces(),
                                                                this));


    return Boolean::fromValue(m_schemaTypeFactory->types().contains(name));
}

Expression::Ptr TypeAvailableFN::typeCheck(const StaticContext::Ptr &context,
                                           const SequenceType::Ptr &reqType)
{
    m_schemaTypeFactory = context->schemaDefinitions();
    return StaticNamespacesContainer::typeCheck(context, reqType);
}

QT_END_NAMESPACE
