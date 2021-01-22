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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef QIODEVICEDELEGATE_P_H
#define QIODEVICEDELEGATE_P_H

#include <QtCore/QTimer>
#include <QtNetwork/QNetworkReply>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * This is read-only currently.
     */
    class QIODeviceDelegate : public QNetworkReply
    {
        Q_OBJECT
    public:
        QIODeviceDelegate(QIODevice *const source);

        void abort() override;

        bool atEnd() const override;
        qint64 bytesAvailable() const override;
        qint64 bytesToWrite() const override;
        bool canReadLine() const override;
        void close() override;
        bool isSequential() const override;
        bool open(OpenMode mode) override;
        qint64 pos() const override;
        bool reset() override;
        bool seek(qint64 pos) override;
        qint64 size() const override;
        bool waitForBytesWritten(int msecs) override;
        bool waitForReadyRead(int msecs) override;

    protected:
        qint64 readData(char *data, qint64 maxSize) override;

    private Q_SLOTS:
        void networkTimeout();
    private:
        enum
        {
            /**
             * 20 seconds expressed in milliseconds.
             */
            Timeout = 20000
        };

        QIODevice *const m_source;
        QTimer m_timeout;
    };
}

QT_END_NAMESPACE

#endif
