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

#ifndef Patternist_PatternMatchingFNs_H
#define Patternist_PatternMatchingFNs_H

#include <private/qpatternplatform_p.h>

/**
 * @file
 * @short Contains classes implementing the functions found in
 * <a href="http://www.w3.org/TR/xpath-functions/#string.match">XQuery 1.0 and
 * XPath 2.0 Functions and Operators, 7.6 AtomicString Functions that Use Pattern Matching</a>.
 *
 * @ingroup Patternist_functions
 */

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Implements the function <tt>fn:matches()</tt>.
     *
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class MatchesFN : public PatternPlatform
    {
    public:
        MatchesFN();
        virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;
    };

    /**
     * @short Implements the function <tt>fn:replace()</tt>.
     *
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class ReplaceFN : public PatternPlatform
    {
    public:
        ReplaceFN();
        virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;
        /**
         * Overridden to attempt to pre-compile the replacement string.
         */
        virtual Expression::Ptr compress(const StaticContext::Ptr &context);

    private:
        /**
         * @short Centralizes the translation string.
         */
        static inline QString errorAtEnd(const char ch);

        /**
         * Reads the string in the third argument and converts it to a a QRegExp compatible
         * replacement string, containing sub-group references and so forth.
         */
        QString parseReplacement(const int captureCount,
                                 const DynamicContext::Ptr &context) const;

        QString m_replacementString;
    };

    /**
     * @short Implements the function <tt>fn:tokenize()</tt>.
     *
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class TokenizeFN : public PatternPlatform
    {
    public:
        TokenizeFN();
        inline Item mapToItem(const QString &subject, const DynamicContext::Ptr &) const;
        virtual Item::Iterator::Ptr evaluateSequence(const DynamicContext::Ptr &context) const;

    private:
        typedef QExplicitlySharedDataPointer<const TokenizeFN> ConstPtr;
    };
}

QT_END_NAMESPACE

#endif
