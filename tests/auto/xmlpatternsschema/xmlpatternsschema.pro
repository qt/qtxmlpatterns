load(qttest_p4)
load(qt_module)

SOURCES += tst_xmlpatternsschema.cpp \

include (../xmlpatterns.pri)

INCLUDEPATH += $$QT.xmlpatterns.private_includes
