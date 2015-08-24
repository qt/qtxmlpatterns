CONFIG += testcase
QT += testlib
SOURCES += tst_xmlpatternsview.cpp

include (../xmlpatterns.pri)

TARGET = tst_xmlpatternsview

wince*: {
    viewexe.files = $$QT.xmlpatterns.bins/xmlpatternsview.exe
    viewexe.path = .
    DEPLOYMENT += viewexe
}
