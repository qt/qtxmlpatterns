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

#ifndef Patternist_ProjectedExpression_H
#define Patternist_ProjectedExpression_H

#include <private/qitem_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    class ProjectedExpression
    {
    public:
        typedef ProjectedExpression * Ptr;
        typedef QVector<ProjectedExpression::Ptr> Vector;
        virtual ~ProjectedExpression()
        {
        }

        enum Action
        {
            Move = 0,
            Skip = 1,
            Keep = 2,
            KeepSubtree = 4 | Keep
        };

        virtual Action actionForElement(const QXmlName name,
                                        ProjectedExpression::Ptr &next) const
        {
            Q_UNUSED(name);
            Q_UNUSED(next);
            return Skip;
        }

    };

    class ProjectedNodeTest
    {
    public:
        typedef ProjectedNodeTest * Ptr;
        virtual ~ProjectedNodeTest()
        {
        }

        virtual bool isMatch(const QXmlNodeModelIndex::NodeKind kind) const
        {
            Q_UNUSED(kind);
            return false;
        }
    };

    class ProjectedStep : public ProjectedExpression
    {
    public:
        ProjectedStep(const ProjectedNodeTest::Ptr test,
                      const QXmlNodeModelIndex::Axis axis)
        {
            Q_ASSERT(test);
            Q_UNUSED(test);
            Q_UNUSED(axis);
        }

        virtual Action actionForElement(const QXmlName name,
                                        ProjectedExpression::Ptr &next) const
        {
            Q_UNUSED(name);
            Q_UNUSED(next);
            // TODO
            return Skip;
        }

    private:
    };

    class ProjectedPath : public ProjectedExpression
    {
    public:
        ProjectedPath(const ProjectedExpression::Ptr left,
                      const ProjectedExpression::Ptr right) : m_left(left)
        {
            Q_ASSERT(m_left);
            Q_ASSERT(right);
            Q_UNUSED(right);
        }

        virtual Action actionForElement(const QXmlName name,
                                        ProjectedExpression::Ptr &next) const
        {
            ProjectedExpression::Ptr &candidateNext = next;
            const Action a = m_left->actionForElement(name, candidateNext);

            if(a != Skip)
            {
                /* The test accepted it, so let's replace us with the new step. */
                next = candidateNext;
            }

            return a;
        }

    private:
        const ProjectedExpression::Ptr  m_left;
    };
}

QT_END_NAMESPACE

#endif
