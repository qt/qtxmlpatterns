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
#include "qgenericsequencetype_p.h"
#include "qmultiitemtype_p.h"
#include "qtypechecker_p.h"

#include "qvalidate_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

Expression::Ptr Validate::create(const Expression::Ptr &operandNode,
                                 const Mode validationMode,
                                 const StaticContext::Ptr &context)
{
    Q_ASSERT(operandNode);
    Q_ASSERT(validationMode == Lax || validationMode == Strict);
    Q_ASSERT(context);
    Q_UNUSED(validationMode);
    Q_UNUSED(context);

    ItemType::List tList;
    tList.append(BuiltinTypes::element);
    tList.append(BuiltinTypes::document);

    const SequenceType::Ptr elementOrDocument(makeGenericSequenceType(ItemType::Ptr(new MultiItemType(tList)),
                                                                      Cardinality::exactlyOne()));


    return TypeChecker::applyFunctionConversion(operandNode,
                                                elementOrDocument,
                                                context,
                                                ReportContext::XQTY0030);
}

QT_END_NAMESPACE
