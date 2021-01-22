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

#ifndef Patternist_Tokenizer_H
#define Patternist_Tokenizer_H

#include <QPair>
#include <QSharedData>
#include <QString>
#include <QUrl>

#include <private/qparsercontext_p.h>
#include <private/qtokensource_p.h>
#include <private/qtokenvalue_p.h>

/**
 * Macro for the data type of semantic values; int by default.
 * See section Data Types of Semantic Values.
 */
#define XPATHSTYPE QPatternist::TokenValue

#include <private/qquerytransformparser_p.h> /* This inclusion must be after TokenValue. */

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Base class for all tokenizers.
     *
     * The main entry point is nextToken(), which ones calls to retrieve the stream
     * of tokens this Tokenizer delivers.
     *
     * @see <a href="http://www.w3.org/TR/xquery-xpath-parsing/">Building a
     * Tokenizer for XPath or XQuery</a>
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class Tokenizer : public TokenSource
    {
    public:
        inline Tokenizer(const QUrl &queryU) : m_queryURI(queryU)
        {
            Q_ASSERT(queryU.isValid());
        }

        typedef QExplicitlySharedDataPointer<Tokenizer> Ptr;

        /**
         * Switches the Tokenizer to only do scanning, and returns complete
         * strings for attribute value templates as opposed to the tokens for
         * the contained expressions.
         *
         * The current position in the stream is returned. It can be used to
         * later resume regular tokenization.
         */
        virtual int commenceScanOnly() = 0;

        /**
         * Resumes regular parsing from @p position. The tokenizer must be in
         * the scan-only state, which the commenceScanOnly() call transists to.
         *
         * The tokenizer will return the token POSITION_SET once after this
         * function has been called.
         */
        virtual void resumeTokenizationFrom(const int position) = 0;

        /**
         * @returns the URI of the resource being tokenized.
         */
        inline const QUrl &queryURI() const
        {
            return m_queryURI;
        }

        virtual void setParserContext(const ParserContext::Ptr &parseInfo) = 0;

    protected:
        /**
         * Returns a string representation of @p token.
         *
         * This function is used for debugging purposes. The implementation of
         * this function is in querytransformparser.ypp.
         */
        static QString tokenToString(const Token &token);

    private:
        Q_DISABLE_COPY(Tokenizer)
        const QUrl m_queryURI;
    };

}

#undef Patternist_DEBUG_PARSER // disable it for now

QT_END_NAMESPACE

#endif
