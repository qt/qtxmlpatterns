QT          += widgets xmlpatterns
HEADERS     = mainwindow.h stationdialog.h stationquery.h timequery.h
SOURCES     = main.cpp mainwindow.cpp stationdialog.cpp stationquery.cpp timequery.cpp
FORMS       = stationdialog.ui

target.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns/trafficinfo
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns/trafficinfo
INSTALLS += target sources

maemo5: CONFIG += qt_example

maemo5: warning(This example might not fully work on Maemo platform)
simulator: warning(This example might not fully work on Simulator platform)
