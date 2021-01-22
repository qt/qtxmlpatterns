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

#ifndef Patternist_XsdAttributeTerm_H
#define Patternist_XsdAttributeTerm_H

#include <private/qnamedschemacomponent_p.h>
#include <private/qxsdannotated_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A base class for all attribute types.
     *
     * For easy resolving of attribute references, we use this as
     * common base class for XsdAttribute and XsdAttributeReference.
     *
     * @ingroup Patternist_schema
     * @author Tobias Koenig <tobias.koenig@nokia.com>
     */
    class XsdAttributeTerm : public NamedSchemaComponent, public XsdAnnotated
    {
        public:
            typedef QExplicitlySharedDataPointer<XsdAttributeTerm> Ptr;

            /**
             * Returns @c true if the term is an attribute use, @c false otherwise.
             */
            virtual bool isAttributeUse() const;

            /**
             * Returns @c true if the term is an attribute use reference, @c false otherwise.
             *
             * @note The reference term is only used internally as helper during type resolving.
             */
            virtual bool isReference() const;
    };
}

QT_END_NAMESPACE

#endif
