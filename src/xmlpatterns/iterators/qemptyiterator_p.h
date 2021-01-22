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

#ifndef Patternist_EmptyIterator_H
#define Patternist_EmptyIterator_H

#include <private/qabstractxmlforwarditerator_p.h>
#include <private/qprimitives_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short An QAbstractXmlForwardIterator which always is empty.
     *
     * EmptyIterator is an QAbstractXmlForwardIterator over the type @c T, which always is empty. Other
     * iterators can also be empty(or, at least behave as they are empty), but this
     * class is special designed for this purpose and is therefore fast.
     *
     * EmptyIterator's constructor is protected, instances is retrieved from CommonValues.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_iterators
     */
    template<typename T> class EmptyIterator : public QAbstractXmlForwardIterator<T>
    {
    public:
        /**
         * @returns always a default constructed value, T().
         */
        virtual T next()
        {
            return T();
        }

        /**
         * @returns always a default constructed value, T().
         */
        virtual T current() const
        {
            return T();
        }

        /**
         * @returns always 0.
         */
        virtual xsInteger position() const
        {
            return 0;
        }

        /**
         * @returns always @c this, the reverse of <tt>()</tt> is <tt>()</tt>.
         */
        virtual typename QAbstractXmlForwardIterator<T>::Ptr toReversed()
        {
            return typename QAbstractXmlForwardIterator<T>::Ptr(const_cast<EmptyIterator<T> *>(this));
        }

        /**
         * @returns always 0
         */
        virtual xsInteger count()
        {
            return 0;
        }

        /**
         * @returns @c this
         */
        virtual typename QAbstractXmlForwardIterator<T>::Ptr copy() const
        {
            return typename QAbstractXmlForwardIterator<T>::Ptr(const_cast<EmptyIterator *>(this));
        }

    protected:
        friend class CommonValues;
    };

    template<typename T>
    static inline
    typename QAbstractXmlForwardIterator<T>::Ptr
    makeEmptyIterator()
    {
        return typename QAbstractXmlForwardIterator<T>::Ptr(new EmptyIterator<T>());
    }

}

QT_END_NAMESPACE

#endif
