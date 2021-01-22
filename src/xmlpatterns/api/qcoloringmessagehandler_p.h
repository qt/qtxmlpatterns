/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the XMLPatterns module of the Qt Toolkit.
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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_ColoringMessageHandler_h
#define Patternist_ColoringMessageHandler_h

#include <QHash>

#include <private/qcoloroutput_p.h>
#include <QAbstractMessageHandler>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    class ColoringMessageHandler : public QAbstractMessageHandler
                                 , private ColorOutput
    {
    public:
        ColoringMessageHandler(QObject *parent = 0);

    protected:
        void handleMessage(QtMsgType type,
                           const QString &description,
                           const QUrl &identifier,
                           const QSourceLocation &sourceLocation) override;

    private:
        QString colorifyDescription(const QString &in) const;

        enum ColorType
        {
            RunningText,
            Location,
            ErrorCode,
            Keyword,
            Data
        };

        QHash<QString, ColorType> m_classToColor;
    };
}

QT_END_NAMESPACE

#endif
