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


#include "quserfunction_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

UserFunction::UserFunction(const FunctionSignature::Ptr &sign,
                           const Expression::Ptr &b,
                           const VariableSlotID slotOffset,
                           const VariableDeclaration::List &varDecls) : m_signature(sign),
                                                                        m_body(b),
                                                                        m_slotOffset(slotOffset),
                                                                        m_argumentDeclarations(varDecls)
{
    Q_ASSERT(m_signature);
    Q_ASSERT(m_body);
    Q_ASSERT(m_slotOffset > -2);
}

QT_END_NAMESPACE
