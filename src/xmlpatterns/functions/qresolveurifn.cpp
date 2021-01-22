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

#include <QUrl>

#include "qanyuri_p.h"
#include "qliteral_p.h"
#include "qpatternistlocale_p.h"
#include "qatomicstring_p.h"

#include "qresolveurifn_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item ResolveURIFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item relItem(m_operands.first()->evaluateSingleton(context));

    if(relItem)
    {
        const QString base(m_operands.last()->evaluateSingleton(context).stringValue());
        const QString relative(relItem.stringValue());

        const QUrl baseURI(AnyURI::toQUrl<ReportContext::FORG0002, DynamicContext::Ptr>(base, context, this));
        const QUrl relativeURI(AnyURI::toQUrl<ReportContext::FORG0002, DynamicContext::Ptr>(relative, context, this));

        return toItem(AnyURI::fromValue(baseURI.resolved(relativeURI)));
    }
    else
        return Item();
}

Expression::Ptr ResolveURIFN::typeCheck(const StaticContext::Ptr &context,
                                        const SequenceType::Ptr &reqType)
{
    Q_ASSERT(m_operands.count() == 1 || m_operands.count() == 2);

    if(m_operands.count() == 1)
    {
        /* Our base URI is always well-defined. */
        m_operands.append(wrapLiteral(toItem(AnyURI::fromValue(context->baseURI())), context, this));
    }

    return FunctionCall::typeCheck(context, reqType);
}

QT_END_NAMESPACE
