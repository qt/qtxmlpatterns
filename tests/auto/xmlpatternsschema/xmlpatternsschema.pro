TARGET = tst_xmlpatternsschema
CONFIG += testcase
QT += testlib

SOURCES += tst_xmlpatternsschema.cpp \

include (../xmlpatterns.pri)

INCLUDEPATH += $$QT.xmlpatterns.private_includes
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
