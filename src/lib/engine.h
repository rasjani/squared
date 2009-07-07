#ifndef ENGINE_H
#define ENGINE_H

#include "SDL/SDL.h"
#include <time.h>
#include "tasks.h"
#include "events.h"

/** The base engine class. **/
class Engine : public Tasks, public Events
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

public:
    Engine();
    virtual ~Engine();

    void Init();
    void Start();

    //  Inherited from Tasks 
    virtual void think              ( const int& iElapsedTime ) = 0;
    virtual void render             ( SDL_Surface* pDestSurface ) = 0;


    // Inherited from Events
    virtual void onEvent(SDL_Event* Event);
    virtual void onExit();
    virtual void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    virtual void onMinimize();
    virtual void onRestore();


    /** OVERLOADED - Data that should be initialized when the application starts. **/
    virtual void AdditionalInit     () = 0;

    /** OVERLOADED - Allocated data that should be cleaned up. **/
    virtual void End                () = 0;

    void            SetTitle        (const char* czTitle);
    const char*     GetTitle        ();

    SDL_Surface*    GetSurface      ();

    int             GetFPS          ();
};

#endif // CENGINE_H
