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

#ifndef Patternist_ToCodepointsIterator_H
#define Patternist_ToCodepointsIterator_H

#include <private/qitem_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Represents a stream of Unicode codepoints, which are computed from a string.
     *
     * ToCodepointsIterator takes in its constructor a string, whose Unicode characters'
     * codepoints it forms an QAbstractXmlForwardIterator over.
     *
     * @see <a href="http://www.w3.org/TR/xpath-functions/#func-string-to-codepoints">XQuery 1.0
     * and XPath 2.0 Functions and Operators, 7.2.2 fn:string-to-codepoints</a>
     * @see StringToCodepointsFN
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_iterators
     */
    class ToCodepointsIterator : public Item::Iterator
    {
    public:
        /**
         * Constructs a ToCodepointsIterator.
         *
         * @param string the string to retrieve Unicode codepoints from. Can not be
         * empty.
         */
        ToCodepointsIterator(const QString &string);
        virtual Item next();
        virtual Item current() const;
        virtual xsInteger position() const;
        virtual xsInteger count();
        virtual Item::Iterator::Ptr copy() const;

    private:
        const QString m_string;
        const int m_len;
        Item m_current;
        xsInteger m_position;
    };
}

QT_END_NAMESPACE

#endif
