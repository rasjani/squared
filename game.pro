OBJECTS_DIR = .obj
CONFIG += link_pkgconfig \
    warn_on
QT -= gui \
    core


PKGCONFIG += sdl
LIBS += -lSDL_image -lSDL_ttf
TEMPLATE = app
TARGET = test
DEPENDPATH += .
INCLUDEPATH += .
QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -Werror
HEADERS += cengine.h \
    cmyengine.h \
    csurface.h \
    csurfacemanager.h \
    cfontmanager.h \
    canimation.h \

SOURCES += cengine.cpp \
    cmyengine.cpp \
    main.cpp \
    cmysurface.cpp \
    cmysurfacemanager.cpp\
    cmyanimation.cpp \
    cmyfontmanager.cpp
