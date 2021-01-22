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

#ifndef Patternist_TokenRevealer_h
#define Patternist_TokenRevealer_h

#include <QSet>

#include <private/qtokenizer_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Delegates another Tokenizer, and while doing so
     * prints the tokens it delivers to @c stderr.
     *
     * Hence, this class is used solely for debugging.
     *
     * @since 4.5
     */
    class TokenRevealer : public Tokenizer
    {
    public:
        TokenRevealer(const QUrl &uri,
                      const Tokenizer::Ptr &other);

        virtual ~TokenRevealer();

        virtual Token nextToken(XPATHLTYPE *const sourceLocator);
        virtual int commenceScanOnly();
        virtual void resumeTokenizationFrom(const int position);
        virtual void setParserContext(const ParserContext::Ptr &parseInfo);

    private:
        const Tokenizer::Ptr    m_tokenizer;
        QString                 m_result;
        QString                 m_indentationString;
    };
}

QT_END_NAMESPACE

#endif

