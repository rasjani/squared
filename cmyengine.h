#ifndef CMYENGINE_H
#define CMYENGINE_H

#include "cengine.h"
#include <stdlib.h>
 
class CMyEngine: public CEngine
{
public:
        void AdditionalInit ();
        void Think          ( const int& iElapsedTime );
        void Render         ( SDL_Surface* pDestSurface );
 
        void KeyUp          (const int& iKeyEnum);
        void KeyDown        (const int& iKeyEnum);
 
        void MouseMoved     (const int& iButton, 
                             const int& iX, 
                             const int& iY, 
                             const int& iRelX, 
                             const int& iRelY);
 
        void MouseButtonUp  (const int& iButton, 
                             const int& iX, 
                             const int& iY, 
                             const int& iRelX, 
                             const int& iRelY);
 
        void MouseButtonDown(const int& iButton, 
                             const int& iX, 
                             const int& iY, 
                             const int& iRelX, 
                             const int& iRelY);
 
        void WindowInactive();
        void WindowActive();
 
        void End();
};
 
#endif // CMYENGINE_H

