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

#ifndef Patternist_Focus_H
#define Patternist_Focus_H

#include <private/qdelegatingdynamiccontext_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A DynamicContext that maintains the focus, a sequence
     * of items.
     *
     * Focus implements both the outer and inner focus. The focus is one of
     * the things that characterizes the XPath language. The focus is what's
     * iterated over in a predicate, whose current item can be received
     * via the context item expression, <tt>.</tt>(the dot),
     * and whose size is retrievable via the function <tt>fn:last()</tt>.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class Focus : public DelegatingDynamicContext
    {
    public:
        Focus(const DynamicContext::Ptr &prevContext);

        virtual xsInteger contextPosition() const;
        virtual Item contextItem() const;
        virtual xsInteger contextSize();

        virtual void setFocusIterator(const Item::Iterator::Ptr &it);
        virtual Item::Iterator::Ptr focusIterator() const;

        /**
         * If there is no top level expression that sets the current item,
         * the focus should be used. This implementation ensures that.
         */
        virtual Item currentItem() const;

    private:
        Item::Iterator::Ptr m_focusIterator;
        xsInteger           m_contextSizeCached;
    };
}

QT_END_NAMESPACE

#endif
