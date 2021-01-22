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

#ifndef Patternist_FunctionArgument_H
#define Patternist_FunctionArgument_H

#include <QList>
#include <QSharedData>

#include <QXmlName>
#include <private/qsequencetype_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Carries meta data for a function argument as found in XPath's
     * builtin functions and user declared functions in XQuery and XSL-T.
     *
     * @ingroup Patternist_functions
     * @see VariableDeclaration
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class FunctionArgument : public QSharedData
    {
    public:
        typedef QExplicitlySharedDataPointer<FunctionArgument> Ptr;
        typedef QList<FunctionArgument::Ptr> List;

        FunctionArgument(const QXmlName name,
                         const SequenceType::Ptr &type);

        QXmlName name() const;
        SequenceType::Ptr type() const;

    private:
        Q_DISABLE_COPY(FunctionArgument)
        const QXmlName m_name;
        const SequenceType::Ptr m_type;
    };
}

QT_END_NAMESPACE

#endif
