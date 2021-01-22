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

#ifndef Patternist_qtokenvalue_p_H
#define Patternist_qtokenvalue_p_H

#include <QPair>
#include <QString>
#include <QList>

#include <private/qatomiccomparator_p.h>
#include <private/qatomicmathematician_p.h>
#include <private/qcombinenodes_p.h>
#include <private/qexpression_p.h>
#include <private/qfunctionargument_p.h>
#include <private/qorderby_p.h>
#include <private/qpath_p.h>
#include <private/qvalidate_p.h>

/**
 * @file
 * @short Contains functions and classes used by the parser and tokenizer.
 */

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A union of all the enums the parser uses.
     */
    union EnumUnion
    {
        AtomicComparator::Operator              valueOperator;
        AtomicMathematician::Operator           mathOperator;
        CombineNodes::Operator                  combinedNodeOp;
        QXmlNodeModelIndex::Axis                axis;
        QXmlNodeModelIndex::DocumentOrder       nodeOperator;
        StaticContext::BoundarySpacePolicy      boundarySpacePolicy;
        StaticContext::ConstructionMode         constructionMode;
        StaticContext::OrderingEmptySequence    orderingEmptySequence;
        StaticContext::OrderingMode             orderingMode;
        OrderBy::OrderSpec::Direction           sortDirection;
        Validate::Mode                          validationMode;
        VariableSlotID                          slot;
        int                                     tokenizerPosition;
        qint16                                  zeroer;
        bool                                    Bool;
        xsDouble                                Double;
        Path::Kind                              pathKind;
    };

    typedef QPair<QString, Expression::Ptr> AttributeHolder;
    typedef QVector<AttributeHolder> AttributeHolderVector;

    class OrderSpecTransfer
    {
    public:
        typedef QList<OrderSpecTransfer> List;
        inline OrderSpecTransfer()
        {
        }

        inline OrderSpecTransfer(const Expression::Ptr &aExpr,
                                 const OrderBy::OrderSpec aOrderSpec) : expression(aExpr),
                                                                        orderSpec(aOrderSpec)
        {
            Q_ASSERT(expression);
        }

        Expression::Ptr     expression;
        OrderBy::OrderSpec  orderSpec;
    };

    /**
     * @short The value the parser, but not the tokenizers, uses for tokens and
     * non-terminals.
     *
     * It is inefficient but ensures nothing leaks, by invoking C++
     * destructors even in the cases the code throws exceptions. This might be
     * able to be done in a more efficient way -- suggestions are welcome.
     */
    class TokenValue
    {
    public:
        QString                         sval;

        Expression::Ptr                 expr;
        Expression::List                expressionList;

        Cardinality                     cardinality;
        ItemType::Ptr                   itemType;
        SequenceType::Ptr               sequenceType;
        FunctionArgument::List          functionArguments;
        FunctionArgument::Ptr           functionArgument;
        QVector<QXmlName>               qNameVector;
        QXmlName                        qName;
        /**
         * Holds enum values.
         */
        EnumUnion                       enums;

        AttributeHolder                 attributeHolder;
        AttributeHolderVector           attributeHolders;
        OrderSpecTransfer::List         orderSpecs;
        OrderSpecTransfer               orderSpec;
    };
}

struct XPATHLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
#ifndef XPATHLTYPE_IS_DECLARED
#  define XPATHLTYPE_IS_DECLARED
#endif

QT_END_NAMESPACE

#endif // Patternist_qtokenvalue_p_H
