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

#include "qxsdidentityconstraint_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

void XsdIdentityConstraint::setCategory(Category category)
{
    m_category = category;
}

XsdIdentityConstraint::Category XsdIdentityConstraint::category() const
{
    return m_category;
}

void XsdIdentityConstraint::setSelector(const XsdXPathExpression::Ptr &selector)
{
    m_selector = selector;
}

XsdXPathExpression::Ptr XsdIdentityConstraint::selector() const
{
    return m_selector;
}

void XsdIdentityConstraint::setFields(const XsdXPathExpression::List &fields)
{
    m_fields = fields;
}

void XsdIdentityConstraint::addField(const XsdXPathExpression::Ptr &field)
{
    m_fields.append(field);
}

XsdXPathExpression::List XsdIdentityConstraint::fields() const
{
    return m_fields;
}

void XsdIdentityConstraint::setReferencedKey(const XsdIdentityConstraint::Ptr &referencedKey)
{
    m_referencedKey = referencedKey;
}

XsdIdentityConstraint::Ptr XsdIdentityConstraint::referencedKey() const
{
    return m_referencedKey;
}

QT_END_NAMESPACE
