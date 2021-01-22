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

#ifndef Patternist_DateTime_H
#define Patternist_DateTime_H

#include <private/qabstractdatetime_p.h>

QT_BEGIN_NAMESPACE

/**
 * @file
 * @short Contains class DateTime. This file was originally called qdatetime_p.h,
 * but various build systems cannot handle that that name happens to be
 * identical to another one, the one in QtCore.
 */

namespace QPatternist
{
    /**
     * @short Implements the value instance of the @c xs:dateTime type.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_xdm
     */
    class DateTime : public AbstractDateTime
    {
    public:
        typedef AtomicValue::Ptr Ptr;

        /**
         * Creates an instance from the lexical representation @p string.
         */
        static DateTime::Ptr fromLexical(const QString &string);
        static DateTime::Ptr fromDateTime(const QDateTime &dt);
        virtual ItemType::Ptr type() const;
        virtual QString stringValue() const;
        virtual Item fromValue(const QDateTime &dt) const;

    protected:
        friend class CommonValues;

        DateTime(const QDateTime &dateTime);
    };
}

QT_END_NAMESPACE

#endif
