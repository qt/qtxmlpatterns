TEMPLATE = app
TARGET = xmlpatternsvalidator
QT -= gui
QT += xmlpatterns

DESTDIR = $$QT.xmlpatterns.bins
target.path = $$[QT_INSTALL_BINS]
INSTALLS += target

# This ensures we get stderr and stdout on Windows.
CONFIG += console

# This ensures that this is a command-line program on OS X and not a GUI application.
CONFIG -= app_bundle

SOURCES = main.cpp
HEADERS = main.h

