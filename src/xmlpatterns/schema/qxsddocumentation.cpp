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

#include "qxsddocumentation_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

XsdDocumentation::XsdDocumentation()
{
}

XsdDocumentation::~XsdDocumentation()
{
}

void XsdDocumentation::setSource(const AnyURI::Ptr &source)
{
    m_source = source;
}

AnyURI::Ptr XsdDocumentation::source() const
{
    return m_source;
}

void XsdDocumentation::setLanguage(const DerivedString<TypeLanguage>::Ptr &language)
{
    m_language = language;
}

DerivedString<TypeLanguage>::Ptr XsdDocumentation::language() const
{
    return m_language;
}

void XsdDocumentation::setContent(const QString &content)
{
    m_content = content;
}

QString XsdDocumentation::content() const
{
    return m_content;
}

QT_END_NAMESPACE
