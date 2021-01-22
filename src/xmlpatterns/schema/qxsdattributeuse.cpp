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

#include "qxsdattributeuse_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

void XsdAttributeUse::ValueConstraint::setVariety(Variety variety)
{
    m_variety = variety;
}

XsdAttributeUse::ValueConstraint::Variety XsdAttributeUse::ValueConstraint::variety() const
{
    return m_variety;
}

void XsdAttributeUse::ValueConstraint::setValue(const QString &value)
{
    m_value = value;
}

QString XsdAttributeUse::ValueConstraint::value() const
{
    return m_value;
}

void XsdAttributeUse::ValueConstraint::setLexicalForm(const QString &form)
{
    m_lexicalForm = form;
}

QString XsdAttributeUse::ValueConstraint::lexicalForm() const
{
    return m_lexicalForm;
}

XsdAttributeUse::ValueConstraint::Ptr XsdAttributeUse::ValueConstraint::fromAttributeValueConstraint(const XsdAttribute::ValueConstraint::Ptr &constraint)
{
    XsdAttributeUse::ValueConstraint::Ptr newConstraint(new XsdAttributeUse::ValueConstraint());
    switch (constraint->variety()) {
        case XsdAttribute::ValueConstraint::Fixed: newConstraint->setVariety(Fixed); break;
        case XsdAttribute::ValueConstraint::Default: newConstraint->setVariety(Default); break;
    }
    newConstraint->setValue(constraint->value());
    newConstraint->setLexicalForm(constraint->lexicalForm());

    return newConstraint;
}

XsdAttributeUse::XsdAttributeUse()
    : m_useType(OptionalUse)
{
}

bool XsdAttributeUse::isAttributeUse() const
{
    return true;
}

void XsdAttributeUse::setUseType(UseType type)
{
    m_useType = type;
}

XsdAttributeUse::UseType XsdAttributeUse::useType() const
{
    return m_useType;
}

bool XsdAttributeUse::isRequired() const
{
    return (m_useType == RequiredUse);
}

void XsdAttributeUse::setAttribute(const XsdAttribute::Ptr &attribute)
{
    m_attribute = attribute;
}

XsdAttribute::Ptr XsdAttributeUse::attribute() const
{
    return m_attribute;
}

void XsdAttributeUse::setValueConstraint(const ValueConstraint::Ptr &constraint)
{
    m_valueConstraint = constraint;
}

XsdAttributeUse::ValueConstraint::Ptr XsdAttributeUse::valueConstraint() const
{
    return m_valueConstraint;
}

QT_END_NAMESPACE
