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

#ifndef Patternist_AbstractNodeTest_H
#define Patternist_AbstractNodeTest_H

#include <private/qanynodetype_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A name test that is of the type <tt>prefix:ncName</tt>.
     *
     * @ingroup Patternist_types
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AbstractNodeTest : public AnyNodeType
    {
    public:
        AbstractNodeTest(const ItemType::Ptr &primaryType);

        bool xdtTypeMatches(const ItemType::Ptr &other) const override;
        ItemType::Ptr xdtSuperType() const override;
        ItemType::Ptr atomizedType() const override;

    protected:
        const ItemType::Ptr m_primaryType;
    };
}

QT_END_NAMESPACE

#endif
