#!/bin/sh
#############################################################################
##
## Copyright (C) 2021 The Qt Company Ltd.
## Contact: https://www.qt.io/licensing/
##
## This file is the build configuration utility of the Qt Toolkit.
##
## $QT_BEGIN_LICENSE:COMM$
##
## Commercial License Usage
## Licensees holding valid commercial Qt licenses may use this file in
## accordance with the commercial license agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and The Qt Company. For licensing terms
## and conditions see https://www.qt.io/terms-conditions. For further
## information use the contact form at https://www.qt.io/contact-us.
##
## $QT_END_LICENSE$
##
##
##
##
##
##
##
##
##
##
##
##
##
##
##
##
##
##
##
############################################################################

outFile="qtokenlookup.cpp"

head -n 38 TokenLookup.gperf > $outFile

# Watch out, the --output option is not supported in the
# gperf version that apt-get pulls in on Mac OS X.
gperf TokenLookup.gperf | sed \
    -e 's/size_t/unsigned int/g' \
    -e 's!/\*FALLTHROUGH\*/!  Q_FALLTHROUGH();!' >> $outFile
