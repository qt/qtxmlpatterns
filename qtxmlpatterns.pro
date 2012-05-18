TEMPLATE = subdirs

module_qtxmlpatterns_src.subdir = src
module_qtxmlpatterns_src.target = module-qtxmlpatterns-src

module_qtxmlpatterns_tools.subdir = tools
module_qtxmlpatterns_tools.target = module-qtxmlpatterns-tools
module_qtxmlpatterns_tools.depends = module_qtxmlpatterns_src

module_qtxmlpatterns_examples.subdir = examples/xmlpatterns
module_qtxmlpatterns_examples.target = module-qtxmlpatterns-examples
module_qtxmlpatterns_examples.depends = module_qtxmlpatterns_src
!contains(QT_BUILD_PARTS,examples) {
    module_qtxmlpatterns_examples.CONFIG = no_default_target no_default_install
}

module_qtxmlpatterns_tests.subdir = tests
module_qtxmlpatterns_tests.target = module-qtxmlpatterns-tests
module_qtxmlpatterns_tests.depends = module_qtxmlpatterns_src
module_qtxmlpatterns_tests.CONFIG = no_default_install
!contains(QT_BUILD_PARTS,tests):module_qtxmlpatterns_tests.CONFIG += no_default_target

SUBDIRS += module_qtxmlpatterns_src \
           module_qtxmlpatterns_tools \
           module_qtxmlpatterns_examples \
           module_qtxmlpatterns_tests \

include (doc/doc.pri)
