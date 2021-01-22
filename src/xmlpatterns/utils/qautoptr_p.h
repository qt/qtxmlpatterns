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

#ifndef QPatternist_AutoPtr_p_h
#define QPatternist_AutoPtr_p_h

#include <QtGlobal>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    template<typename T>
    class AutoPtrRef
    {
    public:
        explicit AutoPtrRef(T *const other) : m_ptr(other)
        {
        }

        T* m_ptr;
    };

    template<typename T>
    class AutoPtr
    {
    public:
        explicit inline AutoPtr(T *pointer = 0) : m_ptr(pointer)
        {
        }

        inline AutoPtr(AutoPtr<T> &other) : m_ptr(other.release())
        {
        }

        inline ~AutoPtr()
        {
            delete m_ptr;
        }

        inline T &operator*() const
        {
            Q_ASSERT_X(m_ptr, Q_FUNC_INFO, "");
            return *m_ptr;
        }

        T *operator->() const
        {
            Q_ASSERT_X(m_ptr, Q_FUNC_INFO, "");
            return m_ptr;
        }

        inline bool operator!() const
        {
            return !m_ptr;
        }

        inline operator bool() const
        {
            return m_ptr != 0;
        }

        AutoPtr(AutoPtrRef<T> ref) : m_ptr(ref.m_ptr)
        {
        }

        AutoPtr& operator=(AutoPtrRef<T> ref)
        {
            if(ref.m_ptr != m_ptr)
            {
                delete m_ptr;
                m_ptr = ref.m_ptr;
            }
            return *this;
        }

        template<typename L>
        operator AutoPtrRef<L>()
        {
            return AutoPtrRef<L>(this->release());
        }

        template<typename L>
        operator AutoPtr<L>()
        {
            return AutoPtr<L>(this->release());
        }

        template<typename L>
        inline AutoPtr(AutoPtr<L>& other) : m_ptr(other.release())
        {
        }

        inline T *release()
        {
            T *const retval = m_ptr;
            m_ptr = 0;
            return retval;
        }

        inline T *data() const
        {
            return m_ptr;
        }

        void reset(T * other = 0)
        {
            if(other != m_ptr)
            {
                delete m_ptr;
                m_ptr = other;
            }
        }

        inline AutoPtr &operator=(AutoPtr &other)
        {
            reset(other.release());
            return *this;
        }

    private:
        T *m_ptr;
    };
}

QT_END_NAMESPACE
#endif
