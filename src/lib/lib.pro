include(../../config.pri)
DESTDIR=../..
TEMPLATE = lib
TARGET = squared

HEADERS += animationmanager.h \
           engine.h \
           entity.h \
           entitymanager.h \
           fontmanager.h \
           rawsurface.h \
           surface.h \
           surfacemanager.h \
           filemanager.h \

SOURCES += engine.cpp \
           entity.cpp \
           animationmanager.cpp \
           entitymanager.cpp \
           fontmanager.cpp \
           rawsurface.cpp \
           surface.cpp \
           surfacemanager.cpp \
           filemanager.cpp \


