OBJECTS_DIR=.obj 
QT-= gui core
CONFIG += ordered warn_on
unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += sdl 
}
windows {

}
LIBS += -lSDL_image -lSDL_ttf -lm
QMAKE_CXXFLAGS += -Wall -Werror  -pedantic-errors

contains (TIMEDEXECUTION, on) {
    DEFINES += TIMEDEXECUTION
}
