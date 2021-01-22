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

#include "qdynamiccontext_p.h"
#include "qvalidationerror_p.h"
#include "qitem_p.h"

#include "qanyuri_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

AnyURI::AnyURI(const QString &s) : AtomicString(s)
{
}

AnyURI::Ptr AnyURI::fromValue(const QString &value)
{
    return AnyURI::Ptr(new AnyURI(value));
}

AnyURI::Ptr AnyURI::fromValue(const QUrl &uri)
{
    return AnyURI::Ptr(new AnyURI(QString::fromLatin1(uri.toEncoded())));
}

AnyURI::Ptr AnyURI::resolveURI(const QString &relative,
                               const QString &base)
{
    const QUrl urlBase(base);
    const QUrl uri(urlBase.resolved(relative));
    return AnyURI::fromValue(uri);
}

ItemType::Ptr AnyURI::type() const
{
    return BuiltinTypes::xsAnyURI;
}

AnyURI::Ptr AnyURI::fromLexical(const QString &value)
{
    bool isValid;
    /* The error code doesn't matter, because we never raise error. */
    const QUrl retval(toQUrl<ReportContext::FORG0001>(value,
                                                      DynamicContext::Ptr(),
                                                      0,
                                                      &isValid,
                                                      false));
    if(isValid)
        return fromValue(retval);
    else
        return ValidationError::createError();
}

bool AnyURI::isValid(const QString &candidate)
{
    bool isOk = false;
    /* The error code doesn't matter, because we never raise error. */
    toQUrl<ReportContext::FORG0001>(candidate,
                                    ReportContext::Ptr(),
                                    0,
                                    &isOk,
                                    false);
    return isOk;
}
QT_END_NAMESPACE
