QT          += widgets xmlpatterns
FORMS       += forms/querywidget.ui \
               forms/querywidget_mobiles.ui
HEADERS     = querymainwindow.h ../shared/xmlsyntaxhighlighter.h
RESOURCES   = recipes.qrc
SOURCES     = main.cpp querymainwindow.cpp ../shared/xmlsyntaxhighlighter.cpp
INCLUDEPATH += ../shared/

target.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns/recipes
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro *.xq *.html forms files
sources.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns/recipes
INSTALLS += target sources

maemo5: CONFIG += qt_example

