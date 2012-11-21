SOURCES += main.cpp filetree.cpp mainwindow.cpp ../shared/xmlsyntaxhighlighter.cpp
HEADERS += filetree.h  mainwindow.h ../shared/xmlsyntaxhighlighter.h
FORMS += forms/mainwindow.ui
QT += widgets xmlpatterns
RESOURCES += queries.qrc
INCLUDEPATH += ../shared/

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns/filetree
sources.files = $$SOURCES $$HEADERS $$RESOURCES forms queries *.pro *.xq *.html
sources.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns/filetree
INSTALLS += target sources

maemo5: CONFIG += qt_example

maemo5: warning(This example might not fully work on Maemo platform)
simulator: warning(This example might not fully work on Simulator platform)
