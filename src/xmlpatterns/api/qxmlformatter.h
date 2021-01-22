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

#ifndef QXMLFORMATTER_H
#define QXMLFORMATTER_H

#include <QtXmlPatterns/QXmlSerializer>

QT_BEGIN_NAMESPACE


class QIODevice;
class QTextCodec;
class QXmlQuery;
class QXmlFormatterPrivate;

class Q_XMLPATTERNS_EXPORT QXmlFormatter : public QXmlSerializer
{
public:
    QXmlFormatter(const QXmlQuery &query,
                  QIODevice *outputDevice);

    void characters(const QStringRef &value) override;
    void comment(const QString &value) override;
    void startElement(const QXmlName &name) override;
    void endElement() override;

    void attribute(const QXmlName &name,
                   const QStringRef &value) override;
    void processingInstruction(const QXmlName &name,
                               const QString &value) override;
    void atomicValue(const QVariant &value) override;
    void startDocument() override;
    void endDocument() override;
    void startOfSequence() override;
    void endOfSequence() override;

    int indentationDepth() const;
    void setIndentationDepth(int depth);

    /* The members below are internal, not part of the public API, and
     * unsupported. Using them leads to undefined behavior. */
    void item(const QPatternist::Item &item) override;
private:
    inline void startFormattingContent();
    Q_DECLARE_PRIVATE(QXmlFormatter)
};

QT_END_NAMESPACE

#endif
