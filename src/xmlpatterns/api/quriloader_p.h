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

#ifndef QURILOADER_P_H
#define QURILOADER_P_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtXmlPatterns/QXmlName>

#include <private/qnamepool_p.h>
#include <private/qvariableloader_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    class URILoader : public QNetworkAccessManager
    {
    public:
        URILoader(QObject *const parent,
                  const NamePool::Ptr &np,
                  const VariableLoader::Ptr &variableLoader);

        QNetworkReply *createRequest(Operation op,
                                     const QNetworkRequest & req,
                                     QIODevice *outgoingData = 0) override;

    private:
        const QString               m_variableNS;
        const NamePool::Ptr         m_namePool;
        const VariableLoader::Ptr   m_variableLoader;

    };
}

QT_END_NAMESPACE

#endif
