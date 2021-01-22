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

#ifndef Patternist_XsdNotation_H
#define Patternist_XsdNotation_H

#include <private/qanyuri_p.h>
#include <private/qderivedstring_p.h>
#include <private/qnamedschemacomponent_p.h>
#include <private/qxsdannotated_p.h>

#include <QtCore/QList>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Represents a XSD notation object, which should not
     * be confused with the atomic type @c xs:NOTATION.
     *
     * This class represents the <em>notation</em> object of a XML schema as described
     * <a href="http://www.w3.org/TR/xmlschema11-1/#cNotation_Declarations">here</a>.
     *
     * @see <a href="http://www.w3.org/Submission/2004/SUBM-xmlschema-api-20040309/xml-schema-api.html#XS-NotationDecl">XML Schema API reference</a>
     * @ingroup Patternist_schema
     * @author Tobias Koenig <tobias.koenig@nokia.com>
     */
    class XsdNotation : public NamedSchemaComponent, public XsdAnnotated
    {
        public:
            typedef QExplicitlySharedDataPointer<XsdNotation> Ptr;
            typedef QList<XsdNotation::Ptr> List;

            /**
             * Sets the public @p identifier of the notation.
             *
             * @see <a href="http://www.w3.org/TR/xmlschema11-1/#nd-public_identifier">Public Identifier Definition</a>
             */
            void setPublicId(const DerivedString<TypeToken>::Ptr &identifier);

            /**
             * Returns the public identifier of the notation.
             */
            DerivedString<TypeToken>::Ptr publicId() const;

            /**
             * Sets the system @p identifier of the notation.
             *
             * @see <a href="http://www.w3.org/TR/xmlschema11-1/#nd-system_identifier">System Identifier Definition</a>
             */
            void setSystemId(const AnyURI::Ptr &identifier);

            /**
             * Returns the system identifier of the notation.
             */
            AnyURI::Ptr systemId() const;

        private:
            DerivedString<TypeToken>::Ptr m_publicId;
            AnyURI::Ptr m_systemId;
    };
}

QT_END_NAMESPACE

#endif
