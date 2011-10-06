CONFIG += testcase
QT += testlib
SOURCES += tst_xmlpatternsview.cpp

include (../xmlpatterns.pri)

TARGET = tst_xmlpatternsview

wince*: {
    viewexe.files = $$QT_BUILD_TREE/xmlpatternsview.exe
    viewexe.path = .
    DEPLOYMENT += viewexe
}
