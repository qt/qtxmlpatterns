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
#include "qxpathhelper_p.h"

#include "qlocalnametest_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

LocalNameTest::LocalNameTest(const ItemType::Ptr &primaryType,
                             const QXmlName::LocalNameCode &ncName) : AbstractNodeTest(primaryType),
                                                                   m_ncName(ncName)
{
}

ItemType::Ptr LocalNameTest::create(const ItemType::Ptr &primaryType, const QXmlName::LocalNameCode localName)
{
    Q_ASSERT(primaryType);

    return ItemType::Ptr(new LocalNameTest(primaryType, localName));
}

bool LocalNameTest::itemMatches(const Item &item) const
{
    Q_ASSERT(item.isNode());
    return m_primaryType->itemMatches(item) &&
           item.asNode().name().localName() == m_ncName;
}

QString LocalNameTest::displayName(const NamePool::Ptr &np) const
{
    QString displayOther(m_primaryType->displayName(np));

    return displayOther.insert(displayOther.size() - 1,
                               QString::fromLatin1("*:") + np->stringForLocalName(m_ncName));
}

ItemType::InstanceOf LocalNameTest::instanceOf() const
{
    return ClassLocalNameTest;
}

bool LocalNameTest::operator==(const ItemType &other) const
{
    return other.instanceOf() == ClassLocalNameTest &&
           static_cast<const LocalNameTest &>(other).m_ncName == m_ncName;
}

PatternPriority LocalNameTest::patternPriority() const
{
    return -0.25;
}

QT_END_NAMESPACE
