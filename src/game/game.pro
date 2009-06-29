include(../../config.pri)
DESTDIR = ../..
LIBS += -L../.. -lsquared
TEMPLATE = app
TARGET = squared

DEPENDPATH += .
INCLUDEPATH += ../lib
HEADERS += \
    cmyengine.h \
    yoshient.h \
    yoshient2.h \

SOURCES += \
    cmyengine.cpp \
    main.cpp \
    yoshient.cpp \
    yoshient2.cpp \

