/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
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

#ifndef Patternist_GenericDynamicContext_H
#define Patternist_GenericDynamicContext_H

#include <QDateTime>
#include <QVector>

#include <private/qdaytimeduration_p.h>
#include <private/qstackcontextbase_p.h>
#include <private/qexpression_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A DynamicContext supplying basic information that always is used.
     *
     * This DynamicContext is the first DynamicContext used during
     * a run and is always used. In addition, more contexts, such as
     * a Focus can be created.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class GenericDynamicContext : public StackContextBase<DynamicContext>
    {
    public:
        typedef QExplicitlySharedDataPointer<GenericDynamicContext> Ptr;

        GenericDynamicContext(const NamePool::Ptr &np,
                              QAbstractMessageHandler *const messageHandler,
                              const LocationHash &locations);

        xsInteger contextPosition() const override;
        /**
         * @returns always @c null, the focus is always undefined when an GenericDynamicContext
         * is used.
         */
        Item contextItem() const override;
        xsInteger contextSize() override;

        void setFocusIterator(const Item::Iterator::Ptr &it) override;
        Item::Iterator::Ptr focusIterator() const override;

        QAbstractMessageHandler * messageHandler() const override;
        QExplicitlySharedDataPointer<DayTimeDuration> implicitTimezone() const override;
        QDateTime currentDateTime() const override;

        QAbstractXmlReceiver *outputReceiver() const override;
        void setOutputReceiver(QAbstractXmlReceiver *const receiver);

        NodeBuilder::Ptr nodeBuilder(const QUrl &baseURI) const override;
        void setNodeBuilder(NodeBuilder::Ptr &builder);

        ResourceLoader::Ptr resourceLoader() const override;
        void setResourceLoader(const ResourceLoader::Ptr &loader);

        ExternalVariableLoader::Ptr externalVariableLoader() const override;
        void setExternalVariableLoader(const ExternalVariableLoader::Ptr &loader);
        NamePool::Ptr namePool() const override;
        QSourceLocation locationFor(const SourceLocationReflection *const reflection) const override;
        void addNodeModel(const QAbstractXmlNodeModel::Ptr &nm) override;
        const QAbstractUriResolver *uriResolver() const override;
        ItemCacheCell &globalItemCacheCell(const VariableSlotID slot) override;
        ItemSequenceCacheCell::Vector &globalItemSequenceCacheCells(const VariableSlotID slot) override;

        void setUriResolver(const QAbstractUriResolver *const resolver);

        /**
         * We return a null item, we have no focus.
         */
        Item currentItem() const override;

        /**
         * @short Returns always @c null, since we're always
         * a top-level context.
         */
        DynamicContext::Ptr previousContext() const override;

        QExplicitlySharedDataPointer<TemplateMode> currentTemplateMode() const override;

    private:
        QAbstractMessageHandler *       m_messageHandler;
        const QDateTime                 m_currentDateTime;
        const DayTimeDuration::Ptr      m_zoneOffset;
        QAbstractXmlReceiver *          m_outputReceiver;
        mutable NodeBuilder::Ptr        m_nodeBuilder;
        ExternalVariableLoader::Ptr     m_externalVariableLoader;
        ResourceLoader::Ptr             m_resourceLoader;
        NamePool::Ptr                   m_namePool;
        const LocationHash              m_locations;
        QAbstractXmlNodeModel::List     m_nodeModels;
        const QAbstractUriResolver *    m_uriResolver;
        ItemCacheCell::Vector           m_globalItemCacheCells;
        ItemSequenceCacheCell::Vector   m_globalItemSequenceCacheCells;
    };
}

QT_END_NAMESPACE

#endif
