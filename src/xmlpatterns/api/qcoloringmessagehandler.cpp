/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
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

#include <QXmlStreamReader>

#include "qcoloringmessagehandler_p.h"
#include "qxmlpatternistcli_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

ColoringMessageHandler::ColoringMessageHandler(QObject *parent) : QAbstractMessageHandler(parent)
{
    m_classToColor.insert(QLatin1String("XQuery-data"), Data);
    m_classToColor.insert(QLatin1String("XQuery-expression"), Keyword);
    m_classToColor.insert(QLatin1String("XQuery-function"), Keyword);
    m_classToColor.insert(QLatin1String("XQuery-keyword"), Keyword);
    m_classToColor.insert(QLatin1String("XQuery-type"), Keyword);
    m_classToColor.insert(QLatin1String("XQuery-uri"), Data);
    m_classToColor.insert(QLatin1String("XQuery-filepath"), Data);

    /* If you're tuning the colors, take it easy laddie. Take into account:
     *
     * - Get over your own taste, there's others too on this planet
     * - Make sure it works well on black & white
     * - Make sure it works well on white & black
     */
    insertMapping(Location, CyanForeground);
    insertMapping(ErrorCode, RedForeground);
    insertMapping(Keyword, BlueForeground);
    insertMapping(Data, BlueForeground);
    insertMapping(RunningText, DefaultColor);
}

void ColoringMessageHandler::handleMessage(QtMsgType type,
                                           const QString &description,
                                           const QUrl &identifier,
                                           const QSourceLocation &sourceLocation)
{
    const bool hasLine = sourceLocation.line() != -1;

    switch(type)
    {
        case QtWarningMsg:
        {
            if(hasLine)
            {
                writeUncolored(QXmlPatternistCLI::tr("Warning in %1, at line %2, column %3: %4").arg(sourceLocation.uri().toString(),
                                                                                                 QString::number(sourceLocation.line()),
                                                                                                 QString::number(sourceLocation.column()),
                                                                                                 colorifyDescription(description)));
            }
            else
            {
                writeUncolored(QXmlPatternistCLI::tr("Warning in %1: %2").arg(sourceLocation.uri().toString(),
                                                                          colorifyDescription(description)));
            }

            break;
        }
        case QtFatalMsg:
        {
            const QString errorCode(identifier.fragment());
            Q_ASSERT(!errorCode.isEmpty());
            QUrl uri(identifier);
            uri.setFragment(QString());

            QString location;

            if(sourceLocation.isNull())
                location = QXmlPatternistCLI::tr("Unknown location");
            else
                location = sourceLocation.uri().toString();

            QString errorId;
            /* If it's a standard error code, we don't want to output the
             * whole URI. */
            if(uri.toString() == QLatin1String("http://www.w3.org/2005/xqt-errors"))
                errorId = errorCode;
            else
                errorId = identifier.toString();

            if(hasLine)
            {
                writeUncolored(QXmlPatternistCLI::tr("Error %1 in %2, at line %3, column %4: %5").arg(colorify(errorId, ErrorCode),
                                                                                                  colorify(location, Location),
                                                                                                  colorify(QString::number(sourceLocation.line()), Location),
                                                                                                  colorify(QString::number(sourceLocation.column()), Location),
                                                                                                  colorifyDescription(description)));
            }
            else
            {
                writeUncolored(QXmlPatternistCLI::tr("Error %1 in %2: %3").arg(colorify(errorId, ErrorCode),
                                                                           colorify(location, Location),
                                                                           colorifyDescription(description)));
            }
            break;
        }
        case QtCriticalMsg:
        case QtDebugMsg:
        case QtInfoMsg:
        {
            Q_ASSERT_X(false, Q_FUNC_INFO,
                       "message() is not supposed to receive QtCriticalMsg, QtInfoMsg or QtDebugMsg.");
            return;
        }
    }
}

QString ColoringMessageHandler::colorifyDescription(const QString &in) const
{
    QXmlStreamReader reader(in);
    QString result;
    result.reserve(in.size());
    ColorType currentColor = RunningText;

    while(!reader.atEnd())
    {
        reader.readNext();

        switch(reader.tokenType())
        {
            case QXmlStreamReader::StartElement:
            {
                if(reader.name() == QLatin1String("span"))
                {
                    Q_ASSERT(m_classToColor.contains(reader.attributes().value(QLatin1String("class")).toString()));
                    currentColor = m_classToColor.value(reader.attributes().value(QLatin1String("class")).toString());
                }

                continue;
            }
            case QXmlStreamReader::Characters:
            {
                result.append(colorify(reader.text().toString(), currentColor));
                continue;
            }
            case QXmlStreamReader::EndElement:
            {
                currentColor = RunningText;
                continue;
            }
            case QXmlStreamReader::StartDocument:
            case QXmlStreamReader::EndDocument:
                continue;
            default:
                Q_ASSERT_X(false, Q_FUNC_INFO,
                           "Unexpected node.");
        }
    }

    Q_ASSERT_X(!reader.hasError(), Q_FUNC_INFO,
               "The output from Patternist must be well-formed.");
    return result;
}

QT_END_NAMESPACE
