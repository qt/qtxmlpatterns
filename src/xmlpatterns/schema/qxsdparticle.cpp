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

#include "qxsdparticle_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

XsdParticle::XsdParticle()
    : m_minimumOccurs(1)
    , m_maximumOccurs(1)
    , m_maximumOccursUnbounded(false)
{
}

void XsdParticle::setMinimumOccurs(unsigned int occurs)
{
    m_minimumOccurs = occurs;
}

unsigned int XsdParticle::minimumOccurs() const
{
    return m_minimumOccurs;
}

void XsdParticle::setMaximumOccurs(unsigned int occurs)
{
    m_maximumOccurs = occurs;
}

unsigned int XsdParticle::maximumOccurs() const
{
    return m_maximumOccurs;
}

void XsdParticle::setMaximumOccursUnbounded(bool unbounded)
{
    m_maximumOccursUnbounded = unbounded;
}

bool XsdParticle::maximumOccursUnbounded() const
{
    return m_maximumOccursUnbounded;
}

void XsdParticle::setTerm(const XsdTerm::Ptr &term)
{
    m_term = term;
}

XsdTerm::Ptr XsdParticle::term() const
{
    return m_term;
}

QT_END_NAMESPACE
