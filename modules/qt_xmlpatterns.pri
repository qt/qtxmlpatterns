QT.xmlpatterns.VERSION = 5.0.0
QT.xmlpatterns.MAJOR_VERSION = 5
QT.xmlpatterns.MINOR_VERSION = 0
QT.xmlpatterns.PATCH_VERSION = 0

QT.xmlpatterns.name = QtXmlPatterns
QT.xmlpatterns.bins = $$QT_MODULE_BIN_BASE
QT.xmlpatterns.includes = $$QT_MODULE_INCLUDE_BASE $$QT_MODULE_INCLUDE_BASE/QtXmlPatterns
QT.xmlpatterns.private_includes = $$QT_MODULE_INCLUDE_BASE/QtXmlPatterns/$$QT.xmlpatterns.VERSION
QT.xmlpatterns.sources = $$QT_MODULE_BASE/src/xmlpatterns
QT.xmlpatterns.libs = $$QT_MODULE_LIB_BASE
QT.xmlpatterns.plugins = $$QT_MODULE_PLUGIN_BASE
QT.xmlpatterns.imports = $$QT_MODULE_IMPORT_BASE
QT.xmlpatterns.depends = core network
QT.xmlpatterns.DEFINES = QT_XMLPATTERNS_LIB

QT_CONFIG += xmlpatterns
