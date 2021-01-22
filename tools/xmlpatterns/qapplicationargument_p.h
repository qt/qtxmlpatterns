/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the tools applications of the Qt Toolkit.
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

#ifndef QApplicationArgument_H
#define QApplicationArgument_H

#include <QtCore/QVariant>

QT_BEGIN_NAMESPACE

class QString;
class QApplicationArgumentPrivate;

class QApplicationArgument
{
public:
    QApplicationArgument();
    QApplicationArgument(const QApplicationArgument &other);
    QApplicationArgument(const QString &name,
                 const QString &description,
                 int aType = QVariant::Invalid);
    ~QApplicationArgument();
    QApplicationArgument &operator=(const QApplicationArgument &other);
    bool operator==(const QApplicationArgument &other) const;
    bool operator<(const QApplicationArgument &other) const;

    void setName(const QString &newName);
    QString name() const;
    void setDescription(const QString &newDescription);
    QString description() const;

    int type() const;
    void setType(int newType);
    void setDefaultValue(const QVariant &value);
    QVariant defaultValue() const;

    void setMinimumOccurrence(int minimum);
    int minimumOccurrence() const;
    void setMaximumOccurrence(int maximum);
    int maximumOccurrence() const;
    void setNameless(bool value);
    bool isNameless() const;

private:
    QApplicationArgumentPrivate *d_ptr;
};

uint qHash(const QApplicationArgument &argument);

QT_END_NAMESPACE

#endif

