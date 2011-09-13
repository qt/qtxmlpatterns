SOURCES += main.cpp filetree.cpp mainwindow.cpp ../shared/xmlsyntaxhighlighter.cpp
HEADERS += filetree.h  mainwindow.h ../shared/xmlsyntaxhighlighter.h
FORMS += forms/mainwindow.ui
QT += widgets xmlpatterns
RESOURCES += queries.qrc
INCLUDEPATH += ../shared/

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns/filetree
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro *.xq *.html
sources.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns/filetree
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xA000D7C4
    CONFIG += qt_example
}
maemo5: CONFIG += qt_example

symbian: warning(This example might not fully work on Symbian platform)
maemo5: warning(This example might not fully work on Maemo platform)
simulator: warning(This example might not fully work on Simulator platform)
