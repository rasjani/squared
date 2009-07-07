#include "engine.h"
#include "support.h"
#include <iostream>
#include "logger.h"
/** Default constructor. **/
Engine::Engine() :
        Tasks::Tasks(),
        Events::Events(),
        lastTick(0),
        winWidth(800),
        winHeight(600),
        appQuit(false),
        title(0),
        display(0),
        appMinimized(false),
        fpsTickCounter(0),
        fpsCounter(0),
        currentFps(0),
        speedFactor(0.0f),
        sdlSubSystems(SDL_INIT_VIDEO)
#ifdef TIMEDEXECUTION
        ,startTime(time(NULL))
#endif
{
}

/** Destructor. **/
Engine::~Engine() {
    if (display != 0) {
        SDL_FreeSurface(display);
        display = 0;
    }

    SDL_QuitSubSystem(sdlSubSystems);

    SDL_Quit();
}

/** Sets the height and width of the window.
        @param iWidth The width of the window
        @param iHeight The height of the window
**/
void Engine::SetSize(const int& iWidth, const int& iHeight) {
    winWidth = iWidth;
    winHeight = iHeight;
    display = SDL_SetVideoMode( iWidth, iHeight, 0, SDL_SWSURFACE );
}

/** Initialize SDL, the window and the additional data. **/
void Engine::Init() {
    // Register SDL_Quit to be called at exit; makes sure things are cleaned up when we quit.
    atexit( SDL_Quit );

    // Initialize SDL's subsystems - in this case, only video.

    if ( SDL_Init( sdlSubSystems ) < 0 ) {
        fprintf( stderr, "Unable to init SDL: %s\n", SDL_GetError() );
        exit( 1 );
    }

    // Attempt to create a window with the specified height and width.
    SetSize( winWidth, winHeight);

    // If we fail, return error.
    if ( ISREALLYNULL(display) ) {
        fprintf( stderr, "Unable to set up video: %s\n", SDL_GetError() );
        exit( 1 );
    }

    AdditionalInit();
}

/** The main loop. **/
void Engine::Start() {
    lastTick = SDL_GetTicks();
    appQuit  = false;

    // Main loop: loop forever.

    while ( !appQuit) {
        // Handle events
        // HandleInput();
        SDL_Event event;

        while ( SDL_PollEvent( &event ) ) {
            onEvent(&event);
        }

        if ( appMinimized) {
            // Release some system resources if the app. is minimized.
            SDL_WaitEvent(&event);
            onEvent(&event);
        } else {
            // Do some thinking
            DoThink();

            // Render stuff
            DoRender();
        }

        SDL_Delay(25);
    }

    End();
}

void Engine::onEvent(SDL_Event* Event) {
    Events::onEvent(Event);
}

void Engine::onExit() {
    appQuit = true;
}

void Engine::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    UNUSED(mod);
    UNUSED(unicode);

    if (sym == SDLK_ESCAPE)
        appQuit = true;
}

void Engine::onMinimize() {
    appMinimized = true;
}

void Engine::onRestore() {
    appMinimized = false;
}

/** Handles the updating routine. **/
void Engine::DoThink() {
#ifdef TIMEDEXECUTION

    if (time(NULL) > startTime + 30) {
        appQuit = true;
    }

#endif
    long elapsedTicks = SDL_GetTicks() - lastTick;

    speedFactor = ((SDL_GetTicks()-lastTick) / 1000.0f) * 32.0f;

    lastTick = SDL_GetTicks();

    think( elapsedTicks );

    fpsTickCounter += elapsedTicks;
}

float Engine::getSpeedFactor() {
    return speedFactor;
}

/** Handles the rendering and FPS calculations. **/
void Engine::DoRender() {
    ++fpsCounter;

    if ( fpsTickCounter >= 1000 ) {
        currentFps  = fpsCounter;
        fpsCounter = 0;
        fpsTickCounter = 0;
    }

    SDL_FillRect( display, 0, SDL_MapRGB( display->format, 0, 0, 0 ) );

    // Lock surface if needed

    if ( SDL_MUSTLOCK( display ) )
        if ( SDL_LockSurface( display ) < 0 )
            return;

    render( GetSurface() );

    // Unlock if needed
    if ( SDL_MUSTLOCK( display ) )
        SDL_UnlockSurface( display );

    // Tell SDL to update the whole gScreen
    SDL_Flip( display );
}

/** Sets the title of the window
        @param czTitle A character array that contains the text that the window title should be set to.
**/
void Engine::SetTitle(const char* czTitle) {
    title = czTitle;
    SDL_WM_SetCaption( title, 0 );
}

/** Retrieve the title of the application window.
        @return The last set windows title as a character array.
        @remark Only the last set title is returned. If another application has changed the window title, then that title won't be returned.
**/
const char* Engine::GetTitle() {
    return title;
}

/** Retrieve the main screen surface.
        @return A pointer to the SDL_Surface surface
        @remark The surface is not validated internally.
**/
SDL_Surface* Engine::GetSurface() {
    return display;
}

/** Get the current FPS.
        @return The number of drawn frames in the last second.
        @remark The FPS is only updated once each second.
**/
int Engine::GetFPS() {
    return currentFps;
}

