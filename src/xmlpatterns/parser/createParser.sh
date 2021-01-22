#!/bin/bash
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

files="qquerytransformparser_p.h qquerytransformparser.cpp"

#p4 revert $files
#p4 edit $files
bison --defines=qquerytransformparser_p.h querytransformparser.ypp

addHeaderScript="1{h; r trolltechHeader.txt
  D; }
2{x; G; }"
sed -i -e "$addHeaderScript" $files

sed -i -f winCEWorkaround.sed qquerytransformparser_p.h
#p4 revert -a $files
