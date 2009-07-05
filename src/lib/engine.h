#ifndef ENGINE_H
#define ENGINE_H

#include "SDL/SDL.h"
#include <time.h>
#include "tasks.h"

#define UNUSED(expr) do { (void)(expr); } while (0)


/** The base engine class. **/
class Engine : public Tasks
{
private:
    /** Last iteration's tick value **/
    long lastTick;

    /** Window width **/
    int winWidth;
    /** Window height **/
    int winHeight;

    /** Has quit been called? **/
    bool appQuit;

    /** The title of the window **/
    const char* title;

    /** Screen surface **/
    SDL_Surface* display;

    /** Is the window minimized? **/
    bool appMinimized;

    /** Variables to calculate the frame rate **/
    /** Tick counter. **/
    int fpsTickCounter;

    /** Frame rate counter. **/
    int fpsCounter;

    /** Stores the last calculated frame rate. **/
    int currentFps;

    int sdlSubSystems;
#ifdef TIMEDEXECUTION
    time_t startTime;
#endif

protected:
    void DoThink();
    void DoRender();

    void SetSize(const int& iWidth, const int& iHeight);

    void HandleInput();

public:
    Engine();
    virtual ~Engine();

    void Init();
    void Start();


    virtual void think              ( const int& iElapsedTime ) = 0;
    virtual void render             ( SDL_Surface* pDestSurface ) = 0;


    /** OVERLOADED - Data that should be initialized when the application starts. **/
    virtual void AdditionalInit     () = 0;

    /** OVERLOADED - All the games calculation and updating.
                @param iElapsedTime The time in milliseconds elapsed since the function was called last.
        **/

    /** OVERLOADED - Allocated data that should be cleaned up. **/
    virtual void End                () = 0;

    /** OVERLOADED - Window is active again. **/
    virtual void WindowActive       () = 0;

    /** OVERLOADED - Window is inactive. **/
    virtual void WindowInactive     () = 0;


    /** OVERLOADED - Keyboard key has been released.
                @param iKeyEnum The key number.
        **/
    virtual void KeyUp              (const int& iKeyEnum) = 0;

    /** OVERLOADED - Keyboard key has been pressed.
                @param iKeyEnum The key number.
        **/
    virtual void KeyDown            (const int& iKeyEnum) = 0;


    /** OVERLOADED - The mouse has been moved.
                @param iButton  Specifies if a mouse button is pressed.
                @param iX       The mouse position on the X-axis in pixels.
                @param iY       The mouse position on the Y-axis in pixels.
                @param iRelX    The mouse position on the X-axis relative to the last position, in pixels.
                @param iRelY    The mouse position on the Y-axis relative to the last position, in pixels.

                @bug The iButton variable is always NULL.
        **/
    virtual void MouseMoved         (const int& iButton,
                                     const int& iX,
                                     const int& iY,
                                     const int& iRelX,
                                     const int& iRelY) = 0;

    /** OVERLOADED - A mouse button has been released.
                @param iButton  Specifies if a mouse button is pressed.
                @param iX       The mouse position on the X-axis in pixels.
                @param iY       The mouse position on the Y-axis in pixels.
                @param iRelX    The mouse position on the X-axis relative to the last position, in pixels.
                @param iRelY    The mouse position on the Y-axis relative to the last position, in pixels.
        **/

    virtual void MouseButtonUp      (const int& iButton,
                                     const int& iX,
                                     const int& iY,
                                     const int& iRelX,
                                     const int& iRelY) = 0;

    /** OVERLOADED - A mouse button has been pressed.
                @param iButton  Specifies if a mouse button is pressed.
                @param iX       The mouse position on the X-axis in pixels.
                @param iY       The mouse position on the Y-axis in pixels.
                @param iRelX    The mouse position on the X-axis relative to the last position, in pixels.
                @param iRelY    The mouse position on the Y-axis relative to the last position, in pixels.
        **/
    virtual void MouseButtonDown    (const int& iButton,
                                     const int& iX,
                                     const int& iY,
                                     const int& iRelX,
                                     const int& iRelY) = 0;

    void            SetTitle        (const char* czTitle);
    const char*     GetTitle        ();

    SDL_Surface*    GetSurface      ();

    int             GetFPS          ();
};

#endif // CENGINE_H
