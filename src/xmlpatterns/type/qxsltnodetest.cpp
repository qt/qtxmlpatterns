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

#include "qbuiltintypes_p.h"
#include "qxsltnodetest_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

bool XSLTNodeTest::xdtTypeMatches(const ItemType::Ptr &other) const
{
    if(!other->isNodeType())
        return false;

    return *static_cast<const XSLTNodeTest *>(other.data()) == *this
           ? true
           : xdtTypeMatches(other->xdtSuperType());
}

bool XSLTNodeTest::itemMatches(const Item &item) const
{
    Q_ASSERT(item);

    return item.isNode() &&
           item.asNode().kind() != QXmlNodeModelIndex::Document;
}

ItemType::Ptr XSLTNodeTest::xdtSuperType() const
{
    return BuiltinTypes::node;
}

QT_END_NAMESPACE
