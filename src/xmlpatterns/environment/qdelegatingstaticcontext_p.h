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

#ifndef Patternist_DelegatingStaticContext_H
#define Patternist_DelegatingStaticContext_H

#include <QUrl>

#include <private/qstaticcontext_p.h>
#include <private/qfunctionfactory_p.h>
#include <private/qschematypefactory_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Delegates all members to a second instance. Used for
     * sub-classing.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class Q_AUTOTEST_EXPORT DelegatingStaticContext : public StaticContext
    {
    public:
        NamespaceResolver::Ptr namespaceBindings() const override;
        void setNamespaceBindings(const NamespaceResolver::Ptr &) override;

        FunctionFactory::Ptr functionSignatures() const override;
        SchemaTypeFactory::Ptr schemaDefinitions() const override;
        DynamicContext::Ptr dynamicContext() const override;

        QUrl baseURI() const override;
        void setBaseURI(const QUrl &uri) override;

        bool compatModeEnabled() const override;
        void setCompatModeEnabled(const bool newVal) override;

        QUrl defaultCollation() const override;

        QAbstractMessageHandler * messageHandler() const override;

        void setDefaultCollation(const QUrl &uri) override;

        BoundarySpacePolicy boundarySpacePolicy() const override;
        void setBoundarySpacePolicy(const BoundarySpacePolicy policy) override;

        ConstructionMode constructionMode() const override;
        void setConstructionMode(const ConstructionMode mode) override;

        OrderingMode orderingMode() const override;
        void setOrderingMode(const OrderingMode mode) override;
        OrderingEmptySequence orderingEmptySequence() const override;
        void setOrderingEmptySequence(const OrderingEmptySequence ordering) override;

        QString defaultFunctionNamespace() const override;
        void setDefaultFunctionNamespace(const QString &ns) override;

        QString defaultElementNamespace() const override;
        void setDefaultElementNamespace(const QString &ns) override;

        InheritMode inheritMode() const override;
        void setInheritMode(const InheritMode mode) override;

        PreserveMode preserveMode() const override;
        void setPreserveMode(const PreserveMode mode) override;

        ItemType::Ptr contextItemType() const override;
        ItemType::Ptr currentItemType() const override;

        StaticContext::Ptr copy() const override;

        ExternalVariableLoader::Ptr externalVariableLoader() const override;
        ResourceLoader::Ptr resourceLoader() const override;
        NamePool::Ptr namePool() const override;
        void addLocation(const SourceLocationReflection *const reflection,
                                 const QSourceLocation &location) override;
        LocationHash sourceLocations() const override;
        QSourceLocation locationFor(const SourceLocationReflection *const reflection) const override;
        const QAbstractUriResolver *uriResolver() const override;

        VariableSlotID currentRangeSlot() const override;
        VariableSlotID allocateRangeSlot() override;

    protected:
        DelegatingStaticContext(const StaticContext::Ptr &context);

    private:
        const StaticContext::Ptr    m_context;
    };
}

QT_END_NAMESPACE

#endif
