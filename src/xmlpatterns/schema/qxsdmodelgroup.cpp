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

#include "qxsdmodelgroup_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

XsdModelGroup::XsdModelGroup()
    : m_compositor(SequenceCompositor)
{
}

bool XsdModelGroup::isModelGroup() const
{
    return true;
}

void XsdModelGroup::setCompositor(ModelCompositor compositor)
{
    m_compositor = compositor;
}

XsdModelGroup::ModelCompositor XsdModelGroup::compositor() const
{
    return m_compositor;
}

void XsdModelGroup::setParticles(const XsdParticle::List &particles)
{
    m_particles = particles;
}

XsdParticle::List XsdModelGroup::particles() const
{
    return m_particles;
}

QT_END_NAMESPACE
