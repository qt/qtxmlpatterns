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

#ifndef Patternist_OptimizationBlocks_H
#define Patternist_OptimizationBlocks_H

#include <private/qatomiccomparator_p.h>
#include <private/qexpression_p.h>
#include <private/qoptimizerframework_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Contains a set of common OptimizerPass instances.
     *
     * @author Frans englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    namespace OptimizationPasses
    {
        /**
         * A list of OptimizerPass instances that performs the
         * following rewrites:
         *
         * - <tt>count([expr]) ne 0</tt> into <tt>exists([expr])</tt>
         * - <tt>count([expr]) != 0</tt> into <tt>exists([expr])</tt>
         * - <tt>0 ne count([expr])</tt> into <tt>exists([expr])</tt>
         * - <tt>0 != count([expr])</tt> into <tt>exists([expr])</tt>
         * - <tt>count([expr]) eq 0</tt> into <tt>empty([expr])</tt>
         * - <tt>count([expr]) = 0</tt> into <tt>empty([expr])</tt>
         * - <tt>0 eq count([expr])</tt> into <tt>empty([expr])</tt>
         * - <tt>0 = count([expr])</tt> into <tt>empty([expr])</tt>
         * - <tt>count([expr]) ge 1</tt> into <tt>exists([expr])</tt>
         * - <tt>count([expr]) >= 1</tt> into <tt>exists([expr])</tt>
         */
        extern OptimizationPass::List comparisonPasses;

        /**
         * A list of OptimizerPass instances that performs the
         * following rewrites:
         *
         * - <tt>for $var in [expr] return $var</tt> into <tt>[expr]</tt>
         */
        extern OptimizationPass::List forPasses;

        /**
         * A list of OptimizerPass instances that performs the
         * following rewrites:
         *
         * - <tt>if([expr of type xs:boolean]) then true() else false()</tt>
         *   into <tt>[expr of type xs:boolean]</tt>
         */
        extern OptimizationPass::List ifThenPasses;

        /**
         * A list of OptimizerPass instances that performs the
         * following rewrites:
         *
         * - <tt>fn:not(fn:exists([expr]))</tt> into <tt>fn:empty([expr])</tt>
         * - <tt>fn:not(fn:empty([expr]))</tt> into <tt>fn:exists([expr])</tt>
         */
        extern OptimizationPass::List notFN;

        /**
         * Initializes the data members in the OptimizationPasses namespace.
         *
         * This class is not supposed to be instantiated, but to be used via its init()
         * function. In fact, this class cannot be instantiated.
         *
         * @author Frans englich <frans.englich@nokia.com>
         */
        class Coordinator
        {
        public:
            /**
             * Initializes the members in the OptimizationPasses namespace.
             */
            static void init();

        private:
            Q_DISABLE_COPY(Coordinator)
            inline Coordinator();
        };
    }
}

QT_END_NAMESPACE

#endif
