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

#ifndef Patternist_DelegatingNamespaceResolver_H
#define Patternist_DelegatingNamespaceResolver_H

#include <QHash>

#include <private/qnamespaceresolver_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Contains a set of bindings, plus a pointer to another resolver
     * which is delegates requests to, in case it can't handle a lookup on its
     * own.
     *
     * @ingroup Patternist
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class DelegatingNamespaceResolver : public NamespaceResolver
    {
    public:
        DelegatingNamespaceResolver(const NamespaceResolver::Ptr &ns);
        DelegatingNamespaceResolver(const NamespaceResolver::Ptr &ns,
                                    const Bindings &overrides);

        virtual void addBinding(const QXmlName nb);

        virtual QXmlName::NamespaceCode lookupNamespaceURI(const QXmlName::PrefixCode prefix) const;
        virtual Bindings bindings() const;

    private:
        const NamespaceResolver::Ptr    m_nsResolver;
        Bindings                        m_bindings;
    };
}

QT_END_NAMESPACE

#endif
