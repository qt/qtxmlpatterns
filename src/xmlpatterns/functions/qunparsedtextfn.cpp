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

#include "qanyuri_p.h"

#include "qunparsedtextfn_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item UnparsedTextFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    Q_ASSERT(m_operands.count() == 1 || m_operands.count() == 2);
    const Item href(m_operands.first()->evaluateSingleton(context));
    if(!href)
        return Item();

    const QUrl mayRela(AnyURI::toQUrl<ReportContext::XTDE1170>(href.stringValue(),
                                                               context,
                                                               this));

    const QUrl uri(context->resolveURI(mayRela, staticBaseURI()));

    if(uri.hasFragment())
    {
        context->error(QtXmlPatterns::tr("The URI cannot have a fragment"),
                       ReportContext::XTDE1170, this);
    }

    QString encoding;

    if(m_operands.count() == 2)
    {
        const Item encodingArg(m_operands.at(1)->evaluateSingleton(context));
        if(encodingArg)
            encoding = encodingArg.stringValue();
    }

    Q_ASSERT(uri.isValid() && !uri.isRelative());
    return context->resourceLoader()->openUnparsedText(uri, encoding, context, this);
}

QT_END_NAMESPACE
