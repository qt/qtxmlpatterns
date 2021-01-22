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

#include <QUrl>

#include <QNetworkAccessManager>

#include "qnetworkaccessdelegator_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

NetworkAccessDelegator::NetworkAccessDelegator(QNetworkAccessManager *const genericManager,
                                               QNetworkAccessManager *const variableURIManager) : m_genericManager(genericManager)
                                                                                                , m_variableURIManager(variableURIManager)
{
}

QNetworkAccessManager *NetworkAccessDelegator::managerFor(const QUrl &uri)
{
    /* Unfortunately we have to do it this way, QUrl::isParentOf() doesn't
     * understand URI schemes like this one. */
    const QString requestedUrl(uri.toString());

    /* On the topic of timeouts:
     *
     * Currently the schemes QNetworkAccessManager handles should/will do
     * timeouts for 4.4, but we need to do timeouts for our own. */
    if(requestedUrl.startsWith(QLatin1String("tag:trolltech.com,2007:QtXmlPatterns:QIODeviceVariable:")))
        return m_variableURIManager;
    else
    {
        if(!m_genericManager)
            m_genericManager = new QNetworkAccessManager(this);

        return m_genericManager;
    }
}

QT_END_NAMESPACE

