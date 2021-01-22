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

#ifndef Patternist_Debug_H
#define Patternist_Debug_H

#include <QtDebug>
/**
 * @file
 * @short Contains macros for debugging.
 */

QT_BEGIN_NAMESPACE

/**
 * @short Enables detailed parser debug output.
 *
 * If this macro is defined, @em a @em lot of debugging information will be outputted.
 * This is all the state transitions, token shifting, and rule reductions that
 * the parser do.
 *
 * This is automatically disabled if @c QT_NO_DEBUG is defined.
 */
#define Patternist_DEBUG_PARSER

/**
 * @short Enables debug printing statements.
 *
 * Patternist does not use qDebug(), but pDebug() instead. It only output
 * if this define is defined.
 *
 * It is automatically disabled if @c QT_NO_DEBUG is defined.
 */
#define Patternist_DEBUG

#undef Patternist_DEBUG // disable it for now

#ifdef QT_NO_DEBUG
#   undef Patternist_DEBUG_PARSER
#   undef Patternist_DEBUG
#endif

namespace QPatternist
{
#ifdef Patternist_DEBUG
    inline QDebug pDebug()
    {
        return qDebug();
    }
#else
    inline QNoDebug pDebug()
    {
        return QNoDebug();
    }
#endif
}

QT_END_NAMESPACE
#endif
