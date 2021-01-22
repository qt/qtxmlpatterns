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

# Generate ReportContext.h by invoking createReportContext.xsl, which
# in turns performs a transformation on the specs, fetched from http://www.w3.org/.

target="qreportcontext_p.h"
tmpFile=".reportContextInput.tmp.xml"
echo "<dummy/>" > $tmpFile
p4 revert $target
p4 edit $target
xsltproc createReportContext.xsl $tmpFile > $target
p4 revert -a $target
rm -f $tmpFile
