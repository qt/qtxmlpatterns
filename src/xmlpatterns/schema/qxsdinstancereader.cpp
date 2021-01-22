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

#include "qxsdinstancereader_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

XsdInstanceReader::XsdInstanceReader(const QAbstractXmlNodeModel *model, const XsdSchemaContext::Ptr &context)
    : m_context(context)
    , m_model(model->iterate(model->root(QXmlNodeModelIndex()), QXmlNodeModelIndex::AxisChild))
{
}

bool XsdInstanceReader::atEnd() const
{
    return (m_model.current() == AbstractXmlPullProvider::EndOfInput);
}

void XsdInstanceReader::readNext()
{
    m_model.next();

    if (m_model.current() == AbstractXmlPullProvider::StartElement) {
        m_cachedAttributes = m_model.attributes();
        m_cachedAttributeItems = m_model.attributeItems();
        m_cachedSourceLocation = m_model.sourceLocation();
        m_cachedItem = QXmlItem(m_model.index());
    }
}

bool XsdInstanceReader::isStartElement() const
{
    return (m_model.current() == AbstractXmlPullProvider::StartElement);
}

bool XsdInstanceReader::isEndElement() const
{
    return (m_model.current() == AbstractXmlPullProvider::EndElement);
}

bool XsdInstanceReader::hasChildText() const
{
    const QXmlNodeModelIndex index = m_model.index();
    QXmlNodeModelIndex::Iterator::Ptr it = index.model()->iterate(index, QXmlNodeModelIndex::AxisChild);

    QXmlNodeModelIndex currentIndex = it->next();
    while (!currentIndex.isNull()) {
        if (currentIndex.kind() == QXmlNodeModelIndex::Text)
            return true;

        currentIndex = it->next();
    }

    return false;
}

bool XsdInstanceReader::hasChildElement() const
{
    const QXmlNodeModelIndex index = m_model.index();
    QXmlNodeModelIndex::Iterator::Ptr it = index.model()->iterate(index, QXmlNodeModelIndex::AxisChild);

    QXmlNodeModelIndex currentIndex = it->next();
    while (!currentIndex.isNull()) {
        if (currentIndex.kind() == QXmlNodeModelIndex::Element)
            return true;

        currentIndex = it->next();
    }

    return false;
}

QXmlName XsdInstanceReader::name() const
{
    return m_model.name();
}

QXmlName XsdInstanceReader::convertToQName(const QString &name) const
{
    const int pos = name.indexOf(QLatin1Char(':'));

    QXmlName::PrefixCode prefixCode = 0;
    QXmlName::NamespaceCode namespaceCode;
    QXmlName::LocalNameCode localNameCode;
    if (pos != -1) {
        prefixCode = m_context->namePool()->allocatePrefix(name.left(pos));
        namespaceCode = m_cachedItem.toNodeModelIndex().namespaceForPrefix(prefixCode);
        localNameCode = m_context->namePool()->allocateLocalName(name.mid(pos + 1));
    } else {
        prefixCode = StandardPrefixes::empty;
        namespaceCode = m_cachedItem.toNodeModelIndex().namespaceForPrefix(prefixCode);
        if (namespaceCode == -1)
            namespaceCode = StandardNamespaces::empty;
        localNameCode = m_context->namePool()->allocateLocalName(name);
    }

    return QXmlName(namespaceCode, localNameCode, prefixCode);
}

bool XsdInstanceReader::hasAttribute(const QXmlName &name) const
{
    return m_cachedAttributes.contains(name);
}

QString XsdInstanceReader::attribute(const QXmlName &name) const
{
    Q_ASSERT(m_cachedAttributes.contains(name));

    return m_cachedAttributes.value(name);
}

QSet<QXmlName> XsdInstanceReader::attributeNames() const
{
    QSet<QXmlName> result;
    for (auto it = m_cachedAttributes.cbegin(), end = m_cachedAttributes.cend(); it != end; ++it)
        result.insert(it.key());
    return result;
}

QString XsdInstanceReader::text() const
{
    const QXmlNodeModelIndex index = m_model.index();
    QXmlNodeModelIndex::Iterator::Ptr it = index.model()->iterate(index, QXmlNodeModelIndex::AxisChild);

    QString result;

    QXmlNodeModelIndex currentIndex = it->next();
    while (!currentIndex.isNull()) {
        if (currentIndex.kind() == QXmlNodeModelIndex::Text) {
            result.append(Item(currentIndex).stringValue());
        }

        currentIndex = it->next();
    }

    return result;
}

QXmlItem XsdInstanceReader::item() const
{
    return m_cachedItem;
}

QXmlItem XsdInstanceReader::attributeItem(const QXmlName &name) const
{
    return m_cachedAttributeItems.value(name);
}

QSourceLocation XsdInstanceReader::sourceLocation() const
{
    return m_cachedSourceLocation;
}

QVector<QXmlName> XsdInstanceReader::namespaceBindings(const QXmlNodeModelIndex &index) const
{
    return index.namespaceBindings();
}

QT_END_NAMESPACE
