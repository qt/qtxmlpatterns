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

#include <QString>

#include "qbuiltintypes_p.h"
#include "qsorttuple_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

bool SortTuple::isAtomicValue() const
{
    Q_ASSERT_X(false, Q_FUNC_INFO,
               "It makes no sense to call this function.");
    return false;
}

QString SortTuple::stringValue() const
{
    return QLatin1String("SortTuple");
}

bool SortTuple::isNode() const
{
    Q_ASSERT_X(false, Q_FUNC_INFO,
               "It makes no sense to call this function.");
    return false;
}

bool SortTuple::hasError() const
{
    Q_ASSERT_X(false, Q_FUNC_INFO,
               "It makes no sense to call this function.");
    return false;
}

Item::Iterator::Ptr SortTuple::typedValue() const
{
    Q_ASSERT_X(false, Q_FUNC_INFO,
               "It makes no sense to call this function.");
    return Item::Iterator::Ptr();
}

ItemType::Ptr SortTuple::type() const
{
    return BuiltinTypes::xsAnyAtomicType;
}

QT_END_NAMESPACE
