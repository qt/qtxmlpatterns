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

#ifndef Patternist_HexBinary_H
#define Patternist_HexBinary_H

#include <private/qbase64binary_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Implements the value instance of the @c xs:hexBinary type.
     *
     * HexBinary inherits from Base64Binary for implementation reasons. The two
     * classes are similar, and inheritance therefore save code.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_xdm
     * @todo Documentation is missing
     */
    class HexBinary : public Base64Binary
    {
    public:
        friend class CommonValues;

        typedef AtomicValue::Ptr Ptr;

        virtual QString stringValue() const;
        virtual ItemType::Ptr type() const;

        /**
         * Creates a @c xs:hexBinary from the lexical representation @p value.
         */
        static AtomicValue::Ptr fromLexical(const NamePool::Ptr &np, const QString &value);

        /**
         * Creates an instance representing @p value.
         */
        static HexBinary::Ptr fromValue(const QByteArray &data);

    protected:
        HexBinary(const QByteArray &val);

    private:
        /**
         * @short Returns -1 on invalid input.
         */
        static inline qint8 fromHex(const QChar &c);
    };
}

QT_END_NAMESPACE

#endif
