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

#ifndef Patternist_CallSite_H
#define Patternist_CallSite_H

#include <private/qunlimitedcontainer_p.h>
#include <private/qcalltargetdescription_p.h>
#include <QXmlName>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Abstract base-class for Expression instances that are callsites
     * to other components, such as templates or user functions.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     * @since 4.5
     */
    class CallSite : public UnlimitedContainer
    {
    public:
        QXmlName name() const;
        bool isRecursive() const;
        void setIsRecursive(const bool value);

        /**
         * Called in the earliest stages of the compilation process. @p sign can
         * be any function signature for a user declared function. If @p sign
         * matches this UserFunctionCallsite, it means the UserFunction represented
         * by @p sign is recursive and that this UserFunctionCallsite should take
         * appropriate measures.
         *
         * @returns @c true if is recursive, otherwise @c false
         */
        virtual bool configureRecursion(const CallTargetDescription::Ptr &sign) = 0;

        /**
         * @short Returns the body of the function/template/component that is
         * being called.
         */
        virtual Expression::Ptr body() const = 0;

        virtual CallTargetDescription::Ptr callTargetDescription() const = 0;

    protected:
        CallSite(const QXmlName &name = QXmlName());

    private:
        Q_DISABLE_COPY(CallSite)
        bool            m_isRecursive;
        const QXmlName  m_name;
    };
}

QT_END_NAMESPACE

#endif
