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

#ifndef QABSTRACTMESSAGEHANDLER_H
#define QABSTRACTMESSAGEHANDLER_H

#include <QtXmlPatterns/QSourceLocation>
#include <QtCore/QObject>

QT_BEGIN_NAMESPACE


class Q_XMLPATTERNS_EXPORT QAbstractMessageHandler : public QObject
{
    Q_OBJECT
public:
    QAbstractMessageHandler(QObject *parent = nullptr);
    virtual ~QAbstractMessageHandler();

    void message(QtMsgType type,
                 const QString &description,
                 const QUrl &identifier = QUrl(),
                 const QSourceLocation &sourceLocation = QSourceLocation());

protected:
    virtual void handleMessage(QtMsgType type,
                               const QString &description,
                               const QUrl &identifier,
                               const QSourceLocation &sourceLocation) = 0;
private:
    Q_DISABLE_COPY(QAbstractMessageHandler)
};

QT_END_NAMESPACE

#endif
