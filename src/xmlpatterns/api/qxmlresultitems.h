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

#ifndef QXMLRESULTITEMS
#define QXMLRESULTITEMS

#include <QtCore/QString>
#include <QtCore/QScopedPointer>
#include <QtXmlPatterns/qtxmlpatternsglobal.h>

QT_BEGIN_NAMESPACE


class QXmlItem;
class QXmlQuery;
class QXmlResultItemsPrivate;

class Q_XMLPATTERNS_EXPORT QXmlResultItems
{
public:
    QXmlResultItems();
    virtual ~QXmlResultItems();

    bool hasError() const;
    QXmlItem next();
    QXmlItem current() const;

private:
    friend class QXmlQuery;
    Q_DECLARE_PRIVATE(QXmlResultItems)
    QScopedPointer<QXmlResultItemsPrivate> d_ptr;
    Q_DISABLE_COPY(QXmlResultItems)
};

QT_END_NAMESPACE

#endif
