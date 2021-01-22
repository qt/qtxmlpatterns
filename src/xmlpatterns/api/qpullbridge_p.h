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

#ifndef PATTERNIST_PULLBRIDGE_P_H
#define PATTERNIST_PULLBRIDGE_P_H

#include <QtCore/QPair>
#include <QtCore/QStack>

#include <private/qabstractxmlforwarditerator_p.h>
#include <private/qabstractxmlpullprovider_p.h>
#include <private/qitem_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    class PullBridge : public AbstractXmlPullProvider
    {
    public:
        inline PullBridge(const QXmlNodeModelIndex::Iterator::Ptr &it) : m_current(StartOfInput)
        {
            Q_ASSERT(it);
            m_iterators.push(qMakePair(StartOfInput, it));
        }

        Event next() override;
        Event current() const override;
        QXmlName name() const override;
        /**
         * Returns always an empty QVariant.
         */
        QVariant atomicValue() const override;
        QString stringValue() const override;
        QHash<QXmlName, QString> attributes() override;
        QHash<QXmlName, QXmlItem> attributeItems() override;

        QXmlNodeModelIndex index() const;
        QSourceLocation sourceLocation() const;

    private:
        typedef QStack<QPair<Event, QXmlNodeModelIndex::Iterator::Ptr> > IteratorStack;
        IteratorStack      m_iterators;
        QXmlNodeModelIndex m_index;
        Event              m_current;
    };
}

QT_END_NAMESPACE

#endif
