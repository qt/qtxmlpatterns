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

#include "qcontextnodechecker_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

void ContextNodeChecker::checkTargetNode(const QXmlNodeModelIndex &node,
                                         const DynamicContext::Ptr &context,
                                         const ReportContext::ErrorCode code) const
{
    if(node.root().kind() != QXmlNodeModelIndex::Document)
    {
        context->error(QtXmlPatterns::tr("The root node of the second argument "
                                         "to function %1 must be a document "
                                         "node. %2 is not a document node.")
                       .arg(formatFunction(context->namePool(), signature()),
                            formatData(node)),
                       code, this);
    }
}

QT_END_NAMESPACE
