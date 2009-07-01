OBJECTS_DIR=.obj 
QT-= gui core
CONFIG += ordered link_pkgconfig warn_on
PKGCONFIG += sdl 
LIBS += -lSDL_image -lSDL_ttf -lm
QMAKE_CXXFLAGS += -Wall -Werror  -pedantic-errors
