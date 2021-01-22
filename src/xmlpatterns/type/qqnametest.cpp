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

#include <QHash>

#include "qbuiltintypes_p.h"
#include "qitem_p.h"
#include "qitem_p.h"

#include "qqnametest_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

QNameTest::QNameTest(const ItemType::Ptr &primaryType,
                     const QXmlName qName) : AbstractNodeTest(primaryType)
                                        , m_qName(qName)
{
    Q_ASSERT(!qName.isNull());
}

ItemType::Ptr QNameTest::create(const ItemType::Ptr &primaryType, const QXmlName qName)
{
    Q_ASSERT(!qName.isNull());
    Q_ASSERT(primaryType);

    return ItemType::Ptr(new QNameTest(primaryType, qName));
}

bool QNameTest::itemMatches(const Item &item) const
{
    Q_ASSERT(item.isNode());
    return m_primaryType->itemMatches(item) &&
           item.asNode().name() == m_qName;
}

QString QNameTest::displayName(const NamePool::Ptr &np) const
{
    QString displayOther(m_primaryType->displayName(np));

    return displayOther.insert(displayOther.size() - 1, np->displayName(m_qName));
}

ItemType::InstanceOf QNameTest::instanceOf() const
{
    return ClassQNameTest;
}

bool QNameTest::operator==(const ItemType &other) const
{
    return other.instanceOf() == ClassQNameTest &&
           static_cast<const QNameTest &>(other).m_qName == m_qName;
}

PatternPriority QNameTest::patternPriority() const
{
    return 0;
}

QT_END_NAMESPACE
