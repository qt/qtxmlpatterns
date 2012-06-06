TEMPLATE = subdirs
SUBDIRS += xquery
!contains(QT_CONFIG, no-widgets): SUBDIRS += filetree trafficinfo schema recipes
