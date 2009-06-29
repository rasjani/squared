#ifndef SQUAREDENGINE_H
#define SQUAREDENGINE_H

#include "engine.h"
#include "surfacemanager.h"
#include "fontmanager.h"
#include "surface.h"
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include "entitymanager.h"

class SquaredEngine: public Engine
{
public:
        SquaredEngine(); 

        void AdditionalInit ();
        void Think          ( const int& elapsedTime );
        void Render         ( SDL_Surface* destSurface );

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

private:

        int myFontId;
        int myImageId;
};

#endif // SQUAREDENGINE_H

