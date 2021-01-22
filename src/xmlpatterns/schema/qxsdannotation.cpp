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

#include "qxsdannotation_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

void XsdAnnotation::setId(const DerivedString<TypeID>::Ptr &id)
{
    m_id = id;
}

DerivedString<TypeID>::Ptr XsdAnnotation::id() const
{
    return m_id;
}

void XsdAnnotation::addApplicationInformation(const XsdApplicationInformation::Ptr &information)
{
    m_applicationInformation.append(information);
}

XsdApplicationInformation::List XsdAnnotation::applicationInformation() const
{
    return m_applicationInformation;
}

void XsdAnnotation::addDocumentation(const XsdDocumentation::Ptr &documentation)
{
    m_documentations.append(documentation);
}

XsdDocumentation::List XsdAnnotation::documentation() const
{
    return m_documentations;
}

QT_END_NAMESPACE
