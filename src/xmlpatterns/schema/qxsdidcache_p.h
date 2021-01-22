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

#ifndef Patternist_XsdIdCache_H
#define Patternist_XsdIdCache_H

#include <private/qschemacomponent_p.h>

#include <QtCore/QExplicitlySharedDataPointer>
#include <QtCore/QReadWriteLock>
#include <QtCore/QSet>
#include <QtCore/QString>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Helper class for keeping track of all existing IDs in a schema.
     *
     * @ingroup Patternist_schema
     * @author Tobias Koenig <tobias.koenig@nokia.com>
     */
    class XsdIdCache : public QSharedData
    {
        public:
            typedef QExplicitlySharedDataPointer<XsdIdCache> Ptr;

            /**
             * Adds an @p id to the id cache.
             */
            void addId(const QString &id);

            /**
             * Returns whether the id cache contains the given @p id already.
             */
            bool hasId(const QString &id) const;

        private:
            QSet<QString>          m_ids;
            mutable QReadWriteLock m_lock;
    };
}

QT_END_NAMESPACE

#endif
