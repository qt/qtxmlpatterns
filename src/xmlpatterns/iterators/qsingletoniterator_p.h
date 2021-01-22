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

#ifndef Patternist_SingletonIterator_H
#define Patternist_SingletonIterator_H

#include <QtXmlPatterns/private/qabstractxmlforwarditerator_p.h>

#include <QtXmlPatterns/private/qprimitives_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short An QAbstractXmlForwardIterator over exactly one item.
     *
     * SingletonIterator's constructor takes one value which is
     * the item it forms an QAbstractXmlForwardIterator over. Other QAbstractXmlForwardIterator instances can
     * also form an QAbstractXmlForwardIterator with one in length, but by that SingletonIterator
     * has this as it only task, it means it is efficient at it.
     *
     * Having to represent single items in Iterators is relatively common.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_iterators
     */
    template<typename T>
    class SingletonIterator : public QAbstractXmlForwardIterator<T>
    {
    public:
        /**
         * Creates an iterator over @p item.
         *
         * @note item may not be @c null. Use the EmptyIterator for
         * the empty sequence
         */
        SingletonIterator(const T &item) : m_item(item),
                                           m_position(0)
        {
            Q_ASSERT(!qIsForwardIteratorEnd(item));
        }

        virtual T next()
        {
            switch(m_position)
            {
                case 0:
                {
                    ++m_position;
                    return m_item;
                }
                case 1:
                {
                    m_position = -1;
                    return T();
                }
                default:
                {
                    Q_ASSERT(m_position == -1);
                    return T();
                }
            }
        }

        virtual T current() const
        {
            if(m_position == 1)
                return m_item;
            else
                return T();
        }

        virtual xsInteger position() const
        {
            return m_position;
        }

        /**
         * @returns a copy of this instance, rewinded to the beginning.
         */
        virtual typename QAbstractXmlForwardIterator<T>::Ptr toReversed()
        {
            return typename QAbstractXmlForwardIterator<T>::Ptr(new SingletonIterator<T>(m_item));
        }

        /**
         * @returns always 1
         */
        virtual xsInteger count()
        {
            return 1;
        }

        virtual typename QAbstractXmlForwardIterator<T>::Ptr copy() const
        {
            return typename QAbstractXmlForwardIterator<T>::Ptr(new SingletonIterator(m_item));
        }

    private:
        const T m_item;
        qint8 m_position;
    };

    /**
     * @short An object generator for SingletonIterator.
     *
     * makeSingletonIterator() is a convenience function for avoiding specifying
     * the full template instantiation for SingletonIterator. Conceptually, it
     * is identical to Qt's qMakePair().
     *
     * @relates SingletonIterator
     */
    template<typename T>
    inline
    typename SingletonIterator<T>::Ptr
    makeSingletonIterator(const T &item)
    {
        return typename SingletonIterator<T>::Ptr(new SingletonIterator<T>(item));
    }
}

QT_END_NAMESPACE

#endif
