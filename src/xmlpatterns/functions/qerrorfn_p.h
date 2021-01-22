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

#ifndef Patternist_ErrorFN_H
#define Patternist_ErrorFN_H

#include <private/qfunctioncall_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Implements the function <tt>fn:error()</tt>.
     *
     * <tt>fn:error()</tt> is a bit special in that its first argument varies between
     * the different signatures. This is implemented by changing the function
     * signature if the amount of arguments is one.
     *
     * <tt>fn:error()</tt> has as return type the peculiar "none" type, which is handled by NoneType.
     *
     * @ingroup Patternist_functions
     * @see CommonSequenceTypes::none
     * @see <a href="http://www.w3.org/TR/xpath-functions/#func-error">XQuery 1.0 and
     * XPath 2.0 Functions and Operators, 3 The Error Function</a>
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class ErrorFN : public FunctionCall
    {
    public:
        virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;
        virtual FunctionSignature::Ptr signature() const;
    };
}

QT_END_NAMESPACE

#endif
