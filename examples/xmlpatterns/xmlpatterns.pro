TEMPLATE = subdirs
SUBDIRS += xquery
!contains(QT_CONFIG, no-widgets): SUBDIRS += filetree trafficinfo schema recipes

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns
sources.files = xmlpatterns.pro shared
sources.path = $$[QT_INSTALL_EXAMPLES]/qtxmlpatterns/xmlpatterns
INSTALLS += target sources
