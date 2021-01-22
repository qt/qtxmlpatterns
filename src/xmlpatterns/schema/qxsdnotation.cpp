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

#include "qxsdnotation_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

void XsdNotation::setPublicId(const DerivedString<TypeToken>::Ptr &id)
{
    m_publicId = id;
}

DerivedString<TypeToken>::Ptr XsdNotation::publicId() const
{
    return m_publicId;
}

void XsdNotation::setSystemId(const AnyURI::Ptr &id)
{
    m_systemId = id;
}

AnyURI::Ptr XsdNotation::systemId() const
{
    return m_systemId;
}

QT_END_NAMESPACE
