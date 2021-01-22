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

#include "qunparsedtextavailablefn_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

bool UnparsedTextAvailableFN::evaluateEBV(const DynamicContext::Ptr &context) const
{
    Q_ASSERT(m_operands.count() == 1 || m_operands.count() == 2);
    const Item href(m_operands.first()->evaluateSingleton(context));
    if(!href)
        return Item();

    bool isValid = false;
    const QUrl mayRela(AnyURI::toQUrl<ReportContext::XTDE1170>(href.stringValue(),
                                                               context,
                                                               this,
                                                               &isValid));

    if(!isValid)
        return false;

    const QUrl uri(context->resolveURI(mayRela, staticBaseURI()));

    /* fn:unparsed-text() will raise an error on this. */
    if(uri.hasFragment())
        return false;

    QString encoding;

    if(m_operands.count() == 2)
    {
        const Item encodingArg(m_operands.at(1)->evaluateSingleton(context));
        if(encodingArg)
            encoding = encodingArg.stringValue();
    }

    Q_ASSERT(uri.isValid() && !uri.isRelative());
    return context->resourceLoader()->isUnparsedTextAvailable(uri, encoding);
}

QT_END_NAMESPACE
