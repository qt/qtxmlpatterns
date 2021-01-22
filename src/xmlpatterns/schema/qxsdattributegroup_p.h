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

#ifndef Patternist_XsdAttributeGroup_H
#define Patternist_XsdAttributeGroup_H

#include <private/qxsdannotated_p.h>
#include <private/qxsdattributeuse_p.h>
#include <private/qxsdwildcard_p.h>

#include <QtCore/QList>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Represents the XSD attributeGroup object.
     *
     * This class represents the <em>attributeGroup</em> object of a XML schema as described
     * <a href="http://www.w3.org/TR/xmlschema11-1/#cAttribute_Group_Definitions">here</a>.
     *
     * @see <a href="http://www.w3.org/Submission/2004/SUBM-xmlschema-api-20040309/xml-schema-api.html#Interface-XSAttributeGroup">XML Schema API reference</a>
     * @ingroup Patternist_schema
     * @author Tobias Koenig <tobias.koenig@nokia.com>
     */
    class XsdAttributeGroup : public NamedSchemaComponent, public XsdAnnotated
    {
        public:
            typedef QExplicitlySharedDataPointer<XsdAttributeGroup> Ptr;
            typedef QList<XsdAttributeGroup::Ptr> List;

            /**
             * Sets the list of attribute @p uses that are defined in the attribute group.
             *
             * @see <a href="http://www.w3.org/TR/xmlschema11-1/#agd-attribute_uses">Attribute Uses</a>
             */
            void setAttributeUses(const XsdAttributeUse::List &uses);

            /**
             * Adds a new attribute @p use to the attribute group.
             */
            void addAttributeUse(const XsdAttributeUse::Ptr &use);

            /**
             * Returns the list of all attribute uses of the attribute group.
             */
            XsdAttributeUse::List attributeUses() const;

            /**
             * Sets the attribute @p wildcard of the attribute group.
             *
             * @see <a href="http://www.w3.org/TR/xmlschema11-1/#agd-attribute_wildcard">Attribute Wildcard</a>
             */
            void setWildcard(const XsdWildcard::Ptr &wildcard);

            /**
             * Returns the attribute wildcard of the attribute group.
             */
            XsdWildcard::Ptr wildcard() const;

        private:
            XsdAttributeUse::List m_attributeUses;
            XsdWildcard::Ptr      m_wildcard;
    };
}

QT_END_NAMESPACE

#endif
