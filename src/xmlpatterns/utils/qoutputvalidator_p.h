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

#ifndef Patternist_OutputValidator_H
#define Patternist_OutputValidator_H

#include <QSet>

#include <private/qdynamiccontext_p.h>
#include "qabstractxmlreceiver.h"
#include <private/qsourcelocationreflection_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Receives QAbstractXmlReceiver events and validates that they are correct,
     * before sending them on to a second QAbstractXmlReceiver.
     *
     * Currently, this is only checking that attributes appear before other
     * nodes.
     *
     * @ingroup Patternist_xdm
     * @author Frans Englich <frans.englich@nokia.com>
     * @todo Escape data
     */
    class OutputValidator : public QAbstractXmlReceiver
                          , public DelegatingSourceLocationReflection
    {
    public:
        OutputValidator(QAbstractXmlReceiver *const receiver,
                        const DynamicContext::Ptr &context,
                        const SourceLocationReflection *const r,
                        const bool isXSLT);

        virtual void namespaceBinding(const QXmlName &nb);

        virtual void characters(const QStringRef &value);
        virtual void comment(const QString &value);

        virtual void startElement(const QXmlName &name);

        virtual void endElement();

        virtual void attribute(const QXmlName &name,
                               const QStringRef &value);

        virtual void processingInstruction(const QXmlName &name,
                                           const QString &value);

        virtual void item(const Item &item);

        virtual void startDocument();
        virtual void endDocument();
        virtual void atomicValue(const QVariant &value);
        virtual void endOfSequence();
        virtual void startOfSequence();

    private:
        bool                        m_hasReceivedChildren;
        QAbstractXmlReceiver *const m_receiver;
        const DynamicContext::Ptr   m_context;

        /**
         * Keeps the current received attributes, in order to check uniqueness.
         */
        QSet<QXmlName>              m_attributes;
        const bool                  m_isXSLT;
    };
}

QT_END_NAMESPACE

#endif
