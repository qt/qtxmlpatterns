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

#include "qitem_p.h"

#include "qabstractxmlreceiver.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

QAbstractXmlReceiver::~QAbstractXmlReceiver()
{
}

template<const QXmlNodeModelIndex::Axis axis>
void QAbstractXmlReceiver::sendFromAxis(const QXmlNodeModelIndex &node)
{
    Q_ASSERT(!node.isNull());
    const QXmlNodeModelIndex::Iterator::Ptr it(node.iterate(axis));
    QXmlNodeModelIndex next(it->next());

    while(!next.isNull())
    {
        sendAsNode(next);
        next = it->next();
    }
}

void QAbstractXmlReceiver::sendAsNode(const Item &outputItem)
{
    Q_ASSERT(outputItem);
    Q_ASSERT(outputItem.isNode());
    const QXmlNodeModelIndex asNode = outputItem.asNode();

    switch(asNode.kind())
    {
        case QXmlNodeModelIndex::Attribute:
        {
            attribute(asNode.name(), outputItem.stringValue());
            break;
        }
        case QXmlNodeModelIndex::Element:
        {
            startElement(asNode.name());

            /* First the namespaces, then attributes, then the children. */
            asNode.sendNamespaces(Ptr(const_cast<QAbstractXmlReceiver *>(this)));
            sendFromAxis<QXmlNodeModelIndex::AxisAttribute>(asNode);
            sendFromAxis<QXmlNodeModelIndex::AxisChild>(asNode);

            endElement();

            break;
        }
        case QXmlNodeModelIndex::Text:
        {
            characters(outputItem.stringValue());
            break;
        }
        case QXmlNodeModelIndex::ProcessingInstruction:
        {
            processingInstruction(asNode.name(), outputItem.stringValue());
            break;
        }
        case QXmlNodeModelIndex::Comment:
        {
            comment(outputItem.stringValue());
            break;
        }
        case QXmlNodeModelIndex::Document:
        {
            sendFromAxis<QXmlNodeModelIndex::AxisChild>(asNode);
            break;
        }
        case QXmlNodeModelIndex::Namespace:
            Q_ASSERT_X(false, Q_FUNC_INFO, "Not implemented");
    }
}

void QAbstractXmlReceiver::whitespaceOnly(const QStringRef &value)
{
    Q_ASSERT_X(value.toString().trimmed().isEmpty(), Q_FUNC_INFO,
               "The caller must guarantee only whitespace is passed. Use characters() in other cases.");
    characters(value.toString());
}

QT_END_NAMESPACE
