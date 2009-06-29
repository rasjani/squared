#ifndef CMYENGINE_H
#define CMYENGINE_H

#include "cengine.h"
#include "csurfacemanager.h"
#include "cfontmanager.h"
#include "csurface.h"
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include "centitymanager.h"

class CMyEngine: public CEngine
{
public:
        CMyEngine(); 

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

        CSurfaceManager *cm;
        CFontManager *fm;
        CEntityManager *cem;

private:

        int myFontId;
        int myImageId;
};

#endif // CMYENGINE_H

