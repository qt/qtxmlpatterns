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

#include "qatomicmathematician_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

AtomicMathematician::~AtomicMathematician()
{
}

QString AtomicMathematician::displayName(const AtomicMathematician::Operator op)
{
    switch(op)
    {
        case AtomicMathematician::Div:
            return QLatin1String("div");
        case AtomicMathematician::IDiv:
            return QLatin1String("idiv");
        case AtomicMathematician::Substract:
            return QLatin1String("-");
        case AtomicMathematician::Mod:
            return QLatin1String("mod");
        case AtomicMathematician::Multiply:
            return QLatin1String("*");
        case AtomicMathematician::Add:
            return QLatin1String("+");
    }

    return QString(); /* Silence GCC warning. */
}

QT_END_NAMESPACE
