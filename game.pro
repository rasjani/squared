OBJECTS_DIR = .obj
CONFIG += link_pkgconfig \
    warn_on
PKGCONFIG += sdl
LIBS += -lSDL_image
TEMPLATE = app
TARGET = test
DEPENDPATH += .
INCLUDEPATH += .
QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -Werror
HEADERS += cengine.h \
    cmyengine.h \
    csurface.h \
    csurfacemanager.h
SOURCES += cengine.cpp \
    cmyengine.cpp \
    main.cpp \
    cmysurface.cpp \
    cmysurfacemanager.cpp
