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

#ifndef Patternist_UserFunction_H
#define Patternist_UserFunction_H

#include <QSharedData>

#include <private/qexpression_p.h>
#include <private/qfunctionsignature_p.h>
#include <private/qvariabledeclaration_p.h>

QT_BEGIN_NAMESPACE

template<typename T> class QList;

namespace QPatternist
{
    /**
     * @short A function created with XQuery's <tt>declare function</tt> declaration.
     *
     * @see UserFunctionCall
     * @see ArgumentReference
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class UserFunction : public QSharedData
    {
    public:
        typedef QExplicitlySharedDataPointer<UserFunction> Ptr;
        typedef QList<UserFunction::Ptr> List;

        /**
         * If @p slotOffset is -1, it means this function has no arguments.
         */
        UserFunction(const FunctionSignature::Ptr &signature,
                     const Expression::Ptr &body,
                     const VariableSlotID slotOffset,
                     const VariableDeclaration::List &varDecls);

        inline const Expression::Ptr &body() const;
        inline void setBody(const Expression::Ptr &newBody);
        inline FunctionSignature::Ptr signature() const;
        inline VariableSlotID expressionSlotOffset() const;
        inline VariableDeclaration::List argumentDeclarations() const;

    private:
        const FunctionSignature::Ptr    m_signature;
        Expression::Ptr                 m_body;
        const VariableSlotID            m_slotOffset;
        const VariableDeclaration::List m_argumentDeclarations;
    };

    inline const Expression::Ptr &UserFunction::body() const
    {
        return m_body;
    }

    inline FunctionSignature::Ptr UserFunction::signature() const
    {
        return m_signature;
    }

    inline VariableSlotID UserFunction::expressionSlotOffset() const
    {
        return m_slotOffset;
    }

    inline VariableDeclaration::List UserFunction::argumentDeclarations() const
    {
        return m_argumentDeclarations;
    }

    void UserFunction::setBody(const Expression::Ptr &newBody)
    {
        m_body = newBody;
    }

}

QT_END_NAMESPACE

#endif
