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
