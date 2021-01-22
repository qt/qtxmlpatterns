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

#ifndef Patternist_XsdDocumentation_H
#define Patternist_XsdDocumentation_H

#include <private/qanytype_p.h>
#include <private/qanyuri_p.h>
#include <private/qderivedstring_p.h>
#include <private/qnamedschemacomponent_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Represents a XSD documentation object.
     *
     * This class represents the <em>documentation</em> component of an <em>annotation</em> object
     * of a XML schema as described <a href="http://www.w3.org/TR/xmlschema11-1/#cAnnotations">here</a>.
     *
     * @ingroup Patternist_schema
     * @author Tobias Koenig <tobias.koenig@nokia.com>
     */
    class XsdDocumentation : public NamedSchemaComponent
    {
        public:
            typedef QExplicitlySharedDataPointer<XsdDocumentation> Ptr;
            typedef QList<XsdDocumentation::Ptr> List;

            /**
             * Creates a new documentation object.
             */
            XsdDocumentation();

            /**
             * Destroys the documentation object.
             */
            ~XsdDocumentation();

            /**
             * Sets the @p source of the documentation.
             *
             * The source points to an URL that contains more
             * information.
             */
            void setSource(const AnyURI::Ptr &source);

            /**
             * Returns the source of the documentation.
             */
            AnyURI::Ptr source() const;

            /**
             * Sets the @p language of the documentation.
             */
            void setLanguage(const DerivedString<TypeLanguage>::Ptr &language);

            /**
             * Returns the language of the documentation.
             */
            DerivedString<TypeLanguage>::Ptr language() const;

            /**
             * Sets the @p content of the documentation.
             *
             * The content can be of abritrary type.
             */
            void setContent(const QString &content);

            /**
             * Returns the content of the documentation.
             */
            QString content() const;

        private:
            AnyURI::Ptr                      m_source;
            DerivedString<TypeLanguage>::Ptr m_language;
            QString                          m_content;
    };
}

QT_END_NAMESPACE

#endif
