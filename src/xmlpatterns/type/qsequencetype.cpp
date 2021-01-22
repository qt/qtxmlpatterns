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

#include "qsequencetype_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

SequenceType::~SequenceType()
{
}

bool SequenceType::matches(const SequenceType::Ptr other) const
{
    Q_ASSERT(other);

    return itemType()->xdtTypeMatches(other->itemType()) &&
           cardinality().isMatch(other->cardinality());
}

bool SequenceType::is(const SequenceType::Ptr &other) const
{
    return matches(other) && other->matches(Ptr(this));
}

QT_END_NAMESPACE
