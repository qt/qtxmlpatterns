QT = core xmlpatterns-private

# Note that qcoloroutput.cpp and qcoloringmessagehandler.cpp are also used internally
# in libQtXmlPatterns. See src/xmlpatterns/api/api.pri.
SOURCES = main.cpp                          \
          qapplicationargument.cpp          \
          qapplicationargumentparser.cpp    


HEADERS = main.h                            \
          qapplicationargument.cpp          \
          qapplicationargumentparser.cpp    

load(qt_tool)
