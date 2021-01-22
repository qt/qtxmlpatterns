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

#include "qcallsite_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

CallSite::CallSite(const QXmlName &name) : m_isRecursive(false)
                                         , m_name(name)
{
}

QXmlName CallSite::name() const
{
    return m_name;
}

bool CallSite::isRecursive() const
{
    return m_isRecursive;
}

void CallSite::setIsRecursive(const bool value)
{
    m_isRecursive = value;
}

QT_END_NAMESPACE
