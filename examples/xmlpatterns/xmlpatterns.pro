TEMPLATE = subdirs
SUBDIRS += xquery
!contains(QT_CONFIG, no-widgets): SUBDIRS += filetree schema recipes

EXAMPLE_FILES = \
    shared

