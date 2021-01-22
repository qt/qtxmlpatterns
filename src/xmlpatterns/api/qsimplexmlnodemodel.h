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

#ifndef QSIMPLEXMLNODEMODEL_H
#define QSIMPLEXMLNODEMODEL_H

#include <QtXmlPatterns/QAbstractXmlNodeModel>
#include <QtXmlPatterns/QXmlQuery>

QT_BEGIN_NAMESPACE


template<typename T> class QExplicitlySharedDataPointer;
class QSimpleXmlNodeModelPrivate;
class Q_XMLPATTERNS_EXPORT QSimpleXmlNodeModel : public QAbstractXmlNodeModel
{
public:
    QSimpleXmlNodeModel(const QXmlNamePool &namePool);
    virtual ~QSimpleXmlNodeModel();

    QUrl baseUri(const QXmlNodeModelIndex &node) const override;
    QXmlNamePool &namePool() const;
    QVector<QXmlName> namespaceBindings(const QXmlNodeModelIndex&) const override;
    QString stringValue(const QXmlNodeModelIndex &node) const override;
    QXmlNodeModelIndex elementById(const QXmlName &id) const override;
    QVector<QXmlNodeModelIndex> nodesByIdref(const QXmlName &idref) const override;

private:
    Q_DECLARE_PRIVATE(QSimpleXmlNodeModel)
};

QT_END_NAMESPACE

#endif
