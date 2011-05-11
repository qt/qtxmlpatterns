%modules = ( # path to module name map
    "QtXmlPatterns" => "$basedir/src/xmlpatterns",
);
%moduleheaders = ( # restrict the module headers to those found in relative path
);
%classnames = (
    "qtxmlpatternsversion.h" => "QtXmlPatternsVersion",
);
%mastercontent = (
    "core" => "#include <QtCore/QtCore>\n",
    "network" => "#include <QtNetwork/QtNetwork>\n",
);
%modulepris = (
    "QtXmlPatterns" => "$basedir/modules/qt_xmlpatterns.pri",
);
# Modules and programs, and their dependencies.
# Each of the module version specifiers can take one of the following values:
#   - A specific Git revision.
#   - "LATEST_REVISION", to always test against the latest revision.
#   - "LATEST_RELEASE", to always test against the latest public release.
#   - "THIS_REPOSITORY", to indicate that the module is in this repository.
%dependencies = (
    "QtXmlPatterns" => {
        "QtCore" => "0c637cb07ba3c9b353e7e483a209537485cc4e2a",
        "QtNetwork" => "0c637cb07ba3c9b353e7e483a209537485cc4e2a",
    },
);
