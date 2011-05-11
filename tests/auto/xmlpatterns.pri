DEFINES += QTEST_XMLPATTERNS
QT += core-private xmlpatterns xmlpatterns-private

wince*: {
    patternsdk.files = $$QT_BUILD_TREE/lib/QtXmlPatternsSDK*.dll
    patternsdk.path = .
    basedata.files = xmlpaternsxqts/Baseline.xml
    basedata.path = .
    DEPLOYMENT += patternsdk
    QT += network
}
QT -= gui

XMLPATTERNS_SDK = QtXmlPatternsSDK
if(!debug_and_release|build_pass):CONFIG(debug, debug|release) {
    symbian:    XMLPATTERNS_SDK = $${XMLPATTERNS_SDK}
    else:win32: XMLPATTERNS_SDK = $${XMLPATTERNS_SDK}d
    else:       XMLPATTERNS_SDK = $${XMLPATTERNS_SDK}_debug
}

XMLPATTERNS_SOURCES = $$QT.xmlpatterns.sources
INCLUDEPATH += \
               $$XMLPATTERNS_SOURCES/acceltree \
               $$XMLPATTERNS_SOURCES/api \
               $$XMLPATTERNS_SOURCES/data \
               $$XMLPATTERNS_SOURCES/environment \
               $$XMLPATTERNS_SOURCES/expr \
               $$XMLPATTERNS_SOURCES/functions \
               $$XMLPATTERNS_SOURCES/iterators \
               $$XMLPATTERNS_SOURCES/janitors \
               $$XMLPATTERNS_SOURCES/parser \
               $$XMLPATTERNS_SOURCES/projection \
               $$XMLPATTERNS_SOURCES/schema \
               $$XMLPATTERNS_SOURCES/type \
               $$XMLPATTERNS_SOURCES/utils
