TARGET = tst_xmlpatternsschema
CONFIG += testcase
QT += testlib
load(qt_module)

SOURCES += tst_xmlpatternsschema.cpp \

include (../xmlpatterns.pri)

INCLUDEPATH += $$QT.xmlpatterns.private_includes
