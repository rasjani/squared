#include "cengine.h"
/** Default constructor. **/
CEngine::CEngine() :
        lastTick(0),
        winWidth(800),
        winHeight(600),
        appQuit(false),
        title(0),
        display(0),
        appMinimized(false),
        fpsTickCounter(0),
        fpsCounter(0),
        currentFps(0)

{
}

/** Destructor. **/
CEngine::~CEngine()
{
    if (display != 0) {
        SDL_FreeSurface(display);
        display = 0;
    }
    SDL_Quit();
}

/** Sets the height and width of the window.
        @param iWidth The width of the window
        @param iHeight The height of the window
**/
void CEngine::SetSize(const int& iWidth, const int& iHeight)
{
    winWidth = iWidth;
    winHeight = iHeight;
    display = SDL_SetVideoMode( iWidth, iHeight, 0, SDL_SWSURFACE );
}

/** Initialize SDL, the window and the additional data. **/
void CEngine::Init()
{
    // Register SDL_Quit to be called at exit; makes sure things are cleaned up when we quit.
    atexit( SDL_Quit );

    // Initialize SDL's subsystems - in this case, only video.
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        fprintf( stderr, "Unable to init SDL: %s\n", SDL_GetError() );
        exit( 1 );
    }

    // Attempt to create a window with the specified height and width.
    SetSize( winWidth, winHeight);

    // If we fail, return error.
    if ( display == NULL )
    {
        fprintf( stderr, "Unable to set up video: %s\n", SDL_GetError() );
        exit( 1 );
    }

    AdditionalInit();
}

/** The main loop. **/
void CEngine::Start()
{
    lastTick = SDL_GetTicks();
    appQuit  = false;

    // Main loop: loop forever.
    while ( !appQuit)
    {
        // Handle mouse and keyboard input
        HandleInput();

        if ( appMinimized) {
            // Release some system resources if the app. is minimized.
            // WaitMessage(); // pause the application until focus in regained
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

/** Handles all controller inputs.
        @remark This function is called once per frame.
**/
void CEngine::HandleInput()
{
    // Poll for events, and handle the ones we care about.
    SDL_Event event;
    while ( SDL_PollEvent( &event ) )
    {
        switch ( event.type )
        {
                case SDL_KEYDOWN:
            // If escape is pressed set the Quit-flag
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                appQuit = true;
                break;
            }

            KeyDown( event.key.keysym.sym );
            break;

                case SDL_KEYUP:
            KeyUp( event.key.keysym.sym );
            break;

                case SDL_QUIT:
            appQuit = true;
            break;

                case SDL_MOUSEMOTION:
            MouseMoved(
                    event.button.button,
                    event.motion.x,
                    event.motion.y,
                    event.motion.xrel,
                    event.motion.yrel);
            break;

                case SDL_MOUSEBUTTONUP:
            MouseButtonUp(
                    event.button.button,
                    event.motion.x,
                    event.motion.y,
                    event.motion.xrel,
                    event.motion.yrel);
            break;

                case SDL_MOUSEBUTTONDOWN:
            MouseButtonDown(
                    event.button.button,
                    event.motion.x,
                    event.motion.y,
                    event.motion.xrel,
                    event.motion.yrel);
            break;

                case SDL_ACTIVEEVENT:
            if ( event.active.state & SDL_APPACTIVE ) {
                if ( event.active.gain ) {
                    appMinimized = false;
                    WindowActive();
                } else {
                    appMinimized = true;
                    WindowInactive();
                }
            }
            break;
        } // switch
    } // while (handling input)
}

/** Handles the updating routine. **/
void CEngine::DoThink()
{
    long elapsedTicks = SDL_GetTicks() - lastTick;
    lastTick = SDL_GetTicks();

    Think( elapsedTicks );

    fpsTickCounter += elapsedTicks;
}

/** Handles the rendering and FPS calculations. **/
void CEngine::DoRender()
{
    ++fpsCounter;
    if ( fpsTickCounter >= 1000 )
    {
        currentFps  = fpsCounter;
        fpsCounter = 0;
        fpsTickCounter = 0;
    }

    SDL_FillRect( display, 0, SDL_MapRGB( display->format, 0, 0, 0 ) );

    // Lock surface if needed
    if ( SDL_MUSTLOCK( display ) )
        if ( SDL_LockSurface( display ) < 0 )
            return;

    Render( GetSurface() );

    // Unlock if needed
    if ( SDL_MUSTLOCK( display ) )
        SDL_UnlockSurface( display );

    // Tell SDL to update the whole gScreen
    SDL_Flip( display );
}

/** Sets the title of the window
        @param czTitle A character array that contains the text that the window title should be set to.
**/
void CEngine::SetTitle(const char* czTitle)
{
    title = czTitle;
    SDL_WM_SetCaption( title, 0 );
}

/** Retrieve the title of the application window.
        @return The last set windows title as a character array.
        @remark Only the last set title is returned. If another application has changed the window title, then that title won't be returned.
**/
const char* CEngine::GetTitle()
{
    return title;
}

/** Retrieve the main screen surface.
        @return A pointer to the SDL_Surface surface
        @remark The surface is not validated internally.
**/
SDL_Surface* CEngine::GetSurface()
{
    return display;
}

/** Get the current FPS.
        @return The number of drawn frames in the last second.
        @remark The FPS is only updated once each second.
**/
int CEngine::GetFPS()
{
    return currentFps;
}
