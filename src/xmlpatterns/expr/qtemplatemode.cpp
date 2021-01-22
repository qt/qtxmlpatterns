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

#include "qtemplatemode_p.h"

#include <algorithm>

QT_BEGIN_NAMESPACE

using namespace QPatternist;

bool TemplateMode::lessThanByPriority(const TemplatePattern::Ptr &t1,
                                      const TemplatePattern::Ptr &t2)
{
    return t1->priority() > t2->priority();
}

void TemplateMode::finalize()
{
    std::sort(templatePatterns.begin(), templatePatterns.end(), lessThanByPriority);

    /* Now we have a list of patterns sorted by priority. */
}

QT_END_NAMESPACE
