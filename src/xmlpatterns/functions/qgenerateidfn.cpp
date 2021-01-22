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

#include "qatomicstring_p.h"

#include "qgenerateidfn_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Item GenerateIDFN::evaluateSingleton(const DynamicContext::Ptr &context) const
{
    const Item item = m_operands.first()->evaluateSingleton(context);
    if (item.isNull())
        return AtomicString::fromValue(QString());

    const QXmlNodeModelIndex &node = item.asNode();

    return AtomicString::fromValue(QLatin1Char('T')
                                   + QString::number(qptrdiff(node.model()))
                                   + QString::number(qptrdiff(node.internalPointer()))
                                   + QString::number(node.additionalData()));
}

QT_END_NAMESPACE
