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

#ifndef QPatternist_ReferenceCountedValue_p_h
#define QPatternist_ReferenceCountedValue_p_h

QT_BEGIN_NAMESPACE

namespace QPatternist
{
/*!
   \class ReferenceCountedValue
   \internal
   \since 4.4
   \brief A template class that reference counts a value.

   This class is useful when an instance needs to have ownership semantics
   as if it was value based. A typical examples is a QObject pointer, which
   doesn't have a single owner.

   This is achieved through storing a copy of the object as
   a member inside ReferenceCountedValue, which never is copied. It will
   stay in scope until the last reference to the ReferenceCountedValue instance
   is removed, and subsequently ReferenceCountedValue is deleted and hence also
   the contained value. One should use ReferenceCountedValue by passing around
   copies of Ptr, which is a typedef for the QExplicitlySharedDataPointer
   smart pointer.
*/
    template<typename T>
    class ReferenceCountedValue : public QSharedData
    {
    public:
        typedef QExplicitlySharedDataPointer<ReferenceCountedValue<T> > Ptr;

        inline ReferenceCountedValue(T *const v) : value(v)
        {
        }

        inline ~ReferenceCountedValue()
        {
            delete value;
        }

        T *const value;
    private:
        /*!
          Disabled, no implementation provided.
         */
        inline ReferenceCountedValue();
        Q_DISABLE_COPY(ReferenceCountedValue)
    };
}

QT_END_NAMESPACE

#endif
