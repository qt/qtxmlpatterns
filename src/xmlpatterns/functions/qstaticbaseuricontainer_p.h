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

#ifndef Patternist_StaticBaseUriContainer_H
#define Patternist_StaticBaseUriContainer_H

#include <QUrl>

#include <private/qfunctioncall_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Base class for functions that needs to
     * store the static base URI for use at runtime.
     *
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class StaticBaseUriContainer : public FunctionCall
    {
    protected:
        inline StaticBaseUriContainer()
        {
        }

        inline void prepareStaticBaseURI(const StaticContext::Ptr &context)
        {
            m_staticBaseURI = context->baseURI();
        }

        inline const QUrl &staticBaseURI() const
        {
            return m_staticBaseURI;
        }

        /**
         * Calls prepareStaticBaseURI(), and return the return value of
         * FunctionCall::typeCheck(), forwarding the arguments.
         */
        virtual Expression::Ptr typeCheck(const StaticContext::Ptr &context,
                                          const SequenceType::Ptr &reqType)
        {
            prepareStaticBaseURI(context);
            return FunctionCall::typeCheck(context, reqType);
        }

    private:
        Q_DISABLE_COPY(StaticBaseUriContainer)
        QUrl m_staticBaseURI;
    };
}

QT_END_NAMESPACE

#endif
