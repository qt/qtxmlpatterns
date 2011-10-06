TARGET = tst_xmlpatterns
CONFIG += testcase
QT += testlib
SOURCES += tst_xmlpatterns.cpp \
           ../qxmlquery/TestFundament.cpp

wince* {
DEFINES += SRCDIR=\\\"./\\\"
} else:!symbian {
DEFINES += SRCDIR=\\\"$$PWD/\\\"
}

include (../xmlpatterns.pri)
