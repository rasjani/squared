OBJECTS_DIR = .obj
CONFIG += link_pkgconfig \
    warn_on
QT -= gui \
    core


PKGCONFIG += sdl
LIBS += -lSDL_image -lSDL_ttf -lm
TEMPLATE = app
TARGET = test
DEPENDPATH += .
INCLUDEPATH += .
QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -Werror
HEADERS += \
    cengine.h \
    cmyengine.h \
    csurface.h \
    csurfacemanager.h \
    cfontmanager.h \
    canimation.h \
    centitymanager.h \
    centity.h \
    yoshient.h \
    yoshient2.h \

SOURCES += \
    cengine.cpp \
    cmyengine.cpp \
    main.cpp \
    cmysurface.cpp \
    cmysurfacemanager.cpp\
    cmyanimation.cpp \
    cmyfontmanager.cpp \
    cmyentitymanager.cpp \
    centity.cpp \
    yoshient.cpp \
    yoshient2.cpp \

