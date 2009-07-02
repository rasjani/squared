include(../../config.pri)
DESTDIR = ../..
LIBS += -L../.. -lsquared
TEMPLATE = app
TARGET = squared

DEPENDPATH += .
INCLUDEPATH += ../lib
HEADERS += \
    squaredengine.h \
    yoshient.h \
    yoshient2.h \

SOURCES += \
    squaredengine.cpp \
    main.cpp \
    yoshient.cpp \
    yoshient2.cpp \

include(../../depend.pri)
