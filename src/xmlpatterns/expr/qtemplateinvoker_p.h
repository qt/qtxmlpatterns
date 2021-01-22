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

#ifndef Patternist_TemplateInvoker_H
#define Patternist_TemplateInvoker_H

#include <private/qcallsite_p.h>
#include <private/qwithparam_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Base class for classes that invokes @em templates, such as
     * CallTemplate and ApplyTemplate.
     *
     * TemplateInvoker has the member m_withParams, which is the @c
     * xsl:with-param instructions of the caller. The definite source for the
     * expressions is m_withParams, not Expression::operands(). However, the
     * order of operands() is defined, while m_withParams is not since it's a
     * hash. Therefore operands() is definite on order.
     *
     * TemplateInvoker is intended to be sub-classed.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     * @since 4.5
     */
    class TemplateInvoker : public CallSite
    {
    public:
        virtual Expression::Ptr compress(const StaticContext::Ptr &context);

        inline const WithParam::Hash &withParams() const;
        WithParam::Hash m_withParams;

        /**
         * This is a bit complicated by that we have two required types, one
         * specified by @c xsl:param in the template declaration, and one on @c
         * xsl:with-param.
         *
         * @see UserFunctionCallsite::expectedOperandTypes()
         * @see <a href="http://www.w3.org/TR/xslt20/#with-param">XSL
         * Transformations (XSLT) Version 2.0, 10.1.1 Passing Parameters to Templates</a>
         */
        virtual SequenceType::List expectedOperandTypes() const;
    protected:
        /**
         * @p withParams may be empty.
         */
        TemplateInvoker(const WithParam::Hash &withParams,
                        const QXmlName &name = QXmlName());

    private:
        Q_DISABLE_COPY(TemplateInvoker)
    };

    const WithParam::Hash &TemplateInvoker::withParams() const
    {
        return m_withParams;
    }

}

QT_END_NAMESPACE

#endif

