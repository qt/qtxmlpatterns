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

#ifndef Patternist_DeduplicateIterator_H
#define Patternist_DeduplicateIterator_H

#include <QList>

#include <private/qexpression_p.h>
#include <private/qitem_p.h>
#include <private/qatomiccomparator_p.h>
#include <private/qcomparisonplatform_p.h>
#include <private/qsourcelocationreflection_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Performs deduplication of the nodes on its source list.
     *
     * @note The nodes in the source list must be in document order.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_iterators
     */
    class DeduplicateIterator : public ListIterator<Item>
    {
    public:
        DeduplicateIterator(const Item::List &source);

        virtual Item next();
        virtual Item::Iterator::Ptr copy() const;
        virtual xsInteger count();

    private:
        /**
         * m_position in ListIteratorPlatform is the position that we
         * show to the outside through position) but do not correspond
         * to the position in m_list, since we skip entries in that one.
         *
         * However, this guy, m_listPos, is the position into m_list.
         */
        int m_listPos;
    };
}

QT_END_NAMESPACE

#endif
