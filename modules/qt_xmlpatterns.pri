QT_XMLPATTERNS_VERSION = $$QT_VERSION
QT_XMLPATTERNS_MAJOR_VERSION = $$QT_MAJOR_VERSION
QT_XMLPATTERNS_MINOR_VERSION = $$QT_MINOR_VERSION
QT_XMLPATTERNS_PATCH_VERSION = $$QT_PATCH_VERSION

QT.xmlpatterns.name = QtXmlPatterns
QT.xmlpatterns.bins = $$QT_MODULE_BIN_BASE
QT.xmlpatterns.includes = $$QT_MODULE_INCLUDE_BASE $$QT_MODULE_INCLUDE_BASE/QtXmlPatterns
QT.xmlpatterns.private_includes = $$QT_MODULE_INCLUDE_BASE/QtXmlPatterns/private
QT.xmlpatterns.sources = $$QT_MODULE_BASE/src/xmlpatterns
QT.xmlpatterns.libs = $$QT_MODULE_LIB_BASE
QT.xmlpatterns.plugins = $$QT_MODULE_PLUGIN_BASE
QT.xmlpatterns.imports = $$QT_MODULE_IMPORT_BASE
QT.xmlpatterns.depends = core network
QT.xmlpatterns.DEFINES = QT_XMLPATTERNS_LIB

QT_CONFIG += xmlpatterns
