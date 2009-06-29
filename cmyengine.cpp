#include "cmyengine.h"
#include "csurface.h"
#include <SDL/SDL_ttf.h>
#include <sstream>
#include <iostream>
#include "yoshient.h"
#include "yoshient2.h"

CMyEngine::CMyEngine() :
    cm(0),
    fm(0),
    cem(0)
{}

int direction = 1;
void CMyEngine::AdditionalInit()
{
    // Load up additional data
    cm = CSurfaceManager::getInstance();
    fm = new CFontManager();
    cem = new CEntityManager();


    cem->addEntity( new YoshiEnt("yoshi.bmp",8));
    cem->addEntity( new YoshiEnt2("yoshi.bmp",8));

    myImageId = cm->addImage(new CSurface("teatteri_nologo.jpg"));
    myFontId = fm->addFont("font.ttf");

}

void CMyEngine::Think( const int& elapsedTime )
{
    cem->think(elapsedTime);

    // Do time-based calculations
}

void CMyEngine::Render( SDL_Surface* destSurface )
{
    // Display slick graphics on screen

    CSurface *image = cm->getImage(myImageId);
    if (image != 0) {
        image->draw(destSurface,10,10);
    }

    cem->render(destSurface);

    if (myFontId != -1) {
        SDL_Rect d;
        d.x = 100;
        d.y = 100;
        SDL_Color fontcolor={250,250,250,0};
        std::stringstream ss;
        ss  << GetFPS(); 
        // ss  << a->getCurrentFrame();
        std::string foo;
        ss >> foo;
        SDL_Surface *temp =  TTF_RenderText_Solid(fm->getFont(myFontId),foo.c_str(),fontcolor);
        SDL_BlitSurface(temp,NULL,destSurface,&d);
        SDL_FreeSurface(temp);
    }
}

void CMyEngine::KeyDown(const int& keyEnum)
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

  if (fm != 0) {
    delete fm;
    fm = 0;
  }

  if (cem != 0) {
    delete cem;
    cem = 0;
  }
}

