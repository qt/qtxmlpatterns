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

#ifndef Patternist_BuiltinNodeType_H
#define Patternist_BuiltinNodeType_H

#include <private/qitem_p.h>
#include <private/qanynodetype_p.h>
#include <private/qbuiltintypes_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short Instances of this class represents types that are sub-classes
     * of <tt>node()</tt>, such as <tt>processing-instruction()</tt>.
     *
     * @ingroup Patternist_types
     * @author Frans Englich <frans.englich@nokia.com>
     */
    template <const QXmlNodeModelIndex::NodeKind kind>
    class BuiltinNodeType : public AnyNodeType
    {
    public:
        bool xdtTypeMatches(const ItemType::Ptr &other) const override;
        bool itemMatches(const Item &item) const override;

        /**
         * @returns for example "text()", depending on what the constructor was passed
         */
        QString displayName(const NamePool::Ptr &np) const override;

        ItemType::Ptr xdtSuperType() const override;
        ItemType::Ptr atomizedType() const override;

        QXmlNodeModelIndex::NodeKind nodeKind() const override;

        PatternPriority patternPriority() const override;

    protected:
        friend class BuiltinTypes;

        /**
         * This constructor does nothing, but exists in order to make it impossible to
         * instantiate this class from anywhere but from BuiltinTypes.
         */
        BuiltinNodeType();
    };

#include "qbuiltinnodetype_tpl_p.h"

}

QT_END_NAMESPACE

#endif
