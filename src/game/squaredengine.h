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

class SquaredEngine: public Engine {
    public:
        SquaredEngine();


        void think(const int& elapsedTime);
        void render(SDL_Surface *destSurface);

        void AdditionalInit ();

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

