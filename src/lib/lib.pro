include(../../config.pri)
DESTDIR=../..
TEMPLATE = lib
TARGET = squared

HEADERS += canimation.h \
           cengine.h \
           centity.h \
           centitymanager.h \
           cfontmanager.h \
           csurface.h \
           csurfacemanager.h
SOURCES += cengine.cpp \
           centity.cpp \
           cmyanimation.cpp \
           cmyentitymanager.cpp \
           cmyfontmanager.cpp \
           cmysurface.cpp \
           cmysurfacemanager.cpp
