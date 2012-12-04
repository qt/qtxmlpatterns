QT          += widgets xmlpatterns
HEADERS     = mainwindow.h stationdialog.h stationquery.h timequery.h
SOURCES     = main.cpp mainwindow.cpp stationdialog.cpp stationquery.cpp timequery.cpp
FORMS       = stationdialog.ui

target.path = $$[QT_INSTALL_EXAMPLES]/xmlpatterns/trafficinfo
INSTALLS += target

maemo5: CONFIG += qt_example

maemo5: warning(This example might not fully work on Maemo platform)
simulator: warning(This example might not fully work on Simulator platform)
