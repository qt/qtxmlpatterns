TARGET = tst_qxmlquery
CONFIG += testcase
SOURCES += tst_qxmlquery.cpp MessageValidator.cpp TestFundament.cpp
HEADERS += PushBaseliner.h                              \
           MessageSilencer.h                            \
           ../qsimplexmlnodemodel/TestSimpleNodeModel.h \
           MessageValidator.h                           \
           NetworkOverrider.h

RESOURCES = input.qrc

QT += network testlib

wince* {
    DEFINES += SRCDIR=\\\"./\\\"
} else {
    DEFINES += SRCDIR=\\\"$$PWD/\\\"
}

include (../xmlpatterns.pri)

wince*: {
   addFiles.files = pushBaselines input.xml
   addFiles.path    = .

   patternistFiles.files = ../xmlpatterns/queries
   patternistFiles.path    = ../xmlpatterns

   DEPLOYMENT += addFiles patternistFiles
}
