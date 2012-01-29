QT          += widgets xmlpatterns
FORMS       += schema.ui schema_mobiles.ui
HEADERS     = mainwindow.h ../shared/xmlsyntaxhighlighter.h
RESOURCES   = schema.qrc
SOURCES     = main.cpp mainwindow.cpp ../shared/xmlsyntaxhighlighter.cpp
INCLUDEPATH += ../shared/

target.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns/schema
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro *.xq *.html files
sources.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns/schema
INSTALLS += target sources

maemo5: CONFIG += qt_example

