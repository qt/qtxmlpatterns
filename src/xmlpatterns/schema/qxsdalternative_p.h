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

#ifndef Patternist_XsdAlternative_H
#define Patternist_XsdAlternative_H

#include <private/qnamedschemacomponent_p.h>
#include <private/qschematype_p.h>
#include <private/qxsdannotated_p.h>
#include <private/qxsdxpathexpression_p.h>

#include <QtCore/QList>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Represents a XSD alternative object.
     *
     * @ingroup Patternist_schema
     * @author Tobias Koenig <tobias.koenig@nokia.com>
     */
    class XsdAlternative : public NamedSchemaComponent, public XsdAnnotated
    {
        public:
            typedef QExplicitlySharedDataPointer<XsdAlternative> Ptr;
            typedef QList<XsdAlternative::Ptr> List;

            /**
             * Sets the xpath @p test of the alternative.
             *
             * @see <a href="http://www.w3.org/TR/xmlschema11-1/#tac-test">Test Definition</a>
             */
            void setTest(const XsdXPathExpression::Ptr &test);

            /**
             * Returns the xpath test of the alternative.
             */
            XsdXPathExpression::Ptr test() const;

            /**
             * Sets the @p type of the alternative.
             *
             * @see <a href="http://www.w3.org/TR/xmlschema11-1/#tac-type_definition">Type Definition</a>
             */
            void setType(const SchemaType::Ptr &type);

            /**
             * Returns the type of the alternative.
             */
            SchemaType::Ptr type() const;

        private:
            XsdXPathExpression::Ptr m_test;
            SchemaType::Ptr         m_type;
    };
}

QT_END_NAMESPACE

#endif
