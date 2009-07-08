#include "events.h"
#include "support.h"
#include "logger.h"
#include <iostream>

Events::Events() :
        inputFocus(true) {

}

Events::~Events() {

}

void Events::onEvent(SDL_Event *Event) {
    switch (Event->type) {
        case SDL_ACTIVEEVENT:

            switch (Event->active.state) {
                case SDL_APPMOUSEFOCUS:

                    if ( Event->active.gain )
                        onMouseFocus();
                    else
                        onMouseBlur();

                    break;

                case SDL_APPINPUTFOCUS:
                    if ( Event->active.gain )
                        onInputFocus();
                    else
                        onInputBlur();

                    break;

                case SDL_APPACTIVE:
                    if ( Event->active.gain == 0 )
                        onMinimize();
                    else
                        onRestore();

                    break;
            }

            break;

        case SDL_KEYDOWN:
            onKeyDown(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.unicode);
            break;

        case SDL_KEYUP:
            onKeyUp(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.unicode);
            break;

        case SDL_MOUSEMOTION:
            onMouseMove(Event->motion.x,
                        Event->motion.y,
                        Event->motion.xrel,
                        Event->motion.yrel,
                        (Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,
                        (Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,
                        (Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0
                       );
            break;

        case SDL_MOUSEBUTTONDOWN:

            switch (Event->button.button)  {
                case SDL_BUTTON_LEFT:
                    onLButtonDown(Event->button.x,Event->button.y);
                    break;

                case SDL_BUTTON_RIGHT:
                    onRButtonDown(Event->button.x,Event->button.y);
                    break;

                case SDL_BUTTON_MIDDLE:
                    onMButtonDown(Event->button.x,Event->button.y);
                    break;
            }

            break;

        case SDL_MOUSEBUTTONUP:

            switch (Event->button.button) {
                case SDL_BUTTON_LEFT:
                    onLButtonUp(Event->button.x,Event->button.y);
                    break;

                case SDL_BUTTON_RIGHT:
                    onRButtonUp(Event->button.x,Event->button.y);
                    break;

                case SDL_BUTTON_MIDDLE:
                    onMButtonUp(Event->button.x,Event->button.y);
                    break;
            }

            break;

        case SDL_JOYAXISMOTION:
            onJoyAxis(Event->jaxis.which,Event->jaxis.axis,Event->jaxis.value);
            break;

        case SDL_JOYBALLMOTION:
            onJoyBall(Event->jball.which,Event->jball.ball,Event->jball.xrel,Event->jball.yrel);
            break;

        case SDL_JOYHATMOTION:
            onJoyHat(Event->jhat.which,Event->jhat.hat,Event->jhat.value);
            break;

        case SDL_JOYBUTTONDOWN:
            onJoyButtonDown(Event->jbutton.which,Event->jbutton.button);
            break;

        case SDL_JOYBUTTONUP:
            onJoyButtonUp(Event->jbutton.which,Event->jbutton.button);
            break;

        case SDL_QUIT:
            onExit();
            break;

        case SDL_SYSWMEVENT:
            break;

        case SDL_VIDEORESIZE:
            onResize(Event->resize.w,Event->resize.h);
            break;

        case SDL_VIDEOEXPOSE:
            onExpose();
            break;

        default:
            onUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
            break;
    }

}

void Events::onInputFocus() {
    inputFocus = true;
}

void Events::onInputBlur() {
    inputFocus = false;
}

void Events::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    //Pure virtual, do nothing
    UNUSED(sym);
    UNUSED(mod);
    UNUSED(unicode);
}

void Events::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    //Pure virtual, do nothing
    UNUSED(sym);
    UNUSED(mod);
    UNUSED(unicode);
    // THIS IS A HACK!
    // For some reason on my own machine, when i background the application
    // i wont receive the onMinimize() event but i do get onInputBlur && onKeyUp
    // with NUMLOCK !!!  Bug in SDL?

    if (inputFocus == false && sym == SDLK_NUMLOCK) {
        onMinimize();
    }
}

void Events::onMouseFocus() {
    //Pure virtual, do nothing
}

void Events::onMouseBlur() {
    //Pure virtual, do nothing
}

void Events::onMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
    //Pure virtual, do nothing
    UNUSED(mX);
    UNUSED(mY);
    UNUSED(relX);
    UNUSED(relY);
    UNUSED(Left);
    UNUSED(Right);
    UNUSED(Middle);
}

void Events::onMouseWheel(bool Up, bool Down) {
    //Pure virtual, do nothing
    UNUSED(Up);
    UNUSED(Down);
}

void Events::onLButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
    UNUSED(mX);
    UNUSED(mY);
}

void Events::onLButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
    UNUSED(mX);
    UNUSED(mY);
}

void Events::onRButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
    UNUSED(mX);
    UNUSED(mY);
}

void Events::onRButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
    UNUSED(mX);
    UNUSED(mY);
}

void Events::onMButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
    UNUSED(mX);
    UNUSED(mY);
}

void Events::onMButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
    UNUSED(mX);
    UNUSED(mY);
}

void Events::onJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
    //Pure virtual, do nothing
    UNUSED(which);
    UNUSED(axis);
    UNUSED(value);
}

void Events::onJoyButtonDown(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
    UNUSED(which);
    UNUSED(button);
}

void Events::onJoyButtonUp(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
    UNUSED(which);
    UNUSED(button);
}

void Events::onJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
    //Pure virtual, do nothing
    UNUSED(which);
    UNUSED(hat);
    UNUSED(value);
}

void Events::onJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
    //Pure virtual, do nothing
    UNUSED(which);
    UNUSED(ball);
    UNUSED(xrel);
    UNUSED(yrel);
}

void Events::onMinimize() {
    //Pure virtual, do nothing
}

void Events::onRestore() {
    //Pure virtual, do nothing
}

void Events::onResize(int w,int h) {
    //Pure virtual, do nothing
    UNUSED(w);
    UNUSED(h);
}

void Events::onExpose() {
    //Pure virtual, do nothing
}

void Events::onExit() {
    //Pure virtual, do nothing
}

void Events::onUser(Uint8 type, int code, void* data1, void* data2) {
    //Pure virtual, do nothing
    UNUSED(type);
    UNUSED(code);
    UNUSED(data1);
    UNUSED(data2);
}
