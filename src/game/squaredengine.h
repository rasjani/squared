#ifndef SQUAREDENGINE_H
#define SQUAREDENGINE_H

#include "engine.h"
#include "surfacemanager.h"
#include "fontmanager.h"
#include "filemanager.h"
#include "surface.h"
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include "entitymanager.h"

class SquaredEngine: public Engine
{
public:
        SquaredEngine(); 


        void think(const int& elapsedTime);
        void render(SDL_Surface *destSurface);

        void AdditionalInit ();

        void KeyUp          (const int& keyEnum);
        void KeyDown        (const int& keyEnum);

        void MouseMoved     (const int& button,
                             const int& x,
                             const int& y,
                             const int& relX,
                             const int& relY);

        void MouseButtonUp  (const int& button,
                             const int& x,
                             const int& y,
                             const int& relX,
                             const int& relY);

        void MouseButtonDown(const int& button,
                             const int& x,
                             const int& y,
                             const int& relX,
                             const int& relY);

        void WindowInactive();
        void WindowActive();

        void End();

        SurfaceManager *cm;
        FontManager *fm;
        EntityManager *cem;
        FileManager *fim;

private:

        int myFontId;
        int myImageId;
};

#endif // SQUAREDENGINE_H

