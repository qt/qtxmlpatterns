TARGET = tst_checkxmlfiles
CONFIG += testcase
SOURCES += tst_checkxmlfiles.cpp \
           ../qxmlquery/TestFundament.cpp
QT = core gui testlib

include (../xmlpatterns.pri)

wince*: {
QT += network
addFiles.files = \
	$$QT.sql.sources/../../examples/sql/masterdetail/albumdetails.xml \
	../../../examples/xquery/globalVariables/globals.gccxml \
	../../../../qtdoc/doc/src/diagrams/stylesheet/treeview.svg \
	../../../../qtdoc/doc/src/diagrams/designer-manual/designer-mainwindow-actions.ui \
	$$QT.widgets.sources/../../examples/tools/undo/undo.qrc
addFiles.path = xmlfiles
DEPLOYMENT += addFiles
} else {
    DEFINES += SOURCETREE=\\\"$$absolute_path(../../..)/\\\"
}
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
