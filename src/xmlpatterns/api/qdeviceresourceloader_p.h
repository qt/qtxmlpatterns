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

#ifndef QPatternist_DeviceResourceLoader_p_H
#define QPatternist_DeviceResourceLoader_p_H

#include <private/qresourceloader_p.h>

QT_BEGIN_NAMESPACE

template<typename T> class QSet;
class QUrl;

namespace QPatternist
{
    /**
     * @short Base class for resource loaders that manage device variables.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @since 4.5
     */
    class DeviceResourceLoader : public ResourceLoader
    {
    public:
        typedef QExplicitlySharedDataPointer<DeviceResourceLoader> Ptr;
        /**
         * @short Returns the URIs for device variables that this
         * ResourceLoader has loaded.
         *
         * The returned set may be empty.
         */
        virtual QSet<QUrl> deviceURIs() const = 0;
    };
}

QT_END_NAMESPACE
#endif
