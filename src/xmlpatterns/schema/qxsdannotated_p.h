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

#ifndef Patternist_XsdAnnotated_H
#define Patternist_XsdAnnotated_H

#include <private/qxsdannotation_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Base class for all XSD components with annotation content.
     *
     * @ingroup Patternist_schema
     * @author Tobias Koenig <tobias.koenig@nokia.com>
     */
    class XsdAnnotated
    {
        public:
            /**
             * Adds a new @p annotation to the component.
             */
            void addAnnotation(const XsdAnnotation::Ptr &annotation);

            /**
             * Adds a list of new @p annotations to the component.
             */
            void addAnnotations(const XsdAnnotation::List &annotations);

            /**
             * Returns the list of all annotations of the component.
             */
            XsdAnnotation::List annotations() const;

        private:
            XsdAnnotation::List m_annotations;
    };
}

QT_END_NAMESPACE

#endif
