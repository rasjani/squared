include(../../config.pri)
DESTDIR=../..
TEMPLATE = lib
TARGET = squared

HEADERS += animationmanager.h \
           engine.h \
           entity.h \
           entitymanager.h \
           fontmanager.h \
           surface.h \
           surfacemanager.h \
           filemanager.h \

SOURCES += engine.cpp \
           entity.cpp \
           animationmanager.cpp \
           entitymanager.cpp \
           fontmanager.cpp \
           surface.cpp \
           surfacemanager.cpp \
           filemanager.cpp \

include(../../depend.pri)
