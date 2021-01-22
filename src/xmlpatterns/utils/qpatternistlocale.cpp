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

#include "qpatternistlocale_p.h"

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    QString escape(const QString &input)
    {
        QString rich;
        rich.reserve(int(input.length() * 1.1));

        for(int i = 0; i < input.length(); ++i)
        {
            switch(input.at(i).unicode())
            {
                case '<':
                {
                    rich += QLatin1String("&lt;");
                    break;
                }
                case '>':
                {
                    rich += QLatin1String("&gt;");
                    break;
                }
                case '&':
                {
                    rich += QLatin1String("&amp;");
                    break;
                }
                case '"':
                {
                    rich += QLatin1String("&quot;");
                    break;
                }
                case '\'':
                {
                    rich += QLatin1String("&apos;");
                    break;
                }
                default:
                    rich += input.at(i);
            }
        }

        return rich;
    }
}

QT_END_NAMESPACE
