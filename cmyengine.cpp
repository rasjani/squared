#include "cmyengine.h"
#include <SDL/SDL_ttf.h>
#include <sstream>

void CMyEngine::AdditionalInit()
{
    // Load up additional data
    cm = new CSurfaceManager();
    CSurface *foo = new CSurface("teatteri_nologo.jpg");
    cm->addImage(foo);
    if(TTF_Init()==-1) {
        exit(2);
    }
    font = TTF_OpenFont("font.ttf",16);
}

void CMyEngine::Think( const int& elapsedTime )
{
    UNUSED(elapsedTime);
    // Do time-based calculations
}

void CMyEngine::Render( SDL_Surface* destSurface )
{
    UNUSED(destSurface);
    // Display slick graphics on screen

    CSurface *image = cm->getImage("teatteri_nologo.jpg");
    if (image != 0) {
        image->draw(destSurface,1,1);
    }

    if (font) {
        SDL_Rect d;
        d.x = 100;
        d.y = 100;
        SDL_Color fontcolor={250,250,250,0};
        std::stringstream ss;
        ss  << GetFPS();
        std::string foo;
        ss >> foo; 
        SDL_Surface *temp =  TTF_RenderText_Solid(font,foo.c_str(),fontcolor);
        SDL_BlitSurface(temp,NULL,destSurface,&d);
        SDL_FreeSurface(temp);
    }
}

void CMyEngine::KeyDown(const int& keyEnum)
{
    switch (keyEnum) {
    case SDLK_LEFT:
        // Left arrow pressed
        break;
    case SDLK_RIGHT:
        // Right arrow pressed
        break;
    case SDLK_UP:
        // Up arrow pressed
        break;
    case SDLK_DOWN:
        // Down arrow pressed
        break;
    }
}


void CMyEngine::KeyUp(const int& keyEnum)
{
    switch (keyEnum) {
    case SDLK_LEFT:
        // Left arrow released
        break;
    case SDLK_RIGHT:
        // Right arrow released
        break;
    case SDLK_UP:
        // Up arrow released
        break;
    case SDLK_DOWN:
        // Down arrow released
        break;
    }
}

void CMyEngine::MouseMoved(const int& button,
                           const int& x,
                           const int& y,
                           const int& relX,
                           const int& relY)
{
    // Handle mouse movement
    UNUSED(button);
    UNUSED(x);
    UNUSED(y);
    UNUSED(relX);
    UNUSED(relY);
    // x and y are absolute screen positions
    // relX and relY are screen position relative to last detected mouse movement
}

void CMyEngine::MouseButtonUp(const int& button,
                              const int& x,
                              const int& y,
                              const int& relX,
                              const int& relY)
{
    // Handle mouse button released
    UNUSED(button);
    UNUSED(x);
    UNUSED(y);
    UNUSED(relX);
    UNUSED(relY);

}

void CMyEngine::MouseButtonDown(const int& button,
                                const int& x,
                                const int& y,
                                const int& relX,
                                const int& relY)
{
    // Handle mouse button pressed
    UNUSED(button);
    UNUSED(x);
    UNUSED(y);
    UNUSED(relX);
    UNUSED(relY);

}

void CMyEngine::WindowInactive()
{
    // Pause game
}

void CMyEngine::WindowActive()
{
    // Un-pause game
}


void CMyEngine::End()
{
    // Clean up
  if (cm != 0) {
    delete cm;
    cm = 0;
  }
  TTF_CloseFont(font);
  TTF_Quit();        
}

