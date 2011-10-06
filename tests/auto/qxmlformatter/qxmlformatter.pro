TARGET = tst_qxmlformatter
CONFIG += testcase
QT += testlib
SOURCES += tst_qxmlformatter.cpp

include (../xmlpatterns.pri)

wince*|symbian:{
   addFiles.files = baselines input
   addFiles.path = .
   DEPLOYMENT += addFiles
}
