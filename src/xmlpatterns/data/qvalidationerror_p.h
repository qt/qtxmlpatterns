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

#ifndef Patternist_ValidationError_H
#define Patternist_ValidationError_H

#include <private/qitem_p.h>
#include <private/qreportcontext_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Used for signalling casting errors.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_xdm
     */
    class ValidationError : public AtomicValue
    {
    public:
        typedef QExplicitlySharedDataPointer<ValidationError> Ptr;

        /**
         * Creates a ValidationError instance that represents a type error.
         *
         * @param description A detailed description of what that made the cast fail,
         * if any. If @c null, which QString() creates, a generic message
         * will be used.
         */
        static AtomicValue::Ptr createError(const QString &description = QString(),
                                            const ReportContext::ErrorCode = ReportContext::FORG0001);

        /**
         * A human readable, translated message describing the error.
         */
        QString message() const;

        /**
         * @returns always @c true
         */
        virtual bool hasError() const;

        /**
         * Always results in an assert crash.
         */
        virtual ItemType::Ptr type() const;

        /**
         * Always results in an assert crash.
         */
        virtual QString stringValue() const;

        /**
         * @returns the error code this ValidationError represents. Typically, this
         * is ReportContext::FORG0001.
         */
        ReportContext::ErrorCode errorCode() const;

    protected:
        ValidationError(const QString &msg, const ReportContext::ErrorCode code);

        const QString                   m_message;
        const ReportContext::ErrorCode  m_code;
    };
}

QT_END_NAMESPACE

#endif
